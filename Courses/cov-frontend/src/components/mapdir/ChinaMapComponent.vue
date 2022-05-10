<template>
    <div class="chinaecomponent">
      <div class="btn-group">
        <button type="button" class="btn btn-outline-danger active" id="confirm" @click="chinamapselectval=4">现有确诊</button>
        <button type="button" class="btn btn-outline-danger" id="risk" @click="chinamapselectval=6">风险地区</button>
      </div>
<!--      <select class="form-select" aria-label="Default select example" v-model="chinamapselectval">-->
<!--        <option value="4">现有确诊</option>-->
<!--        <option value="5">累计确诊</option>-->
<!--        <option value="1">新增确诊</option>-->
<!--        <option value="2">累计治愈</option>-->
<!--        <option value="3">累计死亡</option>-->
<!--        <option value="6">风险地区</option>-->
<!--      </select>-->
      <div style="width:100%;height:530px;" :id="mapId"></div>
    </div>
</template>
<script>
import echarts from "../../plugins/echarts";
import JSON from "../../assets/mapdir/china.json"; // 引入杭州市地图数据(引入方式重点，本人用其他方式报错)
export default {
  name: "ChinaComponent",
  props: {
    mapId: {
      type: String,
      default: null
    },
    mapdata:{

    }
  },
  data() {
    return {
      chinamapselectval: 4,
      mapOption:{
        //鼠标移入时显示的内容
        tooltip: {
          trigger: "item",
          formatter: function(params){
            console.log(params);
            if(params.data===undefined){
              return "无数据"
            }
            else{
              return params.data.name+": <br/>现有确诊"+params.data.cov_data.now_confirm+"人</br>累计确诊"+params.data.cov_data.confirm+"人<br/>新增确诊"+params.data.cov_data.confirm_add+"人<br/>累计死亡"+params.data.cov_data.dead+"人<br/>累计治愈"+params.data.cov_data.heal+"人"
            }
          },
        },
        //左下角显示内容高低
        visualMap: {
          show: true,
          pieces:[
            {gte:500,label:'500人以上'},
            {gte:20,lte:499,label:'20人以上'},
            {gte:1,lte:19,label:'1人以上'},
            {lte:0,label:'0人'}
          ],
          realtime: false,
          calculable: false,
          inRange: {
            color: ["#e4ebf3", "#fbe8b8", "#f7d0a6", "#ed6d4d"],
          },
        },

        series: [
          {
            type: "map",//图标类型
            mapType: "中国", // 自定义扩展图表类型
            name: "中国各省市地图",
            label: {
              show: false,
            },
            zoom: 1.2, //当前视角的缩放比例
            // roam: true, //是否开启平游或缩放
            // scaleLimit: { //滚轮缩放的极限控制
            //   min: 1,
            //   max: 50
            // },
            //用于修改正常显示地图颜色边框等内容
            normal: {
              borderWidth: 1,
              borderColor: "#e1e1e1",
              color: "#90c31d",
              opacity : 0.8
            },
            //用于修改鼠标移入时地图颜色边框等内容
            emphasis: {
              areaColor:"#749f83",//修改移入时地图颜色
            },
            data: [],
          },
        ],
      },
      visualMapList:[
        {
          show: true,
          pieces:[
            {gte:500,label:'500人以上'},
            {gte:20,lte:499,label:'20人以上'},
            {gte:1,lte:19,label:'1人以上'},
            {lte:0,label:'0人'}
          ],
          realtime: false,
          calculable: false,
          inRange: {
            color: ["#e4ebf3", "#fbe8b8", "#f7d0a6", "#ed6d4d"],
          },
        },
        {
          show: true,
          pieces:[
            {gte:500,label:'500人以上'},
            {gte:20,lte:499,label:'20人以上'},
            {gte:1,lte:19,label:'1人以上'},
            {lte:0,label:'0人'}
          ],
          realtime: false,
          calculable: false,
          inRange: {
            color: ["#e4ebf3", "#fbe8b8", "#f7d0a6", "#ed6d4d"],
          },
        },
        {
          show: true,
          pieces:[
            {gte:500,label:'500人以上'},
            {gte:20,lte:499,label:'20人以上'},
            {gte:1,lte:19,label:'1人以上'},
            {lte:0,label:'0人'}
          ],
          realtime: false,
          calculable: false,
          inRange: {
            color: ["#e4ebf3", "#fbe8b8", "#f7d0a6", "#ed6d4d"],
          },
        },
        {
          show: true,
          pieces:[
            {gte:500,label:'500人以上'},
            {gte:20,lte:499,label:'20人以上'},
            {gte:1,lte:19,label:'1人以上'},
            {lte:0,label:'0人'}
          ],
          realtime: false,
          calculable: false,
          inRange: {
            color: ["#e4ebf3", "#fbe8b8", "#f7d0a6", "#ed6d4d"],
          },
        },
        {
          show: true,
          pieces:[
            {gte:500,label:'500人以上'},
            {gte:20,lte:499,label:'20人以上'},
            {gte:1,lte:19,label:'1人以上'},
            {lte:0,label:'0人'}
          ],
          realtime: false,
          calculable: false,
          inRange: {
            color: ["#e4ebf3", "#fbe8b8", "#f7d0a6", "#ed6d4d"],
          },
        },
        {
          show: true,
          pieces:[
            {gte:500,label:'500人以上'},
            {gte:20,lte:499,label:'20人以上'},
            {gte:1,lte:19,label:'1人以上'},
            {lte:0,label:'0人'}
          ],
          realtime: false,
          calculable: false,
          inRange: {
            color: ["#e4ebf3", "#fbe8b8", "#f7d0a6", "#ed6d4d"],
          },
        },
        {
          show: true,
          pieces:[
            {value:1,label:'风险低',color:"#e4ebf3"},
            {value:2,label:'风险中',color:"#f7d0a6"},
            {value:3,label:'风险高',color:"#ed6d4d"}
          ],
          realtime: false,
          calculable: false,
          inRange: {
            color: ["#e4ebf3", "#f7d0a6", "#ed6d4d"]
          },
        },
      ]
    };
  },
  mounted() {
    console.log("ChinaMapCompoent mounted");
  },
  beforeDestroy() {
    if (!this.chart) {
      return;
    }
    this.chart.dispose();
    this.chart = null;
  },
  watch: {
    chinamapselectval: function(val){
      if(val==5){
        for(let i=0;i<this.mapdata.length;i++){
          this.mapdata[i].value = this.mapdata[i].confirm;
        }
      }
      else if(val==4){
        document.getElementById('confirm').setAttribute('class','btn btn-outline-danger active')
        document.getElementById('risk').setAttribute('class','btn btn-outline-danger')
        for(let i=0;i<this.mapdata.length;i++){
          this.mapdata[i].value = this.mapdata[i].now_confirm;
        }
      }
      else if(val==1){
        for(let i=0;i<this.mapdata.length;i++){
          this.mapdata[i].value = this.mapdata[i].confirm_add;
        }
      }
      else if(val==2){
        for(let i=0;i<this.mapdata.length;i++){
          this.mapdata[i].value = this.mapdata[i].heal;
        }
      }
      else if(val==3){
        for(let i=0;i<this.mapdata.length;i++){
          this.mapdata[i].value = this.mapdata[i].dead;
        }
      }
      else if(val==6){
        document.getElementById('confirm').setAttribute('class','btn btn-outline-danger')
        document.getElementById('risk').setAttribute('class','btn btn-outline-danger active')
        for(let i=0;i<this.mapdata.length;i++){
          if(this.mapdata[i].risk=='低'){
            this.mapdata[i].value = 1;
          }
          else if(this.mapdata[i].risk=='中'){
            this.mapdata[i].value = 2;
          }
          else if(this.mapdata[i].risk=='高'){
            this.mapdata[i].value = 3;
          }
        }
      }
      this.mapOption.visualMap = this.visualMapList[val];
      this.mapOption.series[0].data = this.mapdata
      this.myChart.setOption(this.mapOption)      
    },
    mapdata: function () {
      console.log("chinamap mapdata change")
      this.mapOption.series[0].data = this.mapdata
      console.log(this.mapOption.series[0].data)
      var that = this
      this.myChart = echarts.init(document.getElementById(that.mapId))
      echarts.registerMap("中国", JSON, {
      });
      this.myChart.setOption(this.mapOption)
    }
  },
}
</script>