<template>
  <div class="worldcomponent">
    <div>
      <svg xmlns="http://www.w3.org/2000/svg" width="32" height="32" fill="currentColor" class="bi bi-plus-square" viewBox="0 0 16 16" @click="roamMap(0)" style="z-index: 999;margin-right: 5px">
        <path d="M14 1a1 1 0 0 1 1 1v12a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V2a1 1 0 0 1 1-1h12zM2 0a2 2 0 0 0-2 2v12a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V2a2 2 0 0 0-2-2H2z"/>
        <path d="M8 4a.5.5 0 0 1 .5.5v3h3a.5.5 0 0 1 0 1h-3v3a.5.5 0 0 1-1 0v-3h-3a.5.5 0 0 1 0-1h3v-3A.5.5 0 0 1 8 4z"/>
      </svg>
      <svg xmlns="http://www.w3.org/2000/svg" width="32" height="32" fill="currentColor" class="bi bi-dash-square" viewBox="0 0 16 16" @click="roamMap(1)" style="z-index: 999">
        <path d="M14 1a1 1 0 0 1 1 1v12a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V2a1 1 0 0 1 1-1h12zM2 0a2 2 0 0 0-2 2v12a2 2 0 0 0 2 2h12a2 2 0 0 0 2-2V2a2 2 0 0 0-2-2H2z"/>
        <path d="M4 8a.5.5 0 0 1 .5-.5h7a.5.5 0 0 1 0 1h-7A.5.5 0 0 1 4 8z"/>
      </svg>
    </div>
    <div style="width:100%;height:40vw;margin: 20px auto;" :id="mapId"></div>
  </div>
