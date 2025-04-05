#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printMenu() {
    printf("\n--- City-Person Management System (Linked List Only) ---\n");
    printf("1.  Add City\n");
    printf("2.  Add Person to City\n");
    printf("3.  Display Persons in a City\n");
    printf("4.  Display All Cities\n");
    printf("5.  Delete City and its Persons\n");
    printf("6.  Total Number of Cities\n");
    printf("7.  Total Number of Persons in a City\n");
    printf("8.  Search Person in a City\n");
    printf("9.  Exit Program\n");
    printf("Enter your choice: ");
}

void printVisualization(CityNode* cityList) {
    printf("\n--- Visualization of Data Structure ---\n");
    
    if (cityList == NULL) {
        printf("Empty data structure.\n");
        return;
    }
    
    CityNode* currentCity = cityList;
    int cityCount = 1;
    
    while (currentCity != NULL) {
        printf("City %d: %s\n", cityCount++, currentCity->name);
        printf("│\n");
        
        if (currentCity->personList == NULL) {
            printf("└── No persons\n");
        } else {
            PersonNode* currentPerson = currentCity->personList;
            PersonNode* nextPerson;
            
            while (currentPerson != NULL) {
                nextPerson = currentPerson->next;
                
                if (nextPerson == NULL) {
                    printf("└── %s\n", currentPerson->name);
                } else {
                    printf("├── %s\n", currentPerson->name);
                }
                
                currentPerson = nextPerson;
            }
        }
        
        if (currentCity->next != NULL) {
            printf("↓\n");
        }
        currentCity = currentCity->next;
    }
    printf("\n");
}

int main() {
    CityNode* cityList = NULL;  // Head of the city linked list
    int choice, cityIndex;
    char cityName[MAX_NAME_LENGTH];
    char personName[MAX_NAME_LENGTH];
    CityNode* selectedCity;

    while (1) {
        printMenu();
        
        // Input validation
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: // Add City
                printf("Enter city name: ");
                if (fgets(cityName, sizeof(cityName), stdin) != NULL) {
                    cityName[strcspn(cityName, "\n")] = 0; // Remove newline
                    if (strlen(cityName) > 0) {
                        insertCity(&cityList, cityName);
                        printf("City '%s' added successfully!\n", cityName);
                        printVisualization(cityList);
                    } else {
                        printf("City name cannot be empty!\n");
                    }
                }
                break;

            case 2: // Add Person to City
                if (cityList == NULL) {
                    printf("No cities exist. Please add a city first.\n");
                    break;
                }
                
                displayCities(cityList);
                printf("Enter city index: ");
                if (scanf("%d", &cityIndex) != 1) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();
                
                selectedCity = findCityByIndex(cityList, cityIndex);
                if (selectedCity == NULL) {
                    printf("Invalid city index!\n");
                    break;
                }

                printf("Enter person name: ");
                if (fgets(personName, sizeof(personName), stdin) != NULL) {
                    personName[strcspn(personName, "\n")] = 0; // Remove newline
                    if (strlen(personName) > 0) {
                        insertPerson(&(selectedCity->personList), personName);
                        printf("Person '%s' added to '%s'!\n", personName, selectedCity->name);
                        printVisualization(cityList);
                    } else {
                        printf("Person name cannot be empty!\n");
                    }
                }
                break;

            case 3: // Display Persons in a City
                if (cityList == NULL) {
                    printf("No cities exist.\n");
                    break;
                }
                
                displayCities(cityList);
                printf("Enter city index: ");
                if (scanf("%d", &cityIndex) != 1) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();
                
                selectedCity = findCityByIndex(cityList, cityIndex);
                if (selectedCity == NULL) {
                    printf("Invalid city index!\n");
                    break;
                }

                printf("Persons in '%s':\n", selectedCity->name);
                displayPersons(selectedCity->personList);
                break;

            case 4: // Display All Cities
                displayCities(cityList);
                break;

            case 5: // Delete City and its Persons
                if (cityList == NULL) {
                    printf("No cities exist.\n");
                    break;
                }
                
                displayCities(cityList);
                printf("Enter city name to delete: ");
                if (fgets(cityName, sizeof(cityName), stdin) != NULL) {
                    cityName[strcspn(cityName, "\n")] = 0; // Remove newline
                    if (strlen(cityName) > 0) {
                        deleteCity(&cityList, cityName);
                        printf("City '%s' and all its persons deleted!\n", cityName);
                        printVisualization(cityList);
                    } else {
                        printf("City name cannot be empty!\n");
                    }
                }
                break;

            case 6: // Total Number of Cities
                printf("Total number of cities: %d\n", countCities(cityList));
                break;

            case 7: // Total Number of Persons in a City
                if (cityList == NULL) {
                    printf("No cities exist.\n");
                    break;
                }
                
                displayCities(cityList);
                printf("Enter city index: ");
                if (scanf("%d", &cityIndex) != 1) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();
                
                selectedCity = findCityByIndex(cityList, cityIndex);
                if (selectedCity == NULL) {
                    printf("Invalid city index!\n");
                    break;
                }
                
                printf("Total persons in '%s': %d\n", selectedCity->name, countPersons(selectedCity->personList));
                break;

            case 8: // Search Person in a City
                if (cityList == NULL) {
                    printf("No cities exist.\n");
                    break;
                }
                
                displayCities(cityList);
                printf("Enter city index: ");
                if (scanf("%d", &cityIndex) != 1) {
                    printf("Invalid input!\n");
                    clearInputBuffer();
                    break;
                }
                clearInputBuffer();
                
                selectedCity = findCityByIndex(cityList, cityIndex);
                if (selectedCity == NULL) {
                    printf("Invalid city index!\n");
                    break;
                }

                printf("Enter person name to search: ");
                if (fgets(personName, sizeof(personName), stdin) != NULL) {
                    personName[strcspn(personName, "\n")] = 0; // Remove newline
                    
                    if (searchPerson(selectedCity->personList, personName)) {
                        printf("'%s' found in '%s'!\n", personName, selectedCity->name);
                    } else {
                        printf("'%s' not found in '%s'.\n", personName, selectedCity->name);
                    }
                }
                break;

            case 9: // Exit Program
                deleteAllCities(&cityList);
                printf("All resources freed. Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}