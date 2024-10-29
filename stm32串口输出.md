# 串口输出

进入`stm32f1xx_hal.c`

在`#include "stm32f1xx_hal.h"`的后面添加：

```c
#include <stdio.h>
extern UART_HandleTypeDef huart1;   //声明串口
int fputc(int ch, FILE *f)
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
```

在主函数中添加`#include <stdio.h>`

最后在魔法棒中勾选上MicroLIB。
