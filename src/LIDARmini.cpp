#include "LIDARmini.hpp"

LIDARmini::LIDARmini(hwlib::target::pin_out pin):
    pin(pin)
{}
    
    
void LIDARmini::doSomething(int x) {
    hwlib::cout << "Do something: " << x << hwlib::endl;
    hwlib::wait_ms(1000);
}