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
#include <gsl/gsl_sf_bessel.h>

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    ADC_SEQ_Start();
    VDAC_Start();
    

    for(;;)
    {
        //TimeMeasurement_Write(1);
        
        //Lê as amostras do ADC
        ADC_SEQ_StartConvert();
        ADC_SEQ_IsEndConversion(ADC_SEQ_WAIT_FOR_RESULT);
        int16 sample = ADC_SEQ_GetResult16(0);
        
        
        double x = 5.0;
        double y = gsl_sf_bessel_J0 (x);
        
        if(y>1.0)
        {
            CyDelay(10);
        }
        
        
        //Escreve o resultado no DA
        VDAC_SetValue((uint8)((sample &0xFFF0) >> 4));
        
        //TimeMeasurement_Write(0);
        
        CyDelay(10);
        
    }
}

/* [] END OF FILE */
