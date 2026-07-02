#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifdef LOCAL
#define debug(fmt, ...) fprintf(stderr, "[debug] " fmt "\n", ##__VA_ARGS__)
#else
#define debug(...) ((void)0)
#endif

int main() {
    return 0;
}
