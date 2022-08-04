#include"c_project.c"
int main()
{
    u8 add_entry_id[3],add_entry_year[3],delet_entry_id[3],read_entry_id[3],is_exist_id[3];
    u16 selector,flag=0;
    struct SimpleDb *ptr1=malloc(sizeof(struct SimpleDb));//creating the first node of data base
    ptr1->Student_Id[0]=10;ptr1->Student_Year[0]=3;ptr1->course_grade[0]=50;ptr1->course_grade[1]=60;
    ptr1->course_grade[2]=70;ptr1->course_id[0]=62;ptr1->course_id[1]=96;ptr1->course_id[2]=26;ptr1->ptr=NULL;
    printf("1> for checking if database is full or not \n2> to get the number of entires \n");
    printf("3> for enter new entry \n4> for deleting entry from the database \n5> to read entry data by his id\n");
    printf("6> to get the list of ids  \n7> to check if a certain id is exist \n8> to exit the program \n");
    while(1){
        printf("\n enter number from 0 to 8 to get your based on the choices above\n");
        scanf("%d",&selector);
        switch(selector){
        case 1:
            printf("\n%d\n",SDB_IsFull());break;
        case 2:
            printf("%d\n",SDB_GetUsedSize());break;
        case 3:
            printf("\n enter the student id and year \n");
            scanf("%s",add_entry_id);
            scanf("%s",add_entry_year);
            if(((atoi(add_entry_id)>127)||(atoi(add_entry_id)<0))||((atoi(add_entry_year)>127)||(atoi(add_entry_year)<0))){//to get away from overflow
                printf("\n max digit of any number is 3 digits try agian from 0 to 127\n");
                printf("\n enter the student id and student year\n");
                scanf("%s",add_entry_id);
                scanf("%s",add_entry_year);}
            else{}
            printf("%d",SDB_AddEntry(add_entry_id,add_entry_year,ptr1->course_id,ptr1->course_grade,ptr1));
            break;
        case 4:
            printf("\n enter the student id \n");
            scanf("%s",delet_entry_id);
            if((atoi(delet_entry_id)>127)||(atoi(delet_entry_id)<0)){
                printf("\n max digit of any number is 3 digits try agian from 0 to 127\n");
                printf("\n enter the student id \n");
                scanf("%s",delet_entry_id);}
            else{}
            SDB_DeletEntry(delet_entry_id,&ptr1);break;
        case 5:
            printf("\n enter the student id  \n");
            scanf("%s",read_entry_id);
            if(((atoi(read_entry_id)>127)||(atoi(read_entry_id)<0))){//to get away from overflow
                printf("\n max digit of any number is 3 digits try agian from 0 to 127\n");
                printf("\n enter the student id \n");
                scanf("%s",read_entry_id);}
            else{}
            printf("%d",SDB_ReadEntry(read_entry_id,ptr1->Student_Year,ptr1->course_id,ptr1->course_grade,ptr1));break;
        case 6:
            SDB_GetIdList(&counter,ptr1);break;
        case 7:
            printf("\n enter the student id \n");
            scanf("%s",is_exist_id);
            if((atoi(is_exist_id)>127)||(atoi(is_exist_id)<0)){
                printf("\n max digit of any number is 3 digits try agian from 0 to 127\n");
                printf("\n enter the student id \n");
                scanf("%s",is_exist_id);}
            else{}
            printf("%d",SDB_IsIdExist(is_exist_id,ptr1));break;
        case 8:
            flag++;
            break;

        default:
            printf("\n please enter corrent number \n");break;}
        if(flag==1){
            break;}
        else{}}}

