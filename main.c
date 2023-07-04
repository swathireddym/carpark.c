#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main() {
    int choice;
    int carNumber;
    char ownerName[50];

    while (1) {
        printf("1. Park a car\n");
        printf("2. Remove a car\n");
        printf("3. Display parked cars\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            printf("Exiting the program.\n");
            break;
        } else if (choice < 1 || choice > 4) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the car number: ");
                scanf("%d", &carNumber);
                printf("Enter the owner's name: ");
                getchar(); // Clear the newline character from the input buffer
                fgets(ownerName, sizeof(ownerName), stdin);
                ownerName[strcspn(ownerName, "\n")] = '\0'; // Remove the newline character
                struct Car* parkedCar = parkCar(carNumber, ownerName);
                if (parkedCar != NULL) {
                    printf("Car number %d parked successfully. Slot number: %d\n", parkedCar->carNumber, parkedCar->slotNumber);
                }
                break;
            case 2:
                printf("Enter the slot number: ");
                scanf("%d", &carNumber); // Reusing carNumber variable to store slot number
                int removeResult = removeCar(carNumber);
                if (removeResult == 1) {
                    printf("Car in slot number %d removed successfully.\n", carNumber);
                } else if (removeResult == 0) {
                    printf("Car park is empty.\n");
                } else {
                    printf("Slot number %d is not occupied.\n", carNumber);
                }
                break;
            case 3:
                displayCars();
                break;

            default:
                break;
        }
    }

    return 0;
}
