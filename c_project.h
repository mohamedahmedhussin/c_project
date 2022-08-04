#include"STD_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
u16 counter=1;//used to count the entires
struct SimpleDb {
u8 *Student_Id[1];
u8 *Student_Year[1];
u8 *course_grade[3];
u8 *course_id[3];
struct SimpleDb *ptr;
};
typedef enum { F, T } bool;
bool SDB_ReadEntry(u8 id[],u8 *year[],u8 *subject,u8 *grade,struct SimpleDb *ptr);
/*i added ptr1 to can access the linked list throw it
i changed id and year to arrays so i can pass string to them
i changed id and year to arrays so i can pass string to them
also i will not use pointer to subject and grade because the pointer to strcut can access all the data that i want*/
bool SDB_AddEntry(u8 id[],u8 year[],u8 *subject,u8 *grade,struct SimpleDb *ptr1);//i added ptr1 to can access the linked list throw it
//i changed id and year to arrays so i can pass string to them
//also i will not use pointer to subject and grade because the pointer to strcut can access all the data that i want
// i added double pointer because i need to in a certain operation when i delet the first node i need pointer point on the first node pointer
//when i used double pointers only in this fun made alot of errors to me to i will use double pointer in a certain case in this fun
bool SDB_IsFull(void);
u8 SDB_GetUsedSize(void);
void SDB_DeletEntry(u8 id[],struct SimpleDb **ptr);//i added this double pointer to access the struct and also may i change the pointer that point on the first node if i will delet it
void SDB_GetIdList(u8 *count_,struct SimpleDb *list_);//i changed the second pointer to the pointer to struct to can access the linked list and i donot need the count pointer
bool SDB_IsIdExist(u8 id[],struct SimpleDb *ptr);//i added the second pointer to  struct to can access the linked list
