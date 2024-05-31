/******************************************************************/
// Auther  : Mazen Adeeb                                          //
// Date    : 25/03/2022                                           //
// version : 0.0.1                                                //
// Driver  : UART_driver                                          //
/******************************************************************/
# ifndef UART_private_H
# define UART_private_H

# define UART_U8_UBRRH_REG         *((volatile u8 *)0x40)
# define UART_U8_UCSRC_REG         *((volatile u8 *)0x40)

# define UART_U8_UDR_REG           *((volatile u8 *)0x2c)

# define UART_U8_UCSRA_REG         *((volatile u8 *)0x2B)
# define UART_U8_UCSRB_REG         *((volatile u8 *)0x2A)

# define UART_U8_UBRRL_REG         *((volatile u8 *)0x29)



# endif