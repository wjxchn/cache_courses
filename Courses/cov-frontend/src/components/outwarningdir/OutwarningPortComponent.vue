<template>
  <main>
    <div class="row">
      <div class="col-12  mt-4">
        <h2 style="text-align:center; font-family: 'rr'">疫情出行信息</h2>
      </div>
      <div class="col-12">
        <p style="text-align:center; font-family: 'Times New Roman'">Travel information of COVID-19</p>
      </div>
    </div>
    <div class="container marketing">
      <!--导航栏-->
      <el-menu :default-active="this.$route.path" class="el-menu-demo" router mode="horizontal" @select="handleSelect">
        <el-menu-item index="/outwarning">国内出行预警</el-menu-item>
        <el-menu-item index="/outwarningport">口岸通行情况</el-menu-item>
        <el-menu-item index="/outwarningworld">国际出行预警</el-menu-item>
      </el-menu>
      <!--我国口岸通行情况查询-->
      <div class="row featurette" style="margin-top:2%">
        <div class="col-8">
          <h2 class="featurette-heading" style="font-family: 'rr'">中国口岸通行情况查询
            <span class="badge bg-danger" style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter">更新于{{new Date(updateTime).format('yyyy-MM-dd hh:mm:ss')}}</span>
          </h2>
           <p class="lead" style="font-family: 'Times New Roman'">Port traffic situation in our country. 
             <a style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter;color: gray">数据来源于<a href="https://www.nia.gov.cn/n741435/n907688/n1234186/n1248056/index.html">国家移民管理局</a></a>
           </p>
        </div>
        <div class="col-4" >
          <el-input
            placeholder="请输入口岸名称"
            prefix-icon="el-icon-search"
            v-model="keyword"
            @input="getByKeywordAndProvince">
          </el-input>
        </div>
        <div>
          <div class="button-list">
            <el-button :type="provinceCode == index?'primary':''" @click="changeProvince(index)" v-for="(province,index) in provinceNameList" :key="index" style="width:80px;">{{province}}</el-button>
          </div>
        </div>
        <el-divider></el-divider>
        <el-table
          :data="portlist">
          <el-table-column
            prop="name"
            label="口岸名称"
            width="auto">
            <template slot-scope="scope">
              <div style="font-size: 20px;font-family: rr;font-weight: bold;color: black">
                {{scope.row.name}}
              </div>
            </template>
          </el-table-column>
          <el-table-column
          prop="content"
          width="800"
          label="口岸情况">
            <template slot-scope="scope">
              <div style="font-size: 20px;font-family: rr;color: black">
                {{scope.row.content}}
              </div>
            </template>
          </el-table-column>
        </el-table>
      </div>
    </div>
  </main>
</template>

<script>
import "@/assets/fontdir/font.css";
export default {
  components:{
  },
  data(){
    return{
      portlist:[
        {
          name: '首都机场口岸',
          content: '正常 全天',
          time: '2021-07-11 09:21:47'
        },
        {
          name: '大兴机场口岸',
          content: '临时性停航',
          time: '2021-07-11 09:21:47'
        },
      ],
      updateTime: '', 
      keyword:"",
      province:"北京",
      provinceCode: 0,
      provinceNameList: [
        '北京',
        '天津',
        '河北',
        '山西',
        '内蒙古',
        '辽宁',
        '吉林',
        '黑龙江',
        '上海',
        '江苏',
        '浙江',
        '安徽',
        '福建',
        '江西',
        '山东',
        '河南',
        '湖北',
        '湖南',
        '广东',
        '广西',
        '海南',
        '重庆',
        '四川',
        '贵州',
        '云南',
        '西藏',
        '陕西',
        '甘肃',
        '青海',
        '宁夏',
        '新疆',
      ]
    }
  },
  created() {
    this.getByKeywordAndProvince()
  },
  methods:{
    changeProvince(index){
      this.provinceCode = index
      this.province = this.provinceNameList[index]
      this.getByKeywordAndProvince()
    },
    
    getByKeywordAndProvince(){
      this.postRequest(
          "/nialist/getportbykeyword",
          {
              keyword:this.keyword,
              province:this.province,
          }
      ).then( (res)=> {
          if(res.code==="200"){
              console.log(res.data)
              this.portlist=res.data.portlist
              console.log(this.portlist)
              if(this.portlist.length > 0)
                this.updateTime = this.portlist[0].time
          }
          else{
              console.log("返回了400")
          }
      } )
    },   
    handleSelect(key, keyPath) {
      console.log(key, keyPath);
    },
  }
}
</script>

<style scoped>
.button-list {
  width: 100%;
  line-height: 50px;
}
.button-list .el-button {
  margin-left: 25px;
}
.info {
  width: 90%;
  margin: 20px auto;
}
.info .name {
  height: 30px;
  line-height: 30px;
  font-size: 20px;
  font-weight: 600;
  margin: 5px auto;
}

.info .content {
  font-size: 16px;
  text-indent: 1rem;
}
</style>