#include <stdio.h>

typedef struct nonpresjf
{
	int at,bt,ft,tat,wt,inq;
}nonpresjf;
nonpresjf p[20],p1[20];

int main()
{
	int ts;
	int i,limit,nextval,m,min,n;
	p[0].wt=p[0].tat=0;	
	printf("\nEnter the no of process: ");
	scanf("%d",&n);
	printf("\n\n");
	for(i=1;i<=n;i++)
	{
		printf("Enter the arrival time for the process P%d: ",i);
		scanf("%d",&p[i].at);	
	}
	limit=p[1].at;
	for(i=1;i<=n;i++)
	{
		printf("Enter the burst time for the process P%d: ",i);
		scanf("%d",&p[i].bt);
	}
	printf("Enter the time slide: ");
	scanf("%d", &ts);
	for(i=1;i<=n;i++)
		limit+=p[i].bt;
	for(i=1;i<=n;i++) {
		p[i].inq = p[i].at;
		p1[i]=p[i];
	}
	printf("\n\nGantt chart is as follows: \n\n");
	printf("%d",p[1].at);
	nextval=p[1].at;
	do
	{
		i=1;
		m=n;
		while((p[i].at)<=nextval && i<=n) {
          	if((p[i].inq<p[m].inq) && (p[m].bt>0) && (p[i].bt>0)) m=i;
        	i++;
		}
		if (p[m].bt <= ts) {
			nextval+=p[m].bt;
			p[m].bt=0;
			p[m].ft=nextval;
			p[m].tat=p[m].ft-p[m].at;
			p[m].wt=p[m].tat-p1[m].bt;
			p[0].tat+=p[m].tat;
			p[0].wt+=p[m].wt;
		}
		else {
			nextval+=ts;
			p[m].bt-=ts;
			p[m].inq=nextval;
		}
		printf("->P%d->%d",m,nextval);
	}while(nextval<limit);
	p[0].tat=p[0].tat/n;
	printf("\n\n-------------------TABLE----------------------------------\n");
	printf("\nProcess\tAT\tBT\tFT\tTAT\tWT\n");
	for(i=1;i<=n;i++)
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d\n",i,p[i].at,p1[i].bt,p[i].ft,p[i].tat,p[i].wt);
	double wait = p[0].wt*1.0/n;
	printf("Total waiting time: %f\n", wait);
	printf("\n\n-----------------------------------------------------------\n");	
	return 0;	
}