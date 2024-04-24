#include <stdio.h>

int totalCalls = 0;
void sumOfSubset(int arr[], int n, int sum, int targetSum, int idx, int currentSum, int subset[]) {
    totalCalls++;

    if (currentSum == targetSum) 
    {
        printf("Subset found with sum %d: ", targetSum);
        for (int i = 0; i < idx; i++) {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    if (idx >= n || currentSum > targetSum)
        return;


    subset[idx] = arr[idx];
    sumOfSubset(arr, n, sum + arr[idx], targetSum, idx + 1, currentSum + arr[idx], subset);

    subset[idx] = 0;
    sumOfSubset(arr, n, sum, targetSum, idx + 1, currentSum, subset);
}

int main() {
    int n, targetSum;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    int subset[n];

    sumOfSubset(arr, n, 0, targetSum, 0, 0, subset);

    printf("Total calls to sumOfSubset procedure: %d\n", totalCalls);

    return 0;
}
