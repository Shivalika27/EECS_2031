# include <stdio.h>
# include <string.h>

void main()
{
	int size = 100;
	char input1[size];
	char input2[size];
	char result[size];
	int i, j;
	int count;
	
	for(i = 0; i < size; i++)
	{
		input1[i] = '\0';	
		input2[i] = '\0';
		result[i] = '\0';
	}		

	fgets(input1, size, stdin);
	fgets(input2, size, stdin);

	int length1 = strlen(input1);
	int length2 = strlen(input2);
	
	if (input1[length1 - 1] == '\n')
	{
		input1[length1 - 1] = '\0';
	}
	
	if (input2[length2 - 1] == '\n')
	{
		input2[length2 - 1] = '\0';
	}

	length1 = strlen(input1);
	length2 = strlen(input2);

	if (input1[0] == '\0' || input2[0] == '\0')
	{ 	
		printf("0\n");
		return;
	}

	for (i = 0; i < length1; i ++)
	{
		for (j = 0; j < length2; j ++)
		{
			int z1 = 0;
			int z2 = 0;

			z1 = i;
			z2 = j;

			while(input1[z1] == input2[z2])
			{
							
				z1++;
				z2++;
			}

			if (input1[z1] == '\0' || input2[z2] == '\0')
			{
				break;
			}
		}

		if (  j < length2)
		{
			break;
		}
	}
	
	
	int k, l;
	if (i == 0)
	{
		count = length2 - j;
		l = 0;

		for (k = 0;k < (j + count); k ++)
		{
			result[l] = input2[k];
			l++; 
		}

		for (k = count; k < length1; k ++)
                {
                        result[l] = input1[k];              
                        l++;
                }

		if (count > length1)
		{
			count = length1;
			strcpy(result, input2);		
		}
	}
	
	else if (j == 0)
	{
		count = length1 - i;
		l = 0;
		
		for (k = 0;k < (i + count); k ++)
                { 
                        result[l] = input1[k];
			l++;
                }
	
		for (k = count; k < length2; k ++)
		{
			result[l] = input2[k];
			l++;
		}
		
		if (count > length2)
		{
			count = length2;
			strcpy(result, input1);	
		}
	}

	printf("%d\n", count);
}
