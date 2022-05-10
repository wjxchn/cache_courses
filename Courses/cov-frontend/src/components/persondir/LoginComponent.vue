<template>
  <main>
    <div class="bg">
      <div class="logindiv" >
        <div class="row g-3 needs-validation loginform" novalidate>
          <h1 align="center">登录</h1>
          <div class="col-12">
            <label for="validationCustomUsername" class="form-label">邮箱</label>
            <div class="input-group has-validation">
              <span class="input-group-text" id="inputGroupPrepend">@</span>
              <input v-model="mail" type="email" class="form-control" id="validationCustomUsername" aria-describedby="inputGroupPrepend" required>
              <div class="invalid-feedback">
                邮箱格式错误
              </div>
            </div>
          </div>
          <div class="col-12">
            <label for="validationCustom03" class="form-label">密码</label>
            <input v-model="password" type="password" class="form-control" id="validationCustom03" required>
            <div class="invalid-feedback">
              Please provide a valid city.
            </div>
          </div>
          <div align="center" class="col-12">
            <button class="btn btn-secondary" @click="login">登录</button>
            <button class="btn btn-secondary" style="margin-left:20px;" @click="toregister">注册</button>
          </div>
        </div>
      </div>
    </div>
  </main>
</template>

<script>
export default {
  name: 'LoginComponent',
  data(){
    return{
      mail:"",
      password:"",
      mail_is_valid:false
    }
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
  methods:{
    toregister(){
      this.$router.push('/register');
    },
    tofindpassword(){
      this.$router.push('/findpassword');
    },
    login(){
      this.postRequest(
        '/user/login',
        {
          mail:this.mail,
          password:this.password
        }
      )
        .then((response) => {
          console.log(response);
          if(response.code=="200"){
            this.$message({message: '登录成功', type: 'success'})
            this.$router.push('/')
          }
          else{
            this.$message({message: response.msg, type: 'error'})
          }
        })
        .catch((error) => {
          console.log(error)
        })
    }
  }
}
</script>

<style scoped>
.bg{
  /* width:100%; */
  height:700px;
  background-image: url("../../assets/picdir/logimage.jpg");
  background-size: 100% 100%;
  background-attachment: fixed;
  background-repeat: no-repeat;
  background-size: cover;
}
.logindiv{
  width:400px;
  position: absolute;
  top:100px;
  background-color: white;
  left:50%;
  transform: translateX(-50%);
  border-radius: 10px;
}
.loginform{
  margin:15px;
}
.valid{
  display:none;
}
</style>