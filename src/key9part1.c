#include <stdio.h>
#define NMAX 10


int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length, int *mod);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int n, mod, sum, ans_n, data[NMAX], ans_data[NMAX];

    if (input(data, &n) == 1) {
        printf("n/a\n");
    } else {
        sum  = sum_numbers(data, n, &mod);
        if (mod == 1) {
            printf("n/a\n");
        } else {
            printf("%d\n", sum);
            ans_n = find_numbers(data, n, sum, ans_data);
            if (ans_n != 0)
                output(ans_data, ans_n);
            else
                printf("n/a\n");
        }
    }
    return 0;
}

int input(int *buffer, int *length) {
    int flag = 0;

    if (scanf("%d", length) == 1 && *length > 0 && *length < 11) {
        for (int i = 0; i < *length; i++) {
            if (scanf("%d", (buffer + i)) == 0) {
                flag = 1;
                break;
            }
        }
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

int sum_numbers(int *buffer, int length, int *mod) {
    int sum;

    sum = 0;
    *mod = 1;

    for (int i = 0; i < length; i++)
        if (buffer[i] % 2 == 0) {
            sum += buffer[i];
            mod = 0;
        }
    return sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int length_numbers = 0;

    for (int i = 0; i < length; i++) {
        if ((buffer[i] != 0) && (number % buffer[i] == 0)) {
            length_numbers++;
            numbers[length_numbers - 1] = buffer[i];
        }
    }

    return length_numbers;
}
