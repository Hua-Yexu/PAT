#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int P = 0, A = 0, T = 0, e = 0, s = 0, t = 0;
    char c;

    while((c = getchar()) != '\n')
    {
        if(c == 'P') P++;
        if(c == 'A') A++;
        if(c == 'T') T++;
        if(c == 'e') e++;
        if(c == 's') s++;
        if(c == 't') t++;
    }

    while(P || A || T || e || s || t)
    {
        if(P) {putchar('P'); P--;}
        if(A) {putchar('A'); A--;}
        if(T) {putchar('T'); T--;}
        if(e) {putchar('e'); e--;}
        if(s) {putchar('s'); s--;}
        if(t) {putchar('t'); t--;}
    }


    return 0;
}
