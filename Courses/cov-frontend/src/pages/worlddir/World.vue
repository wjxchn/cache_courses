<template>
  <div id="province">
    <NewHeader></NewHeader>
    <WorldInfo></WorldInfo>
    <FooterComponent></FooterComponent>
  </div>
</template>

<script>
import WorldInfo from "@/components/worlddir/WorldInfo";
import NewHeader from "@/components/headerdir/NewHeader";
import FooterComponent from '../../components/footerdir/FooterComponent.vue'
export default {
  name: "Province",
  components:{
    NewHeader,
    WorldInfo,
    FooterComponent
  }
}
</script>

<style scoped>

</style>