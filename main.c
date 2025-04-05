#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked.h"
#include "kota.h"

int main() {
    CityNode* cityList = NULL;
    int choice;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Tambah Kota\n");
        printf("2. Tampilkan Daftar Kota\n");
        printf("3. Tambah Orang ke Kota\n");
        printf("4. Tampilkan Orang di Kota\n");
        printf("5. Hapus Kota\n");
        printf("6. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &choice);
        getchar(); // untuk menangkap newline

        if (choice == 1) {
            char cityName[MAX_NAME_LENGTH];
            printf("Nama kota: ");
            fgets(cityName, sizeof(cityName), stdin);
            cityName[strcspn(cityName, "\n")] = 0; // hapus newline

            insertCity(&cityList, cityName);
            printf("Kota ditambahkan.\n");

        } else if (choice == 2) {
            printf("\nDaftar Kota:\n");
            displayCities(cityList);

        } else if (choice == 3) {
            char cityName[MAX_NAME_LENGTH];
            char personName[MAX_NAME_LENGTH];
            printf("Nama kota: ");
            fgets(cityName, sizeof(cityName), stdin);
            cityName[strcspn(cityName, "\n")] = 0;

            CityNode* city = findCity(cityList, cityName);
            if (city != NULL) {
                printf("Nama orang: ");
                fgets(personName, sizeof(personName), stdin);
                personName[strcspn(personName, "\n")] = 0;

                insertPerson(&(city->personList), personName);
                printf("Orang ditambahkan ke kota %s.\n", cityName);
            } else {
                printf("Kota tidak ditemukan.\n");
            }

        } else if (choice == 4) {
            char cityName[MAX_NAME_LENGTH];
            printf("Nama kota: ");
            fgets(cityName, sizeof(cityName), stdin);
            cityName[strcspn(cityName, "\n")] = 0;

            CityNode* city = findCity(cityList, cityName);
            if (city != NULL) {
                printf("Daftar orang di kota %s:\n", cityName);
                displayPersons(city->personList);
            } else {
                printf("Kota tidak ditemukan.\n");
            }

        } else if (choice == 5) {
            char cityName[MAX_NAME_LENGTH];
            printf("Nama kota yang ingin dihapus: ");
            fgets(cityName, sizeof(cityName), stdin);
            cityName[strcspn(cityName, "\n")] = 0;

            deleteCity(&cityList, cityName);
            printf("Kota telah dihapus.\n");

        } else if (choice == 6) {
            deleteAllCities(&cityList);
            printf("Program selesai.\n");
        } else {
            printf("Pilihan tidak valid.\n");
        }

    } while (choice != 6);

    return 0;
}
