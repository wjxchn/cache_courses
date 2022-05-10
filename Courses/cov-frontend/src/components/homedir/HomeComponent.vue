<template>
  <main>
    <div id="mapdiv"></div>
    <div class="container">
      <div class="row featurette">
        <div class="col-12">
          <div class="row">
            <div class="col-12">
              <div style="font-family: 'rr';font-size: 40px;margin: 20px" align="center">中国疫情数据追踪：图表与数据总览</div>
            </div>
            <div class="badge rounded-pill bg-danger mx-auto" style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter;width: auto">更新于{{new Date(ChinaData.cov_data.time).toLocaleString()}}
            </div>
            <a style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter;color: gray;text-align: right">数据来源于<a href="https://news.qq.com/zt2020/page/feiyan.htm#/">腾讯疫情</a></a>
          </div>
        </div>
        <div class="row">
          <div class="col-xl-6">
            <Chart title="国内疫情数据" time="2021.07.03 12:00" :cov_data="ChinaData.cov_data" style="padding-bottom: 10px"></Chart>
            <CityChart  :location1="mylocc"
                        :location2="mylocp"
                        :location3="mylocd"
                        :covdata="mylocdata"></CityChart>
          </div>
          <div class="col-xl-6">
<!--            <h2 class="featurette-heading" style="font-family: 'rr'">各省疫情趋势</h2>-->
<!--            <p class="lead" style="font-family: 'Times New Roman'">Real-time display of epidemic data in China.</p>-->
            <el-table
                :data="tableDataShow"
                border
                :default-sort = "{prop: 'risk', order: 'descending'}"
                max-height="587"
                align="center"
                header-row-style="font-family: 'Heiti SC';font-weight:lighter;font-size:17px;color:black"
                cell-style="font-family:'rr';font-size:17px;color:black">
              <el-table-column
                  prop="index"
                  v-if="false"
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
                  {{scope.row.name}}
                  <i class="el-icon-zoom-in" style="float:right" @click="goProvince(scope.row)"></i>
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
                  width="80">
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
                  width="80">
                <template slot-scope="scope">
                  <div style="font-size: 20px">
                    {{scope.row.cov_data.dead}}
                  </div>
                </template>
              </el-table-column>
              <el-table-column
                  prop="risk"
                  label="风险级别"
                  sortable
                  width="120">
                <template slot-scope="scope">
                  <div :style="getCellStyle(scope.row.risk)">
                    {{scope.row.risk}}
                  </div>
                </template>
              </el-table-column>
            </el-table>
          </div>

          <div class="col-xl-6">
          </div>
          <div class="col-xl-6">
            <!--这里是饼图区域-->
          </div>

        </div>

        <div class="row" style="margin-top:2%">
          <div class="col-md-6">
            <div class="dropdown-divider"></div>
            <div style="font-size: 30px;font-family: 'rr';height: 645px">
              <div>疫情地图</div>
              <div style="font-size:20px;font-family: 'Times New Roman'">Epidemic Map</div>
              <div>
                <ChinaComponent mapId="china1" ref="chinamapref" :mapdata="ChinaData.locations"></ChinaComponent>
              </div>
            </div>
            <div class="dropdown-divider"></div>
          </div>
          <div class="col-md-6">
            <div class="dropdown-divider"></div>
            <div style="font-size: 28px;font-family:'rr';padding-top: 2px;text-align: center">
                国内疫情数据曲线
            </div>
            <div>
              <TrendChartComponent mapId="aa" ref="chinachartref" style="width: 100%;margin-inline: 3%;margin-bottom: -60px" :dimensions="['confirm','dead','heal', 'total_vaccinations']" :dataList="chinadaylist"></TrendChartComponent>
            </div>
            <div class="dropdown-divider"></div>
            <div style="font-size: 28px;font-family:'rr';padding-top: 2px;text-align: center">
              现有确诊省份占比
            </div>
            <div>
              <ChinaPieChart height="300" pie-id="pie1" ref="piecomponent1" :data-list="tableData" :now_confirm_all="ChinaData.cov_data.now_confirm"></ChinaPieChart>
            </div>
            <div class="dropdown-divider"></div>
          </div>
        </div>

        <div class="row">
        </div>
      </div>
      
    </div>
  </main>
</template>

