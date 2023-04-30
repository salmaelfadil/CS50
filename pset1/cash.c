#include <stdio.h>
#include <cs50.h>
#include <math.h>

{
    float change;
    int cents;
    int coins = 0;

    // prompt user for an amount of chang
    do
    {
        change = get_float("change:");
    }
    while (change < 0);

    cents = round(change * 100);

    //use largest coin possible keep track of coins used

    while (cents >= 25)
    {
        cents = cents - 25;
        coins ++;
    }


    while (cents >= 10)
    {
        cents = cents - 10;
        coins++;
    }


    while (cents >= 5)
    {
        cents= cents - 5;
        coins++;
    }

    while (cents >= 1)
    {
        cents = cents - 1;
        coins++;
    }
    // print number of coins
    {
    printf("%i\n",coins);
    }
}
