//
// Created by 赵政杰 on 2021/11/13.
//
#include <stdio.h>
#define MAX 100
void SelectionSort(int arr[], int len);
void NextPermutation (int numbers[], int n);
int Equal(int s1[], int n);

int num[MAX] = {0};

int main() {
    int n = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
}

int turns = 1;
    for (int i = 1; i <= n; i++) {
        turns *= i;
    }

    SelectionSort(num, n);

for (int i = 1; i <= n; i++) {
    printf("%d ", num[i]);
}
    printf("\n");
    for (int i = 1; i < turns; i++) {
        if (Equal(num, n)) {
            break;
        }
        NextPermutation(num, n);
        printf("\n");

    }
    return 0;
}

void SelectionSort(int arr[], int len) {
    for (int i = 1; i <= len; ++i) {
        int min = arr[i];
        int min_index = i;

        for (int j = i + 1; j <= len; j++) {
            if (min > arr[j]) {
                min = arr[j];
                min_index = j;
            }
        }

        int tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
    }
}

void NextPermutation (int numbers[], int n) {
    int m = 1;
    for (int i = n; i > 1; i--) {
        if (numbers[i - 1] >= numbers[i]) {
            m++;
        } else {
            break;
        }
    }

    int px = 0;
    int index = 0;
    for (int i = n; i > n - m; i--) {
        if (numbers[i] > numbers[n - m]) {
            px = numbers[i];
            index = i;
            break;
        }
    }

    numbers[index] = numbers[n - m];
    numbers[n - m] = px;

    int new_numbers[MAX] = {0};
    for (int i = 1; i <= n; i++) {
        if (i <= n - m) {
            new_numbers[i] = numbers[i];
        } else {
            new_numbers[i] = numbers[2 * n - m + 1 - i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", new_numbers[i]);
    }

    for (int i = 1; i <= n; i++) {
        numbers[i] = new_numbers[i];
    }
}

int Equal(int s1[], int n) {
    for (int i = 1; i < n; i++) {
        if (s1[i] < s1[i + 1]) {
            return 0;
        }
    }
    return 1;
}

