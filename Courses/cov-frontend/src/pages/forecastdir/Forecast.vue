<template>
  <main>
    <NewHeader></NewHeader>
    <ForecastComponent></ForecastComponent>
    <FooterComponent></FooterComponent>
  </main>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import ForecastComponent from '../../components/forecastdir/ForecastComponent.vue'
import FooterComponent from '../../components/footerdir/FooterComponent.vue'
export default {
    name:'Forecast',
    components:{
        NewHeader,
        ForecastComponent,
        FooterComponent
    }
}
</script>

<style scoped>

</style>