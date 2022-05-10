package main;

import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import javax.swing.JOptionPane;

import other.DBset;
import other.Login_user;

public class Login extends Frame{//登录开始页面
	public static void main(String[] args){
		new Login();
	}
	//登录界面
	Toolkit tool= getToolkit();
	String url="src/login.png";
	Image background=tool.getImage(url);
		public void paint(Graphics g){
		g.drawImage(background,0,0,this);
	}
	//背景图片
	TextField text_user,text_pass;
	public Login(){
		this.setTitle("欢迎使用图书管理系统");//标题
		this.setLayout(null);
		this.setSize(300,300);
		setResizable(false);
		Label userlb=new Label("用户名:");//用户名标签
		Label passlb=new Label("密   码:");//密码标签
		Button login=new Button("登录");//登录按钮
		Button quit=new Button("退出");//退出按钮
		text_user=new TextField();//用户名输入框
		text_pass=new TextField();//密码输入框
		text_pass.setEchoChar('●');//保护密码
		userlb.setBounds(30,100,70,20);
		passlb.setBounds(30,150,70,20);
		text_user.setBounds(110,100,120,20);
		text_pass.setBounds(110,150,120,20);
		login.setBounds(30,250,80,25);
		quit.setBounds(180,250,80,25);
		this.add(userlb);
		this.add(passlb);
		this.add(text_user);
		this.add(text_pass);
		this.add(login);
		this.add(quit);
		login.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				sureActionListener(e);
				
			}
		});
		quit.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				DBset.close();
				dispose();

			}
		});
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				DBset.close();
				dispose();
			}
		});
		this.setLocationRelativeTo(null);
		this.setVisible(true);
	}
	public void sureActionListener(ActionEvent le){
		String user=text_user.getText();
		String pass=text_pass.getText();
		String is_admin="";
		if(user.equals("")){
			JOptionPane.showMessageDialog(null,"用户名不能为空，请输入用户名");
			return;
		}
		else if(pass.equals("")){
			JOptionPane.showMessageDialog(null,"密码不能为空，请输入密码");
			return;
		}
		try{
			String sql="select * from uuser where username="+"'"+user+"'"+"and password="+"'"+pass+"'";
			ResultSet rs=DBset.executeQuery(sql);
				if(rs.next()){
					is_admin=rs.getString("is_admin");
				}else{
					JOptionPane.showMessageDialog(null,"用户名或者密码不正确，请重新输入 ");
					return;
				}
			Login_user.login_user=user;
			Main show=new Main();
			JOptionPane.showMessageDialog(null,"登录成功");
			dispose();
		}catch(SQLException e){
			JOptionPane.showMessageDialog(null,"Error");
		}
	}
}