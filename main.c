/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
uint8 addr_read(void)
{
    uint8 reg = OUTPUT_REG_Read();    
    switch (reg)
    {
        case 0x01: return 0;
        case 0x02: return 1;
        case 0x04: return 2;
        case 0x08: return 3;
        case 0x10: return 4;
        case 0x20: return 5;
        case 0x40: return 6;
        case 0x80: return 7;
        default:   return 0xFF;
    }
}
int main(void)
{
    CyGlobalIntEnable;
    
    G0_G1_G2_Write(0x01 & 0x07);
    
    for(;;)
    {   

        for (uint8 count = 0; count <= 7; count++)
        {   
            DBG_PIN_Write(1);
            
            ADDR_SEL_Write(count & 0x07);

            uint8 decoded_addr = addr_read();
            
            if (decoded_addr == count)
            {
                OUT_LED_Write(0);
            }
            else
            {
                OUT_LED_Write(1);
            }
            DBG_PIN_Write(0);
        }
    }
}
/* [] END OF FILE */