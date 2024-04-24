#include<stdio.h>

int max(int a, int b)
{
    return(a>b?a:b);
}


int knapsack(int kc, int wt[], int val[], int n)
{
    if(kc==0 || n==0)
    return 0;

    if(wt[n-1]>kc)
    return knapsack(kc,wt, val, n-1);

    else return max(val[n-1]+knapsack(kc-wt[n-1], wt,val, n-1), knapsack(kc, wt,val, n-1));
}

int main()
{
    int kc, n;

     printf("Enter Knapsack Capacity\n");
    scanf("%d", &kc);

    printf("Enter number of objects\n");
    scanf("%d", &n);

    int wt[n], val[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter weight and profit of object %d: ", i+1);
        scanf("%d%d", &wt[i], &val[i]);
    }

    printf("%d", knapsack(kc, wt, val, n));
}