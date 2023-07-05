#include "carpark.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "displaycar.c"
#include "parkcar.c"
#include "removecar.c"
#include "savedata.c"

int main() {
    int choice;
    char carNumber[20];
    char ownerName[50];

    loadData("car_park_data.txt");

    while (1) {
        printf("1. Park a car\n");
        printf("2. Remove a car\n");
        printf("3. Display parked cars\n");
        printf("4. Save data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting the program.\n");
            break;
        } else if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the car number: ");
                scanf("%s", carNumber);

                if (atoi(carNumber) < 0) {
                    printf("Invalid car number. Please try again.\n");
                    break;
                }

                printf("Enter the owner's name: ");
                getchar();
                fgets(ownerName, sizeof(ownerName), stdin);
                ownerName[strcspn(ownerName, "\n")] = '\0';

                int validCarNumber = 1;
                for (int i = 0; i < strlen(carNumber); i++) {
                    if (!isalnum(carNumber[i])) {
                        validCarNumber = 0;
                        break;
                    }
                }

                int validOwnerName = 1;
                for (int i = 0; i < strlen(ownerName); i++) {
                    if (!isalpha(ownerName[i]) && ownerName[i] != ' ') {
                        validOwnerName = 0;
                        break;
                    }
                }

                if (!validCarNumber || !validOwnerName) {
                    printf("Invalid input. Please try again.\n");
                } else {
                    struct Car* parkedCar = parkCar(carNumber, ownerName);
                    printf("Car parked successfully in slot number %d.\n", parkedCar->slotNumber);
                }

                break;
            case 2:
                printf("Enter the slot number: ");
                int slotNumber;
                scanf("%d", &slotNumber);

                int removalStatus = removeCar(slotNumber);
                if (removalStatus == 0) {
                    printf("No cars parked in the car park.\n");
                } else if (removalStatus == -1) {
                    printf("Car not found in the specified slot number.\n");
                }

                break;
            case 3:
                displayCars();
                break;
            case 4:
                saveData("car_park_data.txt");
                break;
            default:
                break;
        }
    }

    return 0;
}
