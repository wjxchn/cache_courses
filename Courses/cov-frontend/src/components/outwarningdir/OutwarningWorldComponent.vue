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
      <!--前往国家（地区）入境临时管制措施查询-->
      <div class="row featurette" style="margin-top:2%">
        <div class="col-8">
          <h2 class="featurette-heading" style="font-family: 'rr'">前往国家（地区）入境临时管制措施查询
            <span class="badge bg-danger" style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter">更新于{{new Date(policy[0].time).format('yyyy-MM-dd hh:mm:ss')}}</span>
          </h2>
           <p class="lead" style="font-family: 'Times New Roman'">To the country (region) temporary control measures for the query. 
             <a style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter;color: gray">数据来源于<a href="https://www.nia.gov.cn/n794014/n1050176/n1077211/n1215569/index.html">国家移民管理局</a></a>
           </p>
        </div>

        <div class="measure" style="margin-top:10px">
          <!-- <h1 >{{name}}
            <button type="button" size="small" class="btn btn-outline-success btn-lg" disabled>管控措施</button>
          </h1>
          {{policy}} -->
          <div>
            <div class="button-list">
              <p style="font-family: rr;font-size: 20px">热门地区</p>
              <el-button :type="provinceCode == index?'primary':''" @click="changeProvince(index)" v-for="(province,index) in provinceNameList" :key="index">{{province}}</el-button>
            </div>
          </div>

          <div class="dropdown-divider"></div>

          <div class="col-4">
            <el-input
                placeholder="请输入国家（地区）名称"
                prefix-icon="el-icon-search"
                v-model="keyword">
            </el-input>
          </div>

          <el-table
            :data="policy"
            stripe
            max-height="800"
            >
            <el-table-column
              prop="name"
              label="国家(地区)名称"
              width="200">
              <template slot-scope="scope">
                <div style="font-size: 20px;font-family: rr;font-weight: bold;color: black">
                  {{scope.row.name}}
                </div>
              </template>
            </el-table-column>
            <el-table-column
              prop="content"
              label="管控措施"
              width="auto">
              <template slot-scope="scope">
                <div style="font-size: 20px;font-family: rr;color: black;line-height: 30px">
                  {{scope.row.content}}
                </div>
              </template>
            </el-table-column>
          </el-table>
        </div>
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
      policy:[
        {
          name: '美国',
          content: '美国宣布公共卫生紧急状，自美东时间2月2日下午5时开始：1.过去14天内曾到访中国的外国人（美国公民和永久居民的直系亲属除外）将被暂时禁止入境；2.对过去14天去过湖北省的返美美国公民实行最长14天的强制隔离；3.对过去14天去过中国大陆其它地区的返美美国公民在指定口岸实行严格检查并要求在家实行有监控的自我隔离14天；4.来自中国的航班将只能在美国的纽约、洛杉矶、旧金山、西雅图、亚特兰大和檀香山七个机场入境，以便对旅客进行甄别。美国疾病控制和预防中心（CDC）目前要求，有特定国家或地区（目前包括中国、伊朗、韩国、欧洲申根国家、英国和爱尔兰）旅行历史记录的来美旅客，入美后在家或酒店及其他临时住所自我隔离14天，远离社交活动并密切关注身体健康。自3月20日起，暂停在世界各地使领馆的所有常规签证服务。自3月21日起，关闭美墨边境，美墨之间的贸易和商业往来仍将保持，相关的基本工人往来继续，但旅游目的的其他游客将无法跨境。同时关闭美国和加拿大边境，暂停两国之间的“非必要人员流动”。自5月26日23时59分起，暂停接受14天内到过巴西的外国旅客入境，不适用于美国公民、永久居民及其直系亲属。\n自2021年8月1日起，持有F/M签证的中国留学生不再受“赴美禁令”影响，可直接从中国飞往美国，无须在第三国停留至少14天。新规定仅适用于学术项目开始于今年8月1日及以后的学生，最早可以在项目开始前30天进入美国。 ',
          time: '2021-07-11 09:21:47'
        },
        {
          name: '智利',
          content: 'test',
          time: '2021-07-11 09:21:47'
        
        }
      ],
      keyword:"美国",
      provinceCode: 0,
      provinceNameList: [
        '美国','英国','日本','香港','澳门','澳大利亚','台湾'
      ]
    }
  },
  watch:{
    keyword: function (){
      this.getbykeyword()
    }
  },
  created(){
    this.postRequest(
            "/nialist/getpolicybykeyword",
            {
                keyword:this.keyword,
            }
        ).then( (res)=> {
            if(res.code==="200"){
                console.log(res.data)
                this.policy = res.data.policylist
            }
            else{
                console.log("返回了400")
            }
        } )
  },
  methods:{
    changeProvince(index){
      if(index === this.provinceCode)
      {
        this.keyword = ''
        this.provinceCode = null
      }
      else {
        this.provinceCode = index
        this.keyword = this.provinceNameList[index]
      }
    },
    getbykeyword(){
        this.postRequest(
            "/nialist/getpolicybykeyword",
            {
                keyword:this.keyword,
            }
        ).then( (res)=> {
            if(res.code==="200"){
                console.log(res.data)
                this.policy = res.data.policylist
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

    