/******************************************************************/
// Auther  : Mazen Adeeb                                          //
// Date    : 25/03/2022                                           //
// version : 0.0.1                                                //
// Driver  : UART_driver                                          //
/******************************************************************/

# include "std_types.h"
# include "bit_math.h"

# include "UART_config.h"
# include "UART_interface.h"
# include "UART_private.h"




void UART_u8VoidInit(void){
    /*Baud rate 9600*/
    u16 Local_u16BaudRate = 51 ; 
    u8 Local_u8UCSRCValue = 0b1000000 ; 
    /*Normal speed*/
    CLEAR_BIT(UART_U8_UCSRA_REG, 1);
    /*Disable MCPM*/
    CLEAR_BIT(UART_U8_UCSRA_REG, 0);
    /*Enable Rx & Tx*/
    SET_BIT(UART_U8_UCSRB_REG, 4);
    SET_BIT(UART_U8_UCSRB_REG, 3);
    /*Select 8 bit Data */
    CLEAR_BIT(UART_U8_UCSRB_REG, 2);
    SET_BIT(Local_u8UCSRCValue , 2);
    SET_BIT(Local_u8UCSRCValue , 1);
    /*Select asyn mode*/
    CLEAR_BIT(Local_u8UCSRCValue, 6);
    /*No parity bit */
    CLEAR_BIT(Local_u8UCSRCValue, 5);
    CLEAR_BIT(Local_u8UCSRCValue, 4);
    /*2 Stop bits mode */
    SET_BIT(Local_u8UCSRCValue, 3);
    /* Update UCSRC REG */
    UART_U8_UCSRC_REG = Local_u8UCSRCValue; 
    /*Baud rate*/
    UART_U8_UBRRL_REG = (u8)Local_u16BaudRate;
    UART_U8_UBRRH_REG = (u8)(Local_u16BaudRate >> 8 );
}

void UART_voidSendByte(u8 copy_u8data){

    /*wait until the transmit reg is empty*/
    while(GET_BIT(UART_U8_UCSRA_REG, 5) == 0);
    /* Send data byte */
    UART_U8_UDR_REG = copy_u8data ; 
    /*you can check your data is transmitted*/
}

u8 UART_u8RecieveByte(u8 * copy_pu8REcByte){

    u8 Local_errorState = STD_Sucesses ; 
    if (copy_pu8REcByte != NULL)
    {
        /*wait until the data is fully recived*/
        while (GET_BIT(UART_U8_UCSRA_REG, 7) == 0);
        /*Read Data */
        *copy_pu8REcByte = UART_U8_UDR_REG ; 
    }
    else{
        Local_errorState = STD_Error ; 
    }
    return Local_errorState ; 
}