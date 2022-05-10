<template>
<header style="padding-bottom: 64px">
  <nav class="navbar bg-white navbar-expand-lg navbar-light fixed-top" style="opacity: 0.9">
    <div class="container-fluid">
      <a class="navbar-brand" href="#/" style="font-family: 'Times New Roman';font-size: 25px">COVARIANCE</a>
      <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarCollapse" aria-controls="navbarCollapse" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarCollapse">
        <ul class="navbar-nav me-auto mb-2 mb-md-0">
          <li class="nav-item">
            <a class="nav-link" href="#/">中国疫情数据</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#/province?provincecode=5">分省疫情数据</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#/world">国际疫情数据</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#/outwarning">出行信息</a>
          </li>
            <li class="nav-item">
            <a class="nav-link" href="#/news">疫情新闻</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#/discussion" tabindex="-1" aria-disabled="true" v-show="this.$cookies.get('token')">疫情讨论</a>
          </li>
        </ul>
        <ul class="navbar-nav d-flex">
          <li class="nav-item" v-show="this.$cookies.get('token')">
            <a class="nav-link" href="#/person">我</a>
          </li>
          <li class="nav-item" v-show="!this.$cookies.get('token')">
            <a class="nav-link" href="#/login">登录</a>
          </li>
          <li class="nav-item" v-show="this.$cookies.get('token')">
            <a class="nav-link" style="cursor: pointer;" @click="logoutfunc()">退出</a>
          </li>
          <li class="nav-item">
            <a class="nav-link" href="#/register" v-show="!this.$cookies.get('token')">注册</a>
          </li>
        </ul>        
      </div>
    </div>
  </nav>
</header>
</template>

<script>
export default {
  name: 'NewHeader',
  methods:{
    logoutfunc(){
      this.$cookies.remove("token")
      this.$router.push("/login")
    }
  }
}
</script>

<style scoped>
/* RESPONSIVE CSS
-------------------------------------------------- */

@media (min-width: 40em) {
  /* Bump up size of carousel content */
  .carousel-caption p {
    margin-bottom: 1.25rem;
    font-size: 1.25rem;
    line-height: 1.4;
  }

  .featurette-heading {
    font-size: 50px;
  }
}

@media (min-width: 62em) {
  .featurette-heading {
    margin-top: 7rem;
  }
}
</style>