</template>
<script>
import echarts from "../../plugins/echarts";
import JSON from "../../assets/mapdir/world.json"; // 引入杭州市地图数据(引入方式重点，本人用其他方式报错)
export default {
  name: "WorldComponent",
  props: {
    mapId: {
      type: String,
      default: null
    },
    mapData: {
    }
  },
  data() {
    return {
      mapOption:{
        //鼠标移入时显示的内容
        tooltip: {
          trigger: "item",
          formatter: function(params){
            //console.log(params);
            if(params.data===undefined){
              return "无数据"
            }
            else{
              return params.data.name+": <br/>现有确诊"+params.data.cov_data.now_confirm+"人</br>累计确诊"+params.data.cov_data.confirm+"人<br/>新增确诊"+params.data.cov_data.confirm_add+"人<br/>累计死亡"+params.data.cov_data.dead+"人<br/>累计治愈"+params.data.cov_data.heal+"人"
            }
          },
        },
        //左下角显示内容高低
        // visualMap: {
        //   show:false,
        //   min: 100,
        //   max: 5000,
        //   text: ["高", "低"],
        //   realtime: false,
        //   calculable: true,
        //   inRange: {
        //     color: ["lightskyblue", "yellow", "orangered"],
        //   },
        // },
        // backgroundColor:'#ffffff',
        visualMap: {
          show: true,
          pieces:[
            {gte:10000000, label:'≥1000万'},
            {gte:5000000,lte:10000000-1, label:'500万-1000万'},
            {gte:1000000,lte:5000000-1, label:'100万-500万'},
            {gte:100000,lte:1000000-1, label:'10万-100万'},
            {gte:10000,lte:100000 - 1,label:'1万-10万'},
            {gte:5000,lte:9999,label:'5000-9999'},
            {gte:1,lte:4999,label:'1-4999'},
            {value:0, label: '0'}
          ],
          realtime: false,
          calculable: false,
          inRange: {
            color: ["#e4ebf3","#fbe8b8", "#f7d0a6", "#f2a97f", "#ed6d4d",'#ea4141','#ea4141','#7e1b13'],
          },
        },
        series: [
          {
            type: "map",//图标类型
            mapType: "世界", // 自定义扩展图表类型
            name: "世界各国家和地区案件完成数量对比",
            zoom: 1.2, //当前视角的缩放比例
            roam: 'move', //是否开启平游或缩放
            scaleLimit: { //滚轮缩放的极限控制
              min: 1,
              max: 50
            },
            nameMap: {
              "Afghanistan":"阿富汗",
              "Albania":"阿尔巴尼亚",
              "Algeria":"阿尔及利亚",
              "Angola":"安哥拉",
              "Argentina":"阿根廷",
              "Armenia":"亚美尼亚",
              "Australia":"澳大利亚",
              "Austria":"奥地利",
              "Azerbaijan":"阿塞拜疆",
              "Bahamas":"巴哈马",
              "Bahrain":"巴林",
              "Bangladesh":"孟加拉国",
              "Belarus":"白俄罗斯",
              "Belgium":"比利时",
              "Belize":"伯利兹",
              "Benin":"贝宁",
              "Bhutan":"不丹",
              "Bolivia":"玻利维亚",
              "Bosnia and Herz.":"波斯尼亚和黑塞哥维那",
              "Botswana":"博茨瓦纳",
              "Brazil":"巴西",
              "British Virgin Islands":"英属维京群岛",
              "Brunei":"文莱",
              "Bulgaria":"保加利亚",
              "Burkina Faso":"布基纳法索",
              "Burundi":"布隆迪",
              "Cambodia":"柬埔寨",
              "Cameroon":"喀麦隆",
              "Canada":"加拿大",
              "Cape Verde":"佛得角",
              "Cayman Islands":"开曼群岛",
              "Central African Rep.":"中非共和国",
              "Chad":"乍得",
              "Chile":"智利",
              "China":"中国",
              "Colombia":"哥伦比亚",
              "Comoros":"科摩罗",
              "Congo":"刚果",
              "Costa Rica":"哥斯达黎加",
              "Croatia":"克罗地亚",
              "Cuba":"古巴",
              "Cyprus":"塞浦路斯",
              "Czech Rep.":"捷克共和国",
              "Côte d'Ivoire":"科特迪瓦",
              "Dem. Rep. Congo":"刚果民主共和国",
              "Dem. Rep. Korea":"朝鲜",
              "Denmark":"丹麦",
              "Djibouti":"吉布提",
              "Dominican Rep.":"多米尼加共和国",
              "Ecuador":"厄瓜多尔",
              "Egypt":"埃及",
              "El Salvador":"萨尔瓦多",
              "Equatorial Guinea":"赤道几内亚",
              "Eritrea":"厄立特里亚",
              "Estonia":"爱沙尼亚",
              "Ethiopia":"埃塞俄比亚",
              "Falkland Is.":"福克兰群岛",
              "Fiji":"斐济",
              "Finland":"芬兰",
              "Fr. S. Antarctic Lands":"所罗门群岛",
              "France":"法国",
              "Gabon":"加蓬",
              "Gambia":"冈比亚",
              "Georgia":"格鲁吉亚",
              "Germany":"德国",
              "Ghana":"加纳",
              "Greece":"希腊",
              "Greenland":"格陵兰",
              "Guatemala":"危地马拉",
              "Guinea":"几内亚",
              "Guinea-Bissau":"几内亚比绍",
              "Guyana":"圭亚那",
              "Haiti":"海地",
              "Honduras":"洪都拉斯",
              "Hungary":"匈牙利",
              "Iceland":"冰岛",
              "India":"印度",
              "Indonesia":"印度尼西亚",
              "Iran":"伊朗",
              "Iraq":"伊拉克",
              "Ireland":"爱尔兰",
              "Isle of Man":"马恩岛",
              "Israel":"以色列",
              "Italy":"意大利",
              "Jamaica":"牙买加",
              "Japan":"日本",
              "Jordan":"约旦",
              "Kazakhstan":"哈萨克斯坦",
              "Kenya":"肯尼亚",
              "Korea":"韩国",
              "Kuwait":"科威特",
              "Kyrgyzstan":"吉尔吉斯斯坦",
              "Lao PDR":"老挝",
              "Latvia":"拉脱维亚",
              "Lebanon":"黎巴嫩",
              "Lesotho":"莱索托",
              "Liberia":"利比里亚",
              "Libya":"利比亚",
              "Lithuania":"立陶宛",
              "Luxembourg":"卢森堡",
              "Macedonia":"马其顿",
              "Madagascar":"马达加斯加",
              "Malawi":"马拉维",
              "Malaysia":"马来西亚",
              "Maldives":"马尔代夫",
              "Mali":"马里",
              "Malta":"马耳他",
              "Mauritania":"毛利塔尼亚",
              "Mauritius":"毛里求斯",
              "Mexico":"墨西哥",
              "Moldova":"摩尔多瓦",
              "Monaco":"摩纳哥",
              "Mongolia":"蒙古",
              "Montenegro":"黑山共和国",
              "Morocco":"摩洛哥",
              "Mozambique":"莫桑比克",
              "Myanmar":"缅甸",
              "Namibia":"纳米比亚",
              "Nepal":"尼泊尔",
              "Netherlands":"荷兰",
              "New Caledonia":"新喀里多尼亚",
              "New Zealand":"新西兰",
              "Nicaragua":"尼加拉瓜",
              "Niger":"尼日尔",
              "Nigeria":"尼日利亚",
              "Norway":"挪威",
              "Oman":"阿曼",
              "Pakistan":"巴基斯坦",
              "Panama":"巴拿马",
              "Papua New Guinea":"巴布亚新几内亚",
              "Paraguay":"巴拉圭",
              "Peru":"秘鲁",
              "Philippines":"菲律宾",
              "Poland":"波兰",
              "Portugal":"葡萄牙",
              "Puerto Rico":"波多黎各",
              "Qatar":"卡塔尔",
              "Reunion":"留尼旺",
              "Romania":"罗马尼亚",
              "Russia":"俄罗斯",
              "Rwanda":"卢旺达",
              "S. Geo. and S. Sandw. Is.":"南乔治亚和南桑威奇群岛",
              "S. Sudan":"南苏丹",
              "San Marino":"圣马力诺",
              "Saudi Arabia":"沙特阿拉伯",
              "Senegal":"塞内加尔",
              "Serbia":"塞尔维亚",
              "Sierra Leone":"塞拉利昂",
              "Singapore":"新加坡",
              "Slovakia":"斯洛伐克",
              "Slovenia":"斯洛文尼亚",
              "Solomon Is.":"所罗门群岛",
              "Somalia":"索马里",
              "South Africa":"南非",
              "Spain":"西班牙",
              "Sri Lanka":"斯里兰卡",
              "Sudan":"苏丹",
              "Suriname":"苏里南",
              "Swaziland":"斯威士兰",
              "Sweden":"瑞典",
              "Switzerland":"瑞士",
              "Syria":"叙利亚",
              "Tajikistan":"塔吉克斯坦",
              "Tanzania":"坦桑尼亚",
              "Thailand":"泰国",
              "Togo":"多哥",
              "Tonga":"汤加",
              "Trinidad and Tobago":"特立尼达和多巴哥",
              "Tunisia":"突尼斯",
              "Turkey":"土耳其",
              "Turkmenistan":"土库曼斯坦",
              "U.S. Virgin Islands":"美属维尔京群岛",
              "Uganda":"乌干达",
              "Ukraine":"乌克兰",
              "United Arab Emirates":"阿拉伯联合酋长国",
              "United Kingdom":"英国",
              "United States":"美国",
              "Uruguay":"乌拉圭",
              "Uzbekistan":"乌兹别克斯坦",
              "Vanuatu":"瓦努阿图",
              "Vatican City":"梵蒂冈城",
              "Venezuela":"委内瑞拉",
              "Vietnam":"越南",
              "W. Sahara":"西撒哈拉",
              "Yemen":"也门",
              "Yugoslavia":"南斯拉夫",
              "Zaire":"扎伊尔",
              "Zambia":"赞比亚",
              "Zimbabwe":"津巴布韦"
            },
            label: {
              show: false,
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
            data: [{name:"中国", value:1},{name:"美国", value: 2}],
          },
        ],
      }
    };
  },
  mounted() {

  },
  beforeDestroy() {
    if (!this.chart) {
      return;
    }
    this.chart.dispose();
    this.chart = null;
  },
  watch:{
    mapData: function(){
      this.mapOption.series[0].data = this.mapData;
      console.log(this.mapOption.series.data);
      var that = this;
      this.myChart = echarts.init(document.getElementById(that.mapId));
      echarts.registerMap("世界", JSON, {}); //这个是关键，之前拿到的青州各街道数据
      this.myChart.setOption(this.mapOption);
    }
  },
  methods: {
    roamMap(flag) {

      let increaseAmplitude = 2; // 点击按钮每次 放大/缩小 比例
      if (flag == 1) {
        increaseAmplitude = 0.5
      }
      this.mapOption.series[0].zoom = this.mapOption.series[0].zoom*increaseAmplitude;
      this.myChart.setOption(this.mapOption);
    }
  }
}
</script>