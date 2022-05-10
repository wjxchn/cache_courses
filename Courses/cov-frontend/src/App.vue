<template>
  <div id="app" style="background-color: #ffffff;">
    <router-view></router-view>
    <el-backtop :visibility-height="height"></el-backtop>
  </div>
</template>

<script>

export default {
  name: 'App',
  data(){
    return{
      height: 500
    }
  },
  mounted() {
  }
}
</script>

<style>

</style>
