<template>
  <div id="register">
    <NewHeader></NewHeader>
    <LoginComponent></LoginComponent>
  </div>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import LoginComponent from '../../components/persondir/LoginComponent.vue'
export default {
  name: 'Login',
  components: {
    NewHeader,
    LoginComponent
  },
}
</script>

<style scoped>
</style>