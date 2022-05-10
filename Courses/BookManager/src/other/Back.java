package other;

import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.util.Date;
import java.util.*;
import java.text.*;
import javax.swing.JOptionPane;

import book.Book;
import book.BookSelect;
import read.Reader;
import read.ReaderSelect;

public class Back extends Frame {
	public static void main(String[] args){
		new Back();
	}
	//还书界面
	Toolkit tool= getToolkit();
	String url="src/borrow.jpg";
	Image background=tool.getImage(url);
		public void paint(Graphics g){
		g.drawImage(background,0,0,this);
	}
	//背景图片
	Label bookidlb = new Label("图书编号");
	Label readeridlb = new Label("读者编号");
	TextField bookidtxt = new TextField();
	TextField readeridtxt = new TextField();
	Button querybtn = new Button("查询");
	Button borrowbtn = new Button("归还");
	Button closebtn = new Button("清除");
	String[] sep = { "图书信息", "读者信息", "借阅信息" };
	Label[] seplabel = new Label[3];
	String[] optionname = { "图书书名：", "作者：", "出版社：", "出版时间：", "定价：", "剩余数量：", "姓名：","类型：", "可借数：", "可借天数：", "借阅日期：","阅读天数：","还书日期" };
	Label[] alloption = new Label[13];
	Label[] showoption = new Label[13];

