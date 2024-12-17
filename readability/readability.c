#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// readability.c, Prince Michael Kemani. Checks text to see the grade level and ranks it

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    printf("Text: ");
    string text = get_string("");
    float l = (float)count_letters(text) / count_words(text) * 100;
    float s = (float)count_sentences(text) / count_words(text) * 100;
    float i = 0.0588 * l - 0.296 * s - 15.8;
    int index = lroundl(i);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

// count letters
int count_letters(string text)
{
    // variable to store count of letters
    int count = 0;
    int len = strlen(text);

    // loop through letters and return amount of letters in "text"
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

// count words
int count_words(string text)
{
    int wordCount = 1;
    // create a variable for the length of text
    int len = strlen(text);

    // loop through text
    for (int i = 0; i < len; i++)
    {
        if (isblank(text[i]))
        {
            wordCount++;
        }
    }
    return wordCount;
}

// count sentences
int count_sentences(string text)
{
    int sentences = 0;
    // create a variable for the length of text
    int len = strlen(text);

    // loop through text
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}