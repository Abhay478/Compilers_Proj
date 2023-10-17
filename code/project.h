#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


enum type {
    u8, u16, u32, u64,
    i8, i16, i32, i64,
    f32, f64,
    _bool,
    // Add more.
};
struct ID {
    char * name;
    enum type typ;
};    