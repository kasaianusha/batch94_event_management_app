/**************************************************************************************
*      *FILENAME          :   eve_main.c
*
*      *DESCRIPTION       :   This file define the function that comdnsists subfunction 
*                             to perform various operation
*      
*      *REVISION HISTORY  :
*      
*
*      DATE               NAME              REASON
*
*
****************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "../include/eve_management_app_header.h"

int main()
{
	customer_file_to_list();
	eventmanager_file_to_list();
	eventoo_file_to_list();
	int choice=0;
	while(choice!=4)
	{

		//Displaying Main Menu
		
		system("read a");
	        system("clear");	
		printf("\n1.Customer\n2.Event Manager\n3.Eventoo\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:customer_corner();
			       break;
			case 2:eventmanager_corner();
			       break;
			case 3:admin();
			       break;
			case 4:break;
			default:printf("\nInvalid Choice\n");
				break;
		}
	}
	customer_list_to_file();
	eventmanager_list_to_file();
	eventoo_list_to_file();
	printf("\nThank You!\nVisit us Again!!!");
	return EXIT_SUCCESS;
}

