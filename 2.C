#include <stdio.h>

// Функція для знаходження найбільшого спільного дільника
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Функція для знаходження найменшого спільного кратного
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int n;
    printf("Введіть кількість чисел р (2 ≤ р ≤ 20): ");
    scanf("%d", &n);

    if (n < 2 || n > 20) {
        printf("Неправильне значення для кількості чисел. Введіть значення в межах 2 і 20.\n");
        return 1;
    }

    int numbers[20];
    printf("Введіть %d натуральних чисел, розділені пробілом: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int result = numbers[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, numbers[i]);
    }

    printf("Найменше спільне кратне заданих чисел: %d\n", result);

    return 0;
}
