#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h" // Including the header file for function declarations and struct definition

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
        scanf("%d", &choice); // Reading the user's choice

        if (choice == 4) {
            printf("Exiting the program.\n");
            break; // Breaking the loop if the user chooses to exit
        } else if (choice < 1 || choice > 4) {
            printf("Invalid choice. Please try again.\n");
            continue; // Continuing to the next iteration if the user enters an invalid choice
        }

        switch (choice) {
            case 1:
                printf("Enter the car number: ");
                scanf("%d", &carNumber); // Reading the car number from the user
                printf("Enter the owner's name: ");
                getchar(); // Clearing the newline character from the input buffer
                fgets(ownerName, sizeof(ownerName), stdin); // Reading the owner's name
                ownerName[strcspn(ownerName, "\n")] = '\0'; // Removing the newline character from the owner's name
                struct Car* parkedCar = parkCar(carNumber, ownerName); // Parking the car by calling the function
                if (parkedCar != NULL) {
                    printf("Car number %d parked successfully. Slot number: %d\n", parkedCar->carNumber, parkedCar->slotNumber); // Printing the details of the parked car
                }
                break;
            case 2:
                printf("Enter the slot number: ");
                scanf("%d", &carNumber); // Reading the slot number from the user
                int removeResult = removeCar(carNumber); // Removing the car from the specified slot by calling the function
                if (removeResult == 1) {
                    printf("Car in slot number %d removed successfully.\n", carNumber); // Printing a success message if the car is removed
                } else if (removeResult == 0) {
                    printf("Car park is empty.\n"); // Printing a message if the car park is empty
                } else {
                    printf("Slot number %d is not occupied.\n", carNumber); // Printing a message if the specified slot is not occupied
                }
                break;
            case 3:
                displayCars(); // Displaying the details of all parked cars by calling the function
                break;

            default:
                break; // Handling any default case (optional)
        }
    }

    return 0;
}
