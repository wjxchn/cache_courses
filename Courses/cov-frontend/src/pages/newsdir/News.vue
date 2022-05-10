<template>

  <div id="news">
    <NewHeader></NewHeader>
    <div class="row">
      <div class="col-12 mt-4">
        <h1 style="font-family: 'rr';text-align:center;">疫情新闻板块</h1>
      </div>
      <div class="col-12 mb-4">
        <p style="font-family: 'Times New Roman';text-align:center;">Present the News on COVID-19</p>
      </div>
    </div>
    <div class="row">
      <NewsComponent class="col-xl-8"></NewsComponent>
      <MessageComponent class="col-xl-4"></MessageComponent>
    </div>
    <FooterComponent></FooterComponent>
  </div>

 <!-- 第四个大需求，疫情相关新闻信息
 1 爬取网上疫情相关新闻，分至少三类展示：国内病例最新变化情况、各地防控措施、国家最新防控相关政策
 2 以时间轴形式展示官方发布的疫情公告 --> 
</template>

<script>
import NewHeader from '../../components/headerdir/NewHeader.vue'
import NewsComponent from '../../components/newsdir/NewsComponent.vue'
import FooterComponent from '../../components/footerdir/FooterComponent.vue'
import MessageComponent from '../..//components/messagedir/MessageComponent.vue'
export default {
  name: 'News',
  components: {
    NewHeader,
    NewsComponent,
    FooterComponent,
    MessageComponent
  },
}
</script>

<style scoped>
</style>

