//*****************************************************************************
//
//! \file      xhw_i2c.h
//! \brief     Macros used when accessing the I2C hardware.
//! \version   V2.2.1.0
//! \date      $CURRENTTIME$
//! \author    CooCox
//! \copyright
//!
//! Copyright (c)  2011, CooCox
//! All rights reserved.
//!
//! Redistribution and use in source and binary forms, with or without
//! modification, are permitted provided that the following conditions
//! are met:
//!     * Redistributions of source code must retain the above copyright
//! notice, this list of conditions and the following disclaimer.
//!     * Redistributions in binary form must reproduce the above copyright
//! notice, this list of conditions and the following disclaimer in the
//! documentation and/or other materials provided with the distribution.
//!     * Neither the name of the <ORGANIZATION> nor the names of its
//! contributors may be used to endorse or promote products derived
//! from this software without specific prior written permission.
//!
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//! AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//! IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//! ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
//! LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//! CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//! SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//! INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//! CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//! ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
//! THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************


#ifndef __XHW_I2C_H__
#define __XHW_I2C_H__

#include "xhw_types.h"
#include "xhw_ints.h"
#include "xcore.h"
#include "xhw_memmap.h"
#include "xhw_nvic.h"
#include "xhw_sysctl.h"
#include "xdebug.h"
#include "xsysctl.h"

//*****************************************************************************
//
//! \addtogroup CoX_Peripheral_Lib
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup I2C
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup LPC17xx_I2C_Register I2C Register Hardware Layer.
//! \brief      Here are detail register information.
//!             it contains:
//!                 - Register offset.
//!                 - detailed bit-field of the registers.
//!                 - Enum and mask of the registers.
//!
//! \note        Users can read or write the registers through xHWREG().
//!
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup LPC17xx_I2C_Register_Offsets I2C Register Offset(Map)
//! \brief      Here is the register offset, users can get the register address
//!             via <b>I2Cn_BASE + offset</b>, (n=0/1/..)
//! @{
//
//*****************************************************************************

//! I2C Control Set Register.When a one is written to a bit of this register, the
//! corresponding bit in the I2C control register is set.Writing a zero has no
//! effect on the corresponding bit in the I2C control register.
#define I2C_CONSET              ((unsigned long)0x00000000)


//! I2C Status Register.During I2C operation, this register provides detailed
//! status codes that allow software to determine the next action needed.
#define I2C_STAT                ((unsigned long)0x00000004)


//! I2C Data Register.During master or slave transmit mode, data to be transmitted
//! is written to this register.During master or slave receive mode, data that has
//! been received may be read from this register.
#define I2C_DAT                 ((unsigned long)0x00000008)


//! I2C Slave Address Register 0.Contains the 7-bit slave address for operation of
//! the I2C interface in slave mode, and is not used in master mode.The least
//! significant bit determines whether a slave responds to the General Call address.
#define I2C_ADR0                ((unsigned long)0x0000000C)

//! SCH Duty Cycle Register High Half Word.Determines the high time of the I2C clock.
#define I2C_SCLH                ((unsigned long)0x00000010)

//! SCL Duty Cycle Register Low Half Word.Determines the low time of the I2C
//! clock.I2nSCLL and I2nSCLH together determine the clock frequency generated by
//! an I2C master and certain times used in slave mode.
#define I2C_SCLL                ((unsigned long)0x00000014)

//! I2C Control Clear Register.When a one is written to a bit of this register,
//! the corresponding bit in the I2C control register is cleared.Writing a
//! zero has no effect on the corresponding bit in the I2C control register.
#define I2C_CONCLR              ((unsigned long)0x00000018)

//! Monitor mode control register.
#define I2C_MMCTRL              ((unsigned long)0x0000001C)

//! I2C Slave Address Register 1.Contains the 7-bit slave address for operation of
//! the I2C interface in slave mode, and is not used in master mode.The least
//! significant bit determines whether a slave responds to the General Call address.
#define I2C_ADR1                ((unsigned long)0x00000020)

//! I2C Slave Address Register 2.Contains the 7-bit slave address for operation of
//! the I2C interface in slave mode, and is not used in master mode.The least
//! significant bit determines whether a slave responds to the General Call address.
#define I2C_ADR2                ((unsigned long)0x00000024)

//! I2C Slave Address Register 3.Contains the 7-bit slave address for operation of
//! the I2C interface in slave mode, and is not used in master mode.The least
//! significant bit determines whether a slave responds to the General Call address.
#define I2C_ADR3                ((unsigned long)0x00000028)

//! Data buffer register.The contents of the 8 MSBs of the I2DAT shift register
//! will be transferred to the I2DATA_BUFFER automatically after every 9 bits (8
//! bits of data plus ACK or NACK) has been received on the bus.
#define I2C_DATABUF             ((unsigned long)0x0000002C)

