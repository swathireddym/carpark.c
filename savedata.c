//The code includes functions for calculating parking time and fee, saving data to a file, and loading data from a file.

The calculateParkingTime function calculates the parking time in hours by taking the parked time as input and comparing it with the current time. It returns the calculated parking time.

The calculateParkingFee function takes the parking time as input and calculates the parking fee by multiplying it with a predefined parking rate per hour.

The saveData function saves the car park data to a specified file. It opens the file in write mode, iterates over the linked list of cars, and writes the slot number, car number, owner name, and timestamp to the file.

The loadData function loads car park data from a specified file. It opens the file in read mode, reads each line, and extracts the slot number, car number, owner name, and timestamp. It then creates a new car node with the extracted data and adds it to the linked list.
The code provides functionality for calculating parking time and fee, saving data to a file, and loading data from a file in the car park management system.//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carpark.h"

extern struct Car* head; // Declaration of head variable

double calculateParkingTime(time_t parkedTime) {
    time_t currentTime = time(NULL);
    double diffInSeconds = difftime(currentTime, parkedTime);
    double diffInHours = diffInSeconds / 3600;
    return diffInHours;
}

double calculateParkingFee(double parkingTime) {
    return parkingTime * PARKING_RATE_PER_HOUR;
}

void saveData(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    struct Car* current = head;
    while (current != NULL) {
        fprintf(file, "%d,%s,%s,%ld\n", current->slotNumber, current->carNumber,
                current->ownerName, (long)current->timestamp);
        current = current->next;
    }

    fclose(file);
    printf("Data saved successfully to %s.\n", filename);
}

void loadData(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        int slotNumber;
        char carNumber[20];
        char ownerName[50];
        time_t timestamp;

        sscanf(line, "%d,%[^,],%[^,],%ld\n", &slotNumber, carNumber, ownerName, &timestamp);

        struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));
        newCar->slotNumber = slotNumber;
        strncpy(newCar->carNumber, carNumber, sizeof(newCar->carNumber));
        strncpy(newCar->ownerName, ownerName, sizeof(newCar->ownerName));
        newCar->timestamp = timestamp;
        newCar->next = NULL;

        if (head == NULL) {
            head = newCar;
        } else {
            struct Car* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newCar;
        }
    }

    fclose(file);
    printf("Data loaded successfully from %s.\n", filename);
}
