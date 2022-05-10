package book;

import other.DBset;

import java.awt.*;
import java.awt.event.*;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import javax.swing.JOptionPane;
public class BookAdd extends Frame implements ActionListener{
	public static void main(String[] args){
		new BookAdd();
	}
	//���ͼ�����
	Toolkit tool= getToolkit();
	String url="src/book.jpg";
	Image background=tool.getImage(url);
		public void paint(Graphics g){
		g.drawImage(background,0,0,this);
	}
	//����ͼƬ
	public void clearAndSetBookId(){
		for(int j=0;j<booktxt.length;j++){
			booktxt[j].setText("");
		}
		String str=getInsertOrderedList();
		booktxt[0].setEditable(false);
		booktxt[0].setText(str);
	}
	String[] lbname={"ͼ����","ͼ������","ͼ������","��     ��","�� �� ��","����ʱ��","����","�������","ͼ��ҳ��","��������"};
	Label[] booklb=new Label[10];
	TextField[] booktxt=new TextField[10];
	Button savebtn=new Button("����");
	Button closebtn=new Button("����");
	Choice booktype=new Choice();
	public BookAdd(){
		setTitle("�������");
		setLayout(null);
		setSize(500,250);
		setResizable(false);
		this.setForeground(Color.BLACK);
		int lx=50,ly=50;
		booktype.add("�������");
		booktype.add("ͼ�����");
		booktype.add("����");
		booktype.add("���ݿ�");
		booktype.add("�������");
		booktype.add("���պ���");
		booktype.add("Ӣ��");
		booktype.add("��ѧ");
		String str=getInsertOrderedList();
		for(int i=0;i<booklb.length;i++){
			if(lx>240){
				lx=50;
				ly=ly+30;
			}
			booklb[i]=new Label(lbname[i]);
			booklb[i].setBounds(lx,ly,50,20);
			booktxt[i]=new TextField();
			booktxt[i].setBounds(lx+60,ly,100,20);
			lx=lx+190;
			add(booklb[i]);
			add(booktxt[i]);
		}
		booktxt[0].setEditable(false);
		booktxt[0].setText(str);
		booktxt[9].setVisible(false);
		booktype.setBounds(300,170,100,20);
		add(booktype);
		savebtn.setBounds(150,210,80,25);
		closebtn.setBounds(280,210,80,25);
		add(savebtn);
		add(closebtn);
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				DBset.close();
				dispose();	
			}
		});
		savebtn.addActionListener(this);
		closebtn.addActionListener(this);
		setLocationRelativeTo(null);
		setVisible(true);
	}
	public static String getInsertOrderedList(){
		String returnstring="";
		String sql="select * from book";
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
				String mystr=allid[i].substring(2);
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
			for(int f=0;f<6-len;f++){
				returnstring="0"+returnstring;
				
			}
			returnstring="BH"+returnstring;
			DBset.close();
			}catch(SQLException ee){

		}
		return returnstring;
	}
	public  void actionPerformed(ActionEvent e){
		Object ob=e.getSource();
		if(ob==savebtn){
			savebtnActionPerformed();
			clearAndSetBookId();
		}
		if(ob==closebtn){
			DBset.close();
			dispose();						
		}
	}
	public  void savebtnActionPerformed(){
		String id=booktxt[0].getText();
		String typestr=booktype.getSelectedItem().toString();
		String[] inputstring=new String[9];
		for(int i=0;i<inputstring.length;i++){
			inputstring[i]=booktxt[i].getText();
			if(inputstring[i].equals("")){
				JOptionPane.showMessageDialog(null,"�������д����");
				return;
			}
		}
		if(id.equals("")){
			JOptionPane.showMessageDialog(null,"ͼ���Ų���Ϊ��");
			return;
		}
		if(IfBookIdExit(id)){
			JOptionPane.showMessageDialog(null,"ͼ�����Ѵ���");
			return;
		}
		int i=0;
		try{
			SimpleDateFormat sdf=new SimpleDateFormat("yyyy-MM-dd");
			sdf.parse(inputstring[5]);
			float price=Float.parseFloat(inputstring[6]);
			int num= Integer.parseInt(inputstring[7]);
			int page=Integer.parseInt(inputstring[8]);
			String sql="insert into book ";
			sql=sql+"values('"+id+"','"+inputstring[1]+"','"+typestr+"','"+inputstring[2]+"','"+inputstring[3]+"','";
			sql=sql+inputstring[4]+"','"+inputstring[5]+"','"+price+"','"+num+"','"+page+"')";
			i=DBset.executeUpdate(sql);
			if(i==1){
				JOptionPane.showMessageDialog(null,"ͼ����ӳɹ���");
				clearAllText();
			}
		}catch(ParseException e2){
			JOptionPane.showMessageDialog(null,"����ʱ���ʽ������ȷΪ����-��-�գ�");
		}catch(NumberFormatException e1){
			JOptionPane.showMessageDialog(null,"����������۸�ҳ������ӦΪ����");
		}
	}
	public boolean IfBookIdExit(String id){
		boolean right=false;
		String sql="select*from book where id='"+id+"'";
		ResultSet rs=DBset.executeQuery(sql);
		try{
			while(rs.next()){		
				right = true;
			}
		}catch(SQLException e){
			JOptionPane.showMessageDialog(null,"�޷�������ȡ����");
		}
		return right;
	}
	public void clearAllText(){
		for(int i=0;i<booktxt.length;i++){
			booktxt[i].setText("");
		}
	}
}