#ifndef _STD_TYPES_H
#define _STD_TYPES_H

#define NULL 0

typedef unsigned char u8;
typedef unsigned short int u16; 
typedef unsigned long  int u32;   // long int = int =4 byte = 32 bit 

typedef signed char s8;
typedef signed short int s16;
typedef signed int s32;
typedef signed long long int s64;

typedef float f32;
typedef double f64;

typedef enum
{
FALSE,
TRUE		
}bool;



#define OK 0
#define NOK 1
#define NULL_pointer 2  
#define BusyFunc 3

#endif