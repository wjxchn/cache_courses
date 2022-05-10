package book;
import java.sql.Date;
public class Book {
	private static String id,bookname,booktype,author,translator,publisher;
	private static Date publish_time;
	private static int num,page;
	private static float price;
	/*
	 * 图书id，书名，类型，作者，翻译，出版社
	 * 出版时间
	 * 库存数量，页数
	 * 价格
	 */
	public static String getId() {
		return id;
	}
	public static void setId(String id) {
		Book.id = id;
	}
	public static String getBookname() {
		return bookname;
	}
	public static void setBookname(String bookname) {
		Book.bookname = bookname;
	}
	public static String getBooktype() {
		return booktype;
	}
	public static void setBooktype(String booktype) {
		Book.booktype = booktype;
	}
	public static String getAuthor() {
		return author;
	}
	public static void setAuthor(String author) {
		Book.author = author;
	}
	public static String getTranslator() {
		return translator;
	}
	public static void setTranslator(String translator) {
		Book.translator = translator;
	}
	public static String getPublisher() {
		return publisher;
	}
	public static void setPublisher(String publisher) {
		Book.publisher = publisher;
	}
	public static Date getPublish_time() {
		return publish_time;
	}
	public static void setPublish_time(Date publish_time) {
		Book.publish_time = publish_time;
	}
	public static int getStock() {
		return num;
	}
	public static void setStock(int stock) {
		Book.num = stock;
	}
	public static int getPage() {
		return page;
	}
	public static void setPage(int page) {
		Book.page = page;
	}
	public static float getPrice() {
		return price;
	}
	public static void setPrice(float price) {
		Book.price = price;
	}
	public static String[] getBookinformation() {
		String[] bookinformation={id,bookname,String.valueOf(page),author,translator,publisher,publish_time.toString(),String.valueOf(price),String.valueOf(num),booktype,};
		return bookinformation;
	}
}