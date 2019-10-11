#include <stdio.h>

void qsort(int* a, int left, int right);
int partition(int *index_arr, int left, int right);
void swap(int *nums, int l, int r);

int doalg(int n, int k, int *Best) {
    for (int i = 1; i <= n; ++i) {
        Best[i] = i;
    }

    qsort(Best, 1, n);

    for (int i = 0; i < k; ++i) {
        Best[i] = Best[i + 1];
    }
    for (int i = k; i <= n; ++i) {
        Best[i] = -1;
    }

    return 1;
}

void qsort(int* a, int left, int right) {
    if (left >= right) return;;
    int pivotat = partition(a, left, right);
    qsort(a, left, pivotat - 1);
    qsort(a, pivotat + 1, right);
}

int partition(int *Best, int left, int right) {
    int l = left + 1, r = right;
    while (l <= r) {
        if (COMPARE(Best[left], Best[l]) == 1 && COMPARE(Best[left], Best[r]) == 2) {
            swap(Best, l, r);
            l++;
            r--;
        }
        if (COMPARE(Best[left], Best[l]) == 2) {
            l++;
        }
        if (COMPARE(Best[left], Best[r]) == 1) {
            r--;
        }
    }
    swap(Best, left, r);
    return r;
}

void swap(int *nums, int l, int r) {
    int temp = nums[l];
    nums[l] = nums[r];
    nums[r] = temp;
}
