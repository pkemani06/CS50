#include <cs50.h>
#include <stdio.h>

int getHeight(void);
void printBricks(int height);
int main(void)
{
    // Get height from user
    int size = getHeight();

    // Print Bricks
    printBricks(size);
}

// Method to return the Height
int getHeight(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

// Method to print bricks
void printBricks(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (j + 1 < height - i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }

        }
        // second pyrammid pieces go side by side
        printf("  ");
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }

}

