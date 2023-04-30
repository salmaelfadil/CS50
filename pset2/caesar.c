#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check command-line argument
    if (argc != 2 || isalpha(*argv[1]) || ispunct(*argv[1]))
    {
        printf ("usage: ./caesar key\n");
    return 1;
    }
    else if (argc==2 && isdigit(*argv[1]))
    {
        // convert command line argument to integer
        int key = atoi(argv[1]);

        // promt user for plaintext
        string plaintext = get_string("Text:");
        printf ("ciphertext: ");

        //iterate through text
        for (int i=0,n= strlen(plaintext); i<n; i++)

        {
            // lowercase letter
            if (isalpha(plaintext[i]) && islower(plaintext[i]))
            {
                char c;
                printf("%c", (plaintext[i] - 97 + key) % 26 + 97);

            }
            //uppercase letter
            else if (isalpha(plaintext[i]) && isupper(plaintext[i]))
            {
                printf("%c", (plaintext[i] - 65 + key) % 26 + 65);

            }
            //preserving punctuation and spaces
            else if (ispunct(plaintext[i]) || isspace(plaintext[i]))
            printf ("%c", plaintext[i]);

        }
        printf ("\n");
        return 0;

    }

}


ciphertext = POINTS[plaintext[i]]

