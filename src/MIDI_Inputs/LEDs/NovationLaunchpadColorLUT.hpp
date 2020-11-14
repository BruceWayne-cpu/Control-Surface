#pragma once

#include <AH/Arduino-Wrapper.h>

/// Lookup table for the colors of the LEDs used by Novation Launchpad control
/// surfaces. Indexed by velocity value [0, 0x7F], byte order BGR.
static const uint8_t NovationLaunchpadColorLUT[][3] PROGMEM = {
    {0x00, 0x00, 0x00}, // 0x00
    {0x25, 0x25, 0x25}, // 0x01
    {0x8F, 0x8F, 0x8F}, // 0x02
    {0xFD, 0xFD, 0xFD}, // 0x03
    {0x58, 0x66, 0xFF}, // 0x04
    {0x00, 0x29, 0xFF}, // 0x05
    {0x00, 0x0A, 0x6E}, // 0x06
    {0x00, 0x01, 0x22}, // 0x07
    {0x75, 0xC8, 0xFF}, // 0x08
    {0x00, 0x6D, 0xFF}, // 0x09
    {0x00, 0x29, 0x6E}, // 0x0A
    {0x00, 0x1F, 0x30}, // 0x0B
    {0x29, 0xFA, 0xFD}, // 0x0C
    {0x00, 0xFA, 0xFD}, // 0x0D
    {0x00, 0x69, 0x6B}, // 0x0E
    {0x00, 0x1F, 0x20}, // 0x0F
    {0x36, 0xF8, 0x8E}, // 0x10
    {0x00, 0xF8, 0x45}, // 0x11
    {0x00, 0x69, 0x17}, // 0x12
    {0x00, 0x33, 0x17}, // 0x13
    {0x38, 0xF8, 0x32}, // 0x14
    {0x00, 0xF8, 0x00}, // 0x15
    {0x00, 0x68, 0x00}, // 0x16
    {0x00, 0x1F, 0x00}, // 0x17
    {0x57, 0xF8, 0x31}, // 0x18
    {0x00, 0xF8, 0x00}, // 0x19
    {0x00, 0x68, 0x00}, // 0x1A
    {0x00, 0x1F, 0x00}, // 0x1B
    {0x90, 0xF9, 0x2F}, // 0x1C
    {0x4A, 0xF8, 0x00}, // 0x1D
    {0x19, 0x69, 0x00}, // 0x1E
    {0x12, 0x24, 0x00}, // 0x1F
    {0xBE, 0xF9, 0x2A}, // 0x20
    {0xA2, 0xF8, 0x00}, // 0x21
    {0x40, 0x69, 0x00}, // 0x22
    {0x12, 0x1F, 0x00}, // 0x23
    {0xFF, 0xCB, 0x42}, // 0x24
    {0xFF, 0xB7, 0x00}, // 0x25
    {0x64, 0x51, 0x00}, // 0x26
    {0x20, 0x14, 0x00}, // 0x27
    {0xFF, 0x9C, 0x50}, // 0x28
    {0xFF, 0x6C, 0x00}, // 0x29
    {0x6D, 0x27, 0x00}, // 0x2A
    {0x21, 0x07, 0x00}, // 0x2B
    {0xFF, 0x65, 0x58}, // 0x2C
    {0xFF, 0x33, 0x04}, // 0x2D
    {0x6E, 0x10, 0x01}, // 0x2E
    {0x21, 0x02, 0x00}, // 0x2F
    {0xFF, 0x66, 0x97}, // 0x30
    {0xFF, 0x35, 0x64}, // 0x31
    {0x7A, 0x13, 0x1D}, // 0x32
    {0x41, 0x06, 0x0C}, // 0x33
    {0xFF, 0x6D, 0xFF}, // 0x34
    {0xFF, 0x40, 0xFF}, // 0x35
    {0x6D, 0x16, 0x6F}, // 0x36
    {0x21, 0x02, 0x22}, // 0x37
    {0x96, 0x68, 0xFF}, // 0x38
    {0x64, 0x2C, 0xFF}, // 0x39
    {0x23, 0x0C, 0x6E}, // 0x3A
    {0x14, 0x02, 0x2D}, // 0x3B
    {0x00, 0x33, 0xFF}, // 0x3C
    {0x00, 0x48, 0xAD}, // 0x3D
    {0x00, 0x63, 0x8E}, // 0x3E
    {0x00, 0x75, 0x4E}, // 0x3F
    {0x00, 0x45, 0x00}, // 0x40
    {0x41, 0x65, 0x00}, // 0x41
    {0x91, 0x67, 0x00}, // 0x42
    {0xFF, 0x33, 0x04}, // 0x43
    {0x60, 0x55, 0x00}, // 0x44
    {0xDB, 0x2A, 0x25}, // 0x45
    {0x8F, 0x8F, 0x8F}, // 0x46
    {0x2A, 0x2A, 0x2A}, // 0x47
    {0x00, 0x27, 0xFF}, // 0x48
    {0x00, 0xF9, 0xC4}, // 0x49
    {0x00, 0xEC, 0xB7}, // 0x4A
    {0x00, 0xF8, 0x61}, // 0x4B
    {0x00, 0x96, 0x00}, // 0x4C
    {0x8D, 0xF8, 0x00}, // 0x4D
    {0xFF, 0xB7, 0x00}, // 0x4E
    {0xFF, 0x3F, 0x02}, // 0x4F
    {0xFF, 0x33, 0x46}, // 0x50
    {0xFF, 0x37, 0x8C}, // 0x51
    {0x90, 0x32, 0xC3}, // 0x52
    {0x00, 0x2B, 0x53}, // 0x53
    {0x00, 0x62, 0xFF}, // 0x54
    {0x00, 0xE2, 0x92}, // 0x55
    {0x00, 0xF8, 0x72}, // 0x56
    {0x00, 0xF8, 0x00}, // 0x57
    {0x00, 0xF8, 0x00}, // 0x58
    {0x74, 0xF8, 0x4C}, // 0x59
    {0xD4, 0xF9, 0x00}, // 0x5A
    {0xFF, 0x9C, 0x61}, // 0x5B
    {0xD3, 0x66, 0x32}, // 0x5C
    {0xF1, 0x92, 0x95}, // 0x5D
    {0xFF, 0x3F, 0xDE}, // 0x5E
    {0x6D, 0x2D, 0xFF}, // 0x5F
    {0x00, 0x91, 0xFF}, // 0x60
    {0x00, 0xBC, 0xC5}, // 0x61
    {0x00, 0xF8, 0x98}, // 0x62
    {0x00, 0x6F, 0x95}, // 0x63
    {0x00, 0x34, 0x4A}, // 0x64
    {0x03, 0x5C, 0x06}, // 0x65
    {0x47, 0x61, 0x00}, // 0x66
    {0x36, 0x1A, 0x18}, // 0x67
    {0x6D, 0x2D, 0x13}, // 0x68
    {0x1D, 0x4D, 0x7E}, // 0x69
    {0x00, 0x1A, 0xBC}, // 0x6A
    {0x44, 0x68, 0xE9}, // 0x6B
    {0x00, 0x7D, 0xE5}, // 0x6C
    {0x00, 0xE4, 0xFF}, // 0x6D
    {0x00, 0xE3, 0xA7}, // 0x6E
    {0x00, 0xBE, 0x6F}, // 0x6F
    {0x40, 0x25, 0x24}, // 0x70
    {0x66, 0xFA, 0xE2}, // 0x71
    {0xC5, 0xF9, 0x84}, // 0x72
    {0xFF, 0xAB, 0xA7}, // 0x73
    {0xFF, 0x7D, 0x9E}, // 0x74
    {0x51, 0x51, 0x51}, // 0x75
    {0x87, 0x87, 0x87}, // 0x76
    {0xFD, 0xFC, 0xE4}, // 0x77
    {0x00, 0x19, 0xB5}, // 0x78
    {0x00, 0x04, 0x46}, // 0x79
    {0x00, 0xD5, 0x00}, // 0x7A
    {0x00, 0x4F, 0x00}, // 0x7B
    {0x00, 0xBC, 0xC5}, // 0x7C
    {0x00, 0x3E, 0x4E}, // 0x7D
    {0x00, 0x71, 0xC3}, // 0x7E
    {0x00, 0x1C, 0x5D}, // 0x7F
};