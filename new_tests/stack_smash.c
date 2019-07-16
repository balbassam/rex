#include <stdio.h>
#include <unistd.h>

int main(int argc, char**argv)
{
    char buff[80];
    read(0, buff, 0x100);
}
