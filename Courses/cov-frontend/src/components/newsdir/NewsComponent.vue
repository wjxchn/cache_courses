<template>
  <main>
    <div class="container">    
      <nav>
        <div class="nav nav-tabs"  id="nav-tab" role="tablist">
          <button class="nav-link active" id="nav-ChinaNews-tab" data-bs-toggle="tab" data-bs-target="#nav-ChinaNews" type="button" role="tab" aria-controls="nav-ChinaNews" aria-selected="true" style="font-family: 'rr'">国内疫情新闻</button>
          <button class="nav-link" id="nav-ForeignNews-tab" data-bs-toggle="tab" data-bs-target="#nav-ForeignNews" type="button" role="tab" aria-controls="nav-ForeignNews" aria-selected="false" style="font-family: 'rr'">国外疫情新闻</button>
          <button class="nav-link" id="nav-Policy-tab" data-bs-toggle="tab" data-bs-target="#nav-Policy" type="button" role="tab" aria-controls="nav-Policy" aria-selected="false" style="font-family: 'rr'">国家疫情防控公告</button>
        </div>
      </nav>
      <div class="tab-content" id="nav-tabContent">
        <!--国内新闻分页-->
        <div class="tab-pane fade show active" id="nav-ChinaNews" role="tabpanel" aria-labelledby="nav-home-tab">
          <div class="chinanews" style="margin-top:2%">
            <!--国内新闻的标题和搜索-->
            <div class="row">
                <div class="col-4">
                  <h2 style="font-family: 'rr'">国内疫情新闻</h2>
                </div>
                <div class="col-4">
                  <select class="form-select" v-model="ProvinceCode" @change="changeProvince">
                  <option v-for="(item, i) in chinalocations" :value="i" v-bind:key="i">{{item.name}}</option>
                </select>
                </div>
                <div class="col-4">
                  <el-input
                    placeholder="请输入内容"
                    prefix-icon="el-icon-search"
                    v-model="keywords"
                    @input="searchProvinceNews">
                  </el-input>
                </div>
              </div>
            <!--国内新闻的列表-->
<!--            <news-pagination-component style="margin-top:5%" :pagesize=5 :pagesizes="[5, 10, 20, 50]" :datalist="chinanews"/>-->
            <vlist :datalist="chinanews" v-slot="items">
              <div class="row">
                <div class="col-xl-9">
                  <el-link tag="a" target="_blank" style="font-family: 'rr'; font-size: 20px; margin-left:40px;" :underline="false" :href="items.item.url">{{ items.item.title }}</el-link>
                </div>
                <div class="col-xl-3">
                  <p style="font-family: 'rr'; margin-left:40px;">{{items.item.time}}</p>
                </div>
                <div class="col-12"  style="font-family: 'rr'; margin-left:40px;">
                  数据来源：{{items.item.site}}
                </div>
              </div>
            </vlist>
          </div>
        </div>


        <!--国外新闻分页-->
        <div class="tab-pane fade" id="nav-ForeignNews" role="tabpanel" aria-labelledby="nav-profile-tab">
          <div class="foreignnews" style="margin-top:2%">
            <!--国外新闻分页的标题和搜索框-->
            <div class="row">
            <div class="col-8">
              <h2 style="font-family: 'rr'">国外疫情新闻</h2>
            </div>
            <div class="col-4">
              <el-input
                placeholder="请输入内容"
                prefix-icon="el-icon-search"
                v-model="keywords2"
                @input="searchForeignNews"
              >
              </el-input>
            </div>
          </div>
<!--            <news-pagination-component style="margin-top:5%" :pagesizes="[5, 10, 15, 20]" :pagesize="5" :datalist="foreignnews"/>-->
            <vlist :datalist="foreignnews" v-slot="items">
              <div class="row">
                <div class="col-xl-9">
                  <el-link tag="a" target="_blank" style="font-family: 'rr'; font-size: 20px; margin-left:40px;" :underline="false" :href="items.item.url">{{ items.item.title }}</el-link>
                </div>
                <div class="col-xl-3">
                  <p style="font-family: 'rr'; margin-left:40px;">{{items.item.time}}</p>
                </div>
                <div class="col-12"  style="font-family: 'rr'; margin-left:40px;">
                  数据来源：{{items.item.site}}
                </div>
              </div>
            </vlist>
          </div>
        </div>
        <div class="tab-pane fade" id="nav-Policy" role="tabpanel" aria-labelledby="nav-contact-tab">
          <div class="policy" style="margin-top:2%">
            <div class="row">
                <div class="col-8">
                  <h2 style="font-family: 'rr'">国家疫情防控公告</h2>
                </div>
                <div class="col-4">
                  <el-input
                    placeholder="请输入内容"
                    prefix-icon="el-icon-search"
                    v-model="keywords3"
                    @input="searchNotice"
                  >
                  </el-input>
                </div>
              </div>
              <div class="pn" style="margin-top:2%">
                <el-timeline>
                  <el-timeline-item
                    v-for="(notice, index) in notices"
                    :key="index"
                    :timestamp="notice.time">
                    <el-link tag="a" target="_blank" :underline="false" :href="notice.url" style="font-family: 'rr';font-size: 20px">{{notice.title}}</el-link>
                  </el-timeline-item>
                </el-timeline>
              </div>

          </div>
        </div>
      </div>
    </div>
  </main>
