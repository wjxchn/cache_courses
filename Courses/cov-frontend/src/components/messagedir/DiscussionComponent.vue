<template>
<!-- 本部分待完成界面：搜索问题，删除个人回复，删除个人问题，修改个人问题与回复 -->
  <main>

      <div class="container">
        <div class="row" style="margin-top:50px;margin-bottom:30px;">
          <div class="col-10 cardDiscuss">
              <form class="d-flex input-group-sm" style="height: 40px">
                <input class="form-control" type="search" placeholder="根据题目搜索问题" v-model="searchData">
                <button  type="button" @click="Search()" style="width:100px;" class="btn btn-light background-color:white">
                  <svg t="1625966017106" class="icon" viewBox="0 0 1024 1024" version="1.1" xmlns="http://www.w3.org/2000/svg" p-id="2602" width="30" height="30">
                    <path d="M417.05 770.27c-94.33 0-183.01-36.73-249.7-103.43-137.69-137.68-137.69-361.72 0-499.4C234.05 100.74 322.73 64 417.05 64s183 36.74 249.7 103.43c137.69 137.68 137.69 361.72 0 499.4-66.69 66.71-155.37 103.44-249.7 103.44z m0-642.06c-77.18 0-149.73 30.06-204.3 84.62-112.65 112.66-112.65 295.95 0 408.61 54.57 54.57 127.13 84.62 204.3 84.62 77.17 0 149.73-30.05 204.3-84.62C734 508.78 734 325.49 621.35 212.83c-54.57-54.57-127.13-84.62-204.3-84.62z" fill="#707070" p-id="2603">
                    </path><path d="M905.1 960c-8.51 0-16.68-3.39-22.7-9.41L610 678.18c-12.54-12.53-12.54-32.86 0-45.4l22.7-22.7c12.52-12.54 32.86-12.54 45.4 0l272.41 272.4c12.54 12.54 12.54 32.86 0.01 45.4l-22.71 22.71A32.124 32.124 0 0 1 905.1 960z" fill="#707070" p-id="2604"></path>
                  </svg>
                </button>
              </form>
          </div>
          <div class="col-2">
            <div>
              <!-- 发布问题按钮 -->
              <div>      
                <button class="btn btn-primary rounded-pill" type="button" data-bs-toggle="modal" data-bs-target="#MyPage" style="width: 80px" >
                  提问
                </button>
              </div>
              <div class="modal fade" id="MyPage" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
                <div class="modal-dialog">
                  <div class="modal-content">
                    <div class="modal-header">
                      <h5 class="modal-title" id="exampleModalLabel">发布问题</h5>
                      <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                    </div>
                    <div class="modal-body">
                      <form>
                        <div class="mb-3">
                          <label class="col-form-label">问题题目:</label>
                          <input v-model="questiontitle" type="text" class="form-control">
                        </div>
                        <div class="mb-3">
                          <label class="col-form-label">问题内容:</label>
                          <textarea v-model="questioncontent" class="form-control" ></textarea>
                        </div>
                      </form>
                    </div>
                    <div class="modal-footer">
                      <button type="button" class="btn btn-outline-success" @click="publishQuestion" data-bs-dismiss="modal">发布问题</button>
                      <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">取消</button>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>

        <!-- 去掉了margin-top,margin-bottom实现填充 -->    
        <el-table
            :data="showquestions"
            stripe
            style="width: 100%"
            :show-header="false"
        >
          <el-table-column
            prop="id"
            v-if="false">
          </el-table-column>
          <el-table-column
            prop="content"
            v-if="false"
          >
          </el-table-column>
          <el-table-column
            prop="title"
            width="auto"
          >
            <template slot-scope="scope">
              <div style="font-family: 'rr';font-weight:bold;font-size: 20px" class="comment-title">
                <a :href="url" style="color: black" @mouseover="showquestiondetail(scope.row.id)">{{scope.row.title}}</a>
              </div>
              <div style="font-size: 20px;font-family: rr;color:black" class="comment-text">
                <p>{{scope.row.content}}</p>
              </div>
            </template>
          </el-table-column>
          <el-table-column
              prop="username"
              width="260"
          >
            <template slot-scope="scope">
              <div style="text-align: right;">
                <div style="font-family: rr;font-size: 20px;color:black">
                  <div class="p-2" style="text-align: right">
                    <p>
                      <img src="../../assets/picdir/icon.jpeg" alt="user" width="50" class="rounded-circle">
                      {{scope.row.username}}
                    </p>
                    <p style="color: gray">发布于{{scope.row.time}}</p>
                  </div>
                </div>
              </div>
            </template>
          </el-table-column>
          <el-table-column
              prop="time"
              v-if="false"
          >
          </el-table-column>
        </el-table>
        <div class="row">
          <div class="col-12">
            <div>第{{showquestionsIndex+1}}页，共{{this.questions.length%8==0?parseInt(this.questions.length/8):parseInt(this.questions.length/8)+1}}页</div>
            <nav aria-label="Page navigation example">
              <ul class="pagination justify-content-center">
                <li class="page-item">
                  <a class="btn btn-outline-secondary" @click="tolastpage()">上一页</a>
                </li>
                <li class="page-item">
                  <a class="btn btn-outline-secondary" @click="tonextpage()">下一页</a>
                </li>
              </ul>
            </nav>
          </div>
        </div>
      </div>
  </main>
