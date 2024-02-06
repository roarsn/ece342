#include "dfr0151.h"

extern I2C_HandleTypeDef hi2c1;


uint8_t bcd2bin(uint8_t data){
 return ((data >> 4) * 10) + (data & 0x0F);
}

uint8_t bin2bcd(uint8_t data){
  return ((data / 10) << 4)|(data % 10);
}

uint8_t rtc_read(uint8_t address)
{
  uint8_t data;

  if (HAL_I2C_Mem_Read(&hi2c1,ADDR_DS1307,address,I2C_MEMADD_SIZE_8BIT,&data,1,100) != HAL_OK) {
    Error_Handler();
  }

  return data;
}

void rtc_write(uint8_t address,uint8_t data)
{
  if (HAL_I2C_Mem_Write(&hi2c1,ADDR_DS1307,address,I2C_MEMADD_SIZE_8BIT,&data,1,100) != HAL_OK){
    Error_Handler();
  }
}

void rtc_init()
{
  // Initialize Real-Time Clock peripheral
  uint8_t rs=0, sqwe=1, out=0;
  
  rs&=3;
  if (sqwe) rs|=0x10;
  if (out) rs|=0x80;

  rtc_write(0x07,rs);
}

void rtc_get_time(uint8_t *hour,uint8_t *min,uint8_t *sec) 
{
  // Your code here
	*sec=bcd2bin(rtc_read(0x0)); //how to only call once?
	*min=bcd2bin(rtc_read(0x1));
	*hour=bcd2bin(rtc_read(0x2));
	//uint8_t time=bcd2bin(rtc_read(   multiple addresses
}

void rtc_set_time(uint8_t hour,uint8_t min,uint8_t sec)
{
  // Your code here
	
	rtc_write(0x2,bin2bcd(hour));
	rtc_write(0x1,bin2bcd(min));
	rtc_write(0x0,bin2bcd(sec));
}

void rtc_get_date(uint8_t *week_day,uint8_t *day,uint8_t *month,uint8_t *year)
{
  // Your code here
}

void rtc_set_date(uint8_t week_day,uint8_t day,uint8_t month,uint8_t year)
{
  // Your code here
}

void eeprom_write(uint16_t address, uint8_t *data, uint16_t size) {
  // Your code here
	if (HAL_I2C_Mem_Write(&hi2c1,ADDR_DS1307,address,size,data,1,100) != HAL_OK){ //check this
    Error_Handler();
  }
}

uint8_t eeprom_read(uint16_t address) {
  // Your code here
	uint8_t data;

  if (HAL_I2C_Mem_Read(&hi2c1,ADDR_EEPROM,address,I2C_MEMADD_SIZE_16BIT,&data,1,100) != HAL_OK) {
    Error_Handler();
  }
  return data;
}

void rtc_store_time(uint8_t hour,uint8_t min,uint8_t sec)
{
  // Your code here
	uint8_t *hp, *mp, *sp;
	*hp=bin2bcd(hour);
	*mp=bin2bcd(min);
	*sp=bin2bcd(sec);
	uint16_t size=I2C_MEMADD_SIZE_16BIT; //is this right?
	//uint16_t size=0x12;//18bits
	//uint16_t *data=((hour|0x10)<<12)&(min|0x10)<<6)&(sec|0x10);
	eeprom_write(0x2,hp,size); //do one full loop to store it all in one buffer, use an array
	eeprom_write(0x1,mp,size);
	eeprom_write(0x0,sp,size);
}
void rtc_retrieve_time(uint8_t *hour,uint8_t *min,uint8_t *sec) 
{
  // Your code here
	/**sec=bcd2bin(eeprom_read(0x0)); //how to only call once?
	*min=bcd2bin(eeprom_read(0x1));
	*hour=bcd2bin(eeprom_read(0x2));
	rtc_set_time(*hour,*min,*sec);*/
	rtc_write(0x2,eeprom_read(0x2));
	rtc_write(0x1,eeprom_read(0x1));
	rtc_write(0x0,eeprom_read(0x0));
}