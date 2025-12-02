#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE* fd = fopen("./input.txt", "r");
    if (fd == NULL) return 1;

    size_t bytes;
    char dir;
    int dist, total = 0, cur = 50;
    while (fscanf(fd, "%c%d\n", &dir, &dist) == 2) {
        if (dist == 0) continue;
        if (dir == 'L') {
            if (dist > cur)
                while (dist > cur) cur += 100;
            cur -= dist;
        } else if (dir == 'R') {
            cur += dist;
            if (cur > 99)
                while (cur > 99) cur -= 100;
        } else {
            printf("FAILED, got %c, %d\n", dir, dist);
            break;
        }
        if (cur == 0) total++;
    }
    printf("The password is %d\n", total); 
    return 0;
}
