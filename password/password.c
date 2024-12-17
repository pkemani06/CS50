// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool valid(string s);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string s)
{
    bool uCL = false;
    bool lCL = false;
    bool num = false;
    bool sym = false;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        // checks the if current character is a upper-case later, lower-case letter, digit, or symbol
        if (isupper(s[i]))
        {
            uCL = true;
        }
        else if (islower(s[i]))
        {
            lCL = true;
        }
        else if (isdigit(s[i]))
        {
            num = true;
        }
        else if (ispunct(s[i]))
        {
            sym = true;
        }
    }

    return (uCL && lCL && num && sym);
}
