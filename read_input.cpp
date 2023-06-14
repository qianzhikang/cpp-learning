//
// Created by qianzhikang on 2023/6/14.
//
#include "common.h"

// 读取键盘输入
char readMenuSelection(int option) {
    string str;
    while (true) {
        // 读取一行赋值给str
        getline(cin, str);
        if (str.size() != 1 || str[0] - '0' <= 0 || str[0] - '0' > option) {
            cout << "输入非法的选项！请重新输入：" << endl;
        } else {
            break;
        }
    }
    return str[0];
}


// 读取退出标记
char readQuitConfirm() {
    string str;
    while (true) {
        // 读取一行赋值给str
        getline(cin, str);
        if (str.size() != 1 || toupper(str[0]) != 'Y' && toupper(str[0]) != 'N') {
            cout << "输入非法的选项！请重新输入(Y/N)：" << endl;
        } else {
            break;
        }
    }
    return toupper(str[0]);
}

// 键盘输入金额数
int readAmount() {
    string str;
    while (true) {
        // 读取一行赋值给str
        getline(cin, str);
        try {
            // 合法性校验 string to int
            return stoi(str);
        } catch (invalid_argument e) {
            cout << "输入错误，请正确输入数字：";
        }
    }
}