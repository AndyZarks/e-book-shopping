#pragma once
#include<string>
#include<iostream>
using namespace std;

class buyer
{
protected:
	string name;		//����
	string buyerID;		//ID
	string adress;		//��ַ
public:
	buyer();
	buyer(string n, string b, string a);
	string getname();	//��ȡ����
	void setname();		//��������
	string getadress();	//��ȡ��ַ
	void setadress();	//���õ�ַ
	string getid();		//��ȡID
	void setid();		//����ID
	virtual void display() = 0;
	virtual double getdiscount() = 0;
};

class member : public buyer			//��Ա
{
private:
	int member_level;		//��Ա�ȼ�
public:
	member(string n, string b, int l, string a) :buyer(n, b, a)
	{
		member_level = l;
	};
	void display();				//��ʾ������Ϣ
	double getdiscount();			//��ȡ�ۿ���
};

class super_member : public buyer	//���
{
	double discount_rate;	//�ۿ���
public:
	super_member(string n, string b, double r, string a) :buyer(n, b, a)
	{
		discount_rate = r;
	}
	void display();				//��ʾ������Ϣ
	double getdiscount();			//��ȡ�ۿ���
};

class normal_buyer :public buyer	//��ͨ�û�
{
public:
	normal_buyer(string n, string b, string a) :buyer(n, b, a) {};
	void display();				//��ʾ������Ϣ
	double getdiscount();			//��ȡ�ۿ���
};