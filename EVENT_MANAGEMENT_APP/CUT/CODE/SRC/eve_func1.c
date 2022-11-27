#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../include/eve_management_app_header.h"


cust *start,*new,*ptr,*prev,*last;
EM *start1,*new1,*ptr1,*prev1,*last1;
eventoo *start2,*new2,*ptr2,*prev2,*last2;

/***********************************************************************************************************
 *	
 *	*FUNCTION NAME  :    add_cust_details
 *	
 *	*DESCRIPTION 	:    This function is used to add customer details into the customer database by the customer.
 *
 *	*RETURNS 	:    No Returns
 *
 ************************************************************************************************************/
int add_cust_details()
{					      //adding customer details function starts here

	if((new=(cust *)calloc(1,sizeof(cust)))==NULL)
	{
		printf("\nMemory allocation failure\n");
		return EXIT_FAILURE;
	}
	printf(".................................WELCOME TO EVENTOO................................\n");

	printf("------------------------- Registration for Customer-----------------------\n");

	while(1)
	{
		printf("\nEnter Name:");
		scanf("%s",new->Cust_Name);
		if(strlen(new->Cust_Name)==0)
		{
			printf("\nThis field can't be Empty\n");
			continue;
		}

		if(strlen(new->Cust_Name)<5)
		{
			printf("\nMinimum 5 Characters required\n");
			continue;
		}
		if(alpha_valid(new->Cust_Name)==1)
		{
			printf("\nName should have only alphabets\n");
			continue;
		}
		else
				break;
		
	}
         while(1)
	{
		printf("\nEnter Contact Number:");
		scanf("%ld",&new->Phoneno);
		if(validate_phoneno(new->Phoneno))
		{
			printf("\nEnter valid Phone Number\n");
			continue;
		}
		break;
	}
	while(1)
	{ 

		printf("\nEnter Aadhar Number:");
		scanf("%lld",&new->Aadharno);
		if(validate_aadhar(new->Aadharno))
		{
			printf("\nEnter Valid AadharNumber\n");
			continue;
		
		
		
		}
               
		if(start)
		{
			for(ptr=start;(ptr)&&ptr->Aadharno!=new->Aadharno;ptr=ptr->next);
			if((ptr)&&ptr->Aadharno==new->Aadharno)
			{
				printf("\nAadharNumber %lld already exists\n",new->Aadharno);
				continue;
			}
			else
				break;
		}
		else	
			break;
	}
	while(1)
	{
		printf("\nEnter Your Start Date:");
		scanf("%s",new->start_date);
		break;
	}	
	while(1)
	{
		printf("\nEnter No.of Days:");
		scanf("%s",new->ndays);
		if(strlen(new->ndays)==0)
		{
			printf("\nThis field can't be empty\n");
			continue;
		}
		else
			break;
	}
	while(1)
	{
		printf("\nEnter Budget:");
		scanf("%lf",&new->budget);
		break;
	}
	
	while(1)
	{
		printf("\nEnter Password:");
		scanf("%s",new->Password);
		if(validate_password(new->Password))
		       continue;
	        break;
	}
	while(1)
	{
		printf("\nEnter Required Event:");
		printf("\n1.Annual Day\n2.Marriage\n3.Product Launch\n4.Festival\n5.Farewell\n");
		printf("\nEnter choice:");
		scanf("%d",&new->choice);
		if(new->choice>5)
		{
			printf("\nEnter valid Event option\n");
			continue;
		}
		else
		{
			if(new->choice==1)
			{
				strcpy(new->avail_event_opt,"Annual Day");
			}

			if(new->choice==2)
			{
				strcpy(new->avail_event_opt,"Marriage");
			}

			if(new->choice==3)
			{
				strcpy(new->avail_event_opt,"Product Launch");
			}
			if(new->choice==4)
			{
				strcpy(new->avail_event_opt,"Festival");
			}
			if(new->choice==5)
			{
				strcpy(new->avail_event_opt,"Farewell");
			}
		
printf(".................................Registration Succesfull.............\n");
		}
		break;
	}
	if(!start)
	{
		start=new;
		new->next=NULL;
	}
	else if(new->Aadharno < start->Aadharno)
	{
		new->next=start;
		start=new;
	}
	else
	{
		for(ptr=start;(ptr)&&ptr->Aadharno<new->Aadharno;prev=ptr,ptr=ptr->next);
		prev->next=new;
		new->next=ptr;
	
	}
        system("clear");
	system("read a");
	return EXIT_SUCCESS;
}									//adding customer details function ends here


