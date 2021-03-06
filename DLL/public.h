/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

Module Name:

    BulkUsr.h

Abstract:

Environment:

    User & Kernel mode

--*/

#ifndef _USER_H
#define _USER_H

#include <initguid.h>
#include "Hsi_regs.h"



typedef struct _REG_STRUCT{
	unsigned char loc;			// Register address
	unsigned char pos;			// Bit field start in the register byte
	unsigned char width;		//Bit field width [bits]
	unsigned char value;
}REG_STRUCT, *PREG_STRUCT;

// {CAE771C7-09E4-40b0-B670-0163498A099D}
DEFINE_GUID(GUID_CLASS_MIPIHSI_USB , 
0xcae771c7, 0x9e4, 0x40b0, 0xb6, 0x70, 0x1, 0x63, 0x49, 0x8a, 0x9, 0x9d);


#define IOCTL_INDEX             0x800


#define IOCTL_MIPI_GET_CONFIG_DESCRIPTOR CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX,     \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)
                                                   
#define IOCTL_MIPI_RESET_DEVICE          CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX + 1, \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)

#define IOCTL_MIPI_RESET_PIPE            CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX + 2, \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)

#define IOCTL_MIPI_RESET            	 CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX + 3, \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)

#define IOCTL_MIPI_READ_REG            	 CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX + 4, \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)

#define IOCTL_MIPI_WRITE_REG             CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX + 5, \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)


#define IOCTL_MIPI_DUMP_REG             CTL_CODE(FILE_DEVICE_UNKNOWN,     \
                                                     IOCTL_INDEX + 6, \
                                                     METHOD_BUFFERED,         \
                                                     FILE_ANY_ACCESS)

int loopback_test(__in int times);
int Get_Register(
	__in  HANDLE hDevice,
	__in  REG_STRUCT *pos_reg,
	__out unsigned char *regs,
	__in __out int *reg_num
	);
	
int Dump_Register(
	__in  HANDLE hDevice,
	__out unsigned char *regs,
	__out int *reg_num
	);
	
int Set_Register(
	__in HANDLE hDevice,
	__in REG_STRUCT *pos_reg,
	__in int num_reg
	);

int Send_Data(
	__in HANDLE hDevice,
	__in int channel,
	__in unsigned char *buf,
	__in int length
	);

HANDLE
	Open_Device(
	__in BOOL Synchronous
	);
	
void Start_Recieve(HANDLE hDevice);	

#endif

