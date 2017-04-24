/******************************************************************************
 * File:       /vv4os/io/pci.h                                                *
 * Author:     vodozhaba                                                      *
 * Created on: Apr 22, 2017                                                   *
 * Purpose:    Allows working with the PCI bus.                               *
 ******************************************************************************/

#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct PciDevice {
	uint8_t bus;
	uint8_t device : 5;
	uint8_t function : 3;
	struct PciDevice* next;
} __attribute__((packed)) PciDevice;

typedef struct {
	uint8_t header_type : 7;
	bool mf : 1;
} __attribute__((packed)) PciConfigHeaderType;

typedef struct {
	uint8_t completion_code : 4;
	uint8_t reserved : 2;
	bool start_bist : 1;
	bool bist_capable : 1;
} __attribute__((packed)) PciConfigBistRegister;

#define PCI_CONFIG_COMMON_OFFSET_VENDOR_ID 0x00
#define PCI_CONFIG_COMMON_OFFSET_DEVICE_ID 0x02
#define PCI_CONFIG_COMMON_OFFSET_COMMAND 0x04
#define PCI_CONFIG_COMMON_OFFSET_STATUS 0x06
#define PCI_CONFIG_COMMON_OFFSET_REVISION_ID 0x08
#define PCI_CONFIG_COMMON_OFFSET_PROG_IF 0x09
#define PCI_CONFIG_COMMON_OFFSET_SUBCLASS 0x0A
#define PCI_CONFIG_COMMON_OFFSET_CLASS_CODE 0x0B
#define PCI_CONFIG_COMMON_OFFSET_CACHE_LINE_SIZE 0x0C
#define PCI_CONFIG_COMMON_OFFSET_LATENCY_TIMER 0x0D
#define PCI_CONFIG_COMMON_OFFSET_HEADER_TYPE 0x0E
#define PCI_CONFIG_COMMON_OFFSET_BIST_REGISTER 0x0F

#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_BAR0 0x10
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_BAR1 0x14
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_BAR2 0x18
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_BAR3 0x1C
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_BAR4 0x20
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_BAR5 0x24
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_CARDBUS_CIS_POINTER 0x28
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_SUBSYSTEM_VENDOR_ID 0x2C
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_SUBSYSTEM_ID 0x2E
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_EXPANSION_ROM_BASE_ADDRESS 0x30
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_CAPABILITIES_POINTER 0x34
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_INTERRUPT_LINE 0x3C
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_INTERRUPT_PIN 0x3D
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_MIN_GRANT 0x3E
#define PCI_CONFIG_REGULAR_DEVICE_OFFSET_MAX_LATENCY 0x3F

#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_BAR0 0x10
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_BAR1 0x14
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_PRIMARY_BUS_NUMBER 0x18
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_SECONDARY_BUS_NUMBER 0x19
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_SUBORDINATE_BUS_NUMBER 0x1A
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_SECONDARY_LATENCY_TIMER 0x1B
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_IO_BASE 0x1C
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_IO_LIMIT 0x1D
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_SECONDARY_STATUS 0x1E
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_MEMORY_BASE 0x20
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_MEMORY_LIMIT 0x22
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_PREFETCHABLE_MEMORY_BASE 0x24
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_PREFETCHABLE_MEMORY_LIMIT 0x26
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_PREFETCHABLE_BASE_UPPER_32_BITS 0x28
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_PREFETCHABLE_LIMIT_UPEER_32_BITS 0x2C
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_IO_BASE_UPPER_16_BITS 0x30
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_IO_LIMIT_UPPER_16_BITS 0x32
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_CAPABILITIES_POINTER 0x34
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_EXPANSION_ROM_BASE_ADDRESS 0x38
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_INTERRUPT_LINE 0x3C
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_INTERRUPT_PIN 0x3D
#define PCI_CONFIG_PCI_TO_PCI_BRIDGE_OFFSET_BRIDGE_CONTROL 0x3E

extern PciDevice* pci_devices_list;

void PciInit();

uint8_t PciConfigReadFromDevice8(PciDevice* device, uint8_t offset);
uint16_t PciConfigReadFromDevice16(PciDevice* device, uint8_t offset);
uint32_t PciConfigReadFromDevice32(PciDevice* device, uint8_t offset);

void PciConfigWriteToDevice8(PciDevice* device, uint8_t offset, uint8_t data);
void PciConfigWriteToDevice16(PciDevice* device, uint8_t offset, uint16_t data);
void PciConfigWriteToDevice32(PciDevice* device, uint8_t offset, uint32_t data);

PciConfigHeaderType PciConfigReadHeaderTypeFromDevice(PciDevice* device);
PciConfigBistRegister PciConfigReadBistRegisterFromDevice(PciDevice* device);

