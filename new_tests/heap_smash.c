#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char**argv)
{
    void *chunk1;
    void *chunk2;
    chunk1 = malloc(0x80);
    chunk2 = malloc(0x80);

    // Arbitrary overwrite of chunk2 from chunk1
    scanf("%s", chunk1);
    printf("chunk1 @ %p has: %s\n", chunk1, chunk1);
    printf("chunk2 @ %p has: %s\n", chunk2, chunk2);

    free(chunk2);
    printf("chunk1 @ %p has: %s\n", chunk1, chunk1);
    printf("chunk2 @ %p has: %s\n", chunk2, chunk2);
    return 0;
}
