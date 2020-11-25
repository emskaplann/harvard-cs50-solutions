#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

bool contains(int len, char *arr, char val)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == val)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, string argv[])
{
    if (!argv[1])
    {
        printf("No input.\n");
        return 1;
    }
    // int x = toupper((int) 'a') - 64; => to find int value of char
    // argument printing => printf("%s\n", argv[1]);
    char duplicate_check_list[26];

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        // argv[1][i] = toupper(argv[1][i]);
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Invalid input.\n");
            return 1;
        }
        if (contains(strlen(duplicate_check_list), duplicate_check_list, argv[1][i]))
        {
            printf("Invalid input.\n");
            return 1;
        }
        duplicate_check_list[i] = argv[1][i];
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Invalid input.\n");
        return 1;
    }

    string plain_text = get_string("plaintext: ");
    char *cipher_text = malloc(sizeof(char) * strlen(plain_text));
    for (int i = 0; i < strlen(plain_text); i++)
    {
        cipher_text[i] = plain_text[i];
        if (isalpha(plain_text[i]))
        {
            int number_of_char = toupper((int) plain_text[i]) - 64;
            if (plain_text[i] >= 'A' && plain_text[i] <= 'Z') // if letter is uppercase
            {
                cipher_text[i] = toupper(argv[1][number_of_char - 1]);
            }
            else
            {
                cipher_text[i] = tolower(argv[1][number_of_char - 1]);
            }
        }
    }
    printf("ciphertext: %s\n", cipher_text);
    printf("\n");
    return 0;
}