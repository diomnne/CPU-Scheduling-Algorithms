#include <stdio.h>

typedef struct
{
	int id, arrival, burst, completion, turnaround, waiting;
}Process;

void sortByArrivalTime(Process p[], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(p[j].arrival > p[j+1].arrival)
			{
				Process temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
}

int main()
{
	int n;
	printf("\nNumber of Processes: ");
	scanf("%d", &n);

	if(n > 20)
	{
		printf("Maxiumum of 20 Processes only!");
		return 0;
	}

	Process p[n], sorted[n];

	for(int i=0; i<n; i++)
	{
		p[i].id = i+1;
		printf("\nPROCESS ID %d:", i+1);
		printf("\n");
		printf("Arrival Time: ");
		scanf("%d", &p[i].arrival);
		printf("Burst Time: ");
		scanf("%d", &p[i].burst);
		printf("\n");
	}

	sortByArrivalTime(p, n);

	int currentTime = 0;
	float sumTT = 0, sumWT = 0;

	for(int i=0; i<n; i++)
	{
		if(currentTime < p[i].arrival)
		{
			currentTime = p[i].arrival;
		}

		p[i].completion = currentTime + p[i].burst;
		p[i].turnaround = p[i].completion - p[i].arrival;
		p[i].waiting = p[i].turnaround - p[i].burst;

		sumTT += p[i].turnaround;
		sumWT += p[i].waiting;

		currentTime = p[i].completion;
	}

	printf("\nPID\tAT\tBT\tCT\tTT\tWT\n");
	for(int i=0; i<n; i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].id, p[i].arrival, p[i].burst, p[i].completion, p[i].turnaround, p[i].waiting);
	}

	printf("\nAverage Turnaround Time = %.2f", sumTT / n);
	printf("\nAverage Waiting Time = %.2f\n", sumWT / n);

}