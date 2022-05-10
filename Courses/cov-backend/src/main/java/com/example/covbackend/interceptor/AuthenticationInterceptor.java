package com.example.covbackend.interceptor;

import com.auth0.jwt.*;
import com.auth0.jwt.JWTVerifier;
import com.auth0.jwt.algorithms.Algorithm;
import com.auth0.jwt.exceptions.JWTDecodeException;
import com.auth0.jwt.exceptions.JWTVerificationException;
import com.example.covbackend.annotations.PassToken;
import com.example.covbackend.annotations.UserLoginToken;
import com.example.covbackend.entity.User;
import com.example.covbackend.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.method.HandlerMethod;
import org.springframework.web.servlet.HandlerInterceptor;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.*;
import java.lang.reflect.Method;


public class AuthenticationInterceptor implements HandlerInterceptor {
    @Autowired
    UserService userService;
    @Override
    public boolean preHandle(HttpServletRequest httpServletRequest, HttpServletResponse httpServletResponse, Object object) throws Exception {
        String token = httpServletRequest.getHeader("token");// 从 http 请求头中取出 token
        // 如果不是映射到方法直接通过
        if(!(object instanceof HandlerMethod)){
            return true;
        }
        HandlerMethod handlerMethod=(HandlerMethod)object;
        Method method=handlerMethod.getMethod();
        //检查是否有passtoken注释，有则跳过认证
        if (method.isAnnotationPresent(PassToken.class)) {
            PassToken passToken = method.getAnnotation(PassToken.class);
            if (passToken.required()) {
                return true;
            }
        }
        //检查有没有需要用户权限的注解
        if (method.isAnnotationPresent(UserLoginToken.class)) {
            UserLoginToken userLoginToken = method.getAnnotation(UserLoginToken.class);
            if (userLoginToken.required()) {
                // 执行认证
                if (token == null) {
                    httpServletResponse.sendError(HttpServletResponse.SC_UNAUTHORIZED);
                    return false;
                }
                // 获取 token 中的 user id
                String userId = null;
                try {
                    userId = JWT.decode(token).getAudience().get(0);
                } catch (JWTDecodeException j) {
                    System.out.println("走到这里了吗");
                    Cookie cookie = new Cookie("token", "过期");
                    //将cookie设置在根目录下面
                    cookie.setPath("/");
                    //设置cookie的有效期，单位是秒(一年)
                    //如果这个maxage不设置的话，cookie就不会写入硬盘，而是写在内存。只在当前页面有效。
                    cookie.setMaxAge(0);
                    System.out.println("cookie完成设置");
                    httpServletResponse.addCookie(cookie);
                    System.out.println(httpServletResponse);
                    httpServletResponse.sendError(HttpServletResponse.SC_UNAUTHORIZED);
                    return false;
                    //throw new RuntimeException(j);
                }
                User user = null;
                try{
                    user = userService.getById(Integer.parseInt(userId));
                }
                catch(Exception e){
                    httpServletResponse.sendError(HttpServletResponse.SC_UNAUTHORIZED);
                    return false;
                }
                if (user == null) {
                    //throw new RuntimeException("用户不存在，请重新登录");
                    httpServletResponse.sendError(HttpServletResponse.SC_UNAUTHORIZED);
                    return false;
                }
                // 验证 token
                JWTVerifier jwtVerifier = JWT.require(Algorithm.HMAC256(user.getPassword())).build();
                try {
                    jwtVerifier.verify(token);
                } catch (JWTVerificationException e) {
                    Cookie cookie = new Cookie("token", "过期");
                    //将cookie设置在根目录下面
                    cookie.setPath("/");
                    //设置cookie的有效期，单位是秒(一年)
                    //如果这个maxage不设置的话，cookie就不会写入硬盘，而是写在内存。只在当前页面有效。
                    cookie.setMaxAge(0);
                    System.out.println("cookie完成设置");
                    httpServletResponse.addCookie(cookie);
                    httpServletResponse.sendError(HttpServletResponse.SC_UNAUTHORIZED);
                    return false;
                    //throw new RuntimeException(e);
                }
                return true;
            }
        }
        return true;
    }

    @Override
    public void postHandle(HttpServletRequest httpServletRequest, HttpServletResponse httpServletResponse, Object o, ModelAndView modelAndView) throws Exception {

    }
    @Override
    public void afterCompletion(HttpServletRequest httpServletRequest, HttpServletResponse httpServletResponse, Object o, Exception e) throws Exception {

    }
}
