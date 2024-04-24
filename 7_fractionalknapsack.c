#include<stdio.h>

typedef struct object
{
    int id, weight,profit;
    float ratio;
}object;

void knapsack(int kc, int n, object objects[])
{
    int rem = kc;
    double finalValue=0.0;
    for(int i=0; i<n; i++)
    {
        if(rem>=objects[i].weight)
        {
            rem-=objects[i].weight;
            finalValue+=objects[i].profit;
        }
        else
        {
            finalValue=finalValue+objects[i].profit*((double)rem/objects[i].weight);
            break;
        }
    }
    printf("Final Value = %.2f\n", finalValue);
}

void main()
{
    int kc, n;
    

    printf("Enter the quantity of knapsack\n");
    scanf("%d", &kc);

    printf("Enter number of objects\n");
    scanf("%d", &n);

    object objects[n];
    for(int i=0; i<n; i++)
    {
        printf("Enter weight and profit of object %d : \n", i);
        scanf("%d%d", &objects[i].weight, &objects[i].profit);
        objects[i].ratio = objects[i].profit/(float)objects[i].weight;
        objects[i].id = i+1;
    }

    printf("Before sorting: \n\n");
    printf("Object\t\tWeight\t\tProfit\t\tRatio\n");

    for(int i=0; i<n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%2f\n", objects[i].id,objects[i].weight, objects[i].profit, objects[i].ratio);
    }

    printf("\nAfter sorting\n\n");
object temp;
    for(int i=0; i<n; i++)
    {
        // printf("%d\t\t%d\t\t%d\t\t%d\n", objects[i].id,objects[i].weight, objects[i].profit, objects[i].ratio);
        for(int j=0; j<n-i-1; j++) 
        {
            if(objects[j].ratio<objects[j+1].ratio)
            {
                temp = objects[j];
                objects[j] = objects[j+1];
                objects[j+1]=temp;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%2f\n", objects[i].id,objects[i].weight, objects[i].profit, objects[i].ratio);
    }
    knapsack(kc, n, objects);
}

