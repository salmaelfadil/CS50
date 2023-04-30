#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)

{
    long card;
    // promt user for credit card number
   do
   {
       card= get_long("card: "); 
   } 
   while ( card < 0);
   
   // checksum
   int sum1;
   int sum2;
   int sum3;
   int digit;
   int lastdigit;
   
   lastdigit= card %10;
   
   // case 1
   while (card < 0)
   { 
       card=card/100;
       sum1=sum1 +lastdigit;
   }
       
   
   // case 2
   while (card < 0)
   {
       card = card/100;
   lastdigit=lastdigit * 2;
   sum2 = sum2 +(lastdigit/10 +lastdigit%10);
   }
   
   sum3 = sum1+sum2;
   
   if (sum3%10 !=0)
    printf("Invalid");
   
   // type of visa
   
   int length;
   int firsttwodigits=0; 
   int firstdigit=0;
   
   if (firsttwodigits==34 ||firsttwodigits== 37)
   printf ("American Express\n");
   
   else if (firsttwodigits == 51 || firsttwodigits== 52 || firsttwodigits== 53 ||firsttwodigits== 54 || firsttwodigits==55)
   printf ("Mastercard\n");
   
   else if (firstdigit ==4)
   printf ("Visa");
}
