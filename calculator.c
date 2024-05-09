#include <stdio.h>

int main() {
    char operator;
    double num1, num2, result;

    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf", num1, num2, result);
            printf("\n");
            break;
        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf", num1, num2, result);
            printf("\n");
            break;
        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf", num1, num2, result);
            printf("\n");
            break;
        case '/':
            if (num2 == 0) {
                printf("Error! Division by zero.");
            } else {
                result = num1 / num2;
                printf("%.2lf / %.2lf = %.2lf", num1, num2, result);
                printf("\n");
            }
            break;
        default:
            printf("Error! Invalid operator.");
            printf("\n");
    }

    return 0;
}

