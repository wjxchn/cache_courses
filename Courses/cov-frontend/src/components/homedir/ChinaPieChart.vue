<template>
  <div class="echarts" style="width: 100%">
    <div :id="pieId" style="width: 100%"></div>
  </div>
</template>

<script>
import echarts from '../../plugins/echarts';
export default {
  name: "ChinaPieChart",
  props:{
    pieId:{
      type:String,
      default: null
    },
    height:{
      type: String,
      default: 300
    },
    now_confirm_all:{
      type:Number,
      default: null
    },
    dataList:{},
  },
  data() {
    return {
      option : {
        legend: {
          orient: 'vertical',
          right:'right'
        },
        tooltip: {
          trigger: 'item',
          formatter: '现有确诊人数<br/>{b} : {c} ({d}%)'
        },
        toolbox: {
          show: true,
          feature: {
            mark: {show: true},
          }
        },
        // geo:{
        //   zoom : 1
        // },
        series: [
          {
            name: '访问来源',
            type: 'pie',
            radius: ['40%', '70%'],
            avoidLabelOverlap: false,
            itemStyle: {
              borderRadius: 10,
              borderColor: '#fff',
              borderWidth: 2
            },
            emphasis: {
            },
            labelLine: {
              show: true
            },
            data: [
            ]
          }
        ]
      }
    }
  },
  watch:{
    dataList: function (){
      var chart = document.getElementById(this.pieId)
      this.myChart = echarts.init(chart)
      var compare = function (x, y) {//比较函数
        if (x.now_confirm < y.now_confirm) {
          return 1;
        } else if (x.now_confirm > y.now_confirm) {
          return -1;
        } else {
          return 0;
        }
      }
      let dataListSorted = []
      dataListSorted = this.dataList.concat()
      dataListSorted.sort(compare)
      let sum = 0
      for(let i =0;i<8;i++)
      {
        let tmp = {
          name: dataListSorted[i].name,
          value: parseInt(dataListSorted[i].now_confirm)
        }
        sum += tmp.value
        this.option.series[0].data.push(tmp)
      }
      this.option.series[0].data.push({
        name: '其他省份',
        value: this.now_confirm_all - sum
      })
      this.myChart.setOption(this.option);
    }
  },
  mounted() {
    var div = document.getElementsByClassName("echarts")
    div[0].style.height = this.height + 'px'
    div[0].style.width = this.width + 'px'
    var chart = document.getElementById(this.pieId)
    chart.style.height = this.height + 'px'
    chart.style.width = this.width + 'px'
  },
  beforeDestroy() {
    if (!this.myChart) {
      return
    }
    this.myChart.dispose()
    this.myChart = null
  },
}
</script>

<style scoped>

</style>