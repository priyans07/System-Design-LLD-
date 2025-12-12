#include<iostream>
using namespace std;

class Burger{
public:
    virtual void createBurger() = 0;
    virtual ~Burger() {}
};

class BasicBurger : public Burger{
public:
    void createBurger() override {
        cout << "Creating Basic Burger" << endl;
    }
};

class PremiumBurger : public Burger{
public:
    void createBurger() override {
        cout << "Creating Premium Burger" << endl;
    }
};

class BasicWheatBurger : public BasicBurger{
public:
    void createBurger() override {
        cout << "Creating Basic Wheat Burger" << endl;
    }
};

class PremiumWheatBurger : public PremiumBurger{
public:
    void createBurger() override {
        cout << "Creating Premium Wheat Burger" << endl;
    }
};

class BurgerFactory{
public:
    virtual Burger* createBurger(string type) = 0;
    virtual ~BurgerFactory() {}
};

class SimpleFactoryInstance : public BurgerFactory {
public:
    Burger* createBurger(string type) override {
        if(type == "basic")  return new BasicBurger();
        if(type == "premium") return new PremiumBurger();
        return nullptr;
    }
};

class WheatFactoryInstance : public BurgerFactory {
public:
    Burger* createBurger(string type) override {
        if(type == "basic")  return new BasicWheatBurger();
        if(type == "premium") return new PremiumWheatBurger();
        return nullptr;
    }
};

int main() {
    cout << "enter which type of burger you want (simple/wheat) : ";
    string factoryType;
    cin >> factoryType;

    BurgerFactory* b = nullptr;

    if(factoryType == "simple") {
        b = new SimpleFactoryInstance();
        Burger* burger = b->createBurger("basic");
        if(burger) burger->createBurger();
    }
    else if(factoryType == "wheat") {
        b = new WheatFactoryInstance();
        Burger* burger = b->createBurger("premium");
        if(burger) burger->createBurger();
    }

    return 0;
}
