<template>
  <div>
    <div style="margin-top: 20px">
      <transition-group
          v-bind:css="false"
          v-on:before-enter="beforeEnter"
          v-on:enter="enter">
        <div v-for="(item, index) in pagedata"  :data-index="index" :key="item.id">

          <div class="itembox">
            <slot v-bind:item="item"></slot>
            <el-divider></el-divider>
          </div>
        </div>
      </transition-group>

      <div v-if="pagedata.length === 0" style="font-family: 'rr'; font-size: 25px">{{ blankmessage }}</div>
    </div>
    <el-pagination
        v-if="pagination"
        @size-change="handleSizeChange"
        @current-change="handleCurrentChange"
        :page-sizes="pagesizes"
        :page-size="pagesize"
        :current-page="currentpage"
        layout="total, sizes, prev, pager, next"
        :total="total">
    </el-pagination>
  </div>
</template>

<script>
import "@/assets/fontdir/font.css";
export default {
  name: "Vlist",

  watch:{
    datalist: function () {
      console.log('vlist:datalist change')
      if(typeof (this.datalist) == "undefined")
        alert("无数据");
      if(this.pagination)
        this.handleCurrentChange(1);
      else
        this.pagedata = this.datalist;
      if(typeof(this.currentpage) == "undefined" )
        this.currentpage = 1;
      this.total = this.datalist.length
      console.log(this.pagedata)
    }
  },
  mounted() {

  },
  props:{
    datalist: Array,
    pagination: {
      default: true
    },
    blankmessage:{
      default:"无"
    }
  },
  data(){
    return{
      pagesizes: [5,10,20,50],
      pagesize: 10,
      pagedata:[],
      currentpage:1,
      total:0,
    }

  },
  methods:{
    handleSizeChange(val) {
      this.pagesize = val;
      this.pagedata = this.datalist.slice((this.currentpage - 1) * this.pagesize, this.currentpage * this.pagesize)
    },
    handleCurrentChange(val) {
      this.currentpage = val;
      this.pagedata = this.datalist.slice((this.currentpage - 1) * this.pagesize, this.currentpage * this.pagesize)
    },
    beforeEnter (el) {
      el.style.opacity = 0;
      el.style.transform = "translateY(20px)"
    },
    enter (el, done) {
      let delay = el.dataset.index * (120 - el.dataset.index * 5)
      if(delay < 0)
        delay = 0
      setTimeout(()=>{
        el.style.transition = 'all 0.4s ease';
        el.style.opacity = 1;
        el.style.transform = "translateY(0px)"
        done()
      }, delay)
    }
  }
}
</script>
<style scoped>
.el-divider--horizontal{
  margin: 8px 0;
}
.itembox{
  box-shadow:0px 0px 0px #ffffff;
  transition: all 0.25s ease-in;
}
.itembox:hover{

  box-shadow:0px 3px 3px #c8c8c8;
  transform:scale(1.01,1.01);
  transition: all 0.25s ease-out;
}
</style>