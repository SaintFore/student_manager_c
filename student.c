// student.c
#include "student.h"
#include <string.h>

// 添加学生的函数
void add_student(struct Student students[], int *count) {
    char name[50];
    int id;
    float score;
    // 提示用户输入...
    printf("请输入学生姓名，学号，成绩: \n");
    // 使用 scanf 读取...
    scanf("%s %d %f", name, &id, &score);
    // 存入数组...
    strcpy(students[*count].name, name);
    students[*count].id = id;
    students[*count].score = score;
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
    scanf("%d", &search_id);

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

void delete_student(struct Student students[], int *count) {
    int index_to_delete = -1;
    int id;
    printf("请输入您想要删除的学生的学号: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (id == students[i].id) {
            index_to_delete = i;
            break;
        }
    }
    if (index_to_delete == -1) {
        printf("没有这个用户");
    } else {
        printf("已经删除id为%d,名字为%s", students[index_to_delete].id,
               students[index_to_delete].name);
        for (int i = index_to_delete; i < *count - 1; i++) {
            students[i] = students[i + 1];
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
void load_from_file(struct Student students[], int *count) {
    FILE *file;
    file = fopen("student.txt", "r");
    if (file == NULL) {
        printf("文件无法打开\n");
        return;
    } else {
        fscanf(file, "%d\n", count);
        for (int i = 0; i < *count; i++) {
            fscanf(file, "%s %d %f\n", students[i].name, &students[i].id,
                   &students[i].score);
        }
        fclose(file);
        printf("数据读取成功");
    }
}

int main() {
    struct Student student_list[10];
    int student_count = 0;
    int choice;

    while (1) {
        printf("\n--- 学生管理系统 ---\n");
        printf("1. 添加学生\n");
        printf("2. 显示所有学生\n");
        printf("3. 按学号查找学生\n");
        printf("4. 按学号删除学生\n");
        printf("5. 存储数据\n");
        printf("6. 读取数据\n");
        printf("0. 退出程序\n");
        printf("----------\n");
        printf("请输入你的选择: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
        case 1:
            // 调用添加函数
            add_student(student_list, &student_count);
            break;
        case 2:
            // 调用显示函数
            display_students(student_list, student_count);
            break;
        case 3:
            // 调用查找函数
            search_student(student_list, student_count);
            break;
        case 4:
            delete_student(student_list, &student_count);
            break;
        case 5:
            save_to_file(student_list, student_count);
            break;
        case 6:
            load_from_file(student_list, &student_count);
            break;
        case 0:
            printf("感谢使用，再见！\n");
            return 0;
        default:
            printf("无效输入，请重新选择。\n");
            break;
        }
    }

    return 0;
}
