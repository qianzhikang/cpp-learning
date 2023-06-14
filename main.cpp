#include "common.h"
#include "account_item.h"


int main() {
    // 1. 加载文件中的账目数据
    vector<AccountItem> items;
    loadDataFromFile(items);

    // 是否退出标志
    bool quit = false;
    while (!quit) {
        // 2. 显示主菜单
        showMainMenu();

        // 3. 读取键盘选择，并做合法性校验
        char key = readMenuSelection(3);


        switch (key) {
            // 1:记账
            case '1':
                showAccountingMenu();
                accounting(items);
                break;
                //2:查询账单
            case '2':
                showQueryMenu();
                query(items);
                break;
                // 3:退出
            case '3':
                cout << "\n确认退出？（Y/N）：";
                if (readQuitConfirm() == 'Y') {
                    quit = true;
                }
                break;
            default:
                break;
        }
        cout << endl;
    }

    return 0;
}
