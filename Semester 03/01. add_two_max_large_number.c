#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add two large numbers represented as character arrays
char* addLargeNumbers(const char* number1, const char* number2) {
    // Find the lengths of the input numbers
    int len1 = strlen(number1);
    int len2 = strlen(number2);

    // Find the maximum length among the two numbers
    int maxLen = (len1 > len2) ? len1 : len2;

    // Allocate memory for the result array with an extra space for carry if needed
    char* result = (char*)malloc((maxLen + 2) * sizeof(char)); // Extra space for carry and null terminator

    // Initialize carry to 0
    int carry = 0;

    // Traverse the numbers from right to left and add digits
    int i = len1 - 1; // Start from the last digit of the first number
    int j = len2 - 1; // Start from the last digit of the second number
    int k = maxLen + 1; // Start from the second last position in result array to leave room for carry

    while (i >= 0 || j >= 0) {
        // Get the digits to add, if one number is shorter, consider its digit as 0
        int digit1 = (i >= 0) ? number1[i] - '0' : 0;
        int digit2 = (j >= 0) ? number2[j] - '0' : 0;

        // Add digits along with carry
        int sum = digit1 + digit2 + carry;

        // Update carry for the next iteration
        carry = sum / 10;

        // Store the result in the result array
        result[k] = (sum % 10) + '0';

        // Move to the next digits in both numbers and result array
        i--;
        j--;
        k--;
    }

    // If there is a final carry, add it to the result
    if (carry) {
        result[k] = carry + '0';
    } else {
        // If no carry, move result pointer to next position
        k++;
    }

    // Null-terminate the result array
    result[maxLen + 1] = '\0';

    return result;
}

int main() {
    const char* number1 = "123456789012345678901234567890";
    const char* number2 = "987654321098765432109876543210";

    // Add the numbers
    char* sum = addLargeNumbers(number1, number2);

    // Output the sum
    printf("Sum: %s\n", sum);

    // Free the dynamically allocated memory
    free(sum);

    return 0;
}