</template>

<script>

import "@/assets/fontdir/font.css";

export default {
  name: 'DiscussionComponent',
  data(){
    return{
      showquestions:[],
      showquestionsIndex: 0,
      total: 0, //实现动态绑定
      pageSize: 2,
      currentPage: 1,  
      questiontitle:"",
      questioncontent:"",
      questions:[
      ],
      searchData:"",
      username: '',
      names: ['000', '111', '222', '333', '444', '555'],
      url : ''
    }
  },
  created(){
    this.postRequest(
      "/user/getusername",
      {},
      {
        token:this.$cookies.get("token")
      }
    ).then((response) =>{
      if(response.code==="200"){
        this.username = response.data.username
      }
      else{
        console.log(response.msg)
      }
    } ).catch(err=>{
      console.log(err)
    })
    this.postRequest(
      "/social/shownewquestion",
      {}
    ).then( (response) => {
      console.log(response)
      if(response.code==="200"){
        this.questions = response.data.questionlist
        for(let i=0;i<Math.min(this.questions.length,8);i++){
          this.showquestions.push(this.questions[i]);
          console.log(this.questions[i]);
        }        
      }
      else{
        alert("显示错误")
      }
    })
  },
	methods:{
    tolastpage(){
      if(this.showquestionsIndex!=0){
        this.showquestionsIndex-=1;
        while(this.showquestions.length!=0){
          this.showquestions.pop();
        }
        for(let i=this.showquestionsIndex*8;i<(this.showquestionsIndex+1)*8;i++){
          this.showquestions.push(this.questions[i]);
        }
      }
    },
    tonextpage(){
      if(this.questions.length%8==0){
        if(this.showquestionsIndex!=parseInt(this.questions.length/8)-1){
          this.showquestionsIndex+=1;
          while(this.showquestions.length!=0){
            this.showquestions.pop();
          }
          for(let i=this.showquestionsIndex*8;i<(this.showquestionsIndex+1)*8;i++){
            this.showquestions.push(this.questions[i]);
          }
        }
      }
      else{
        if(this.showquestionsIndex!=parseInt(this.questions.length/8)){
          this.showquestionsIndex+=1;
          while(this.showquestions.length!=0){
            this.showquestions.pop();
          }
          for(let i=this.showquestionsIndex*8;i<Math.min(this.questions.length,(this.showquestionsIndex+1)*8);i++){
            this.showquestions.push(this.questions[i]);
          }
        }
      }
    },
    toMessage(){
      this.$router.push('/message');
    },
    toQuestion(){
      this.$router.push('/question');
    },
    publishQuestion(){
      this.postRequest(
        "/social/publishquestion",
        {
          title:this.questiontitle,
          content:this.questioncontent,
        },
        {
          token:this.$cookies.get('token')
        }
      ).then( res =>{
        if(res.code==="200"){
          alert("发布成功")
          this.$router.go(0)
        }
        else{
          alert(res.msg)
        }
      } )
    },
    showquestiondetail(index){
      this.url = this.$router.resolve({path: '/discussion/discussiondetail', query: {question_id:index}}).href;
    },
    toMyPage(){
		  this.$router.push('/person');
    },
    search(){
        this.postRequest(
        "/social/searchquestion",
        {},
        {
          token:this.$cookies.get("token")
        }).then((response)=>{
          console.log(response);
          console.log("收到了response")
        }).catch(err=>{
          console.log(err)
        })
    },

    Search() {
      // search 是 v-model="search" 的 search
      if(this.searchData===""||this.searchData===null){
        alert("请输入搜索关键字")
        this.$router.go(0)
      }
      else{
        this.postRequest(
        "/social/searchquestion",
        {
          keyword:this.searchData
        },
        ).then((response)=>{
          if(response.code==="200"){
            this.questions = response.data.questionlist
            this.showquestions = response.data.questionlist
          }
          else{
            alert(response.msg)
          }
        }).catch(err=>{
          console.log(err)
        })
      }
    }
  }
}
</script>

