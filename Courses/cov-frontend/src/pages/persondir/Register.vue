<template>
  <div id="register">
    <NewHeader></NewHeader>
    <RegisterComponent></RegisterComponent>
  </div>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import RegisterComponent from '../../components/persondir/RegisterComponent.vue'
export default {
  name: 'Register',
  components: {
    NewHeader,
    RegisterComponent
  },
}
</script>

<style scoped>
</style>