// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

// Encapsulation class - 
// 1. It's all abbout binding data and methods or capsule all details and behavoiour in a class so that whenever we need that object we can directly ask/use that class/bluprint to create that object
// 2. It also helps in data privacy if we want more control over some data or don't want to give access to users we can hide from user and can give a methid to intracct e.g Getter() and Setter() methods are commonly used


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
        string engine;
        string name;
        int initialVelocity ;
        int accerateWith ;
        bool engineState;
        int decelerateWith;
    
    public:
        // string engine;
        SportCar(string name){
            this->engine = "Lamborgini Engine";
            this->name = name;
            this->initialVelocity = 12;
            this->accerateWith = 10;
            this->engineState = false;
            this->decelerateWith = 5;
        }
        void setEngineName(string sentence){
            //here we can perform some validation of engine name - like only Lamborgini engine allowed or something if we want
            //this is benifit of getter and setter and not in direct giving public access

            //currently a small validation performed

            string word;
            bool found = false;

            // Use stringstream to break the sentence into words
            stringstream ss(sentence);
            while (ss >> word) {
                if (word == "Lamborgini") {
                    found = true;
                    break;
                }
            }

            if (found) {
                this->engine = sentence;
                cout<<"Current Engine set as: "<<sentence<<endl;
            } else {
                cout << "'Lamborgini' engine only allowd." << endl;
            }
        }

        string getEngineName(){
            return this->engine;
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
    
    SportCar *c1 = new SportCar("Lambogini");
    cout<<"Current Engine name is: "<<c1->getEngineName()<<endl;
    c1->start();
    c1->currSpeed();
    c1->accelerate();
    c1->aplyingbreak();
    c1->stop();
    c1->accelerate();

    //Here we can get direct access of name of engine and manipulate that

    // c1->engine = "Lamborgini Engine";
    // cout<<c1->getEngineName() <<endl;
    // c1->engine = "Ducati Engine";
    // cout<<"Engine name changed too -> "<<c1->getEngineName() <<endl;

    //Now i want to give rectrict direct access of engine 
    c1->setEngineName("Ducati Engine");
    c1->setEngineName("Lamborgini old Engine");
    c1->setEngineName("Farrari Engine");
    cout<<"Current Engine name is: "<<c1->getEngineName()<<endl;

    return 0;
}


