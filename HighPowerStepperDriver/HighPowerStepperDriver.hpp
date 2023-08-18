#ifndef _HIGHPOWERSTEPPERDRIVER_HPP
#define _HIGHPOWERSTEPPERDRIVER_HPP

#include <cstdint>

class HighPowerStepperDriver{
public: 
  HighPowerStepperDriver();
  void resetSettings();
  void applySettings();
  void enableDriver();
  void disableDriver();
  void setDirection(bool value);
  bool getDirection();
  void step();
  void setStepMode(HPSDStepMode mode);
  void setStepMode(uint16_t mode);
  void setCurrentMilliamps36v4(uint16_t current);
  void setDecayMode(HPSDDecayMode mode);
  void clearStatus();
  void clearFaults();

protected:
  uint16_t ctrl, torque, off, blank, decay, stall, drive;
  void writeCTRL();
  void writeTORQUE();
  void writeOFF();
  void writeBLANK();
  void writeDECAY();
  void writeSTALL();
  void writeDRIVE();
  public:
    DRV8711SPI driver; 
};

// Address of control and status registers
enum class HPSDRegAddr : uint8_t
{
  CTRL   = 0x00,
  TORQUE = 0x01,
  OFF    = 0x02,
  BLANK  = 0x03,
  DECAY  = 0x04,
  STALL  = 0x05,
  DRIVE  = 0x06,
  STATUS = 0x07,
};

// Possible arguments to setStepMode().
enum class HPSDStepMode : uint16_t
{
  MicroStep256 = 256,
  MicroStep128 = 128,
  MicroStep64  =  64,
  MicroStep32  =  32,
  MicroStep16  =  16,
  MicroStep8   =   8,
  MicroStep4   =   4,
  MicroStep2   =   2,
  MicroStep1   =   1,
};

// Possible arguments to setDecayMode().
enum class HPSDDecayMode : uint8_t
{
  Slow                = 0b000,
  SlowIncMixedDec     = 0b001,
  Fast                = 0b010,
  Mixed               = 0b011,
  SlowIncAutoMixedDec = 0b100,
  AutoMixed           = 0b101,
};

// Bits that are set in the return value of readStatus() to indicate statusconditions.
enum class HPSDStatusBit : uint8_t
{
  
  OTS    = 0,  // Overtemperature shutdown
  AOCP   = 1,  // Channel A overcurrent shutdown
  BOCP   = 2,  // Channel B overcurrent shutdown
  APDF   = 3,  // Channel A predriver fault
  BPDF   = 4,  // Channel B predriver fault
  UVLO   = 5,  // Undervoltage lockout
  STD    = 6,  // Stall detected
  STDLAT = 7,  // Latched stall detect
};

#endif