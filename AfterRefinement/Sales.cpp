#include "Sales.h"

using namespace std;

int Sales::getTotalSales() {
    string str;
    fstream openFile;
    openFile.open("sales.txt");
    getline(openFile, str);
    int sales = stoi(str);
    return sales;
}

void Sales::setTotalSales(int price) {
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