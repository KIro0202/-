#ifndef PLCmemory_h 

//паспорт, снилс, инн, диплом, военник, счёт

#include <stdint.h>

#define INPUT_SIZE   1024
#define OUTPUT_SIZE  1024
#define MERKER_SIZE  8192

uint8_t I_area[INPUT_SIZE];
uint8_t Q_area[OUTPUT_SIZE];
uint8_t M_area[MERKER_SIZE];



struct memory
{
   enum area{
    I, Q, M, DB
   };
   short byte_offset;
   short bit_offset;
   enum type{
    BIT, BYTE, WORD, DWORD
   }; 
};

struct value {

enum type{

}



}




void writeBYTE(valueByte, memory, base);
void readMemory(memory);
void writeBIT();


#endif