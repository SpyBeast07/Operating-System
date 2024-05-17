#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "student.h"

struct Node {
    struct Students data;
    struct Node* next;
};

struct ListStudents {
    struct Node* head;
};

void make_list(struct ListStudents* list);
void insert_stu(struct ListStudents* list, const struct Students* student);
void display(const struct ListStudents* list);

#endif

