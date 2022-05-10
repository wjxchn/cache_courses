<template>
    <div>
        <Guider id="navBar" :class="{isFixed:istabBar}"/>
        <el-container>
            <el-aside class="leftside" width="210px">

            <!--     ↓↓↓↓↓↓↓↓↓↓↓↓↓↓  这个default-active是指当前激活的页面，把页面对应的index写进去，例如：当前页面是我的文档，则写进去2-1 -->
            <el-menu default-active="3-1" class="el-menu-vertical-demo" :default-openeds="opend"
            @open="handleOpen" @close="handleClose" background-color="#fff"
            text-color="#000000" active-text-color="#f96332" >
            <el-submenu index="1">
                <template slot="title">
                    <i class="el-icon-menu"></i>
                    <span>工作台</span>
                </template>
                    <el-menu-item index="1-1" @click="Mywork" :loading="logining"><i class="el-icon-notebook-2" style="color:black"></i>我的文档</el-menu-item>
                    <el-menu-item index="1-2" @click="Myteam" :loading="logining"><i class="el-icon-set-up" style="color:black"></i>我的团队</el-menu-item>
                    <el-menu-item index="1-3" @click="MyFavorite" :loading="logining"><i class="el-icon-star-off" style="color:black"></i>我的收藏</el-menu-item>
                    <el-menu-item index="1-4" @click="Trash" :loading="logining"><i class="el-icon-delete" style="color:black"></i>回收站</el-menu-item>
                    <el-menu-item index="1-5" @click="Message" :loading="logining"><i class="el-icon-chat-dot-round" style="color:black"></i>收件箱</el-menu-item>
            </el-submenu>
            <el-submenu index="2">
                <template slot="title">
                    <i class="el-icon-s-home"></i>
                    <span>个人信息</span>
                </template>
                    <el-menu-item index="2-1" @click="Person" :loading="logining"><i class="el-icon-user" style="color:black"></i>个人资料</el-menu-item>
            </el-submenu>
            <el-submenu index="3">
                <template slot="title">
                    <i class="el-icon-s-opportunity"></i>
                    <span>其他</span>
                </template>
                    <el-menu-item index="3-1" @click="Help" :loading="logining"><i class="el-icon-view" style="color:black"></i>帮助</el-menu-item>
                    <el-menu-item index="3-2" @click="Aboutus" :loading="logining"><i class="el-icon-link" style="color:black"></i>开发者信息</el-menu-item>
            </el-submenu>
            </el-menu>
            </el-aside>
        <el-container>
        <main id="mainPart" role="main" class="container">

    <!-- 页面内部的内容写在main中间即可 -->
        <div >
                <p style="font-size:30px;margin-top:20px"><b>帮助中心</b></p>
            <div>
                <el-collapse v-model="activeNames" @change="handleChange">
                    <el-collapse-item title="哪些浏览器可以使用福报文档？" name="1">
                        <div>Chrome、Firefox、Safari、IE10以上，以及其他以Webkit为内核的浏览器（如：360安全/极速浏览器，QQ浏览器，搜狗浏览器等等）。

我们推荐您优先使用 最新稳定版 Chrome 浏览器。
</div>
                    </el-collapse-item>
                    <el-collapse-item title="福报最多支持多少人同时编辑一个文档？" name="2">
                        <div>1个。当有人正在编辑文档时，福报文档会禁止其他人编辑文档，等候文档无人编辑时方可编辑。</div>
                    </el-collapse-item>
                    <el-collapse-item title="福报有iOS和Android客户端吗？" name="3">
                        <div>不好意思，没有。福报目前仅支持桌面端web.</div>
                    </el-collapse-item>
                    <el-collapse-item title="如何新建福报个人doc文档？" name="4">
                        <div>在工作台-我的文档 界面右上角【新建】,即可通过模板创建文档。</div>
                    </el-collapse-item>
                    <el-collapse-item title="如何新建福报团队doc文档？" name="5">
                        <div>在工作台-我的团队 进入团队页面后 界面右上角【新建】,即可创建文档。</div>
                    </el-collapse-item>
                    <el-collapse-item title="误删的文件如何恢复？" name="6">
                        <div>在工作台-回收站 即可找到误删的文件并恢复。</div>
                    </el-collapse-item>
                    <el-collapse-item title="网站不好使了怎么办？" name="7">
                        <div>在开发者信息中，找到我们的开发人员邮箱并投递邮件，即可联系开发人员修复Bug。</div>
                    </el-collapse-item>
                </el-collapse>
            </div>
        </div>
        </main>
        </el-container>
        </el-container>
        <BottomGuider/>
    </div>
</template>

<script>
import Guider from '../components/Guider'
import BottomGuider from '../components/BottomGuider'
export default {
    name: 'PageDemo',
    components: {
        Guider,
        BottomGuider
    },
    data () {
        return {
            opend:['1','2','3'],
            uniqueOpened:false,
            istabBar: false
        }
    },
    methods: {
        //侧边栏的跳转
        handleOpen(key, keyPath) {
            console.log(key, keyPath);
        },
        handleClose(key, keyPath) {
            console.log(key, keyPath);
        },
        Person(){
            this.$router.push('/Person');
        },
        Mywork(){
            this.$router.push('/Personaldoc');
        },
        Myteam(){
            this.$router.push('/Team');
        },
        MyFavorite(){
            this.$router.push('/MyFavoriteDoc');
        },
        TeamM(){
            this.$router.push('/TeamManagement');
        },
        Trash(){
            this.$router.push('/Trash');
        },
        Message(){
            this.$router.push('/Message');
        },
        Help(){
            this.$router.push('/Help');
        },
        Aboutus(){
            this.$router.push('/Aboutus');
        },
        // 添加一个方法 兼容
        handleScroll () {
            let scrollTop = window.pageYOffset || document.documentElement.scrollTop || document.body.scrollTop;
                    
                // 固定导航栏
                let navBar = document.querySelector("#navBar");
                let mainPart = document.querySelector("#mainPart");
                if (scrollTop > 0){
                    this.istabBar = true
                    mainPart.style.paddingTop = navBar.offsetHeight + "px";
                } else {
                    this.istabBar = false
                    mainPart.style.paddingTop = "0px";
                }
        }
    },
    mounted () {
        window.addEventListener('scroll', this.handleScroll); // Dom树加载完毕
    },
    destroyed () {
        window.removeEventListener('scroll', this.handleScroll) // 销毁页面时清除
    }
}
</script>

<style scoped>
.isFixed {
    position: fixed;
    top: 0;
    z-index: 10;
}
#navBar {
    width: 100%;
    background-color: #f96332;
    backdrop-filter: blur(30px);
}
#mainPart {
    width: 100%;
}

</style>
