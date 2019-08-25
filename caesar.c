#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int argument(string argv[]);
int main(int argc, string argv[])
{
    if (argc == 2 && argument(argv) == 0)
        {
        int b = atoi (argv[1]);
         string s = get_string("plaintext: ");               
         printf("ciphertext: ");
                for (int j = 0; j < strlen(s); j++)
                    {
                    int c = (int) s[j];
                    int t = c;
                     if (c > 64 && c < 91)     
                        {
                             t = c + b%26;
                            if (t > 90)
                            {
                                t = t - 26;
                            }
                        }
                                else if (c > 96 && c < 123)
                                {
                                t = c + b%26;
                              if (t > 122)
                              {
                              t = t - 26;
                              }
                        }
                   printf("%c", t);
                    }
        printf("\n");
          }
     else
         return 1;
     printf("Usage ./ceasar key\n");  
}
 
int argument(string argv[])
{
    int x = 0;
    int y = strlen(argv[1]); 
     for (int i = 0; i < y; i++)
       {
          if (isdigit(argv[1][i]) == 0 ) 
           {
                x = (int) argv[1];
            }
      }
    return x;  
}