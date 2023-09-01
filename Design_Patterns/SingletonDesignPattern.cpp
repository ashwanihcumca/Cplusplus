#include <iostream>
#include <mutex>
using namespace std;

//string s = "Ashwani Tiwari";
class Singleton{
    private:
        static Singleton* inst;
        static std::mutex m;
        Singleton() = default;
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        //std::mutex m;
    public:
        static Singleton* getInstance()
        {
            if(inst == nullptr)
            {
                m.lock();
                if(inst == nullptr)
                {
                    inst = new Singleton(); 
                    cout<<"Address of inst"<<inst<<endl;
                }
                m.unlock();
            }
            return inst;
        }
};

Singleton* Singleton::inst = nullptr;
std::mutex Singleton::m;
int main(){
    Singleton* singleInst = Singleton::getInstance();
    cout<<"Address of singleInst"<<singleInst<<endl;
    Singleton* singleInst_1 = Singleton::getInstance();
    cout<<"Address of singleInst_1"<<singleInst<<endl;
    return 0;
}