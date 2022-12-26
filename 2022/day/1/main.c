#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

static void insert(int x, int n, int a[n])
{
    for (int i = 0; i < n; i++) {
        if (x < a[i]) {
            continue;
        }
        memmove(&a[i + 1], &a[i], (n - i - 1) * sizeof(int));
        a[i] = x;
        break;
    }
}

int main(int argc, char **argv)
{
    FILE *f;
    char buf[32];
    int top[3] = {-1, -1, -1};
    int sum = 0;

    f = fopen("input", "r");
    assert(f);

    while (fgets(buf, sizeof(buf), f)) {
        if (buf[0] == '\n') {
            printf("sum=%d, top = [%d, %d, %d]\n", sum, top[0], top[1], top[2]);
            insert(sum, ARRAY_SIZE(top), top);
            printf("top = [%d, %d, %d]\n", top[0], top[1], top[2]);
            sum = 0;
            continue;
        }
        sum += atoi(buf);
    }

    printf("%d\n", top[0] + top[1] + top[2]);

    fclose(f);
}
