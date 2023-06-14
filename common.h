//
// Created by qianzhikang on 2023/6/14.
//

#ifndef ACCOUNT_BOOK_COMMON_H
#define ACCOUNT_BOOK_COMMON_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#define INCOME "收入"
#define EXPAND "支出"
#define FILENAME "/Users/qianzhikang/Code/C++/account-book/account-book.txt"

// 绘制主菜单
void showMainMenu();
// 绘制账单菜单
void showAccountingMenu();
// 查询菜单
void showQueryMenu();

// 读取键盘输入
char readMenuSelection(int option);
// 读取退出标记
char readQuitConfirm();
// 读取输入金额
int readAmount();

#endif //ACCOUNT_BOOK_COMMON_H
