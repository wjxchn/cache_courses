<template>
  <div id="message">
    <NewHeader></NewHeader>
    <div class="row discussiontitle">
      <div class="col-12 mt-4">
        <h1 style="font-family: 'rr';text-align:center;">防控知识交流区</h1>
      </div>
      <div class="col-12">
        <p style="font-family: 'Times New Roman';text-align:center;">Present the Discussion about the Information on COVID-19</p>
      </div>
    </div>
    <div class="row">
      <DiscussionDetailComponent class="col-xl-8"></DiscussionDetailComponent>
      <MessageComponent class="col-xl-4"></MessageComponent>
    </div>
    <FooterComponent></FooterComponent>
  </div>
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import DiscussionDetailComponent from '../../components/messagedir/DiscussionDetailComponent.vue'
import FooterComponent from '../../components/footerdir/FooterComponent.vue'
import MessageComponent from '../../components/messagedir/MessageComponent.vue'
export default {
  name: 'DiscussionDetail',
  components: {
    NewHeader,
    DiscussionDetailComponent,
    FooterComponent,
    MessageComponent,
  },
}
</script>

<style scoped>
</style>