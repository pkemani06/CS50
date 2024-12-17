#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // convert pixel to double
            double red = image[i][j].rgbtRed;
            double blue = image[i][j].rgbtBlue;
            double green = image[i][j].rgbtGreen;

            // calculate average
            int avg = round((red + blue + green) / 3);

            // set new values
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
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
            image[i][j] = image[i][(width - j) - 1];
            image[i][(width - j) - 1] = temp;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // create a copy 2D array
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // create Gx and Gy 2D ARRAYS
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0,}, {1, 2, 1}};

    // loop through and solve for edges
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redX = 0;
            int greenX = 0;
            int blueX = 0;
            int redY = 0;
            int greenY = 0;
            int blueY = 0;
            for (int y = 0; y < 3; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    // variables to track current pixel location
                    int currentY = i - 1 + y;
                    int currentX = j - 1 + x;

                    if (currentX < 0 || currentX > (width - 1) || currentY < 0 || currentY > (height - 1))
                    {
                        continue;
                    }

                    // update Gx and Gy variables
                    int xnum = Gx[y][x];
                    int ynum = Gy[y][x];

                    // update Gx
                    redX += image[currentY][currentX].rgbtRed * xnum;
                    greenX += image[currentY][currentX].rgbtGreen * xnum;
                    blueX += image[currentY][currentX].rgbtBlue * xnum;

                    // update Gy
                    redY += image[currentY][currentX].rgbtRed * ynum;
                    greenY += image[currentY][currentX].rgbtGreen * ynum;
                    blueY += image[currentY][currentX].rgbtBlue * ynum;
                }
            }
            // create colors
            int red = round(sqrt(((redX * redX) + (redY * redY))));
            int blue = round(sqrt(((blueX * blueX) + (blueY * blueY))));
            int green = round(sqrt(((greenX * greenX) + (greenY * greenY))));

            // make value 255 if greater than 255
            if (red > 255)
            {
                red = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }

            // assign
            copy[i][j].rgbtRed = red;
            copy[i][j].rgbtBlue = blue;
            copy[i][j].rgbtGreen = green;
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
