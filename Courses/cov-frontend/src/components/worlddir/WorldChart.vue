<template>
    <div style="font-family: 'rr'">
      <div class="card text-center" style="height: 315px">
        <h3 class="card-title" style="padding-top: 20px;padding-bottom: 20px">{{title}}</h3>
        <div class="row" style="padding: 10px;padding-bottom:20px;">
          <div class="col-3">
            <div style="font-size: 16px;">现有确诊</div>
            <div style="font-size: 30px;font-family: 'Times New Roman';color: orange">{{data.now_confirm}}</div>
            <div style="font-size: 15px">昨日<span style="font-family: 'Times New Roman';color: orange">{{data.now_confirm_add > 0? '+' + data.now_confirm_add : data.now_confirm_add}}</span></div>
          </div>
          <div class="col-3">
            <div style="font-size: 16px;">累计治愈</div>
            <div style="font-size: 30px;font-family: 'Times New Roman';color: #50abb3">{{data.heal}}</div>
            <div style="font-size: 15px">昨日<span style="font-family: 'Times New Roman';color: #50abb3">{{data.heal_add > 0? '+' + data.heal_add : data.heal_add}}</span></div>
          </div>
          <div class="col-3">
            <div style="font-size: 16px;">累计死亡</div>
            <div style="font-size: 30px;font-family: 'Times New Roman';color: #4e4f54">{{data.dead}}</div>
            <div style="font-size: 15px">昨日<span style="font-family: 'Times New Roman';color: #4e4f54">{{data.dead_add > 0? '+' + data.dead_add : data.dead_add}}</span></div>
          </div>
          <div class="col-3">
            <div style="font-size: 16px;">累计接种</div>
            <div style="font-size: 30px;font-family: 'Times New Roman';color: #2972e5">{{data.total_vaccinations}}剂</div>
          </div>
          <div style="margin-bottom: 20px"></div>
          <div class="col-3">
            <div style="font-size: 16px;">累计确诊</div>
            <div style="font-size: 30px;font-family: 'Times New Roman';color: #e83132">{{data.confirm}}</div>
            <div style="font-size: 15px">昨日<span style="font-family: 'Times New Roman';color: #e83132">{{data.confirm_add > 0? '+' + data.confirm_add : data.confirm_add}}</span></div>
          </div>
          <div class="col-3">
            <div style="font-size: 16px;">治愈率</div>
            <div style="font-size: 30px;font-family: 'Times New Roman';color: #50abb3">{{(data.heal*100/data.confirm).toFixed(2)}}%</div>
          </div>
          <div class="col-3">
            <div style="font-size: 16px;">死亡率</div>
            <div style="font-size: 30px;font-family: 'Times New Roman';color: #4e4f54">{{(data.dead*100/data.confirm).toFixed(2)}}%</div>
          </div>
          <div class="col-3">
            <div style="font-size: 16px;">每百人接种</div>
            <div style="font-size: 30px;font-family: 'Times New Roman';color: #2972e5">{{data.total_vaccinations_per_hundred}}剂</div>
          </div>
        </div>
      </div>
    </div>
</template>

<script>
import "@/assets/fontdir/font.css";
export default {
  name: "WorldChart",
  props: {
    title: {
      type: String,
      default: '世界疫情概况'
    },
    time: {

    },
    data: {

    }
  },
  methods: {

  }
}
</script>

<style scoped>

</style>