#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {quantity = 50, max_length = 20};

typedef struct{
    char first_name[max_length];
    char last_name[max_length];
    int birth_year;
    int grade;
} PERSON;

//запись массива структур в файл
void write_in_file(PERSON* students, int length)
{
    char file_name[max_length];
    printf("Enter name of file to write: ");
    scanf("%s", file_name);
    FILE* f = fopen(file_name, "w"); if (f == NULL) {perror("fopen() failed"); exit(1);}

    for (int i = 0; i < length; i++)
        fprintf(f, "%s %s %d %d\n", students[i].last_name, students[i].first_name, students[i].birth_year, students[i].grade);
    fclose(f);
    printf("File was recorded successfully\n");
}

//чтение из файла в массив структур
void read_from_file(PERSON* students, int* count)
{
    char file_name[max_length];
    printf("Enter name of file to read: ");
    scanf("%s", file_name);
    FILE* f = fopen(file_name, "r"); if (f == NULL) {perror("fopen() failed"); exit(1);}
    int k = 0;
    while (fscanf(f, "%s%s%d%d", students[k].last_name, students[k].first_name, &students[k].birth_year, &students[k].grade) == 4)
        k++;
    fclose(f);
    *count = k;
    printf("File has been read successfully\n");
}

//форматный вывод содержимого файла на консоль
void prnt_file_in_consol(){

    char file_name[max_length];
    char buffer[quantity];
    printf("Enter name of file to print: ");
    scanf("%s", file_name);
    FILE *f = fopen(file_name,"r"); if (f == NULL) {perror("fopen() failed"); exit(1);}
    while(fgets(buffer, quantity, f)!= NULL)
        fputs(buffer, stdout);
    fclose(f);
}

void prnt_struct_in_consol(PERSON* structure, int k){
    for(int i = 0; i < k; i++)
        printf("%s %s %d %d\n", structure[i].first_name, structure[i].last_name, structure[i].birth_year, structure[i].grade);

}
//добавить студента в структуру
void add_student(PERSON* students, int* k)
{
    int n = *k;
    if (n < quantity){
        printf("Enter name, surname, year of birth and grade: ");
        if (scanf("%s%s%d%d", students[n].last_name, students[n].first_name, &students[n].birth_year, &students[n].grade) != 4){
            perror("Incorrrect input");
            exit(2);
            }
        n++;
    }
    else printf("Exceeded the limit of students\n");
    *k = n;
    printf("Student added\n");
}
//удалить n-го студента
void delete_student(PERSON* students, int* length)
{
    int n;
    printf("Enter number of student to delete: ");
    scanf("%d", &n);
    for (int i = n; i <= *length; ++i){
        strcpy(students[i].last_name, students[i+1].last_name);
        strcpy(students[i].first_name, students[i+1].first_name);
        students[i].birth_year = students[i+1].birth_year;
        students[i].grade = students[i+1].grade;
    }
    (*length)--;
    printf("Student deleted\n");
}

//запись структуры в бинарный файл
void write_in_binary(PERSON* students, int k)
{
    char file_name[max_length];
    printf("Enter name of file to write to: ");
    scanf("%s", file_name);
    FILE *f=fopen(file_name,"wb"); if (f == NULL) {perror("fopen() failed"); exit(1);}
    fwrite(students, sizeof(PERSON), k, f);
    fclose(f);
    printf("File was recorded successfully\n");
}

//чтение структуры из бинарного файла
void read_from_binary(PERSON* students, int* k)
{
    char file_name[max_length];
    printf("Enter name of file to read: ");
    scanf("%s", file_name);
    FILE*f=fopen(file_name,"rb"); if (f == NULL) {perror("fopen() failed"); exit(1);}
    int count = 0;
    while(fread(&students[count], sizeof(PERSON), 1, f)==1)
        count++;;
    *k = count;
    fclose(f);
    printf("File has been read successfully\n");
}

