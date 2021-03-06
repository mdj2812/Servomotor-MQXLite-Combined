/**HEADER*********************************************************************
*
* Copyright (c) 2010 Freescale Semiconductor;
* All Rights Reserved
*
******************************************************************************
*
* THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
* STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
*
* $FileName: psp_cpudef.h$
* $Version : 3.8.11.0$
* $Date    : Sep-8-2011$
*
* Comments:
*   Processor and platform identifiers defined here
*
*END*************************************************************************/

#ifndef __psp_cpudef_h__
    #define __psp_cpudef_h__

#include "mqx_cpudef.h"

/* CPU groups for Kinetis K-Series */
#define PSP_CPU_GROUP_KINETIS_K1X       (0x01)
#define PSP_CPU_GROUP_KINETIS_K2X       (0x02)
#define PSP_CPU_GROUP_KINETIS_K3X       (0x03)
#define PSP_CPU_GROUP_KINETIS_K4X       (0x04)
#define PSP_CPU_GROUP_KINETIS_K5X       (0x05)
#define PSP_CPU_GROUP_KINETIS_K6X       (0x06)
#define PSP_CPU_GROUP_KINETIS_K7X       (0x07)

/* CPU groups for Kinetis GP L-Series */
#define PSP_CPU_GROUP_KINETIS_KL0X      (0x20)
#define PSP_CPU_GROUP_KINETIS_KL1X      (0x21)
#define PSP_CPU_GROUP_KINETIS_KL2X      (0x22)
#define PSP_CPU_GROUP_KINETIS_KL3X      (0x23)
#define PSP_CPU_GROUP_KINETIS_KL4X      (0x24)

/* CPU groups for Kinetis GP E-Series */
#define PSP_CPU_GROUP_KINETIS_KE0X      (0x30)
#define PSP_CPU_GROUP_KINETIS_KE1X      (0x31)
#define PSP_CPU_GROUP_KINETIS_KE2X      (0x32)
#define PSP_CPU_GROUP_KINETIS_KE3X      (0x33)
#define PSP_CPU_GROUP_KINETIS_KE4X      (0x34)
#define PSP_CPU_GROUP_KINETIS_KE5X      (0x35)
#define PSP_CPU_GROUP_KINETIS_KE6X      (0x36)

/* Specific CPU identification macros */
/* Kinetis GP K-Series family with Cortex M4 core */
#define PSP_CPU_K1X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M4, PSP_CPU_GROUP_KINETIS_K1X, 0xF))
#define PSP_CPU_K2X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M4, PSP_CPU_GROUP_KINETIS_K2X, 0xF))
#define PSP_CPU_K3X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M4, PSP_CPU_GROUP_KINETIS_K3X, 0xF))
#define PSP_CPU_K4X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M4, PSP_CPU_GROUP_KINETIS_K4X, 0xF))
#define PSP_CPU_K5X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M4, PSP_CPU_GROUP_KINETIS_K5X, 0xF))
#define PSP_CPU_K6X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M4, PSP_CPU_GROUP_KINETIS_K6X, 0xF))
#define PSP_CPU_K7X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M4, PSP_CPU_GROUP_KINETIS_K7X, 0xF))

/* Kinetis GP L-Series family with Cortex M0+ core */
#define PSP_CPU_KL0X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KL0X, 0xF))
#define PSP_CPU_KL1X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KL1X, 0xF))
#define PSP_CPU_KL2X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KL2X, 0xF))
#define PSP_CPU_KL3X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KL3X, 0xF))
#define PSP_CPU_KL4X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KL4X, 0xF))

/* Kinetis GP E-Series family with Cortex M0+ core */
#define PSP_CPU_KE0X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KE0X, 0xF))
#define PSP_CPU_KE1X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KE1X, 0xF))
#define PSP_CPU_KE2X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KE2X, 0xF))
#define PSP_CPU_KE3X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KE3X, 0xF))
#define PSP_CPU_KE4X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KE4X, 0xF))
#define PSP_CPU_KE5X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KE5X, 0xF))
#define PSP_CPU_KE6X            (PSP_CPU_NUM(PSP_CPU_ARCH_ARM_CORTEX_M0P, PSP_CPU_GROUP_KINETIS_KE6X, 0xF))

