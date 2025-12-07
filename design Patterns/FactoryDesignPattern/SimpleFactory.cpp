//simple Factory - A factory class that creates objects based on input
//which decides which concrete class to instantiate

#include<iostream>
using namespace std;

class Burger{
    public:
    virtual void prepareBurger()=0; //pure virtual function
    virtual ~Burger() {} //virtual destructor
};
class BasicBurger : public Burger{
    public:
    void prepareBurger() override{
        cout<<"Preparing Basic Burger"<<endl;
    }
};
class PremiumBurger : public Burger{
    public:
    void prepareBurger() override{
        cout<<"Preparing Premium Burger"<<endl;
    }
};
class BurgerFactory{
    public:
    Burger* createBurger(string type){
        if(type=="basic"){
            return new BasicBurger();
        }
        else if(type=="premium"){
            return new PremiumBurger();
        }
        else{
            return nullptr;
        }
    }
};

int main()
{
    BurgerFactory* b=new BurgerFactory();
    Burger* burger1=b->createBurger("basic");
    burger1->prepareBurger();
}