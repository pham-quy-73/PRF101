#include <stdio.h>

// tinh tong cac so nguyen
int sumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    int userInput;

    do {
        // nguoi dung nhap so
        printf("Nhap mot so nguyen khong am: ");
        scanf("%d", &userInput);

        if (userInput >= 0) {
            // tinh va in ra tong cac chu so nguyen
            int digitSum = sumOfDigits(userInput);
            printf("Tong cac chu so cua %d la: %d\n", userInput, digitSum);
        } else {
            // khi nhap vao so am chong trinh ket thuc
            printf("Chuong trinh ket thuc.\n");
        }

    } while (userInput >= 0);

    return 0;
}

