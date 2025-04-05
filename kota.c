#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kota.h"

CityNode* createCityNode(const char* name) {
    CityNode* newNode = (CityNode*)malloc(sizeof(CityNode));
    strcpy(newNode->name, name);
    newNode->personList = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertCity(CityNode** head, const char* name) {
    CityNode* newNode = createCityNode(name);
    newNode->next = *head;
    *head = newNode;
}

CityNode* findCity(CityNode* head, const char* name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0)
            return head;
        head = head->next;
    }
    return NULL;
}

CityNode* findCityByIndex(CityNode* head, int index) {
    int count = 1;
    while (head != NULL) {
        if (count == index)
            return head;
        head = head->next;
        count++;
    }
    return NULL;
}

void displayCities(CityNode* head) {
    int index = 1;
    while (head != NULL) {
        printf("%d. %s\n", index++, head->name);
        head = head->next;
    }
}

int countCities(CityNode* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void deleteCity(CityNode** head, const char* name) {
    CityNode* current = *head;
    CityNode* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL)
                *head = current->next;
            else
                prev->next = current->next;

            deleteAllPersons(&(current->personList));
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void deleteAllCities(CityNode** head) {
    CityNode* current = *head;
    while (current != NULL) {
        CityNode* next = current->next;
        deleteAllPersons(&(current->personList));
        free(current);
        current = next;
    }
    *head = NULL;
}
