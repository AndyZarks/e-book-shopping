#include"menu.h"

void back()			//返回菜单或退出
{
	char c;
	cout << '\n'<<"操作成功！是否返回主菜单？（请输入 y 或者 n）" << endl;
	while (1)
	{
		c = getchar();
		if (c == '\n')continue;
		else if (c == 'y') { system("cls"); menu(); break; }
		else if (c == 'n')break;
		else cout << "Please enter y(es) or n(o)!" << "\n";
	}
}

void buy_book()		//买书
{
	cout << "请选择排序规则:" << endl;
	cout << "[1]----以书序号排序" << endl;
	cout << "[2]----以书名排序" << endl;
	cout << "[3]----以价格排序" << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 1:sort(vector_books.begin(), vector_books.end(), less_sort_ID); break;
	case 2:sort(vector_books.begin(), vector_books.end(), less_sort_name); break;
	case 3:sort(vector_books.begin(), vector_books.end(), less_sort_price); break;
	}
	system("cls");
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "			书籍列表" << endl;
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "书序号" << '\t' << "书名" << '\t' << "作者" << '\t' << "出版社" << '\t' << "定价" << endl;
	for (unsigned int i = 0; i < vector_books.size(); i++)
	{
		vector_books[i].display_mini();
	}
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "请输入你要购买的图书的书序号或书名(输入Q退出):" << endl;
	order* p_order = new order;	//动态生成一个订单类的对象
	while (1)	//持续将书加入购物车的循环
	{
		string key_buy;
		cin >> key_buy;
		if (key_buy == "Q") break;
		int n = 0;	//0代表没有找到书，1代表找到书了
		for (unsigned int i = 0; i < vector_books.size(); i++)
		{
			if (vector_books[i].getbook_ID() == key_buy || vector_books[i].getbook_name() == key_buy)
			{
				cout << "您选购的书籍《" << vector_books[i].getbook_name() << "》已经添加至购物车" << endl;
				p_order->shopping_list.push_back(vector_books[i]);
				n = 1;
			}
		}
		if (n == 0)	//判断有没有找到书
		{
			cout << "非常抱歉，没有找到相关书籍..." << endl;
			cout << "请重新输入信息(输入Q退出):" << endl;
		}
		else cout << "请继续输入下一本书的信息(输入Q退出):" << endl;
	}
	while (p_order->shopping_list.size())
	{
		cout << "请输入您的账户ID:" << endl;
		string ID;
		cin >> ID;
		int m = 0;
		for (unsigned int i = 0; i < vector_buyers.size(); i++)
		{
			if (ID == vector_buyers[i]->getid())
			{
				p_order->setbuyer(vector_buyers[i]);
				m = 1;
			}
		}
		if (m == 0)
		{
			cout << "没有找到该账户！";
		}
		else break;
	}
	p_order->setprice();
	if (p_order->shopping_list.size())vector_order.push_back(*p_order);
	back();
}

void search_book()	//查书
{
	cout << "输入书序号或者书名搜索(输入Q退出):" << endl;
	while (1)
	{
		string search;
		cin >> search;
		if (search == "Q") break;
		int n = 0;
		for (unsigned int i = 0; i < vector_books.size(); i++)
		{
			if (vector_books[i].getbook_ID() == search || vector_books[i].getbook_name() == search)
			{
				cout << "搜索成功！该书信息为:" << endl;
				for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
				vector_books[i].display();
				for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
				n = 1;
			}
		}
		if (n == 0)
		{
			cout << "非常抱歉，没有找到相关书籍..." << endl;
			cout << "请重新输入信息(输入Q退出):" << endl;
		}
		else break;
	}
	back();
}

