<template>
  <div class="login">
  <div class="hed" style="text-align:center">
		<el-image style="height:120px;width:405px" :src="'http://r.photo.store.qq.com/psc?/V143D3j445iBwL/45NBuzDIW489QBoVep5mcVXyL*BsvZygoyXkXSowchA7gJ2NMBMBsOjMwY5piqegdZCDtFL6KmYG89tApO1qbCXbnAYUG9HzopHGRYUR1HI!/r'"></el-image>
		<h1 style="color:#f96332" >登录</h1>
	</div>
    <div class="bc" >
          <el-form class="mmain" :model="ruleForm2" :rules="rules2" status-icon ref="ruleForm2">
            <el-form-item label-width="130px" style="width:370px" prop="username">
                <el-input type="text" v-model="ruleForm2.username" auto-complete="off" placeholder="用户名"></el-input>
            </el-form-item>
            <el-form-item label-width="130px" style="width:370px" prop="password">
                <el-input type="password" v-model="ruleForm2.password" auto-complete="off" placeholder="密码"></el-input>
            </el-form-item >
            <el-form-item label-width="175px">
              <el-button style="background-color:#f96332;color:white;" @click="handleSubmit" >登录</el-button>
              <el-button style="background-color:#f96332;color:white;" @click="Guider" >返回</el-button>
            </el-form-item>
            <el-form-item label-width="270px" >
                <el-button style="color:#f96332" type="text" @click="forgetpassword">忘记密码?</el-button>
            </el-form-item>
            <el-form-item label="还未注册？点击此处注册" label-width="370px">
                <el-button style="background-color:#f96332;color:white;" @click="Regi" >注册</el-button>
            </el-form-item>
          </el-form>
        </div>
    </div>
</template>

<script>
import axios from 'axios'
export default {
  data() {
    return {
        logining: false,
        ruleForm2: {
          username: '',
          password: ''
        },
        rules2: {
          account: [
            { required: true, message: '请输入账号', trigger: 'blur' },
          ],
          checkPass: [
            { required: true, message: '请输入密码', trigger: 'blur' },
          ]
        },
        checked: true
      };
    },
    methods: {
      Regi(){
        this.$router.push('/Regi')
      },
      Guider(){
        this.$router.push('/')
      },
      handleReset2() {
        this.$refs.ruleForm2.resetFields();
      },
      handleSubmit(ev) {
        this.$refs.ruleForm2.validate((valid) => {
          if (valid) {
            this.logining = true;
            axios({
                method: 'post',
                url: 'http://59.110.160.141/api/login/',
                data: {'username': this.ruleForm2.username, 'password': this.ruleForm2.password}
            })
            .then(response => {
                console.log(response)
                if(response.data.code===200){
                    localStorage.setItem('username', this.ruleForm2.username);
                    localStorage.setItem('playcookie', true);
                    this.$router.push('/PersonalDoc')
                }
                else if(response.data.code===400){
                    alert('账号或密码错误')
                    this.$router.go(0)
                }
                else{
                    alert('错误')
                    this.$router.go(0)
                }
            })
            .catch(error => {
                console.log(error)
                alert('出现错误')
                this.$router.go(0)
            })
          } else {
            alert('登录失败');
            return false;
          }
        });
      },
      forgetpassword(){
          this.$router.push('/findpassword')
      }
    }
  }
</script>

<style scoped>
.el-checkbox__input is checked{
  fill:#f96332;
  border-color:#f96332;
  color:#f96332;
}
.login
{
    width:100%;
    height:100%;
    z-index:-1;
    position:fixed;
	  background-color:#f7f7f7;
    position: fixed;
    background-size: 100% 100%;
    overflow-y: auto;
}
.bc
{
    background-color: rgba(255, 255, 255, 0.7);
    border-radius:50px;
    margin:0 auto;
    margin-top:5%;
    width: 500px;
}
.mmain{
    padding-top:5%;
    width: 500px;
}
</style>
