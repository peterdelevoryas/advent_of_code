#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char **argv)
{
    FILE *f;
    char buf[32];
    int max_calories_seen = -1;
    int sum_calories = 0;

    f = fopen("input", "r");
    assert(f);


    while (fgets(buf, sizeof(buf), f)) {
        if (buf[0] == '\n') {
            printf("%d %d\n", sum_calories, max_calories_seen);
            max_calories_seen = max(sum_calories, max_calories_seen);
            sum_calories = 0;
            continue;
        }
        sum_calories += atoi(buf);
    }

    printf("%d\n", max_calories_seen);

    fclose(f);
}
