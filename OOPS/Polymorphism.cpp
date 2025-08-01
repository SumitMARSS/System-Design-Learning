//last property of object in real world -> polymorphism


//polymorphism -> poly - many , morphism -> forms
//some objects has many forms
//in terms of coding -> we have 2 types -> dynamic, static
// Dynamic -> Method overriding -> as same function behave differnely circumstances -> applying accerate in normal car oor electric car
// static -> Method overloading -> same function bahavve differently under different parameter
//can create 2 accerate method as if we apply brake normally -> default and if we apply accelerate suddennly and full accelerate then car directly increase speed more 
//see example of static in normalCar class -> accelerate() 




#include <bits/stdc++.h>
using namespace std;


class Car{
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        
    public:
        Car(string a, string b){
            this->brand = a;
            this->model = b;
            this->isEngineOn = false;
            this->currentSpeed = 0;
        }
        
        void startEngine(){
            if(isEngineOn){
                cout<<brand<<" "<<model<<" :Engine already startted"<<endl;
            }
            else{
                isEngineOn = true;
                cout<<brand<<" "<<model<<" :Engine is starting....."<<endl;
            }
        }
        
        void stopEngine(){
            if(!isEngineOn){
                cout<<brand<<" "<<model<<" :Engine already stopped"<<endl;
            }
            else{
                currentSpeed = 0;
                isEngineOn = false;
                cout<<brand<<" "<<model<<" :Engine is stoping....."<<endl;
            }
        }
        
        void currentSpeedofCar(){
            if(isEngineOn){
                cout<<brand<<" "<<model<<" :current speed is.."<<currentSpeed<<endl;
            }
            else{
                cout<<brand<<" "<<model<<" :Engine is not started....."<<endl;
            }
        }

        virtual void accelerate() = 0; //virtual method for abstract pprograming
        
        void brake(){
            if(isEngineOn){
                cout<<brand<<" "<<model<<" :Applying break.."<<endl;
                currentSpeed = 0;
            }
            else{
                cout<<brand<<" "<<model<<" :Engine is alreayd stop....."<<endl;
            }
        }
        
        virtual ~Car(){}
};

class ManualCar : public Car{
    private:
        int currentGear;
        bool isRegular;
    public:
        ManualCar(string a, string b) : Car(b, a){
            this->currentGear = 0;
            this->isRegular = false;
        }
        //dynamic polymorphism -> method overriding example case overriding accelerate
        void accelerate(){
            currentSpeed += 20;
            cout<<"Accerating with speed 20km/h"<<endl;
        }
        // static polymorphism -> method overloading example case overloading accelerate
        void accelerate(bool isRegular){
            currentSpeed += 50;
            cout<<"Accerating with speed 50km/h"<<endl;
        }

        void shiftGear(int gear){
            currentGear = gear;
            cout<<brand<<" "<<model<<" :Gear is shifted to....."<<currentGear<<endl;
        }
};


class ElectricCar : public Car{
    private:
        int batteryPercentage;
    public:
        ElectricCar(string a, string b) : Car(b, a){
            this->batteryPercentage = 100;
        }
        //dynamic polymorphism -> method overriding  example case overriding accelerate
        void accelerate(){
            currentSpeed += 15;
            batteryPercentage -= 20;
            cout<<"Accerating with speed 15km/h and batery is also decreased by 20%"<<endl;
        }

        void ChargeBattery(){
            batteryPercentage = 100;
            cout<<brand<<" "<<model<<" :Battery is charged to....."<<batteryPercentage<<endl;
        }
};


int main() {
    ManualCar *c1 = new ManualCar("Suzuki", "ABC6233");
    c1->startEngine();
    c1->currentSpeedofCar();
    c1->accelerate();
    c1->currentSpeedofCar();
    c1->accelerate(true);
    c1->currentSpeedofCar();
    c1->brake();
    c1->stopEngine();
    c1->shiftGear(3);
    delete c1;
    
    cout<<"........................................................"<<endl;
    
    
    ElectricCar *c2 = new ElectricCar("Tata", "JHJD33");
    c2->startEngine();
    c2->currentSpeedofCar();
    c2->accelerate();
    c2->currentSpeedofCar();
    c2->brake();
    c2->stopEngine();
    c2->ChargeBattery();
    delete c2;
    
    return 0;
}






