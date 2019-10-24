#include"books.h"

book::book()
{
	book_ID = "";
	book_name = "";
	author = "";
	publishing = "";
	price = 0;
}

book::book(string b_id, string b_n, string au, string pu, double pr)
{
	book_ID = b_id;
	book_name = b_n;
	author = au;
	publishing = pu;
	price = pr;
}

void book::display()
{
	cout << "���: " << book_ID << endl;
	cout << "����: " << book_name << endl;
	cout << "����: " << author << endl;
	cout << "������: " << publishing << endl;
	cout << "����: " << price << endl;
}

void book::display_mini()
{
	cout << book_ID << '\t' << book_name << '\t' << author << '\t' << publishing << '\t' << price << endl;
}

string book::getbook_ID()
{
	return book_ID;
}

string book::getbook_name()
{
	return book_name;
}

string book::getauthor()
{
	return author;
}

string book::getpublishing()
{
	return publishing;
}

double book::getprice()
{
	return price;
}

bool less_sort_ID(book const& bk1, book const& bk2)
{
	return bk1.book_ID < bk2.book_ID;
}
bool less_sort_name(book const& bk1, book const& bk2)
{
	return bk1.book_name < bk2.book_name;
}
bool less_sort_price(book const& bk1, book const& bk2)
{
	return bk1.price < bk2.price;
}