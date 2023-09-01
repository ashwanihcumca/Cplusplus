#include <iostream>
#include <string>
using namespace std;

class IToy{
    public:
    virtual void instanceCreated() = 0;

};
class PlasticToy:public IToy{
    public:
    void instanceCreated(){
        std::cout<<"Plastic instance has been created "<<std::endl;
    }

};

class GlassToy:public IToy{
    public:
    void instanceCreated(){
        std::cout<<"Glass instance has been created "<<std::endl;
    }

};

class ClayToy:public IToy{
    public:
    void instanceCreated(){
        std::cout<<"Clay instance has been created "<<std::endl;
    }

};

class ToyFactory{
    public:
        static IToy* getToyInstane(string str)
        {
            if(str == "plastic toy")
            {
                toy = new PlasticToy();
            }
            else if(str == "glass toy")
            {
                toy = new GlassToy();
            }
            else if(str == "clay toy")
            {
                toy = new ClayToy();
            }
            else
            {
                cout<<"Invalid toy type"<<endl;
            }
            return toy;
        }
    private:
        static IToy* toy;
};

IToy* ToyFactory::toy = nullptr;

int main(){
    string input_user ="";
    std::cout<<"Please enter the toy name"<<endl;
    getline(cin,input_user);
    IToy* toy = ToyFactory::getToyInstane(input_user);
    if(toy)
        toy->instanceCreated();
    return 0;

}