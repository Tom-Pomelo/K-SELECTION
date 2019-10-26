#include <stdio.h>

void select(int i, int k, int* Best);

int bsearch(int id, int left, int right, int* Best);

void insert(int pos, int k, int* Best);

int doalg(int n, int k, int* Best) {
    for (int i = 0; i < k; ++i) Best[i] = -1;
    for (int i = 1; i <= n; ++i) select(i, k, Best);
    return 1;
}

void select(int i, int k, int* Best) {
    if (i <= k || COMPARE(Best[k - 1], i) == 2) {
        Best[k - 1] = i;
        int pos = bsearch(k - 1, 0, k - 1, Best);
        insert(pos, k, Best);
    }
}

int bsearch(int id, int left, int right, int* Best) {
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (Best[mid] == -1 || COMPARE(Best[id], Best[mid]) == 1) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

void insert(int pos, int k, int* Best) {
    int temp = Best[pos];
    Best[pos] = Best[k - 1];
    for (int i = k - 1; i > pos; --i) {
        Best[i] = Best[i - 1];
    }
    Best[pos + 1] = temp;
}