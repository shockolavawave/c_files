#include<stdio.h>
#include<stdlib.h>

int main()
{
	short a;
	int m1, n1, *mat1, m2, n2, *mat2, i, j, k, l, tr, tc, *trnsp, *mul_mat, mid, max, p;
	
	printf("This program will multiply the matrices matrix_1 and matrix_2.\n"
		   "(All the values should be integer only.)\n\n");
	
	printf("Enter the number of rows and columns in matrix_1: ");
	a = scanf("%d%d", &m1, &n1);
	
	if(a!=1 || m1<=0 || n1<=0)
	{
		printf("Invalid input!\nTry re-running\n");
		exit(0);
	}
	
	fflush(stdin);
	printf("Enter the number of rows and columns in matrix_2: ");
	a = scanf("%d%d", &m2, &n2);
	
	if(a!=1 || m2<=0 || n2<=0)
	{
		printf("Invalid input!\nTry re-running\n");
		exit(0);
	}
	
	if(n1!=m2)
	{
		printf("The no. of columns of matrix_1 is not equal to no. of rows of matrix_2,\n"
			   "Hence, multiplication of matrices of these order is not possible");
		puts("\nTry re-running.");
		exit(0);
	}
	
	printf("\nThe template for matrix_1 is:-\n\n");
	//printing a template for matrix 1
	for(i=0; i<m1; i++)
	{
		for(j=0; j<n1; j++)
			printf("A[%03d][%03d]  ", (i+1), (j+1));
		putchar('\n');
	}
	
	//allocating memory for matrix 1
	mat1 = (int*)calloc(m1*n1, sizeof(int));
	
	if(mat1==NULL)
	{
		puts("Insufficient memory for matrix_1.\nExiting");
		exit(0);
	}
	
	fflush(stdin);
	putchar('\n');
	//recording elements into matrix 1
	for(i=k=0; i<m1; i++)
	{
		for(j=0; j<n1; j++, k++)
		{
			printf("Enter element at A[%03d][%03d]: ", (i+1), (j+1));
			a = scanf("%d", (mat1 + k));
			
			fflush(stdin);
			
			if(a!=1)
			{
				printf("Invalid input.\nTry re-running.\n");
				exit(0);
			}
		}
		putchar('\n');
	}
	
	printf("\nThe template for matrix_2 is:-\n\n");
	//printing a template for matrix 2
	for(i=0; i<m2; i++)
	{
		for(j=0; j<n2; j++)
			printf("B[%03d][%03d]  ", (i+1), (j+1));
		putchar('\n');
	}
	
	//allocating memory for matrix 2
	mat2 = (int*)calloc(m2*n2, sizeof(int));
	
	if(mat2==NULL)
	{
		puts("Insufficient memory for matrix_2.\nExiting");
		exit(0);
	}
	
	fflush(stdin);
	putchar('\n');
	//recording elements into matrix 2
	for(i=k=0; i<m2; i++)
	{
		for(j=0; j<n2; j++, k++)
		{
			printf("Enter element at B[%03d][%03d]: ", (i+1), (j+1));
			a = scanf("%d", (mat2 + k));
			
			fflush(stdin);
			
			if(a!=1)
			{
				printf("Invalid input.\nTry re-running.\n");
				exit(0);
			}
		}
		putchar('\n');
	}
	
	//creating a transpose of mat2 for calculations
	tr = n2;
	tc = m2;
	
	trnsp = (int*)calloc(tr*tc, sizeof(int));
	
	if(trnsp==NULL)
	{
		puts("Insufficient memory for calculations.\nExiting");
		exit(0);
	}
	
	for(i=k=0; i<n2; i++)
	{
		for(j=0; j<(tr*tc); j += n2, k++)
		{
			*(trnsp + k) = *(mat2 + i + j);
		}
	}
	
	//allocating memory for the resultant matrix
	mul_mat = (int*)calloc((m1*n2), sizeof(int));
	
	//multiplying elements
	for(i=l=0; l<(m1*n2); i++)
		for(j=0; j<tr; j++,l++)
			for(k=0; k<tc; k++)
				*(mul_mat + l) += (*(mat1 + (i*n1) + k)) * (*(trnsp + (j*tc) + k));
	
	puts("\nThe resultant matrix is:-\n");
	
	//combined display
	max = (m1>n1)?(m1):(n1);
	max = (max>n2)?(max):(n2);
	
	mid = (!(max%2))?((max/2)-1):(((max+1)/2)-1);
	
	for (i=j=k=l=0; i<max; i++)
	{
		//mat1 display row by row
		if(j<(m1*n1))
			while(j<(m1*n1))
			{
				printf("% 5d|", *(mat1 + j));
				
				j++;
				if(!(j%n1))
					break;
			}
		else
			for(p=0; p<(6*n1); p++)
				printf(" ");
		
		//multiplication sign
		printf((i==mid)?"        x      ":"               ");
		
		//mat2 display row by row
		if(k<(m2*n2))
			while(k<(m2*n2))
			{
				printf("% 5d|", *(mat2 + k));
				
				k++;
				if(!(k%n2))
					break;
			}
		else
			for(p=0; p<(6*n2); p++)
				printf(" ");
		
		//equals sign
		printf((i==mid)?"        =      ":"               ");
		
		//resultant matrix row by row
		if(l<(m1*n2))
			while(l<(m1*n2))
			{
				printf("% 5d|", *(mul_mat + l));
				
				l++;
				if(!(l%n2))
					break;
			}
		else
			for(p=0; p<(6*n1); p++)
				printf(" ");
		
		putchar('\n');
	}
	
	//freeing up memory
	free(mat1); free(mat2); free(trnsp); free(mul_mat);
	
	puts("\nThank you for using the program! (^_^)");
	
	return 0;
}