/**********************************************************************************************************
 *
 * 	*FUNCTION NAME : edit_cust_details
 *
 * 	*DESCRIPTION : This function is used to edit customer details into the customer database by the customer
 *
 * 	*RETURNS : No returns
 *
 *********************************************************************************************************/
int edit_cust_details()
{									//editing customer details function details starts here
	if(!start)
	{
		printf("\nEmpty List\n");
		return EXIT_FAILURE;
	}
        long long int Aadharno;
	while(1)
	{
		printf("\nEnter Aadhar Number for editing:");
		scanf("%lld",&Aadharno);
	
		if(validate_aadhar(Aadharno))
		{
			printf("\nEnter valid AadharNumber\n");
		      	continue;
		}
		break;
	
	}
	for(ptr=start;(ptr)&&ptr->Aadharno!=Aadharno;ptr=ptr->next);
	if(!ptr)
	
	{
		printf("\nAadharno %lld not found\n",Aadharno);
		return EXIT_FAILURE;

	
	
	}
	printf("Enter New Phone Number For Editing\n");
	scanf("%ld",&ptr->Phoneno);
	

	printf("Enter new name for editing\n");
	scanf("%s",&ptr->Cust_Name);
	printf("Enter new Start Date for editing\n");
	scanf("%s",&ptr->start_date);
	printf("Enter new No.of Days of Event for editing\n");
	scanf("%s",&ptr->ndays);
	printf("Enter new Budget For editing\n");
	scanf("%lf",&ptr->budget);
	printf("Enter New Password For Editing\n:");
	scanf("%s",&ptr->Password);
	
	printf("Enter avail Event  option:");

	printf("\n1.Annual Day\n2.Marriage\n3.Product Launch\n4.Festival\n5.Farewell\n");
	printf("\nEnter choice:");
	scanf("%d",&ptr->choice);
	
	if(ptr->choice>5)
	{
		printf("\nEnter valid Event option\n");
	         
	}
	else
	{
		if(ptr->choice==1)
		{
			strcpy(ptr->avail_event_opt,"Annual Day");
		}

		if(ptr->choice==2)
		{
			strcpy(ptr->avail_event_opt,"Marriage");
		}

		if(ptr->choice==3)
		{
			strcpy(ptr->avail_event_opt,"Product Launch");
		}
		if(ptr->choice==4)
		{
			strcpy(ptr->avail_event_opt,"Festival");
		}
		if(ptr->choice==5)
		{
			strcpy(ptr->avail_event_opt,"Farewell");
		
		}
	
	}
	return EXIT_SUCCESS;
	
}
	



	


								//editing customer details function ends here

/************************************************************************************************************
 *
 * 	*FUNCTION : view_cust_details
 *
 * 	*DESCRIPTION : This function is used to view all customer details in the customer database
 *
 * 	*RETURNS  :  No returns
 *
 ***********************************************************************************************************/
int view_cust_details()
{								//view customer details function starts here
	if(!start)
	{
		printf("\nNo records found\n");
		return EXIT_FAILURE;
	}
printf("\nAadharNumber       Customer_Name       Start-Date      No.of.Days      Budget      Event Type      Phone Number   \n");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
	      
		printf("\n%3lld %15s %15s %15s %15lf %15s %15ld\n",ptr->Aadharno,ptr->Cust_Name,ptr->start_date,ptr->ndays,ptr->budget,ptr->avail_event_opt,ptr->Phoneno);
	}
	return EXIT_SUCCESS;
}										//view customer details function ends here

/**************************************************************************************************************************
 *
 * 	*FUNCTION NAME : del_cust_details
 *
 * 	*DESCRIPTION : This function is used to delete customer details in the customer database by the customer and admin
 *
 * 	*RETURNS : No returns
 *
 ************************************************************************************************************************/


int del_cust_details()
{				       //deleting customer details function starts here
	if(!start)
	{
		printf("\nNo record found\n");
		return EXIT_FAILURE;
	}
	long long int Aadharno;
	while(1)
	{
		printf("\nEnter the Aadhar Number for deleting:");
		scanf("%lld",&Aadharno);
		if(validate_aadhar(Aadharno))
		{
			printf("\nEnter valid Aadhar Number");
			
		}
		else
			break;

	}
	if(Aadharno==start->Aadharno)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	else
	{
		for(ptr=start;(ptr) && ptr->Aadharno!=Aadharno;prev=ptr,ptr=ptr->next);
		if(!ptr)
		{
			printf("\nAadhar number %lld is not found\n",Aadharno);
			return EXIT_FAILURE;
		}
		prev->next=ptr->next;
		free(ptr);
	}
	return EXIT_SUCCESS;
}					//deleting customer details function ends here

