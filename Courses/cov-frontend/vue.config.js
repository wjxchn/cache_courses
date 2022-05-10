let proxyObj = {};

proxyObj['/vhr'] = {
    ws: false,
    target: 'http://localhost:8888', //目标转发地址
    changeOrigin: true,
    pathRewrite: {
        '^/vhr': ''
    }
};

module.exports = {
    devServer: {
        host: 'localhost',
        port: 8080,
        proxy: proxyObj
    }
};