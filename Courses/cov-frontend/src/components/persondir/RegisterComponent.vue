<template>
  <main>
    <div class="bg">
    <div class="registerdiv">
      <div class="row g-3 needs-validation registerform" novalidate>
        <h1 align="center">注册</h1>
        <div class="col-12">
          <label for="validationCustomUsername" class="form-label">邮箱</label>
          <div class="input-group has-validation">
            <span class="input-group-text" id="inputGroupPrepend">@</span>
            <input v-model="mail" type="email" class="form-control" id="validationCustomUsername" aria-describedby="inputGroupPrepend" required @blur="checkmail">
            <div class="invalid-feedback">
              邮箱已被注册！
            </div>
          </div>
        </div>
        <div class="col-12">
          <label for="validationCustomUsername" class="form-label">用户名</label>
          <div class="input-group has-validation">
            <input v-model="username" type="email" class="form-control" id="validationCustomUsername" aria-describedby="inputGroupPrepend" required>
            <div class="invalid-feedback">
              用户名已被注册！
            </div>
          </div>
        </div>
        <div class="col-12">
          <label for="validationCustom03" class="form-label">密码</label>
          <input v-model="password" type="password" class="form-control" id="validationCustom03" required >
          <div style="font-size: 15px;font-family: rr;color: gray">
            您的密码长度必须为 8-24 个字符，包含字母和数字，并且不得包含空格、特殊字符或表情符号
          </div>
          <div class="invalid-feedback">
            您的密码长度必须为 8-24 个字符，包含字母和数字，并且不得包含空格、特殊字符或表情符号
          </div>
        </div>
        <div class="col-12">
          <label for="validationCustom03" class="form-label">确认密码</label>
          <input v-model="confirm_password" type="password" class="form-control" id="validationCustom03" required>
          <div class="invalid-feedback">
            请确认您的密码
          </div>
        </div>
        <div class="col-12">
          <div class="form-check">
            <input v-model="ischeck" class="form-check-input" type="checkbox" value="" id="invalidCheck" required>
            <label class="form-check-label" for="invalidCheck">
              同意网站条款
            </label>
            <div class="invalid-feedback">
              You must agree before submitting.
            </div>
          </div>
        </div>
        <div class="col-12" align="center">
          <button  class="btn btn-secondary" @click="register">注册</button>
        </div>
      </div>
    </div>
    </div>
  </main>
</template>

<script>
export default {
  data(){
    return{
      username:"",
      mail:"",
      mail_is_valid:true,
      password:"",
      bPwd: null,//密码值和长度的验证
      degreeNumber: 0,//密码复杂度的验证
      regum:0,
      confirm_password:"",
      ischeck:false,
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
     checkmail(){
      this.postRequest(
        '/user/checkmail',
        {
          mail:this.mail
        }
       )
        .then((response) => {
          if(response.code==="200"){
            this.mail_is_valid=true
            }
          else{
            this.mail_is_valid=false
            }
        })
        .catch((error) => {
          console.log(error)
        })
    },
    passwordValid() {
        if (this.password === null || this.password.length < 8 || this.password.length > 24 || this.password.trim().length === "") {
          this.bPwd = false;
        } else {
          this.bPwd = true;
        }
        let arrVerify = [
          {regName: 'Number', regValue: /^.*[0-9]+.*/},
          {regName: 'LowerCase', regValue: /^.*[a-z]+.*/},
          {regName: 'UpperCase', regValue: /^.*[A-Z]+.*/},
          {regName: 'SpecialCharacters', regValue: /^.*[^a-zA-Z0-9]+.*/}
        ];
        let regNum = 0;// 记录匹配的次数
        for (let iReg = 0; iReg < arrVerify.length; iReg++) {
          if (arrVerify[iReg].regValue.test(this.password)) {
            regNum = regNum + 1;
          }
        }
        this.degreeNumber = regNum;
      },
    register(){
      this.passwordValid()
      console.log(this.ischeck)
      if(this.bPwd===false || this.degreeNumber <=1 ){
        this.$message({message: "密码长度应在8-24个字符之间，且必须包含大小写字母、数字和特殊字符中的两个或两个以上", type: 'error'})
      }
      else if(this.password !== this.confirm_password){
        this.$message({message: "密码与确认密码不相同", type: 'error'})
      }
      else if(this.ischeck === false){
        this.$message({message: "同意网站条款方可注册", type: 'error'})
      }
      else if(this.username === null || this.username === ''){
        this.$message({message: "用户名不能为空", type: 'error'})
      }
      else if(this.mail === null || this.mail === ''){
        this.$message({message: "邮箱不能为空", type: 'error'})
      }
      else{
        this.postRequest(
        '/user/register',
        {
          username:this.username,
          mail:this.mail,
          password:this.password
        }
       )
        .then((response) => {
          if(response.code==="200"){
            this.$message({message: "注册成功", type: 'success'})
            console.log(response.data.user)
            this.$router.push('/login');
            }
          else{
            console.log(response)
            this.$message({message: "邮箱或用户名已被注册", type: 'error'})
          }
        })
        .catch((error) => {
          console.log(error)
        })
      }    
    },
   }
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
.registerdiv{
  width:400px;
  position: absolute;
  top:100px;
  background-color: white;
  left:50%;
  transform: translateX(-50%);
  border-radius: 10px;
}
.registerform{
  margin:15px;
}
.valid{
  display:none;
}
</style>