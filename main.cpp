#include"books.h"
#include"customer.h"
#include"order.h"
#include"menu.h"
#include"custom_vector.h"

int main()
{
	book bk1("0001", "JAVA从入门到女装", "女装大师", "神乐坂出版社", 41);
	book bk2("0002", "C++从入门到放弃", "大锤", "富土康出版社", 36);
	book bk3("0003", "GO从入门到开源", "某bilibili员工", "AcFun出版社", 22.33);
	book bk4("0004", "高数从入门到入土", "元首", "小达人出版社", 43);
	book bk5("0005", "MySQL从入门到删库", "Administrator", "删库进化人出版社", 32);
	vector_books.push_back(bk1);
	vector_books.push_back(bk2);
	vector_books.push_back(bk3);
	vector_books.push_back(bk4);
	vector_books.push_back(bk5);
	normal_buyer buyer1("元首", "0001", "柏林总理府");
	normal_buyer buyer2("大胡子", "0002", "克里姆林宫");
	member buyer3("常凯申", "0003", 1, "重庆");
	member buyer4("隆美尔", "0004", 2, "北非");
	super_member buyer5("张三", "0005", 0.5, "上海");
	super_member buyer6("李四", "0006", 0.5, "北京");
	vector_buyers.push_back(&buyer1);
	vector_buyers.push_back(&buyer2);
	vector_buyers.push_back(&buyer3);
	vector_buyers.push_back(&buyer4);
	vector_buyers.push_back(&buyer5);
	vector_buyers.push_back(&buyer6);
	menu();		//进入主菜单
	return 0;
}