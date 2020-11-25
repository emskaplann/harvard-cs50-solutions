#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    long credit = get_long("Number: ");
    int length = floor(log10(labs(credit))) + 1;
    // printf("%d\n", length);
    if (length == 13 || length == 15 || length == 16) // If the length is valid
    {
        int digits[length];
        for (int i = length - 1; i >= 0; i--)
        {
            digits[i] = credit % 10;
            credit = credit / 10;
        }

        int total = 0;
        for (int i = length - 2; i >= 0; i -= 2) // starting iteration with second-to-last
        {
            int product = digits[i] * 2;
            int length_of_product = floor(log10(abs(product))) + 1;
            if (length_of_product > 1)
            {
                for (int j = length - 1; j >= 0; j--)
                {
                    total += product % 10;
                    product = product / 10;
                }
            }
            else
            {
                total += product;
            }
        }

        for (int i = length - 1; i >= 0; i -= 2)
        {
            total += digits[i];
        }
        // printf("%d\n", total); // right now we have the expected value 13 for test input: 4003600000000014

        if (total % 10 != 0)
        {
            printf("INVALID\n");
            return 0;
        }

        if (length == 15 && digits[0] == 3 && (digits[1] == 4 || digits[1] == 7))
        {
            printf("AMEX\n");
        }
        else if ((length == 13 || length == 16) && digits[0] == 4)
        {
            printf("VISA\n");
        }
        else if (length == 16 && digits[0] == 5 && (digits[1] == 1 || digits[1] == 2 || digits[1] == 3 || digits[1] == 4 || digits[1] == 5))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
        return 0;
    }
    else // if length is invalid
    {
        printf("INVALID\n");
        return 0;
    }
}

// American Express uses 15-digit numbers | 34 or 37
// MasterCard uses 16-digit numbers | MasterCard numbers start with 51, 52, 53, 54, or 55
// Visa uses 13- and 16-digit | 4