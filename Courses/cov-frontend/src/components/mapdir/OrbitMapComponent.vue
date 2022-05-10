<template>
  <div class="home" style="width: 100%; height:100%;">
    <div id="orbitchart" style="width: 100%; height:100%;"></div>
  </div>
</template>

<script>
import echarts from "../../plugins/echarts";
import JSON from "../../assets/mapdir/china.json";
export default {
  name: "Province",
  data() {
    return {
      chart: null,
      oribmap:{
        大连:[122.2229,39.4409],
        北京:[116.4551,40.2539],
        上海:[121.4648,31.2891],
        广州:[113.5107,23.2196],
      },
      id: 'echart',
    };
  },
  mounted() {
    echarts.registerMap('中国', JSON);
    this.initChart();
  },
  methods: {
    initChart() {
        var echarts = require('echarts');
        const OribitData = [
          [{ name: "" }, { name: "大连", value: 50 }],
          [{ name: "大连" }, { name: "北京", value: 50 }],
          [{ name: "北京" }, { name: "上海", value: 50 }],
          [{ name: "上海" }, { name: "广州", value: 50 }],
        ];
        const color = ["#a6c84c"];
        const planePath ="path://M1705.06,1318.313v-89.254l-319.9-221.799l0.073-208.063c0.521-84.662-26.629-121.796-63.961-121.491c-37.332-0.305-64.482,36.829-63.961,121.491l0.073,208.063l-319.9,221.799v89.254l330.343-157.288l12.238,241.308l-134.449,92.931l0.531,42.034l175.125-42.917l175.125,42.917l0.531-42.034l-134.449-92.931l12.238-241.308L1705.06,1318.313z";
        const series = [];
        [
          ["轨迹", OribitData],
        ].forEach((item, i) => {
          console.log(item);
          console.log('1');
          series.push(
          {
            //尾气特效
            type: "lines",
            zlevel: 1,
            effect: {
              show: true,
              period: 6,//尾气速度
              trailLength: 0.6,//尾气长度
              color: "#fff",//尾气颜色
              symbolSize: 2//尾气大小
            },
            //轨迹线
            lineStyle: {
              normal: {
                color: color[i],
                width: 0,//宽度
                curveness: 0.2//曲率0为直线
              }
            },
            data: this.convertData(item[1])
          },
          {
            //飞机线
            type: "lines",
            zlevel: 2,
            symbol: ["none", "arrow"],
            symbolSize: 10,
            effect: {
              show: true,
              period: 6,//飞机速度
              trailLength: 0,//飞机轨迹长度
              symbol: planePath,
              symbolSize: 15//飞机大小
            },
            lineStyle: {
              normal: {
                color: color[i],
                width: 1,//飞机宽度
                opacity: 0.6,//飞机宽度
                curveness: 0.2//飞机曲率
              }
            },
            data: this.convertData(item[1])
          },
          {
            type: "effectScatter",
            coordinateSystem: "geo",
            zlevel: 2,
            rippleEffect: {
              brushType: "stroke"
            },
            label: {
              normal: {
                show: true,
                position: "right",
                formatter: function(v){
                  console.log(v);
                  return v.data.name;
                }
              }
            },
            symbolSize: function(val) {
              console.log(val);
              return val[2] / 8;
            },
            itemStyle: {
              normal: {
                color: color[i]
              }
            },
            data: item[1].map(dataItem => {
              console.log(dataItem);
              console.log(this.oribmap[dataItem[1].name].concat([dataItem[1].value]));
              console.log(2);
              return {
                name: dataItem[1].name,
                value: this.oribmap[dataItem[1].name].concat([dataItem[1].value])
              };
            }),
            tooltip: {
              show: true,
              formatter: function(val){
                console.log(val);
                return val.data.name + ":"+val.data.value[2];
              }
            }
          }
        );
      });
      const option = {
        backgroundColor: "#404a59",
        title: {
          text: "患者轨迹",
          left: "center",
          textStyle: {
            color: "#fff"
          }
        },
        tooltip: {
          trigger: "item"
        },
        geo: {
          map: "中国",
          label: {
            emphasis: {
              show: false
            }
          },
          roam: true,
          itemStyle: {
            normal: {
              areaColor: "#323c48",
              borderColor: "#404a59"
            },
            emphasis: {
              areaColor: "#2a333d"
            }
          }
        },
      series: series
    };
    this.chart = echarts.init(document.getElementById("orbitchart"));
    this.chart.setOption(option);
  },
  convertData(data) {
    const res = [];
    for (let i = 0; i < data.length; i++) {
      const dataItem = data[i];
      const fromCoord = this.oribmap[dataItem[0].name];
      const toCoord = this.oribmap[dataItem[1].name];
      if (fromCoord && toCoord) {
        res.push({
          fromName: dataItem[0].name,
          toName: dataItem[1].name,
          coords: [fromCoord, toCoord]
        });
      }
    }
    return res;
    }
  }
}
</script>

<style scoped>
    .o-echarts {
        min-width: 1000px;
        min-height: 880px;
    }
</style>