</template>

<script>
import Vlist from "@/components/newsdir/Vlist";
export default {
  components: {Vlist},
  data() {
    return {
      currentPage1: 5,
      ProvinceCode: 0,

      //中国新闻部分
      chinanews:[],
      chinalocations:[],
      keywords:"",

      //国际新闻部分
      foreignnews:[],
      keywords2:"",

      //通告部分
      notices:[],
      keywords3:""
    };
  },
  mounted() {

    //请求中国新闻
    var that = this;
    this.postRequest('/news',{locationId:1})
        .then((response) => {
          that.chinanews = response.data;
        } )
        .catch((error) => { console.log("获取中国新闻异常======" + error) })


    //请求中国省份列表
    this.postRequest('/locations',{belongId:1})
        .then((response) => {
          that.chinalocations = response.data;that.chinalocations.unshift({id:1, name:"全国"})
        } )
        .catch((error) => { console.log("获取中国省份列表错误======" + error) })


    //请求国际新闻
    this.postRequest('/news',{locationId:0})
        .then((response) => {
          that.foreignnews = response.data;} )
        .catch((error) => { console.log("获取外国新闻异常======" + error) })


    //请求通告
    this.postRequest('/allnotices')
        .then((response) => {
          that.notices = response.data;} )
        .catch((error) => { console.log("获取通告异常======" + error) })
  },
  methods:{

    //当国内新闻页面切换下拉框选择省份时
    changeProvince(){
      var that = this;
      if(typeof (this.keywords) == "undefined")
      {
        if (this.chinalocations[this.ProvinceCode].id === 480 || this.chinalocations[this.ProvinceCode].id === 497 || this.chinalocations[this.ProvinceCode].id === 434)
        {
          this.chinanews = [{title:'暂无数据',id:0, site:'暂无数据'}]
        }
        else {
          this.postRequest('/news',{locationId:this.chinalocations[this.ProvinceCode].id})
              .then((response) => {
                that.chinanews = response.data;} )
              .catch((error) => { console.log("获取中国新闻异常======" + error) })
        }
      }
      else
        this.searchProvinceNews();
    },


    //当国内新闻分页输入框内容变化时
    searchProvinceNews(){
      var that = this;
      if (this.chinalocations[this.ProvinceCode].id === 480 || this.chinalocations[this.ProvinceCode].id === 497 || this.chinalocations[this.ProvinceCode].id === 434)
      {
        this.chinanews = [{title:'暂无数据',id:0, site:'暂无数据'}]
      }
      else {
        this.postRequest('/searchnews',{locationId:this.chinalocations[this.ProvinceCode].id, keywords:this.keywords})
            .then((response) => {
              that.chinanews = response.data;} )
            .catch((error) => { console.log("获取中国新闻异常======" + error) })
      }
    },

    //当国外新闻分页输入框内容变化时
    searchForeignNews(){
      var that = this;
      this.postRequest('/searchnews',{locationId: 0,keywords:this.keywords2})
          .then((response) => {
            that.foreignnews = response.data;} )
          .catch((error) => { console.log("获取中国新闻异常======" + error) })
    },
    //当通告输入框内容变化时
    searchNotice(){
      var that = this;
      this.postRequest('/searchnotices',{keywords:this.keywords3})
          .then((response) => {
            that.notices = response.data;} )
          .catch((error) => { console.log("获取通告异常======" + error) })
    }

  }

}
</script>

<style scoped>
#nav-tab .nav-link{
  color: black;
}
#nav-tab .active{
  color: #40aaff;
}
</style>