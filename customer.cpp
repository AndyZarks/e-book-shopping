#include"customer.h"

buyer::buyer()							//�޲ι��캯��
{
	name = "";
	buyerID = "0000";
	adress = "";
}

buyer::buyer(string n, string b, string a)	//���������캯��
{
	name = n;
	buyerID = b;
	adress = a;
}

string buyer::getadress()				//��ȡ��ַ
{
	return adress;
}

void buyer::setadress()					//���õ�ַ
{
	cout << "�������µĵ�ַ" << endl;
	string tempadress;
	cin >> tempadress;
	adress = tempadress;
}

string buyer::getname()					//��ȡ����
{
	return name;
}

void buyer::setname()					//��������
{
	cout << "�������µ�����:" << endl;
	string tempname;
	cin >> tempname;
	name = tempname;

}

string buyer::getid()						//��ȡID
{
	return buyerID;
}

void buyer::setid()						//����ID
{
	cout << "�������µ�ID:" << endl;
	string tempID;
	cin >> tempID;
	buyerID = tempID;
}

void member::display()					//��ʾ��Ա��Ϣ
{
	cout << "������" << name << endl;
	cout << "�û�ID��" << buyerID << endl;
	cout << "��ַ:" << adress << endl;
	cout << "���ǻ�Ա������Ϊ: " << member_level << endl;
}

double member::getdiscount()		//��ȡ��Ա�ۿ���
{
	return member_level * 0.9;
}

void super_member::display()			//��ʾ�����Ϣ
{
	cout << "������" << name << endl;
	cout << "�û���" << buyerID << endl;
	cout << "��ַ:" << adress << endl;
	cout << "�𾴵Ĺ�������ڱ�վ�������" << discount_rate * 100 << "%" << "���Ż�" << endl;
}

double super_member::getdiscount()	//��ȡ����ۿ���
{
	return discount_rate;
}

void normal_buyer::display()			//��ʾ��ͨ�û���Ϣ
{
	cout << "������������" << name << endl;
	cout << "�����˱�ţ�" << buyerID << endl;
	cout << "������Ϊ��ͨ�û�" << endl;
	cout << "��ַ:" << adress << endl;
}

double normal_buyer::getdiscount()	//��ȡ��ͨ�˿��ۿ���
{
	return 1;
}