#include "semantic.hpp"

PDT get_pdt(char * s) {
    switch(s[0]) {
        case 'u': switch(s[1]) {
            case '8': return U8;
            case '1': return U16; 
            case '6': return U64;
            case '3': return U32;
        };
        break;
        case 'i': switch(s[1]) {
            case '8': return U8;
            case '1': return U16; 
            case '6': return U64;
            case '3': return U32;
        };
        break;
        case 'f': return PDT_FLOAT;
        case 'c': return PDT_CHAR;
        case 'b': return PDT_BOOL;
        case 's': return PDT_STR;
    }
    return I32;
}

VarTypes get_vt(PDT pdt) {
    switch(pdt) {
        default: // all cases are covered, default is unreachable (included to silence compiler warning)
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
}

Variant::Variant(std::string tag, std::string val, Enum * este) {
    this->tag = tag;
    this->val = val;
    this->este = este;
}

GenericInner::GenericInner(void * val, int which) {
    this->val = val;
    this->which = which;
}
