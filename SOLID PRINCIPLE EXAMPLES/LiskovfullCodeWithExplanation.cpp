// SOLID
//S - Single Responsibility Principle
//L











//Liskov Principle Code - demo


// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
using namespace std;
//Liskov substitution principle

// class Vechile{
//     private:
//         string engine;
//         int wheel;
//     public:
//         Vechile(string enng, int wheel){
//             this->wheel = wheel;
//             this->engine = enng;
//         }
//         virtual void StartEngine(){
//             cout<<"Running with vechile engine"<<endl;
//         };
//         virtual void Running(){
//             cout<<"Running in 2 wheel"<<endl;
//         }
//         string getEngine () const{
//             return this->engine;
//         }
//         int getWheel () const{
//             return this->wheel;
//         }
//         virtual ~Vechile(){}
// };

// class Bike: public Vechile{
//     public:
//         Bike(string engineName, int wheelCount) : Vechile(engineName, wheelCount) {}
//         void StartEngine() override {
//             cout<<"Running on "<<getEngine()<<endl;
//         }
//         void Running() override{
//             cout<<"Running on "<<getWheel()<<endl;
//         }
// };

// class Car: public Vechile{
//     public:
//         Car(string engineName, int wheelCount) : Vechile(engineName, wheelCount) {}
//         void StartEngine() override{
//             cout<<"Running on "<<getEngine()<<endl;
//         }
//         void Running() override{
//             cout<<"Running on "<<getWheel()<<endl;
//         }
// };

// class Bicycle: public Vechile{
//     Bicycle(Null)
// }

// //vechile
// motor vechile , normal vechile
// in motor vechile we have - 
// bike,, car
// in normal vechile
// cycle, bailgadii etc wwhhich don't have any engine

class Vechile{
    private:
        int wheel;
    public:
        Vechile(int wheel){
            this->wheel = wheel;
        }
        int getWheel() const {
            return this->wheel;
        }
        virtual void WheelCapacity(){
            cout<<"Running in wheel - don't know"<<endl;
        }

        virtual ~Vechile(){}
};

class MotorVechile: public Vechile{
    private:
        string engine;
    public:
        MotorVechile(string eng, int wheel) : Vechile(wheel) {
            this->engine = eng;
        }
        virtual void EngineRunning(){
            cout<<"Starting in engine"<<endl;
        }
        string getEngine() const {
            return this->engine;
        }
};

class NormalVechile: public Vechile{
    public:
    NormalVechile(int wheel) : Vechile(wheel){}
};

class Bike: public MotorVechile{
    public:
    Bike(string engine, int wheel) : MotorVechile(engine, wheel){}
    void EngineRunning(){
        cout<<"Running in engine"<<getEngine()<<endl;
    }
    void WheelCapacity(){
        cout<<"Running in wheel"<<getWheel()<<endl;
    }
};

class Car: public MotorVechile{
    public:
    Car(string engine, int wheel) : MotorVechile(engine, wheel){}
    void EngineRunning(){
        cout<<"Running in engine"<<getEngine()<<endl;
    }
    void WheelCapacity(){
        cout<<"Running in wheel"<<getWheel()<<endl;
    }
};

class Bicycle: public NormalVechile{
    public:
    Bicycle(int wheel) : NormalVechile(wheel){}
    void WheelCapacity(){
        cout<<"Running in wheel"<<getWheel()<<endl;
    }
};


int main() {
  Bike mybike("Yamaha Engine", 2);
  Car mycar("Car Engine", 4);
  Bicycle mycycle(3);
  
  mybike.EngineRunning();
  mybike.WheelCapacity();
  
  mycycle.WheelCapacity();
  
  mycar.EngineRunning();
  mycar.WheelCapacity();
}





