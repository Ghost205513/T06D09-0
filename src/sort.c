#include <stdio.h>

int input(int *buffer, int length);
void output(int *buffer, int length);
void sort(int *array, int length);
void qs(int *array, int left, int right);

int main() {
    int data[10];

    if (input(data, 10) == 1) {
        printf("n/a\n");
    } else {
        sort(data, 10);
        output(data, 10);
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

void sort(int *array, int length) {
    qs(array, 0, length - 1);
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
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
        qs(array, left, j);

    if (i < right)
        qs(array, i, right);
}
