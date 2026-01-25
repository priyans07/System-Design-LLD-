#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include "../models/Order.h"
#include "../models/Cart.h"
#include "../models/Restraunt.h"
#include "../strategies/PaymentStrategy.h"
#include <vector>
#include <string>
using namespace std;

class OrderFactory {
public:
    virtual Order* createOrder(User* user, Cart* cart, Restraunt* restaurant, const vector<MenuItems>& menuItems,
                                PaymentStrategy* paymentStrategy, double totalCost, const string& orderType) = 0;
    virtual ~OrderFactory() {}
};

#endif // ORDER_FACTORY_H