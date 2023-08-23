#include <iostream>
#include <cstdint>
#include "HighPowerStepperDriver.hpp"
#include "HSPD_SPI.hpp"
#include <chrono>
#include <thread>

int main(){
    std::cout << "SPI test begin!" << std::endl;
    
    HighPowerStepperDriver sd;
    sd.initStepper(sd);

    sd.setDirection(0);
    for(int i = 1; i < 100000; i++){
        sd.step();
	    std::cout<<i<<std::endl;
    }

    std::cout << "SPI test end!" << std::endl;
}
