import Vue from 'vue'
import VueRouter from 'vue-router'

Vue.use(VueRouter)

// 这里面负责写路由映射，便于管理
// 创建路由实例并配置路由映射
// path:'*',redirect:'/home'  重定向到path是/home的映射 */
const router = new VueRouter({
  routes: [
    //主页
    {
      path: '/',
      components: require('../pages/homedir/Home.vue')
    },

    //以下是persondir用户相关部分
    {
      path: '/register',
      components: require('../pages/persondir/Register.vue')
    },
    {
      path: '/login',
      components: require('../pages/persondir/Login.vue')
    },
    {
      path: '/findpassword',
      components: require('../pages/persondir/Findpassword.vue')
    },
    {
      path: '/person',
      components: require('../pages/persondir/Person.vue')
    },
    {
      path: '/editpassword',
      components:require('../pages/persondir/Editpassword.vue')
    },
    {
      path: '/editperson',
      components: require('../pages/persondir/Editperson.vue')
    },

    //forecastdir
    {
      path: '/forecast',
      components: require('../pages/forecastdir/Forecast.vue')
    },

    //outwarningdir
    {
      path: '/outwarning',
      components: require('../pages/outwarningdir/Outwarning.vue')
    },
    {
      path: '/outwarningworld',
      components: require('../pages/outwarningdir/OutwarningWorld.vue')
    },
    {
      path: '/outwarningport',
      components: require('../pages/outwarningdir/OutwarningPort.vue')
    },

    //provincedir
    {
      path: '/province',
      components:require('../pages/provincedir/Province')
    },

    //worlddir
    {
      path: '/world',
      components:require('../pages/worlddir/World')
    },

    //messagedir
    {
      path: '/message/messagedetail',
      components: require('../pages/message/MessageDetail.vue')
    },
    {
      path: '/discussion',
      components: require('../pages/message/Discussion.vue')
    },
    {
      path: '/discussion/discussiondetail',
      components: require('../pages/message/DiscussionDetail.vue')
    },
    
    //news
    {
      path:'/news',
      components: require('../pages/newsdir/News.vue')
    },

    //location
    {
      path:'/locationcomponent',
      components: require('../components/mapdir/LocationComponent.vue')
    },

    //这两个必须放最后
    {
      path: '/404',
      components: require('../pages/404dir/404.vue')
    },
    {
      path: '*',
      components: require('../pages/404dir/404.vue')
    },
  ]
})
// 不存在的页面跳转到404页面
router.beforeEach((to, from, next) => {
  console.log('to.matched.length', to.matched.length)
  if (to.matched.length === 0) { // 如果未匹配到路由
    from.name ? next({ name: from.name }) : next('/404') // 如果上级也未匹配到路由则跳转登录页面，如果上级能匹配到则转上级路由
  } else {
    next() // 如果匹配到正确跳转
  }
})
export default router