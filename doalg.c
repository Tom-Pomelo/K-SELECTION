#include <stdio.h>

#define true 1

void select(int i, int k, int* Best);

int bsearch(int id, int left, int right, int* Best);

void shift(int pos, int k, int* Best);

int doalg(int n, int k, int* Best) {
    for (int i = 0; i < k; ++i) Best[i] = -1;
    for (int i = 1; i <= n; ++i) select(i, k, Best);
    return 1;
}

void select(int i, int k, int* Best) {
    if (i <= k || COMPARE(Best[k - 1], i) == 2) {
        Best[k - 1] = i;
        int pos = bsearch(k - 1, 0, k - 1, Best);
        shift(pos, k, Best);
    }
}

int bsearch(int id, int left, int right, int* Best) {
    if (left == right) return left;
    int mid = left + (right - left) / 2;
    if (Best[mid] == -1 || COMPARE(Best[id], Best[mid]) == 1) {
        return bsearch(id, left, mid, Best);
    } else {
        return bsearch(id, mid + 1, right, Best);
    }
}

void shift(int pos, int k, int* Best) {
    int temp = Best[k - 1];
    for (int i = k - 1; i > pos; --i) {
        Best[i] = Best[i - 1];
    }
    Best[pos] = temp;
}