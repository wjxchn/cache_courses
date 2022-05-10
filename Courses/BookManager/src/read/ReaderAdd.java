package read;
import java.awt.*;
import java.awt.event.*;
import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.JOptionPane;

import other.DBset;

public class ReaderAdd extends Frame{
	public static void main(String[] args){
		new ReaderAdd();
	}
	//��Ӷ��߽���
	Toolkit tool= getToolkit();
	String url="src/reader.jpg";
	Image background=tool.getImage(url);
		public void paint(Graphics g){
		g.drawImage(background,0,0,this);
	}
	//����ͼƬ
	public void clearAndSetReaderId(){
		for(int j=0;j<readertxt.length;j++){
			readertxt[j].setText("");
		}
		String str=getInsertOrderedList();
		readertxt[0].setEditable(false);
		readertxt[0].setText(str);

	}
	String[] labelsign={"���߱��","��������","�������","�����Ա�","�ɽ�����","�ɽ�����"};
	Label[] readerlb=new Label[6];
	static TextField[] readertxt=new TextField[6];
	Button querybtn,closebtn;
	static Choice readertype,readersex;
	public ReaderAdd(){
		setLayout(null);
		setSize(500,200);setResizable(false);
		setTitle("����¶���");
		String str=getInsertOrderedList();
		int lx=50,ly=50;
			for(int i=0;i<readertxt.length;i++){
				if(lx>240){
					ly=ly+30;
					lx=50;
				}
				readerlb[i]=new Label(labelsign[i]);
				readertxt[i]=new TextField();
				readerlb[i].setBounds(lx,ly,50,20);
				readertxt[i].setBounds(lx+60,ly,100,20);
				lx=lx+190;
				add(readerlb[i]);
				add(readertxt[i]);
			}
		readertxt[0].setEditable(false);
		readertxt[0].setText(str);
		readertype=new Choice();
		readertype.add("��ʦ");
		readertype.add("ѧ��");
		readersex=new Choice();
		readersex.add("��");
		readersex.add("Ů");
		readertxt[2].setVisible(false);
		readertxt[3].setVisible(false);
		readertype.setBounds(110,80,100,20);
		readersex.setBounds(300,80,100,20);
		add(readertype);add(readersex);
		querybtn=new Button("Add");
		closebtn=new Button("Close");
		querybtn.setBounds(130,140,50,20);
		closebtn.setBounds(310,140,50,20);
		add(querybtn);add(closebtn);
		querybtn.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				updateActionPerformed(e);
				clearAndSetReaderId();
			}
		});
		closebtn.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				DBset.close();
				dispose();
			}
		});
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				DBset.close();
				dispose();
			}
		});
		setLocationRelativeTo(null);
		setVisible(true);
	}
	public static String getInsertOrderedList(){
		String returnstring="";
		String sql="select * from reader";
		try{
			int count=0;
			ResultSet rs=DBset.executeQuery(sql);
			while(rs.next()){
				count++;
			}
			String[] allid=new String[count];
			int[] intofid=new int[count];
			int i=0;
			ResultSet rs1=DBset.executeQuery(sql);
			while(rs1.next()){
				allid[i]=rs1.getString("id");
				String mystr=allid[i].substring(1);
				intofid[i]=Integer.parseInt(mystr);
				i++;
			}
			int temp=-1;
			for(int j=0;j<intofid.length;j++){
				if(intofid[j]>temp){
					temp=intofid[j];		
				}
			}
			returnstring=String.valueOf(temp+1);
			int len=returnstring.length();
			for(int f=0;f<5-len;f++){
				returnstring="0"+returnstring;
			}
			returnstring="R"+returnstring;
			DBset.close();
			}catch(SQLException ee){}
		return returnstring;
	}
	public static void updateActionPerformed(ActionEvent e){

		String[] readerstr=new String[6];
		readerstr[2]=readertype.getSelectedItem().toString();
		readerstr[3]=readersex.getSelectedItem().toString();
		for(int i=0;i<readerstr.length;i++){
			if(i==2||i==3){
				continue;
			}
			readerstr[i]=readertxt[i].getText();
			if(readerstr[i].equals("")){
				JOptionPane.showMessageDialog(null,"����дȫ����Ϣ");
				return;
			}
		}
		String id=getInsertOrderedList();
		if(IfReaderExit(id)){
			JOptionPane.showMessageDialog(null,"�ö����Ѿ�����");
			return;
		}
		try{
			int max_num=Integer.parseInt(readerstr[4]);
			int days_num=Integer.parseInt(readerstr[5]);
			String sql="insert into reader(id,readername,readertype,sex,max_num,days_num) values('";
			sql=sql+id+"','"+readerstr[1]+"','"+readerstr[2]+"','"+readerstr[3]+"',"+max_num+","+days_num+")";
			int a=DBset.executeUpdate(sql);
			if(a==1){
				JOptionPane.showMessageDialog(null,"������ӳɹ�");
			}else{
				JOptionPane.showMessageDialog(null,"�������ʧ��");
			}
			DBset.close();
		}catch(NumberFormatException e1){
			JOptionPane.showMessageDialog(null,"�ɽ������Ϳɽ���������������");
		}
	}
	public static boolean IfReaderExit(String id){
		String sql="select * from reader where id='"+id+"'";
		try{
			ResultSet rs=DBset.executeQuery(sql);
			if(rs.next()){
				return true;
			}else{
				return false;
			}
		}catch(SQLException e){
			JOptionPane.showMessageDialog(null,"��ѯ���ݴ���");
		}
		return false;
	}
}