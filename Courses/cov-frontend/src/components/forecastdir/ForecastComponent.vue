<template>
  <main>
    <div class="jumbotron">
      <div class="mainimg">
        <div style="font-size: 3vw;padding-top: 20%;font-family: 'rr';color: white" align="center">
          <div>为您提供最权威的疫情数据</div>
          <div>COVARIANCE, Covid-19 Information and Variance</div>
        </div>
      </div>
    </div>

    <h2 style="font-family:'rr';margin-top:20px" align="center">疫情预测评估</h2>
    <h4 align="center">Prediction Assessment</h4>
    <div style="margin-top:10px" class="container">
    <div class="col-md-12">
      <div class="row">
        <div class="col-md-4">
          <div calss="swiper_img" style="padding-top:50px">
            <a @click="toprediction()">
              <img style="width:100%" src="../../assets/picdir/prediction1.jpg">
            </a>
          </div>
          <div calss="swiper_img">
            <a @click="tochinaprediction()">
              <img style="width:100%" src="../../assets/picdir/prediction2.png">
            </a>
          </div>
          <div calss="swiper_img">
            <a @click="toglobalprediction()">
              <img style="width:100%" src="../../assets/picdir/prediction3.png">
            </a>
          </div>
        </div>
        <div class="col-md-8">
          <div align="center" class="char-title">
            <h2 >我国新增人数预测</h2>
            <p> Global Prediction of COVID-19 New Cases</p>
          </div>
          <!--预测图
            <ChinaMapComponent style="height:50vw;" mapId="china1" ref="chinamapref" :mapdata="ChinaData.locations"></ChinaMapComponent>
          -->
        </div>
      </div>
    </div>
    </div>

    <hr class="featurette-heading">

    <div class="col_bottom">
      <h2 style="font-family:'rr'" align="center">全球逐月预测及其季节预测</h2>
      <h4 align="center">Global Monthly and Seasonal Prediction</h4>
      <div class="col-md-12">
      <div class="row">
        <div class="col-md-5" style="margin-left:5%">
          <div class="row">
            <div class="col">
              <h4 style="font-family:'rr'">全球每月预测概况</h4>      
            </div>
            <div class="col-3">
              <select class="form-select" aria-label="Default select example">
                <option selected>Global</option>
                <option value="1">US</option>
                <option value="2">India</option>
                <option value="3">Russia</option>
              </select>
            </div>
            <div class="col-3">
              <select class="form-select" aria-label="Default select example">
                <option selected>Jul 2021</option>
                <option value="1">Aug 2021</option>
                <option value="2">Sept 2021</option>
                <option value="3">Oct 2021</option>
              </select>
            </div>
            <h6 >Overview of Monthly Global Prediction</h6>
            <!--预测图-->
            <div class="monthly-predication-chart">
              <MonthlyComponent style="width:100%" id="main" ></MonthlyComponent>
            </div>

          </div>
        </div>
        <div class="col-md-5" style="margin-left:5%">
          <div class="row">
            <div class="col">
              <h4 style="font-family:'rr'">全球新增季节预测</h4>      
            </div>
            <div class="col-3">
              <select class="form-select" aria-label="Default select example">
                <option selected>Global</option>
                <option value="1">US</option>
                <option value="2">India</option>
                <option value="3">Russia</option>
              </select>
            </div>
            <div class="col-3">
              <select class="form-select" aria-label="Default select example">
                <option selected>Spring</option>
                <option value="1">Summer</option>
                <option value="2">Autumn</option>
                <option value="3">Winter</option>
              </select>
            </div>
            <h6 >Seasonal Prediction of New Cases</h6>
            <!--预测图-->
            <div class="monthly-predication-chart">
            </div>

          </div>
        </div>
      </div>
      </div>
    </div>
  </main>
</template>

<script>
//import ChinaMapComponent from '@/components/mapdir/ChinaMapComponent.vue'
import MonthlyComponent from '@/components/forecastdir/MonthlyComponent.vue'
import "@/assets/fontdir/font.css";
export default {
  components:{
    //ChinaMapComponent,
    MonthlyComponent,
  },
  methods:{
    toprediction(){
      this.$router.push('/404')
    },
    tochinaprediction(){
      this.$router.push('/404')
    },
    toglobalprediction(){
      this.$router.push('/404')
    }
  }
}
</script>

<style scoped>
.mainimg{
  width: 100%;
  height: 35vw;
  background-image: url("../../assets/picdir/home_pic.jpeg");
  background-size: 100% 100%;
}
</style>