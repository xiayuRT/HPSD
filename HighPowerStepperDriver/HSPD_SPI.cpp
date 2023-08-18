/**
 * ****************************(C) COPYRIGHT 2023 Blue Bear****************************
 * @file       HSPD_SPI.cpp
 * @brief      Simple spi config for HPSD
 * 
 * @note       
 * @history:
 *   Version   Date            Author          Modification    Email
 *   V1.0.0    Aug-18-2023     Xiayu Z                         xiayu.zeng@runningtide.com
 * 
 * @verbatim
 * ==============================================================================
 * 
 * ==============================================================================
 * @endverbatim
 * ****************************(C) COPYRIGHT 2023 Blue Bear****************************
 */

#include <iostream>
#include <cstdlib>

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include "HSPD_SPI.hpp"


// Register Access
#define REGWRITE 0x0000

// SPI configuration
static const char *device = "/dev/spidev0.0";
static uint8_t spi_mode |= SPI_MODE_0;
static uint8_t bits_per_word = 16;
static uin32_t spi_speed = 500000;
static uint16_t spi_delay = 0;


static void pabort(const char *s){
    std::cout << s << std::endl; // output the error message to the terminal
    std::exit(EXIT_FAILURE);  // terminate the program
}

// Start the SPI
int SPI_begin(){

    int ret = 0;
    int spi_fd;

    // search for the SPI device
    spi_fd = open(device, O_RDWR)
    if(spi_fd < 0)
        pabort("Can't open the device");


    // set the SPI mode
    ret = ioctl(fd, SPI_IOC_WR_MODE, &mode);
    if (ret == -1)
        pabort("can't set spi mode");

    ret = ioctl(fd, SPI_IOC_RD_MODE, &mode);
    if (ret == -1)
        pabort("can't set spi mode");

    
    // set the bits per word
    ret = ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
    if (ret == -1)
        pabort("can't set bits per word");

    ret = ioctl(fd, SPI_IOC_RD_BITS_PER_WORD, &bits);
    if (ret == -1)
        pabort("can't set bits per word");


    // set the SPI speed
    ret = ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    if (ret == -1)
        pabort("can't set max speed hz");

    ret = ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
    if (ret == -1)
        pabort("can't get max speed hz");

}

// End the SPI
void SPI_end(int spi_fd){
    close(spi_fd);
}

// Write instruction
void reg_write(int spi_fd, uint16_t data){
    int ret;
    uint16_t tx[] = {data};

    struct spi_ioc_transfer tr ={
        .tx_buf = (unsigned long) tx,
        .rx_buf = (unsigned long) NULL,
        .len = (sizeof(tx)/sizeof(*tx) * 2),
        .delay_usecs = delay,
        .speed_hz = speed,
        .bits_per_word = bits_per_word
    };

    ret = ioclt(spi_fd, SPI_IOC_MESSAGE(1), &tr);

    if(ret < 1)
        pabort("can't send spi message!");
}
