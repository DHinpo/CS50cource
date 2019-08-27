#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int shift(char c);
int keys = 0;
int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    else
        {
        string key = argv[1];
        for (int i = 0; i < strlen(argv[1]); i++)
            {
                if (!isalpha(key[i]))  
                    {
                        printf("Usage: ./vigenere keyword\n");
                        return 1;
                    }
            }
        }
    string s = get_string("plaintext: ");               
    printf("ciphertext: ");
    int p = 0;
    for (int j = 0; j < strlen(s); j++)
        {
            if (p == strlen(argv[1]))
                {
                    p = 0;
                }
            keys = shift(argv[1][p]);  
            int c = (int) s[j];
            int t = c;
            if (c > 64 && c < 91)     
                {
                    t = c + keys%26;
                    if (t > 90)
                        {
                            t = t - 26;
                        }
                    p++;
                }
            else if (c > 96 && c < 123)
                {
                    t = c + keys%26;
                    if (t > 122)
                        {
                            t = t - 26;
                        }
                    p++;
                }
            printf("%c", t);
        }
    printf("\n");
    return 0;
}
   

int shift(char c)
{
    int v = 0;
    if (c > 96)
        {
            v = c - 97;
        }
    else
        {
            v = c - 65;
        }
    return v;
}
