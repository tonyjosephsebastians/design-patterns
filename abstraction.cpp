//Real-world Abstraction: Car Control System
#include <iostream>
#include <string>
using namespace std;

// Engine subsystem - hidden from driver
class Engine {
private:
    bool isRunning;
    int rpm;
    
    void ignite() {
        cout << "Igniting spark plugs..." << endl;
        isRunning = true;
        rpm = 800;
    }
    
    void fuelInjection() {
        cout << "Injecting fuel..." << endl;
    }
    
public:
    Engine() : isRunning(false), rpm(0) {}
    
    void start() {
        if (!isRunning) {
            fuelInjection();
            ignite();
            cout << "Engine started" << endl;
        }
    }
    
    void stop() {
        if (isRunning) {
            isRunning = false;
            rpm = 0;
            cout << "Engine stopped" << endl;
        }
    }
    
    void accelerate(int amount) {
        if (isRunning) {
            rpm += amount;
            cout << "Engine RPM: " << rpm << endl;
        }
    }
};

// Transmission subsystem - hidden from driver
class Transmission {
private:
    int currentGear;
    
    void engageClutch() {
        cout << "Clutch engaged" << endl;
    }
    
    void disengageClutch() {
        cout << "Clutch disengaged" << endl;
    }
    
public:
    Transmission() : currentGear(0) {}
    
    void shiftGear(int gear) {
        if (gear >= -1 && gear <= 6) { // -1 for reverse
            engageClutch();
            currentGear = gear;
            disengageClutch();
            cout << "Shifted to gear " << gear << endl;
        }
    }
};

// Simplified car interface - what the driver sees
class Car {
private:
    Engine engine;
    Transmission transmission;
    string model;
    
public:
    Car(string m) : model(m) {}
    
    void start() {
        cout << "Starting " << model << "..." << endl;
        engine.start();
        transmission.shiftGear(0); // Neutral
    }
    
    void drive() {
        cout << "Driving " << model << "..." << endl;
        transmission.shiftGear(1);
        engine.accelerate(1000);
    }
    
    void stop() {
        cout << "Stopping " << model << "..." << endl;
        transmission.shiftGear(0);
        engine.stop();
    }
    
    void park() {
        cout << "Parking " << model << endl;
        transmission.shiftGear(-1); // Reverse to park
        transmission.shiftGear(0);  // Then neutral
    }
};

int main() {
    Car myCar("Toyota Camry");
    
    // Simple interface hides complex subsystems
    myCar.start();
    myCar.drive();
    myCar.stop();
    myCar.park();
    
    // Can't access internal components directly
    // myCar.engine.ignite(); // Error - engine is private
}