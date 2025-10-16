// student.c
#include "student.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// 添加学生的函数
void add_student(struct Student **students, int *count, int *capacity) {
    if (*count == *capacity) {
        int new_capacity = (*capacity == 0) ? 1 : *capacity * 2;
        struct Student *temp =
            realloc(*students, new_capacity * sizeof(struct Student));
        if (temp == NULL) {
            return;
        } else {
            *students = temp;
            *capacity = new_capacity;
        }
    }
    char name[50];
    int id;
    float score;
    // 提示用户输入...
    printf("请输入学生姓名，学号，成绩: \n");
    // 使用 scanf 读取...
    scanf("%s %d %f", name, &id, &score);
    // 存入数组...
    strcpy((*students)[*count].name, name);
    (*students)[*count].id = id;
    (*students)[*count].score = score;
    // 别忘了增加 *count 的值！
    *count += 1;
}

// 显示所有学生的函数
void display_students(struct Student students[], int count) {
    // 打印一个标题...
    printf("学生信息表\n");
    // 使用 for 循环遍历数组...
    // 打印每个学生的信息...
    for (int i = 0; i < count; i++) {
        struct Student student = students[i];
        printf("学生: %-10sid: %-15d成绩: %-5.2f\n", student.name, student.id,
               student.score);
    }

    for (int i = 0; i < 10; i++) {
        printf("-");
    }
    printf("\n");
}

// 查找学生的函数
void search_student(struct Student students[], int count) {
    int search_id;
    printf("请输入要查找的学号: ");
    /* scanf("%d", &search_id); */
    search_id = get_integer_input();

    // 在这里写一个 for 循环来查找...
    for (int i = 0; i < count; i++) {
        // 如果找到了，打印信息并 return
        if (search_id == students[i].id) {
            struct Student student = students[i];
            printf("学生: %-10sid: %-15d成绩: %-5.2f\n", student.name,
                   student.id, student.score);
            return;
        }
    }
    // 如果循环结束还没找到，打印 "未找到"
    printf("没有这个学号\n");
}

void delete_student(struct Student **students, int *count) {
    int index_to_delete = -1;
    int id;
    printf("请输入您想要删除的学生的学号: ");
    /* scanf("%d", &id); */
    id = get_integer_input();

    for (int i = 0; i < *count; i++) {
        if (id == (*students)[i].id) {
            index_to_delete = i;
            break;
        }
    }
    if (index_to_delete == -1) {
        printf("没有这个用户");
    } else {
        printf("已经删除id为%d,名字为%s", (*students)[index_to_delete].id,
               (*students)[index_to_delete].name);
        for (int i = index_to_delete; i < *count - 1; i++) {
            (*students)[i] = (*students)[i + 1];
        }
        (*count)--;
    }
}
void save_to_file(struct Student students[], int count) {
    FILE *file;
    file = fopen("student.txt", "w");
    if (file == NULL) {
        printf("文件无法打开! \n");
        return;
    } else {
        fprintf(file, "%d\n", count);
        for (int i = 0; i < count; i++) {
            fprintf(file, "%s %d %f\n", students[i].name, students[i].id,
                    students[i].score);
        }
        fclose(file);
        printf("存储成功");
    }
}
void load_from_file(struct Student **students, int *count, int *capacity) {
    FILE *file;
    file = fopen("student.txt", "r");
    if (file == NULL) {
        printf("文件无法打开\n");
        return;
    } else {
        fscanf(file, "%d", count);
        *capacity = *count;
        if (*students != NULL) {
            free(*students);
        }
        struct Student *temp = malloc(*capacity * sizeof(struct Student));
        if (temp == NULL) {
            fclose(file);
            return;
        } else {
            *students = temp;
        }
        for (int i = 0; i < *count; i++) {
            fscanf(file, "%s %d %f", (*students)[i].name, &(*students)[i].id,
                   &(*students)[i].score);
        }
        fclose(file);
        printf("数据读取成功");
    }
}

int get_integer_input() {
    char buffer[100];
    char *endptr;
    long value;
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("输入流错误，程序退出! \n");
            exit(1);
        }
        value = strtol(buffer, &endptr, 10);
        // 开头就是非数字
        if (endptr == buffer) {
            printf("无效输入，请重新输入! \n");
            continue;
        }
        // 为指针去除数字后面的空白字符
        while (isspace((unsigned char)*endptr)) {
            endptr++;
        }
        // 如果数字后面还是非数字，还是非法的
        if (*endptr != '\0') {
            printf("无效输入，请重新输入! \n");
            continue;
        }
        return (int)value;
    }
}

void sort_students_by_id(struct Student *students, int count) {
    if (count < 2) {
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].id > students[j + 1].id) {
                struct Student tempId = students[i];
                students[j] = students[j + 1];
                students[j + 1] = tempId;
            }
        }
    }
}
