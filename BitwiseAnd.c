#include <stdio.h>

int rangeBitwiseAnd(int m, int n) {
    int shift = 0;
    
    // Find common prefix by shifting both m and n right until they match
    while (m < n) {
        m >>= 1;
        n >>= 1;
        shift++;
    }

    // Shift result back to the left to get the final AND value
    return m << shift;
}

int main() {
    int m = 5, n = 7;

    int result = rangeBitwiseAnd(m, n);
    printf("Bitwise AND of numbers in range [%d, %d] is %d\n", m, n, result);

    return 0;
}
