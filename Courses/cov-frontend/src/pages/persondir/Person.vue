<template>
  <div id="register">
    <NewHeader></NewHeader>
    <PersonComponent></PersonComponent>
    <FooterComponent></FooterComponent>
  </div>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import PersonComponent from '../../components/persondir/PersonComponent.vue'
import FooterComponent from '../../components/footerdir/FooterComponent.vue'
export default {
  name: 'Person',
  components: {
    NewHeader,
    PersonComponent,
    FooterComponent
  },
}
</script>

<style scoped>
</style>