#include"menu.h"

void back()			//���ز˵����˳�
{
	char c;
	cout << '\n'<<"�����ɹ����Ƿ񷵻����˵����������� y ���� n��" << endl;
	while (1)
	{
		c = getchar();
		if (c == '\n')continue;
		else if (c == 'y') { system("cls"); menu(); break; }
		else if (c == 'n')break;
		else cout << "Please enter y(es) or n(o)!" << "\n";
	}
}

void buy_book()		//����
{
	cout << "��ѡ���������:" << endl;
	cout << "[1]----�����������" << endl;
	cout << "[2]----����������" << endl;
	cout << "[3]----�Լ۸�����" << endl;
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
	cout << "			�鼮�б�" << endl;
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "�����" << '\t' << "����" << '\t' << "����" << '\t' << "������" << '\t' << "����" << endl;
	for (unsigned int i = 0; i < vector_books.size(); i++)
	{
		vector_books[i].display_mini();
	}
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "��������Ҫ�����ͼ�������Ż�����(����Q�˳�):" << endl;
	order* p_order = new order;	//��̬����һ��������Ķ���
	while (1)	//����������빺�ﳵ��ѭ��
	{
		string key_buy;
		cin >> key_buy;
		if (key_buy == "Q") break;
		int n = 0;	//0����û���ҵ��飬1�����ҵ�����
		for (unsigned int i = 0; i < vector_books.size(); i++)
		{
			if (vector_books[i].getbook_ID() == key_buy || vector_books[i].getbook_name() == key_buy)
			{
				cout << "��ѡ�����鼮��" << vector_books[i].getbook_name() << "���Ѿ���������ﳵ" << endl;
				p_order->shopping_list.push_back(vector_books[i]);
				n = 1;
			}
		}
		if (n == 0)	//�ж���û���ҵ���
		{
			cout << "�ǳ���Ǹ��û���ҵ�����鼮..." << endl;
			cout << "������������Ϣ(����Q�˳�):" << endl;
		}
		else cout << "�����������һ�������Ϣ(����Q�˳�):" << endl;
	}
	while (p_order->shopping_list.size())
	{
		cout << "�����������˻�ID:" << endl;
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
			cout << "û���ҵ����˻���";
		}
		else break;
	}
	p_order->setprice();
	if (p_order->shopping_list.size())vector_order.push_back(*p_order);
	back();
}

void search_book()	//����
{
	cout << "��������Ż�����������(����Q�˳�):" << endl;
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
				cout << "�����ɹ���������ϢΪ:" << endl;
				for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
				vector_books[i].display();
				for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
				n = 1;
			}
		}
		if (n == 0)
		{
			cout << "�ǳ���Ǹ��û���ҵ�����鼮..." << endl;
			cout << "������������Ϣ(����Q�˳�):" << endl;
		}
		else break;
	}
	back();
}

