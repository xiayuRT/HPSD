/**
 * ****************************(C) COPYRIGHT 2023 Blue Bear****************************
 * @file       HSPD_SPI.hpp
 * @brief      this is the header file for HSPD_SPI.hpp
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
#ifndef _HSPD_SPI_HPP
#define _HSPD_SPI_HPP

#include <cstdint>

int SPI_begin();
void SPI_end(int spi_fd);
void reg_write(int spi_fd, uint16_t data);

#endif