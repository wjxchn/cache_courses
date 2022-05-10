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
      <!--国内航班预警-->
      <div class="row featurette" style="margin-top:2%">
        <div class="col-12">
          <h2 class="featurette-heading" style="font-family: 'rr'">国内火车预警信息
            <span class="badge bg-danger" style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter">更新于{{new Date(updateTime).format('yyyy-MM-dd hh:mm:ss')}}</span>
          </h2>
          <p class="lead" style="font-family: 'Times New Roman'">Warning message preview of domestic railway. </p>
          <div class="row">
            <div class="col-2">              
              <el-cascader
              v-model="from_station"
              placeholder="出发地"
              :options="city_station_list"
              filterable>
              </el-cascader></div>
            <div class="col-1" style="text-align: center">
              <el-button @click="changeFromAndTo(0)" icon="el-icon-sort" style="transform: rotate(90deg);" circle></el-button>
            </div>
            <div class="col-3">
            <el-cascader
              v-model="to_station"
              placeholder="目的地"
              :options="city_station_list"
              filterable>
              </el-cascader>
            </div>
            <div class="col-3">
            <el-input
              placeholder="在结果中检索车次"
              prefix-icon="el-icon-search"
              v-model="train_no_search">
            </el-input>
            </div>
            <div class="col-3" style="text-align: right">
              <el-button @click="searchTrain()" type="primary" icon="el-icon-search">搜索</el-button>
            </div>
          </div>
          <el-table
            :data="trainData"
            v-loading="trainLoading"
            height="500"
            border
            align="center"
            style="margin-top: 15px"
            :header-row-style="{'font-family': 'Heiti SC','font-weight':'lighter','font-size':'17px','color':'black'}"
            :cell-style="{'font-family':'rr','font-size':'17px','color':'black'}">
            <el-table-column
                prop="train_no"
                label="车次"
                sortable
                width="200">
              <template slot-scope="scope">
                <div style="font-size: 20px">
                  {{scope.row.train_no}}
                </div>
              </template>
            </el-table-column>
              <el-table-column
                  prop="from_station"
                  label="出发地"
                  sortable
                  width="200">
                <template slot-scope="scope">
                  <div style="font-size: 20px">
                    {{scope.row.station_data[0].station}}
                  </div>
                </template>
              </el-table-column>
              <el-table-column
                prop="to_station"
                label="目的地"
                sortable
                width="200">
                <template slot-scope="scope">
                  <div style="font-size: 20px">
                    {{scope.row.station_data[scope.row.station_data.length-1].station}}
                  </div>
                </template>
              </el-table-column>
              <el-table-column prop="stations" label="经停站" align="left" type="expand" width="200">
                <template slot-scope="scope">
                  <el-table :data="scope.row.station_data" max-height="300">
                    <el-table-column prop="name" label="经停站名" width="auto">
                      <template slot-scope="scope1">
                        <span style="font-size: 16px; font-family: 'rr'">{{scope1.row.station}}</span>
                        <span class="small-icon" style="background-color: #3fb684" v-if="scope.row.from_index == scope1.$index">始</span>
                        <span class="small-icon" style="background-color: #ff8a37" v-if="scope.row.to_index == scope1.$index">终</span>
                      </template>
                      <!-- {{scope.row.name}} -->
                    </el-table-column>
                    <el-table-column prop="confirm" label="现有确诊" width="auto">
                      <template slot-scope="scope1">
                        <span style="font-size: 16px; font-family: 'Times New Roman'">{{scope1.row.now_confirm}}</span>
                      </template>
                    </el-table-column>
                    <el-table-column prop="confirm_add" label="新增确诊" width="auto">
                      <template slot-scope="scope1">
                        <span style="font-size: 16px; font-family: 'Times New Roman'">{{scope1.row.confirm_add}}</span>
                      </template>
                    </el-table-column>
                    <el-table-column prop="heal" label="治愈" width="auto">
                      <template slot-scope="scope1">
                        <span style="font-size: 16px; font-family: 'Times New Roman'">{{scope1.row.heal}}</span>
                      </template>
                    </el-table-column>
                    <el-table-column prop="dead" label="死亡" width="auto">
                      <template slot-scope="scope1">
                        <span style="font-size: 16px; font-family: 'Times New Roman'">{{scope1.row.dead}}</span>
                      </template>
                    </el-table-column>
                    <el-table-column prop="risk" label="风险等级" width="auto">
                      <template slot-scope="scope1">
                        <span style="font-size: 16px; font-family: 'Times New Roman'">{{scope1.row.risk}}</span>
                      </template>
                    </el-table-column>
                  </el-table>
                </template>
              </el-table-column>
              <el-table-column
                  prop="info"
                  label="预警提示"
                  width="auto">
                <template slot-scope="scope">
                  <div style="font-size: 20px">
                    {{scope.row.info}}
                  </div>
                </template>
              </el-table-column>
            </el-table>
        </div>
      </div>

      <hr class="featurette-divider">
      <!--国内高铁预警div-->
      <div class="row featurette">
        <div class="col-12">
          <h2 class="featurette-heading" style="font-family: 'rr'">国内航班预警预览
            <span class="badge bg-danger" style="font-family: 'Heiti TC';font-size: 15px;font-weight: lighter">更新于{{new Date(updateTime).format('yyyy-MM-dd hh:mm:ss')}}</span>
          </h2>
          <p class="lead" style="font-family: 'Times New Roman'">Warning message preview of domestic flights. </p>

          <div class="row">
            <div class="col-2">
              <el-select v-model="from_airport" filterable placeholder="起始地">
                <el-option
                  v-for="item in city_list"
                  :key="item.value"
                  :label="item.label"
                  :value="item.value">
                </el-option>
              </el-select>
            </div>
            <div class="col-1" style="text-align: center">
              <el-button @click="changeFromAndTo(1)" icon="el-icon-sort" style="transform: rotate(90deg);" circle></el-button>
            </div>
            <div class="col-3">
              <el-select v-model="to_airport" filterable placeholder="目的地">
                <el-option
                  v-for="item in city_list"
                  :key="item.value"
                  :label="item.label"
                  :value="item.value">
                </el-option>
            </el-select>
            </div>
            <div class="col-3">
              <el-input
                placeholder="在结果中检索航班号"
                prefix-icon="el-icon-search"
                v-model="flight_no_search">
              </el-input>
            </div>
            <div class="col-3" style="text-align: right">
              <el-button @click="searchFlight()" type="primary" icon="el-icon-search">搜索</el-button>
            </div>
          </div>
          <el-table
            height="500"
            v-loading="flightLoading"
            :data="flightData"
            border
            align="center"
            style="margin-top: 15px"
            :header-row-style="{'font-family': 'Heiti SC','font-weight':'lighter','font-size':'17px','color':'black'}"
            :cell-style="{'font-family':'rr','font-size':'17px','color':'black'}">
            <el-table-column
                prop="flight_no"
                label="航班号"
                sortable
                width="200">
              <template slot-scope="scope">
                <div style="font-size: 20px">
                  {{scope.row.flight_no}}
                </div>
              </template>
            </el-table-column>
              <el-table-column
                  prop="from_airport"
                  label="出发地"
                  sortable
                  width="200">
                <template slot-scope="scope">
                  <div style="font-size: 20px">
                    <el-popover
                      placement="bottom"
                      align="center"
                      trigger="hover">
                      <div class="popover-title">{{city_info.from.name}}疫情数据</div>
                      <div class="popover-content">现有确诊：{{city_info.from.now_confirm}}人</div>
                      <div class="popover-content">新增确诊：{{city_info.from.confirm_add}}人</div>
                      <div class="popover-content">累计治愈：{{city_info.from.heal}}人</div>
                      <div class="popover-content">累计死亡：{{city_info.from.dead}}人</div>
                      <span style="font-size: 20px" slot="reference">
                        {{ scope.row.from_airport }}
                      </span>
                    </el-popover>
                  </div>
                </template>
              </el-table-column>
              <el-table-column
                prop="to_airport"
                label="目的地"
                sortable
                width="200">
                <template slot-scope="scope">
                  <div style="font-size: 20px">
                    <el-popover
                      placement="bottom"
                      align="center"
                      trigger="hover">
                      <div class="popover-title">{{city_info.to.name}}疫情数据</div>
                      <div class="popover-content">现有确诊：{{city_info.to.now_confirm}}人</div>
                      <div class="popover-content">新增确诊：{{city_info.to.confirm_add}}人</div>
                      <div class="popover-content">累计治愈：{{city_info.to.heal}}人</div>
                      <div class="popover-content">累计死亡：{{city_info.to.dead}}人</div>
                      <span style="font-size: 20px" slot="reference">
                        {{ scope.row.to_airport }}
                      </span>
                    </el-popover>
                  </div>
                </template>
              </el-table-column>
              <el-table-column prop="stop" label="中转城市" width="200">
                <template slot-scope="scope">
                  <div style="font-size: 20px" v-if="scope.row.stop == null">
                    无
                  </div>
                  <div v-else>
                    <el-popover
                      placement="bottom"
                      align="center"
                      trigger="hover">
                      <div class="popover-title">{{scope.row.stop}}疫情数据</div>
                      <div class="popover-content">现有确诊：{{city_info[scope.row.stop].now_confirm}}人</div>
                      <div class="popover-content">新增确诊：{{city_info[scope.row.stop].confirm_add}}人</div>
                      <div class="popover-content">累计治愈：{{city_info[scope.row.stop].heal}}人</div>
                      <div class="popover-content">累计死亡：{{city_info[scope.row.stop].dead}}人</div>
                      <span style="font-size: 20px" slot="reference">
                        {{ scope.row.stop }}
                      </span>
                    </el-popover>
                  </div>
                </template>
              </el-table-column>
              <el-table-column
                  prop="info"
                  label="预警提示"
                  width="auto">
                <template slot-scope="scope">
                  <div style="font-size: 20px">
                    {{scope.row.info}}
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
      updateTime: '2021/7/10 10:00:00',
      trainLoading: false,
      flightLoading: false,
      trainData: [
        // {id:1, train_no: "D727", from_station: "北京", to_station:"深圳", from_index: 0, to_index: 1,stations:[{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10},{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10}],info:"深圳市宝安区为中风险地区"},
        // {id:2, train_no: "G79", from_station: "北京", to_station:"深圳",  from_index: 0, to_index: 1,stations:[{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10},{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10}],info:"深圳市宝安区为中风险地区"},
        // {id:3, train_no: "D901", from_station: "北京", to_station:"深圳",from_index: 0, to_index: 1,stations:[{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10},{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10}],info:"深圳市宝安区为中风险地区"},
        // {id:4, train_no: "Z181", from_station: "北京", to_station:"深圳",from_index: 0, to_index: 1,stations:[{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10},{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10}],info:"深圳市宝安区为中风险地区"},
        // {id:5, train_no: "Z181", from_station: "北京", to_station:"东莞",from_index: 0, to_index: 1,stations:[{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10},{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10}],info:"东莞市麻涌镇为中风险地区"},
        // {id:6, train_no: "D2287", from_station: "上海", to_station:"深圳",from_index: 0, to_index: 1,stations:[{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10},{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10}],info:"深圳市宝安区为中风险地区"},
        // {id:7, train_no: "D2281", from_station: "上海", to_station:"深圳",from_index: 0, to_index: 1,stations:[{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10},{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10}],info:"深圳市宝安区为中风险地区"},
        // {id:8, train_no: "D2289", from_station: "上海", to_station:"深圳",from_index: 0, to_index: 1,stations:[{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10},{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10}],info:"深圳市宝安区为中风险地区"},
        // {id:9, train_no: "D3107", from_station: "上海", to_station:"深圳",from_index: 0, to_index: 1,stations:[{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10},{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10}],info:"深圳市宝安区为中风险地区"},
        // {id:1, train_no: "D3125", from_station: "上海", to_station:"深圳",from_index: 0, to_index: 1,stations:[{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10},{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10}],info:"深圳市宝安区为中风险地区"},
        // {id:1, train_no: "D3125", from_station: "上海", to_station:"深圳",from_index: 0, to_index: 1,stations:[{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10},{name: '北京', confirm: 10, confirm_add: 10, dead: 10, heal: 10}],info:"深圳市宝安区为中风险地区"},
      ],
      train_no_search: '',
      city_station_list: [
        {
          value: 0,
          label: '北京',
          children: [
            {
              value: 0,
              label: '北京西站'
            }
          ]
        },
      ],
      from_station: '',
      to_station: '',
      flight_no_search: '',
      from_airport: '',
      to_airport: '',
      city_list: [
        {
          value: 0,
          label: '北京',
        },
      ],
      city_info: {
        '北京': {
          location_id: 0,
          confirm: 10, 
          confirm_add: 10, 
          dead: 10, 
          heal: 10
        },
        '深圳': {
          location_id: 0,
          confirm: 10, 
          confirm_add: 10, 
          dead: 10, 
          heal: 10
        }
      },
      flightData: [
        // {id:1, flight_no: "3U1026", from_airport: "北京", to_airport:"深圳",stop:'北京',info:"深圳市宝安区为中风险地区"},
        // {id:2, flight_no: "3U1040", from_airport: "北京", to_airport:"深圳",stop:'北京',info:"深圳市宝安区为中风险地区"},
        // {id:3, flight_no: "CA3406", from_airport: "北京", to_airport:"深圳",stop:'深圳',info:"深圳市宝安区为中风险地区"},
        // {id:4, flight_no: "CA1341", from_airport: "北京", to_airport:"深圳",stop:'深圳',info:"深圳市宝安区为中风险地区"},
        // {id:5, flight_no: "HU7711", from_airport: "北京", to_airport:"深圳",stop:null,info:"深圳市宝安区为中风险地区"},
        // {id:6, flight_no: "KY9110", from_airport: "北京", to_airport:"深圳",stop:null,info:"深圳市宝安区为中风险地区"},
        // {id:7, flight_no: "SC9204", from_airport: "北京", to_airport:"深圳",stop:null,info:"深圳市宝安区为中风险地区"},
        // {id:8, flight_no: "ZH4003", from_airport: "北京", to_airport:"深圳",stop:null,info:"深圳市宝安区为中风险地区"},
        // {id:9, flight_no: "ZH9110", from_airport: "北京", to_airport:"深圳",stop:null,info:"深圳市宝安区为中风险地区"},
        // {id:1, flight_no: "CA1313", from_airport: "北京", to_airport:"深圳",stop:null,info:"深圳市宝安区为中风险地区"},
        // {id:1, flight_no: "CA1357", from_airport: "北京", to_airport:"深圳",stop:null,info:"深圳市宝安区为中风险地区"},
        // {id:1, flight_no: "CZ4263", from_airport: "北京", to_airport:"深圳",stop:null,info:"深圳市宝安区为中风险地区"},
        // {id:1, flight_no: "CZ3152", from_airport: "北京", to_airport:"深圳",stop:null,info:"深圳市宝安区为中风险地区"},
      ],
    }
  },
  created(){
    this.postRequest(
      "/getcity",
      {}
    ).then( (res)=>{
      if(res.code === "200"){
        this.city_station_list = res.data.citylist
      }
      else{
        console.log("有点问题");
      }
    } ).catch( (err)=>{
        console.log(err)
    } )
    this.postRequest(
      "/citylist",
      {}
    ).then( (res)=>{
      if(res.code === "200"){
        console.log(res.data);
        this.city_list = res.data.citylist
        this.updateTime = res.data.updatedate
      }
      else{
        console.log("有点问题");
      }
    } ).catch( (err)=>{
        console.log(err)
    } )
  },
  mounted(){
    this.from_station = ['北京','北京西']
    this.to_station = ['长沙','长沙南']
    this.searchTrain()
    this.from_airport = 115
    this.to_airport = 164
    this.searchFlight()
  },
  methods:{
    handleSelect(key, keyPath) {
      console.log(key, keyPath);
    },
    searchTrain(){
      if(this.from_station[1]===null || this.from_station==="" || this.to_station[1]===null || this.to_station===""){
        this.$message({message: "请选择出发地和目的地", type: 'error'})
      }
      else{
        this.trainLoading = true
        console.log(this.from_station[1])
        console.log(this.to_station[1])
        this.postRequest(
        "/train/getbykeyword",
        {
          keyword:this.train_no_search,
          from:this.from_station[1],
          to:this.to_station[1]
        }
      ).then( (res)=>{
        if(res.code==="200"){
          console.log("在这里")
          console.log(res.data)
          this.trainData = res.data
          this.trainLoading = false
        }
        else{
          console.log("有点问题")
        }
      }).catch( (err) =>{
        console.log(err)
      })
      }
    },
    searchFlight() {
      if(this.from_airport===null || this.from_airport==="" || this.to_airport===null || this.to_airport===""){
        this.$message({message: "请选择出发地和目的地", type: 'error'})
      }
      else{
        this.flightLoading = true
        this.postRequest(
          "/flightsinfo",
          {
            keywords: this.flight_no_search,
            from:this.from_airport,
            to:this.to_airport
          }
        ).then( (res)=>{
          if(res.code==="200"){
            console.log(res.data);
            this.flightData = res.data.flights
            this.city_info = res.data.city_info
            this.flightLoading = false
          }
          else{
            console.log("有点问题")
          }
        }).catch( (err) =>{
          console.log(err)
        })
      }
    },
    changeFromAndTo(flag) {
      if(flag == 0){
        var temp = this.from_station
        this.from_station = this.to_station
        this.to_station = temp
      }
      else {
        var tmp = this.from_airport
        this.from_airport = this.to_airport
        this.to_airport = tmp
      }
    }
  }
}
</script>

<style scoped>
.small-icon {
  display: block;
  width: 25px;
  height: 25px;
  border-radius: 25px;
  float: right;
  margin-right: 20px; 
  line-height: 25px;
  text-align: center;
  color: white;
}

.popover-title {
  font-family: 'rr';
  font-size: 18px;
  font-weight: 600;
  text-align: center;
}

.popover-content {
  font-family: 'rr';
  font-size: 16px;
  line-height: 24px;
  text-align: center;
}
</style>