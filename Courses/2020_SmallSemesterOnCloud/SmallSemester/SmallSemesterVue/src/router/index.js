import Vue from 'vue'
import Router from 'vue-router'

const routerOptions = [
  { path: '/', component: 'Firstpage', meta: {title: '福报文档'}},//主页
  { path: '/aboutus' , component: 'Aboutus', meta: {title: '福报文档'} },//开发者信息页面
  { path: '/addgroupdocfromdemo' , component: 'AddGroupDocFromDemo', meta: {title: '福报文档'} },//开发者信息页面
  { path: '/animation', component: 'Animation', meta: {title: '福报文档'} },//封面（暂时弃置）
  { path: '/article', component: 'Article', meta: {title: '福报文档'} },//文章（暂时弃置）
  { path: '/bottomguider', component: 'BottomGuider', meta: {title: '福报文档'} },//底边栏挂件
  { path: '/carousel', component: 'Carousel', meta: {title: '福报文档'} },//封面（暂时弃置）
  { path: '/createfromdemo', component: 'CreateFromDemo', meta: {title: '福报文档'} },//使用模板创建文档页面
  { path: '/createteam', component: 'CreateTeam', meta: {title: '福报文档'} },//创建团队页面
  { path: '/docform', component:'DocForm', meta: {title: '福报文档'} },//文档模板
  { path: '/groupdocform', component:'GroupDocForm', meta: {title: '福报文档'} },//文档模板
  { path: '/editgroupdoc', component: 'EditGroupDoc', meta: {title: '福报文档'} },//编辑团队文档页面
  { path: '/editperson' , component: 'EditPerson', meta: {title: '福报文档'} },//编辑个人资料页面
  { path: '/editpersonaldoc', component: 'EditPersonalDoc', meta: {title: '福报文档'} },//编辑个人文档页面
  { path: '/firstpage' , component: 'Firstpage', meta: {title: '福报文档'}},//首页
  { path: '/findpassword' , component: 'Findpassword', meta: {title: '福报文档'} },//找回密码页面
  { path: '/guider', component: 'Guider', meta: {title: '福报文档'} },//顶栏挂件
  { path: '/help' , component: 'Help', meta: {title: '福报文档'}},//帮助手册页面
  { path: '/login', component: 'Login', meta: {title: '福报文档'} },//登录页面
  { path: '/message' , component: 'Message', meta: {title: '福报文档'} },//站内信息页面
  { path: '/myfavoritedoc' , component: 'MyFavoriteDoc', meta: {title: '福报文档'} },//我的收藏页面
  { path: '/newgroupdoc' , component: 'NewGroupdoc', meta: {title: '福报文档'} },//新建团队文档页面 
  { path: '/pagedemo', component: 'PageDemo', meta: {title: '福报文档'} },//页面模板（顶、侧、底栏）
  { path: '/person' , component: 'Person', meta: {title: '福报文档'} },//个人资料页面
  { path: '/personaldoc', component:'PersonalDoc', meta: {title: '福报文档'} },//个人文档页面
  { path: '/plaintext_new', component:'PlainText_new', meta: {title: '福报文档'} },//创建新文档页面
  { path: '/regi', component: 'Regi', meta: {title: '福报文档'} },//注册页面
  { path: '/showplaintext_new', component:'ShowPlainText_new', meta: {title: '福报文档'} },//查看个人文档页面
  { path: '/team', component:'Team', meta: {title: '福报文档'} },//我的团队页面
  { path: '/teammanagement', component:'TeamManagement', meta: {title: '福报文档'} },//团队管理页面
  { path: '/trash' , component: 'Trash', meta: {title: '福报文档'} },//回收站页面
  { path: '/userinfo', component:'UserInfo', meta: {title: '福报文档'} },//文档模板
  { path: '*', component: 'NotFound', meta: {title: '福报文档'} },
]
const routes = routerOptions.map(route => {
  return {
    ...route,
    component: () => import(`@/components/${route.component}.vue`)
  }
})

Vue.use(Router)

export default new Router({
  routes,
  mode: 'history'
})
