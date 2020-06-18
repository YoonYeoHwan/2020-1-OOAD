#pragma once
#include <iostream>
#include <fstream>
#include <vector>

class StockManage {
    public:
        void checkStock();
        void orderStock();
        void orderMask();
        void stockCount(std::vector<std::pair<int,int>>);
        void maskCount(int);
};