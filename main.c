#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <gmp.h>

/*
 * https://gmplib.org/manual/Integer-Exponentiation
 * https://gmplib.org/manual/Low_002dlevel-Functions
 * https://gmplib.org/manual/Integer-Logic-and-Bit-Fiddling
*/

/**
 * SIMD or GMP lib approach
 */

/** this is the biggest string possible in hex(pow(2,128)-1)
 * FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
 * fffffffffffffffffffffffffffffffe
 * @return
 */

int main() {
    uint8_t size = 128;
    mpz_t input, mask;
    mpz_init(input);
    mpz_init(mask);
    //init
   // mpz_init_set_str(input, "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF", 16);
    mpz_init_set_str(input, "FFFFFFFFFFFFFFFFFFFFF", 16);

    //shift left my multiplying with 2
    mpz_mul_2exp(input, input, 1);
    //create 128-bit number
    mpz_ui_pow_ui(mask, 2, size);
    mpz_sub_ui(mask, mask, 1);  // mask = (2^desired_size) - 1

    // Apply the mask to the result
    mpz_and(input, input, mask);

    // Print the result
    gmp_printf("Shifted : %Zx\n", input);

    // Free GMP integers
    mpz_clear(input);
    mpz_clear(mask);

    return 0;
}
