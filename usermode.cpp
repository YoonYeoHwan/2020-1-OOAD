#include "usermode.h"
#include "payment.h"
#include "stockmanage.h"
#include "log.h"

using namespace std;

void Usermode::prescription() {
    cout << "------------------------------------------------------------" << endl;
    cout << "\n처방전을 제출해주세요.\n" << endl;
    cout << "------------------------------------------------------------" << endl;
    sleep(1);
    cout << "\n처방전을 받았습니다. 잠시만 기다려주세요.\n" << endl;
    srand((unsigned int)time(NULL));
    int price = rand();
    price = price % 100 * 100;
    sleep(1);
    cout << "약 제조 중...\n" << endl;
    sleep(2);
    cout << "약 제조가 완료되었습니다.\n" << endl;
    cout << "결제 화면으로 이동합니다.\n" << endl;
    cout << "------------------------------------------------------------\n" << endl;
    
    Payment p;
    p.payment(price);

    Log l;
    l.log(price, "처방전");
}

void Usermode::buyMedicine() {
    cout << "------------------------------------------------------------\n" << endl;
    cout << "구매하실 의약품을 선택해주세요.\n" << endl;

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
        cout << counter << ". " << tmpProductsName << " " << tmpPrice << "원 " << endl;
        
    }
    fclose(file);

    int productNumber;
    cout << "\n------------------------------------------------------------" << endl;
    cout << "입력 : ";
    cin >> productNumber;
    cout << "------------------------------------------------------------\n" << endl;
    if(productsCount[productNumber - 1] > 0) {
        cout << productsName[productNumber - 1] << "를 선택하셨습니다." << endl;
        cout << "결제 화면으로 이동합니다." << endl;
        Payment p;
        p.payment(productsPrice[productNumber - 1]);
    }
    else {
        cout << "해당 상품은 품절되었습니다. 초기 화면으로 이동합니다." << endl;
        return;
    }

    StockManage SM;
    SM.stockCount(productNumber - 1);

    Log l;
    l.log(productsPrice[productNumber - 1], productsName[productNumber - 1]);
}

void Usermode::buyMask() {
    cout << "------------------------------------------------------------\n" << endl;
    string str;
    fstream openFile;
    openFile.open("mask.txt");
    getline(openFile, str);
    int number = stoi(str);

    if(number == 0) {
        cout << "죄송합니다. 현재 마스크는 품절입니다." << endl;
    }
    else {
        string week[7] = {"일", "월", "화", "수", "목", "금", "토"};
        time_t timer;
        struct tm *t;

        timer = time(NULL);
        t = localtime(&timer);
        if(t->tm_wday == 0 || t->tm_wday == 6) {
            cout << "오늘은 " << week[t->tm_wday] << "요일 입니다. 모든 사람이 마스크를 구매할 수 있습니다.\n" << endl;
        }
        else {
            int personalID;
            cout << "오늘은 " << week[t->tm_wday] << "요일 입니다. 출생년도 끝자리가 " << t->tm_wday << " " << (t->tm_wday + 5) % 10  << " 인 사람만 마스크를 구매할 수 있습니다.\n" << endl;
            cout << "주민등록번호 앞자리 6자리를 입력해주세요.\n" << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << "입력 : ";
            cin >> personalID;
            cout << "------------------------------------------------------------\n" << endl;
            if(personalID / 10000 % 10 == t->tm_wday || personalID / 10000 % 10 == (t->tm_wday + 5) % 10) {
                cout << "오늘 날짜의 마스크 구매 대상자가 맞습니다.\n" << endl;
            }
            else {
                cout << "죄송합니다. 오늘 날짜의 마스크 구매 대상자가 아닙니다.\n" << endl;
                return;
            }
        }
        cout << "결제 화면으로 이동합니다." << endl;

        Payment p;
        p.payment(3000);

        StockManage SM;
        SM.maskCount(--number);

        Log l;
        l.log(3000, "공적마스크");
    }
}