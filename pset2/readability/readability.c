#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>



// FORMULA: index = 0.0588 * L - 0.296 * S - 15.8
// Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

// 20 words, 50 letters, 5 sentences
// L => 100 / 20 = 5 | 50 * 5 = 250

// Rules:
// 1- period, exclamation point, or question mark indicates the end of a sentence.
// 2- any sequence of characters separated by spaces should count as a word.
// 3- Your program should print as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
// 4- If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, your program should output "Before Grade 1".

int main(void)
{
    string text = get_string("Text: ");
    float word_count = 1.0;
    float letter_count = 0.0;
    float sentence_count = 0.0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letter_count += 1.0;
        }
        else if (text[i] == ' ')
        {
            word_count += 1.0;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence_count += 1.0;
        }
    }


    float average_num_of_letters_per_100_words = letter_count * (100.0 / word_count);
    float average_num_of_sentences_per_100_words = sentence_count * (100.0 / word_count);
    // printf("%f - %f", average_num_of_letters_per_100_words, average_num_of_sentences_per_100_words);
    float grade_index = 0.0588 * average_num_of_letters_per_100_words - 0.296 * average_num_of_sentences_per_100_words -
                        15.8; // FORMULA: index = 0.0588 * L - 0.296 * S - 15.8

    if (grade_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int) round(grade_index));
    }
    // printf("%f\n", word_count);
    // printf("%f\n", sentence_count);

    return 0;
}