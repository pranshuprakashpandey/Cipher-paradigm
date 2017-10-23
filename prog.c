#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	void text_encrypt(char cipher[25], int shift, int num)
	{
	    for (int i=0; i < num; i++)
	    {
	        if (cipher[i] >= 'A' && cipher[i] <= 'Z')
	        {
	            cipher[i] = (char)(((cipher[i] + shift - 'A' + 26) % 26) + 'A');
	        }
	        else if (cipher[i] >= 'a' && cipher[i] <= 'z')
	        {
	            cipher[i] = (char)(((cipher[i] + shift - 'a' + 26) % 26) + 'a');
	        }
	    }
	}
	 
	void text_decrypt(char cipher[25], int shift, int num)
	{
	    for (int i=0; i < num; i++)
	    {
	        if (cipher[i] >= 'A' && cipher[i] <= 'Z')
	        {
	            cipher[i] = (char)(((cipher[i] - shift - 'A' + 26) % 26) + 'A');
	        }
	        else if (cipher[i] >= 'a' && cipher[i] <= 'z')
	        {
	            cipher[i] = (char)(((cipher[i] - shift - 'a' + 26) % 26) + 'a');
	        }
	    }
	}
	 
	int main ()
	{
	    char text[10];
	    static const char encrypt[] = "encrypt";
	    static const char decrypt[] = "decrypt";
	    int shift;
	    char cipher[25];
	    int result1;
	    int result2;
	    int num;
	 
	    printf("Enter operation: encrypt or decrypt");
	    scanf("%s",&text);
	    printf("\nEnter shift key");
	    scanf("%d",&shift);
	    printf("\nEnter text to encrypt/decrypt");
	    scanf("%s",&cipher);

	    num = strlen (cipher);
	    result1 = strcmp (text, encrypt);
	    result2 = strcmp (text, decrypt);

	    if(result1 == 0)
	    {
	        text_decrypt(cipher, shift, num);
	    }
	    if(result2 == 0)
	    {
	        text_encrypt(cipher, shift, num);
	    }

	    printf("Result:");
	    printf(cipher);
	}
