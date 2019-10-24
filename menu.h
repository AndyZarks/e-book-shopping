#pragma once
#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include"books.h"
#include"customer.h"
#include"order.h"
#include"custom_vector.h"
using namespace std;

void back();			//返回菜单或退出
void buy_book();		//买书
void search_book();		//查书
void edit_info();		//添加或修改用户信息
void order_history();	//订单历史
void menu();			//主菜单