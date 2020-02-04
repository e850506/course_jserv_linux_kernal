/*
    Created by unknowntpo at 2020.2.3 (Mon)
    @title : Bit field practice (with bit-field)
    @abstract : declaration of date with the use of bit fields.
*/
#include <stdbool.h>
#include <stdio.h>
bool is_one(int i) { return i == 1; } // a function input
int main() {
    struct { signed int a : 1; } obj = { .a = 1 }; // struct.
    // obj is a structure variable.
    puts(is_one(obj.a) ? "one" : "not one"); // puts vs printf?
    return 0;
}