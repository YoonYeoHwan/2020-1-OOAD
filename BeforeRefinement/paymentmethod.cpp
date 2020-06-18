#include "paymentmethod.h"
#include "receipt.h"

using namespace std;

void PaymentMethod::paymentCard(int price) {
    cout << "\n카드를 투입해주세요.\n" << endl;
    cout << "------------------------------------------------------------" << endl;
    sleep(2);
    cout << "\n카드가 투입되었습니다.\n" << endl;
    cout << "결제중...\n" << endl;
    sleep(2);
    cout << price << "원 결제가 완료되었습니다.\n" << endl;
    Receipt receipt;
    if(receipt.receiptAsk()) receipt.receiptForm(price);
}

void PaymentMethod::paymentCash(int price) {
    int input;
    cout << "투입할 금액을 입력해주세요. : ";
    cin >> input;
    cout << "\n결제 진행 중..." << endl;
    sleep(2);
    while(true) {
        if(price > input) {
            cout << "\n";
            cout << price - input << "원이 부족합니다.\n" << endl;
            cout << "투입할 금액을 입력해주세요. : ";
            int tmp;
            cin >> tmp;
            input += tmp;
        }
        if(price == input) {
            sleep(2);
            cout << '\n' << price << "원 결제가 완료되었습니다.\n" << endl;
            break;
        }
        if(price < input) {
            sleep(2);
            cout << '\n' << price << "원 결제가 완료되었습니다.\n" << endl;
            cout << "거스름돈 " << input - price << "원이 반환됩니다.\n" << endl;
            break;
        } 
        sleep(2);
    }
    Receipt receipt;
    if(receipt.receiptAsk()) receipt.receiptForm(price);
}