#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"

PersonNode* createPersonNode(const char* name) {
    PersonNode* newNode = (PersonNode*)malloc(sizeof(PersonNode));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void insertPerson(PersonNode** head, const char* name) {
    PersonNode* newNode = createPersonNode(name);
    newNode->next = *head;
    *head = newNode;
}

void displayPersons(PersonNode* head) {
    if (head == NULL) {
        printf("No persons to display.\n");
        return;
    }
    int index = 1;
    while (head != NULL) {
        printf("%d. %s\n", index++, head->name);
        head = head->next;
    }
}

int countPersons(PersonNode* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int searchPerson(PersonNode* head, const char* name) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0)
            return 1;
        head = head->next;
    }
    return 0;
}

void deleteAllPersons(PersonNode** head) {
    PersonNode* current = *head;
    while (current != NULL) {
        PersonNode* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
