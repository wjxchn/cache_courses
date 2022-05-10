<template>
    <div class="container">
        <div class="row">
          <div class="col-12  mt-4">
            <h2 style="font-family: 'rr'">{{question.title}}</h2>
          </div>
          <div class="col-12">
            <p style="font-family: 'rr'">{{question.content}}</p>
          </div>
          <div class="col-12  mb-4">
            <button class="btn btn-outline-success" type="button" style="width:100px;" data-bs-toggle="modal" data-bs-target="#comment" >评论问题</button>
            <div class="modal fade" id="comment" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
              <div class="modal-dialog">
                <div class="modal-content">
                  <div class="modal-header">
                    <h5 class="modal-title" id="exampleModalLabel">评论当前问题</h5>
                    <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                  </div>
                  <div class="modal-body">
                    <form>
                      <div class="mb-3">
                        <label for="msesage-text" class="col-form-label">我的评论:</label>
                        <textarea class="form-control" v-model="my_comment"></textarea>
                      </div>
                    </form>
                  </div>
                  <div class="modal-footer">
                    <button class="btn btn-outline-success" @click="publishcomment" data-bs-dismiss="modal">发布评论</button>
                    <button type="button" class="btn btn-secondary" data-bs-dismiss="modal">取消</button>
                  </div>
                </div>
              </div>
            </div>
          </div>
          <div class="col-12">
            <h4 class="card-title" style="font-size: 25px;font-family: 'rr';font-weight: bold">问题讨论区</h4>
          </div>
          <div class="col-lg-8">
            <h6 class="card-title" style="font-size: 20px;font-family: 'rr';font-weight: bold">普通用户讨论</h6>
            <div v-for="(item,i) in comments" :value="i" v-bind:key="i">
              <div class="container card" >
                <div class="row">
                  <div class="col-md-2">
                    <img :src="item.img" alt="user" width="50" class="rounded-circle">
                  </div>
                  <div class="col-md-2" style="font-family: rr;font-size: 20px;padding-top: 0.5vw">
                    {{item.name}}
                  </div>
                </div>
                <div style="font-family: rr;font-size: 20px;padding-top: 0.5vw">
                  {{item.time}}
                </div>                
              </div>

              <!-- 问题主体 -->
              <div>
                <div class="comment-text w-100" style="font-family: rr;font-size: 20px;">
                  {{item.content}}                        
                </div>
              </div>
            </div>
          </div>
          <div class="col-lg-4">
            <h6 class="card-title" style="font-size: 20px;font-family: 'rr';font-weight: bold">专家讨论</h6>
            <div v-for="(item,i) in expertcomments" :value="i" v-bind:key="i">
              <div class="container card" >
                <div class="row">
                  <div class="col-md-2">
                    <img :src="item.img" alt="user" width="50" class="rounded-circle">
                  </div>
                  <div class="col-md-10" style="font-family: rr;font-size: 20px;padding-top: 0.5vw">
                    {{item.name}}
                    <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-award-fill" viewBox="0 0 16 16">
                      <path d="m8 0 1.669.864 1.858.282.842 1.68 1.337 1.32L13.4 6l.306 1.854-1.337 1.32-.842 1.68-1.858.282L8 12l-1.669-.864-1.858-.282-.842-1.68-1.337-1.32L2.6 6l-.306-1.854 1.337-1.32.842-1.68L6.331.864 8 0z"/>
                      <path d="M4 11.794V16l4-1 4 1v-4.206l-2.018.306L8 13.126 6.018 12.1 4 11.794z"/>
                    </svg>
                  </div>
                </div>
              </div>
              <!-- 问题主体 -->
              <div>
                <div class="comment-text w-100" style="font-family: rr;font-size: 20px;">
                  {{item.content}}                        
                </div>
              </div>
            </div>            
          </div>
        </div>
      </div>
</template>

<script>
export default {

}
</script>

<style>

</style>