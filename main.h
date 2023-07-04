#ifndef CAR_PARKING_H
#define CAR_PARKING_H

// Header guard to prevent multiple inclusions of the header

// Structure to represent a car
struct Car {
    int slotNumber;          // Slot number of the car in the parking
    int carNumber;           // Car number
    char ownerName[50];      // Owner's name
    struct Car* next;        // Pointer to the next car in the linked list
};

// Function to park a car
struct Car* parkCar(int carNumber, const char* ownerName);

// Function to remove a car
int removeCar(int slotNumber);

// Function to display all parked cars
void displayCars();

#endif /* CAR_PARKING_H */
