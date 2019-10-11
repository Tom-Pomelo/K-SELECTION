#include <stdio.h>

void qsort(int *a, int left, int right, int k);
int partition(int *index_arr, int left, int right);
void swap(int *nums, int l, int r);

int doalg(int n, int k, int *Best) {
    int index_arr[n + 1];
    for (int i = 1; i <= n; ++i) {
        index_arr[i] = i;
    }

    for (int i = 0; i < k; ++i) Best[i] = -1;

    qsort(index_arr, 1, n, k);

    for (int i = 0; i < k; ++i) {
        Best[i] = index_arr[i + 1];
    }
    printf("\n");
    for (int i = 0; i < k; ++i) {
        printf("%d\n", Best[i]);
    }

    return 1;
}


void qsort(int *a, int left, int right, int k) {
    if (left >= right) return;
    int pivotat = partition(a, left, right);
    qsort(a, left, pivotat - 1, k);
    qsort(a, pivotat + 1, right, k);

}

int partition(int *index_arr, int left, int right) {
    int l = left + 1, r = right;
    while (l <= r) {
        if (COMPARE(index_arr[left], index_arr[l]) == 1 && COMPARE(index_arr[left], index_arr[r]) == 2) {
            swap(index_arr, l, r);
            l++;
            r--;
        }
        if (COMPARE(index_arr[left], index_arr[l]) == 2) {
            l++;
        }
        if (COMPARE(index_arr[left], index_arr[r]) == 1) {
            r--;
        }
    }
    swap(index_arr, left, r);
    return r;
}

void swap(int *nums, int l, int r) {
    int temp = nums[l];
    nums[l] = nums[r];
    nums[r] = temp;
}
