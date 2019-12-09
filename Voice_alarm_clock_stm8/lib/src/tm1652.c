#include "tm1652.h"


void Delay(uint32_t nCount)
{
  while (nCount != 0)
  {
    nCount--;
  }
}

void SHUMAGUAN_Init(void)
{

  GPIO_Init(TM1652_GPIO, TM1652_SDA, GPIO_MODE_OUT_PP_HIGH_FAST);//初始化TM1651 推挽输出high 10M
  Delay(5000);
  TM1652_Set(0x18,0x38);//初始化
}
    
///=======================================
void Delay_us(u8 i) //nus 延时  2.5us
{
  for(; i>0; i--)
  {
    nop(); nop(); nop();nop(); 
    nop(); nop(); nop();nop(); 
  }        
}

//=========================================
void I2CWrByte(u8 sdat) //写一个字节
{
  unsigned char i=0, sfalg=0;
  GPIO_WriteHigh(TM1652_GPIO, TM1652_SDA);
  GPIO_WriteLow(TM1652_GPIO, TM1652_SDA);
  Delay_us(52);    //保持52us
  
 //发送8位数据
  for(i=0; i<8; i++)
  {
      if(sdat & 0x01)
      {
          GPIO_WriteHigh(TM1652_GPIO, TM1652_SDA);
          sfalg++;
      }else
      {
          GPIO_WriteLow(TM1652_GPIO, TM1652_SDA);
      }
      Delay_us(52); 
      sdat >>=1;
  }

  //校验位,按照发送数据中1的个数来判断
  if(sfalg%2==0)			         
  {
      GPIO_WriteHigh(TM1652_GPIO, TM1652_SDA);
  }
  else			        
  {
      GPIO_WriteLow(TM1652_GPIO, TM1652_SDA);
  }
  Delay_us(52); 
  
  //停止位
  GPIO_WriteHigh(TM1652_GPIO, TM1652_SDA);  
  Delay_us(52);   
}



void TM1652_Set(u8 add,u8 dat) //数码管显示
{
	I2CWrByte(add); //第一个显存地址
        Delay_us(10);
	I2CWrByte(dat);
        Delay_us(10);
}


//----------------------------------------------------------------------------------------------------------------------------------



u8 duty[16]={0x00,0x80,0x40,0xc0,0x20,0xa0,0x60,0xe0,0x10,0x90,0x50,0xd0,0x30,0xb0,0x70,0xf0};
u8 imax[8]={0x00,0x08,0x04,0x0c,0x02,0x0a,0x06,0x0e};
u8 RG_DOT_5[]={0,1,2,4,8,16,32};
u8 CODE[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f, //0~9显示代码
             0x77,0x7c,0x58,0x5e,0x79,0x71,                     //a~f显示代码
             0x6f,0x76,0x04,0x38,0x54,0x5c,0x73,0x50,0x6d,0x78,0x1c,0x3e,0x00,0x6e,0x40}; 


void  display(u8 disnum,u8 disbit,u8 dotbit)  //显示的数值，第几位显示，是否闪烁，是否带小数点
{
      u8 discode;
      discode=CODE[disnum];
      if(dotbit==1)  discode=discode|0x80;
      if (disbit==1)        TM1652_Set(0x08,discode);//GR1
      else if (disbit==2)  TM1652_Set(0x88,discode);//GR2
      else if (disbit==3)  TM1652_Set(0x48,discode);//GR3
      else if (disbit==4)  TM1652_Set(0xc8,discode);//GR4      
      Delay(1800);      
}


void backlight(u8 i,u8 d){
  
  
  
  Delay(1000);
  u8 num = (duty[d]&0xf0)|(imax[i]&0x0f);
  
  TM1652_Set(0x18,num);
  Delay(1000);
  
  
//  switch(i){
//    case 0:
//      TM1652_Set(0x18,0x00);
//    break;
//
//    case 1:
//      TM1652_Set(0x18,0x88);
//    break;
//
//    case 2:
//      TM1652_Set(0x18,0x84);
//    break;
//
//    case 3:
//      TM1652_Set(0x18,0x8c);
//    break;
//
//    case 4:
//      TM1652_Set(0x18,0x82);
//    break;
//
//    case 5:
//      TM1652_Set(0x18,0x8a);
//    break;
//
//    case 6:
//      TM1652_Set(0x18,0x86);
//    break;
//
//    case 7:
//      TM1652_Set(0x18,0x8e);
//    break;
//  }
  
  
}





