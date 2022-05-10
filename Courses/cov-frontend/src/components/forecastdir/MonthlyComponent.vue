<template>
	<div id="main" style="width: 600px;height: 400px;"></div>
</template>
<script>
import echarts from '../../plugins/echarts'
//折线图test
	export default {
		name: 'test',
		data() {
			return {
				charts: 'test',
				opinionData: ["3", "2", "4", "4", "5"]
			}
		},
		methods: {
			drawLine(id) {
				this.charts = echarts.init(document.getElementById(id))
				this.charts.setOption({
					tooltip: {
						trigger: 'axis'
					},
					legend: {
						data: ['近七日收益']
					},
					grid: {
						left: '3%',
						right: '4%',
						bottom: '3%',
						containLabel: true
					},

					toolbox: {
						feature: {
							saveAsImage: {}
						}
					},
					xAxis: {
						type: 'category',
						boundaryGap: false,
            data: ["1","2","3","4","5"]
					},
					yAxis: {
						type: 'value'
					},

					series: [{
						name: '近七日收益',
						type: 'line',
						stack: '总量',
						data: this.opinionData
					}]
				})
			}
		},
		//调用
		mounted() {
			this.$nextTick(function() {
				this.drawLine('main')
			})
		}
	}
</script>
<style scoped>
	
</style>
