#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>



int main(void)
{
    // promt user for text
    string text = get_string("Text: ");
    
    int words = 0, sentences = 0, letters = 0;
    
    // iterate over text checking each character
    for (int i = 0, n = strlen(text); i < n; i++)
    
    if (isalpha(text[i]))
    {
        letters++;
    }
 
    // count words
    else if (isspace(text[i]))
    {
        words++;
    }
    // count sentences
    else if ((text[i]) == '.' || (text[i]) == '?')
    {
        sentences++;
    }
    
    words = words + 1;
    
    float L = ((float) letters / (float)words) * 100 ;
    float S = ((float) sentences / (float) words) * 100;
    // calculate
    float grade = 0.0588 *  L - 0.296 * S - 15.8;
    
    int index = round(grade);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %i\n", index);
    }

  
}
