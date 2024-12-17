#include <cs50.h>
#include <stdio.h>

bool checkIfValid(long n);
int findLength(long c);
bool checkSum(long cardNum);
void printBrand(long ccn);

int main(void)
{
    // Get card number
    long cardNum = get_long("Number: ");

    // Print card brand or invalid if not valid
    if (checkIfValid(cardNum) == true)
    {
         printBrand(cardNum);
    }
    else
    {
        printf("INVALID\n");
    }

}



bool checkIfValid(long cardNum)
{
    int len = findLength(cardNum);
    return (len == 13  || len == 15 || len == 16) && checkSum(cardNum);
}

int findLength(long c)
{
    // Get card length
    int len;
    for (len = 0; c != 0; len++)
    {
        c /= 10;
    }
    return len;
}

bool checkSum(long num)
{
    int sum = 0;

    for (int i = 0; num != 0; num /= 10, i++)
    {

        if (i % 2 == 0)
        {
            sum += num % 10;
        }
        else
        {
            int number = (num % 10) * 2;
            sum += number / 10 + (number % 10);
        }
    }
    //return sum of that number to figure out if last digit is 0
    return (sum % 10) == 0;
}

void printBrand(long ccn)
{
    if ((ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13))
    {
        printf("AMEX\n");
    }
    else if (ccn >= 51e14 && ccn < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if ((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}
