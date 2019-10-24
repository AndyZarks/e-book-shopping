#pragma once
#include<string>
#include<iostream>
using namespace std;

class buyer
{
protected:
	string name;		//名字
	string buyerID;		//ID
	string adress;		//地址
public:
	buyer();
	buyer(string n, string b, string a);
	string getname();	//获取名字
	void setname();		//设置名字
	string getadress();	//获取地址
	void setadress();	//设置地址
	string getid();		//获取ID
	void setid();		//设置ID
	virtual void display() = 0;
	virtual double getdiscount() = 0;
};

class member : public buyer			//会员
{
private:
	int member_level;		//会员等级
public:
	member(string n, string b, int l, string a) :buyer(n, b, a)
	{
		member_level = l;
	};
	void display();				//显示个人信息
	double getdiscount();			//获取折扣率
};

class super_member : public buyer	//贵宾
{
	double discount_rate;	//折扣率
public:
	super_member(string n, string b, double r, string a) :buyer(n, b, a)
	{
		discount_rate = r;
	}
	void display();				//显示个人信息
	double getdiscount();			//获取折扣率
};

class normal_buyer :public buyer	//普通用户
{
public:
	normal_buyer(string n, string b, string a) :buyer(n, b, a) {};
	void display();				//显示个人信息
	double getdiscount();			//获取折扣率
};