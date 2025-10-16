// student.h
#ifndef STUDENT_H // Include Guard 开始
#define STUDENT_H
#include <stdio.h>

// 结构体定义
struct Student {
    char name[50];
    int id;
    float score;
};

void add_student(struct Student **students, int *count, int *capacity);
void display_students(struct Student *students, int count);
void search_student(struct Student *students, int count);
void delete_student(struct Student **students, int *count);
void save_to_file(struct Student *students, int count);
void load_from_file(struct Student **students, int *count, int *capacity);
int get_integer_input();
void sort_students_by_id(struct Student *students, int count);
void sort_students_by_score(struct Student *students, int count);

#endif // STUDENT_H // Include Guard 结束
