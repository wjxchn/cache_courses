<template>
  <div class="outwarning">
    <New-header></New-header>
    <OutwarningWorldComponent></OutwarningWorldComponent>
    <FooterComponent></FooterComponent>
  </div>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import OutwarningWorldComponent from '../../components/outwarningdir/OutwarningWorldComponent.vue'
import FooterComponent from '../../components/footerdir/FooterComponent.vue'
export default {
  name:'Outwarning',
  components:{
    NewHeader,
    OutwarningWorldComponent,
    FooterComponent
  },
}
</script>