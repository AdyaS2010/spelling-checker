#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float grade_level(int letters, int sentences, int words);

int main(void)
{
    // Prompt user for text -> passage, paragraph, sentence(s), etc...
    string text = get_string("Text: ");

    // Count number of letters, words, sentences in given text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    /*
        printf("%i\n", letters);
        printf("%i\n", words);
        printf("%i\n", sentences);
}

int count_letters(string text)
{
    // Return number of letters in text

    // Count letters
    int letters = 0;

    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
 
}

int count_sentences(string text)
{
    int sentencecount = 0;

    // Return number of words in text
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // if (text[i] == 32)
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentencecount++;
        }
    }
    return sentencecount;
}

float grade_level(int letters, int sentences, int words)
{
 
}
