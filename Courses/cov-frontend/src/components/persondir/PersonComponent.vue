<template>
  <main class="container">
    <div class="row">
      <div class="col-md-12 userimg">
        <div class="col-2">
          <img style ="width:150px;padding-top: 130px" src="../../assets/picdir/icon.jpeg">
        </div>
      </div>
      <div class="card">
        <div class="card-body">
          <div class="row">
            <div class="col-12" style="font-weight: bold;font-family: 'rr';font-size: 30px">
              <div>
                {{user.username}}
                <button style="float:right" type="button" class="btn btn-outline-secondary" @click="toeditperson">编辑个人资料</button>
                <button style="float:right;margin-right:10px" type="button" class="btn btn-outline-secondary" @click="toeditpassword">修改个人密码</button>
              </div>
              <div style="font-size: 20px;font-weight: normal;width: 90%">
                个人简介
                <p style="font-weight: lighter">{{user.introduction}}</p>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="row mt-4">
      <div id="question" class="card">
        <div class="card-body">
          <nav>
            <div class="nav nav-tabs" id="nav-tab" role="tablist">
              <button class="nav-link active" id="nav-home-tab" data-bs-toggle="tab" data-bs-target="#nav-home" type="button" role="tab" aria-controls="nav-home" aria-selected="true">
                <div style="font-weight: bold;font-family: 'rr';font-size: 20px">
                  我的回答
                </div>
              </button>
              <button class="nav-link" id="nav-profile-tab" data-bs-toggle="tab" data-bs-target="#nav-profile" type="button" role="tab" aria-controls="nav-profile" aria-selected="false">
                <div style="font-weight: bold;font-family: 'rr';font-size: 20px">
                  我的提问
                </div>
              </button>
            </div>
          </nav>
          <div class="tab-content" id="nav-tabContent">
            <div class="tab-pane fade show active" id="nav-home" role="tabpanel" aria-labelledby="nav-home-tab">
              <div v-for="(item,index) in commentlist" :key="index">
                <div>
                  <div style="font-weight: bold;font-family: 'rr';font-size: 25px">{{item.questiontitle}}</div>
                  <div class="row">
                    <div class="col-md-12" style="font-family: 'rr';font-size: 18px">
                      <img style ="width:50px;" src="../../assets/picdir/icon.jpeg">
                        {{user.username}}<span style="color: gray;font-size: 15px">，{{user.introduction}}</span>
                      <div style="font-size: 17px;font-weight: normal">
                        <p style="font-weight: lighter"></p>
                      </div>
                    </div>
                  </div>
                  <div style="font-weight: lighter;font-family: 'rr';font-size: 20px">{{item.content}} </div>
                  <div class="align-items-end d-flex flex-column">
                    <div type="button" class="btn btn-outline-danger" data-bs-dismiss="modal" @click="deletecomment(index)">删除回答</div>
                  </div>
                </div>

                <div class="dropdown-divider"></div>
              </div>
            </div>
            <div class="tab-pane fade" id="nav-profile" role="tabpanel" aria-labelledby="nav-profile-tab">
              <div v-for="(item,index) in questionlist" :key="index">
                <div>
                  <div style="font-weight: bold;font-family: 'rr';font-size: 25px;padding-block: 10px">{{item.title}}</div>
                  <div style="font-weight: lighter;font-family: 'rr';font-size: 20px">{{item.content}} </div>
                  <div class="align-items-end d-flex flex-column">
                    <div type="button" class="btn btn-outline-danger" data-bs-dismiss="modal" @click="deletequestion(index)">删除提问</div>
                  </div>
                </div>

                <div class="dropdown-divider"></div>
              </div>
            </div>
            <div class="tab-pane fade" id="nav-contact" role="tabpanel" aria-labelledby="nav-contact-tab">...</div>
          </div>
        </div>
      </div>
    </div>
  </main>
</template>

