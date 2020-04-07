#include "adminmode.h"
#include "sales.h"
#include "stockmanage.h"

using namespace std;

void Admin::admin() {
    string password;
    string inputPassword;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n관리자 계정에 로그인하기 위해서는 비밀번호를 입력해주십시오.\n" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "입력 : ";
    cin >> inputPassword;
    cout << "------------------------------------------------------------" << endl;
    fstream openFile;
    openFile.open("admin.txt");
    getline(openFile, password);
    if(password.compare(inputPassword) == 0) {
        cout << "\n관리자 계정에 로그인 되셨습니다.\n" << endl;
        adminMenu();
    }
    else {
        cout << "\n비밀번호가 일치하지 않습니다.\n" << endl;
    }
}

void Admin::adminMenu() {
    int mode;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n원하시는 작업을 선택해주세요.\n" << endl;
    cout << "1. 매출 확인" << endl;
    cout << "2. 재고 확인" << endl;
    cout << "3. 재고 주문" << endl;
    cout << "4. 제품 추가" << endl;
    cout << "5. 마스크 주문\n" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "입력 : ";
    cin >> mode;
    cout << "------------------------------------------------------------\n" << endl;
    adminMenuSelect(mode);
}

void Admin::adminMenuSelect(int mode) {
    Sales s;
    StockManage SM;
    if(mode == 1) s.checkSales();
    else if(mode == 2) SM.checkStock();
    else if(mode == 3) SM.orderStock();
    else if(mode == 4) addNewProduct();
    else if(mode == 5) SM.orderMask();
}

void Admin::addNewProduct() {
        string productName;
    int productPrice;
    int productNumber;
    cout << "새로 등록하고 싶은 물건의 품명과 가격과 초기 재고를 입력해주세요.\n" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "품명 : ";
    cin >> productName;
    cout << "가격 : ";
    cin >> productPrice;
    cout << "수량 : ";
    cin >> productNumber;
    cout << "------------------------------------------------------------" << endl;

    string productsName[10];
    int productsPrice[10];
    int productsCount[10];

    for(int j=0; j<10; j++) {
        productsName[j] = ' ';
        productsPrice[j] = 0;
        productsCount[j] = 0;
    }

    FILE *file = fopen("products.txt", "r");
    int counter = 0;

    while(1) {
        char tmpProductsName[20];
        int tmpPrice;
        int tmpCounter;
        fscanf(file, "%s %d %d", tmpProductsName, &tmpPrice, &tmpCounter);
        if(feof(file)) break;
        productsName[counter] = tmpProductsName;
        productsPrice[counter] = tmpPrice;
        productsCount[counter] = tmpCounter;
        counter++;
        cout << counter << ". " << tmpProductsName <<  endl;
        
    }
    fclose(file);
    productsName[counter] = productName;
    productsPrice[counter] = productPrice;
    productsCount[counter] = productNumber;

    FILE *wFile = fopen("products.txt", "w");
    for(int i=0; i<=counter; i++) {
        string strsum = productsName[i] + " " + to_string(productsPrice[i]) + " " + to_string(productsCount[i]);
        const char* ch = strsum.c_str();
        fputs(ch, wFile);
        fputs("\n", wFile);
    }
    fclose(wFile);

    cout << "\n상품 등록을 정상적으로 완료하였습니다.\n" << endl;
}