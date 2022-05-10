<template>
  <div>

    <div>
      <div class="brick" v-for="item in pagedata" :key="item">
        <div class="row">
          <div class="col-xl-9">
            <el-link tag="a" target="_blank" style="font-family: 'rr'; font-size: 20px; margin-left:40px;" :underline="false" :href="item.url">{{ item.title }}</el-link>
          </div>
          <div class="col-xl-3">
            <p style="font-family: 'rr'; margin-left:40px;">{{item.time}}</p>
          </div>
          <div class="col-12"  style="font-family: 'rr'; margin-left:40px;">
            数据来源：{{item.site}}
          </div>
        </div>
        <el-divider></el-divider>
      </div>
    </div>
    <el-pagination
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
  name: "newsPaginationComponent",
  props:{
    pagesizes: Array,
    pagesize: Number,
    datalist: Array
  },
  watch:{
    datalist: function () {
      if(typeof (this.datalist) == "undefined")
        this.$message({message: "无数据", type:'error'});
      this.handleCurrentChange(1);
      if(typeof(this.currentpage) == "undefined" )
        this.currentpage = 1;

      this.total = this.datalist.length

    }
  },
  data(){
    return{
      pagedata:[],
      currentpage:1,
      total:0
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
    }
  }
}
</script>

<style>

</style>