<template>
  <div id="province">
    <NewHeader></NewHeader>
    <ProvinceInfo></ProvinceInfo>
    <FooterComponent></FooterComponent>
  </div>
</template>

<script>
import ProvinceInfo from "@/components/provincedir/ProvinceInfo";
import NewHeader from "@/components/headerdir/NewHeader";
import FooterComponent from '../../components/footerdir/FooterComponent.vue'
export default {
  name: "Province",
  components:{
    NewHeader,
    ProvinceInfo,
    FooterComponent
  }
}
</script>

<style scoped>

</style>