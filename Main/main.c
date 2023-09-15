/*
  =============================================================================
 * Name			:main.c
 * Author		:Omar Elshamy
 * Description 	:School Management System C graduation project
 * Created on	:5/8/2023
 ==============================================================================
 */
#include "main.h"
/*==========================================================================*/
int main()
{
    u16 ret_main=0;
    student* head='\0' ;
    while(1)
    {
        ret_main =MAIN_MENU (head,&head);
        if(ret_main==0)
        {
            break;
        }
        else
        {
            /*Do Nothing*/
        }
    }
    return 0;
}
/*==========================================================================*/
