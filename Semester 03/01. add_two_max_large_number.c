#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add two numbers represented as character arrays
char* addLargeNumbers(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;   // If len1 > len2 then len1 otherwise len2
    int result[maxLen + 1]; // To store the result
    int carry = 0; // Initialize carry to 0

    // Traverse both strings in reverse order
    for (int i = 0; i < maxLen; i++) {
        int digit1 = (i < len1) ? (num1[len1 - 1 - i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[len2 - 1 - i] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        result[maxLen - i] = sum % 10;
        carry = sum / 10;
    }

    // Handle the last carry, if any
    result[0] = carry;

    // Convert the result to a character array
    char* sum = (char*) malloc((maxLen + 2) * sizeof(char)); // +1 for the result, +1 for the null terminator
    int j = 0;
    if (result[0] != 0) {
        sum[j] = result[0] + '0';
        j++;
    }
    for (int i = 1; i <= maxLen; i++) {
        sum[j] = result[i] + '0';
        j++;
    }
    sum[j] = '\0'; // Null terminator

    return sum;
}

int main() {
    char number1[] = "101";
    char number2[] = "10";
    char* sum = addLargeNumbers(number1, number2);
    printf("Sum: %s\n", sum);
}
