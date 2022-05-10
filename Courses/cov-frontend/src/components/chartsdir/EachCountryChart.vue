<template>
  <div class="echarts" style="width: 100%;">
    <div style="width: 100%" :id="mapId"></div>
  </div>
</template>

<script>
import echarts from '../../plugins/echarts'
export default {
  name: 'EachCountryChart',
  props: {
    mapId: {
      type: String,
      default: null
    },
    dataList: {

    },
    dimensions: {
      type: Array,
      default: () => ['confirm', 'heal', 'dead', 'confirm_add']
    },
    height: {
      type: String,
      default: '300'
    },
  },
  data() {
    return {
      mapOption: {
        // legend: ['确诊', '治愈', '死亡'],
        // tooltip: {
        //   trigger: 'item',
        //   formatter: '{b}<br/>{c} (p / km2)',
        // },
        // legend: {
        //   data: ['confirm', 'dead', 'heal'],
        // },
        // toolbox: {
        //   feature: {
        //     saveAsImage: {},
        //   },
        // },
        grid: {
          containLabel: true,
          // left: 70
        },
        dataset: {
          dimensions: ['date', 'confirm', 'heal', 'dead'],
          source: [],
        },
        xAxis: {
          type: 'category',
        },
        yAxis: [
          {//第一个y轴位置在左侧
            position:'left',
            type : 'value',
            name: '累计确诊/治愈/死亡人数',
            axisLabel: {
              formatter: '{value} 个'
            }
          },
        ],
        tooltip: {
          trigger: 'axis',
        },
        toolbox:{},
        legend: {data: []},
        series: [],
        flag: true
      },
    }
  },
  mounted() {
    var div = document.getElementsByClassName("echarts")
    div[0].style.height = this.height + 'px'
    var chart = document.getElementById(this.mapId)
    chart.style.height = this.height + 'px'
    //this.getdata()
  },
  watch: {

    dataList: function () {
      this.mapOption.dataset.source = this.dataList
      var newDimensions = ['datetime']
      var newSeries = [];
      for(var i=0; i<this.dimensions.length; i++){
        newDimensions.push(this.dimensions[i])
        if(this.dimensions[i] == 'confirm'){
          newSeries.push({ type: 'line', name: '确诊', color: '#ff8a37', symbol: 'none', yAxisIndex:'0'})
          this.mapOption.legend.data.push("确诊")
        } else if(this.dimensions[i] == 'heal'){
          newSeries.push({ type: 'line', name: '治愈', color: '#0ee9c6', symbol: 'none', yAxisIndex:'0'})
          this.mapOption.legend.data.push("治愈")
        } else if(this.dimensions[i] == 'dead'){
          newSeries.push({ type: 'line', name: '死亡', color: '#f35353', symbol: 'none', yAxisIndex:'0'})
          this.mapOption.legend.data.push("死亡")
        } else if(this.dimensions[i] == 'total_vaccinations'){
          newSeries.push({ type: 'line', name: '接种', color: '#44a3ef', symbol: 'none', yAxisIndex:'1'})
          this.mapOption.legend.data.push("接种")
          this.mapOption.yAxis.push({ position:'right', type : 'value', name: '疫苗接种数', max: 2000000000, splitNumber: 5, axisLabel: { formatter: '{value} 人' }},)
        } else if(this.dimensions[i] == 'confirm_add'){
          newSeries.push({ type: 'line', name: '新增确诊', color: '#44a3ef', symbol: 'none', yAxisIndex:'1'})
          this.mapOption.legend.data.push("新增确诊")
          this.mapOption.yAxis.push({ position:'right', type : 'value', name: '新增确诊', axisLabel: { formatter: '{value} 人' }})
        }
      }
      this.mapOption.legend.selected = {"确诊": true, "死亡": false, "治愈": false, "接种": true, "新增确诊": true, }
      this.mapOption.dataset.dimensions = newDimensions
      this.mapOption.series = newSeries
      var that = this
      this.myChart = echarts.init(document.getElementById(that.mapId))
      // echarts.registerMap("杭州市", JSON, {}); //这个是关键，之前拿到的青州各街道数据
      this.myChart.setOption(this.mapOption)
    }
  },
  beforeDestroy() {
    if (!this.chart) {
      return
    }
    this.chart.dispose()
    this.chart = null
  },
  methods: {
    /**

     drawMap() {
      //地图
      var that = this
      this.myChart = echarts.init(document.getElementById(that.mapId))
      // echarts.registerMap("杭州市", JSON, {}); //这个是关键，之前拿到的青州各街道数据
      this.myChart.setOption(this.mapOption)
    },
     getdata() {
      this.$axios({
        method: 'get',
        url: 'https://api.inews.qq.com/newsqa/v1/query/inner/publish/modules/list?modules=chinaDayList',
      })
        .then((response) => {
          console.log('拿到数据了！')
          console.log(response)
          console.log(response.data.chinaDayList)
          this.mapOption.dataset.source = response.data.chinaDayList
          console.log(this.mapOption)
          this.drawMap()
        })
        .catch((error) => {
          console.log(error)
        })
    },
     */
  },

}
</script>