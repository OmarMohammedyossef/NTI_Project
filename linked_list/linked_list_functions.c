/*
===============================================================================
 * Name			:linked list functions.c
 * Author		:Omar Elshamy
 * Description 	:Source File For School Management System
 * Created on	:Aug, 2023
===============================================================================
 */
/*
 *Include Files
 */
#include "linked_list_functions.h"
/*==========================================================================*/
/*
 * Description :
 * This function displays the welcome screen and targeted activates.
 */
u16 MAIN_MENU (student * head,student **head_adr)
{
    u16 choice;
    printf("        Welcome       \n");
    printf("===================================\n");
    printf("Menu:       \n");
    printf("1- Add a new student \n");
    printf("2- Delete a student\n");
    printf("3- View student list \n");
    printf("4- Update information of existing student \n");
    printf("5- Rank of top 3 students \n");
    printf("6- Update score of existing student \n");
    printf("7- Exit \n");
    printf("===================================\n");
    printf("Please chose number of process from 1 to 7:\n");
    scanf("%hu",&choice);
    switch (choice)
    {
        case 1:
                NEW_STUDENT(head,head_adr);
                break;
        case 2:
                DELETE_STUDENT(head,head_adr);
                break;
        case 3:
                STUDENT_LIST(head);
                break;
        case 4:
                STUDENT_EDIT(head);
                break;
        case 5:
                RANK_STUDENT(head);
                break;
        case 6:
                STUDENT_SCORE(head);
                break;
        case 7:
                printf("Thank you\n");
                return 0;
                break;
        default:
                printf("Invalid Number\n\n");
                break;
    }
    return 1;
}
/*==========================================================================*/
/*
 * Description :
 * This function creates a new student account in the end
 * it asks about
 * details of the student such as name, date of birth, ID,
 * address and phone number.
 */
 void NEW_STUDENT(student *head,student **head_adr)
{  /*add student to the end of the linked list*/
    u32 ID;
    u16 flag=0;
    if(head==NULL)
    {
        student *new_student;
        new_student =(student*)malloc(sizeof(student));

        fflush(stdin);
        printf("Please, Enter student's name \n");
        gets(new_student->Name);

        printf("Please, Enter student's ID \n");
        scanf("%u",&new_student->ID);

        fflush(stdin);
        printf("Please, Enter student's Address \n");
        gets(new_student->Address);

        printf("Please, Enter student's Phone_Number \n");
        scanf(" %s",&new_student->Phone_Number);

        printf("Please, Enter student's Exam result \n");
        scanf(" %i",&new_student->Exam_res);

        printf("Please, Enter student's Birthday (dd/mm/yyyy)\n");
        scanf("%u/%u/%u",&new_student->Birthday.Day,&new_student->Birthday.Month,&new_student->Birthday.Year);

        printf("\n");

        new_student->next = *head_adr;
        *head_adr = new_student;
    }
    else
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
        /* now we can add a new variable */
        head->next = (student*)malloc(sizeof(student));
        fflush(stdin);
        printf("Please, Enter student's name \n");
        gets(head->next->Name);

        printf("Please, Enter student's ID \n");
        scanf("%u",&head->next->ID);

        ID=head->next->ID;
        flag= Check_ID(*head_adr, ID) ;

        if(flag==1)
        {
            printf("ID used before \n");
            free(head->next) ;
            head->next=NULL ;
            return ;
        }
        else
        {}
        fflush(stdin);
        printf("Please, Enter student's Address \n");
        gets(head->next->Address);

        printf("Please, Enter student's Phone_Number \n");
        scanf(" %s",&head->next->Phone_Number);

        printf("Please, Enter student's Exam result \n");
        scanf("%i",&head->next->Exam_res);

        printf("Please, Enter student's Birthday (dd/mm/yyyy)\n");
        scanf("%u/%u/%u",&head->next->Birthday.Day,&head->next->Birthday.Month,&head->next->Birthday.Year);

        printf("\n");

        head->next->next = NULL;

    }
}
/*==========================================================================*/
/*
 * Description :
 * This function is for deleting a customer account.
 */
