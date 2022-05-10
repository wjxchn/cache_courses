<template>
  <main>
    <div class="container">
      <div class="row">
        <div class="col-12">
          <div style="font-family: 'rr';font-size: 40px;margin: 20px" align="center">世界疫情数据追踪：图表与数据总览</div>
        </div>
        <div class="badge rounded-pill bg-danger mx-auto" style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter;width: auto">更新于{{new Date(globalData.cov_data.time).toLocaleString()}}
        </div>
        <a style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter;color: gray;text-align: right">数据来源于<a href="https://news.qq.com/zt2020/page/feiyan.htm#/">腾讯疫情</a></a>
      </div>
      <div class="row">
        <div class="col-xl-8">
          <Chart :time="new Date()" title="疫情概况" :data="globalData.cov_data"></Chart>
          <div class="card curve" style="height: 500px">
            <div class="card-title curve">
              <div style="font-family: 'rr';font-size: 30px;margin-top: 10px;margin-bottom: -10px">世界疫情图表</div>
            </div>
            <div class="card-body" style="padding-top: -200px">
              <TrendChartComponent data-zoom="true" height="400" :dimensions="['confirm','dead','heal','confirm_add']" :dataList="globaldaylist" mapId="test1" ref="countrycomponent1"></TrendChartComponent>
            </div>
          </div>
        </div>
        <div class="col-xl-4">
          <div class="card overflow-auto" style="max-height: 825px">
            <div class="card-body">
              <div style="font-family: 'rr';font-size: 30px;">
                新闻
                <span class="badge bg-primary" style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter">速报</span>
                <el-link style="font-size: 15px;float: right;margin-top: 15px" :underline="false" :href="NewsDir"> 查看更多</el-link>
              </div>
              <div class="dropdown-divider"></div>
              <vlist :datalist="foreignnews" v-slot="items" :pagination="false" :blankmessage="暂无新闻">
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
        <div class="col-xl-12">
          <div style="font-family: 'rr';font-size: 30px;padding-bottom: 10px">世界疫情现有确诊人数地图</div>
          <div class="border">
            <WorldMapComponent mapId="worldmapid" ref="worldmapref" v-bind:map-data="globalData.locations"></WorldMapComponent>
          </div>
        </div>
        <div class="col-xl-6">
          <div class="dropdown-divider"></div>
          <div style="font-family: 'rr';font-size: 30px;padding-bottom: 10px">
            各国现有病例、治愈、死亡及每百人疫苗接种数
          </div>
          <el-table
              :data="tableDataShow"
              border
              :default-sort = "{prop: 'cov_data.now_confirm', order: 'descending'}"
              height="682"
              style="width: 100%"
              align="center"
              header-row-style="font-family: 'Heiti SC';font-weight:lighter;font-size:17px;color:black"
              cell-style="font-family:rr;font-size:17px;color:black">
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
              <template slot="header" slot-scope="scope">
                <el-input
                    v-model="search"
                    size="mini"
                    placeholder="搜索地区"/>
              </template>
              <template slot-scope="scope">
                <i data-bs-toggle="offcanvas" data-bs-target="#offcanvasRight" aria-controls="offcanvasRight" class="el-icon-zoom-in" style="float: right" @click="showDrawer(scope.row)"></i>
                <div>{{scope.row.name}}</div>
              </template>
            </el-table-column>
            <el-table-column
                prop="cov_data.now_confirm"
                label="现有病例"
                sortable
                width="120">
              <template slot-scope="scope">
                <div style="font-size: 20px">
                  {{scope.row.cov_data.now_confirm}}
                </div>
              </template>
            </el-table-column>
            <el-table-column
                prop="cov_data.heal"
                label="治愈"
                sortable
                width="100">
              <template slot-scope="scope">
                <div style="font-size: 20px">
                  {{scope.row.cov_data.heal}}
                </div>
              </template>
            </el-table-column>
            <el-table-column
                prop="cov_data.dead"
                label="死亡"
                sortable
                width="100">
              <template slot-scope="scope">
                <div style="font-size: 20px">
                  {{scope.row.cov_data.dead}}
                </div>
              </template>
            </el-table-column>
            <el-table-column
                prop="cov_data.total_vaccinations_per_hundred"
                label="每百人疫苗接种"
                sortable
                width="100"
            >
              <template slot-scope="scope">
                <div style="font-size: 20px">
                  <div v-if="!isZero(scope.row.cov_data.total_vaccinations_per_hundred)">
                    {{scope.row.cov_data.total_vaccinations_per_hundred}}
                  </div>
                  <div v-if="isZero(scope.row.cov_data.total_vaccinations_per_hundred)">
                    -
                  </div>
                </div>
              </template>
            </el-table-column>
          </el-table>
        </div>
        <div class="col-md-6">
          <div class="dropdown-divider"></div>
          <div style="font-size: 30px;font-family: rr">
            数据分析与对比
          </div>
          <div>
            <div style="z-index: 1000;">
              <el-popover
                  placement="top-end"
                  width="200"
                  trigger="hover"
                  content="该项对比了当前疫情最严重(确诊人数最多)的8个国家，越严重的国家代表该国在过去到现在的时间段内疫情防控能力越差"
              >
              <span slot="reference" style="font-size: 20px;font-family: rr">
                <div style="text-align: center">
                  疫情严重国家确诊人数占比
                  <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-question-circle" viewBox="0 0 16 16">
                  <path d="M8 15A7 7 0 1 1 8 1a7 7 0 0 1 0 14zm0 1A8 8 0 1 0 8 0a8 8 0 0 0 0 16z"/>
                  <path d="M5.255 5.786a.237.237 0 0 0 .241.247h.825c.138 0 .248-.113.266-.25.09-.656.54-1.134 1.342-1.134.686 0 1.314.343 1.314 1.168 0 .635-.374.927-.965 1.371-.673.489-1.206 1.06-1.168 1.987l.003.217a.25.25 0 0 0 .25.246h.811a.25.25 0 0 0 .25-.25v-.105c0-.718.273-.927 1.01-1.486.609-.463 1.244-.977 1.244-2.056 0-1.511-1.276-2.241-2.673-2.241-1.267 0-2.655.59-2.75 2.286zm1.557 5.763c0 .533.425.927 1.01.927.609 0 1.028-.394 1.028-.927 0-.552-.42-.94-1.029-.94-.584 0-1.009.388-1.009.94z"/>
                </svg>
                </div>
              </span>
              </el-popover>
            </div>
            <WorldPieChart height="340" pie-id="pie1" ref="piecomponent1" :data-list="tableData" :now_confirm_all="globalData.cov_data.now_confirm"></WorldPieChart>
            <div class="dropdown-divider"></div>
            <el-popover
                placement="top-end"
                width="200"
                trigger="hover"
                content="该项对比选取了当前疫情最严重的8个国家，每百人疫苗接种数越多，在一定程度上将意味着该国在未来的疫情形势将有所好转"
            >
              <span slot="reference" style="font-size: 20px;font-family: rr">
                  <div style="text-align: center">
                    疫情严重国家每百人疫苗接种数对比
                    <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-question-circle" viewBox="0 0 16 16">
                    <path d="M8 15A7 7 0 1 1 8 1a7 7 0 0 1 0 14zm0 1A8 8 0 1 0 8 0a8 8 0 0 0 0 16z"/>
                    <path d="M5.255 5.786a.237.237 0 0 0 .241.247h.825c.138 0 .248-.113.266-.25.09-.656.54-1.134 1.342-1.134.686 0 1.314.343 1.314 1.168 0 .635-.374.927-.965 1.371-.673.489-1.206 1.06-1.168 1.987l.003.217a.25.25 0 0 0 .25.246h.811a.25.25 0 0 0 .25-.25v-.105c0-.718.273-.927 1.01-1.486.609-.463 1.244-.977 1.244-2.056 0-1.511-1.276-2.241-2.673-2.241-1.267 0-2.655.59-2.75 2.286zm1.557 5.763c0 .533.425.927 1.01.927.609 0 1.028-.394 1.028-.927 0-.552-.42-.94-1.029-.94-.584 0-1.009.388-1.009.94z"/>
                  </svg>
                  </div>
                </span>
            </el-popover>
            <WorldBarChart style="margin-bottom: -50px" bar-id="bar1" ref="barcomponent1" :data-list="tableData" :world_acc="globalData.total_vaccinations_per_hundred"></WorldBarChart>
          </div>
          <div class="dropdown-divider"></div>
        </div>
        <div class="offcanvas offcanvas-end" tabindex="-1" id="offcanvasRight" aria-labelledby="offcanvasRightLabel" style="width: 640px">
          <div class="offcanvas-header">
            <h5 id="offcanvasRightLabel" style="font-family: 'rr'">{{this.CountryName}}详细疫情数据</h5>
            <button type="button" class="btn-close text-reset" data-bs-dismiss="offcanvas" aria-label="Close"></button>
          </div>
          <div class="offcanvas-body" style="margin-left: -15px">
            <TrendChartComponent data-zoom="true" height="400" :dimensions="['confirm','dead','heal','confirm_add']" :dataList="countrydaylist[CountryIndex]" mapId='map5' ref="countrycomponent4"></TrendChartComponent>
          </div>
        </div>
      </div>
    </div>

  </main>
