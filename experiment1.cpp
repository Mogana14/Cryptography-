#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int shift;
    char plain[100];
    char encrypted[100];
    printf("Enter the key value: ");
    scanf("%d", &shift);
    printf("Enter the plain text: ");
    scanf("%s", plain);
    int len = strlen(plain);
    for (int i = 0; i < len; i++)
    {
        if (isupper(plain[i]))
        {
            encrypted[i] = (plain[i] - 'A' + shift) % 26 + 'A';
        }
        else if (islower(plain[i]))
        {
            encrypted[i] = (plain[i] - 'a' + shift) % 26 + 'a';
        }
        else
        {
            encrypted[i] = plain[i];
        }
    }

    encrypted[len] = '\0';

    printf("The encrypted text is: %s\n", encrypted);
    return 0;
}
