#include "Card.h"

using namespace std;

void Card::requestPayment(int price) {
    cout << "\n카드를 투입해주세요.\n" << endl;
    cout << "------------------------------------------------------------" << endl;
    sleep(2);
    cout << "\n카드가 투입되었습니다.\n" << endl;
    cout << "결제중...\n" << endl;
    sleep(2);
    cout << price << "원 결제가 완료되었습니다.\n" << endl;
}