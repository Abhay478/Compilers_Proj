#include "semantic.h"

PDT get_pdt(char * s) {
    switch(s[0]) {
        case 'U': switch(s[1]) {
            case '8': return U8;
            case '1': return U16; 
            case '6': return U64;
            case '3': return U32;
        };
        break;
        case 'I': switch(s[1]) {
            case '8': return U8;
            case '1': return U16; 
            case '6': return U64;
            case '3': return U32;
        };
        break;
        case 'F': return PDT_FLOAT;
        case 'C': return PDT_CHAR;
        case 'B': return PDT_BOOL;
        case 'S': return PDT_STR;
    }
    return I32;
}

VarTypes get_vt(PDT pdt) {
    switch(pdt) {
        case U8:
        case U16:
        case U32:
        case U64:
        case I8:
        case I16:
        case I32:
        case I64:
            return INT;
        case PDT_FLOAT:
            return FLOAT;
        case PDT_CHAR:
            return CHAR;
        case PDT_BOOL:
            return BOOL;
        case PDT_STR:
            return STR;
    }
    return INT;
}
