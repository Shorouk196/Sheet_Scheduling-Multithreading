#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int R1 , C1 , R2 , C2 ;                  /* R1 for ROW1 , C1 for COLUMN 1 ,R2 for ROW2 , C2 for COLUMN 2 */
int MatrixA[10][10];                     
int MatrixB[10][10];
int Result[10][10];
/* ================================================================================= */
void* multi_matrices(void* Arg)          /*  multibly two matrix */
{
	int  i,j,k;
	int sum =0;
	for ( i= 0 ; i< R1 ; i++ )
    {
	  for(j = 0; j < C2 ; j++)
	 {
	   for(k = 0; k < R2; k++)
	    {
	      sum = sum + MatrixA[i][k]*MatrixB[k][j];
	    }
		Result[i][j] = sum;
		sum =0;
	  }
	}
}
int main()
{
int i , j ;
printf("Enter number of rows and columns for Matrix [1]\n");    /* entering number of row and column for matrix A*/
printf(" Row1 : \n");
scanf(" %d" ,&R1);
printf("Column1 :\n ");
scanf(" %d" ,&C1);
/* ================================================================================= */
printf("Please enter Matrix [1] values \n ");                         /* entering values of matrix A*/
for ( i = 0; i < R1; i++)
{
for ( j = 0; j < C1; j++)
{
scanf("%d",&MatrixA[i][j]);
}
}
/* ================================================================================= */
printf("Enter number of rows and columns for Matrix [2]\n");             /* entering number of row and column for matrix B*/
printf(" Row2 : \n");
scanf(" %d" ,&R2);
printf("Column2:\n");
scanf(" %d" ,&C2);
/* ================================================================================= */
if (R2 != C1)                                                        /* for multiply 2 matrix it must be R2 = C1 */
{                                                                    /* if R2 != C1 the print this message */
printf("Error ! ,  C1 and R2 must be same  value \n");              
}
else{

/* ================================================================================= */
printf("Please enter Matrix [2] values \n ");             /* entering values of matrix B*/
for(i = 0; i < R2 ; i++)
{
for(j = 0; j < C2; j++)
{
scanf("%d",&MatrixB[i][j]);
}
}
/*==================================================================================================*/

pthread_t tid[R1];
for(i = 0; i < R1 ; i++)                      /* create threads */
{
    int *p;
    pthread_create(&tid[i], NULL, &multi_matrices, (void*)(p));
}
for(i = 0; i < R1 ; i++)                /* wait for all threads end */
{
    pthread_join(tid[i], NULL);
}
/*================================================================================================*/

printf(" MatrixA : \n");               /* print matrix A */
for(i = 0; i < R1 ; i++)
{
for(j = 0; j < C1; j++)
{
printf("%d\t ", MatrixA[i][j] );
}
printf ("\n");
}
/*================================================================================================*/
printf(" MatrixB : \n");              /* print matrix A */
for(i = 0; i < R2 ; i++)
{
for(j = 0; j < C2; j++)
{
printf("%d\t ", MatrixB[i][j] );
}
printf ("\n");
}
/*================================================================================================*/
printf(" Result : \n");            /* print matrix result */
	for(i = 0; i < R1 ; i++)
	{
	for(j = 0; j < C2; j++)
	{
	printf("%d\t ", Result[i][j] );
	}
	printf ("\n");
	}
}
return 0;
}