#include <stdio.h>

int main(void)
{
    print_alphabet_x10();
    return (0);
}

void print_alphabet_x10(void){
    char alp[] = "abcdefghijklmnopqrstuvwxyz\n";
    int i = 0;
    while(i < 10 ) {
        printf(alp);
        i++;
    }
}
