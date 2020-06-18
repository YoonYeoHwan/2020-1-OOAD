#include "StockAdaptor.h"

using namespace std;

void StockAdaptor::StockChange(int productNum, int count, std::vector<std::pair<int, int>> v) {
    Stock stock;
    stock.setStock(productNum, count, v);
}

Stock StockAdaptor::getStock() {
    Stock stock;
    return stock;
}

Mask StockAdaptor::getMask() {
    Mask mask;
    return mask;
}

void StockAdaptor::MaskChange() {
    Mask mask;
    mask.setMask();
}