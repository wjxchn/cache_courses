package main;

import book.BookAdd;
import book.BookDelete;
import book.BookQuery;
import book.BookUpdate;
import read.ReaderAdd;
import read.ReaderDelete;
import read.ReaderQuery;
import read.ReaderUpdate;
import other.DBset;
import other.Back;
import other.Borrow;

import java.awt.*;
import java.awt.event.*;

public class Main extends Frame{
	public static void main(String[] args){
		new Main();
	}
	//ͼ�����ϵͳ������
	Toolkit tool= getToolkit();
	String url="src/main.jpg";
	Image background=tool.getImage(url);
		public void paint(Graphics g){
		g.drawImage(background,0,0,this);
	}
	//����ͼƬ
	Button book_add,book_update,book_delete;
	Button reader_add,reader_update,reader_delete;
	Button borrow,back,query_book,query_reader,exit;
	//���ܰ�ť
	public Main(){
		setTitle("ͼ�����ϵͳ");	
		setLayout(null);
		setSize(780,540);
		setResizable(false);
		book_add=new Button("���ͼ��");
		book_update=new Button("����ͼ����Ϣ");
		book_delete=new Button("ɾ��ͼ��");
		reader_add=new Button("��Ӷ���");
		reader_update=new Button("���¶�����Ϣ");
		reader_delete=new Button("ɾ������");
		borrow=new Button("�������");
		back=new Button("�������");
		query_book=new Button("ͼ���ѯ");
		query_reader=new Button("���߲�ѯ");
		exit=new Button("�˳�ϵͳ");
		book_add.setBounds(70,200,80,50);
		book_add.setBackground(Color.LIGHT_GRAY);
		book_update.setBounds(70,300,80,50);
		book_update.setBackground(Color.LIGHT_GRAY);
		book_delete.setBounds(70,400,80,50);
		book_delete.setBackground(Color.lightGray);
		reader_add.setBounds(250,200,80,50);
		reader_add.setBackground(Color.pink);
		reader_update.setBounds(250,300,80,50);
		reader_update.setBackground(Color.pink);
		reader_delete.setBounds(250,400,80,50);
		reader_delete.setBackground(Color.pink);
		borrow.setBounds(440,200,80,50);
		borrow.setBackground(Color.yellow);
		back.setBounds(440,300,80,50);
		back.setBackground(Color.yellow);
		query_book.setBounds(620,200,80,50);
		query_book.setBackground(Color.orange);
		query_reader.setBounds(620,300,80,50);
		query_reader.setBackground(Color.orange);
		exit.setBounds(345,50,80,50);
		exit.setBackground(Color.red);
		this.add(book_add);
		this.add(book_update);
		this.add(book_delete);
		this.add(reader_add);
		this.add(reader_update);
		this.add(reader_delete);
		this.add(borrow);
		this.add(back);
		this.add(query_book);
		this.add(query_reader);
		this.add(exit);
		//��ť�¼�
		book_add.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new BookAdd();
			}
		});
		book_update.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new BookUpdate();
			}
		});
		book_delete.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new BookDelete();
			}
		});
		reader_add.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new ReaderAdd();
			}
		});
		reader_update.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new ReaderUpdate();
			}
		});
		reader_delete.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new ReaderDelete();
			}
		});
		borrow.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new Borrow();
			}
		});
		back.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new Back();
			}
		});
		query_book.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new BookQuery();
			}
		});
		query_reader.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				new ReaderQuery();
			}
		});
		exit.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e){
				DBset.close();
				System.exit(0);
			}
		});
		addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				DBset.close();
				System.exit(0);
			}
		});
		setLocationRelativeTo(null);
		setVisible(true);
	}
}