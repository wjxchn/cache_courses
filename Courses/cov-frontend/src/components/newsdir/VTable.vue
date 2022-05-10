<template>
  <div>

    <el-pagination
        @size-change="handleSizeChange"
        @current-change="handleCurrentChange"
        :page-sizes="pagesizes"
        :page-size="pagesize"
        :current-page="currentpage"
        layout="total, sizes, prev, pager, next"
        :total="total">
    </el-pagination>
    <div style="margin-top: 20px">

      <table id="vtable" class="table table-striped table-sm table-hover">
        <thead>
        <tr>
          <th scope="col">航班号</th>
          <th scope="col">出发地</th>
          <th scope="col">目的地</th>
          <th scope="col">出发时间</th>
          <th scope="col">变更情况</th>
        </tr>
        </thead>
        <tbody is="transition-group" v-bind:css="false"
               v-on:before-enter="beforeEnter"
               v-on:enter="enter"
        >
        <tr v-for="(item, index) in pagedata" :data-index="index" :key="item.id">
          <td>{{item.num}}</td>
          <td>{{item.src}}</td>
          <td>{{item.des}}</td>
          <td>{{item.time}}</td>
          <td>{{item.tip}}</td>
        </tr>
        </tbody>
      </table>
    </div>



  </div>
</template>

<script>
import "@/assets/fontdir/font.css";
export default {
  name: "Vlist",

  watch:{
    datalist: {
      handler() {
        if(typeof (this.datalist) == "undefined")
          alert("无数据");
        this.handleCurrentChange(1);
        if(typeof(this.currentpage) == "undefined" )
          this.currentpage = 1;
        this.total = this.datalist.length

      },
      immediate:true
    }
  },
  props:{
    datalist: Array
  },
  data(){
    return{
      pagesizes: [5,10,20,50],
      pagesize: 10,
      pagedata:[],
      currentpage:1,
      total:0,
      entertime: 0,
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
      this.entertime = 0;
      el.style.opacity = 0;
      el.style.transform = "translateX(10px)"
    },
    enter (el, done) {
      let delay = this.entertime;
      this.entertime += 50;
      setTimeout(()=>{
        el.style.transition = 'all 0.25s ease';
        el.style.opacity = 1;
        el.style.transform = "translateX(0px)";
        done()
      }, delay)
    },

  }
}
</script>

<style scoped>
#vtable{
  table-layout:fixed;
  font-size: 20px;
  overflow: auto;
}
#vtable td{
  padding-top: 10px;
  padding-bottom: 10px;
}
</style>