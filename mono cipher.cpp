#include <stdio.h>
#include <string.h>
#include <ctype.h>
void encrypt(char *plainText, char *key, char *cipherText)
{
int i, len, index;
len = strlen(plainText);
for (i = 0; i < len; i++)
{
if (isalpha(plainText[i]))
{
index = toupper(plainText[i]) - 'A';
cipherText[i] = key[index];
}
else
{
cipherText[i] = plainText[i];
}
}
cipherText[i] = '\0';
}
int main()
{
char plainText[100], cipherText[100];
char key[26] = "QWERTYUIOPASDFGHJKLZXCVBNM";
printf("Enter the plain text: ");
scanf("%s", plainText);
encrypt(plainText, key, cipherText);
printf("The cipher text is: %s\n", cipherText);
return 0;
}
