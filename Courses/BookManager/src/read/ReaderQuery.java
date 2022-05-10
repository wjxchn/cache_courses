package read;

import java.awt.*;
import java.awt.event.*;
import java.sql.SQLException;
import java.sql.ResultSet;
import javax.swing.*;

import other.DBset;
public class ReaderQuery extends JFrame{
	public static void main(String[] args){
		new ReaderQuery();
	}
	//���߲��ҽ���
	Toolkit tool= getToolkit();
	String url="src/rselect.jpg";
	Image background=tool.getImage(url);
		public void paint(Graphics g){
		g.drawImage(background,0,0,this);
	}
	//����ͼƬ
	Label namelb=new Label("��������");
	Label typelb=new Label("��������");
	TextField nametxt=new TextField();
	TextField typetxt=new TextField();
	Button querybtn=new Button("��ѯ");
	Button closebtn=new Button("����");
	JTable table;
	JScrollPane scrollpane;
	String[] heads={"���߱��","��������","��������","�����Ա�","�ɽ�����","�ɽ�����"};
	Object[][] readertable=new Object[30][heads.length];
	public ReaderQuery(){
		setTitle("���߲�ѯ");
		setSize(700,400);
		setLayout(null);
		setResizable(false);
		
		namelb.setBounds(100,30,50,20);
		nametxt.setBounds(160,30,100,20);
		typelb.setBounds(280,30,50,20);
		typetxt.setBounds(340,30,100,20);
		querybtn.setBounds(500,30,50,20);
		closebtn.setBounds(600,30,50,20);
		add(namelb);add(nametxt);add(typelb);add(typetxt);add(querybtn);add(closebtn);
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				DBset.close();
				dispose();
			}
		});
		querybtn.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				 queryActionPerformed(e);
			}
		});
		closebtn.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
			  	DBset.close();
				dispose();
			}
		});

		setLocationRelativeTo(null);
		setVisible(true);
	}
	private void queryActionPerformed(ActionEvent e){
		readertable=new Object[30][heads.length];
		String readername=nametxt.getText(),readertype=typetxt.getText();
		String sql,sql1,sql2,sql3;
		if(readername.equals("")){
			sql1="";
		}else{
			sql1="readername like'"+readername+"%'";
		}
		if(readertype.equals("")){
			sql2="";
		}else{
			sql2="readertype like '"+readertype+"%'";
		}
		if(!readername.equals("")&&!readertype.equals("")){
			sql2="and "+sql2;
		}
		sql="select * from reader where ";
		sql3=sql1+sql2;
		if(!sql3.equals("")){
			sql=sql+sql3;
		}else{
			JOptionPane.showMessageDialog(null,"��������Ҫ��ѯ����Ϣ");
			return;
		}
		try{
			ResultSet rs=DBset.executeQuery(sql);
			String[] alloptions={"id","readername","readertype","sex","max_num","days_num"};
			int i=0;
			boolean rsnext=false;
			while(rs.next()){
				for(int j=0;j<alloptions.length;j++){
					readertable[i][j]=rs.getString(alloptions[j]);
				}
				i++;
				rsnext=true;
			}
			if(rsnext){
				table=new JTable(readertable,heads);
				scrollpane=new JScrollPane(table);
				scrollpane.setBounds(50,120,600,240);
				add(scrollpane);

				
			}else{
				JOptionPane.showMessageDialog(null,"û�в�ѯ���κ����������Ϣ");
			}
		}catch(SQLException se){
			JOptionPane.showMessageDialog(null,"�Ҳ�����Ҫ��ѯ����Ϣ");

		}
		
	}
	
}