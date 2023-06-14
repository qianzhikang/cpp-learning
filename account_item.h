//
// Created by qianzhikang on 2023/6/14.
//

#ifndef ACCOUNT_BOOK_ACCOUNT_ITEM_H
#define ACCOUNT_BOOK_ACCOUNT_ITEM_H

#include "common.h"

struct AccountItem {
    // 类型
    string itemType;
    // 账户
    int account;
    // 备注
    string detail;
};

/** 针对账目数据进行操作的函数声明 */
// 从文件读取账单信息
void loadDataFromFile(vector<AccountItem> &);

// 记账操作
void accounting(vector<AccountItem> &);

// 收入
void income(vector<AccountItem> &);

// 支出
void expand(vector<AccountItem> &);

// 将记账操作持久化到文件中
void insertIntoFile(const AccountItem &);

// 查询操作
void query(const vector<AccountItem> &);

// 查询所有条目信息
void queryItems(const vector<AccountItem> &);

// 查询收入/支出
void queryItems(const vector<AccountItem> &, const string &);

// 打印账单信息
void printItem(const AccountItem &);


#endif //ACCOUNT_BOOK_ACCOUNT_ITEM_H
