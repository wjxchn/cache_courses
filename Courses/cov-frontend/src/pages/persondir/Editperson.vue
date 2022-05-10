<template>
  <div id="editperson">
    <NewHeader></NewHeader>
    <EditpersonComponent></EditpersonComponent>
    <FooterComponent></FooterComponent>
  </div>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import EditpersonComponent from '../../components/persondir/EditpersonComponent.vue'
import FooterComponent from '../../components/footerdir/FooterComponent.vue'
export default {
  name: 'Editperson',
  components: {
    NewHeader,
    EditpersonComponent,
    FooterComponent
  },
}
</script>

<style scoped>
</style>