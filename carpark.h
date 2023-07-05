#ifndef CAR_PARK_H
#define CAR_PARK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define PARKING_RATE_PER_HOUR 50

struct Car {
    int slotNumber;
    char carNumber[20];
    char ownerName[50];
    time_t timestamp;
    struct Car* next;
};


struct Car* parkCar(const char* carNumber, const char* ownerName);
int removeCar(int slotNumber);
void displayCars();
double calculateParkingTime(time_t parkedTime);
double calculateParkingFee(double parkingTime);
void saveData(const char* filename);
void loadData(const char* filename);

#endif
