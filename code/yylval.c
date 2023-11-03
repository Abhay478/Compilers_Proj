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
