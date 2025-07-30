// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// Abstract class - it's all abbout hiding unnessary details and showing only what is needed/important - if user want they can see that details 
// it doesn't impace if user access that data
class Car{
    public:
        virtual void start () = 0;
        virtual void currSpeed() = 0;
        virtual void accelerate () = 0;
        virtual void aplyingbreak () = 0;
        virtual void stop () = 0;
        ~Car() {}
};

class SportCar : public Car{
    private:
        string name;
        int initialVelocity ;
        int accerateWith ;
        bool engineState;
        int decelerateWith;
    
    public:
        SportCar(string name){
            this->name = name;
            this->initialVelocity = 12;
            this->accerateWith = 10;
            this->engineState = false;
            this->decelerateWith = 5;
        }
        
        void start(){
            if(engineState){
                cout<<"Your car is already running"<<endl;
            }
            else{
                engineState = true;
                cout<<name<<" is starting 0"<<" KM/hour"<<endl;
            }
        }
        void currSpeed(){
            if(engineState){
                cout<<name<<"car reached at "<<initialVelocity<<" KM/hour"<<endl;
            }
            else{
                cout<<"Your engine is not started, first start that"<<endl;
            }
            
        }
        void accelerate(){
            if(engineState){
                cout<<name<<"car is accelerating with "<<accerateWith<<" KM/hour"<<endl;
                cout<<"Your current velocity become "<<initialVelocity + accerateWith <<" KM/hour"<<endl;
            }
            else{
                cout<<"Your engine is not started, first start that"<<endl;
            }
        }
        void aplyingbreak(){
            if(engineState){
                cout<<name<<"car is deccelerating with "<<decelerateWith<<" KM/hour"<<endl;
                cout<<"Your current velocity become "<<initialVelocity - decelerateWith <<" KM/hour"<<endl;
            }
            else{
                cout<<"Your engine is not started, first start that"<<endl;
            }
            
        }
        void stop(){
            if(engineState){
                initialVelocity = 0;
                engineState = false;
                cout<<"Your car is stooped and initial velocity marked as"<<initialVelocity<<endl;
            }
            else{
                cout<<"Your engine is not started, first start that"<<endl;
            }
        }
    
};

int main() {
    
    Car *c1 = new SportCar("Lambogini");
    c1->start();
    c1->currSpeed();
    c1->accelerate();
    c1->aplyingbreak();
    c1->stop();
    c1->accelerate();

    return 0;
}


