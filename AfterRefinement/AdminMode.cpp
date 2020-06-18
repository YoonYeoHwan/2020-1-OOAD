#include "AdminMode.h"
#include "SalesAdaptor.h"
#include "StockAdaptor.h"

using namespace std;

void AdminMode::orderStock() {

    cout << "주문하고 싶은 품목과 개수를 선택해주세요.\n" << endl;
    cout << "------------------------------------------------------------\n" << endl;

    int ProductNumber;
    int count;

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

    cout << "\n------------------------------------------------------------" << endl;
    cout << "상품 : ";
    cin >> ProductNumber;
    cout << "수량 : ";
    cin >> count;
    cout << "------------------------------------------------------------" << endl;

    vector<pair<int, int>> v;
    StockAdaptor STA;
    STA.StockChange(ProductNumber, count, v);

    cout << "\n주문이 정상적으로 완료되었습니다." << endl;
    cout << "\n------------------------------------------------------------" << endl;

}

void AdminMode::orderMask() {
    StockAdaptor STA;
    STA.MaskChange();
    cout << "마스크 주문이 정상적으로 완료되었습니다." << endl;
    cout << "\n------------------------------------------------------------" << endl;
}

void AdminMode::checkStock() {
    FILE *file = fopen("products.txt", "r");
    int counter = 0;
    while(1) {
        char tmpProductsName[20];
        int tmpPrice;
        int tmpCounter;
        fscanf(file, "%s %d %d", tmpProductsName, &tmpPrice, &tmpCounter);
        if(feof(file)) break;
        counter++;
        cout << counter << ". " << tmpProductsName << " " << tmpCounter << "개" << endl;
    }
    fclose(file);
}

void AdminMode::checkMask() {
    StockAdaptor STA;
    cout << "현재 남아있는 마스크의 재고는 " << STA.getMask().getMask() << "개 입니다." << endl;
}

void AdminMode::checkSales() {
    SalesAdaptor SA;
    cout << "현재까지의 매출은 총 " << SA.getSales() << "원입니다.\n" << endl;
}