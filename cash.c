#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    //ask for text
    string text = get_string("Enter Text: \n");
    
    
    //the formula: index = 0.0588 * L - 0.296 * S - 15.8
    
    //find # of letters
    float letters = 0, words = 1, sentences = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        //find # of words
        if (isspace(text[i]))
        {
            words++;
        }
        //find # of sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        
    }
    // find L--> L= letters / words * 100
    float l = letters / words * 100;
    //find S -->sentence / words * 100
    float s = sentences / words * 100;
    //enter into formula
    float index = 0.0588 * l - 0.296 * s - 15.8;
    //round the number to get a grade
    int indexGrade = round(index);
    //print grade,before grade 1 and 16+
    
    if (indexGrade >= 1 && indexGrade <= 16)
    {
        printf("Grade %i\n", indexGrade);
    }
    else
    {
        if (indexGrade < 1)
        {
            printf("Before Grade 1\n");
        }
        if (indexGrade > 16)
        {
            printf("Grade 16+\n");
        }
    }
}
