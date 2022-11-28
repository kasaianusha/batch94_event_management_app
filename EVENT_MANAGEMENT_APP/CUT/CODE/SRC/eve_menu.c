#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/eve_management_app_header.h"

/************************************************************************************************
 *	*FUNCTION NAME	:  customer_corner
 *
 *	*DESCRIPTION	:  This function is used to performs various opertions in the 
 *	                   customer database by receiving choice from the customer.
 *
 *	*RETURNS	:  add_cust_details() function - for adding the details of the customer.
 *			   
 *			   edit_cust_details() function - for editing the details of the 
 *			   existing customer.
 *			   
 *			   view_cust_details() function - for viewing the details of the customer.
 *			   
 *			   del_cust_details() function  - for deleting the details of the customer.
 *
 *************************************************************************************************/

int customer_corner()
{
	int choice;
	while(choice!=4)
	{
		system("read a");
		system("clear");
		printf("\n1.Add Customer Details\n2.Edit Customer Details\n3.View Customer Details\n4.Delete Customer Details\n5.Go Back\n");
		printf("\nEnter your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:add_cust_details();
			       break;
			case 2:edit_cust_details();
			       break;
			case 3:view_cust_details();
			       break;
			case 4:del_cust_details();
			       break;
			case 5:return EXIT_SUCCESS;
			      // break;
			default:printf("\nInvalid Choice\n");
				continue;
		}
	}
	return EXIT_SUCCESS;
}
/*************************************************************************************************
 *      *FUNCTION NAME	: eventmanager_corner
 *
 *	*DESCRIPTION	: This function is used to performs various opertions in the technician 
 *	                  database by receiving choice from the Event Manager.
 *
 *	*RETURNS	:  add_EM_details() function - for adding the details of the technician.
 *			   
 *			   edit_EM_details() function - for editing the details of the existing 
 *			   Event Manager
 *			   
 *			   view_EM_details() function - for viewing the details of the Event Manager
 *			   
 *			   view_cust_details() function  - for viewing  the details of the Customer 
 *
 ***************************************************************************************************/

int eventmanager_corner()
{
	int choice;
	while(choice!=3)
	{
		system("read a");
		system("clear");
		printf("\n1.Add Event Manager Details\n2.Edit Event Manager Details\n3.View Event Manager Details\n4.Go Back\n");
		printf("Enter your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:add_EM_details();
			       break;
			case 2:edit_EM_details();
			       break;
			case 3:view_EM_details();
			       break;
			case 4:return EXIT_SUCCESS;
			       //break;
			default:printf("\nInvalid Choice\n");
				continue;
		}
	}
	return EXIT_SUCCESS;
}


int admin()
{
	while(1)
	{
		char admin_id[50];
		char pswd[20];
		system("read a");
		system("clear");
	 
		printf("Enter admin_id:");
		scanf("%s",admin_id);
		printf("Enter password:");
		scanf("%s",pswd);

		if(strcmp(pswd,"admin@123")==0)
		{
			system("clear");
			int ch1=0;
			while(ch1!=4)
			{
				printf("\n1.Customer Details\n2.Event Manager Details\n3.Eventoo Details\n4.Exit\n");		
				printf("Enter your choice:\n");
				scanf("%d",&ch1);
				switch(ch1)
				{
					case 1: customer_corner();
						break;
					case 2: eventmanager_corner();
						break;
					case 3: eventoo_corner();
						break;
					case 4: break;
					default:printf("Invalid choice\n");
						printf("choice number between 1 to 11\n:");
						continue;
				}
			}
		}
		else
		{
			printf("\nAccess Denied\n");
			continue;
		}
		break;
	}
}

/**********************************************************************************
 *      *FUNCTION NAME	:  eventoo_corner
 *
 *	*DESCRIPTION	:  This function is used to performs various opertions in
 *	                   the service database by receiving choice from the admin.
 *
 *	*RETURNS	:  edit_records() function - for editing the details of the 
 *	                   existing customers and technicians by admin.
 *
 *			   view_records() function - for viewing the details of the 
 *			   customers and technicains by admin.
 *
 *			   del_records() function  - for deleting the details of the  
 *			   customers and technicians by admin.
 *
 *********************************************************************************/

int eventoo_corner()
{
	int choice;
	while(choice!=6)
	{
		system("read a");
		system("clear");
		//int completion_status;
		//printf("Enter Completion Status of Event");
		//scanf("%d",&completion_status);
		//if(completion_status==1)
		//{
			//printf("Event Completed Successfully\n");
		//}
		//else
		//{
			//printf("Sorry ..try again\n");
		//}
		printf("\n1.Events Completed Reports\n2.Events with Budget Overrun\n3.Successful Event Managers\n4.Pending Events List\n5.Valued Customers\n6.Delete Event Manager Records\n7.Go Back\n");
		printf("Enter your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:events_completed_report();
			       break;
			case 2:events_with_budget_overrun();
			       break;
			case 3:successfull_event_managers();
			       break;
			case 4:pending_events_list();
			       break;
			case 5:valued_customers();
			       break;
			case 6:del_EM_details();
			       break;
                 	case 7:return EXIT_SUCCESS;
			       //break;
			default:printf("\nInvalid Choice\n");
				continue;
		}
	}
	return EXIT_SUCCESS;
}