void edit_info()	//��ӻ��޸��û���Ϣ
{
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "��ѡ���޸Ļ�����û���Ϣ:" << endl;
	cout << "[1]----�޸��û���Ϣ" << endl;
	cout << "[2]----������û�" << endl;
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	int a;
	cin >> a;
	while (a == 1)	//�޸��û���Ϣ�ֲ˵�
	{
		system("cls");
		for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
		cout << "\t\t" << "�޸��û���Ϣ" << endl;
		for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
		cout << "����������û�ID������(����Q�˳�):" << endl;
		string search;
		cin >> search;
		if (search == "Q") break;
		int n = 0;
		for (unsigned int i = 0; i < vector_buyers.size(); i++)
		{
			if (search == vector_buyers[i]->getname() || search == vector_buyers[i]->getid())
			{
				cout << "������Ϣ��:" << endl;
				for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
				vector_buyers[i]->display();
				for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
				n = 1;
				cout << '\n' << "��ѡ����Ҫ�޸ĵ�����:" << endl;
				cout << "[1]----�޸�����" << endl;
				cout << "[2]----�޸ĵ�ַ" << endl;
				while (1)	//�޸���ѡ��ֲ˵�
				{
					int a;
					cin >> a;
					if (a == 1)
					{
						vector_buyers[i]->setname();
						cout << "��������������: ";
						cout << vector_buyers[i]->getname() << endl;
						break;
					}
					else if (a == 2)
					{
						vector_buyers[i]->setadress();
						cout << "�������ĵ�ַ��: ";
						cout << vector_buyers[i]->getadress() << endl;
						break;
					}
					else cout << "��������ȷ������:" << endl;
				}
			}
		}
		if (n == 0)
		{
			cout << "û���ҵ���Ӧ���û���" << endl;
			cout << "������������Ϣ(����Q�˳�):" << endl;
		}
		else break;
	}
	while (a == 2)	//������û��ֲ˵�
	{
		system("cls");
		for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
		cout << "\t\t" << "������û�" << endl;
		for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
		cout << "��ѡ�����Ļ�Ա���:" << endl;
		cout << "[1]----��ͨ�û�" << endl;
		cout << "[2]----��Ա" << endl;
		cout << "[3]----���" << endl;
		for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
		cout << "����:  ";
		int i;
		cin >> i;
		if (i == 1)		//�����ͨ�û�
		{
			cout << '\n' << "������������Ϣ:" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			cout << "����" << '\t' << "�û�ID" << '\t' << "��ַ" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			string name;
			string buyerID;
			string adress;
			cin >> name >> buyerID >> adress;
			for(unsigned b = 0;b < vector_buyers.size(); b++)
			{
				if (buyerID == vector_buyers[b]->getid())
				{
					cout << "ID�Ѵ��ڣ����������룡" << endl;
					cin >> buyerID;
					b = 0;
				}
			}
			buyer* p_buyer = new normal_buyer(name, buyerID, adress);
			cout << '\n' << "������ϢΪ:" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			p_buyer->display();
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			vector_buyers.push_back(p_buyer);
			break;
		}
		else if (i == 2)//��ӻ�Ա
		{
			cout << '\n' << "������������Ϣ:" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			cout << "����" << '\t' << "�û�ID" << '\t' << "��ַ" << '\t' << "��Ա�ȼ�" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			string name, buyerID, adress;
			int level;
			cin >> name >> buyerID >> adress >> level;
			for (unsigned b = 0; b < vector_buyers.size(); b++)
			{
				if (buyerID == vector_buyers[b]->getid())
				{
					cout << "ID�Ѵ��ڣ����������룡" << endl;
					cin >> buyerID;
					b = 0;
				}
			}
			buyer* p_buyer = new member(name, buyerID, level, adress);
			cout << '\n' << "������ϢΪ:" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			p_buyer->display();
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			vector_buyers.push_back(p_buyer);
			break;
		}
		else if (i == 3)//��ӹ��
		{
			cout << '\n' << "������������Ϣ:" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			cout << "����" << '\t' << "�û�ID" << '\t' << "��ַ" << '\t' << "�ۿ���" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			string name, buyerID, adress;
			double discount;
			cin >> name >> buyerID >> adress >> discount;
			for (unsigned b = 0; b < vector_buyers.size(); b++)
			{
				if (buyerID == vector_buyers[b]->getid())
				{
					cout << "ID�Ѵ��ڣ����������룡" << endl;
					cin >> buyerID;
					b = 0;
				}
			}
			buyer* p_buyer = new super_member(name, buyerID, discount, adress);
			cout << '\n' << "������ϢΪ:" << endl;
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			p_buyer->display();
			for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
			vector_buyers.push_back(p_buyer);
			break;
		}
		else cout << "��ѡ����ȷ���û����ͣ�" << endl;
	}
	back();
}

void order_history()	//�鿴������ʷ
{
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	cout << "\t\t" << "��ʷ����" << endl;
	for (int i = 0; i < 48; i++)cout << "*"; cout << endl;
	for (unsigned int i = 0; i < vector_order.size(); i++)
	{
		cout <<"\n\n\t\t"<< "������" << i + 1 << "��" << endl;
		vector_order[i].display();
		cout << endl;
	}
	back();
}

void save_data()	//���������������ļ�
{
	ofstream save_buyer_data;	//�����û�����
	save_buyer_data.open("buyer.dat", ios::binary);
	if(!save_buyer_data)
	{
		cout << "���ļ��޷���" << endl;
		exit(1);
	}
	for (unsigned int i = 0; i < vector_buyers.size(); i++)
	{
		save_buyer_data.write((char*)vector_buyers[i], sizeof(*vector_buyers[i]));
	}
	save_buyer_data.close();
	ofstream save_order_data;	//���涩������
	save_order_data.open("order.dat", ios::binary);
	if (!save_order_data)
	{
		cout << "���ļ��޷���" << endl;
		exit(1);
	}
	for (unsigned int i = 0; i < vector_order.size(); i++)
	{
		save_order_data.write((char*)& vector_order[i], sizeof(vector_order[i]));
	}
	save_order_data.close();
	back();
}

void import_data()	//�ӱ����ļ���������
{
	ifstream in_buyer_data;		//�����û�����
	in_buyer_data.open("buyer.dat", ios::binary);
	if(!in_buyer_data)
	{
		cout << "���ļ��޷���" << endl;
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
	ifstream in_order_data;	//���붩������
	in_order_data.open("order.dat", ios::binary);
	if (!in_order_data)
	{
		cout << "���ļ��޷���" << endl;
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

void menu()			//���˵�
{
	for (int i = 0; i < 52; i++) cout << "*"; cout << endl;
	cout << "	+----------------------------------+" << endl;
	cout << "	|       ��ӭ����ͼ��ѡ��ϵͳ       |" << endl;
	cout << "	+----------------------------------+" << endl;
	cout << "	|       [1]----ѡ��ͼ��            |" << endl;
	cout << "	|       [2]----����ͼ��            |" << endl;
	cout << "	|       [3]----��ӻ��޸��û���Ϣ  |" << endl;
	cout << "	|       [4]----�鿴��ʷ����        |" << endl;
	cout << "	|       [5]----��������������      |" << endl;
	cout << "	|       [6]----�ӱ��ص�������      |" << endl;
	cout << "	|       [0]----�˳�ϵͳ            |" << endl;
	cout << "	+----------------------------------+" << endl;
	for (int i = 0; i < 52; i++) cout << "*"; cout << endl;
	cout << "��ѡ����:";
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