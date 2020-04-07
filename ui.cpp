#include "ui.h"

using namespace std;

void UI::startProgram() {
    int mode;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n\n\t\t     Post System Start\n\n" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n원하시는 작업을 선택해주세요.\n" << endl;
    cout << "1. 처방전 제출" << endl;
    cout << "2. 의약품 구매" << endl;
    cout << "3. 공적 마스크 구매" << endl;
    cout << "4. 관리자" << endl;
    cout << "\n------------------------------------------------------------" << endl;
    cout << "입력 : ";
    cin >> mode;
    modeSelect(mode);
    cout << "\n------------------------------------------------------------" << endl;
}

void UI::modeSelect(int mode) {
    if(mode == 1) prescription();
    else if(mode == 2) buyMedicne();
    else if(mode == 3) buyMask();
    else if(mode == 4) admin();
}

void UI::prescription() {
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
    payment(price);
}

void UI::buyMedicne() {
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
        payment(productsPrice[productNumber - 1]);
    }
    else {
        cout << "해당 상품은 품절되었습니다. 초기 화면으로 이동합니다." << endl;
    }
    stockCount(--productNumber);
}

void UI::buyMask() {
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
            if(personalID / 100 % 10 == t->tm_wday or personalID / 100 % 10 == (t->tm_wday + 5) % 10) {
                cout << "오늘 날짜의 마스크 구매 대상자가 맞습니다.\n" << endl;
            }
            else {
                cout << "죄송합니다. 오늘 날짜의 마스크 구매 대상자가 아닙니다.\n" << endl;
                return;
            }
        }
        cout << "결제 화면으로 이동합니다." << endl;
        payment(3000);
        maskCount(--number);
    }
}

void UI::payment(int price) {
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
    if(paymentMode == 1) paymentCard(price);
    else if(paymentMode == 2) paymentCash(price);
    sales(price);
}

void UI::stockCount(int number) {
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

void UI::maskCount(int number) {
    FILE *file;
    file = fopen("mask.txt", "w");
    string strtmp = to_string(number);
    const char* ch = strtmp.c_str();
    fputs(ch, file);
    fclose(file);
}

void UI::sales(int price) {
    string str;
    fstream openFile;
    openFile.open("sales.txt");
    getline(openFile, str);
    int sales = stoi(str);
    sales += price;
    FILE *file;
    file = fopen("sales.txt", "w");
    string strtmp = to_string(sales);
    const char* ch = strtmp.c_str();
    fputs(ch, file);
    fclose(file);
}

void UI::paymentCard(int price) {
    cout << "\n카드를 투입해주세요.\n" << endl;
    cout << "------------------------------------------------------------" << endl;
    sleep(2);
    cout << "\n카드가 투입되었습니다.\n" << endl;
    cout << "결제중...\n" << endl;
    sleep(2);
    cout << price << "원 결제가 완료되었습니다.\n" << endl;
    if(receiptAsk()) receipt(price);
}

void UI::paymentCash(int price) {
    int input;
    cout << "투입할 금액을 입력해주세요. : ";
    cin >> input;
    while(true) {
        if(price > input) {
            cout << price - input << "원이 부족합니다.\n" << endl;
            cout << "투입할 금액을 입력해주세요. : ";
            int tmp;
            cin >> tmp;
            input += tmp;
        }
        if(price == input) {
            cout << '\n' << price << "원 결제가 완료되었습니다.\n" << endl;
            break;
        }
        if(price < input) {
            cout << '\n' << price << "원 결제가 완료되었습니다." << endl;
            cout << "거스름돈 " << input - price << "원이 반환됩니다.\n" << endl;
            break;
        } 
    }
    if(receiptAsk()) receipt(price);
}

bool UI::receiptAsk() {
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

void UI::receipt(int price) {
    cout << "\n영수증이 출력됩니다.\n" << endl;
    cout << "----------------\n" << endl;
    cout << "     영수증\n\n" << endl;
    cout << "   금액 " << price << "원\n" << endl;
    cout << "----------------\n" << endl;
}

void UI::admin() {
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

void UI::adminMenu() {
    int mode;
    cout << "------------------------------------------------------------" << endl;
    cout << "\n원하시는 작업을 선택해주세요.\n" << endl;
    cout << "1. 매출 확인" << endl;
    cout << "2. 재고 확인" << endl;
    cout << "3. 재고 주문" << endl;
    cout << "4. 제품 추가\n" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "입력 : ";
    cin >> mode;
    cout << "------------------------------------------------------------\n" << endl;
    adminModeSelect(mode);
}

void UI::adminModeSelect(int mode) {
    if(mode == 1) checkSales();
    else if(mode == 2) checkStock();
    else if(mode == 3) orderStock();
    else if(mode == 4) addNewProduct();
}

void UI::checkSales() {
    string str;
    fstream openFile;
    openFile.open("sales.txt");
    getline(openFile, str);
    int sales = stoi(str);
    cout << "현재까지의 매출은 총 " << sales << "원입니다.\n" << endl;
}

void UI::checkStock() {
    fstream openFile;
    openFile.open("products.txt");
    if(openFile.is_open()) {
        string product;
        int price;
        int number;
        int i = 0;
        while(!openFile.eof()) {
            openFile >> product >> price >> number;
            cout << ++i << ". " << product << " " << number << "개" << endl;;
        }
    }
}

void UI::orderStock() {

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

void UI::addNewProduct() {
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