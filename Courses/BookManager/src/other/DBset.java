package other;

import java.sql.*;
import javax.swing.JOptionPane;

public class DBset{
	private static String url="jdbc:sqlserver://localhost:1433;DatabaseName=java";
	/*
	 * java是数据库名称，可以自行修改或新建名为java的数据库
	 * 创建数据表见SQLset.sql文件
	 * SQL网络配置管理TCP动态端口值修改为为1433
	 * 连接本地SQL SERVER数据库
	 */
	private static Connection con=null;
	private DBset(){
		try{
			if(con==null){
				Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
				con = DriverManager.getConnection(url, "sa", "wjxsqlserver");
				/*
				 * "sa"是用户名
				 * "18373651"是该用户名的密码，请自行修改登录密码
				 */
			}
		}catch(Exception e){
			JOptionPane.showMessageDialog(null,"Error：无法打开数据库");
			System.out.println(e.getMessage());
		}
	}
	public static ResultSet executeQuery(String sql){
		ResultSet rs=null;
		try{
			if(con==null){
				new DBset();
			}
			rs=con.createStatement().executeQuery(sql);
		}catch(SQLException e){
			JOptionPane.showMessageDialog(null,"Error：数据查询错误");
			rs=null;
		}
		return rs;
	}
	public static int executeUpdate(String sql){
		int a=0;
		try{
			if(con==null){
				new DBset();
			}
			a= con.createStatement().executeUpdate(sql);
		}catch(SQLException e){
			JOptionPane.showMessageDialog(null,"Error：数据更新失败");			
			a=-1;
		}
		return a;
	}
	public static void close(){
		try{
			if(con!=null){
				con.close();
				con=null;
			}
		}catch(SQLException e){
			JOptionPane.showMessageDialog(null,"Error：未打开数据库");
		}
	}
}