<style scoped>

.fixedbutton{
  position:fixed;
  background-color: white;
  margin-top: 320px;

}


.overflow-hidden {
    overflow: hidden;
    overflow-x: hidden;
    overflow-y: hidden;
}


.name {

font-family: "Times New Roman", Times, serif;
font-size: 24px;
color: #000000;
 
}


/*******************/
/*Comment widgets*/
/*******************/

.comment-widgets {
  position: relative;
   }
  .comment-widgets .comment-row {
    border-bottom: 1px solid transparent;
    padding: 14px;
    display: -webkit-box;
    display: -ms-flexbox;
    display: flex;
    margin: 10px 0; }
    .comment-widgets .comment-row:last-child {
      border-bottom: 0px; }
    .comment-widgets .comment-row:hover, .comment-widgets .comment-row.active {
      background: rgba(0, 0, 0, 0.05); }

.comment-text {
  padding: 15px;
  width: 100%; }
  .comment-text:hover .comment-footer .action-icons,
  .comment-text.active .comment-footer .action-icons {
    visibility: visible; }
  .comment-text p {
    max-height: 65px;
    width: 100%;
    overflow: hidden; }

.comment-footer .action-icons {
  visibility: hidden; }
  .comment-footer .action-icons a {
    padding-left: 7px;
    vertical-align: middle;
    color: #a1aab2; }
    .comment-footer .action-icons a:hover, .comment-footer .action-icons a.active {
      color: #2962FF; }

.comment-title{
    margin-top: 20px;
    padding: 15px;
}

.comment-ph{
  margin-top: 40px;
}

.card {
  position: relative;
  display: flex;
  flex-direction: column;
  min-width: 0;
  word-wrap: break-word;
  background-color: #fff;
  background-clip: border-box;
  border: 1px solid rgba(0, 0, 0, 0.125);
  border-radius: 0.25rem;
  margin-bottom: 20px;
  background: #fff;
  overflow: hidden;
  border-radius: 2px;
  -webkit-box-shadow: 0 1px 3px rgba(18,18,18,.1);
  box-shadow: 0 1px 3px rgba(18,18,18,.1);
  -webkit-box-sizing: border-box;
  box-sizing: border-box;
}

.cardDiscuss {
  position: relative;
  display: flex;
  flex-direction: column;
  min-width: 0;
  word-wrap: break-word;
  background-color: #fff;
  background: #fff;
  overflow: hidden;
  margin-bottom: 20px;
  margin-top: 0px;
}

.cardSearch {
  position: relative;
  display: flex;
  flex-direction: column;
  min-width: 0;
  word-wrap: break-word;
  background-color: #fff;
  background: #fff;
  overflow: hidden;
  margin-bottom: 20px;
}
.card-body {
  flex: 1 1 auto;
  padding: 1rem 1rem;
}

.card-title {
  margin-bottom: 0.5rem;
}

.messageimg{
  width: 100%;
  height: 10vw;
}

body {
  font-family: "Inconsolata", monospace;
  color: #0d1e2d;
}

a {
  color: #777;
  text-decoration: none;
}

a:hover {
  color: #000;
}

h1, h2, h3, h4, h5, h6, .font-heading {
  font-family: "Raleway", sans-serif;
}

.filters a {
  text-decoration: none;
  color: #000;
  display: inline-block;
  padding-left: 10px;
  padding-right: 10px;
  position: relative;
}

.filters a:hover, .filters a:focus, .filters a:active {
  text-decoration: none;
}

.filters a:hover:before {
  content: "";
  position: absolute;
  left: 10px;
  right: 10px;
  bottom: 0;
  height: 1px;
  background-color: #000;
}

.filters a.active {
  color: #000;
}

.filters a.active:before {
  content: "";
  position: absolute;
  left: 10px;
  right: 10px;
  bottom: 0;
  height: 1px;
  background-color: #000;
}

.item {
  border: none;
  margin-bottom: 30px;
}

.item .item-wrap {
  display: block;
  position: relative;
  overflow: hidden;
}

.item .item-wrap:after {
  z-index: 2;
  position: absolute;
  content: "";
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background: rgba(0, 0, 0, 0.4);
  visibility: hidden;
  opacity: 0;
  transition: .3s all ease-in-out;
}

.item .item-wrap img {
  transition: .3s transform ease;
  transform: scale(1);
}

.item .item-wrap > .work-info {
  position: absolute;
  top: 50%;
  width: 100%;
  text-align: center;
  z-index: 3;
  transform: translateY(-50%);
  color: #fff;
  opacity: 0;
  visibility: hidden;
  margin-top: 20px;
  transition: .3s all ease;
}

.item .item-wrap > .work-info h3 {
  font-size: 20px;
  margin-bottom: 0;
}

.item .item-wrap > .work-info span {
  font-size: 14px;
  text-transform: uppercase;
  letter-spacing: .2rem;
}

.item .item-wrap:hover {
  text-decoration: none;
}

.item .item-wrap:hover img {
  transform: scale(1.05);
}

.item .item-wrap:hover:after {
  opacity: 1;
  visibility: visible;
}

.item .item-wrap:hover .work-info {
  margin-top: 0px;
  opacity: 1;
  visibility: visible;
}

.h3 {
  font-size: 20px;
}

.h4 {
  font-size: 16px;
}

.heading {
  font-size: 28px;
}

.readmore {
  display: inline-block;
  border: 1px solid #000;
  padding: 10px 15px;
  font-size: 12px;
  text-transform: uppercase;
  color: #000;
  transition: .2s all ease;
  font-weight: 700;
}

.readmore:active, .readmore:focus, .readmore:hover {
  outline: none;
}

.readmore:hover {
  color: #fff;
  text-decoration: none;
  background: #000;
}

.testimonials-slider .swiper-pagination {
  margin-top: -60px;
  position: relative;
}

.testimonials-slider .swiper-pagination .swiper-pagination-bullet {
  width: 12px;
  height: 12px;
  background-color: rgba(13, 30, 45, 0.3);
  opacity: 1;
}

.testimonials-slider .swiper-pagination .swiper-pagination-bullet-active {
  background-color: rgba(13, 30, 45, 0.6);
}

.sticky-content {
  position: sticky;
  position: -webkit-sticky;
  top: 0;
  /* required */
}

.list-line li {
  margin-bottom: 10px;
  position: relative;
  padding-left: 30px;
}

.list-line li:before {
  content: "";
  position: absolute;
  left: 0;
  top: .7rem;
  width: 10px;
  height: 2px;
  background: #000;
}

.form-control {
  border-radius: 0;
  background: #f8f9fa;
  border: 1px solid transparent;
  padding-top: 10px !important;
  padding-bottom: 10px !important;
}

.form-control:active, .form-control:focus {
  background: #eff1f4;
  outline: none;
  box-shadow: none;
  border: 1px solid transparent;
}

.custom-progress {
  height: 7px;
  border-radius: 0;
}

.custom-progress .progress-bar {
  background: #000;
}

/* Services */
.services i {
  font-size: 40px;
}

.services h4 {
  padding-top: 10px;
}

/* Contact Form */
.php-email-form .error-message {
  display: none;
  color: #fff;
  background: #ed3c0d;
  text-align: left;
  padding: 15px;
  font-weight: 600;
}

.php-email-form .error-message br + br {
  margin-top: 25px;
}

.php-email-form .sent-message {
  display: none;
  color: #fff;
  background: #18d26e;
  text-align: center;
  padding: 15px;
  font-weight: 600;
}

.php-email-form .loading {
  display: none;
  background: #fff;
  text-align: center;
  padding: 15px;
}

.php-email-form .loading:before {
  content: "";
  display: inline-block;
  border-radius: 50%;
  width: 24px;
  height: 24px;
  margin: 0 10px -6px 0;
  border: 3px solid #18d26e;
  border-top-color: #eee;
  -webkit-animation: animate-loading 1s linear infinite;
  animation: animate-loading 1s linear infinite;
}

@-webkit-keyframes animate-loading {
  0% {
    transform: rotate(0deg);
  }
  100% {
    transform: rotate(360deg);
  }
}

@keyframes animate-loading {
  0% {
    transform: rotate(0deg);
  }
  100% {
    transform: rotate(360deg);
  }
}

/*--------------------------------------------------------------
# Header
--------------------------------------------------------------*/
/* Custom Navmenu */
.custom-navmenu {
  background: #0d1e2d;
}

.custom-navmenu .custom-menu, .custom-navmenu .custom-menu li {
  padding: 0;
  margin: 0;
  list-style: none;
}

.custom-navmenu .custom-menu li {
  margin-bottom: 0;
  font-size: 20px;
}

.custom-navmenu .custom-menu li a {
  color: #fff;
  padding: 10px 0 !important;
}

.custom-navmenu .custom-menu li a:hover {
  text-decoration: none;
}

.custom-navmenu .custom-menu li.active a {
  text-decoration: underline;
}

.custom-navmenu h3 {
  font-size: 20px;
  color: #fff;
}

.custom-navmenu p {
  color: rgba(255, 255, 255, 0.6);
}

.custom-navmenu a {
  color: rgba(255, 255, 255, 0.7);
}

.custom-navmenu a:hover {
  color: #fff;
}

/* Custom Navbar */
.custom-navbar {
  padding-top: 50px;
  width: 100%;
}

@media (max-width: 780px) {
  .custom-navbar > .container {
    padding-right: 0;
    padding-left: 0;
  }
}

.custom-navbar .navbar-brand {
  font-size: 1.7rem;
}

/* Burger */
.burger {
  width: 28px;
  height: 32px;
  cursor: pointer;
  position: relative;
}

.burger:before, .burger span, .burger:after {
  width: 100%;
  height: 2px;
  display: block;
  background: #000;
  border-radius: 2px;
  position: absolute;
  opacity: 1;
}

.burger:before, .burger:after {
  transition: top 0.35s cubic-bezier(0.23, 1, 0.32, 1), transform 0.35s cubic-bezier(0.23, 1, 0.32, 1), opacity 0.35s cubic-bezier(0.23, 1, 0.32, 1), background-color 1.15s cubic-bezier(0.86, 0, 0.07, 1);
  -webkit-transition: top 0.35s cubic-bezier(0.23, 1, 0.32, 1), -webkit-transform 0.35s cubic-bezier(0.23, 1, 0.32, 1), opacity 0.35s cubic-bezier(0.23, 1, 0.32, 1), background-color 1.15s cubic-bezier(0.86, 0, 0.07, 1);
  content: "";
}

.burger:before {
  top: 4px;
}

.burger span {
  top: 15px;
}

.burger:after {
  top: 26px;
}

/* Hover */
.burger:hover:before {
  top: 7px;
}

.burger:hover:after {
  top: 23px;
}

/* Click */
.burger.active span {
  opacity: 0;
}

.burger.active:before, .burger.active:after {
  top: 40%;
}

.burger.active:before {
  transform: rotate(45deg);
}

.burger.active:after {
  transform: rotate(-45deg);
}

.burger:focus {
  outline: none;
}

.social a {
  display: inline-block;
  width: 50px;
  height: 50px;
  border-radius: 50%;
  background: #f8f9fa;
  position: relative;
  text-align: center;
  color: #0d1e2d;
}

.social a span {
  display: inline-block;
  left: 50%;
  position: absolute;
  top: 50%;
  transform: translate(-50%, -50%);
}

.social a:hover {
  color: #000;
}

</style>