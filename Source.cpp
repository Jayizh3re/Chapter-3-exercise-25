#include <iostream>
#include <cmath>

int main()
{
    double rowLengthFeet;
    double endPostFeet;
    double spacingFeet;

    std::cout << "Enter the length of the row in feet: ";
    if (!(std::cin >> rowLengthFeet)) return 1;

    std::cout << "Enter the amount of space used by an end post assembly (feet): ";
    if (!(std::cin >> endPostFeet)) return 1;

    std::cout << "Enter the amount of space between vines (feet): ";
    if (!(std::cin >> spacingFeet)) return 1;

    if (spacingFeet <= 0.0) {
        std::cout << "Error: spacing between vines must be greater than 0.\n";
        return 1;
    }

    double usableFeet = rowLengthFeet - 2.0 * endPostFeet;
    if (usableFeet <= 0.0) {
        std::cout << "No space available for vines after accounting for end posts.\n";
        std::cout << "Number of grapevines that will fit in the row: 0\n";
        return 0;
    }

    // V = (R - 2E) / S
    int vines = static_cast<int>(std::floor(usableFeet / spacingFeet + 1e-12));
    if (vines < 0) vines = 0;

    std::cout << "Number of grapevines that will fit in the row: " << vines << "\n";
    return 0;
}