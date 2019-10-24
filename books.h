#pragma once
#include<string>
#include<iostream>
using namespace std;

class book
{
protected:
	string book_ID;			//�����
	string book_name;		//����
	string author;			//����
	string publishing;		//������
	double price;			//�۸�
public:
	book();
	book(string b_id, string b_n, string au, string pu, double pr);
	void display();
	void display_mini();
	string getbook_ID();	//��ȡ�����
	string getbook_name();	//��ȡ����
	string getauthor();		//��ȡ����
	string getpublishing();	//��ȡ������
	double getprice();		//��ȡ�۸�
	friend bool less_sort_ID(book const&, book const&);		//�����������
	friend bool less_sort_name(book const&, book const&);	//����������
	friend bool less_sort_price(book const&, book const&);	//�Լ۸�����
};

bool less_sort_ID(book const&, book const&);
bool less_sort_name(book const&, book const&);
bool less_sort_price(book const&, book const&);