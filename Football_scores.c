#include <stdio.h>

// find combination function
void find_combinations(int score) { 
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score); // Print header

    for (int td2 = 0; td2 <= score / 8; td2++) { // Loop for touchdowns with 2-point conversion
        for (int td1 = 0; td1 <= score / 7; td1++) { // Loop for touchdowns with field goal
            for (int td = 0; td <= score / 6; td++) { // Loop for touchdowns
                for (int fg = 0; fg <= score / 3; fg++) { // Loop for field goals
                    for (int safety = 0; safety <= score / 2; safety++) { // Loop for safeties
                        int total = 8 * td2 + 7 * td1 + 6 * td + 3 * fg + 2 * safety;  // Calculate total score
                        if (total == score) { // Check if total matches the input score
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", // Print valid combination
                                   td2, td1, td, fg, safety);
                        }
                    }
                }
            }
        }
    }

    printf("\n");
}

// main function
int main() {
    int score; // Variable to hold user input score

    while (1) { // Loop that breaks when 1 is entered
        printf("Enter the NFL score (Enter 1 to stop): "); // Prompt user for input
        scanf("%d", &score); // Scans user input

        if (score == 1) { // Check for 1
            printf("Program terminated.\n"); // Print termination message
            break; // breaks the program
        }

        if (score < 2) { // Check for invalid scores
            printf("Score must be at least 2 to be valid.\n\n"); 
            continue;
        }

        find_combinations(score); // Call function to find combinations
    }

    return 0;
}