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
	//添加图书界面
	Toolkit tool= getToolkit();
	String url="src/book.jpg";
	Image background=tool.getImage(url);
		public void paint(Graphics g){
		g.drawImage(background,0,0,this);
	}
	//背景图片
	public void clearAndSetBookId(){
		for(int j=0;j<booktxt.length;j++){
			booktxt[j].setText("");
		}
		String str=getInsertOrderedList();
		booktxt[0].setEditable(false);
		booktxt[0].setText(str);
	}
	String[] lbname={"图书编号","图书名称","图书作者","翻     译","出 版 社","出版时间","定价","库存数量","图书页数","所属类型"};
	Label[] booklb=new Label[10];
	TextField[] booktxt=new TextField[10];
	Button savebtn=new Button("保存");
	Button closebtn=new Button("返回");
	Choice booktype=new Choice();
	public BookAdd(){
		setTitle("添加新书");
		setLayout(null);
		setSize(500,250);
		setResizable(false);
		this.setForeground(Color.BLACK);
		int lx=50,ly=50;
		booktype.add("程序设计");
		booktype.add("图形设计");
		booktype.add("其他");
		booktype.add("数据库");
		booktype.add("软件工程");
		booktype.add("航空航天");
		booktype.add("英语");
		booktype.add("数学");
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
				JOptionPane.showMessageDialog(null,"请务必填写完整");
				return;
			}
		}
		if(id.equals("")){
			JOptionPane.showMessageDialog(null,"图书编号不能为空");
			return;
		}
		if(IfBookIdExit(id)){
			JOptionPane.showMessageDialog(null,"图书编号已存在");
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
				JOptionPane.showMessageDialog(null,"图书添加成功！");
				clearAllText();
			}
		}catch(ParseException e2){
			JOptionPane.showMessageDialog(null,"出版时间格式错误，正确为（年-月-日）");
		}catch(NumberFormatException e1){
			JOptionPane.showMessageDialog(null,"库存数量，价格，页数错误，应为数字");
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
			JOptionPane.showMessageDialog(null,"无法正常读取数据");
		}
		return right;
	}
	public void clearAllText(){
		for(int i=0;i<booktxt.length;i++){
			booktxt[i].setText("");
		}
	}
}