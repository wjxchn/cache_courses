## 1.关于连接本地SQL sever的配置

#### ①：

首先需要修改DBset.java中“数据库名称”，“登录名”和“密码”用来连接本地的SQL SERVER数据库。

（确保SQL SERVER开启了身份验证，即可以通过登录名和密码连接SQL SERVER）

#### ②：

在SQL网络配置中进入TCP/IP协议把TCP动态端口值修改为1433，并把其他IP设置为开启。

#### ③：

使用修改后的登录名登录SQL SERVER并执行SQLset.SQL文件，在第①步修改的数据库中创建表“book”、“reader”、“uuser”、“borrow”。

#### ④：

在java构建路径中添加外部包 sqljdbc4.jar(位于lib文件下的sqljdbc4.jar包)，否则将无法连接SQL SEVER。

相关配置文档：https://blog.csdn.net/u012393192/article/details/76152458；

## 2.关于项目在IDE中运行的相关事项

#### ①：

在Login.java文件运行，默认登录管理员为：“admin”，密码“123456”，（可以自行在SQLset.SQL中添加管理员信息）。

#### ②：

在Main.java文件运行，跳过管理员登录页面，直接进入图书管理系统主页面。

#### ③：

在其他文件（BookAdd.java、BookDelete.java、BookQuery.java、BookUpdate.java、Borrow.java、ReaderAdd.java、ReaderDelete.java、ReaderQuery.java、ReaderUpdate.java)运行，跳过登录界面和主界面直接进入相应的界面。