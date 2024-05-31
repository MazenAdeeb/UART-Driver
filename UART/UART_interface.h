/******************************************************************/
// Auther  : Mazen Adeeb                                          //
// Date    : 25/03/2022                                           //
// version : 0.0.1                                                //
// Driver  : UART_driver                                          //
/******************************************************************/
# ifndef UART_INTERFACE_H
# define UART_INTERFACE_H

void UART_u8VoidInit(void);

void UART_voidSendByte(u8 copy_u8data);

u8 UART_u8RecieveByte(u8 * copy_pu8REcByte);





# endif