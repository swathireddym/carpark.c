#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carpark.h"

extern struct Car* head; // Declaration of head variable


int removeCar(int slotNumber) {
    if (head == NULL) {
        return 0;
    }

    struct Car* current = head;
    struct Car* previous = NULL;

    while (current != NULL && current->slotNumber != slotNumber) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return -1;
    }

    double parkingTime = calculateParkingTime(current->timestamp);
    double parkingFee = calculateParkingFee(parkingTime);

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);

    printf("Car in slot number %d removed successfully.\n", slotNumber);
    printf("Parking time: %.2f hours\n", parkingTime);
    printf("Parking fee: %.2f rupees\n", parkingFee);

    return 1;
}
