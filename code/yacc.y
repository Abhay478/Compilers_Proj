%{
    #include "project.h"
%}

%union {
    struct ID id;
    enum type typ;
    char * str_c;
    char * op; // Should I make this an enum?
    int num;
    float fl;
};
%%
a : 'a' ;
%%

int main() {
    return 0;
}