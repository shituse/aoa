#include<stdio.h>

void selection(int arr[], int n)
{
    int min, temp;
    for(int i=0;i<n; i++)
    {
        min=i;
        for(int j=i+1; j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}

void main()
{
    int n;
    printf("Enter array length: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements : \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    selection(arr,n);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}
