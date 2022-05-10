package other;

import java.sql.ResultSet;
import java.sql.SQLException;
import javax.swing.JOptionPane;

public class IfBorrowBack{
	public static boolean findBook(String bookid,String readerid){
		String sql;
		sql="SELECT * FROM BORROW WHERE book_id='"+bookid+"' AND reader_id='"+readerid+"' AND if_back='·ñ'";
		ResultSet rs=DBset.executeQuery(sql);
		try{
			if(rs.next())
				return true;
			else
				return false;
		}catch(SQLException e){
			JOptionPane.showMessageDialog(null,"Êý¾Ý¿â²éÑ¯Ê§°Ü");
		}
		return true;
	}
}