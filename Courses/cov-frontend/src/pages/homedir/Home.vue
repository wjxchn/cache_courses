<template>
  <div id="home">
    <NewHeader></NewHeader>
    <HomeComponent :china-data="chinaData" :global-data="globalData" :table-data="tableData" :table-data-show="tableDataShow"></HomeComponent>
    <FooterComponent></FooterComponent>
  </div>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import HomeComponent from '../../components/homedir/HomeComponent.vue'
import FooterComponent from '../../components/footerdir/FooterComponent.vue'
export default {
  name: 'Home',
  components: {
    NewHeader,
    HomeComponent,
    FooterComponent
  },
  data(){
    return {
      //设置初始值避免加载过慢显示不出来
      chinaData:{
        cov_data:{
          confirm:0,no_infect_add:0,no_infect:0,dead_add:0,heal:0,now_confirm:0,dead:0,now_confirm_add:0,heal_add:0,confirm_add:0
        }
      },
      globalData:{
        cov_data:{
          confirm:0,no_infect_add:0,no_infect:0,dead_add:0,heal:0,now_confirm:0,dead:0,now_confirm_add:0,heal_add:0,confirm_add:0
        }
      },
      tableData: '',
      tableDataShow:'',
    }
  },
  mounted(){
    this.postRequest('/covdata')
        .then((response) => {
          this.chinaData = response.data;
          this.tableData = this.chinaData.locations
          console.log(response.data);
          this.tableDataShow = this.tableData
          for (let i = 0;i<this.tableData.length;i++)
          {
            this.tableData[i].index = i
          }
          for(var i = 0; i < this.chinaData.locations.length; i++){
            if(this.chinaData.locations[i].id == 2 || this.chinaData.locations[i].id == 27 || this.chinaData.locations[i].id == 218){
              this.chinaData.locations[i].risk = '-'
            }
          }
        } )

        .catch((error) => { console.log(error) })
    this.postRequest('/globalcovdata')
        .then((response) => {
          this.globalData = response.data;} )
        .catch((error) => { console.log(error) })

  }
}
</script>

<style scoped>

</style>