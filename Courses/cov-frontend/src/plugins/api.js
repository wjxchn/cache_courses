import axios from 'axios'
import router from './router'

/* 使用axios响应拦截器拦截响应数据 */
axios.interceptors.response.use(success => {
    /* 业务错误：http的status是200，而服务端返回的data.status是500 */
    if (success.status && success.status == 200 && success.data.code == 400) {
        //Message.error({message: success.data.msg})
    }
    else if(success.status && success.status == 200 && success.data.code == 200){
        //Message.success({message: success.data.msg})
    }
    return success.data;
}, error => {
    console.log(error);
    if(error.response.status == 401){
        alert("登录失效，请重新登录")
        router.replace('/login');
    }
    else if (error.response.status == 504 || error.response.status == 404) {
        //Message.error({message: '服务器被吃了( ╯□╰ )'})
    } else if (error.response.status == 403) {
        //Message.error({message: '权限不足，请联系管理员'})
    } else if (error.response.status == 401) {
        //Message.error({message: '尚未登录，请登录'})
        router.replace('/');
    } else {
        if (error.response.data.msg) {
            //Message.error({message: error.response.data.msg})
        } else {
            //Message.error({message: '服务器内部出现问题'})
        }
    }
    return;
})

/* 请求的统一前缀 */
let base = 'vhr';

/* security登录默认key value，不支持json */
export const postKeyValueRequest = (url, params) => {
    return axios({
        method: 'post',
        url: `${base}${url}`,
        data: params,
        transformRequest: [function (data) {
            let ret = '';
            for (let i in data) {
                ret += encodeURIComponent(i) + '=' + encodeURIComponent(data[i]) + '&'
            }
            return ret;
        }],
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
        }
    });
}

/*export const postRequest = (url, params) => {
    return axios({
        method: 'post',
        url: `${base}${url}`,
        data: params
    })
}*/


export const postRequest = (url, params, headers) => {
    return axios({
        method: 'post',
        url: `${base}${url}`,
        data: params,
        headers:headers
        
    })
}

export const putRequest = (url, params) => {
    return axios({
        method: 'put',
        url: `${base}${url}`,
        data: params
    })
}

export const getRequest = (url, params) => {
    return axios({
        method: 'get',
        url: `${base}${url}`,
        params: params
    })
}

export const deleteRequest = (url, params) => {
    return axios({
        method: 'delete',
        url: `${base}${url}`,
        data: params
    })
}