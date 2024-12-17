#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // convert RGB values to doubles
            double red = image[i][j].rgbtRed;
            double blue = image[i][j].rgbtBlue;
            double green = image[i][j].rgbtGreen;

            // calculate average
            int avg = round((red + blue + green) / 3);

            // set each RGB value to average value
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // convert rgb into doubles
            double red = image[i][j].rgbtRed;
            double blue = image[i][j].rgbtBlue;
            double green = image[i][j].rgbtGreen;

            // calculate sepia
            int sepiaRed = round((0.393 * red) + (0.769 * green) + (0.189 * blue));
            int sepiaGreen = round((0.349 * red) + (0.686 * green) + (0.168 * blue));
            int sepiaBlue = round((0.272 * red) + (0.534 * green) + (0.131 * blue));

            // check is value is greater than 255. If so, deafult the value to 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // modify image
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // loop through and blur image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0;
            int totalBlue = 0;
            int totalGreen = 0;
            float counter = 0.0;

            for (int y = -1; y < 2; y++)
            {
                for (int x = -1; x < 2; x++)
                {
                    int currentY = i + y;
                    int currentX = j + x;

                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (height - 1))
                    {
                        continue; // skip commands within the loop and increment to the next step of the loop
                    }

                    totalRed += image[currentY][currentX].rgbtRed;
                    totalBlue += image[currentY][currentX].rgbtBlue;
                    totalGreen += image[currentY][currentX].rgbtGreen;

                    // increment counter by one (keep track of grids for average)
                    counter++;
                }

                // find average and assign pixel that color
                copy[i][j].rgbtRed = round(totalRed / counter);
                copy[i][j].rgbtBlue = round(totalBlue / counter);
                copy[i][j].rgbtGreen = round(totalGreen / counter);
            }
        }
    }

    // set copy back to original
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
        }
    }
    return;
}
