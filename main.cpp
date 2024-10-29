
#include <stdio.h>
extern UART_HandleTypeDef huart1;   //声明串口
int fputc(int ch, FILE *f)     // 输出重定向
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
  return ch;
}
int fgetc(FILE *f)
{
  uint8_t ch = 0;
  HAL_UART_Receive(&huart1, &ch, 1, 0xffff);
  return ch;
}
