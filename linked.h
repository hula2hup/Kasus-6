#ifndef LINKED_H
#define LINKED_H

#define MAX_NAME_LENGTH 50

typedef struct PersonNode {
    char name[MAX_NAME_LENGTH];
    struct PersonNode* next;
} PersonNode;

typedef struct CityNode {
    char name[MAX_NAME_LENGTH];
    PersonNode* personList;
    struct CityNode* next;
} CityNode;

// Function prototypes untuk person
PersonNode* createPersonNode(const char* name);
void insertPerson(PersonNode** head, const char* name);
void displayPersons(PersonNode* head);
int countPersons(PersonNode* head);
int searchPerson(PersonNode* head, const char* name);
void deleteAllPersons(PersonNode** head);

#endif // LINKED_H
