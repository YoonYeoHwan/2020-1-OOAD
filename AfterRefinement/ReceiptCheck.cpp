#include "ReceiptCheck.h"

using namespace std;

bool ReceiptCheck::wantReceipt() {
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