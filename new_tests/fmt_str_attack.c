#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    char buff[100];
    fgets(buff, 100, stdin);
    printf(buff);
}
