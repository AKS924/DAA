#include <stdio.h>
#include <conio.h>
void sort(int file[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (file[i] > file[j])
            {
                temp = file[i];
                file[i] = file[j];
                file[j] = temp;
            }
        }
    }
}

void main()
{
    int n, i;
    int cost = 0;
    int file[20];
    clrscr();

    printf("Enter number of files: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter size of file %d: ", i + 1);
        scanf("%d", &file[i]);
    }
    sort(file, n);
    while (n > 1)
    {
        int merge_file = file[0] + file[1];

        cost = cost + merge_file;

        for (i = 1; i < n - 1; i++)
        {
            file[i] = file[i + 1];
        }

        file[0] = merge_file;

        n = n - 1;

        sort(file, n);
    }
    printf("\nMinimum Cost of Merging: %d", cost);

    getch();
}