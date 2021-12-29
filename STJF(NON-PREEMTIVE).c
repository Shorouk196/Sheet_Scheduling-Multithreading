
#include<stdio.h>
#include<malloc.h>

void main()
{
	int n, i, j, pos, temp,
	    *bt, *wt, *tat, *p ,
	    *st ,*at ;                                     /* st for service time (finsh time)  and at for arrival time. */
	float avgwt = 0, avgtat = 0;
/******************************************************************************************************************/
	printf("\n Enter the number of processes : ");
    scanf("%d", &n);
/******************************************************************************************************************/
    p = (int*)malloc(n*sizeof(int));
    bt = (int*)malloc(n*sizeof(int));
    wt = (int*)malloc(n*sizeof(int));
    tat = (int*)malloc(n*sizeof(int));
    st = (int*)malloc(n*sizeof(int));
    at = (int*)malloc(n*sizeof(int));
/******************************************************************************************************************/
 	printf("\n Enter the burst time for each process \n");
    for(i=0; i<n; i++)
    {
        printf(" Burst time for P%d : ", i);
        scanf("%d", &bt[i]);
        p[i] = i;
    }
    printf("\n Enter the arrival time for each process \n");
    for(i=0; i<n; i++)
    {
        printf(" Burst arrival for P%d : ", i);
        scanf("%d", &at[i]);
        p[i] = i;
    }

		for (i = 0; i<n; i++)
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
		for (i = 1; i<n; i++)
	{
		pos = i;
		for (j = i + 1; j<n; j++)
		{
			if (bt[j] < bt[pos])
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
    for(i=1; i<n; i++)
    {
		st[i] = st[i-1] + bt [i-1];            /* service time for process =  service time for Previous process + brust time for Previous process*/
		wt[i] = st[i] - at[i];                 /* waiting time[p] = service time[p-1] + arrival Time[p-1] */
        tat[i] = wt[i] + bt[i] ;                /*Turnaround Time = Waiting Time + Burst Time */
        
         avgwt += wt[i];
        avgtat += tat[i]; 
    }
  

    
    avgwt = avgwt/n;
    avgtat = avgtat/n;

    printf("\n PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");
    printf("--------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("-------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i], tat[i]);
    }
}

