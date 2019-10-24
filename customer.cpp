#include"customer.h"

buyer::buyer()							//无参构造函数
{
	name = "";
	buyerID = "0000";
	adress = "";
}

buyer::buyer(string n, string b, string a)	//带参数构造函数
{
	name = n;
	buyerID = b;
	adress = a;
}

string buyer::getadress()				//获取地址
{
	return adress;
}

void buyer::setadress()					//设置地址
{
	cout << "请输入新的地址" << endl;
	string tempadress;
	cin >> tempadress;
	adress = tempadress;
}

string buyer::getname()					//获取名字
{
	return name;
}

void buyer::setname()					//设置名字
{
	cout << "请输入新的姓名:" << endl;
	string tempname;
	cin >> tempname;
	name = tempname;

}

string buyer::getid()						//获取ID
{
	return buyerID;
}

void buyer::setid()						//设置ID
{
	cout << "请输入新的ID:" << endl;
	string tempID;
	cin >> tempID;
	buyerID = tempID;
}

void member::display()					//显示会员信息
{
	cout << "姓名：" << name << endl;
	cout << "用户ID：" << buyerID << endl;
	cout << "地址:" << adress << endl;
	cout << "您是会员，级别为: " << member_level << endl;
}

double member::getdiscount()		//获取会员折扣率
{
	return member_level * 0.9;
}

void super_member::display()			//显示贵宾信息
{
	cout << "姓名：" << name << endl;
	cout << "用户：" << buyerID << endl;
	cout << "地址:" << adress << endl;
	cout << "尊敬的贵宾！您在本站购书可享" << discount_rate * 100 << "%" << "的优惠" << endl;
}

double super_member::getdiscount()	//获取贵宾折扣率
{
	return discount_rate;
}

void normal_buyer::display()			//显示普通用户信息
{
	cout << "购书人姓名：" << name << endl;
	cout << "购书人编号：" << buyerID << endl;
	cout << "购书人为普通用户" << endl;
	cout << "地址:" << adress << endl;
}

double normal_buyer::getdiscount()	//获取普通顾客折扣率
{
	return 1;
}