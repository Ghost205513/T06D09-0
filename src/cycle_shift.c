#include <stdio.h>
#define NMAX 10


int input(int *buffer, int *length, int *c);
void output(int *buffer, int length);
void shift(int *array, int length, int c);

int main() {
    int n, c, data[NMAX];

    if (input(data, &n, &c) == 1) {
        printf("n/a\n");
    } else {
        shift(data, n, c);
        output(data, n);
    }
    return 0;
}

int input(int *buffer, int *length, int *c) {
    int flag = 0;

    if (scanf("%d", length) == 1 && *length > 0 && *length < 11) {
        for (int i = 0; i < *length; i++) {
            if (scanf("%d", (buffer + i)) == 0) {
                flag = 1;
                break;
            }
        }

        if (scanf("%d", c) == 0)
            flag = 1;
    } else {
        flag = 1;
    }

    return flag;
}

void output(int *buffer, int length) {
    printf("%d", *buffer);

    for (int i = 1; i < length; i++)
        printf(" %d", buffer[i]);

    printf("\n");
}

void shift(int *array, int length, int c) {
    int buffer;

    if (c > 0) {
        for (int i = 0; i < (c % length); i++) {
            buffer = array[0];

            for (int j = 1; j < length; j++)
                array[j - 1] = array[j];

            array[length - 1] = buffer;
        }
    } else {
        for (int i = 0; i < -1 * (c % length); i++) {
            buffer = array[length - 1];

            for (int j = length - 1; j > 0; j--)
                array[j] = array[j - 1];

            array[0] = buffer;
        }
    }
}
