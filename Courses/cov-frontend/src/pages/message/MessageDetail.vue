<template>
  <div id="message">
    <NewHeader></NewHeader>
    <div class="row">
      <div class="col-12 mt-4">
        <h1 style="font-family: 'rr';text-align:center;">防控知识详情</h1>
      </div>
      <div class="col-12">
        <p style="font-family: 'Times New Roman';text-align:center;">Present the Detailed Information on COVID-19</p>
      </div>
    </div>
    <div class="row">
      <MessageDetailComponent class="col-xl-9"></MessageDetailComponent>
      <MessageComponent class="col-xl-3"></MessageComponent>
    </div>
    <FooterComponent></FooterComponent>
  </div>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import MessageDetailComponent from '../../components/messagedir/MessageDetailComponent.vue'
import FooterComponent from '../../components/footerdir/FooterComponent.vue'
import MessageComponent from '../../components/messagedir/MessageComponent.vue'
export default {
  name: 'MessageDetail',
  components: {
    NewHeader,
    MessageDetailComponent,
    FooterComponent,
    MessageComponent
  },
}
</script>

<style scoped>
</style>