void DELETE_STUDENT(student * head,student **head_adr)
{
    u32 ID ;
    printf("Please, Enter your ID \n");
    scanf("%u",&ID);
    student *temp=NULL;

    /* */
    if(head==NULL)
    {
        printf("The linked list is empty \n");
        return ;
    }
    else if(head->next==NULL)
    {
        *head_adr = head->next;      /* Changed head  */
        free(*head_adr);
        printf("The linked list become empty \n");
        return ;
    }
    /*  */
    if (head != NULL && head->ID == ID)
    {
        *head_adr = head->next;         /* Changed head  */
        free(head);                     /* free old head */
         printf("The information of student deleted \n");
        return;
    }



      /* Search for the ID to be deleted, keep track of the previous node */
    while (head != NULL && head->ID != ID)
    {
        temp = head;
        head = head->next;
    }

    /* If ID was not present in linked list*/
    if (head == NULL)
    {
        printf("ID not found in linked list.\n");
        return;
    }
    else
    {
        /* Unlink the node from linked list*/
        temp->next = head->next;
        free(head); /* Free memory*/
        printf("The information of student deleted \n");
    }
 }
/*==========================================================================*/
/*
 * Description :
 * this function, you can view
 * the students information such as name, date of
 * birth, ID, address and phone number in table
 * form (alphabetically ascending).
 */
void STUDENT_LIST(student * head)
{
    if(head==NULL)
    {
        printf("the linked list is empty\n");
    }
    else
    {
        while (head != NULL)
        {
            printf("\n");
            printf("===================================\n");
            printf("The Name is: %s\n",head->Name);
            printf("ID is: %u\n",head->ID);
            printf("The Address is: %s\n",head->Address);
            printf("The Phone Number is: %s\n",head->Phone_Number);
            printf("The Exam result is: %u\n",head->Exam_res);
            printf("The Birthday is: %u/%u/%u\n",head->Birthday.Day,head->Birthday.Month,head->Birthday.Year);
            printf("===================================\n");
            head = head->next;
        }
    }
}
/*==========================================================================*/
/*
 * Description :
 * this function has been used
 * for updating a particular student account.
 */
void STUDENT_EDIT(student *head)
{
    u32 ID ;
    printf("Please, Enter your ID \n");
    scanf("%u",&ID);
    if(head==NULL)
    {
        printf("the linked list is empty\n");
        return ;
    }
    while(head!=NULL)
    {
        if(head->ID==ID)
        {
            fflush(stdin);
            printf("Please, Enter your name \n");
            gets(head->Name);

            printf("Please, Enter your ID \n");
            scanf("%u",&head->ID);

            fflush(stdin);
            printf("Please, Enter your Address \n");
            gets(head->Address);

            printf("Please, Enter your Phone_Number \n");
            scanf(" %s",&head->Phone_Number);

            printf("Please, Enter your Exam result \n");
            scanf("%i",&head->Exam_res);

            printf("Please, Enter your Birthday (dd/mm/yyyy)\n");
            scanf("%u/%u/%u",&head->Birthday.Day,&head->Birthday.Month,&head->Birthday.Year);
            printf("\n");
            break ;
        }
        head=head->next ;
    }
    printf("\n\n");
}
/*==========================================================================*/
/*
 * Description :
 * Rank of top 3 students
 * this function can sort all students according to computer science score.
 */
