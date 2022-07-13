#include <stdio.h>

#define LEN 100

int input(int *buffer, int *length);
void output(int *buffer, int length);
void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
int compare(int *a, int len_a, int *b, int len_b);
void delete_extra_zeros(int *buffer, int *len, int max_len);
void shift2start(int *buffer, int len, int max_len);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод:
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод:
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/

int main() {
    int n_1, n_2, n_sum, n_sub, number_1[LEN], number_2[LEN], number_sum[LEN + 1], number_sub[LEN];

    if (input(number_1, &n_1) == 1) {
        printf("n/a\n");
    } else {
        if (input(number_2, &n_2) == 1) {
            printf("n/a\n");
        } else {
            sum(number_1, n_1, number_2, n_2, number_sum, &n_sum);
            delete_extra_zeros(number_sum, &n_sum, LEN + 1);
            shift2start(number_sum, n_sum, LEN + 1);
            output(number_sum, n_sum);
            if (compare(number_1, n_1, number_2, n_2) == 1) {
                printf("n/a\n");
            } else {
                sub(number_1, n_1, number_2, n_2, number_sub, &n_sub);
                delete_extra_zeros(number_sub, &n_sub, LEN);
                shift2start(number_sub, n_sub, LEN);
                output(number_sub, n_sub);
            }
        }
    }
    return 0;
}

int input(int *buffer, int *length) {
    int flag, flag_digit;
    char temp;

    flag = 0;
    flag_digit = 1;
    temp = getchar();
    *length = 0;

    while (((int) temp > 47 && (int) temp < 58) || temp == ' ' || temp == '\t') {
        if ((int) temp > 47 && (int) temp < 58 && flag_digit == 1) {
            flag_digit = 0;
            (*length)++;

            if (*length > 100) {
                flag = 1;
                break;
            }

            buffer[*length - 1] = (int) temp - 48;
         } else if (temp == ' ' || temp == '\t') {
            flag_digit = 1;
        } else {
            break;
        }

        temp = getchar();
    }

    if (temp != '\n' || *length == 0)
        flag = 1;

    return flag;
}

void output(int *buffer, int length) {
    printf("%d", *buffer);

    for (int i = 1; i < length; i++)
        printf(" %d", buffer[i]);

    printf("\n");
}

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int temp, i;

    temp = 0;
    i = 0;

    while (len1 >= 1 + i || len2 >= 1 + i || temp != 0) {
        result[LEN + 1 - 1 - i] = 0;

        if (len1 >= 1 + i) {
            result[LEN + 1 - 1 - i] += buff1[len1 - 1 - i];
        }

        if (len2 >= 1 + i) {
            result[LEN + 1 - 1 - i] += buff2[len2 - 1 - i];
        }

        result[LEN + 1 - 1 - i] += temp;
        temp = result[LEN + 1 - 1 - i] / 10;
        result[LEN + 1 - 1 - i] %= 10;
        i++;
    }

    *result_length = i;
}

int compare(int *a, int len_a, int *b, int len_b) {
    int ans;

    ans = -1;
    if (len_a > len_b) {
        ans = 0;
    } else if (len_a < len_b) {
        ans = 1;
    } else {
        for (int i = 0; i < len_a; i++) {
            if (a[i] > b[i]) {
                ans = 0;
                break;
            } else if (a[i] < b[i]) {
                ans = 1;
                break;
            }
        }
    }

    return ans;
}

void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length) {
    int temp, i;

    temp = 0;
    i = 0;

    while (len1 >= 1 + i || len2 >= 1 + i || temp != 0) {
        result[LEN - 1 - i] = buff1[len1 - 1 - i];

        if (len2 >= 1 + i) {
            result[LEN - 1 - i] -= buff2[len2 - 1 - i];
        }

        result[LEN - 1 - i] += temp;

        if (result[LEN - 1 - i] < 0) {
            result[LEN - 1 - i] += 10;
            temp = -1;
        } else {
            temp = 0;
        }

        i++;
    }

    *result_length = i;
}

void delete_extra_zeros(int *buffer, int *len, int max_len) {
    for (int i = max_len - *len; i < max_len; i++) {
        if (buffer[i] == 0)
            (*len)--;
        else
            break;
    }

    if (*len == 0)
        (*len)++;
}

void shift2start(int *buffer, int len, int max_len) {
    if (max_len > len) {
        for (int i = max_len - len; i < max_len; i++) {
            buffer[i - (max_len - len)] = buffer[i];
            buffer[i] = 0;
        }
    }
}