	public Back() {
		setTitle("图书归还");
		setLayout(null);
		setSize(500, 470);
		setResizable(false);
		this.setForeground(Color.BLACK);
		bookidlb.setBounds(50, 50, 50, 20);
		bookidtxt.setBounds(110, 50, 100, 20);
		readeridlb.setBounds(220, 50, 50, 20);
		readeridtxt.setBounds(280, 50, 100, 20);
		querybtn.setBounds(400, 50, 50, 20);
		add(bookidlb);
		add(bookidtxt);
		add(readeridlb);
		add(readeridtxt);
		add(querybtn);
		int lx = 50, ly = 90, i = 0, k = 0;
		for (int j = 0; j < alloption.length; j++) {
			if (lx > 300) {
				lx = 50;
				ly = ly + 30;
			}
			if (ly == 90 || ly == 210 || ly == 300) {
				System.out.println(i);
				seplabel[i] = new Label("<" + sep[i] + ">");
				seplabel[i].setBounds(20, ly, 65, 20);
				add(seplabel[i]);
				j--;
				k++;
				if (k <= 1) {
					i = 0;
				}
				if (k == 2 || k == 3) {
					i = 1;
				}
				if (k == 4) {
					i = 2;
				}
			} else {
				alloption[j] = new Label(optionname[j]);
				showoption[j] = new Label("");
				alloption[j].setBounds(lx, ly, 70, 20);
				showoption[j].setBounds(lx + 70, ly, 150, 20);
				add(alloption[j]);
				add(showoption[j]);
			}
			lx = lx + 250;
		}
		borrowbtn.setBounds(110, 400, 50, 20);
		closebtn.setBounds(310, 400, 50, 20);
		add(borrowbtn);
		add(closebtn);
		borrowbtn.setEnabled(false);
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				dispose();
			}
		});
		querybtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				queryActionPerformed(e);
			}
		});

		borrowbtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				borrowActionPerformed(e);
			}
		});
		closebtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				setInitialize();	
			}
		});

		setLocationRelativeTo(null);
		setVisible(true);
	}
	public void borrowActionPerformed(ActionEvent e) {
		String bookid = bookidtxt.getText(), readerid = readeridtxt.getText();
		if (!bookid.equals("") && !readerid.equals("")) {
			Date currentdate = new Date();
			String borrowbackdate = showoption[12].getText();
			String sql = "update borrow set back_date='"+borrowbackdate+"',if_back='是'";
			sql=sql+"where book_id='"+bookid+"'and reader_id='"+readerid+"'and if_back='否'";
			int success = DBset.executeUpdate(sql);
			if (success == 1) {
				JOptionPane.showMessageDialog(null, "归还图书成功");

			} else {
				JOptionPane.showMessageDialog(null, "归还图书失败");
			}
			setInitialize();
		}
	}

	public void queryActionPerformed(ActionEvent e) {
		String bookid = bookidtxt.getText(), readerid = readeridtxt.getText();
		if (bookid.equals("")) {
			JOptionPane.showMessageDialog(null, "图书编号不可以为空，请输入图书编号");
			setInitialize();
			return;
		}
		else if (readerid.equals("")){
			JOptionPane.showMessageDialog(null, "读者编号不可以为空，请输入读者编号");
			setInitialize();
			return;
		}
		Book book = BookSelect.SelectBookByID(bookid);
		Reader reader = ReaderSelect.SelectReaderByID(readerid);
		if (!IfBorrowBack.findBook(bookid, readerid)) {
			JOptionPane.showMessageDialog(null,"没有借阅记录，请核对图书编号和读者编号");
			setInitialize();
			return;

		} else {

		}
		if (book != null && reader != null) {
			showoption[0].setText(book.getBookname().toString());
			showoption[1].setText(book.getAuthor().toString());
			showoption[2].setText(book.getPublisher().toString());
			showoption[3].setText(book.getPublish_time().toString());
			showoption[4].setText(String.valueOf(book.getPrice()));
			showoption[5].setText(String.valueOf(book.getStock()));
			showoption[6].setText(reader.getReadername());
			showoption[7].setText(reader.getReadertype());
			showoption[8].setText(String.valueOf(reader.getMax_num()));
			showoption[9].setText(String.valueOf(reader.getDays_num()));
		} else if(book==null){
			JOptionPane.showMessageDialog(null, "查询图书不存在，请核对图书编号");
			setInitialize();
			return;

		} else if(reader==null){
			JOptionPane.showMessageDialog(null, "查询读者不存在，请核对图书编号");
			setInitialize();
			return;

		}
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
		Date currentdate = new Date();
		Date thisbookborrowdate=getBorrowDate(bookid,readerid);
		String daycutearlyday=getReaderBorrowDays(thisbookborrowdate,currentdate);
		showoption[10].setText(sdf.format(thisbookborrowdate));
		showoption[12].setText(sdf.format(currentdate));
		showoption[11].setText(daycutearlyday);
		borrowbtn.setEnabled(true);
		bookidtxt.setEditable(false);
		readeridtxt.setEditable(false);
	}
	public boolean IfLeapYear(int year) {// 是否闰年，用于计算时间差
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
			return true;
		}
		return false;
	}

	public String getReaderBorrowDays(Date date1, Date date2) {// 计算时间差
		String sum = "";
		int year1 = 0, month1 = 0, day1 = 0;
		int year2 = 0, month2 = 0, day2 = 0;
		int[] monthdays = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		Calendar cal1 = new GregorianCalendar();
		Calendar cal2 = new GregorianCalendar();
		cal1.setTime(date1);
		year1 = cal1.get(Calendar.YEAR);
		month1 = cal1.get(Calendar.MONTH);
		day1 = cal1.get(Calendar.DAY_OF_MONTH);
		cal2.setTime(date2);
		year2 = cal2.get(Calendar.YEAR);
		month2 = cal2.get(Calendar.MONTH);
		day2 = cal2.get(Calendar.DAY_OF_MONTH);
		if (IfLeapYear(year1)) {
			monthdays[1] = 29;
		} else {
			monthdays[1] = 28;
		}
		int a = 3, count = 0;
		while (a > 0) {
			if (month1 > monthdays.length - 1) {
				year1++;
				month1 = 0;
			}
			if (IfLeapYear(year1)) {
				monthdays[1] = 29;
			} else {
				monthdays[1] = 28;
			}
			if (day1 > monthdays[month1]) {
				month1++;
				day1 = 1;
			}
			day1++;
			count++;
			if (year1 >= year2 && month1 >= month2 && day1 >= day2) {
				a = -1;

			}
		}
		sum = String.valueOf(count);
		return sum;
	}
	public Date getBorrowDate(String bookid, String readerid) {// 获取读者借书日期
		String sql, mydate = "";
		Date readerdate = new Date();
		sql = "select * from borrow where book_id='" + bookid
				+ "' and reader_id='" + readerid + "' and if_back='否'";
		ResultSet rs = DBset.executeQuery(sql);
		try {
			if (rs.next()) {
				mydate = rs.getString("borrow_date");
			}
			SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
			readerdate = sdf.parse(mydate);
			DBset.close();
		} catch (SQLException e) {
			JOptionPane.showMessageDialog(null, "借书日期查询失败");
		} catch (ParseException e2) {
			JOptionPane.showMessageDialog(null, "借书日期异常");
		}
		return readerdate;
	}

	public void setInitialize() {
		for (int i = 0; i < showoption.length; i++) {
			showoption[i].setText("");
		}
		bookidtxt.setText("");
		readeridtxt.setText("");
		bookidtxt.setEditable(true);
		readeridtxt.setEditable(true);
		borrowbtn.setEnabled(false);
	}

	
}