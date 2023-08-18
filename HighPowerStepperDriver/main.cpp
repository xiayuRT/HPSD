#include <iostream>
#include <cstdint>
#include "HighPowerStepperDriver.hpp"
#include "HSPD_SPI.hpp"

int main(){
    std::cout << "SPI test begin!" << std::endl;
    for(;;){
        int fd = SPI_begin();
        uint16_t test = 0b100110011001;
        reg_write(fd, test);
        SPI_end(fd);
    }

}