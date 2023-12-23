#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
 
#define MAX_RECORDS 100 
 
typedef struct { 
    char surname[50]; 
    int id; 
    char faculty[50]; 
    int group; 
} Record; 
 
Record table[MAX_RECORDS]; 
int numRecords = 0; 
 
void inputRecord() { 
    Record newRecord; 
    printf("Введите фамилию: "); 
    scanf("%s", newRecord.surname); 
    printf("Введите номер зачетной книжки: "); 
    scanf("%d", &newRecord.id); 
    printf("Введите факультет: "); 
    scanf("%s", newRecord.faculty); 
    printf("Введите номер группы: "); 
    scanf("%d", &newRecord.group); 
 
    table[numRecords] = newRecord; 
    numRecords++; 
} 
 
void saveTableToFile(const char* filename) { 
    FILE* file = fopen(filename, "w"); 
    for (int i = 0; i < numRecords; i++) { 
        fprintf(file, "%s %d %s %d\n", table[i].surname, table[i].id, table[i].faculty, table[i].group); 
    } 
    fclose(file); 
} 
 
void loadTableFromFile(const char* filename) { 
    FILE* file = fopen(filename, "r"); 
    while (fscanf(file, "%s %d %s %d", table[numRecords].surname, &table[numRecords].id, table[numRecords].faculty, &table[numRecords].group) == 4) { 
        numRecords++; 
    } 
    fclose(file); 
} 

int compareRecordsByGroup(const void* a, const void* b) { 
    return ((Record*)a)->group - ((Record*)b)->group; 
} 
 
void sortTableByGroup() { 
    qsort(table, numRecords, sizeof(Record), compareRecordsByGroup); 
} 

void viewTable() { 
    for (int i = 0; i < numRecords; i++) { 
        printf("%s %d %s %d\n", table[i].surname, table[i].id, table[i].faculty, table[i].group); 
    } 
} 

void deleteRecord(int index) { 
    if (index < numRecords) { 
        for (int i = index; i < numRecords - 1; i++) { 
            table[i] = table[i + 1]; 
        } 
        numRecords--; 
    } else { 
        printf("Индекс записи за пределами диапазона\n"); 
    } 
} 
 
void editRecord(int index) { 
    if (index < numRecords) { 
        printf("Введите новые данные для записи с индексом %d:\n", index); 
        inputRecord(); 
        table[index] = table[numRecords - 1]; 
        numRecords--; 
    } else { 
        printf("Индекс записи за пределами диапазона\n"); 
    } 
} 

void processRecordsByGroup(int numGroup) { 
    for (int i = 0; i < numRecords; i++) { 
        if (table[i].group == numGroup) { 
            printf("Обработка записи: %s %d %s %d\n", table[i].surname, table[i].id, table[i].faculty, table[i].group); 
        } 
    } 
} 


void searchTableByGroup(int numGroup) { 
    int minDiff = 1000; 
    Record nearestRecord; 
    for (int i = 0; i < numRecords; i++) { 
        if (table[i].group == numGroup) { 
            printf("Запись с заданным номером группы: %s %d %s %d\n", table[i].surname, table[i].id, table[i].faculty, table[i].group); 
            return; 
        } else { 
            int diff = abs(table[i].group - numGroup); 
            if (diff < minDiff) { 
                minDiff = diff; 
                nearestRecord = table[i]; 
            } 
        } 
    } 
    printf("Наиболее близкая запись: %s %d %s %d\n", nearestRecord.surname, nearestRecord.id, nearestRecord.faculty, nearestRecord.group); 
} 
 
int main() { 
    //inputRecord(); 
    //inputRecord(); 
    //saveTableToFile("records.txt"); 
    loadTableFromFile("records.txt"); 
    //viewTable(); 
    //deleteRecord(0); 
    //viewTable(); 
    //saveTableToFile("records.txt");
    //editRecord(0);
    //sortTableByGroup(); 
    //saveTableToFile("records.txt");
    //viewTable();
    searchTableByGroup(29);
    //processRecordsByGroup(4);
    //saveTableToFile("records.txt");
    return 0; 
}








