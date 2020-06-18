#ifndef _STOCKADAPTOR_H
#define _STOCKADAPTOR_H

#include "Mask.h"
#include "Stock.h"
#include <string>
#include <vector>

class StockAdaptor {
    public: 
        void StockChange(int, int, std::vector<std::pair<int, int>> v);
        void MaskChange();
        Stock getStock();
        Mask getMask();
};

#endif