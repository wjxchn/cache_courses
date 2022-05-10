<template>
  <main>
    <div class="container marketing">
      <div class="row featurette">
        <div class="col-12" style="width:100%;height:20px;"></div>
        <div class="col-md-2" style="margin: auto;">
          <select
              class="form-select"
              v-model="ProvinceCode"
              aria-label="Default select example"
              @change="changeProvince"
          >
            <option v-for="(item, i) in chinaData" :value="i" v-bind:key="i">{{item.name}}</option>
          </select>
        </div>
        <div class="col-12">
          <div style="font-family: 'rr';font-size: 40px;margin: 20px" align="center">{{chinaData[ProvinceCode].name}}疫情数据追踪：图表与数据总览</div>
        </div>
        <div class="badge rounded-pill bg-danger mx-auto" style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter;width: auto">更新于{{new Date(chinaData[ProvinceCode].cov_data.time).format('yyyy-MM-dd hh:mm:ss')}}</div>
        <a style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter;color: gray;text-align: right">数据来源于<a href="https://news.qq.com/zt2020/page/feiyan.htm#/">腾讯疫情</a></a>
      </div>
      <div class="row">
        <div class="col-xl-8">
          <Chart time="2021.07.03 12:00" title="疫情概况" :cov_data="chinaData[ProvinceCode].cov_data"></Chart>
          <div style="width:100%;height:10px;"></div>
          <div class="card curve" style="height: 500px">
            <div class="card-title curve">
              <div style="font-family: 'rr';font-size: 30px;margin-top: 10px;margin-bottom: -10px;text-align:center;">历史数据曲线</div>
            </div>
            <div class="card-body" style="padding-top: -200px">
              <TrendChartComponent data-zoom="true" height="400" mapId="TrendChartComponent" ref="chinachartref" :dimensions="['confirm','dead','heal', 'confirm_add']" :dataList="provinceDataList[ProvinceCode]"></TrendChartComponent>
            </div>
          </div>
        </div>
        <div class="col-xl-4">
          <div class="card">
            <div class="card-body">
              <div style="font-family: 'rr';font-size: 30px;">
                最新新闻
                <span class="badge bg-primary" style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter">速报</span>
                <el-link style="font-size: 15px;float: right;margin-top: 15px" :underline="false" :href="NewsDir"> 查看更多</el-link>
              </div>
              <div style="max-height: 711px;overflow-y: scroll;overflow-x: hidden">
                <vlist blankmessage="暂无新闻" :datalist="chinanews" v-slot="items" :pagination="false">
                  <el-link style="font-family: 'rr';font-size: 25px" :href="items.item.url" target="_blank" :underline="false">
                    {{items.item.title}}
                  </el-link>
                  <div class="row" style="font-family: rr;font-size: 15px;color: gray">
                    <div class="col">
                    新闻来源：{{items.item.site}}   
                    </div>
                    <div class="col">
                    {{items.item.time}}
                    </div>
                  </div>
                </vlist>
              </div>
            </div>
          </div>
        </div>
        <div class="col-xl-6">
          <div class="dropdown-divider"></div>
          <div style="font-size: 30px;font-family: 'rr';">疫情地图</div>
          <div>
            <ProvinceMapComponent mapId="provincemapid" ref="provincemapref" :mapdata="chinaData[ProvinceCode]" :mapname="chinaData[ProvinceCode].name"></ProvinceMapComponent>
          </div>
          <div class="dropdown-divider"></div>
        </div>
        <div class="col-xl-6">
          <div class="dropdown-divider"></div>
          <div style="font-size: 30px;font-family: 'rr'">
            地区详细信息
          </div>
          <el-table
              :data="chinaData[ProvinceCode].locations"
              border
              :default-sort = "{prop: 'risk', order: 'descending'}"
              max-height="610"
              style="width: 100%"
              :header-row-style="{'font-family': 'Heiti SC','font-weight':'lighter','font-size':'17px','color':'black'}"
              :cell-style="{'font-family':'rr','font-size':'17px','color':'black'}">
            <el-table-column
                v-if="false"
                prop="index"
                width="140"
            >
            </el-table-column>
            <el-table-column
                prop="name"
                label="地区"
                width="auto">
            </el-table-column>
            <el-table-column
                prop="cov_data.confirm_add"
                label="新增确诊"
                sortable
                width="90"
            >
              <template slot-scope="scope">
                <div style="font-size: 20px">{{scope.row.cov_data.confirm_add}}</div>
              </template>
            </el-table-column>
            <el-table-column
                prop="cov_data.now_confirm"
                label="现有确诊"
                sortable
                width="90">
              <template slot-scope="scope">
                <div style="font-size: 20px">{{scope.row.cov_data.now_confirm}}</div>
              </template>
            </el-table-column>
            <el-table-column
                prop="cov_data.heal"
                label="治愈"
                sortable
                width="80">
              <template slot-scope="scope">
                <div style="font-size: 20px">{{scope.row.cov_data.heal}}</div>
              </template>
            </el-table-column>
            <el-table-column
                prop="cov_data.dead"
                label="死亡"
                sortable
                width="80">
              <template slot-scope="scope">
                <div style="font-size: 20px">{{scope.row.cov_data.dead}}</div>
              </template>
            </el-table-column>
            <el-table-column
                prop="risk"
                label="风险级别"
                sortable
                width="90"
            >
              <template slot-scope="scope" >
                <div :style="getCellStyle(scope.row.risk)">
                  <div v-if="scope.row.name !== '境外输入'">
                    {{scope.row.risk}}
                  </div>
                  <div v-if="scope.row.name === '境外输入'">
                    --
                  </div>
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
import ProvinceMapComponent from "@/components/mapdir/ProvinceMapComponent";
import Chart from "@/components/provincedir/ProvinceChart";
import TrendChartComponent from "@/components/chartsdir/TrendChartComponent";
import Vlist from "@/components/newsdir/Vlist";
import "@/assets/fontdir/font.css";
export default {
  name: 'ProvinceInfo',
  components:{
    ProvinceMapComponent,
    Chart,
    TrendChartComponent,
    Vlist
  },
  data(){
    return{
      ProvinceCode: 0,
      chinaData: [
        {
          cov_data:{
            confirm:0,no_infect_add:0,no_infect:0,dead_add:0,heal:0,now_confirm:0,dead:0,now_confirm_add:0,heal_add:0,confirm_add:0
          },
          name:"",belong_id:"",risk:"",locations:[],id:"",type:"",value:""
        }
      ],
      provinceDataList: [],
      RiskRegion:[],
      chinalocations:[],
      chinanews: [],
      NewsDir: '',
      location_id: 0,
    }
  },
  created(){
    this.ProvinceCode = this.$route.query.provincecode
    let routeData = this.$router.resolve({ path: '/news'});
    this.NewsDir = routeData.href
    var that = this;
    this.postRequest('/covdata')
        .then((response) => {
          that.chinaData = response.data.locations;} )
        .catch((error) => { console.log(error) })

    this.postRequest('/history/getallprovincedaylist')
        .then((res) => {
          that.provinceDataList = res.data;} )
        .catch((error) => { console.log(error) })
  },
  mounted(){
    var that = this;
    this.postRequest('/covdata')
        .then((response) => {
          that.chinaData = response.data.locations;
          this.location_id =  this.chinaData[this.ProvinceCode].id
          if (this.chinaData[this.ProvinceCode].name === '西藏自治区' || this.chinaData[this.ProvinceCode].name === '新疆维吾尔自治区' || this.chinaData[this.ProvinceCode].name === '青海省')
          {
            console.log("没有新闻")
            this.chinanews = []
          }
          else {
            this.postRequest('/news',{locationId:this.location_id})
                .then((response) => {
                  console.log("有新闻");
                  that.chinanews = response.data;
                } )
                .catch((error) => { console.log("获取中国新闻异常======" + error) })
          }
        } )
        .catch((error) => { console.log(error) })

    this.postRequest('/history/getallprovincedaylist')
            .then((res) => {
              that.provinceDataList = res.data;} )
            .catch((error) => { console.log(error) })

    window.onresize = () => {
      that.$refs.provincemapref.myChart.resize();
      that.$refs.chinachartref.myChart.resize();
    }
  },
  methods:{
    changeProvince(){
      this.$router.push({
        path: '/province',
        query: {
          provincecode: this.ProvinceCode
        }
      });
      this.location_id =  this.chinaData[this.ProvinceCode].id
      console.log('地名')
      console.log(this.chinaData[this.ProvinceCode])
      if (this.chinaData[this.ProvinceCode].name === '西藏自治区' || this.chinaData[this.ProvinceCode].name === '新疆维吾尔自治区' || this.chinaData[this.ProvinceCode].name === '青海省')
      {
        console.log("没有新闻")
        this.chinanews = []
      }
      else {
        this.postRequest('/news',{locationId:this.location_id})
            .then((response) => {
              console.log("有新闻");
              this.chinanews = response.data;
            } )
            .catch((error) => { console.log("获取中国新闻异常======" + error) })
      }
    },
    goNewsPage(url){
      window.open(url)
    },
    getCellStyle(risk){
      let style;
      if (risk === '高' || risk === '中')
      {
        style = 'color:red;font-weight:bolder'
      }
      return style
    },
  }
}
</script>

<style scoped>
</style>