</template>

<script>
import WorldMapComponent from "@/components/mapdir/WorldMapComponent";
import TrendChartComponent from "@/components/chartsdir/TrendChartComponent";
import Chart from "@/components/worlddir/WorldChart";
import "@/assets/fontdir/font.css";
import WorldPieChart from "@/components/chartsdir/WorldPieChart";
import WorldBarChart from "@/components/chartsdir/WorldBarChart";
import Vlist from "@/components/newsdir/Vlist";
// import Vue from "vue";
export default {
  name: 'WorldInfo',
  components:{
    WorldBarChart,
    WorldPieChart,
    WorldMapComponent,
    Chart,
    TrendChartComponent,
    Vlist
  },
  watch:{
    search: function () {
      this.tableDataShow = this.tableData.filter(data => !this.search || data.name.toLowerCase().includes(this.search.toLowerCase()))
    }
  },
  data(){
    return{
      UpdateTime : '2021年7月5日14时14分',
      CountryIndex: 3,
      CountryName: '',
      foreignnews :[],
      statetext:'State of the virus\n' +
          'Update for July 1\n' +
          '\n' +
          'Another wave of the pandemic is hitting many parts of the world, with countries in Asia, Africa and Latin America experiencing their highest caseloads, driven in part by the highly contagious Delta variant of the virus.\n' +
          'Worried about virus variants and the new surge, the W.H.O. and health officials in many countries are urging people to continue — or resume — wearing masks, while new lockdowns and travel bans take effect from Australia to Bangladesh to South Africa to Portugal.\n' +
          'The European Union has started using digital travel passes to free people from some travel restrictions by showing that they are fully vaccinated, have recently tested negative for the virus, or have recently recovered from infection.',
      globalData: {
        cov_data:{
          confirm:0,no_infect_add:0,no_infect:0,dead_add:0,heal:0,now_confirm:0,dead:0,now_confirm_add:0,heal_add:0,confirm_add:0
        }
      },
      globaldaylist: [],
      countrydaylist: [],
      tableData: [],
      search: '',
      tableDataShow: [],
      drawer: false,
      NewsDir: '',
    }
  },
  mounted(){
    let routeData = this.$router.resolve({ path: '/news'});
    this.NewsDir = routeData.href
    this.postRequest('/news',{locationId:0})
        .then((response) => {
          this.foreignnews = response.data;} )
        .catch((error) => { console.log("获取外国新闻异常======" + error) })
    var that = this;
    this.postRequest("/history/overseasdaylist")
        .then((response) => {
          that.globaldaylist = response.data
        })
        .catch((error) => {
          console.log(error)
        })
    this.postRequest('/history/getallcountrydaylist')
        .then((res) => {
          that.countrydaylist = res.data;} )
        .catch((error) => { console.log(error) })
    this.postRequest('/globalcovdata')
        .then((response) => {
          this.globalData = response.data;
          this.tableData = that.globalData.locations;
          for(let i = 0 ; i<this.tableData.length; i++)
          {
            this.tableData[i].index = i
            if(this.tableData[i].cov_data.total_vaccinations_per_hundred == null){
              this.tableData[i].cov_data.total_vaccinations_per_hundred = 0
            }
          }
          this.tableDataShow = this.tableData
        } )
        .catch((error) => { console.log(error) })
    window.onresize = () => {
      that.$refs.worldmapref.myChart.resize();
      that.$refs.countrycomponent1.myChart.resize();
      that.$refs.countrycomponent4.myChart.resize();
      that.$refs.piecomponent1.myChart.resize();
      that.$refs.barcomponent1.myChart.resize();
    }
  },
  methods:{
    showDrawer(row){
      if (row.name === '中国')
      {
        this.$router.push('/')
        return
      }
      let index = row.index
      this.CountryIndex = index
      this.CountryName = this.tableData[index].name
    },
    isZero(data){
      return data === 0;
    }
  }
}
</script>

<style scoped>
.curve{
  margin: 10px auto;
  height: 320px;
}
</style>