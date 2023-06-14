//
// Created by qianzhikang on 2023/6/14.
//
#include "common.h"
#include "account_item.h"

void loadDataFromFile(vector<AccountItem> &items) {
    ifstream input(FILENAME);
    AccountItem item;
    string word;
    while (input >> item.itemType >> item.account >> item.detail) {
        items.push_back(item);
    }
    input.close();
}

// 记账操作
void accounting(vector<AccountItem> &items) {
    // 读取键盘选择，并做合法性校验
    char key = readMenuSelection(3);
    switch (key) {
        // 1:收入
        case '1':
            income(items);
            break;
            //2:支出
        case '2':
            expand(items);
            break;
            // 3:退出
        default:
            break;
    }
    cout << endl;
}


// 收入
void income(vector<AccountItem> &items) {
    // 新建一个AccountItem对象
    AccountItem item;
    // 类型为收入
    item.itemType = INCOME;
    // 交互，输入金额
    cout << "\n本次收入金额为：";
    // 读取键盘输入金额并校验
    item.account = readAmount();
    // 交互输入备注
    cout << "\n填写备注：";
    getline(cin, item.detail);
    // 添加到vector
    items.push_back(item);
    // 写入文件实现持久化
    insertIntoFile(item);
    // 显示成功信息
    cout << "\n-------------记账成功！-----------------" << endl;
    cout << "\n请按回车返回主菜单..." << endl;
    string line;
    getline(cin, line);
}

// 支出
void expand(vector<AccountItem> &items) {
    // 新建一个AccountItem对象
    AccountItem item;
    // 类型为支出
    item.itemType = EXPAND;
    // 交互，输入金额
    cout << "\n本次支出金额为：";
    // 读取键盘输入金额并校验
    item.account = -readAmount();
    // 交互输入备注
    cout << "\n填写备注：";
    getline(cin, item.detail);
    // 添加到vector
    items.push_back(item);
    // 写入文件实现持久化
    insertIntoFile(item);
    // 显示成功信息
    cout << "\n-------------记账成功！-----------------" << endl;
    cout << "\n请按回车返回主菜单..." << endl;
    string line;
    getline(cin, line);
}


// 插入账目信息到文件中
void insertIntoFile(const AccountItem &item) {
    // 创建一个 ofstream 对象, ios::out | ios::app 以追加方式进行写入
    ofstream output(FILENAME, ios::out | ios::app);
    output << item.itemType << "\t" << item.account << "\t" << item.detail << endl;
    output.close();
}


// --------------------------- 查询 ------------------------------
// 查询操作
void query(const vector<AccountItem> &items) {
    // 读取键盘选择，并做合法性校验
    char key = readMenuSelection(4);
    switch (key) {
        // 1:查询所有账目，统计总收支
        case '1':
            queryItems(items);
            break;
            //2:查询收入，统计总收入
        case '2':
            queryItems(items, INCOME);
            break;
            // 3:查询支出，统计总支出
        case '3':
            queryItems(items, EXPAND);
            break;
        default:
            break;
    }
    cout << endl;
}


// 查询账目功能函数
void queryItems(const vector<AccountItem> &items) {
    cout << "-----------------查询结果-------------------------" << endl;
    cout << "\n 类型\t\t金额\t\t备注\n" << endl;
    // 遍历账目，统计总收支
    int total = 0;
    for (auto item: items) {
        printItem(item);
        total += item.account;
    }
    cout << "===================================================\n" << endl;
    cout << "总收支：" << total << endl;
    cout << "\n请按回车返回主菜单..." << endl;
    string line;
    getline(cin, line);
}

// 查询收入/支出
void queryItems(const vector<AccountItem> &items, const string &type) {
    cout << "-----------------查询结果-------------------------" << endl;
    cout << "\n 类型\t\t金额\t\t备注\n" << endl;
    // 遍历账目，统计总收入/支出
    int total = 0;
    for (auto item: items) {
        if (item.itemType == type){
            printItem(item);
            total += item.account;
        }
    }
    cout << "===================================================\n" << endl;
    cout << ((type == INCOME) ? "总收入":"总支出：") << total << endl;
    cout << "\n请按回车返回主菜单..." << endl;
    string line;
    getline(cin, line);
}


// 打印输出一条账目信息
void printItem(const AccountItem &item) {
    cout << item.itemType << "\t\t" << item.account << "\t\t" << item.detail << endl;
}