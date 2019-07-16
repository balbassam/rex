#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define BUFLEN 128
char name[BUFLEN] = {0};

void setbuffering() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
}

void print_name() {
    printf("This buffers contents are here: ");
    write(STDOUT_FILENO, name, BUFLEN);
    printf("\n");
}

void edit_name() {
    long idx;
    printf("Enter an index in the buffer: "); fflush(stdout);
    scanf("%ld", &idx);
    printf("What should be in location %ld? ", idx); fflush(stdout);

    read(STDIN_FILENO, &name[idx], 1);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(int argc, char** argv) {
    int quit = 0;;
    int choice = 0;
    setbuffering();

    printf("Welcome to our raw buffer editor\n");
    while(!quit) {
        printf("1. Print buffer\n2. Edit buffer\n3. quit\n> ");
        fflush(stdout);
        scanf("%d", &choice);

        if (choice == 1) {
            print_name();
        }
        else if (choice == 2) {
            edit_name();
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
