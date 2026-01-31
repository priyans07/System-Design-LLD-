#include <iostream>
using namespace std;

/* Base Component */
class Burger {
public:
    virtual int price() {
        return 50;   // plain burger price
    }

    virtual ~Burger() {}
};

/* Decorator (Wrapper) */
class BurgerDecorator : public Burger {
protected:
    Burger* burger;

public:
    BurgerDecorator(Burger* b) {
        burger = b;
    }
};

/* Concrete Decorator: Cheese */
class Cheese : public BurgerDecorator {
public:
    Cheese(Burger* b) : BurgerDecorator(b) {}

    int price() override {
        return burger->price() + 20;
    }
};

/* Concrete Decorator: Extra Patty */
class ExtraPatty : public BurgerDecorator {
public:
    ExtraPatty(Burger* b) : BurgerDecorator(b) {}

    int price() override {
        return burger->price() + 30;
    }
};

int main() {
    Burger* burger = new Burger();      // Plain burger (50)
    burger = new Cheese(burger);        // Add cheese (+20)
    burger = new ExtraPatty(burger);    // Add extra patty (+30)

    cout << burger->price() << endl;    // Output: 100

    return 0;
}
