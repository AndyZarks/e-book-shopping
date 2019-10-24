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
	double total_price;		//总计价格
	buyer* p_buyer;			//买家
public:
	order();
	vector<book> shopping_list;	//购物清单
	void display();				//显示订单信息 
	void setprice();			//设置总价
	void setbuyer(buyer* buyer);//设置买家
};

