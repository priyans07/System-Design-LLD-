// According to strategy design principle
// inherinetence is not good practice for writing sclable code
// suppose you have a class and rest of your class is implementing that class 
// but some classes have some set of methods which are not defined virtually in base class
// so in that case if you want to add new functionality you have to modify the base class
// which is not a good practice according to open closed principle
// so to avoid this we use strategy design pattern
// here is an example of strategy design pattern in which we have a robot class
// and different types of robots like war robot , companion robot etc
// and each robot has different types of walking , talking and flying abilities
// so we create separate abstract classes for walking , talking and flying abilities
// and then we create concrete classes for each ability
// and then we use composition to include these abilities in robot class

#include<iostream>
using namespace std;
// <<abstract class>>
class WalkableRobot {
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};
class NormalWalk : public WalkableRobot {
public :
void walk() override{
    cout<<"I can walk normally"<<endl;
}
};
class ZigZagWalk : public WalkableRobot {
public:
void walk() override{
    cout<<"I can walk in zigzag manner"<<endl;
}
};
class TalkableRobot{
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};
class NormalTalk : public TalkableRobot {
public :
void talk() override{
    cout<<"I can talk normally"<<endl;
}};
class LoudTalk : public TalkableRobot {
public : 
void talk() override{
    cout<<"I can talk loudly"<<endl;
}
};
class FlyableRobot{
public:
virtual void fly() = 0;
virtual ~FlyableRobot() {}
};
class CanFly : public FlyableRobot {
public : 
void fly() override{
    cout<<"I can fly"<<endl;
}
};
class jetFly : public FlyableRobot {
public:
void fly() override{
    cout<<"I can fly like a jet"<<endl;
}
};
class Robot{
    protected:
    WalkableRobot* w;
    TalkableRobot* t;
    FlyableRobot * f;
    public:
    virtual void Projection()=0;
    Robot(WalkableRobot* _w,TalkableRobot* _t,FlyableRobot* _f)
    {
        this->w=_w;
        this->t=_t;
        this->f=_f;
    }
    void walk(){
        w->walk();
    }
    void talk(){
        t->talk();
    }
    void fly(){
        f->fly();
    }

};
class CompanionRobot : public Robot 
{
    private :
    protected:
    public:
    CompanionRobot(WalkableRobot* _w,TalkableRobot* _t,FlyableRobot* _f):Robot(_w,_t,_f){}
    void Projection() override
    {
        cout<<"I am a companion robot"<<endl;
    }
    
};
class WarRobot : public Robot 
{
    private :
    protected:
    public:
    WarRobot(WalkableRobot* _w,TalkableRobot* _t,FlyableRobot* _f):Robot(_w,_t,_f){}
    void Projection() override
    {
        cout<<"I am a war robot"<<endl;
    }
    
};
int main()
{
    WalkableRobot* w1=new NormalWalk();
    TalkableRobot* t1=new LoudTalk();
    FlyableRobot* f1=new CanFly();
    Robot* r1=new CompanionRobot (w1,t1,f1);
    r1->Projection();
    r1->walk();
    r1->talk();
    r1->fly();

    cout<<endl;

    WalkableRobot* w2=new ZigZagWalk();
    TalkableRobot* t2=new NormalTalk();
    FlyableRobot* f2=new jetFly();
    Robot* r2=new WarRobot (w2,t2,f2);
    r2->Projection();
    r2->walk();
    r2->talk();
    r2->fly();

    return 0;
}