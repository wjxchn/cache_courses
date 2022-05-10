<template>
  <main>
    <div class="edit">
      <div class="editdiv">
        <div class="left">
          <div class="col-12">
          <label for="img" class="form-label">头像:</label><br>
          <img style="width:50%;border-radius:10px;" src="../../assets/picdir/icon.jpeg">
          </div>
        </div>
        <div class="right">
          <label style="margin-top:10px;" for="name" class="form-label">用户名:</label>
          <input type="text" class="form-control" id="formGroupExampleInput" :disabled="edit" placeholder="现在的用户名" v-model="username">
          <label for="name" class="form-label">个人简介</label>
          <textarea class="form-control" style="height: 120px;resize: none" :disabled="edit" v-model="introduction"></textarea>
        </div>
      </div>
      <div class="col-12" align="center">
        <button  class="btn btn-outline-secondary" @click="edit=!edit">修改</button>
        <button  class="btn btn-outline-success" style="margin-left:20px;" @click="changeinfo">完成</button>
        <button  class="btn btn-outline-danger" type="submit" style="margin-left:20px;" @click="toperson">返回</button>
      </div>
    </div>
  </main>
</template>

<script>
export default {
  data(){
    return {
      imgUrl:require("../../assets/test.jpg"),
      mail:"",
      introduction:"",
      username:"",
      edit: true
    }
  },
  mounted() {
    this.postRequest(
        '/user/showpersoninfo',
        {},
        {
          token:this.$cookies.get("token")
        }
    )
        .then((response) => {
          if(response.code==="200"){
            this.username = response.data.user.username
            this.introduction = response.data.user.introduction
          }
          else{
            this.$message({message: response.msg, type: 'error'})
          }
        })
        .catch((error) => {
          console.log(error)
        });
  },
  methods:{
    changeinfo(){
      if(this.username === null || this.username === ''){
        this.$message({message: "用户名不能为空", type: 'error'})
      }
      else{
        this.postRequest(
        "/user/changeinfo",
        {
          location_id:0,
          introduction:this.introduction,
          username:this.username
        },
        {
          token:this.$cookies.get("token")
        }
      ).then( (response) => {
        if(response.code==="200"){
          this.$message({message: "修改成功", type: 'success'})
          this.$router.push("/person")
        }
        else{
          this.$message({message: response.msg, type: 'error'})
        }
      } ).catch( (err) => {
        console.log(err)
      })
      }
      
    },
    toperson(){
      this.$router.push("/person")
    }
  }
}
</script>

<style scoped>
.edit{
  margin-left: 16%;
  margin-top: 5px;
  height:550px;
  width:68%;
  border: 2px solid #adadad;
  border-radius: 10px;
}
.editdiv{
  width:100%;
  height:500px;
  
}
.left{
  float:left;
  height:60%;
  padding:5%;
  margin-top:100px;
  border-right: 1px solid #000;
  width:30%;
}
.right{
  float:left;
  width:65%;
  padding: 5%;
  margin-top: 10%;
}
</style>