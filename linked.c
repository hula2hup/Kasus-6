#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"

// --- Person node functions ---

// Create a new person node
PersonNode* createPersonNode(const char* name) {
    PersonNode* newNode = (PersonNode*)malloc(sizeof(PersonNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    strncpy(newNode->name, name, MAX_NAME_LENGTH - 1);
    newNode->name[MAX_NAME_LENGTH - 1] = '\0';  // Ensure null-termination
    newNode->next = NULL;
    
    return newNode;
}

// Insert person at the beginning of the list
void insertPerson(PersonNode** head, const char* name) {
    PersonNode* newNode = createPersonNode(name);
    if (newNode == NULL) return;
    
    newNode->next = *head;
    *head = newNode;
}

// Display all persons in the list
void displayPersons(PersonNode* head) {
    int count = 1;
    PersonNode* current = head;
    
    if (current == NULL) {
        printf("No persons in this city.\n");
        return;
    }
    
    while (current != NULL) {
        printf("  %d. %s\n", count++, current->name);
        current = current->next;
    }
}

// Count persons in the list
int countPersons(PersonNode* head) {
    int count = 0;
    PersonNode* current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

// Search for a person in the list
int searchPerson(PersonNode* head, const char* name) {
    PersonNode* current = head;
    
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1;  // Found
        }
        current = current->next;
    }
    
    return 0;  // Not found
}

// Delete all persons in the list
void deleteAllPersons(PersonNode** head) {
    PersonNode* current = *head;
    PersonNode* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
}

// --- City node functions ---

// Create a new city node
CityNode* createCityNode(const char* name) {
    CityNode* newNode = (CityNode*)malloc(sizeof(CityNode));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    strncpy(newNode->name, name, MAX_NAME_LENGTH - 1);
    newNode->name[MAX_NAME_LENGTH - 1] = '\0';  // Ensure null-termination
    newNode->personList = NULL;
    newNode->next = NULL;
    
    return newNode;
}

// Insert city at the end of the list
void insertCity(CityNode** head, const char* name) {
    // Check if city already exists
    if (findCity(*head, name) != NULL) {
        printf("City '%s' already exists!\n", name);
        return;
    }
    
    CityNode* newNode = createCityNode(name);
    if (newNode == NULL) return;
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    CityNode* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Find a city by name
CityNode* findCity(CityNode* head, const char* name) {
    CityNode* current = head;
    
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    
    return NULL;
}

// Find a city by index (1-based)
CityNode* findCityByIndex(CityNode* head, int index) {
    if (index < 1) return NULL;
    
    CityNode* current = head;
    int count = 1;
    
    while (current != NULL && count < index) {
        current = current->next;
        count++;
    }
    
    return current;
}

// Display all cities
void displayCities(CityNode* head) {
    int count = 1;
    CityNode* current = head;
    
    if (current == NULL) {
        printf("No cities exist.\n");
        return;
    }
    
    printf("Cities:\n");
    while (current != NULL) {
        printf("%d. %s\n", count++, current->name);
        current = current->next;
    }
}

// Count cities in the list
int countCities(CityNode* head) {
    int count = 0;
    CityNode* current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

// Delete a city by name
void deleteCity(CityNode** head, const char* name) {
    if (*head == NULL) return;
    
    CityNode* current = *head;
    CityNode* prev = NULL;
    
    // Check if the first city is the one to delete
    if (strcmp(current->name, name) == 0) {
        *head = current->next;
        deleteAllPersons(&(current->personList));
        free(current);
        return;
    }
    
    // Search for the city
    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }
    
    // If city not found
    if (current == NULL) {
        printf("City '%s' not found!\n", name);
        return;
    }
    
    // Delete the city
    prev->next = current->next;
    deleteAllPersons(&(current->personList));
    free(current);
}

// Delete all cities
void deleteAllCities(CityNode** head) {
    CityNode* current = *head;
    CityNode* next;
    
    while (current != NULL) {
        next = current->next;
        deleteAllPersons(&(current->personList));
        free(current);
        current = next;
    }
    
    *head = NULL;
}