#include <stdio.h>
#include <math.h>

int check_character_in_string(char string[], int c, int count);
void capitalize_the_string(char string[]);
int calculate_sum_square_n(int n);
void calculate_sum_1_n(int n, float& sum);
int calculate_sum_odd_intergers_less_than_n(int n, int sum);
bool prime(int n);
void odd_even_divisible8(int* p, int& count_odd, int& count_divisible_by_8);

void main() {
	int select;
	printf("Assignment 5: Funtion\n");
	printf("Student's name: Nguyen Viet Anh\t Student's ID: 20233260\n");
	printf("This program can do 8 tasks below:\n");
	int count = 0;
	do {
		printf("1. How many 'c' characters appear in the string you just entered?\n");
		printf("2. Convert the entered string to uppercase letters\n");
		printf("3. Calculate the sum S = 1^2 + 2^2 + ... + n^2\n");
		printf("4. Calculate the sum of S = 1 + 1/2 + ... + 1/n\n");
		printf("5. Calculate the sum of odd integers less than n\n");
		printf("6. Check if n is prime number or not?\n");
		printf("7. How many even numbers, odd numbers, and numbers divisible by 8 are there in an array?\n");
		printf("8. Enter 4 1-digit natural numbers one by one, print the square root of the number made up of those 4 digits\n");
		printf("Select the task you want by enter number: ");
		scanf_s("%d", &select);
		switch (select) {
		case 1: {
			int c, count = 0;
			char string[100];
			printf("How many 'c' characters appear in the string you just entered?\n");
			printf("Enter a string (less than 100 characters): ");
			fseek(stdin, 0, SEEK_END);
			fgets(string, 100, stdin);
			printf("Enter a character 'c': ");
			c = getchar();
			count = check_character_in_string(string, c, count);
			printf("The number of characters '%c' in the string just entered is: %d\n", c, count);
			break;
		}
		case 2: {
			char string[100];
			printf("Convert the entered string to uppercase letters\n");
			printf("Enter a string (less than 100 characters): ");
			fseek(stdin, 0, SEEK_END);
			fgets(string, 100, stdin);
			capitalize_the_string(string);
			printf("The string entered after capitalization is: %s", string);
			break;
		}
		case 3: {
			int n;
			printf("Calculate the sum S = 1^2 + 2^2 + ... + n^2\n");
			printf("Enter the value of n (n is an integer and n > 1): ");
			scanf_s("%d", &n);
			n = calculate_sum_square_n(n);
			printf("The sum is: %d\n", n);
			break;
		}
		case 4: {
			int n;
			float sum = 0;
			printf("Calculate the sum of S = 1 + 1/2 + ... + 1/n\n");
			printf("Enter the value of n (n is an integer and n > 0): ");
			scanf_s("%d", &n);
			calculate_sum_1_n(n, sum);
			printf("The sum is: %f\n", sum);
			break;
		}
		case 5: {
			int n, sum = 0;
			printf("Calculate the sum of odd integers less than n\n");
			printf("Enter the value of n (n is an integer and n > 1): ");
			scanf_s("%d", &n);
			sum = calculate_sum_odd_intergers_less_than_n(n, sum);
			printf("The sum is: %d\n", sum);
			break;
			}
		case 6: {
			int n;
			printf("Check if n is prime number or not?\n");
			printf("Enter the value of n (n is an integer and n > 1): ");
			scanf_s("%d", &n);
			if (prime(n))
				printf("%d is a prime number\n", n);
			else
				printf("%d is not a prime number\n", n);
			break;
			}
		case 7: {
			int array[20], n, count_odd = 0, count_divisible_by_8 = 0;
			printf("How many even numbers, odd numbers, and numbers divisible by 8 are there in an array?\n");
			printf("Enter non-zero values for the array one by one (n <= 20) (If you want to stop, enter 0):\n");
			for (int i = 0; i < 20; i++) {
				scanf_s("%d", &array[i]);
				if (array[i] == 0) {
					n = i;
					break;
				}
			}
			odd_even_divisible8(array, count_odd, count_divisible_by_8);
			printf("The number of even numbers in the array is: %d\n", n - count_odd);
			printf("The number of odd numbers in the array is: %d\n", count_odd);
			printf("The number of numbers divisible by 8 in the array is: %d\n", count_divisible_by_8);
			break;
		}
		case 8: {
			int n, m = 0;
			printf("Enter 4 1-digit natural numbers one by one, print the square root of the number made up of those 4 digits\n");
			for (int i = 0; i < 4; i++) {
				printf("Enter the %dth number: ", i + 1);
				scanf_s("%d", &n);
				m = m * 10 + n;
			}
			printf("The square root is: %.2f\n", sqrt(float(m)));
			break;
		}
		}
		printf("Enter 1 if you want to use this program again, otherwise enter 0: ");
		scanf_s("%d", &select);
		count++;
	} while (select == 1);
	printf("You've done %d tasks this time\n", count);
	printf("Thank for using this program!\n");
}

int check_character_in_string(char string[], int c, int count) {
	for (int i = 0; string[i] != '\0'; i++) {
		if (c != string[i])
			continue;
		count += 1;
	}
	return count;
}
void capitalize_the_string(char string[]) {
	for (int i = 0; string[i] != '\0'; i++) {
		if ('a' <= string[i] && string[i] <= 'z')
			string[i] -= 32;
	}
}
int calculate_sum_square_n(int n) {
	return (n * (n + 1) * (2 * n + 1)) / 6;
}
void calculate_sum_1_n(int n, float& sum) {
	for (int i = 1; i <= n; i++) {
		sum += 1.0 / i;
	}
}
int calculate_sum_odd_intergers_less_than_n(int n, int sum) {
	for (int i = 1; i < n; i += 2) {
		sum += i;
	}
	return sum;
}
bool prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i < sqrt(n); i++) {
		if ((n % i) == 0) return false;
	}
	return true;
}
void odd_even_divisible8(int* p, int& count_odd, int& count_divisible_by_8) {
	for (int i = 0; *p != 0; i++) {
		if (*p % 8 == 0)
			count_divisible_by_8 += 1;
		if (*p % 2 != 0)
			count_odd += 1;
		p++;
	}
}