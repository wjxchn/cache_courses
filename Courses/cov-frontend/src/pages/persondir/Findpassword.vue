<template>
  <div id="register">
    <NewHeader></NewHeader>
    <FindpasswordComponent></FindpasswordComponent>
  </div>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import FindpasswordComponent from '../../components/persondir/FindpasswordComponent.vue'
export default {
  name: 'Findpassword',
  components: {
    NewHeader,
    FindpasswordComponent
  },
}
</script>

<style scoped>
</style>