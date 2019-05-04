#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <ctype.h>
#include <unistd.h>

#define bufSize 100
#define SIZE 100

const char *alphabet = "abcdefghijklmnopqrstuvwxyz";

int main()
{
	int choice1;
	int choice2;
	char *passwordArray[bufSize];
	char *passwordArray2[bufSize];
	char *passwordCompareArray[bufSize];

	//Will hold string, so should be size of our max string
	unsigned char ibuf[SIZE];

	//SHA256 hash, so only needs to be 32 bytes
	unsigned char hashbuf[32];

	char *hashbuf2[32];
	char buffer[bufSize];
	char buffer2[1000];
	char username[9];
	char password[9];


	//File handling.
	FILE *f;
	FILE *f1;
	FILE *f2;
	FILE *f12;
	int m = 0;
	int z = 0;

	//Starting options.
	printf("Which file would you like to attack: \n");
	printf("1)Plain password.\n");
	printf("2)Hashed password.\n");
	printf("3)Hashed + salt password.\n");
	scanf("%d", &choice1);

	switch(choice1)
	{
		case 1:
			f = fopen("plainAccount2.txt", "r");				

			printf("Brute force on hashed account.\n");
	
			//Read the line from file.
			while(fgets(buffer, sizeof(buffer), f) != NULL)
			{
				int i;
				
				for (i = 0; i < strlen(buffer)-1; i++)
				{
					
					if(isspace(buffer[i])) 
					{
						
						i = i+1;

						int k,l;
						
						passwordArray[m] = malloc(100* sizeof(char));
						
						for (k = 0, l = i; l < strlen(buffer)-1; k++,l++)
						{
							
							passwordArray[m][k] = buffer[l];
						}
					}

				}
				m++;
			
			}
		
/*			int n;
		

			for(n = 0; n < m; n++)
			{
				printf("%s\n",passwordArray[n]);
			}

*/
			passwordCompareArray[0] = malloc(100* sizeof(char));
			


    			for(passwordCompareArray[0][0] = 'a'; passwordCompareArray[0][0] <= 'z'; passwordCompareArray[0][0]++)
			{
            			for(passwordCompareArray[0][1] = 'a'; passwordCompareArray[0][1] <= 'z'; passwordCompareArray[0][1]++) 
				{
	                		for(passwordCompareArray[0][2] = 'a'; passwordCompareArray[0][2] <= 'z'; passwordCompareArray[0][2]++) 
					{
						//Hash compare
						if(strcmp(passwordCompareArray[0], passwordArray[0]) == 0)
						{
							printf("%s -> %s\n", passwordCompareArray[0], passwordArray[0]);
							printf("Math found!\n");

							return(0);
						}
					}	
				}
			}

			fclose(f);
			break;
		case 2:
			f1 = fopen("hashedAccount2.txt", "r");

			printf("Brute force on hashed account.\n");
			
			//Read the line from file.
			while(fgets(buffer, sizeof(buffer), f1) != NULL)
			{
				int i;
				
				for (i = 0; i < strlen(buffer)-1; i++)
				{
					
					if(isspace(buffer[i])) 
					{
						
						i = i+1;

						int k,l;
						
						passwordArray[m] = malloc(100* sizeof(char));
						
						for (k = 0, l = i; l < strlen(buffer)-1; k++,l++)
						{
							
							passwordArray[m][k] = buffer[l];
						}
					}

				}
				m++;
			
			}
/*		
			int n;
		

			for(n = 0; n < m; n++)
			{
				printf("%s\n",passwordArray[n]);
			}

*/
				
			passwordCompareArray[0] = malloc(100* sizeof(char));
			




			int flag[32];
			hashbuf2[0] = malloc(100* sizeof(char));

			passwordArray2[0] = malloc(1200000* sizeof(char));

			FILE *temp = fopen("temp.txt","w");
			//printf("%s\n",passwordCompareArray[0]);
    		
			for(passwordCompareArray[0][0] = 'a'; passwordCompareArray[0][0] <= 'z'; passwordCompareArray[0][0]++)
			{
            			for(passwordCompareArray[0][1] = 'a'; passwordCompareArray[0][1] <= 'z'; passwordCompareArray[0][1]++) 
				{
	                		for(passwordCompareArray[0][2] = 'a'; passwordCompareArray[0][2] <= 'z'; passwordCompareArray[0][2]++) 
					{
						int n;
					
						for(n = 0; n < 100; n++) 
						{
							ibuf[n] = passwordCompareArray[0][n];
						}

						SHA256(ibuf, strlen(passwordCompareArray[0]), hashbuf);
					
						int k;
						for(k = 0; k < 32; k++) 
						{
					
							if(hashbuf[k] == passwordArray[0][k]) 
							{
								flag[k] = 1;						
							}
						
							//fprintf(temp, "%02x", hashbuf[k]);
						}
						//fprintf(temp,"\n");													       
					}
				}
			}
		
			int p;
			printf("Flag Match Found: ");
		
			for(p = 0; p < 32; p++) 
			{
				printf("%d", flag[p]);
			}
		
			printf("\n");
			printf("Match Found: %s\n",passwordArray[0]);

			fclose(f1);
			break;
		case 3:
			f2 = fopen("hashedSaltAccount2.txt", "r");

			printf("Brute force on hashed account.\n");
			
			//Read the line from file.
			while(fgets(buffer, sizeof(buffer), f2) != NULL)
			{
				int i;
				
				for (i = 0; i < strlen(buffer)-1; i++)
				{
					
					if(isspace(buffer[i])) 
					{
						
						i = i+1;

						int k,l;
						
						passwordArray[m] = malloc(100* sizeof(char));
						
						for (k = 0, l = i; l < strlen(buffer) - 1; k++, l++)
						{
							
							passwordArray[m][k] = buffer[l];
						}
					}
				}
				m++;
			}
		
			int n;
		
/*
			for(n = 0; n < m; n++)
			{
				printf("%s\n",passwordArray[n]);
			}

*/
			
	
	
			passwordCompareArray[0] = malloc(10000* sizeof(char));

			int flag2[32], i;
				
			int salt = rand () % 1000 + 1;
			char saltS[1000];
			sprintf(saltS, "%d", i);				

			strcat(passwordCompareArray[0],saltS);

			//printf("%s\n",passwordCompareArray[0]);
	
			for(passwordCompareArray[0][0] = 'a'; passwordCompareArray[0][0] <= 'z'; passwordCompareArray[0][0]++)
			{
            			for(passwordCompareArray[0][1] = 'a';passwordCompareArray[0][1] <= 'z';passwordCompareArray[0][1]++) 
				{
	                		for(passwordCompareArray[0][2] = 'a'; passwordCompareArray[0][2] <= 'z'; passwordCompareArray[0][2]++) 
					{	
						int s;
		
						//Copy over string to buffer
						for(s = 0; s < 100; s++)
						{
							ibuf[s] = passwordCompareArray[0][s];
						}
						
						SHA256(ibuf, strlen(passwordCompareArray[0]), hashbuf);
						
						int k;
						for(k = 0; k < 32; k++) 
						{
								
							if(hashbuf[k] == passwordArray[0][k]) 
							{
								flag2[k] = 1;					
							}
						}													                       
					}
				}
			}

			int w;
		
			printf("Flag Match Found: ");
			
			for(w = 0; w < 32; w++) 
			{
				printf("%d", flag2[w]);
			}
		
			printf("\n");
			printf("Match Found: %s\n",passwordArray[0]);

			fclose(f2);
			break;
		default:

			printf("Error: Unknown choice.\n");
			break;
	}
	return 0;
}
