//
// Created by qianzhikang on 2023/6/14.
//

#include "common.h"

// 绘制主菜单的函数
void showMainMenu(){
    system("clear");
    cout << "-------------------------------------------------------" << endl;
    cout << "|===============  欢迎使用记账簿  ====================|" << endl;
    cout << "|                                                     |" << endl;
    cout << "|***************    1 记  账      ********************|" << endl;
    cout << "|***************    2 查  询      ********************|" << endl;
    cout << "|***************    3 退  出      ********************|" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << "\n请选择(1 - 3)：";
}

void showAccountingMenu(){
    system("clear");
    cout << "-------------------------------------------------------" << endl;
    cout << "|===============   选择记账种类   ====================|" << endl;
    cout << "|                                                     |" << endl;
    cout << "|***************    1 收  入      ********************|" << endl;
    cout << "|***************    2 支  出      ********************|" << endl;
    cout << "|***************    3 返回主菜单  ********************|" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << "\n请选择(1 - 3)：";
}
void showQueryMenu()
{
    cout << "-------------------------------------------------------" << endl;
    cout << "|===============   选择查询条件   ====================|" << endl;
    cout << "|                                                     |" << endl;
    cout << "|***************  1 统计所有账目  ********************|" << endl;
    cout << "|***************  2 统 计 收 入   ********************|" << endl;
    cout << "|***************  3 统 计 支 出   ********************|" << endl;
    cout << "|***************  4 返回主菜单    ********************|" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << "\n请选择(1 - 4)：";
}
