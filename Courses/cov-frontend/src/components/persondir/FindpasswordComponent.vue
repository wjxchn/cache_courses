<template>
  <main>
    <div class="bg">
    <div class="findpassworddiv">
      <form class="row g-3 needs-validation findpasswordform" novalidate>
        <h1 align="center">找回密码</h1>
        <div class="col-12">
          <label for="validationCustomUsername" class="form-label">邮箱</label>
          <div class="input-group has-validation">
            <span class="input-group-text" id="inputGroupPrepend">@</span>
            <input v-model="mail" type="email" class="form-control" id="validationCustomUsername" aria-describedby="inputGroupPrepend" required>
            <div class="invalid-feedback">
              请输入您注册时的邮箱
            </div>
          </div>
        </div>
        <div class="col-12">
          <label for="validationCustom03" class="form-label">新密码</label>
          <input v-model="password" type="password" class="form-control" id="validationCustom03" required>
          <div class="invalid-feedback">
            您的密码长度必须为 8-20 个字符，包含字母和数字，并且不得包含空格、特殊字符或表情符号
          </div>
        </div>
        <div class="col-12">
          <label for="validationCustom03" class="form-label">确认密码</label>
          <input v-model="confirm_password" type="password" class="form-control" id="validationCustom03" required>
          <div class="invalid-feedback">
            请确认您的密码
          </div>
        </div>
        <div align="center" class="col-12">
          <button class="btn btn-secondary" type="submit">登录</button>
        </div>
      </form>
    </div>
    </div>
  </main>
</template>

<script>
export default {
  data(){
    return{
      mail:"",
      password:"",
      confirm_password:""
    }
  },
  methods:{
    
  },
  mounted() {
    console.log(document.documentElement.clientWidth);
    console.log(document.documentElement.clientHeight);
    var bg = document.getElementsByClassName("bg")[0]
    bg.style.height = document.documentElement.clientHeight-65 + "px"
    window.onresize = () => {
      bg.style.height = document.documentElement.clientHeight-65 + "px"
    }
  },
}
</script>

<style scoped>
.bg{
  width:100%;
  background-image: url("../../assets/picdir/logimage.jpg");
  background-attachment: fixed;
  background-repeat: no-repeat;
  background-size: cover;
}
.findpassworddiv{
  width:400px;
  position: absolute;
  top:100px;
  background-color: white;
  left:50%;
  transform: translateX(-50%);
  border-radius: 10px;
}
.findpasswordform{
  margin:15px;
}
</style>