#include "receipt.h"

using namespace std;

bool Receipt::receiptAsk() {
    int answer;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n영수증을 출력하시겠습니까?\n" << endl;
    cout << "1. 예" << endl;
    cout << "2. 아니오" << endl;
    cout << "\n------------------------------------------------------------" << endl;
    cout << "입력 : ";
    cin >> answer;
    cout << "------------------------------------------------------------" << endl;
    if(answer == 1) return true;
    else return false;
}

void Receipt::receiptForm(int price) {
    cout << "\n영수증이 출력됩니다.\n" << endl;
    cout << "----------------\n" << endl;
    cout << "     영수증\n\n" << endl;
    cout << "   금액 " << price << "원\n" << endl;
    cout << "----------------\n" << endl;
}