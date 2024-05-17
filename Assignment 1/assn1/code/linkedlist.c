#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void make_list(struct ListStudents* list) {
    list->head = NULL;
}

void insert_stu(struct ListStudents* list, const struct Students* student) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strncpy(newNode->data.name, student->name, sizeof(student->name));
    newNode->data.rollNumber = student->rollNumber;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(const struct ListStudents* list) {
    const struct Node* current = list->head;

    // Traverse the list and display each student
    while (current != NULL) {
        printf("Name: %s, Roll Number: %d\n", current->data.name, current->data.rollNumber);
        current = current->next;
    }
}