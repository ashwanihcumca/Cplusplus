#include <iostream>
#include <list>
#include <string>
using namespace std;
class ISubscriber
{
    public:
    virtual void notify(string) =0;
};

class User:public ISubscriber{
    int user_id;
    public:
        User() = default;
        User(int id):user_id(id){
            //cout<<"calling User constructor"<<endl;
        }
        void notify(string str){
            cout<<"User :: "<<user_id<<"  has been notified with msg::"<<str<<endl;
        }
};

class Group{
    public:
        Group() = default;
        void subscribe(ISubscriber * s){
            sub.push_back(s);
        }
        void unsubscribe(ISubscriber * remove_s){
            sub.remove(remove_s);
        }
        void notify(string str)
        {
            for(auto s: sub)
            {
               s->notify(str);
            }
        }
    private:
        list<ISubscriber*> sub;
};


int main()
{
    Group *gptr = new Group();
    
    User* user_1 = new User(1);
    User* user_2 = new User(2);
    User* user_3 = new User(3);
    User* user_4 = new User(4);
    
    gptr->subscribe(user_1);
    gptr->subscribe(user_2);
    gptr->subscribe(user_3);
    gptr->subscribe(user_4);
    
    gptr->notify("notification");
    
    gptr->unsubscribe(user_1);
    
    gptr->notify("new notification ");

    return 0;
}