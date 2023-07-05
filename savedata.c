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
