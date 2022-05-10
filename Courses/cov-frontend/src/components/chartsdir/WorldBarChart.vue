<template>
  <div class="echarts" style="width: 100%;height: 360px">
    <div id="barId" style="width: 100%;height: 360px"></div>
  </div>
</template>

<script>
import echarts from '../../plugins/echarts';
export default {
  name: "WorldBarChart",
  props:{
    barId:{
      type:String,
      default: null
    },
    world_acc:{
      type:Number,
      default: null
    },
    dataList:{},
  },
  data() {
    return {
      colorlist: [],
      option : {
        xAxis: {
          type: 'category',
          data: [],
          axisLabel: { interval: 0},
        },
        tooltip: {
          trigger: 'item',
          formatter: '每百人疫苗接种剂次<br/>{b} : {c}'
        },
        yAxis: {
          type: 'value'
        },
        series: [{
          data: [],
          type: 'bar'
        }]
      }
    }
  },
  watch:{
    dataList: function (){
      var chart = document.getElementById('barId')
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
      let color = ['#5a6fc0','#9eca7f','#f2ca6b','#ee7874','#85bedb','#59a076','#ec8a5d','#9264af']
      for(let i =0;i<8;i++)
      {
        let name = dataListSorted[i].name
        let val = parseFloat(dataListSorted[i].total_vaccinations_per_hundred)
        this.option.xAxis.data.push(name)
        console.log(color[i])
        this.option.series[0].data.push({
          value: val,
          itemStyle: {
            color: color[i]
          }
        })
      }
      this.option.xAxis.data.push('世界平均')
      this.option.series[0].data.push({
        value: this.world_acc,             
        itemStyle: {
          color: '#ef8edc'
        }
      })
      console.log(this.option.xAxis.data)
      this.myChart.setOption(this.option);
    }
  },
  mounted() {
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