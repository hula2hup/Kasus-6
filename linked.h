#ifndef LINKED_H
#define LINKED_H

#define MAX_NAME_LENGTH 50

// Person node structure
typedef struct PersonNode {
    char name[MAX_NAME_LENGTH];
    struct PersonNode* next;
} PersonNode;

// City node structure
typedef struct CityNode {
    char name[MAX_NAME_LENGTH];
    PersonNode* personList;  // Points to linked list of persons
    struct CityNode* next;   // Points to next city
} CityNode;

// Function prototypes for person linked list
PersonNode* createPersonNode(const char* name);
void insertPerson(PersonNode** head, const char* name);
void displayPersons(PersonNode* head);
int countPersons(PersonNode* head);
int searchPerson(PersonNode* head, const char* name);
void deleteAllPersons(PersonNode** head);

// Function prototypes for city linked list
CityNode* createCityNode(const char* name);
void insertCity(CityNode** head, const char* name);
CityNode* findCity(CityNode* head, const char* name);
CityNode* findCityByIndex(CityNode* head, int index);
void displayCities(CityNode* head);
int countCities(CityNode* head);
void deleteCity(CityNode** head, const char* name);
void deleteAllCities(CityNode** head);

#endif // LINKED_H