#include<stdio.h>
#include<string.h>
 
struct employee {
    int id;
    char name[50];
    float salary;
} e1; // khai bao bien e1
 
int main() {
    // luu tru thong tin employee
    e1.id = 17;
    strcpy(e1.name, "Vinh Tran"); // sao chep string thanh mang char
    e1.salary = 1000;
    // hien thi thong tin employee ra man hinh
    printf("employee 1 id : %d\n", e1.id);
    printf("employee 1 name : %s\n", e1.name);
    printf("employee 1 salary : %f\n", e1.salary);
    return 0;
}