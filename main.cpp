// main.cpp - menu for the Sensor Fusion project.
// Each menu option runs exactly one task function.
#include <iostream>
#include <limits>

#include "state.h"
#include "trajectory.h"
#include "sensors.h"
#include "fusion.h"
#include "kalman.h"
#include "analysis.h"
#include "display.h"
#include "experiments.h"
#include "tests.h"

static void printMenu() {
    std::cout << "\n===== Sensor Fusion System =====\n"
              << "1. Generate Trajectory\n"
              << "2. Simulate Sensors\n"
              << "3. Weighted-Average Sensor Fusion\n"
              << "4. Kalman Filter\n"
              << "5. Calculate RMSE\n"
              << "6. Display Results\n"
              << "7. Run Noise and Dropout Experiments\n"
              << "8. Test and Integrate System\n"
              << "9. Exit\n"
              << "Enter your choice: ";
}

int main() {
    SystemState state;
    int choice = 0;

    do {
        printMenu();
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) break;          // input ended
            std::cin.clear();                   // bad input: reset and retry
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Please enter a number from 1 to 9.\n";
            continue;
        }

        switch (choice) {
            case 1: generateTrajectory(state); break;
            case 2: simulateSensors(state);    break;
            case 3: weightedAverage(state);    break;
            case 4: kalmanFilter(state);       break;
            case 5: calculateRMSE(state);      break;
            case 6: displayResults(state);     break;
            case 7: runExperiments(state);     break;
            case 8: runTests(state);           break;
            case 9: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice. Enter 1-9.\n"; break;
        }
    } while (choice != 9);

    return 0;
}
