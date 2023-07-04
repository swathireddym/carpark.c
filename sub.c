#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

struct Car* head = NULL; // Global head pointer for the linked list
int currentSlotNumber = 1; // Current slot number for parking

// Function to park a car
struct Car* parkCar(int carNumber, const char* ownerName) {
    // Create a new car node
    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));
    newCar->slotNumber = currentSlotNumber++;
    newCar->carNumber = carNumber;
    strncpy(newCar->ownerName, ownerName, sizeof(newCar->ownerName));
    newCar->next = NULL;

    if (head == NULL) {
        // If the list is empty, set the new car as the head
        head = newCar;
    } else {
        // Traverse to the end of the list and add the new car at the end
        struct Car* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCar;
    }

    return newCar;
}

// Function to remove a car
int removeCar(int slotNumber) {
    if (head == NULL) {
        return 0; // Car park is empty
    }

    struct Car* current = head;
    struct Car* previous = NULL;

    // Traverse the list to find the car with the given slot number
    while (current != NULL && current->slotNumber != slotNumber) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return -1; // Slot number not found
    }

    // Remove the car from the list
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    return 1; // Car removed successfully
}

// Function to display all parked cars
void displayCars() {
    if (head == NULL) {
        printf("Car park is empty.\n");
        return;
    }

    struct Car* current = head;
    printf("Cars parked in the car park:\n");

    // Traverse the list and print details of each car
    while (current != NULL) {
        printf("Slot number: %d, Car number: %d, Owner: %s\n", current->slotNumber, current->carNumber, current->ownerName);
        current = current->next;
    }
}