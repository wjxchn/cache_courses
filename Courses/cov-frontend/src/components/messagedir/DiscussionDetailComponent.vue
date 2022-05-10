<template>
  <main>
    
      <div class="container">
        <div class="row">
          <div class="col-12" style="margin-top: 50px">
            <div class="card">
              <div class="card-body">
                <div class="mt-4">
                  <h2 style="font-family: 'rr'">{{question.title}}</h2>
                </div>
                <div>
              <span style="font-family: 'rr';font-size: 20px">
              {{question.content}}
              </span>
                </div>
                <div>
                  <button class="btn btn-outline-primary rounded-pill" data-bs-toggle="modal" data-bs-target="#comment" style="width: 110px;margin-top: 10px">
                    <svg t="1625971711377" class="icon" viewBox="0 0 1024 1024" version="1.1" xmlns="http://www.w3.org/2000/svg" p-id="6493" width="20" height="20">
                      <path d="M949.570847 212.673727l-41.801035 41.517579L768.565377 115.843378l41.801035-41.459251c15.340383-15.283078 39.522132-16.084327 53.892421-1.768273l87.024006 86.454024C965.710432 173.382862 964.91123 197.393719 949.570847 212.673727L949.570847 212.673727zM580.373227 579.594491 441.169815 441.244516l306.238706-304.299541 139.205459 138.348951L580.373227 579.594491 580.373227 579.594491zM560.984644 598.869486l-194.863083 55.314817 55.659671-193.666838L560.984644 598.869486 560.984644 598.869486zM236.551554 178.118724c-48.13223 0-87.081311 38.949081-87.081311 87.024006l0 522.372232c0 48.062646 38.962384 87.026052 87.026052 87.026052l522.485819 0c48.063669 0 87.028099-38.963407 87.028099-87.028099L846.010213 439.248046l87.079264-87.028099 0 464.321094c0 80.124875-64.954361 145.078213-145.078213 145.078213L207.468169 961.619254c-80.124875 0-145.078213-64.954361-145.078213-145.078213L62.389956 236.114602c0-80.124875 64.954361-145.078213 145.078213-145.078213l464.435705 0-87.083357 87.083357L236.551554 178.119747 236.551554 178.118724z" p-id="6494" fill="#8a8a8a">
                      </path>
                    </svg>
                    写回答
                  </button>
                  <div class="col-12  mb-4">
                    <div class="modal fade" id="comment" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
                      <div class="modal-dialog">
                        <div class="modal-content">
                          <div class="modal-header">
                            <h5 class="modal-title" id="exampleModalLabel">评论当前问题</h5>
                            <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                          </div>
                          <div class="modal-body">
                            <form>
                              <div class="mb-3">
                                <label for="msesage-text" class="col-form-label">我的评论:</label>
                                <textarea class="form-control" v-model="my_comment"></textarea>
                              </div>
                            </form>
                          </div>
                          <div class="modal-footer">
                            <button class="btn btn-outline-success" @click="publishcomment" data-bs-dismiss="modal">发布评论</button>
                            <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">取消</button>
                          </div>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </div>
        </div>

        <!-- 去掉了margin-top,margin-bottom实现填充 -->
      
        <div class="row">
          <div class="col-12">
            <div class="card">
              <div class="comment-widgets  scrollable" v-for="(item,i) in comments" :value="i" v-bind:key="i" >
                <div v-if="i%2==0" :value="i" v-bind:key="i"  style="background:#f8f9fa">
                    <div class="container" >
                      <div class="row">
                        <div class="col-md-12 comment-ph2" style="font-family: rr;font-size: 20px;padding-top: 0.5vw" >
                          <img src="../../assets/picdir/icon.jpeg" alt="user" width="50" class="rounded-circle comment-ph2">
                          {{item.name}}
                        </div>
                      </div>
                      <div style="font-family: rr;font-size: 20px;color: gray">
                        评论于：{{item.time}}
                      </div>                
                    </div>
                    <!-- 问题主体 -->
                    <div>
                      <div class="comment-text w-100" style="font-family: rr;font-size: 20px;">
                        {{item.content}}                        
                      </div>
                    </div>
                </div>
                <div v-else>
                  <div class="container" >
                    <div class="row">
                      <div class="col-md-12 comment-ph2" style="font-family: rr;font-size: 20px;padding-top: 0.5vw" >
                        <img src="../../assets/picdir/icon.jpeg" alt="user" width="50" class="rounded-circle comment-ph2">
                        {{item.name}}<span style="color: gray;font-size: 15px">，{{item.introduction}}</span>
                      </div>
                    </div>
                    <div style="font-family: rr;font-size: 20px;color: gray">
                      评论于：{{item.time}}
                    </div>
                  </div>
                  <!-- 问题主体 -->
                  <div>
                    <div class="comment-text w-100" style="font-family: rr;font-size: 20px;">
                      {{item.content}}
                    </div>
                  </div>
                </div>
              </div>
            </div>    
          </div>
        </div>
      </div>
  </main>
</template>

<script>
export default {
  name: 'DiscussionDetailComponent',
  data(){
    return{
      comments:[],
      question:{},
      my_comment:"",
      username:"",
    }
  },
  created(){
    this.postRequest(
      
      "/social/showquestiondetail",
      {
        question_id:this.$route.query.question_id
      }
    ).then((response) =>{
      if(response.code==="200"){
        this.question = response.data.question
        this.username = response.data.username
        this.comments = response.data.comments
        for(let i=0 ; i<this.comments.length; i++){
          this.comments[i].img = require("../../assets/picdir/headph1.jpg")
        }
        console.log(this.question)
        console.log(this.comments)
      }
      else{
        alert(response.msg)
      }
    } )
  },
	methods:{
	toDiscuss(){
		this.$router.push('/discussion');
	},
  toMyPage(){
    this.$router.push('/person')
  },
  publishcomment(){
    console.log("走到这里了吗")
    this.postRequest(
      "/social/publishcomment",
      {
        question_id:this.question.id,
        content:this.my_comment
      },
      {
        token:this.$cookies.get("token")
      }
    ).then((response) => {
      if(response.code==="200"){
        alert("发布成功")
        this.$router.go(0);
      }
      else{
        alert(response.msg)
      }
    })
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
.fixedbutton2{
  position:fixed;
  background-color: white;
  margin-top: 220px;

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

.comment-ph2{
  margin-top: 10px;
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