/* ------------------------------------------------------------------- *
 *  @file:     bitops.c                                                *
 *  @author:   julie.engel@mail.com                                    *
 *  @compiler: gcc version 4.2.1 20080704 (Red Hat 4.1.2-46)           *
 * ------------------------------------------------------------------- */
/* note: one unsigned char is exactly one byte (8 bits) */

/* == Includes ============================================================= */

#include <stdio.h>

/* == Defines ============================================================== */

/* Attribute to define function parameters as intentionally unused */
#define __UNUSED__ __attribute__(( unused ))

/* == Bit Operation Helper Function ======================================== */

/**
 * Prints out the binary value of the given byte. Helper function.
 *
 * @param       val     the byte we want the binary value from
 * @return      void
 */
void decbin_output(unsigned char val) {

    int i;
    unsigned char value = val;
    unsigned char str[9];
    
    for (i = 7; i >= 0; i--) {
        str[7-i] = '0' + ((val >> i) & 0x1);
    }
    str[8] = 0;

    printf("%03d = %s\n", value, str);
    return;
}

/* == Bit Operation Demo Functions ========================================= */

/**
 * Performs a bitwise AND.
 *
 * The bitwise AND will copy a bit to the result if it exists in
 * both operands. If we evaluate the truth table:
 *
 *                      a   b   q
 *                      0   0   0
 *                      0   1   0
 *                      1   0   0
 *                      1   1   1
 *
 *  we see that only in the last line, where both a and b are 1, q
 *  is also set to 1, because, as we said, q = 1 if a & b = 1.
 *
 * @param       a       first operand
 * @param       b       second operand
 * @return      q       result of the bitwise AND
 */
unsigned char bitwise_and(unsigned char a,
                          unsigned char b) {
    unsigned char q = 0;

    q = a & b;
    decbin_output(q);

    return q;
}


/**
 * Performs a bitwise OR.
 *
 * The bitwise OR will copy a bit if it exists in either operand,
 * or both. If we evalute the truth table for the bitwise OR:
 *
 *                      a   b   q
 *                      0   0   0
 *                      0   1   1
 *                      1   0   1
 *                      1   1   1
 *
 *  we see that every time, either a or b is 1, q is also set to 1, 
 *  because, as we said q = 1 if a | b | both = 1.
 *
 * @param       a       first operand
 * @param       b       second operand
 * @return      q       result of the bitwise OR
 */
unsigned char bitwise_or(unsigned char a,
                         unsigned char b) {
    unsigned char q = 0;

    q = a | b;
    decbin_output(q);

    return q;
}

/**
 * Performs a bitwise XOR.
 *
 * The bitwise XOR will copy a bit if it exists in either operand,
 * but not when present in both. Let's have a look at the truth table:
 *
 *                      a   b   q
 *                      0   0   0
 *                      0   1   1
 *                      1   0   1
 *                      1   1   0
 *
 *  we see that every time either a or b is 1, q is also set to 1, 
 *  because, as we said, q = 1 if a exkl | b = 1.
 *
 * @param       a       first operand
 * @param       b       second operand
 * @return      q       result of the bitwise XOR
 */
unsigned char bitwise_xor(unsigned char a,
                          unsigned char b) {
    unsigned char q = 0;

    q = a ^ b;
    decbin_output(q);

    return q;
}

/**
 * Bitwise NOT.
 *
 * This operator is unary (it requires only one input operand), an
 * has the effect of flipping bits.
 *
 * For example:
 *                   input: 004 = 0000 0100
 *      after modification: 251 = 1111 1011
 *
 * @param       value   the value whose bits to flip
 * @return      q       result of the ones complement
 */
unsigned char bitwise_not(unsigned char value) {

    value = ~ value;
    decbin_output(value);

    return value;
}

/**
 * Shifts the bits of the given value the given number of shifts to the left.
 */
unsigned char shift_left(unsigned char value,
                         unsigned char shift) {

    //value = value << shift;
    value <<= shift;
    decbin_output(value);

    return value;
}

/**
 * Shifts the bits of the given value the given number of shifts to the right.
 */
unsigned char shift_right(unsigned char value,
                          unsigned char shift) {
    
    //value = value >> shift;
    value >>= shift;
    decbin_output(value);

    return value;
}

/* == Main (used for testing) =============================================== */

int main(__UNUSED__ int argc, 
         __UNUSED__ char** argv) 
{
    //unsigned char a = 60;
    //unsigned char b = 13;
    
    unsigned char a = 6;
    unsigned char b = 6;
    unsigned char origin = 4;       /* origin value before shift */
    unsigned char nshift = 2;       /* number of shifts */

    printf("AND:\n");
    decbin_output(a);               /*  60 = 0011 1100 */
    decbin_output(b);               /*  13 = 0000 1101 */
    printf("-------------\n");
    bitwise_and(a, b);              /*  12 = 0000 1100 */

    printf("\n");

    printf("OR:\n");
    decbin_output(a);               /*  60 = 0011 1100 */
    decbin_output(b);               /*  13 = 0000 1101 */
    printf("-------------\n");
    bitwise_or(a, b);               /*  61 = 0011 1101 */

    printf("\n");

    printf("XOR:\n");
    decbin_output(a);               /*  60 = 0011 1100 */
    decbin_output(b);               /*  13 = 0000 1101 */
    printf("-------------\n");
    bitwise_xor(a, b);              /*  61 = 0011 1101 */

    printf("\n");

    printf("NOT:\n");
    decbin_output(origin);          /*   4 = 0000 0100 */
    printf("--------------\n");
    bitwise_not(origin);            /* 251 = 1111 1011 */

    printf("\n");

    printf("SHIFT LEFT\n");
    decbin_output(origin);          /*   4 = 0000 0100 */
    printf("--------------\n");
    shift_left(origin, nshift);     /*  32 = 0010 0000 */

    printf("\n");

    printf("SHIFT RIGHT\n");
    decbin_output(origin);          /*   4 = 0000 0100 */
    printf("--------------\n");
    shift_right(origin, nshift);    /*   1 = 0000 0001 */

    return 0;
}
