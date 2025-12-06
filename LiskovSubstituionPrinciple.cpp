#include<iostream>
using namespace std;

// <<abstract_class>>
class Account{
    public:
    virtual void deposit(long amt)=0;
    virtual void withdraw(long amt)=0;
};
class SavingAccount: public Account{
private : long balance =0;
public: 
//constructor
SavingAccount(long balance){
this->balance=balance;
}
void deposit(long amt){
    balance+=amt;
    cout<<"updated balance "<<balance;
}
void withdraw(long amt){
    if(balance < amt){
        cout<<"insufficient funds"<<endl;
    }
    else{
        balance-=amt;
        cout<<"update balance after withdraw"<<balance<<endl;
    }
}
};

// <<abstract>>
class FD{
    public :
    virtual void deposit(long amt)=0;
};
class FDAccount : public FD{
    private : long balance=0;
    public :
    FDAccount(long balance){
        balance=this->balance;}
    void deposit(long amt){
    balance+=amt;
    cout<<"amount on FD "<<balance<<endl;        
    }
};
class BankCLient
{
    private : 
    vector<Account*> normal_accounts;
    vector<FD*> Fd_accounts;
    public :
    BankCLient(vector<Account*> acc,vector<FD*> fd){
this->normal_accounts=acc;
        this->Fd_accounts=fd;
    }
    void processTransaction(){
        cout<<"Processing normal accoutn trxc"<<endl;
        for(auto i : normal_accounts){
            i->deposit(1000);
            i->withdraw(10);
        }
        cout<<"processing fd account trnsx"<<endl;
        for(auto i: Fd_accounts){
            i->deposit(100);
        }
    }
};
int main(){
vector<Account*> acc;
acc.push_back(new SavingAccount(1000));
vector<FD*> fd;
fd.push_back(new FDAccount(1000));
BankCLient* b= new BankCLient(acc,fd);
b->processTransaction();
}