<template>
  <div class="outwarning">
    <New-header></New-header>
    <OutwarningComponent></OutwarningComponent>
    <FooterComponent></FooterComponent>
  </div>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import OutwarningComponent from '../../components/outwarningdir/OutwarningComponent.vue'
import FooterComponent from '../../components/footerdir/FooterComponent.vue'
export default {
  name:'Outwarning',
  components:{
    NewHeader,
    OutwarningComponent,
    FooterComponent
  },
}
</script>