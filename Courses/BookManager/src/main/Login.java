package main;

import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import javax.swing.JOptionPane;

import other.DBset;
import other.Login_user;

public class Login extends Frame{//��¼��ʼҳ��
	public static void main(String[] args){
		new Login();
	}
	//��¼����
	Toolkit tool= getToolkit();
	String url="src/login.png";
	Image background=tool.getImage(url);
		public void paint(Graphics g){
		g.drawImage(background,0,0,this);
	}
	//����ͼƬ
	TextField text_user,text_pass;
	public Login(){
		this.setTitle("��ӭʹ��ͼ�����ϵͳ");//����
		this.setLayout(null);
		this.setSize(300,300);
		setResizable(false);
		Label userlb=new Label("�û���:");//�û�����ǩ
		Label passlb=new Label("��   ��:");//�����ǩ
		Button login=new Button("��¼");//��¼��ť
		Button quit=new Button("�˳�");//�˳���ť
		text_user=new TextField();//�û��������
		text_pass=new TextField();//���������
		text_pass.setEchoChar('��');//��������
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
			JOptionPane.showMessageDialog(null,"�û�������Ϊ�գ��������û���");
			return;
		}
		else if(pass.equals("")){
			JOptionPane.showMessageDialog(null,"���벻��Ϊ�գ�����������");
			return;
		}
		try{
			String sql="select * from uuser where username="+"'"+user+"'"+"and password="+"'"+pass+"'";
			ResultSet rs=DBset.executeQuery(sql);
				if(rs.next()){
					is_admin=rs.getString("is_admin");
				}else{
					JOptionPane.showMessageDialog(null,"�û����������벻��ȷ������������ ");
					return;
				}
			Login_user.login_user=user;
			Main show=new Main();
			JOptionPane.showMessageDialog(null,"��¼�ɹ�");
			dispose();
		}catch(SQLException e){
			JOptionPane.showMessageDialog(null,"Error");
		}
	}
}