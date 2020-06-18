#include "ModeController.h"
#include "UserMode.h"
#include "AdminCheck.h"
#include "AdminMode.h"

using namespace std;

void ModeController::modeSelect(int mode) {
    if(mode == 1) userModeSelect();
    else if(mode == 2) adminModeSelect();
}

void ModeController::adminModeSelect() {
    AdminCheck adminCheck;
    AdminMode adminMode;
    if(adminCheck.checkAdmin()) {
        int mode;
        cout << "\n원하시는 작업을 선택해주세요.\n" << endl;
        cout << "1. 매출 확인" << endl;
        cout << "2. 재고 확인" << endl;
        cout << "3. 마스크 확인" << endl;
        cout << "4. 재고 주문" << endl;
        cout << "5. 마스크 주문\n" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "입력 : ";
        cin >> mode;
        cout << "------------------------------------------------------------\n" << endl;

        if(mode == 1) adminMode.checkSales();
        else if(mode == 2) adminMode.checkStock();
        else if(mode == 3) adminMode.checkMask();
        else if(mode == 4) adminMode.orderStock();
        else if(mode == 5) adminMode.orderMask();
    }
    else return;
}

void ModeController::userModeSelect() {
    UserMode userMode;

    int mode;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n원하시는 작업을 선택해주세요.\n" << endl;
    cout << "1. 처방전 제출" << endl;
    cout << "2. 의약품 구매" << endl;
    cout << "3. 공적 마스크 구매" << endl;
    cout << "\n------------------------------------------------------------" << endl;
    cout << "입력 : ";
    cin >> mode;

    if(mode == 1) userMode.buyWithPrescription();
    else if(mode == 2) userMode.buyMedicine();
    else if(mode == 3) userMode.buyMask();
}