//! I2C Slave address mask register 0.This mask register is associated with I2ADR0
//! to determine an address match.The mask register has no effect when
//! comparing to the General Call address ('0000000').
#define I2C_MASK0               ((unsigned long)0x00000030)

//! I2C Slave address mask register 1.This mask register is associated with I2ADR0
//! to determine an address match.The mask register has no effect when
//! comparing to the General Call address ('0000000').
#define I2C_MASK1               ((unsigned long)0x00000034)

//! I2C Slave address mask register 2.This mask register is associated with I2ADR0
//! to determine an address match.The mask register has no effect when
//! comparing to the General Call address ('0000000').
#define I2C_MASK2               ((unsigned long)0x00000038)

//! I2C Slave address mask register 3.This mask register is associated with I2ADR0
//! to determine an address match.The mask register has no effect when
//! comparing to the General Call address ('0000000').
#define I2C_MASK3               ((unsigned long)0x0000003C)

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup LPC17xx_I2C_Register_CONSET I2C Register CONSET
//! \brief      I2C CONSET Register description.
//!
//! @{
//
//*****************************************************************************

//! Asser acknowledge flag.
#define CONSET_AA                  BIT_32_2

//! I2C interrupt flag.
#define CONSET_SI                  BIT_32_3

//! Stop Flag.
#define CONSET_STO                 BIT_32_4

//! Start Flag.
#define CONSET_STA                 BIT_32_5

//! I2C interface enable.
#define CONSET_I2CEN               BIT_32_6

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup LPC17xx_I2C_Register_CONCLR I2C Register CONCLR
//! \brief      I2C CONCLR Register description.
//!
//! @{
//
//*****************************************************************************

//! Assert acknowledge clear bit.
#define CONCLR_AAC                  BIT_32_2

//! I2C interrupt clear bit.
#define CONCLR_SIC                  BIT_32_3

//! Start flag clear bit.
#define CONCLR_STAC                 BIT_32_5

//! I2C interface disable bit.
#define CONCLR_I2CENC               BIT_32_6

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup LPC17xx_I2C_Register_STAT I2C Register STAT
//! \brief      I2C STAT Register description.
//!
//! @{
//
//*****************************************************************************

//! I2C interface status.
#define STAT_STATUS_M               BIT_MASK(32, 7, 3)

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup LPC17xx_I2C_Register_DAT I2C Register DAT
//! \brief      I2C DAT Register description.
//!
//! @{
//
//*****************************************************************************

//! Data value mask.
#define DAT_DATA_M                  BIT_MASK(32, 7, 0)

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup LPC17xx_I2C_Register_MMCTRL I2C Register MMCTRL
//! \brief      I2C MMCTRL Register description.
//!
//! @{
//
//*****************************************************************************

//! Monitor mode enable.
#define MMCTRL_MM_ENA              BIT_32_0

//! SCL output enable.
#define MMCTRL_ENA_SCL             BIT_32_1

//! Select interrupt register match.
#define MMCTRL_MATCH_ALL           BIT_32_2

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup LPC17xx_I2C_Register_DATABUF I2C Register DATABUF
//! \brief      I2C DATABUF Register description.
//!
//! @{
//
//*****************************************************************************

//! Data buffer mask.
#define DATABUF_DATA_M             BIT_MASK(32, 7, 0)

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup LPC17xx_I2C_Register_ADR I2C Register ADR
//! \brief      I2C ADR Register description.
//!
//! @{
//
//*****************************************************************************

//! General Call Enable Bit.
#define ADR_GC                     BIT_32_0

//! I2C device address for slave mode.
#define ADR_ADDR_M                 BIT_MASK(32, 7, 1)

//! I2C device address for slave mode shift.
#define ADR_ADDR_S                 1

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup LPC17xx_I2C_Register_MASK I2C Register MASK
//! \brief      I2C ADR Register description.
//!
//! @{
//
//*****************************************************************************

//! Mask Bits.
#define MASK_MASK_M                 BIT_MASK(32, 7, 1)

//! I2C device address for slave mode shift.
#define MASK_MASK_S                 1

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup LPC17xx_I2C_Register_SCLH I2C Register SCLH
//! \brief      I2C SCLH Register description.
//!
//! @{
//
//*****************************************************************************

//! Count for SCL High time period selection.
#define SCLH_SCLH_M                 BIT_MASK(32, 15, 0)

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup LPC17xx_I2C_Register_SCLL I2C Register SCLL
//! \brief      I2C SCLL Register description.
//!
//! @{
//
//*****************************************************************************

//! Count for SCL low time period selection.
#define SCLL_SCLL_M                 BIT_MASK(32, 15, 0)

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

#endif // __XHW_I2C_H__