/* CPU id check support macros */
/* Kinetis GP K-Series family */
#define PSP_MQX_CPU_IS_KINETIS_K1X  ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_K1X))
#define PSP_MQX_CPU_IS_KINETIS_K2X  ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_K2X))
#define PSP_MQX_CPU_IS_KINETIS_K3X  ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_K3X))
#define PSP_MQX_CPU_IS_KINETIS_K4X  ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_K4X))
#define PSP_MQX_CPU_IS_KINETIS_K5X  ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_K5X))
#define PSP_MQX_CPU_IS_KINETIS_K6X  ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_K6X))
#define PSP_MQX_CPU_IS_KINETIS_K7X  ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_K7X))

/* Kinetis GP L-Series family */
#define PSP_MQX_CPU_IS_KINETIS_KL0X ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_KL0X))
#define PSP_MQX_CPU_IS_KINETIS_KL1X ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_KL1X))
#define PSP_MQX_CPU_IS_KINETIS_KL2X ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_KL2X))
#define PSP_MQX_CPU_IS_KINETIS_KL3X ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_KL3X))
#define PSP_MQX_CPU_IS_KINETIS_KL4X ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_KL4X))


/* Kinetis GP E-Series family */
#define PSP_MQX_CPU_IS_KINETIS_KE0X ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_KE0X))
#define PSP_MQX_CPU_IS_KINETIS_KE1X ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_KE1X))
#define PSP_MQX_CPU_IS_KINETIS_KE2X ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_KE2X))
#define PSP_MQX_CPU_IS_KINETIS_KE3X ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_KE3X))
#define PSP_MQX_CPU_IS_KINETIS_KE4X ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_KE4X))
#define PSP_MQX_CPU_IS_KINETIS_KE5X ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_KE5X))
#define PSP_MQX_CPU_IS_KINETIS_KE6X ((PSP_GET_CPU_GROUP(MQX_CPU) == PSP_CPU_GROUP_KINETIS_KE6X))


/* Kinetis GP K-Series family */
#define PSP_MQX_CPU_IS_KINETIS_K    (PSP_MQX_CPU_IS_KINETIS_K1X | \
                                     PSP_MQX_CPU_IS_KINETIS_K2X | \
                                     PSP_MQX_CPU_IS_KINETIS_K3X | \
                                     PSP_MQX_CPU_IS_KINETIS_K4X | \
                                     PSP_MQX_CPU_IS_KINETIS_K5X | \
                                     PSP_MQX_CPU_IS_KINETIS_K6X | \
                                     PSP_MQX_CPU_IS_KINETIS_K7X )
/* Kinetis GP L-Series family */
#define PSP_MQX_CPU_IS_KINETIS_L    (PSP_MQX_CPU_IS_KINETIS_KL0X | \
                                     PSP_MQX_CPU_IS_KINETIS_KL1X | \
                                     PSP_MQX_CPU_IS_KINETIS_KL2X | \
                                     PSP_MQX_CPU_IS_KINETIS_KL3X | \
                                     PSP_MQX_CPU_IS_KINETIS_KL4X )
/* Kinetis GP E-Series family */
#define PSP_MQX_CPU_IS_KINETIS_E    (PSP_MQX_CPU_IS_KINETIS_KE0X | \
                                     PSP_MQX_CPU_IS_KINETIS_KE1X | \
                                     PSP_MQX_CPU_IS_KINETIS_KE2X | \
                                     PSP_MQX_CPU_IS_KINETIS_KE3X | \
                                     PSP_MQX_CPU_IS_KINETIS_KE4X | \
                                     PSP_MQX_CPU_IS_KINETIS_KE5X | \
                                     PSP_MQX_CPU_IS_KINETIS_KE6X)


#endif /* __psp_cpudef_h__ */
