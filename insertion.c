#include<stdio.h>

void insertion(int arr[],int n)
{
    int j,key;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

int main()
{
    int n;
    printf("Enter size of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    insertion(arr,n);
    printf("Array after sorting\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}