void RANK_STUDENT(student *head)
{
    student * temp1=NULL;
    student * temp2=NULL;
    student * temp3=NULL;
    if(head==NULL)
    {
        printf("the linked list is empty\n");
        return ;
    }
    /*Case one student*/
    else if(head->next==NULL)
    {
        printf("The First student is: ");
        puts(head->Name);
        printf("The Exam result is: %d\n",head->Exam_res);
        printf("There are not second or third student, just one student\n\n ");
        return ;
    }
    /*Print the top tow students*/
    else if(head->next->next==NULL)
    {
        while(head->next!=NULL)
        {
            if(head->next->Exam_res > head->Exam_res)
            {
                temp1= head->next;
                temp2= head;
                break;
            }
            else
            {
                temp2= head->next;
                temp1= head;
                break;
            }
            head=head->next ;
        }
        printf("The First student is: ");
        puts(temp1->Name);
        printf("The Exam result is: %d\n",temp1->Exam_res);

        printf("The Second student is: ");
        puts(temp2->Name);
        printf("The Exam result is: %d\n",temp2->Exam_res);

        printf("There are not Third student, just tow ");
    }
    else
    {
        while(head->next->next!=NULL)
        {
            if (head->next->Exam_res < head->Exam_res)                     /* 1st or 2nd    */
            {
                if(head->next->next->Exam_res < head->Exam_res)            /* 1st or 3rd    */
                {
                    temp1=head;                                            /*1st is top     */
                    if(head->next->next->Exam_res < head->next->Exam_res)  /*2nd or 3rd     */
                    {
                        temp2=head->next;                                  /*2nd is between */
                        temp3=head->next->next;                            /* 3rd is last   */
                    }
                    else
                    {
                        temp2=head->next->next;                            /*3rd is between */
                        temp3=head->next;                                  /*2nd is last    */
                    }
                }
                else
                {
                    temp1=head->next->next;                                /*3rd is top     */
                    temp2=head;                                            /*1st is between */
                    temp3=head->next;                                      /* 2nd is last   */
                }
            }
            else
            {
                 if(head->next->next->Exam_res < head->next->Exam_res)     /*2nd or 3rd     */
                {
                    temp1=head->next;                                      /*2nd is top     */
                    if(head->next->next->Exam_res < head->Exam_res)        /*1st or 3rd     */
                    {
                        temp2=head;                                        /*1st is between */
                        temp3=head->next->next;                            /* 3rd is last   */
                    }
                    else
                    {
                        temp2=head->next->next;                            /*3rd is between */
                        temp3=head;                                        /*1st is last    */
                    }
                }
                else
                {
                    temp1=head->next->next;                                /*3rd is top     */
                    temp2=head->next;                                      /*2nd is between */
                    temp3=head;                                            /* 1st is last   */
                }
            }

            head->next=head->next->next ;
        }
        /*Print the top three students*/
         printf("The First student is: ");
         puts(temp1->Name);
         printf("The Exam result is: %d\n",temp1->Exam_res);
         printf("The Second student is: ");
         puts(temp2->Name);
         printf("The Exam result is: %d\n",temp2->Exam_res);
         printf("The Third student is: ");
         puts(temp3->Name);
         printf("The Exam result is: %d\n",temp3->Exam_res);
    }
    printf("\n\n");
}
/*==========================================================================*/
/*
 * Description :
 * this function has been used for updating score of all students.
 */
void STUDENT_SCORE(student *head)
{
    u32 ID;
    printf("Please, Enter your ID \n");
    scanf("%u",&ID);
    if(head==NULL)
    {
        printf("the linked list is empty\n");
        return ;
    }
    while(head!=NULL)
    {
        /*Edit score  */
        if(head->ID==ID)
        {
            printf("Please, Enter your Exam result \n");
            scanf("%i",&head->Exam_res);
            printf("The result updated\n\n");
            return ;
        }
        else
        {
            /* Do Nothing */
        }
        head=head->next ;
    }
     printf("Invalid ID\n\n");

 }
 /*==========================================================================*/
 /*
  * Description :
  * this function has been used for Check ID of new ID.
  */
 u32 Check_ID(student * head,u32 ID)
 {
   student * temp = head;
    while (temp != NULL)
    {
        if (temp->ID == ID)
        {
            return 0;    /* ID  exists */
        }
        temp = temp->next;
    }
    return 1;           /* ID first use */
}
/*==========================================================================*/
/*
 * The End
 */
