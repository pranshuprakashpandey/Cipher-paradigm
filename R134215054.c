#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	void caesar_encrypt(char cipher[25], int shift, int num)
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
	 
	void caesar_decrypt(char cipher[25], int shift, int num)
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

	void vignere_encrypt(char *newmsg)
	{
	    char key[] = "CYBERLAW";
    	    int msgLen = strlen(newmsg), keyLen = strlen(key), i, j;
 
	    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
 
    	    //generating new key
    	    for(i = 0, j = 0; i < msgLen; ++i, ++j)
	    {
        	if(j == keyLen)
            	j = 0;
 
        	newKey[i] = key[j];
     	    }

	    newKey[i] = '\0';
 
    	    //encryption
    	    for(i = 0; i < msgLen; ++i)
		{
		    encryptedMsg[i] = ((newmsg[i] + newKey[i]) % 26) + 'A';
 
		    //encryptedMsg[i] = '\0';	
		}
	    //decryption
	    for(i = 0; i < msgLen; ++i)
            {
		decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
 
	        decryptedMsg[i] = '\0';
 	    }
 	    printf("\n Cipher Message after hill cipher: %s", newmsg);
	    printf("\nKey: %s", key);
    	    printf("\nNew Generated Key: %s", newKey);
    	    printf("\nEncrypted Message: %s", encryptedMsg);
    	  //printf("\nDecrypted Message: %s", decryptedMsg);
	}	 


	void hill_encrypt(char *message)
	{
	    int i,j,k;
	    int key[2][2] = {{5,3},{2,1}};
	    int c[25],d[25];
	    char cipher2[25];
            printf("\n\nHill Cipher\n");
	    int determinant=0,t=0;
	    for(i=0;i<25;i++)
	    {
		c[i] = message[i]-65;
		printf("\n %d \n",c[i]);
	    }
	    for(i=0;i<strlen(message);i++)
	    {
		t=0;
		for(j=0;j<2;j++)
		{
		    t=t+(key[i][j]*c[j]);
		}
		d[i]=t%26;
	    }
	    printf("\nEncrypted Cipher Text :");
	    for(i=0;i<strlen(message);i++)
	    {
		printf(" %c",d[i]+65);
		cipher2[i]=d[i]+65;
	    }	
	    
	    vignere_encrypt(cipher2);
	    
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
	 
	    printf("Enter operation: encrypt or decrypt\n");
	    scanf("%s",&text);
	    /*printf("\nEnter shift key");
	    scanf("%d",&shift);*/
	    printf("\nEnter text to encrypt/decrypt");
	    scanf("%s",&cipher);

	    num = strlen (cipher);
	    result1 = strcmp (text, encrypt);
	    result2 = strcmp (text, decrypt);

	    if(result1 == 0)
	    {
	        caesar_decrypt(cipher, shift, num);
	    }
	    if(result2 == 0)
	    {
	        caesar_encrypt(cipher, 7, num);
	    }

	    printf("Result: \n");
	    printf(cipher);
	    
	    hill_encrypt(cipher);

	}



	    











