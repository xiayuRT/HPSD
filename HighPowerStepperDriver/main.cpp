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
    sd.setStepMode(HPSDStepMode::MicroStep128);
    sd.enableDriver();
    sd.setDirection(0);
    for(int i = 1; i < 100000; i++){
        sd.step();
        //std::this_thread::sleep_for(std::chrono::microseconds(2));
	std::cout<<i<<std::endl;
    }

    std::cout << "SPI test end!" << std::endl;
}
