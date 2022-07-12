#include <stdio.h>


int input(int *buffer, int length);
void output(int *buffer, int length);
void copy(int *dst, int *src, int length);
void sort1(int *array, int length);
void sort2(int *array, int length);
void qs(int *array, int left, int right);
void hs(int *array, int n);
void make_heap(int *array, int n, int start);
void swap(int *a, int *b);

int main() {
    int data[10];
    int data_copy[10];

    if (input(data, 10) == 1) {
        printf("n/a\n");
    } else {
        copy(data_copy, data, 10);
        sort1(data, 10);
        output(data, 10);
        sort2(data_copy, 10);
        output(data_copy, 10);
    }
}

int input(int *buffer, int length) {
    int flag = 0;

    for (int i = 0; i < length; i++) {
        if (scanf("%d", (buffer + i)) == 0) {
            flag = 1;
            break;
        }
    }

    return flag;
}

void output(int *buffer, int length) {
    printf("%d", *buffer);

    for (int i = 1; i < length; i++)
        printf(" %d", buffer[i]);

    printf("\n");
}

void copy(int *dst, int *src, int length) {
    for (int i = 0; i < length; i++)
        dst[i] = src[i];
}

void sort1(int *array, int length) {
    qs(array, 0, length - 1);
}

void sort2(int *array, int length) {
    hs(array, length);
}

void qs(int *array, int left, int right) {
    int i, j;
    int x;

    i = left;
    j = right;
    x = array[(left + right) / 2];

    do {
        while (i < right && array[i] < x)
            i++;

        while (j > left && x < array[j])
            j--;

        if (i <= j) {
            swap(array + i, array + j);
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
        qs(array, left, j);

    if (i < right)
        qs(array, i, right);
}

void hs(int *array, int n) {
    for (int i = (n / 2 - 1); i >= 0; i--)
        make_heap(array, n, i);

    for (int i = (n - 1); i >= 0; i--) {
        swap(array, array + i);
        make_heap(array, i, 0);
    }
}

void make_heap(int *array, int n, int start) {
    int largest, left, right;

    largest = start;
    left = 2 * start + 1;
    right = 2 * start + 2;

    if (left < n && array[left] > array[largest])
        largest = left;

    if (right < n && array[right] > array[largest])
        largest = right;

    if (largest != start) {
        swap(array + start, array + largest);
        make_heap(array, n, largest);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
