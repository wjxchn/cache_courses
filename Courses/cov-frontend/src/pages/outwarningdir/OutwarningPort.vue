<template>
  <div class="outwarning">
    <New-header></New-header>
    <OutwarningPortComponent></OutwarningPortComponent>
    <FooterComponent></FooterComponent>
  </div>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import OutwarningPortComponent from '../../components/outwarningdir/OutwarningPortComponent.vue'
import FooterComponent from '../../components/footerdir/FooterComponent.vue'
export default {
  name:'Outwarning',
  components:{
    NewHeader,
    OutwarningPortComponent,
    FooterComponent
  },
}
</script>