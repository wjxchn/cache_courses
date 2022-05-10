<template>
  <div style="font-family: 'rr'">
    <div class="card text-center">
      <h3 class="card-title" style="padding-top: 20px;padding-bottom: 20px">{{title}}</h3>
      <div class="row" style="padding: 10px;padding-bottom:20px;">
        <div class="col-3">
          <div style="font-size: 16px;">现有确诊</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: orange">{{cov_data.now_confirm}}</div>
          <div style="font-size: 15px">昨日<span style="font-family: 'Times New Roman';color: orange">{{cov_data.now_confirm_add > 0? '+' + cov_data.now_confirm_add : cov_data.now_confirm_add}}</span></div>
        </div>
        <div class="col-3">
          <div style="font-size: 16px;">无症状</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: darkorange">{{cov_data.no_infect}}</div>
          <div style="font-size: 15px">昨日<span style="font-family: 'Times New Roman';color: darkorange">{{cov_data.no_infect_add > 0? '+' + cov_data.no_infect_add : cov_data.no_infect_add}}</span></div>
        </div>
        <div class="col-3">
          <div style="font-size: 16px;">累计治愈</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: #50abb3">{{cov_data.heal}}</div>
          <div style="font-size: 15px">昨日<span style="font-family: 'Times New Roman';color: #50abb3">{{cov_data.heal_add > 0? '+' + cov_data.heal_add : cov_data.heal_add}}</span></div>
        </div>
        <div class="col-3">
          <div style="font-size: 16px;">累计死亡</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: #4e4f54">{{cov_data.dead}}</div>
          <div style="font-size: 15px">昨日<span style="font-family: 'Times New Roman';color: #4e4f54">{{cov_data.dead_add > 0? '+' + cov_data.dead_add : cov_data.dead_add}}</span></div>
        </div>

        <div style="padding: 10px"></div>

        <div class="col-3">
          <div style="font-size: 16px;">累计确诊</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: red">{{cov_data.confirm}}</div>
          <div style="font-size: 15px">昨日<span style="font-family: 'Times New Roman';color: red">{{cov_data.confirm_add > 0? '+' + cov_data.confirm_add : cov_data.confirm_add}}</span></div>
        </div>
        <div class="col-3">
          <div style="font-size: 16px;">每百人接种</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: #2972e5">{{cov_data.total_vaccinations_per_hundred}}剂</div>
        </div>
        <div class="col-3">
          <div style="font-size: 16px;">治愈率</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: #50abb3">{{(cov_data.heal*100/cov_data.confirm).toFixed(2)}}%</div>
        </div>
        <div class="col-3">
          <div style="font-size: 16px;">死亡率</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: #4e4f54">{{(cov_data.dead*100/cov_data.confirm).toFixed(2)}}%</div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import "@/assets/fontdir/font.css";
export default {
  name: "Chart",
  props: ['title', 'time', 'cov_data']
}
</script>

<style scoped>

</style>