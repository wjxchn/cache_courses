<template>
  <div style="font-family: 'rr'">
    <div class="card text-center" style="height: 260px">
      <div class="card-title" style="padding-top: 20px;font-size: 20px;padding-bottom: 15px">
        <div style="font-size: 25px">当前位置——{{location1}}{{location2}}{{location3}}</div>
      </div>
      <div class="row" style="padding-bottom:10px;">
        <div class="col-4">
          <div style="font-size: 16px;">现有确诊</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: orange">{{covdata.now_confirm}}</div>
        </div>
        <div class="col-4">
          <div style="font-size: 16px;">累计治愈</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: #50abb3">{{covdata.heal}}</div>
        </div>
        <div class="col-4">
          <div style="font-size: 16px;">累计死亡</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: #4e4f54">{{covdata.dead}}</div>
        </div>
        <div style="padding: 5px"></div>
        <div class="col-4">
          <div style="font-size: 16px;">累计确诊</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: red">{{covdata.confirm}}</div>
        </div>
        <!-- <div class="col-3">
          <div style="font-size: 16px;">境外输入</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: #4f6c9c">{{}}</div>
          <div style="font-size: 15px">昨日<span style="font-family: 'Times New Roman';color: #4f6c9c">{{}}</span></div>
        </div> -->
        <div class="col-4">
          <div style="font-size: 16px;">治愈率</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: #50abb3">{{(covdata.heal*100/covdata.confirm).toFixed(2)}}%</div>
        </div>
        <div class="col-4">
          <div style="font-size: 16px;">死亡率</div>
          <div style="font-size: 30px;font-family: 'Times New Roman';color: #4e4f54">{{(covdata.dead*100/covdata.confirm).toFixed(2)}}%</div>
        </div>
        <div class="col-md-12" style="font-size: 13px;color: gray;text-align: right;margin-left: -10px">
          提示:暂无定位代表您可能位于港澳台地区或海外，或者没有开启浏览器定位
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import "@/assets/fontdir/font.css";
export default {
  name: "Chart",
  props: ['location1', 'location2', 'location3', 'covdata']
}
</script>

<style scoped>

</style>