void edit_info()	//添加或修改用户信息
{
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "请选择修改或添加用户信息:" << endl;
	cout << "[1]----修改用户信息" << endl;
	cout << "[2]----添加新用户" << endl;
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	int a;
	cin >> a;
	while (a == 1)	//修改用户信息分菜单
	{
		system("cls");
		for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
		cout << "\t\t" << "修改用户信息" << endl;
		for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
		cout << "请输入你的用户ID或姓名(输入Q退出):" << endl;
		string search;
		cin >> search;
		if (search == "Q") break;
		int n = 0;
		for (unsigned int i = 0; i < vector_buyers.size(); i++)
		{
			if (search == vector_buyers[i]->getname() || search == vector_buyers[i]->getid())
			{
				cout << "您的信息是:" << endl;
				for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
				vector_buyers[i]->display();
				for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
				n = 1;
				cout << '\n' << "请选择您要修改的数据:" << endl;
				cout << "[1]----修改姓名" << endl;
				cout << "[2]----修改地址" << endl;
				while (1)	//修改项选择分菜单
				{
					int a;
					cin >> a;
					if (a == 1)
					{
						vector_buyers[i]->setname();
						cout << "现在您的姓名是: ";
						cout << vector_buyers[i]->getname() << endl;
						break;
					}
					else if (a == 2)
					{
						vector_buyers[i]->setadress();
						cout << "现在您的地址是: ";
						cout << vector_buyers[i]->getadress() << endl;
						break;
					}
					else cout << "请输入正确的数字:" << endl;
				}
			}
		}
		if (n == 0)
		{
			cout << "没有找到相应的用户！" << endl;
			cout << "请重新输入信息(输入Q退出):" << endl;
		}
		else break;
	}
	while (a == 2)	//添加新用户分菜单
	{
		system("cls");
		for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
		cout << "\t\t" << "添加新用户" << endl;
		for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
		cout << "请选择您的会员类别:" << endl;
		cout << "[1]----普通用户" << endl;
		cout << "[2]----会员" << endl;
		cout << "[3]----贵宾" << endl;
		for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
		cout << "您是:  ";
		int i;
		cin >> i;
		if (i == 1)		//添加普通用户
		{
			cout << '\n' << "请输入以下信息:" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			cout << "姓名" << '\t' << "用户ID" << '\t' << "地址" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			string name;
			string buyerID;
			string adress;
			cin >> name >> buyerID >> adress;
			for(unsigned b = 0;b < vector_buyers.size(); b++)
			{
				if (buyerID == vector_buyers[b]->getid())
				{
					cout << "ID已存在，请重新输入！" << endl;
					cin >> buyerID;
					b = 0;
				}
			}
			buyer* p_buyer = new normal_buyer(name, buyerID, adress);
			cout << '\n' << "您的信息为:" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			p_buyer->display();
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			vector_buyers.push_back(p_buyer);
			break;
		}
		else if (i == 2)//添加会员
		{
			cout << '\n' << "请输入以下信息:" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			cout << "姓名" << '\t' << "用户ID" << '\t' << "地址" << '\t' << "会员等级" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			string name, buyerID, adress;
			int level;
			cin >> name >> buyerID >> adress >> level;
			for (unsigned b = 0; b < vector_buyers.size(); b++)
			{
				if (buyerID == vector_buyers[b]->getid())
				{
					cout << "ID已存在，请重新输入！" << endl;
					cin >> buyerID;
					b = 0;
				}
			}
			buyer* p_buyer = new member(name, buyerID, level, adress);
			cout << '\n' << "您的信息为:" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			p_buyer->display();
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			vector_buyers.push_back(p_buyer);
			break;
		}
		else if (i == 3)//添加贵宾
		{
			cout << '\n' << "请输入以下信息:" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			cout << "姓名" << '\t' << "用户ID" << '\t' << "地址" << '\t' << "折扣率" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			string name, buyerID, adress;
			double discount;
			cin >> name >> buyerID >> adress >> discount;
			for (unsigned b = 0; b < vector_buyers.size(); b++)
			{
				if (buyerID == vector_buyers[b]->getid())
				{
					cout << "ID已存在，请重新输入！" << endl;
					cin >> buyerID;
					b = 0;
				}
			}
			buyer* p_buyer = new super_member(name, buyerID, discount, adress);
			cout << '\n' << "您的信息为:" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			p_buyer->display();
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			vector_buyers.push_back(p_buyer);
			break;
		}
		else cout << "请选择正确的用户类型！" << endl;
	}
	back();
}

