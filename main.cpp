#include"books.h"
#include"customer.h"
#include"order.h"
#include"menu.h"
#include"custom_vector.h"

int main()
{
	book bk1("0001", "JAVA�����ŵ�Ůװ", "Ůװ��ʦ", "�����������", 41);
	book bk2("0002", "C++�����ŵ�����", "��", "������������", 36);
	book bk3("0003", "GO�����ŵ���Դ", "ĳbilibiliԱ��", "AcFun������", 22.33);
	book bk4("0004", "���������ŵ�����", "Ԫ��", "С���˳�����", 43);
	book bk5("0005", "MySQL�����ŵ�ɾ��", "Administrator", "ɾ������˳�����", 32);
	vector_books.push_back(bk1);
	vector_books.push_back(bk2);
	vector_books.push_back(bk3);
	vector_books.push_back(bk4);
	vector_books.push_back(bk5);
	normal_buyer buyer1("Ԫ��", "0001", "��������");
	normal_buyer buyer2("�����", "0002", "����ķ�ֹ�");
	member buyer3("������", "0003", 1, "����");
	member buyer4("¡����", "0004", 2, "����");
	super_member buyer5("����", "0005", 0.5, "�Ϻ�");
	super_member buyer6("����", "0006", 0.5, "����");
	vector_buyers.push_back(&buyer1);
	vector_buyers.push_back(&buyer2);
	vector_buyers.push_back(&buyer3);
	vector_buyers.push_back(&buyer4);
	vector_buyers.push_back(&buyer5);
	vector_buyers.push_back(&buyer6);
	menu();		//�������˵�
	return 0;
}