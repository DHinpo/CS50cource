#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{  
 long card;
 do
    {
      card = get_long("Card: ");
    }
     while (card <= 0 );
        {
            string name = "INVALID"; 
            int n,i;    
            int s = 0;  
            int t = 0;  
            int r = 0;  
             
            long v = card/1000000000000;
            while (v > 99)
            {
                v = v/10;
            }
            long card2 = card/10;
            
            while (card > 0)
            {
               n = n + card%10;
               card = card/100;
                t++;
            }
            while (card2 > 0)
            {
                i = (card2%10)*2;
                    if (i > 9)
                    {
                        i = 1 + i%10;
                    }
                s = s + i;
                card2 = card2/100;
                r++;
            }
                if ((n + s) %10 == 0)
                {
                    if((r+t == 13 && v/10 == 4) || (r+t == 16 && v/10 == 4))
                    {
                        name = "VISA";  
                    }
                    else if((r+t == 15 && v == 34) || (r+t == 15 && v == 37))
                    {
                        name = "AMEX";  
                    }
                    else if(r+t == 16 && (v > 50 && v < 56))
                    {
                    name = "MASTERCARD";  
                    }
               }
            printf("%s\n", name);
         }
}   
