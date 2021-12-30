
#include<stdio.h>
#include<malloc.h>

void main()
{
	int n, i, j, pos, temp,
	   *bt, *wt, *tat, *p ,
	   *st ,*at ;                                     
	float avgwt = 0, avgtat = 0;
/******************************************************************************************************************/
	printf("\n Enter the number of processes : ");         /*  taking number of process .*/
    scanf("%d", &n);
/******************************************************************************************************************/
    p  = (int*)malloc(n*sizeof(int));                      /* Processes .        */
    bt = (int*)malloc(n*sizeof(int));                      /* brust time .       */
    wt = (int*)malloc(n*sizeof(int));                      /* waiting time .     */
    tat= (int*)malloc(n*sizeof(int));                      /* turnaround time .  */
    st = (int*)malloc(n*sizeof(int));                      /* service time  .    */
    at = (int*)malloc(n*sizeof(int));                      /* arrival time .     */
/******************************************************************************************************************/
 	printf("\n Enter the burst time for each process \n");            /* taking brust time for each process .*/
    for(i=0; i<n; i++)
    {
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
        p[i] = i;
    }
/******************************************************************************************************************/
    printf("\n Enter the arrival time for each process \n");        /* taking arrival time for each process .*/
    for(i=0; i<n; i++)
    {
        printf(" Burst arrival for P%d : ", i);
        scanf("%d", &at[i]);
        p[i] = i;
    }
/******************************************************************************************************************/
for (i = 0; i<n; i++)                 /* sort processes , brust time , arrival time according to arrival time */
	{
		pos = i;
		for (j = i + 1; j<n; j++)
		{
			if (at[j] < at[pos])
			{
				pos = j;
			}
		}
		
		temp = at[i];
		at[i] = at[pos];
		at[pos] = temp;

		temp = bt[i];
		bt[i] = bt[pos];
		bt[pos] = temp;

		temp = p[i];
		p[i] = p[pos];
		p[pos] = temp;
	}
/********************************************************************************************/
	st[0]= 0;
    wt[0] = 0;
    tat[0] = bt[0];
    avgwt += wt[0];
    avgtat += tat[0]; 
/******************************************************************************************************************/
    for(i=1; i<n; i++)                          /* calculating waiting time and Turnaround Time . */
    {
		st[i] = st[i-1] + bt [i-1];
		wt[i] = st[i] - at[i]; 
		if((wt[i])<0)                      /* if wating time < 0 -> it will be equled 1 .*/
          {
            wt[i] = 0;
           } 
        else 
        {
            wt[i] = wt[i];
        }
		tat[i] = wt[i] + bt[i]  ;               
        
         avgwt += wt[i];
        avgtat += tat[i]; 
    }
/******************************************************************************************************************/    
    avgwt = avgwt/n;                       /* calculating avarage for waiting time and Turnaround Time . */
    avgtat = avgtat/n;
/******************************************************************************************************************/
    printf("\n PROCESS \t ARRIVAL TIME \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d \n", p[i], at[i] ,bt[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("-------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i], tat[i]);
    }
}

