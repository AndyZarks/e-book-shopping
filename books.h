#pragma once
#include<string>
#include<iostream>
using namespace std;

class book
{
protected:
	string book_ID;			//书序号
	string book_name;		//书名
	string author;			//作者
	string publishing;		//出版社
	double price;			//价格
public:
	book();
	book(string b_id, string b_n, string au, string pu, double pr);
	void display();
	void display_mini();
	string getbook_ID();	//获取书序号
	string getbook_name();	//获取书名
	string getauthor();		//获取作者
	string getpublishing();	//获取出版社
	double getprice();		//获取价格
	friend bool less_sort_ID(book const&, book const&);		//以书序号排序
	friend bool less_sort_name(book const&, book const&);	//以书名排序
	friend bool less_sort_price(book const&, book const&);	//以价格排序
};

bool less_sort_ID(book const&, book const&);
bool less_sort_name(book const&, book const&);
bool less_sort_price(book const&, book const&);