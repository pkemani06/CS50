// Accessing cs50 manual pages libraries
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get user name
    string name = get_string("What is your name? ");

    // print hello, "user"
    printf("hello, %s\n", name);
}