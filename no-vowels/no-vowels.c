// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string s);
bool isVowel(char c);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("RE-DO NOW!!\n");
    }
    else
    {
        printf("%s\n", replace(argv[1]));
    }

}



bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string replace(string s)
{
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        // switch the value to its proper number if it is a vowel
        switch (s[i])
        {
            case 'a':
                s[i] = '6';
                break;
            case 'e':
                s[i] = '3';
                break;
            case 'i':
                s[i] = '1';
                break;
            case 'o':
                s[i] = '0';
                break;
        }
    }
    return s;
}