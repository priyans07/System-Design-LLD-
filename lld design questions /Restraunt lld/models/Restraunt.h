#ifndef RESTRAUNT_H
#define RESTRAUNT_H

#include<iostream>
#include<vector>
#include "Menu.h"
using namespace std;
class Restraunt{
    private :
    static int NextRestraunt;
    int restraunt_id;
    string name;
    string location;
    vector<MenuItems> ms;
    public:
    Restraunt(const string&name,const string&location){
        this->name=name;
        this->location=location;
        this->restraunt_id=NextRestraunt++;
    }
    string GetName() const{
        return name;
    }
    void SetName(const string& n){
        name=n;
    }
    string GetLocation() const{
        return location;
    }
    void SetLocation(const string& loc){
        location=loc;
    }
    int GetRestrauntId() const{ 
        return restraunt_id;
    }
    void AddMenuItem(const MenuItems& item){
        ms.push_back(item);
    }
    const vector<MenuItems>& GetMenuItems() const{
        return ms;
    }
};
int Restraunt::NextRestraunt=0;

#endif