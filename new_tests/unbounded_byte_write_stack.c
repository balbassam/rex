#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define BUFLEN 128

void setbuffering() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
}

// long geti() {
//     char BUF[BUFLEN];
//     char *endptr;
//     long i;
// 
//     fgets(&BUF, BUFLEN, STDIN_FILENO);
//     read(STDIN_FILENO, &BUF, BUFLEN);
//     i = strtol(BUF, &endptr, 0);
//     if (endptr == BUF) {
//         printf("invalid number\n");
//     }
//     return i;
// }

void print_name(char *name) {
    printf("This buffers contents are here: ");
    write(STDOUT_FILENO, name, BUFLEN);
    printf("\n");
}

void edit_name(char *name) {
    long idx;
    printf("Enter an index in the buffer: "); fflush(stdout);
    //idx = geti();
    scanf("%ld", &idx);
    printf("What should be in location %ld? ", idx); fflush(stdout);

    read(STDIN_FILENO, &name[idx], 1);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(int argc, char** argv) {
    int quit = 0;;
    int choice = 0;
    char name[BUFLEN] = {0};
    setbuffering();

    printf("Welcome to our raw buffer editor\n");
    while(!quit) {
        printf("1. Print buffer\n2. Edit buffer\n3. quit\n> ");
        fflush(stdout);
        // choice = geti();
        scanf("%d", &choice);

        if (choice == 1) {
            print_name(name);
        }
        else if (choice == 2) {
            edit_name(name);
        }
        else if (choice == 3) {
            quit = 1;
            printf("Good bye!\n");
        } else {
            printf("Bad choice %d\n", choice);
        }
    }
    return 0;
}
