#include <iostream>
using namespace std;

int main() {
    const int numStudents = 40;
    const int numTests = 4;

    // Example scores for 3 students. In a real scenario, initialize all 40 students with their scores.
    int scores[numStudents][numTests] = {
        {85, 78, 90, 88},
        {60, 75, 70, 80},
        {90, 85, 85, 95}
        // Add more rows for the remaining students
    };

    float averages[numStudents];

    for (int i = 0; i < numStudents; i++) {
        int sum = 0;
        int minScore = scores[i][0];

        // Calculate the sum of scores and find the minimum score
        for (int j = 0; j < numTests; j++) {
            sum += scores[i][j];
            if (scores[i][j] < minScore) {
                minScore = scores[i][j];
            }
        }

        // Subtract the minimum score and calculate the average of the best 3 scores
        float best3Average = (sum - minScore) / 3.0;
        averages[i] = best3Average;
    }

    // Output the average of the best 3 scores for each student
    for (int i = 0; i < numStudents; i++) {
        cout << "Student " << i + 1 << " average of best 3 tests: " << averages[i] << endl;
    }

    return 0;
}
