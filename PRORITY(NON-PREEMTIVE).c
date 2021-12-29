// CPU-Scheduling-Algorithm-In-C
// Non Pre-emptive Priority Scheduling Algorithm

#include<stdio.h>
#include<malloc.h>

void main()
{
	int n, i, j, pos, temp, *bt, *wt,
      	*tat, *p, *pt , *at , st=0 ;
	float avgwt = 0, avgtat = 0;
/***********************************************************************************************/
	printf(" Enter the number of processes :\n ");        /*  taking number of process .*/
    scanf("%d", &n);
/***********************************************************************************************/
    p  = (int*)malloc(n*sizeof(int));                      /* Processes .      */
    bt = (int*)malloc(n*sizeof(int));                      /* brust time .     */
    pt = (int*)malloc(n*sizeof(int));                      /* periority .      */
    wt = (int*)malloc(n*sizeof(int));                      /* wating time .    */
    tat= (int*)malloc(n*sizeof(int));                      /* turnaround time .*/
    at = (int*)malloc(n*sizeof(int));                      /* arrival time .   */
/***********************************************************************************************/	
 	printf(" Enter the burst time for each process \n");   /* taking brust time for each process .*/
    for(i=0; i<n; i++)
    {
        printf(" Burst time of P%d :\n ", i);
        scanf("%d", &bt[i]);
         p[i] = i;
    }
/***********************************************************************************************/
     printf(" Enter the arrival time for each process \n"); /* taking arrival time for each process .*/
    for(i=0; i<n; i++)
    {
        printf(" arrival  time for P%d : \n", i);
        scanf("%d", &at[i]);
        p[i] = i;
    }
/***********************************************************************************************/
     	printf("Enter the priority for each process \n "); /* taking priority for each process .*/
        for(i=0; i<n; i++)
    {
        printf(" Priority of P%d :\n ", i);
        scanf("%d", &pt[i]);
        p[i] = i;
    }
/***********************************************************************************************/
   for(i=0; i<n; i++)                        /* sort processes , brust time , arrival time according to arrival time */
    {
    	pos = i;
    	for(j=i+1; j<n; j++)
    	{
    	if(at[j] < at[pos])
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
/***********************************************************************************************/
    st = bt[0];                                         /* st variable used to store burst time for the processes. */
    for(int k = 1; k < n ; k++ )                        /* sort processes , brust time , arrival time according to priority */                            
    {
    for ( j = k; j < n ; j++ )
    {
    if(at[j]<st)
    {
    if(pt[j]<pt[k])
    {
    temp=at[k];
    at[k]=at[j];
    at[j]=temp;

    temp=bt[k];
    bt[k]=bt[j];
    bt[j]=temp;

    temp=p[k];
    p[k]=p[j];
    p[j]=temp;
    }                                          /* end of second if statment .*/
	}                                          /* end of first if statment . */
    }                                          /* end of second for loop.    */
    }                                          /* end of first for loop .    */
	
/***********************************************************************************************/		                                             
	wt[0] =0;
	tat[0]= bt[0];
    avgwt += wt[0];
    avgtat += tat[0];
 /***********************************************************************************************/   
	for (i =1 ; i < n ; i++)                 /* calculating waiting time and Turnaround Time . */
	{
       if((st - at[i])<0)                    /* if wating time < 0 -> it will be equled 1 .*/
       {
       wt[i] = 0;
       }                                    
       else
       {
        wt[i] = st - at[i];
       }
        tat[i] = wt[i] + bt[i];     
        avgwt += wt[i];
        avgtat += tat[i];
        st+=bt[i];
    }
/***********************************************************************************************/
    avgwt = avgwt/n;          /* calculating avarage for waiting time and Turnaround Time . */
    avgtat = avgtat/n;
/***********************************************************************************************/
    printf("\n PROCESS \t PRIORITY \t ARRIVAL \t BURST TIME \t WAITING TIME \t TURNAROUND TIME \n");      
    printf("--------------------------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" P%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t %d \n", p[i], pt[i], ar[i], bt[i], wt[i], tat[i]);
    }

    printf("\n Average Waiting Time = %f \n Average Turnaround Time = %f \n", avgwt, avgtat);

    printf("\n \tGAANT CHART \n");
    printf("---------------------------\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t|| P%d ||\t%d\n", wt[i], p[i], tat[i]);
    }
}