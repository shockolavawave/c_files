#include<stdio.h>
#include<stdlib.h>

int main()
{
	short a;
	int m, n, *mat, i, j, k;
	
	printf("This program will print the transpose of a given 2D matrix.\n"
		   "(All values should be integer only.)\n\n");
	
	printf("Enter the number of rows:    ");
	a = scanf("%d", &m);
	
	if(!a || m<=0)
	{
		printf("Invalid input.\nTry re-running.\n");
		exit(0);
	}
	
	fflush(stdin);
	printf("Enter the number of columns: ");
	a = scanf("%d", &n);
	
	if(!a || n<=0)
	{
		printf("Invalid input.\nTry re-running.\n");
		exit(0);
	}
	
	putchar('\n');
	//printing a template of the matrix
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
			printf("A[%03d][%03d]  ", (i+1), (j+1));
		putchar('\n');
	}
	
	mat = (int*)calloc(m*n, sizeof(int));
	
	if(mat==NULL)
	{
		puts("Insufficient memory for calculations.\nExiting");
		exit(0);
	}
	
	fflush(stdin);
	putchar('\n');
	//recording elements
	for(i=k=0; i<m; i++)
	{
		for(j=0; j<n; j++, k++)
		{
			printf("Enter element at A[%03d][%03d]: ", (i+1), (j+1));
			a = scanf("%d", (mat + k));
			
			fflush(stdin);
			
			if(!a)
			{
				printf("Invalid input.\nTry re-running.\n");
				exit(0);
			}
		}
		putchar('\n');
	}
	
	putchar('\n');
	printf("Your matrix is: \n");
	//printing matrix
	
	for(i=0; i<(n*7); i++)
		putchar('_');
	
	printf("\n\n");
	
	for(i=j=0; i<(m*n); i++)
	{
		printf("% 5d| ", *(mat + i));
		
		j++;
		
		if(j==n)
		{
			putchar('\n');
			j = 0;
		}
	}
	
	for(i=0; i<(n*7); i++)
		putchar('_');
	
	printf("\n\nand the transpose is:-\n");
	//printing transpose
	
	for(i=0; i<(n*7); i++)
		putchar('_');
	
	printf("\n\n");
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<(m*n); j += n)
			printf("% 5d| ", *(mat + i + j));

		putchar('\n');
	}
	
	for(i=0; i<(n*7); i++)
		putchar('_');
	
	free(mat);
	printf("\n\nThank you for using the program! ^_^\n");
	
	return 0;
}