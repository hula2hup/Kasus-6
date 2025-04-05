#ifndef KOTA_H
#define KOTA_H

#include "linked.h" // Untuk akses PersonNode

// Function prototypes untuk city
CityNode* createCityNode(const char* name);
void insertCity(CityNode** head, const char* name);
CityNode* findCity(CityNode* head, const char* name);
CityNode* findCityByIndex(CityNode* head, int index);
void displayCities(CityNode* head);
int countCities(CityNode* head);
void deleteCity(CityNode** head, const char* name);
void deleteAllCities(CityNode** head);

#endif // KOTA_H
