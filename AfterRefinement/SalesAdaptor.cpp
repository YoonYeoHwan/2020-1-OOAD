#include "SalesAdaptor.h"
#include "Sales.h"

using namespace std;

void SalesAdaptor::SalesChange(int price) {
    Sales sales;
    sales.setTotalSales(price);
}

int SalesAdaptor::getSales() {
    Sales s;
    return s.getTotalSales();
}