<script>
import Chart from "@/components/chartsdir/Chart";
import CityChart from "@/components/provincedir/CityChart";
import ChinaComponent from '@/components/mapdir/ChinaMapComponent.vue'
import TrendChartComponent from "@/components/chartsdir/TrendChartComponent";
import "@/assets/fontdir/font.css";
import WorldPieChart from "@/components/chartsdir/WorldPieChart";
import ChinaPieChart from "@/components/homedir/ChinaPieChart";
export default {
  name: 'HomeComponent',
  components: {
    ChinaPieChart,
    WorldPieChart,
    Chart,
    CityChart,
    ChinaComponent,
    TrendChartComponent,
  },
  props: [
    'ChinaData',
    'globalData',
    'tableData',
    'tableDataShow',
  ],
  watch:{
    search:function() {
      this.tableDataShow = this.tableData.filter(data => !this.search || data.name.toLowerCase().includes(this.search.toLowerCase()))
    }
  },
  data(){
    return{
      publicPath: '/',
      chinadaylist:{},
      chinavaccinationdaylist:[],
      globaldaylist:[],
      search: '',
      mylocc: '',
      mylocp: '',
      mylocd: '',
      mylocdata:{}
    }
  },
  mounted(){
    var that = this;
    this.postRequest("/history/getallchinadaylist")
        .then((response) => {
          that.chinadaylist = response.data
          console.log(response.data);
          console.log(this.ChinaData)
        })
        .catch((error) => {
          console.log(error)
        })
    this.postRequest("/history/overseasdaylist")
        .then((response) => {
          console.log(response);
          that.globaldaylist = response.data
        })
        .catch((error) => {
          console.log(error)
        })
    window.onresize = () => {
      that.$refs.chinamapref.myChart.resize();
      that.$refs.chinachartref.myChart.resize();
      that.$refs.piecomponent1.myChart.resize();
    }
    var map = new AMap.Map('mapdiv', {
    });
    AMap.plugin('AMap.Geolocation', function() {
        var geolocation = new AMap.Geolocation();
        geolocation.getCurrentPosition(function(status,result){
            if(status=='complete'){
                onComplete(result)
            }else{
                onError(result)
            }
        });
    });
    //解析定位结果
    function onComplete(data) {
        console.log(data.position.lng);
        var str = [];
        str.push('定位结果：' + data.position);
        str.push('定位类别：' + data.location_type);
        if(data.accuracy){
             str.push('精度：' + data.accuracy + ' 米');
        }//如为IP精确定位结果则没有精度信息
        str.push('是否经过偏移：' + (data.isConverted ? '是' : '否'));
        that.$axios({
          method:'get',
          url:'https://restapi.amap.com/v3/geocode/regeo',
          params:{
            location: data.position.lng+','+data.position.lat,
            key: 'd05ecc16db2af3450e049076b7359134'
          }
        }).then(res=>{
          console.log(res);
          console.log(res.regeocode.addressComponent.country);
          console.log(res.regeocode.addressComponent.province);
          console.log(res.regeocode.addressComponent.district);
          that.mylocc = res.regeocode.addressComponent.country;
          that.mylocp = res.regeocode.addressComponent.province;
          that.mylocd = res.regeocode.addressComponent.district;
          that.postRequest("/covdatabyname",{name:that.mylocd}).then((response) => {
            that.mylocdata = response.data
          })
        }).catch(err=>{
          console.log(err);
        })
    }
    //解析定位错误信息
    function onError(data) {
      console.log(data);
      console.log('定位失败');
    }

  },
  methods:{
    // searchCountry(){
    //   this.tableDataShow = this.tableData)
    // },
    getCellStyle(risk){
      let style;
      if (risk === '高' || risk === '中')
      {
        style = 'color:red;font-weight:bolder'
      }
      return style
    },
    goChinaChart(){
      this.$router.push({
        path: '/province',
        query: {
          provincecode: 5
        }
      });
    },
    goProvince(row) {
      let routeData = this.$router.resolve({ path: '/province', query: {  provincecode:row.index } });
      window.open(routeData.href, '_blank');
      // let url = '/province?provincecode=' + row.index
      // this.$router.push(url)
    },
    goWorldChart(){
      this.$router.push('/world')
    },
    getRiskString(){

    }
  }
}
</script>

<style scoped>
.mainimg{
  width: 100%;
  height: 30vw;
  background-image: url("../../assets/picdir/home_pic.jpeg");
  background-size: 100% 35vw;
}
</style>