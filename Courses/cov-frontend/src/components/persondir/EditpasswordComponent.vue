<template>
  <main>
    <div class="bg">
    <div class="editpassworddiv">
      <form class="row g-3 needs-validation editpasswordform" novalidate>
        <h1 align="center">修改密码</h1>
        <div class="col-12">
          <label for="validationCustom03" class="form-label">原密码</label>
          <input v-model="old_password" type="password" class="form-control" id="validationCustom03" required>
          <div class="invalid-feedback">
            您的密码长度必须为 8-24 个字符，包含字母和数字，并且不得包含空格、特殊字符或表情符号
          </div>
        </div>
        <div class="col-12">
          <label for="validationCustom03" class="form-label">新密码</label>
          <div style="font-size: 12px;color: gray">
            您的密码长度必须为 8-24 个字符，包含字母和数字，并且不得包含空格、特殊字符或表情符号, 且不能与原密码一致
          </div>
          <input v-model="password" type="password" class="form-control" id="validationCustom03" required>
          <div class="invalid-feedback">
            您的密码长度必须为 8-24 个字符，包含字母和数字，并且不得包含空格、特殊字符或表情符号, 且不能与原密码一致
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
          <button class="btn btn-secondary" @click="changepassword">确认修改</button>
          <button style="margin-left:10px" class="btn btn-secondary" type="submit" @click="toperson">返回</button>
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
      old_password:"",
      password:"",
      confirm_password:"",
      bPwd: null,//密码值和长度的验证
      degreeNumber: 0,//密码复杂度的验证
      regum:0,
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
      toperson(){
          this.$router.push('/person');
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
    changepassword(){
      this.passwordValid()
      console.log(this.ischeck)
      if(this.bPwd===false || this.degreeNumber <=1 ){
        this.$message({message: "密码长度应在8-24个字符之间，且密码必须包含大小写字母、数字和特殊字符中的两个或两个以上", type: 'error'})
      }
      else if(this.password !== this.confirm_password){
        this.$message({message: "密码与确认密码不相同", type: 'error'})
      }
      else if (this.password === this.old_password)
      {
        this.$message({message: "新密码和原密码不能相同", type: 'error'})
      }
      else{
        this.postRequest(
        '/user/changepassword',
        {
          old_password:this.old_password,
          new_password:this.password
        },
        {
          token:this.$cookies.get("token")
        }
        )
        .then((response) => {
          if(response.code==="200"){
            this.$message({message: "修改成功，请重新登录", type: 'success'})
            this.$cookies.remove("token")
            this.$router.push('/login')
            // this.$router.go(0)
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
.editpassworddiv{
  width:400px;
  position: absolute;
  top:100px;
  background-color: white;
  left:50%;
  transform: translateX(-50%);
  border-radius: 10px;
}
.editpasswordform{
  margin:15px;
}
</style>