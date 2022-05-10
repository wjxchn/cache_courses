<template>
  <div>
    <p id="status"></p>
    <p id="result"></p>
    <p id="area"></p>
    <div id="mapdiv" ></div>
  </div>
</template>

<script>
export default {
  name: 'LocationComponent',
  mounted(){
    var that = this;
    var map = new AMap.Map('mapdiv', {
    });
    AMap.plugin('AMap.Geolocation', function() {
        var geolocation = new AMap.Geolocation();
        geolocation.getCurrentPosition(function(status,result){
            if(status=='complete'){
                onComplete(result)
            }else{
                onError(result)
            }
        });
    });
    //解析定位结果
    function onComplete(data) {
        console.log(data.position.lng);
        document.getElementById('status').innerHTML='定位成功'
        var str = [];
        str.push('定位结果：' + data.position);
        str.push('定位类别：' + data.location_type);
        if(data.accuracy){
             str.push('精度：' + data.accuracy + ' 米');
        }//如为IP精确定位结果则没有精度信息
        str.push('是否经过偏移：' + (data.isConverted ? '是' : '否'));
        document.getElementById('result').innerHTML = str.join('<br>');
        that.$axios({
          method:'get',
          url:'https://restapi.amap.com/v3/geocode/regeo',
          params:{
            location: data.position.lng+','+data.position.lat,
            key: 'd05ecc16db2af3450e049076b7359134'
          }
        }).then(res=>{
          console.log(res);
          console.log(res.regeocode.addressComponent.country);
          console.log(res.regeocode.addressComponent.province);
          console.log(res.regeocode.addressComponent.district);
          document.getElementById('area').innerHTML = "您所在的区域是："+res.regeocode.addressComponent.country+res.regeocode.addressComponent.province+res.regeocode.addressComponent.district
        }).catch(err=>{
          console.log(err);
        })
    }
    //解析定位错误信息
    function onError(data) {
        document.getElementById('status').innerHTML='定位失败'
        document.getElementById('result').innerHTML = '失败原因排查信息:'+data.message;
    }
  }
}
</script>

<style>

</style>