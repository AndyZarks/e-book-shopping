#pragma once
#include<string>
#include<iostream>
#include<vector>
#include"books.h"
#include"customer.h"
using namespace std;

class order
{
private:
	double total_price;		//�ܼƼ۸�
	buyer* p_buyer;			//���
public:
	order();
	vector<book> shopping_list;	//�����嵥
	void display();				//��ʾ������Ϣ 
	void setprice();			//�����ܼ�
	void setbuyer(buyer* buyer);//�������
};

