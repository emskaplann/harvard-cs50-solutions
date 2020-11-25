#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);



    for (int row = 0; row < height; ++row)
    {
        for (int space = 0; space < height - (row + 1); ++space)
        {
            printf(" ");
        }
        for (int hash_one = 0; hash_one < row + 1; ++hash_one)
        {
            printf("#");
        }

        printf("  ");

        for (int hash_two = 0; hash_two < row + 1; ++hash_two)
        {
            printf("#");
        }
        printf("\n");
    }
}

// ...#.#...
// ..##.##..
// .###.###.
// ####.####