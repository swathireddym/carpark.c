#ifndef CAR_PARKING_H
#define CAR_PARKING_H

// Structure to represent a car
struct Car {
    int slotNumber;
    int carNumber;
    char ownerName[50];
    struct Car* next;
};

// Function to park a car
struct Car* parkCar(int carNumber, const char* ownerName);

// Function to remove a car
int removeCar(int slotNumber);

// Function to display all parked cars
void displayCars();

#endif /* CAR_PARKING_H */
