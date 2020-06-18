#include "payment.h"
#include "paymentmethod.h"
#include "sales.h"

using namespace std;

void Payment::payment(int price) {
    int paymentMode;
    cout << "\n------------------------------------------------------------\n" << endl;
    cout << "결제하실 금액은 " << price << " 원입니다." << endl;
    cout << "결제 방법을 선택해주세요.\n" << endl;
    cout << "1. 카드 결제" << endl;
    cout << "2. 현금 결제" << endl;
    cout << "\n------------------------------------------------------------" << endl;
    cout << "입력 : ";
    cin >> paymentMode;
    cout << "------------------------------------------------------------" << endl;

    PaymentMethod paymentmethod;
    if(paymentMode == 1) paymentmethod.paymentCard(price);
    else if(paymentMode == 2) paymentmethod.paymentCash(price);

    Sales s;
    s.sales(price);
}