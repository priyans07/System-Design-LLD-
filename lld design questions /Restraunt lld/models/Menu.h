#ifndef MenuItems_H
#define MenuItems_H
#include<iostream>
#include<string>
using namespace std;

class MenuItems{
    private:
    string code;
    string name ;
    int price;
    public:
    //created a constructor first 
    MenuItems(const string& code,const string& name,int price){
        this->code=code;
        this->name=name;
        this->price=price;
    }
    //getter and setter initialisation 
    string Getcode() const{
        return code;
    }
    void setCode(const string& s){
        code=s;
    }
    string GetName() const {
        return name;
    }
    void setName(const string & s){
        name=s;
    }
    int GetPrice() const{
        return price;
    }
    void SetPrice(int p){
        price=p;
    }

};
#endif
