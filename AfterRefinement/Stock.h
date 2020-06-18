#ifndef _STOCK_H
#define _STOCK_H

#include <string>
#include <fstream>
#include <vector>

class Stock {
    public:
        void setStock(int, int, std::vector<std::pair<int,int>>);
    // private: 
    //     string stockList[];
    //     int priceList[];
    //     int numOfStockList[];
};

#endif