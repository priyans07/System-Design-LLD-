#ifndef RESTRAUNT_MANAGER_H
#define RESTRAUNT_MANAGER_H

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../models/Restraunt.h"
using namespace std;

class RestrauntManager{
private:

vector<Restraunt*> restraunts;
static RestrauntManager* instance;

public:
static RestrauntManager* GetInstance(){
    if(instance==nullptr){
        instance=new RestrauntManager();
    }
    return instance;}
    
    void AddRestraunt(Restraunt* r){
        restraunts.push_back(r);
    }

    vector<Restraunt*> GetRestrauntBYLocation(const string& location){
        vector<Restraunt*> result;
        transform(location.begin(),location.end(),location.begin(),::tolower);
        for(auto i : restraunts){
            string rl=i->GetLocation();
            transform(rl.begin(), rl.end(), rl.begin(), ::tolower);
            if(rl==location){
                result.push_back(i);
            }
        }
        return result;
    }


};

RestrauntManager* RestrauntManager::instance=nullptr;

#endif