//Event Manager Details
/*************************************************************************************************************************************
 *
 * 	*FUNCTION NAME : add_EM_details
 *
 * 	*DESCRIPTION : This function is used to add the Technician details in the technician database by the technician
 *
 * 	*RETURNS : No returns
 *
 ***********************************************************************************************************************************/
int add_EM_details()
{										//adding eventmanager details function starts here
	if((new1=(EM *)calloc(1,sizeof(EM)))==NULL)
	{
		printf("\nMemory Allocation Failed\n");
		return EXIT_FAILURE;
	}
         printf("........................................Event Manager Registration.........................");
	while(1)
	{
		printf("\nEnter Event Manager Name:");
		scanf("%s",new1->EM_Name);
		if(alpha_valid(new1->EM_Name))
		{
			printf("\nName should contain only characters\n");
			continue;
		}
		if((strlen(new1->EM_Name))==0)
		{
			printf("\nThis field cannot be Null\n");
			continue;
		}
		else if(strlen(new1->EM_Name)<5)
		{
			printf("\nMinimum 5 characters is required\n");
			continue;
		}
		else 
			break;
		break;
	}


	while(1)
	{
		printf("\nEnter Event Specialized:\n");
		printf("\n1.AnnuaL Day\n2.Marriage\n3.Product Launch\n4.Festival\n5.Farewell\n");
		printf("\nEnter choice:");
		scanf("%d",&new1->choice);
		if(new1->choice>5)
		{
			printf("\nEnter valid Event  type\n");
			
		}
		else
		{
			if(new1->choice==1)
			{
				strcpy(new1->event_type,"Annual Day");
			}

			if(new1->choice==2)
			{
				strcpy(new1->event_type,"Marriage");
			}

			if(new1->choice==3)
			{
				strcpy(new1->event_type,"Product Launch");
			}
			if(new1->choice==4)
			{
				strcpy(new1->event_type,"Festival");
			}
			if(new1->choice==5)
			{
				strcpy(new1->event_type,"Farewell");
			}
		
		}
		break;
		
	}
        while(1)
	{
		printf("\nEnter PhoneNumber:");
		scanf("%ld",&new1->contact_number);
		if(validate_phoneno(new1->contact_number))
		{
			printf("\nEnter valid Phone Number\n");
			continue;
		}
		else
			break;

		break;
	}
	while(1)
	{
		printf("\nEnter Years of Experience:");
		scanf("%d",&new1->Years_of_experience);
		if(new1->Years_of_experience==0)
		{
			printf("\nThis field cannot be empty\n");
			continue;
		}
		break;
	
	}
	while(1)
	{
		printf("\nEnter Expenses of Event:");
		scanf("%lf",&new1->cost_of_event);
		if(new1->cost_of_event==0.0)
		{
			printf("\nThis field cannot be empty\n");
			continue;
		}
		break;
	}

	while(1)
	{
		printf("\nEnter Password:");
		scanf("%s",new1->password);
		if(validate_password(new1->password))
		{
			printf("Given Password doesn't meet requirements");
			continue;
		}
		break;
	}
	printf("....................Registration Successfull............\n");
	if(!start1)
	{
		new1->EMCODE=100;
		start1=last1=new1;
		new1->next1=NULL;
	}
	else
	{
		new1->EMCODE=last1->EMCODE+1;
		last1=new1;
		new1->next1=NULL;
	}

        return EXIT_SUCCESS;

}										//adding eventmanager details function ends here

/*************************************************************************************************************************************
 *
 * 	*FUNCTION NAME : edit_EM_details
 *
 * 	*DESCRIPTION : This function is used to edit technician details in the technician database by the technician
 *
 * 	*RETURNS : No returns
 *
 ***********************************************************************************************************************************/
