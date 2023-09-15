/*
  =============================================================================
 * Name			:linked list functions.h
 * Author		:Omar Elshamy
 * Description 	:Header File For School Management System
 * Created on	:Aug, 2023
 ==============================================================================
 */
#ifndef LINKED_LIST_FUNCTIONS_H_INCLUDED
#define LINKED_LIST_FUNCTIONS_H_INCLUDED
/*==========================================================================*/
/*Include standard libraries Files*/
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
/*==========================================================================*/
/*Macros*/
#define NULL '\0'
/*==========================================================================*/
/*
 *Make Node as a Struct
 *
*/
typedef struct Date
{
    u8 Day;
    u8 Month;
    u32 Year;

}Date;
typedef struct student
{
    u8 Name [60];
    u32 ID ;
    s8 Address[50];
    s8 Phone_Number [25];
    s32 Exam_res ;
    Date Birthday;
    struct student *next;
}student;
/*==========================================================================*/
/*
 *Functions's Prototype
*/
u16 MAIN_MENU (student * head,student **head_adr);
void NEW_STUDENT(student *head,student **head_adr);
void DELETE_STUDENT(student *head,student **head_adr);
void STUDENT_LIST(student * head);
void STUDENT_EDIT(student *head);
void RANK_STUDENT(student *head);
void STUDENT_SCORE(student *head);
u32 Check_ID(student * head,u32 ID) ;
/*==========================================================================*/
#endif /* LINKED_LIST_FUNCTIONS_H_INCLUDED */
