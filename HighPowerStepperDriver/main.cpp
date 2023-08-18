#include <iostream>
#include <cstdint>
#include "HighPowerStepperDriver.hpp"
#include "HSPD_SPI.hpp"
#include <chrono>
#include <thread>

int main(){
    std::cout << "SPI test begin!" << std::endl;
    
    HighPowerStepperDriver sd;
    sd.resetSettings();
    sd.clearStatus();
    sd.setDecayMode(HPSDDecayMode::AutoMixed);
    sd.setCurrentMilliamps36v4(2500);
    sd.setStepMode(HPSDStepMode::MicroStep2);
    sd.enableDriver();
    sd.setDirection(0);
    for(int i = 0; i < 100; i++){
        sd.step();
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }

    std::cout << "SPI test end!" << std::endl;
}