int edit_EM_details()
{                                                                           //editing eventmanager details function starts here

	if(!start1)
	{
		printf("\nNo records found\n");
		return EXIT_FAILURE;
	}
	int EMCODE;
	while(1)
	{
		printf("\nEnter the EMCODE :\n");
		scanf("%d",&EMCODE);
		for(ptr1=start1;(ptr1)&&ptr1->EMCODE!=EMCODE;ptr1=ptr1->next1);
		if(!ptr1)
		{
			printf("\nEMCODE Id %d not found\n",EMCODE);
			return EXIT_FAILURE;
		}
		printf("Enter new name\n");
		scanf("%s",ptr1->EM_Name);
		printf("Enter New Phone Number:");
		scanf("%ld",&ptr1->contact_number);
		printf("Enter Years of Experience To be edited\n");
		scanf("%d",&ptr1->Years_of_experience);
		printf("Expenses To be edited\n");
		scanf("%lf",&ptr1->cost_of_event);
		printf("Enter Edited Password\n");
		scanf("%s",ptr1->password);
		printf("Enter Event Type to be edited:");
		printf("\n1.Annual Day\n2.Marriage\n3.Product Launch\n4.Festival\n5.Farewell\n");
		printf("\nEnter choice:");
		scanf("%d",&ptr1->choice);
		if(ptr1->choice>5)
		{
			printf("\nEnter Event  type\n");
			continue;
		}
		else
		{
			if(ptr1->choice==1)
			{
				strcpy(ptr1->event_type,"Annual Day");
			}

			if(ptr1->choice==2)
			{
				strcpy(ptr1->event_type,"Marriage");
			}

			if(ptr1->choice==3)
			{
				strcpy(ptr1->event_type,"Product Launch");
			}
			if(ptr1->choice==4)
			{
				strcpy(ptr1->event_type,"Festival");
			}
			if(ptr1->choice==5)
			{
				strcpy(ptr1->event_type,"Farewell");
			}
		}
		break;
	}
        

        return EXIT_SUCCESS;
}

/************************************************************************************************************************************
 *
 * 	*FUNCTION NAME : view_EM_details
 *
 * 	*DESCRIPTION : This function is used to view eventmanager details in the eventmanager database
 *
 * 	*RETURNS : No returns
 *
 *************************************************************************************************************************************/
int view_EM_details()
{										//view eventmanager details function starts here
	if(!start1)
	{
		printf("\nNo records found\n");
		return EXIT_FAILURE;
         }
printf("\nEMCODE  Event Manager Name      Event Type     Years_of_Experience    Expenses for the Event  Password   Phone number\n");
	for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
	{
		printf("\n%2d  %10s  %15s  %20d  %15lf  %15s %25ld\n",ptr1->EMCODE,ptr1->EM_Name,ptr1->event_type,ptr1->Years_of_experience,ptr1->cost_of_event,ptr1->password,ptr1->contact_number);
	}
	
        return EXIT_SUCCESS;

}										//view Event Manager details function ends here

/***********************************************************************************************************************************
 *
 * 	*FUNCTION NAME : del_EM_details
 *
 * 	*DESCRIPTION : This function is used to delete Event Manager details in the eventoo database by the Event Manager
 *
 * 	*RETURNS : No returns
 *
 *********************************************************************************************************************************/

int del_EM_details()
{										//deleting Event Manager details function starts here

	if(!start1)
	{
		printf("\nNo record found\n");
		return EXIT_FAILURE;
	}
	int EMCODE;
	while(1)
	{
		printf("\nEnter the EMCODE  for deleting:");
		scanf("%d",&EMCODE);
		if(EMCODE<100)
		{
			printf("\nEnter valid EMCODE");
			continue;
		}
		else
			break;

	}
	if(EMCODE==start1->EMCODE)
	{
		ptr1=start1;
		start1=start1->next1;
		free(ptr1);
	}
	else
	{
		for(ptr1=start1;(ptr1) && ptr1->EMCODE!=EMCODE;prev1=ptr1,ptr1=ptr1->next1);
		if(!ptr1)
		{
			printf("\nEMCODE %d is not found\n",EMCODE);
			return EXIT_FAILURE;
		}
		prev1->next1=ptr1->next1;
		free(ptr1);
	}
	return EXIT_SUCCESS;																	                                                 //deleting Event Manager details function ends here
}

/***********************************************************************************************************************************
 *
 *	*FUNCTION NAME : successfull_event_manaers
 *n
 *	*DESCRIPTION : This function is used to edit the records in the service database by the admin
 *
 *	*RETURNS : No returns
 *
 **********************************************************************************************************************************/

