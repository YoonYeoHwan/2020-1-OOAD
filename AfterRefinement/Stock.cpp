#include "Stock.h"

using namespace std;

void Stock::setStock(int ProductNumber, int count, vector<pair<int, int>> v) {

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
    }
    fclose(file);

    FILE *wFile = fopen("products.txt", "w");

    int vectorSize = v.size();
    if(vectorSize == 0) {
        for(int i=0; i<counter; i++) {
            if(ProductNumber - 1 == i) {
                productsCount[i] += count;
            }
            string strsum = productsName[i] + " " + to_string(productsPrice[i]) + " " + to_string(productsCount[i]);
            const char* ch = strsum.c_str();
            fputs(ch, wFile);
            fputs("\n", wFile);
        }
    }
    else {
        for(int i=0; i<counter; i++) {
            for(int j=0; j<vectorSize; j++) {
                if(i == v[j].first - 1) {
                    productsCount[i] -= v[j].second;
                }
            }
            string strsum = productsName[i] + " " + to_string(productsPrice[i]) + " " + to_string(productsCount[i]);
            const char* ch = strsum.c_str();
            fputs(ch, wFile);
            fputs("\n", wFile);
        }
    }
    fclose(wFile);

    return;
}