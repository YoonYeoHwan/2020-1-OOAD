#include "UI.h"
#include "ModeController.h"

using namespace std;

void UI::startProgram() {
    int mode;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n\n\t\t     Post System Start\n\n" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n원하시는 작업을 선택해주세요.\n" << endl;
    cout << "1. User Mode" << endl;
    cout << "2. Admin Mode" << endl;
    cout << "\n------------------------------------------------------------" << endl;
    cout << "입력 : ";
    cin >> mode;
    
    ModeController modeController;
    modeController.modeSelect(mode);

    cout << "\n\t\t   프로그램이 종료됩니다.\n" << endl;
    cout << "------------------------------------------------------------" << endl;
}

void UI::printReceipt(int price) {
    cout << "\n영수증이 출력됩니다.\n" << endl;
    cout << "----------------\n" << endl;
    cout << "     영수증\n\n" << endl;
    cout << "   금액 " << price << "원\n" << endl;
    cout << "----------------\n\n" << endl;
    cout << "------------------------------------------------------------" << endl;
}