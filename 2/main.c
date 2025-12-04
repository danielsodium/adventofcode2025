#include <stdio.h>
#include <stdlib.h>

typedef unsigned long int lu;

int is_invalid(lu n) {
    int i = 0;
    int digits[64];

    if (n == 0) return 1;

    while (n > 0) {
        digits[i++] = n % 10;
        n /= 10;
    }
    if (i % 2 == 1) return 0;

    int p1 = i - 1;
    int p2 = i/2 - 1;

    while (p2 >= 0)
        if (digits[p1--] != digits[p2--]) return 0;
    return 1;
}

int main() {
    FILE* fd = fopen("./input.txt", "r");
    if (fd == NULL) return 1;

    char comma;
    lu first, last;
    lu total;
    while (fscanf(fd, "%lu%*c%lu", &first, &last) == 2) {

        for (lu i = first; i < last; i++) {
            if (is_invalid(i)) total += i;
        }

        if (fscanf(fd, "%c", &comma) == 0) break;
    }
    printf("The answer is %lu\n", total); 
    return 0;
}
