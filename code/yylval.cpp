#include "semantic.hpp"
using namespace std;

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
            case '8': return I8;
            case '1': return I16; 
            case '6': return I64;
            case '3': return I32;
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
        case PDT_VOID:
            return VOID;
    }
}

string get_pdt_str(PDT pdt) {
    switch(pdt) {
        case U8:
            return "uint8_t";
        case U16:
            return "uint16_t";
        case U32:
            return "uint32_t";
        case U64:
            return "uint64_t";
        case I8:
            return "int8_t";
        case I16:
            return "int16_t";
        case I32:
            return "int32_t";
        case I64:
            return "int64_t";
        case PDT_FLOAT:
            return "double";
        case PDT_CHAR:
            return "char";
        case PDT_BOOL:
            return "bool";
        case PDT_STR:
            return "string";
        case PDT_VOID:
            return "void";
        default: return "void"; // all cases are covered, default is unreachable (included to silence compiler warning)
    }
}

Variant::Variant(std::string tag, std::string val, Enum * este) {
    this->tag = tag;
    this->val = val;
    this->este = este;
}

GenericInner::GenericInner(int lit_int) {
    this->is_int = true;
    this->lit_int = lit_int;
}

GenericInner::GenericInner(Type * type) {
    this->is_int = false;
    this->type = type;
}
