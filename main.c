#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void sort(int *s_arr, int first, int last); // ukazatel na massiv i poslednee i pervoe chislo

int main(void) {
    int arr[SIZE] = {}; //obyavlenie massiva
    printf("Random generated array: ");
    for (int i=0; i < SIZE; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    sort(arr, 0, SIZE - 1);
    printf("\nSorted array: ");
    for (int i=0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void sort (int *s_arr, int first, int last){
    if (first<last){
        int left = first;
        int right = last;
        int middle = s_arr[(left + right) / 2];
        do{
            while (s_arr[left] < middle)
                left++;
            while (s_arr[right] > middle)
                right--;
            if (left <= right){
                int tmp = s_arr[left];
                s_arr[left] = s_arr [right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left < right);
        sort(s_arr, first, right);
        sort(s_arr, left, last);
    }
}