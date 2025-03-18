#include "h.h"
#define EXIT cs = 10; break;

int main(void)
{

    PERSON* students = (PERSON*)malloc(sizeof(PERSON)*quantity);

    int cs = 1, k=0;
    do{
    printf("\nChoose:\n 1-print file in consol file\n 2-read the file\n 3-write in file\n\
 4-add new student\n 5-delete student\n 6-read file in binary\n\
 7-write in binary file\n 8-print struct in consol\n 0-exit\n");
    scanf("%d",&cs);
    switch(cs)
        {
            case 1: prnt_file_in_consol(); EXIT
            case 2: read_from_file(students, &k); EXIT
            case 3: write_in_file(students, k); EXIT
            case 4: add_student(students, &k); EXIT
            case 5: delete_student(students, &k); EXIT
            case 6: read_from_binary(students, &k); EXIT
            case 7: write_in_binary(students, k); EXIT
            case 8: prnt_struct_in_consol(students, k); EXIT
            case 0: cs = 0; return 0;
            default: printf("Incorrect input\n"); return 666;
        }
    }while(cs);

    free(students);

    return 0;
}
