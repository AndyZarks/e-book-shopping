#include"order.h"

order::order()
{
	total_price = 0;
	p_buyer = NULL;
}

void order::display()
{
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "\t\t" << "订单信息" << endl;
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "书序号" << '\t' << "书名" << '\t' << "作者" << '\t' << "出版社" << '\t' << "定价" << endl;
	for (unsigned int i = 0; i < shopping_list.size(); i++)
	{
		shopping_list[i].display_mini();
	}
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "总价" << "\t\t\t\t\t" << total_price << endl;
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "买家信息:" << endl;
	p_buyer->display();
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
}

void order::setprice()
{
	for (unsigned int i = 0; i < shopping_list.size(); i++)
	{
		total_price += shopping_list[i].getprice() * p_buyer->getdiscount();
	}
}

void order::setbuyer(buyer* buyer)
{
	p_buyer = buyer;
}