#include <stdio.h>

#define MAX 10
void bucketSort(int arr[], int n) {
    int bucket[MAX][MAX], bucketCount[MAX];
    int i, j, k;
    for (i=0;i<MAX;i++)
        bucketCount[i]=0;
    int maxVal=arr[0];
    for (i=1;i<n;i++)
        if (arr[i]>maxVal)
            maxVal=arr[i];
    for (i=0;i<n;i++) {
        int index=(arr[i]*MAX)/(maxVal+1);
        bucket[index][bucketCount[index]++]=arr[i];
    }
    for (i=0; i<MAX;i++) {
        for (j=1; j<bucketCount[i];j++) {
            int key=bucket[i][j];
            k=j-1;
            while (k>=0 && bucket[i][k]>key) {
                bucket[i][k+1]=bucket[i][k];
                k--;
            }
            bucket[i][k+1]=key;
        }
    }
    k=0;
    for (i=0;i<MAX;i++) {
        for (j=0; j<bucketCount[i];j++) {
            arr[k++]=bucket[i][j];
        }}}
int main() {
    int n, i;
    printf("enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter %d elements: ", n);
    for (i=0;i<n;i++)
        scanf("%d", &arr[i]);
    bucketSort(arr, n);
    printf("sorted array using Bucket Sort: ");
    for (i=0;i<n;i++)
        printf("%d ", arr[i]);
    return 0;
}
