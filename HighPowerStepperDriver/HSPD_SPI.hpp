#ifndef _HSPD_SPI_HPP
#define _HSPD_SPI_HPP

#include <stdint.h>

int SPI_begin();
void SPI_end(int spi_fd);
void reg_write(int spi_fd, uint16_t data);

#endif