void order_history()	//查看订单历史
{
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "\t\t" << "历史订单" << endl;
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	for (unsigned int i = 0; i < vector_order.size(); i++)
	{
		cout <<"\n\n\t\t"<< "订单【" << i + 1 << "】" << endl;
		vector_order[i].display();
		cout << endl;
	}
	back();
}

void save_data()	//保存数据至本地文件
{
	ofstream save_buyer_data;	//保存用户数据
	save_buyer_data.open("buyer.dat", ios::binary);
	if(!save_buyer_data)
	{
		cout << "此文件无法打开" << endl;
		exit(1);
	}
	for (unsigned int i = 0; i < vector_buyers.size(); i++)
	{
		save_buyer_data.write((char*)vector_buyers[i], sizeof(*vector_buyers[i]));
	}
	save_buyer_data.close();
	ofstream save_order_data;	//保存订单数据
	save_order_data.open("order.dat", ios::binary);
	if (!save_order_data)
	{
		cout << "此文件无法打开" << endl;
		exit(1);
	}
	for (unsigned int i = 0; i < vector_order.size(); i++)
	{
		save_order_data.write((char*)& vector_order[i], sizeof(vector_order[i]));
	}
	save_order_data.close();
	back();
}

void import_data()	//从本地文件导入数据
{
	ifstream in_buyer_data;		//导入用户数据
	in_buyer_data.open("buyer.dat", ios::binary);
	if(!in_buyer_data)
	{
		cout << "此文件无法打开" << endl;
		exit(1);
	}
	for (unsigned int i = 0; i < 6; i++)
	{
		in_buyer_data.read((char*)vector_buyers[i], sizeof(*vector_buyers[i]));
	}
	for (buyer* p_buyer = NULL; !in_buyer_data.eof();)
	{
		in_buyer_data.read((char*)p_buyer, sizeof(buyer*));
		vector_buyers.push_back(p_buyer);
	}
	in_buyer_data.close();
	ifstream in_order_data;	//导入订单数据
	in_order_data.open("order.dat", ios::binary);
	if (!in_order_data)
	{
		cout << "此文件无法打开" << endl;
		exit(1);
	}
	for (order* p_order = new order; !in_order_data.eof();)
	{
		in_order_data.read((char*)p_order, sizeof(*p_order));
		vector_order.push_back(*p_order);
	}
	in_order_data.close();
	back();
}

void menu()			//主菜单
{
	for (int i = 0; i < 52; i++) cout << "*"; cout << endl;
	cout << "	+----------------------------------+" << endl;
	cout << "	|       欢迎进入图书选购系统       |" << endl;
	cout << "	+----------------------------------+" << endl;
	cout << "	|       [1]----选购图书            |" << endl;
	cout << "	|       [2]----查找图书            |" << endl;
	cout << "	|       [3]----添加或修改用户信息  |" << endl;
	cout << "	|       [4]----查看历史订单        |" << endl;
	cout << "	|       [5]----保存数据至本地      |" << endl;
	cout << "	|       [6]----从本地导入数据      |" << endl;
	cout << "	|       [0]----退出系统            |" << endl;
	cout << "	+----------------------------------+" << endl;
	for (int i = 0; i < 52; i++) cout << "*"; cout << endl;
	cout << "请选择功能:";
	int a;
	cin >> a;
	switch (a)
	{
	case 1:system("cls"); buy_book(); break;
	case 2:system("cls"); search_book(); break;
	case 3:system("cls"); edit_info(); break;
	case 4:system("cls"); order_history(); break;
	case 5:system("cls"); save_data(); break;
	case 6:system("cls"); import_data(); break;
	case 0:break;
	}
}