// main.c
#include "student.h"

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
