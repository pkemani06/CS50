#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    int endSize;
    do
    {
        startSize = get_int("Start Size: ");
    }
    while (startSize < 9);
    // TODO: Prompt for end size
    do
    {
        endSize = get_int("End Size: ");
    }
    while (endSize < startSize);
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    for (int i = 0; startSize < endSize; i++)
    {
        startSize += (startSize / 3) - (startSiz / 4);
        years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}
