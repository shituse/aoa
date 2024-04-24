#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int temp1;
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            temp1=arr[i];
            arr[i]=arr[j];
            arr[j]=temp1;
        }
    }
    temp1=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp1;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    printf("Enter number of elements: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    quickSort(arr, 0, n - 1);
    
    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
