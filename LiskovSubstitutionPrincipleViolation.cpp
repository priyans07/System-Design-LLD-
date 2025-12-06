#include<iostream>
using namespace std;
// <<abstract>>
class Account{
    public:
    virtual void deposit(double amt)=0;
    virtual void withdraw(double amt)=0;
};
class SavingAccount : public Account
{
private : double balance;
public:
SavingAccount(){
    balance=0;
}
void deposit(double amt){
    balance+=amt;
    cout<<"deposited "<<amt<<endl;
}
void withdraw(double amt)
{
    if(balance < amt){
        cout<<"insuffient balance"<<endl;
    }else{
        balance-=amt;
    }
}
};
class FD: public Account{
private: double balance=0;
public:
FD(){
    balance=0;
}
void deposit(double amt){
    balance+=amt;
    cout<<"amount deposited "<<amt<<endl;
}
void withdraw(double amt){
    throw logic_error("not allowed");
}
};

class BankClient{
    private :
    vector<Account*> accounts;
    public :
    BankClient(vector<Account*>accounts){
        this->accounts=accounts;
    }
    void processTransaction(){
        for(auto i: accounts)
        {
            i->deposit(1000); // all accounts allow deposit
            try{
                i->withdraw(10);
            }catch(const logic_error &e)
            {
                cout<<"execption: "<<e.what()<<endl;
            }

        }
    }
};

int main()
{
    //liskov substition principke --> koi bhi child class is substituion to its parent class
     vector<Account*> acc;
     acc.push_back(new SavingAccount());
     acc.push_back(new FD());
     BankClient* client= new BankClient(acc);
     client->processTransaction();
}


//Liskov substitution principle states , the base class is always meant to 
// broader the domain of the parent class never narrow down it 