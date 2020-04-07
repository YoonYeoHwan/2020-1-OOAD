#include "sales.h"

using namespace std;

void Sales::sales(int price) {
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

void Sales::checkSales() {
    string str;
    fstream openFile;

    openFile.open("sales.txt");
    getline(openFile, str);
    int sales = stoi(str);
    cout << "현재까지의 매출은 총 " << sales << "원입니다.\n" << endl;
}