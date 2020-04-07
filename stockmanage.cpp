#include "stockmanage.h"

using namespace std;

void StockManage::checkStock() {
    FILE *file1 = fopen("products.txt", "r");
    int counter = 0;
    while(1) {
        char tmpProductsName[20];
        int tmpPrice;
        int tmpCounter;
        fscanf(file1, "%s %d %d", tmpProductsName, &tmpPrice, &tmpCounter);
        if(feof(file1)) break;
        counter++;
        cout << counter << ". " << tmpProductsName << " " << tmpCounter << "개" << endl;
    }
    fclose(file1);
}

void StockManage::orderStock() {
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

    FILE *wFile = fopen("products.txt", "w");
    for(int i=0; i<counter; i++) {
        if(ProductNumber - 1 == i) {
            productsCount[i]+=count;
        }
        string strsum = productsName[i] + " " + to_string(productsPrice[i]) + " " + to_string(productsCount[i]);
        const char* ch = strsum.c_str();
        fputs(ch, wFile);
        fputs("\n", wFile);
    }
    fclose(wFile);

    cout << "\n주문이 정상적으로 완료되었습니다." << endl;
}

void StockManage::stockCount(int number) {
    string productsName[10];
    int productsPrice[10];
    int productsCount[10];

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
    }
    fclose(file);

    FILE *wFile = fopen("products.txt", "w");
    for(int i=0; i<counter; i++) {
        if(number == i) {
            productsCount[i]--;
        }
        string strsum = productsName[i] + " " + to_string(productsPrice[i]) + " " + to_string(productsCount[i]);
        const char* ch = strsum.c_str();
        fputs(ch, wFile);
        fputs("\n", wFile);
    }
    fclose(wFile);
}

void StockManage::maskCount(int number) {
    FILE *file;
    file = fopen("mask.txt", "w");
    string strtmp = to_string(number);
    const char* ch = strtmp.c_str();
    fputs(ch, file);
    fclose(file);
}

void StockManage::orderMask() {
    FILE *file = fopen("mask.txt", "r");
    int tmp;
    fscanf(file, "%d", &tmp);
    tmp += 10;
    fclose(file);

    file = fopen("mask.txt", "w");
    string strtmp = to_string(tmp);
    const char* ch = strtmp.c_str();
    fputs(ch, file);
    fclose(file);
    
    cout << "마스크 주문이 정상적으로 완료되었습니다." << endl;
}