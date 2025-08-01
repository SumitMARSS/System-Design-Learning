// Inharitance -> A new class (child or subclass) automatically gets the properties and behavior (data and methods) of an existing class (parent or base class. 
//  This lets you create new functionality by reusing code you already have, making your code simpler and more organized.
//In simple words -> A new class can use everything from an existing class, and also add its own features.

//Difference between public, private, protected -> Access specifiers or Access modifiers 
// Public Class -> Accessable to all -> class manualCar : Public Car 
// Private CLass -> No one can access after that heirarcy if at time of inheritance we use -> class manualCar : Private Car 
// Protected Class -> Only used by inherited class -> class manualCar : Protected Car 


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
        
        void accelerate(){
            if(isEngineOn){
                cout<<brand<<" "<<model<<" :Applying acceleration.."<<endl;
                currentSpeed += 20;
            }
            else{
                cout<<brand<<" "<<model<<" :Engine is not started....."<<endl;
            }
        }
        
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
    public:
        ManualCar(string a, string b) : Car(b, a){
            this->currentGear = 0;
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






