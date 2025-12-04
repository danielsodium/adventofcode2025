#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 256

int main() {
    FILE* fd = fopen("./input.txt", "r");
    if (fd == NULL) return 1;
    
    int total = 0;

    char buffer[MAX_LINE];
    while (fgets(buffer, MAX_LINE, fd)) {
        char max[3] = "00\0";
        int i = 0;
        while (buffer[i] != '\0' && buffer[i] != '\n') {
            if (buffer[i] > max[0] &&
                buffer[i+1] != '\0' && buffer[i+1] != '\n') {
                max[0] = buffer[i];
                max[1] = '0';
            } else if (buffer[i] > max[1]) {
                max[1] = buffer[i];
            }
            i++;
        }
        total += atoi(max);
    }
    printf("total = %d\n", total);
    return 0;
}
