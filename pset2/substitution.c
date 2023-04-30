#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


const int size=26;

int main(int argc, string argv[])
{
    bool isvalid( string s);
    if (argc !=2)
    {
        printf ("usage: ./substitution KEY\n");
        return 1;
    }
    else if (argc==2)
    {
        if (!isvalid(argv[1]))
        {
            printf ("Key must not contain repeated characters\n");
            return 1;
            
        }     
        for ( int e=0, x=strlen(argv[1]); e<x; e++)
        {
            if (ispunct(argv[1][e]))
            {
                printf("usage: ./substituion KEY\n");
                return 1;
                
            }
            else if (isdigit(argv[1][e]) || !isalpha(argv[1][e]))
            {
                printf("key must only contain alphabetic characters\n");
                return 1;
                
            }
            else if (x !=26)
            {
                printf("Key must contain 26 characters\n");
                return 1;
                
            }
            else
            {
                string plaintext=get_string ("plaintext: ");
                printf("ciphertext: ");
                
                string POINTS=argv[1];
                for (int i='A'; i <='Z'; i++) 
                POINTS[i-'A']= toupper (POINTS[i-'A']) -i;
                // iterate over alphabet
                
                 // h-A =39
                
                for (int i=0, n =strlen(plaintext); i<n; i++)
                {
                    if (ispunct(plaintext[i]) || isspace(plaintext[i]) || isdigit(plaintext[i]) )
                    {
                        printf ("%c", (plaintext[i]));
                        
                    }
                    else if (isalpha(plaintext[i]) && islower (plaintext[i]))
                    {
                        plaintext[i]= plaintext[i] + POINTS[plaintext[i]-'a'];
                        printf ("%c", plaintext[i]);
                        
                    }
                    else if (isalpha(plaintext[i]) && isupper (plaintext[i]))
                    {
                        plaintext[i]= plaintext[i] + POINTS[plaintext[i]-'A'];
                        printf ("%c",plaintext[i]);
                        
                    }
                    
                }
                printf ("\n");
                return 0;
                
            }
            
        }
        
    }
    
}

bool isvalid( string s)

{
    int freq[26]= {0};
    for (int e=0, x=26; e <x ; e++)
    {
        int index =toupper(s[e]) - 'A';
        if (freq[index] >0)
        return false;
        freq[index]++;
        
    }
   
    return true;
}
    

