#include <stdio.h>
#include <cs50.h>

int get_height(string prompt);
int main(void)
{
    int i = get_height("Height: ");
    for (int e = 1; e <= i; e++)
        {
               for (int q = (i - e); q > 0; q--)
               {
               printf(" ");
               }
                    for (int w = 0; w < e; w++)
                    {
                        printf("#");
                    }
        printf("\n");
}
        }
        

int get_height(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n > 8 || n < 1);
    return n;
}
