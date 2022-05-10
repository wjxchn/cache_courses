package other;

import java.sql.*;
import javax.swing.JOptionPane;

public class DBset{
	private static String url="jdbc:sqlserver://localhost:1433;DatabaseName=java";
	/*
	 * java�����ݿ����ƣ����������޸Ļ��½���Ϊjava�����ݿ�
	 * �������ݱ��SQLset.sql�ļ�
	 * SQL�������ù���TCP��̬�˿�ֵ�޸�ΪΪ1433
	 * ���ӱ���SQL SERVER���ݿ�
	 */
	private static Connection con=null;
	private DBset(){
		try{
			if(con==null){
				Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
				con = DriverManager.getConnection(url, "sa", "wjxsqlserver");
				/*
				 * "sa"���û���
				 * "18373651"�Ǹ��û��������룬�������޸ĵ�¼����
				 */
			}
		}catch(Exception e){
			JOptionPane.showMessageDialog(null,"Error���޷������ݿ�");
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
			JOptionPane.showMessageDialog(null,"Error�����ݲ�ѯ����");
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
			JOptionPane.showMessageDialog(null,"Error�����ݸ���ʧ��");			
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
			JOptionPane.showMessageDialog(null,"Error��δ�����ݿ�");
		}
	}
}