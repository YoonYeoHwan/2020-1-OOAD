#include "ui.h"
#include "usermode.h"
#include "adminmode.h"

using namespace std;

void UI::startProgram() {
    int mode;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n\n\t\t     Post System Start\n\n" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n원하시는 작업을 선택해주세요.\n" << endl;
    cout << "1. 처방전 제출" << endl;
    cout << "2. 의약품 구매" << endl;
    cout << "3. 공적 마스크 구매" << endl;
    cout << "4. 관리자" << endl;
    cout << "\n------------------------------------------------------------" << endl;
    cout << "입력 : ";
    cin >> mode;
    modeSelect(mode);
    cout << "\n\n" << endl;
}

void UI::modeSelect(int mode) {
    Usermode user;
    Admin admin;
    if(mode == 1) user.prescription();
    else if(mode == 2) user.buyMedicine();
    else if(mode == 3) user.buyMask();
    else if(mode == 4) admin.admin();
}