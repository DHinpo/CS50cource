#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{  
    float dollars;      
    int r = 0;
    do
    {
        dollars = get_float("Change: ");
    }
    while (dollars <= 0);
    {
    int coins = round(dollars * 100);
        if (coins >= 25)
        {
        r = r + coins/25;
        coins = coins%25;
        }
            if (coins >= 10)
            {
            r = r + coins/10;
            coins = coins%10;
            }
        
                if (coins >= 5)
                {
                r = r + coins/5;
                coins = coins%5;
                }
                   
                      r = r + coins;
       printf("%i\n", r);
        
    }
}  