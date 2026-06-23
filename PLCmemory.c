#include "PLCmemory.h"
#include <string.h>




uint8_t valueByte = 0;
uint16_t valueWord = 0;
uint32_t valueDouble = 0;
int offset = 0;
uint8_t *base;
struct memory memory;






switch (memory.area){
    case M: base = M_area; break;
    case I: base = I_area; break;
    case Q: base = Q_area; break;
}

switch (memory.type){
    case BIT: 
    writeBit();
    break;
    case BYTE:
    writeBYTE();
    break;
    case WORD:
    writeWORD();
    break;
    case DWORD:
    writeDWROD();
    break;
}


void writeBIT(valueByte, memory, base) { //сука ну мёд
    uint8_t byte;
    if (valueByte==1){
    byte = *(base + memory.byte_offset) | (1 << memory.bit_offset);
    }
    else{
        byte = *(base + memory.byte_offset) & ~(1 << memory.bit_offset);
    }
    *(base + memory.byte_offset) = byte;
    return;
}


void writeBYTE(valueByte, memory, base){
    *(base + memory.byte_offset) = valueByte;
}

void writeWORD(valueWord, memory, base){
    *(base + memory.byte_offset) = valueWord;
}

void writeDOUBLE (valueDouble, memory, base){
    *(base + memory.byte_offset) = valueDouble;
}

uint8_t readBYTE (memory, base){
    return *(base + memory.byte_offset);
}

uint16_t readWORD(memory, base)
{
    return *(uint16_t *)(base + addr.byte_offset);
}


uint32_t readDOUBLE (memory, base){
    return *(uint32_t *)(base + addr.byte_offset);
}


/* //M3.5 = 1
struct memory write_merkers;

    write_merkers.area  M;
    write_merkers.byte_offset = 3;
    write_merkers.bit_offset = 5;
    write_merkers.type = BIT;


 */
}