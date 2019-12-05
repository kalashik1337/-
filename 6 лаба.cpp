#include <stdio.h>
#include <windows.h>

FILE* f;
int nmax = 0, pos = 0, wpos = 0, n = 0;
char chr = '\0';

void main()
{
    printf(">START OF PROGRAM\r\n");
    if (!(f = fopen("text.txt", "rb+")))
        printf("\tERROR : file not exist or already open\r\n");
    else
    {
        while (!feof(f))
        {
            fread(&chr, 1, 1, f); pos = ftell(f); n = 0;
            while (isalpha(chr) && !feof(f))
            {
                fread(&chr, 1, 1, f);
                n++;
            }
            if (nmax < n)
            {
                wpos = pos;
                nmax = n;
            }
        }
        fseek(f, wpos - 1, SEEK_SET);
        printf("max word length : %d\r\n", nmax);
        printf("word with maxlen: ");
        while (isalpha(chr) && !feof(f))
        {
            fread(&chr, 1, 1, f);
            printf("%c", chr);
        }
        printf("\r\n>END OF PROGRAM\r\n");
    }
    scanf("%c", &chr);
}