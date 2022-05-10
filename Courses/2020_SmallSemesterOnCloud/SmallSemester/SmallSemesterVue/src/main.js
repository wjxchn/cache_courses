// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'
import 'bootstrap'
import $ from 'jquery'
//import './mock/index.js'

Vue.config.productionTip = false

import VueQuillEditor from 'vue-quill-editor'
import 'quill/dist/quill.core.css'
import 'quill/dist/quill.snow.css'
import 'quill/dist/quill.bubble.css'
Vue.use(VueQuillEditor);

import Element from 'element-ui'
import 'element-ui/lib/theme-chalk/index.css';
Vue.use(Element)

import verify from "vue-verify-plugin";





var myRules={
  agecheck:{
    test:function(val){
      if(!/^\d+$/.test(val)){
        return false
      }
      if(val<0) {
          return false
      }
      if(val>140){
          return false
      }
      return true;          
    },
    message:"年龄范围为[0,140]且为整数"
  }
};
Vue.use(verify,{
  blur:true,
  rules:myRules
});


router.beforeEach((to, from, next)=>{
  if(to.meta.title){
    document.title = to.meta.title
  }
  next()
})

/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  components: { App },
  template: '<App/>'
})
