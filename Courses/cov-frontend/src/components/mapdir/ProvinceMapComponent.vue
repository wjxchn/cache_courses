<template>
  <div class="chinaecomponent" style="width:100%;height:600px;">
    <div class="btn-group">
      <button type="button" class="btn btn-outline-danger active" id="confirm" @click="chinamapselectval=4">现有确诊</button>
      <button type="button" class="btn btn-outline-danger" id="risk" @click="chinamapselectval=6">风险地区</button>
    </div>
    <div style="width:100%;height:560px;" :id="mapId"></div>
  </div>
</template>
<script>
  import echarts from "../../plugins/echarts";
  export default {
  name: "ProvinceComponent",
  props: {
    mapId: {
      type: String,
      default: null
    },
    mapname:{
      type: String,
      default: null
    },
    mapdata:{

    }
  },
  mounted() {
    console.log("provinceMapCompoent mounted");

  },

  data() {
    return {
      chinamapselectval: 4,
      mapJsonList: {
        "北京市":require("../../assets/mapdir/provincemap/北京市.json"),
        "天津市":require("../../assets/mapdir/provincemap/天津市.json"),
        "河北省":require("../../assets/mapdir/provincemap/河北省.json"),
        "内蒙古自治区":require("../../assets/mapdir/provincemap/内蒙古自治区.json"),
        "辽宁省":require("../../assets/mapdir/provincemap/辽宁省.json"),
        "吉林省":require("../../assets/mapdir/provincemap/吉林省.json"),
        "黑龙江省":require("../../assets/mapdir/provincemap/黑龙江省.json"),
        "山西省":require("../../assets/mapdir/provincemap/山西省.json"),
        "陕西省":require("../../assets/mapdir/provincemap/陕西省.json"),
        "宁夏回族自治区":require("../../assets/mapdir/provincemap/宁夏回族自治区.json"),
        "甘肃省":require("../../assets/mapdir/provincemap/甘肃省.json"),
        "青海省":require("../../assets/mapdir/provincemap/青海省.json"),
        "":require("../../assets/mapdir/provincemap/新疆维吾尔自治区.json"),
        "西藏自治区":require("../../assets/mapdir/provincemap/西藏自治区.json"),
        "四川省":require("../../assets/mapdir/provincemap/四川省.json"),
        "云南省":require("../../assets/mapdir/provincemap/云南省.json"),
        "重庆市":require("../../assets/mapdir/provincemap/重庆市.json"),
        "贵州省":require("../../assets/mapdir/provincemap/贵州省.json"),
        "广西壮族自治区":require("../../assets/mapdir/provincemap/广西壮族自治区.json"),
        "河南省":require("../../assets/mapdir/provincemap/河南省.json"),
        "山东省":require("../../assets/mapdir/provincemap/山东省.json"),
        "湖北省":require("../../assets/mapdir/provincemap/湖北省.json"),
        "安徽省":require("../../assets/mapdir/provincemap/安徽省.json"),
        "江苏省":require("../../assets/mapdir/provincemap/江苏省.json"),
        "湖南省":require("../../assets/mapdir/provincemap/湖南省.json"),
        "江西省":require("../../assets/mapdir/provincemap/江西省.json"),
        "上海市":require("../../assets/mapdir/provincemap/上海市.json"),
        "浙江省":require("../../assets/mapdir/provincemap/浙江省.json"),
        "福建省":require("../../assets/mapdir/provincemap/福建省.json"),
        "台湾省":require("../../assets/mapdir/provincemap/台湾省.json"),
        "广东省":require("../../assets/mapdir/provincemap/广东省.json"),
        "香港特别行政区":require("../../assets/mapdir/provincemap/香港特别行政区.json"),
        "澳门特别行政区":require("../../assets/mapdir/provincemap/澳门特别行政区.json"),
        "海南省":require("../../assets/mapdir/provincemap/海南省.json"),
        "新疆维吾尔自治区":require("../../assets/mapdir/provincemap/新疆维吾尔自治区.json"),
      },
      mapOption:{
        //鼠标移入时显示的内容
        tooltip: {
          trigger: "item",
          formatter: function(params){
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
            {gte:10,label:'10人以上'},
            {gte:3,lte:9,label:'3人以上'},
            {gte:1,lte:2,label:'1人以上'},
            {value:0,label:'0人'},
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
            mapType: "省份", // 自定义扩展图表类型
            name: "中国各省级行政单位案件完成数量对比",
            label: {
              show: false,
            },
            zoom: 1.2, //当前视角的缩放比例
            roam: false, //是否开启平游或缩放
            scaleLimit: { //滚轮缩放的极限控制
              min: 1,
              max: 50
            },
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
            data: [
            ],
          },
        ],
      },
      visualMapList:[
        {
          show: true,
          pieces:[
            {gte:10,label:'10人以上'},
            {gte:3,lte:9,label:'3人以上'},
            {gte:1,lte:2,label:'1人以上'},
            {value:0,label:'0人'},
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
            {gte:10,label:'10人以上'},
            {gte:3,lte:9,label:'3人以上'},
            {gte:1,lte:2,label:'1人以上'},
            {value:0,label:'0人'},
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
            {gte:10,label:'10人以上'},
            {gte:3,lte:9,label:'3人以上'},
            {gte:1,lte:2,label:'1人以上'},
            {value:0,label:'0人'},
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
            {gte:10,label:'10人以上'},
            {gte:3,lte:9,label:'3人以上'},
            {gte:1,lte:2,label:'1人以上'},
            {value:0,label:'0人'},
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
            {gte:10,label:'10人以上'},
            {gte:3,lte:9,label:'3人以上'},
            {gte:1,lte:2,label:'1人以上'},
            {value:0,label:'0人'},
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
        },
      ]
    };
  },
  beforeDestroy() {
    if (!this.chart) {
      return;
    }
    this.chart.dispose();
    this.chart = null;
  },
  watch:{
    chinamapselectval: function(val){
      if(val==4){
        document.getElementById('confirm').setAttribute('class','btn btn-outline-danger active')
        document.getElementById('risk').setAttribute('class','btn btn-outline-danger')
        for(let i=0;i<this.mapdata.locations.length;i++){
          this.mapdata.locations[i].value = this.mapdata.locations[i].now_confirm;
        }
      }
      else if(val==6){
        document.getElementById('confirm').setAttribute('class','btn btn-outline-danger')
        document.getElementById('risk').setAttribute('class','btn btn-outline-danger active')
        for(let i=0;i<this.mapdata.locations.length;i++){
          if(this.mapdata.locations[i].risk=='低'){
            this.mapdata.locations[i].value = 1;
          }
          else if(this.mapdata.locations[i].risk=='中'){
            this.mapdata.locations[i].value = 2;
          }
          else if(this.mapdata.locations[i].risk=='高'){
            this.mapdata.locations[i].value = 3;
          }
        }
      }
      this.mapOption.visualMap = this.visualMapList[val];
      this.mapOption.series[0].data = this.mapdata.locations;
      this.myChart.setOption(this.mapOption)      
    },
    mapdata: function () {
      console.log("provinceMapCompoent mapdata change");
      console.log(this.mapdata.locations)
      this.mapOption.series[0].data = this.mapdata.locations
      var that = this;

      that.myChart = echarts.init(document.getElementById(that.mapId));

      echarts.registerMap("省份", that.mapJsonList[that.mapdata.name], {}); //这个是关键，之前拿到的青州各街道数据
      that.myChart.setOption(that.mapOption);
    }
  }
}
</script>