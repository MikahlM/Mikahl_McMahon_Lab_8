#include <stdio.h>

// Forward declarations before the main so the compiler knows about them
float convert(float temp, char from, char to); 
void categorize(float celsius);

int main() { // Main function
    float temp; // Temperature value
    char from, to; // Temperature scales
    
    // prints what the users sees and scans them
    printf("Enter the temperature value: ");
    scanf("%f", &temp);

    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &from);

    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &to);
    // Convert temperature by calling convert function
    float converted = convert(temp, from, to);
    if (converted == -1) { // Check for invalid conversion
        printf("Invalid conversion.\n"); // if invalid prints this
        return 1;
    }

    printf("Converted temperature: %.2f %c\n", converted, to); // Output converted temperature

    // converts the temp to celsius so it can be categorized
    float celsius = convert(converted, to, 'C');
    categorize(celsius); // Categorize temperature by calling categorize function

    return 0;
}

// conversion function
float convert(float temp, char from, char to) {
    if (from == to) return temp; // if the to and from are the same return temp
    // the rest are the conversion formulas for each combination
    if (from == 'C' && to == 'F') return temp * 9.0 / 5.0 + 32;
    if (from == 'F' && to == 'C') return (temp - 32) * 5.0 / 9.0;
    if (from == 'C' && to == 'K') return temp + 273.15;
    if (from == 'K' && to == 'C') return temp - 273.15;
    if (from == 'F' && to == 'K') return (temp - 32) * 5.0 / 9.0 + 273.15;
    if (from == 'K' && to == 'F') return (temp - 273.15) * 9.0 / 5.0 + 32;
    return -1; // if there is no valid conversion return -1
}

// categorization function
// the temperature is converted into celsius before being passed here for convenience
void categorize(float celsius) {
    printf("Temperature category: "); // prints header
    // checks the temp and sees where it fits in the ranges
    if (celsius < 0) { 
        printf("Freezing\nWeather advisory: Wear a jacket!\n");
    } else if (celsius < 10) {
        printf("Cold\nWeather advisory: Bundle up!\n");
    } else if (celsius < 25) {
        printf("Comfortable\nWeather advisory: Enjoy the day!\n");
    } else if (celsius < 35) {
        printf("Hot\nWeather advisory: Drink lots of water!\n");
    } else {
        printf("Extreme Heat\nWeather advisory: Stay indoors!\n");
    }
}