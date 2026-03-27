/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for the PSoC 4 - TCPWM dead time mode
*             for ModusToolbox.
*
* Related Document: See README.md 
*
*
*******************************************************************************
* (c) 2025, Infineon Technologies AG, or an affiliate of Infineon
* Technologies AG. All rights reserved.
* This software, associated documentation and materials ("Software") is
* owned by Infineon Technologies AG or one of its affiliates ("Infineon")
* and is protected by and subject to worldwide patent protection, worldwide
* copyright laws, and international treaty provisions. Therefore, you may use
* this Software only as provided in the license agreement accompanying the
* software package from which you obtained this Software. If no license
* agreement applies, then any use, reproduction, modification, translation, or
* compilation of this Software is prohibited without the express written
* permission of Infineon.
* 
* Disclaimer: UNLESS OTHERWISE EXPRESSLY AGREED WITH INFINEON, THIS SOFTWARE
* IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* INCLUDING, BUT NOT LIMITED TO, ALL WARRANTIES OF NON-INFRINGEMENT OF
* THIRD-PARTY RIGHTS AND IMPLIED WARRANTIES SUCH AS WARRANTIES OF FITNESS FOR A
* SPECIFIC USE/PURPOSE OR MERCHANTABILITY.
* Infineon reserves the right to make changes to the Software without notice.
* You are responsible for properly designing, programming, and testing the
* functionality and safety of your intended application of the Software, as
* well as complying with any legal requirements related to its use. Infineon
* does not guarantee that the Software will be free from intrusion, data theft
* or loss, or other breaches ("Security Breaches"), and Infineon shall have
* no liability arising out of any Security Breaches. Unless otherwise
* explicitly approved by Infineon, the Software may not be used in any
* application where a failure of the Product or any consequences of the use
* thereof can reasonably be expected to result in personal injury.
*******************************************************************************/

/******************************************************************************/
/*  Includes                                                                  */
/******************************************************************************/
#include "cy_pdl.h"
#include "cybsp.h"

/*******************************************************************************
 * Function Name: main
 * Summary:
 *  This is the main function.
 * Parameters:
 *  none
 * Return:
 *  int
 *******************************************************************************
 */
int main(void)
{
    cy_rslt_t result;

    /* Initialize the device and board peripherals */
    result = cybsp_init();
    
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }
    
    /* Enable global interrupts */
     __enable_irq();
    
    /* Initialize the TCPWM_PWM as PWM DT Mode */
    Cy_TCPWM_PWM_Init(pwm_HW, pwm_NUM, &pwm_config);
    
    /* Enable the TCPWM_PWM */
    Cy_TCPWM_PWM_Enable(pwm_HW, pwm_NUM);
    
    /* PWM dead time mode signal output */
    Cy_TCPWM_TriggerReloadOrIndex(pwm_HW, pwm_MASK);
    
    for(;;);
}

/* [] END OF FILE */