<script>
import "@/assets/fontdir/font.css";
export default {
  components:{
  },
  created(){
    this.postRequest(
        '/user/showpersoninfo',
        {},
        {
          token:this.$cookies.get("token")
        }
       )
        .then((response) => {
          if(response.code==="200"){
            this.user = response.data.user
            this.ChinaData = response.data.subscribedatalist
            this.myprovince = response.data.my_province
            console.log("这里")
            console.log(this.ChinaData)
            console.log(this.user)
          }
          else{
            this.$message({message: response.msg, type: 'error'})
          }
        })
        .catch((error) => {
          console.log(error)
        });
  },
  mounted(){
    
    this.postRequest(
        '/social/myquestion',
        {},
        {
          token:this.$cookies.get("token")
        }
    )
        .then(response => {
          console.log(response);
          if(response.code === "200"){
            this.questionlist = response.data.questionlist
            console.log("问题列表")
            console.log(this.questionlist)
          }
          else if(response.code === "400"){
            this.$message({message: response.msg, type: 'error'})
            // this.$router.push('/')
          }
          else{
            this.$message({message: '错误', type: 'error'})
            console.log(response)
            // this.$router.push('/')
          }
        })
        .catch(error => { console.log(error)
        });
    this.postRequest(
        '/social/mycomment',
        {},
        {
          token:this.$cookies.get("token")
        }
    )
        .then(response => {
          console.log(response);
          if(response.code === "200"){
            this.commentlist = response.data.list
            console.log("评论列表")
            console.log(this.commentlist)
          }
          else if(response.code === "400"){
            this.$message({message: response.msg, type: 'error'})
            // this.$router.push('/')
          }
          else{
            this.$message({message: '错误', type: 'error'})
            console.log(response)
            // this.$router.push('/')
          }
        })
        .catch(error => {
          console.log(error)
        });
  },
  methods:{
    toeditperson(){
      this.$router.push('/editperson');
    },
    toeditpassword(){
      this.$router.push('/editpassword');
    },
    goprovince(){
      this.$router.push({
        path: '/province',
        query: {
          provincename: '北京',
          provincecode: 0
        }
      });
    },
    deletequestion(index){
      console.log(index)
      var id = this.questionlist[index].id
      this.postRequest(
          '/social/deletequestion',
          {
            question_id: id
          }
      ).then(response =>{
        console.log(response)
        if(response.code === '200'){
          this.$message({message: '删除成功', type: 'success'})
          this.$router.go(0)
        }
        else if(response.data === '400'){
          this.$message({message: response.msg, type: 'error'})
        }
        else{
          this.$message({message: '错误', type: 'error'})
        }
      }).catch(error =>{
        this.$message({message: '错误', type: 'error'})
        console.log(error)
      })
    },
    deletecomment(index){
      console.log(index)
      var id = this.commentlist[index].id
      this.postRequest(
          '/social/deletecomment',
          {
            comment_id: id
          }
      ).then(response =>{
        console.log(response)
        if(response.code === '200'){
          this.$message({message: '删除成功', type: 'success'})
          this.$router.go(0)
        }
        else if(response.data === '400'){
          this.$message({message: response.msg, type: 'error'})
        }
        else{
          this.$message({message: '错误', type: 'error'})
        }
      }).catch(error =>{
        this.$message({message: '错误', type: 'error'})
        console.log(error)
      })
    }
  },
  data(){
    return {
      imgUrl:require("../../assets/test.jpg"),
      user:{},
      page1:true,
      questionlist:[
      ],
      myquestion:{},
      myprovince:{},
      myreply:{},
      myanswer:{},
      chinaData:{
        covdata:{
          confirm:0,no_infect_add:0,no_infect:0,dead_add:0,heal:0,now_confirm:0,dead:0,now_confirm_add:0,heal_add:0,confirm_add:0
        }
      },
      commentlist:[],
      ChinaData:[
        {
          location: '北京'
        }
      ]
    }
  }  
}
</script>

<style scoped>
.userimg{
  background-image: url("../../assets/picdir/background_img.jpeg");
  background-size: 100%;
  width: 100%;
  height: 290px;
}
</style>