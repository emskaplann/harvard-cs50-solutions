#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

// 0xff 0xd8 0xff => first three bytes of .JPEG files
//

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Invalid command input.\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Couldn't open the file.\n");
        return 1;
    }

    BYTE buffer[512];
    int counter = -1;
    char *filename = malloc(8);

    sprintf(filename, "%03i.jpg", counter);
    FILE *img = fopen(filename, "w");

    // Read input file
    while (fread(buffer, 1, 512, file) == 512)
    {
        // DO WHAT YOU NEED HERE
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // printf("%hhx\n", buffer[0]);
            counter++;
            fclose(img);
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
        }

        fwrite(buffer, 1, 512, img);
    }
    free(filename);
    fclose(file);
    remove("-01.jpg");
    return 0;
}