int successfull_event_managers()
{											//editing eventoo database starts here
	

	if((new2=(eventoo *)calloc(1,sizeof(eventoo)))==NULL)
	{
		printf("\nMemory allocation failure\n");
		return EXIT_FAILURE;
	}
	while(1)
	{
		printf("Enter Event Manager's Aadhar  Number:");
		scanf("%lld",&new2->Aadharno);
		if(validate_aadhar(new2->Aadharno))
		{
			printf("\nEnter Valid AadharNumber\n");
			continue;
		}
		if(start2)
		{
			for(ptr2=start2;(ptr2)&&ptr2->Aadharno!=new2->Aadharno;ptr2->next2);
			if((ptr2)&&ptr2->Aadharno==new2->Aadharno)
			{
				printf("\nAadharNumber %lld already exists\n",new2->Aadharno);
				continue;
			}
			else
				break;
		}
		break;
	}
	return EXIT_SUCCESS;



}											//editing event database ends here

/***********************************************************************************************************************************
 *
 * 	*FUNCTION : events_completed_reports
 *
 * 	*DESCRIPTION : This function is used to view the records in the event database
 *
 * 	*RETURNS : No returns
 *
 **********************************************************************************************************************************/
int events_completed_report()
{			

	//viewing eventoo database starts here
        if(!start1)
       {
	       printf("\n NO EVENTS TO SHOW \n");
	       return EXIT_FAILURE;
       }
	printf("                              EVENT COMPLETED REPORTS\n");
		printf("-----------------------------------------------------------------------------------\n");
	printf("   CUSTOMERNAME       EMCODE     EVENT NAME\n");
		printf("-----------------------------------------------------------------------------------\n");
	for(ptr1=start1;(ptr1);ptr1=ptr1->next1);
	{
		if((ptr1->EMCODE)!=0){
			printf("%s  \t%d\t  %s\n",ptr1->EM_Name,ptr1->EMCODE,ptr1->event_type);
		}
	
}
	return EXIT_SUCCESS;


}											//viewing eventoo database ends here

/***********************************************************************************************************************************
 *
 * 	*FUNCTION NAME : events_with_budget_overrun
 *
 * 	*DESCRIPTION : This function is used to delete records in the eventoo database by the admin
 * 	
 * 	*RETURNS : No returns
 *
 *********************************************************************************************************************************/
int events_with_budget_overrun()
{										// records in eventoo database starts here
	
		if(!start1)
		{
			printf("\n NO EVENTS TO SHOW \n");
		}
		return EXIT_FAILURE;
		
		
			printf("--------------------------------------EVENTS WITH BUDGET OVERRUN-----------------------\n");
			printf("CUSTOMER              EVENT WITH BUDGET  OVERRUN\n");
			for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
			{
			      if((ptr1->budget) < (ptr1->actual_expenses))
			      {
                                         printf("\t%s\t    \t%2d\t       \t%3lf\t",ptr1->cust,ptr1->event_type);
			      }

			}
			return EXIT_SUCCESS;


}	
//records in eventoo database ends here
int pending_events_list()

{
	if(!start)
	{
		printf("\n ...................NO PENDING EVENTS.....................\n");
	}
	return EXIT_SUCCESS;
	printf("\n                      EVENTS PENDING LIST\n");
		printf("-----------------------------------------------------------------------------------\n");
	printf("CUSTOMER     EVENT PENDING     \n");
		printf("-----------------------------------------------------------------------------------\n");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		if((strlen(ptr->avail_event_opt))==0)
		{
			printf("\t%s\t\t%s\t\n",ptr->Cust_Name,ptr->avail_event_opt);
		}
	}
	return EXIT_SUCCESS;

}
int valued_customers()
{
/*	
if(!start2)
	{
		printf("\nEmpty list\n");
		return EXIT_FAILURE;
	}
	int val_id;
	char val_cust=0;
	ptr2=start2;
	while(ptr2!=NULL)
	{
		if(val_cust<ptr2->total_cust)
		{
			val_cust=ptr2->total_cust;
		}
		else
		{
			ptr2=ptr2->next2;
		}
	}
	for(ptr2=start2;(ptr2);ptr2=ptr2->next2){
		if(val_cust==ptr2->total_cust){
			val_id=ptr2->event_ID;
			strcpy(val_cust,ptr2->event_type);
		}
	}
		printf("\n                     VALUED CUSTOMERS\n");
		printf("-----------------------------------------------------------------------------------\n");
	printf("The event id  is %d and event name is  %s \n",val_id);
	printf("Total students registered %d\n",val_cust);
	return EXIT_SUCCESS;

*/
}
