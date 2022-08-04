#include"c_project.h"
bool SDB_AddEntry(u8 id[],u8 year[],u8 *subject,u8 *grade,struct SimpleDb *ptr1){

    u8 id_1[3],id_2[3],id_3[3],grade_1[3],grade_2[3],grade_3[3],stud_id[3];

    if(SDB_IsIdExist(id,ptr1)==1){
        printf("\n this id already taken enter anther one \n");
        scanf("%s",id);}
    else{}
    if(counter==10){//to prevent adding anyother entries if there is no place
        SDB_IsFull();return F;}
    else{
        ++counter;//counter to the entires
        printf("\n please enter the subject ids \n");
        scanf("%s",id_1);scanf("%s",id_2);scanf("%s",id_3);
        printf("\n please enter the subjects grades  \n");
        scanf("%s",grade_1);scanf("%s",grade_2);scanf("%s",grade_3);
    if(((atoi(grade_1)>127)||(atoi(grade_1)<0))||((atoi(grade_2)>127)||(atoi(grade_2)<0))||((atoi(grade_3)>127)||(atoi(grade_3)<0))){
    //to get away from overflow
        printf("\n all the entered numbers must be between 0 to 127 \n");
        printf("\n please enter the subjects grades  \n");
        scanf("%s",grade_1);scanf("%s",grade_2);scanf("%s",grade_3);}
    else if(((atoi(id_1)>127)||(atoi(id_1)<0))||((atoi(id_2)>127)||(atoi(id_2)<0))||((atoi(id_3)>127)||(atoi(id_3)<0))){
        printf("\n all the entered numbers will be between 0 to 127 try again \n");
         printf("\n please enter the subject ids \n");
        scanf("%s",id_1);scanf("%s",id_2);scanf("%s",id_3);}
    else if((atoi(id_1)==atoi(id_2))||(atoi(id_1)==atoi(id_3))||(atoi(id_2)==atoi(id_3))){
        printf("\n you entered two subjects with the same code that not allowed reenter the data agian \n");
         printf("\n please enter the subject ids \n");
        scanf("%s",id_1);scanf("%s",id_2);scanf("%s",id_3);}
    else{}
    if((atoi(grade_1)>100||atoi(grade_1)<0)||(atoi(grade_2)>100||atoi(grade_2)<0)||(atoi(grade_3)>100||atoi(grade_3)<0)){
        printf("\n error the subject grades from 0 to 100 please enter them agian \n");
        scanf("%s",grade_1);scanf("%s",grade_2);scanf("%s",grade_3);
        //when compilar enter this condition automatic makes id_3 equal zero so it forced me to sacn it here agian
        printf("\n the third subject id again \n");scanf("%s",id_3);}
    else{}
    struct SimpleDb *ptr=malloc(sizeof(struct SimpleDb));
    ptr->Student_Id[0]=atoi(id);ptr->Student_Year[0]=atoi(year);ptr->course_id[0]=atoi(id_1);ptr->course_id[1]=atoi(id_2);
    ptr->course_id[2]=atoi(id_3);ptr->course_grade[0]=atoi(grade_1);ptr->course_grade[1]=atoi(grade_2);ptr->course_grade[2]=atoi(grade_3);
    ptr->ptr=NULL;
    if(ptr1==NULL){
        struct SimpleDb **ptr2=&ptr1;//i can enter double pointer to the fun but that made alot of problems to me so i get forced to intialize anther one here
        *ptr2=ptr;
        if ((ptr1)->ptr==NULL){
    //if ptr1->ptr=NULL that means the first node has been added
        printf("\n new entry successfully addedss \n");return T;}
       else{
        printf("\n there is an error in entering process \n");return F;}}
    else{
    while((ptr1)->ptr!=NULL){ptr1=(ptr1)->ptr;}
    (ptr1)->ptr=ptr;
    if ((ptr1)->ptr==NULL){
    //if ptr1->ptr=NULL that means there is no node added yet so there is no data stored in the data base
    printf("\n there is an error in entering process \n");return F;}
    else{printf("\n new entry successfully added \n");return T;}}}}


bool SDB_IsFull(void){

    if(counter==10){printf("\n there is no place available in database \n");return T;}
    else {printf("\n there is %d places avialable \n",10-counter);return F;}}


u8 SDB_GetUsedSize(void){

    printf("\n number of entires in the database=");return counter;}

void SDB_DeletEntry(u8 id[],struct SimpleDb **ptr){

    int i=1,j=0;//to know which node iam accessing
    struct SimpleDb *current=*ptr;
    struct SimpleDb *pervious=*ptr;
    if(SDB_IsIdExist(id,current)==0){printf("\n this id doesnot exist \n");}
    else{
    if(*ptr==NULL){printf("\n there is no member in the database \n");}
    else{
        while(pervious->Student_Id[0]!=atoi(id)){
            pervious=pervious->ptr;i++;}
        if(i==1){
            if(pervious->ptr==NULL){
                *ptr=NULL;
                 free(pervious);
                 free(current);
                 pervious=NULL;
                 current=NULL;
                 if(counter>0){counter--;}
                 else{}
                 printf("\n the entry data has been deleted \n");}
            else{
                *ptr=current->ptr;
                free(current);
                pervious=NULL;
                current=NULL;
                if(counter>0){counter--;}
                //i did that because if the counter =0 i will decrease to -1 that will make problems in fun SDB_IsFull and SDB_GetUsedSize
                else{}
                printf("\n the entry data has been deleted \n");}}
        else{
            for(j=0;j<(i-1);j++){
            pervious=current;
            current=current->ptr;}
            pervious->ptr=current->ptr;
            free(current);
            current=NULL;
            if(counter>0){counter--;}
            else{}
            printf("\n the entry data has been deleted \n");}}}}

bool SDB_ReadEntry(u8 id[],u8 *year[],u8 *subject,u8 *grade,struct SimpleDb *ptr){

    int count=1;
    if(ptr==NULL){printf("\n there is no member in the database \n");return F;}
    else{
        for(int i=0;i<counter;i++){
            if(ptr->Student_Id[0]==atoi(id)){
               printf("\n id is exist and his data is shown below \n");
               printf("\n student year   subject1_id   subject2_id   subject3_id   subject1_grade   subject2_grade   subject3_grade \n");
               printf("\n       %d            %d            %d            %d             %d               %d                %d\n",ptr->Student_Year[0],ptr->course_id[0],ptr->course_id[1],ptr->course_id[2],ptr->course_grade[0],ptr->course_grade[1],ptr->course_grade[2]);
               return T;break;}
            else if((ptr->Student_Id[0]!=atoi(id))&&(counter==count)){
                printf("\n id doesnot exist in the database \n");return F;}
            else{}
            ptr=ptr->ptr;
            ++count;}}}

void SDB_GetIdList(u8 *count_,struct SimpleDb *list_){

    if(list_==NULL){printf("\n there is no member in the database \n");}
    else{
        printf("\n number of entires exist in the database=%d \n",counter);
        printf("the list of the student ids in the data base is:");
        for(int i=0;i<counter;i++){
            printf("%d, ",list_->Student_Id[0]);
            list_=list_->ptr;}}}

bool SDB_IsIdExist(u8 id[],struct SimpleDb *ptr){
    if(ptr==NULL){printf("\n there is no member in the database \n");return F;}
    else{
    int count=1;
    while(ptr->Student_Id[0]!=atoi(id)){
        if(count>=counter){break;}
        else{}
        ptr=ptr->ptr;++count;}
    if(ptr->Student_Id[0]==atoi(id)){
        return T;}
    else{
        return F;}}}


