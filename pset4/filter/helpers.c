#include "helpers.h"
#include "math.h"
#include <stdio.h>
// typedef struct
// {
//     BYTE  rgbtBlue;
//     BYTE  rgbtGreen;
//     BYTE  rgbtRed;
// } __attribute__((__packed__))
// RGBTRIPLE;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Height => row-count for 2D array
    // Width => column-count for 2D array
    // image[height][width].rgbtBlue = 0x00 => example of accessing one of the three bytes in one pixel
    // 0x00 => black & 0xff => white
    // to convert a pixel to grayscale we need to make sure all three bytes are equal in value, that's how a gray(white-to-black) color happens in a pixel
    // to decide what shade of gray to convert we can get the average of three bytes and update all of them to that value
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((image[i][j].rgbtBlue == image[i][j].rgbtGreen || image[i][j].rgbtBlue == image[i][j].rgbtRed) && image[i][j].rgbtBlue != 0)
            {
                image[i][j].rgbtGreen = image[i][j].rgbtBlue;
                image[i][j].rgbtRed = image[i][j].rgbtBlue;
            }
            else if ((image[i][j].rgbtGreen == image[i][j].rgbtRed || image[i][j].rgbtGreen == image[i][j].rgbtBlue)
                     && image[i][j].rgbtGreen != 0)
            {
                image[i][j].rgbtBlue = image[i][j].rgbtGreen;
                image[i][j].rgbtRed = image[i][j].rgbtGreen;
            }
            else
            {
                int avg_byte_val = round(((float) image[i][j].rgbtBlue + (float) image[i][j].rgbtGreen + (float) image[i][j].rgbtRed) / 3);
                image[i][j].rgbtBlue = avg_byte_val;
                image[i][j].rgbtGreen = avg_byte_val;
                image[i][j].rgbtRed = avg_byte_val;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int half_length = round(width / 2);
        for (int j = 0, k = width - 1; j < half_length; j++, k--)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // 120 140 150 => 127 140 149 by averaging the box neighbours of the value
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float rgbtBlueAvg = 0;
            float rgbtGreenAvg = 0;
            float rgbtRedAvg = 0;
            int counter = 0;
            for (int k = i - 1; k < i + 2; k++)
            {
                if (k < 0 || k > height - 1)
                {
                    continue;
                }

                for (int l = j - 1; l < j + 2; l++)
                {
                    if (l < 0 || l > width - 1)
                    {
                        continue;
                    }

                    rgbtBlueAvg += (float) image[k][l].rgbtBlue;
                    rgbtGreenAvg += (float) image[k][l].rgbtGreen;
                    rgbtRedAvg += (float) image[k][l].rgbtRed;
                    counter++;

                }
            }
            temp[i][j].rgbtBlue = round(rgbtBlueAvg / counter);
            temp[i][j].rgbtGreen = round(rgbtGreenAvg / counter);
            temp[i][j].rgbtRed = round(rgbtRedAvg / counter);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    return;
}

// submit50 cs50/problems/2020/x/filter/more