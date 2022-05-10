<template>
  <div id="editpassword">
    <NewHeader></NewHeader>
    <EditpasswordComponent></EditpasswordComponent>
  </div>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import EditpasswordComponent from '../../components/persondir/EditpasswordComponent.vue'
export default {
  name: 'Editpassword',
  components: {
    NewHeader,
    EditpasswordComponent
  },
}
</script>

<style scoped>
</style>