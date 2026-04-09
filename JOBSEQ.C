#include <stdio.h>
#include <conio.h>
struct Job {
    int id;
    int deadline;
    int profit;
};
void sort(struct Job jobs[], int n)
{
    int i, j;
    struct Job temp;

    for (i = 0; i < n - 1; i++)
    {
	for (j = i + 1; j < n; j++)
	{
	    if (jobs[i].profit < jobs[j].profit)
	    {
		temp = jobs[i];
		jobs[i] = jobs[j];
		jobs[j] = temp;
	    }
	}
    }
}

void main()
{
    int n, i, j;
    int max_deadline = 0;
    int total_profit = 0;
    struct Job jobs[20];
    int slot[20];
    int result[20];
    clrscr();

    printf("Enter number of jobs: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
	printf("Enter Job ID, Deadline and Profit for job %d: ", i + 1);
	scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }
    sort(jobs, n);
    for (i = 0; i < n; i++)
    {
	if (jobs[i].deadline > max_deadline)
	{
	    max_deadline = jobs[i].deadline;
	}
    }
    for (i = 0; i < max_deadline; i++)
    {
	slot[i] = 0;
	result[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
	for (j = jobs[i].deadline - 1; j >= 0; j--)
	{
	    if (slot[j] == 0)
	    {
		slot[j] = 1;
		result[j] = jobs[i].id;
		total_profit += jobs[i].profit;
		break;
	    }
	}
    }
    printf("\nJob Sequence: ");
    for (i = 0; i < max_deadline; i++)
    {
	if (result[i] != 0)
	{
	    printf("%d ", result[i]);
	}
    }

    printf("\nMaximum Profit: %d", total_profit);

    getch();
}