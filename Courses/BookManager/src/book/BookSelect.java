package book;

import other.DBset;

import java.sql.*;
import javax.swing.JOptionPane;
public class BookSelect{
	public static Book SelectBookByID(String id){
		String sql="SELECT * FROM book WHERE id='"+id+"'";
		ResultSet rs=DBset.executeQuery(sql);
		Book book=null;
		try{
		book=new Book();
		if(rs.next()){
			book.setId(rs.getString("id"));
			book.setBooktype(rs.getString("booktype"));
			book.setBookname(rs.getString("bookname"));
			book.setAuthor(rs.getString("author"));
			book.setTranslator(rs.getString("translator"));
			book.setPublisher(rs.getString("publisher"));
			book.setPublish_time(rs.getDate("publish_time"));
			book.setPrice(rs.getFloat("price"));
			book.setStock(rs.getInt("num"));
			book.setPage(rs.getInt("page"));
			}else{
				book=null;	
			}
		}catch(SQLException e){
			JOptionPane.showMessageDialog(null,"Error：无法连接数据库"+e.getMessage());
		}catch(NullPointerException e){
			JOptionPane.showMessageDialog(null,"Error：无法连接数据库"+e.getMessage());
		}
		return book;
	}
}