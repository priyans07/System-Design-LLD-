#include<iostream>
#include<vector>

using namespace std;
class Product{
    public:
    string ProductName;
    double price;
    Product(string ProductName,double price)
    {
        this->ProductName=ProductName;
        this->price=price;
    }
};

//violating Single Responsibility Principle
class Shoppingcart{
    private:
    vector<Product*>products;
    public:
    void addproducts(Product* p){
        products.push_back(p);
    }
    vector<Product*> getProducts(){
        return products;
    }
    double CalculateTotalPrice(){
        double sum=0;
        for(auto i: products){
            sum+=i->price;
        }
        return sum;
    }
    void printInvoice()
    {
        for(auto i: products){
            cout<<"you have bought "<<i->ProductName<<" of price "<<i->price<<endl;
        }
    }
};
int main(){
    Shoppingcart* Sc=new Shoppingcart();
    Sc->addproducts(new Product("Pen",5.0));
    Sc->addproducts(new Product("Cake",252.00));
    Sc->addproducts(new Product("Burger",60));

    cout<<endl;
    cout<<"the total price of items are :"<<Sc->CalculateTotalPrice();
    cout<<endl;
    Sc->printInvoice();

}