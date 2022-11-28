#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "../include/eve_management_app_header.h"

extern cust *start,*new,*ptr,*prev,*last;
extern EM *start1,*new1,*ptr1,*prev1,*last1;
extern eventoo *start2,*new2,*ptr2,*prev2,*last2;



int validate_aadhar(long long int num)
{

                        if(num < 100000000000|| num >999999999999)                         
			{
                                printf("\nInvalid Length.Length should only be 12 digits.\n");
                                return 1;
                        }
		        return 0;

}

int validate_phoneno(long int num)
{

                        if(num < 1000000000|| num >9999999999) 
			{
                                printf("\nInvalid Length.Length should only be 10 digits.\n");
                                return 1;
                        }

                        return 0;
}

int alpha_valid(char *s)
{
	for(char *p=s;(*p);p++)
	{
		if(!isalpha(*p))
			return 1;
	}
	return 0;
}
int validate_password(char *str)
{
	char *ptr = str;

	int c_count = 0 , s_count = 0 , i_count = 0;
	while(*ptr !='\0')
	{
		if(*ptr >= 'A' && *ptr <= 'Z')
		{
			c_count = 1;
		}
		else if(*ptr >= 'a' && *ptr <= 'z')
		{
			s_count = 1;
		}
		else if(*ptr >= 48 && *ptr <= 57 )
		{
			i_count = 1;
		}
		else
		{
			return 0;
		}

		ptr++;
	}

	if(c_count &&s_count &&i_count)
	return 1;
	else
	return 0;
}


/*********************************************************
 *
 * 	*FUNCTION NAME : customer_file_to_list
 *
 * 	*DESCRIPTION   : This function is used here to transfer the data from the customer file to the list.
 *
 * 	*RETURNS       : No Returns
 *
 *********************************************************/


int customer_file_to_list()		//customer file to list function starts here...
{
	FILE *pc;
	cust_temp c1;
	if((pc=fopen("../data/customer","rb"))==NULL)
	{
		//printf("\n File is not found\n");
		return EXIT_FAILURE;
	}
	fread(&c1,sizeof(c1),1,pc);
	while(!feof(pc))

	{
		
		if((new=(cust *)calloc(1,sizeof(cust)))==NULL)
		{
			printf("\n Memory Allocation Failed \n");
			return EXIT_FAILURE;
		}
		new->Aadharno=c1.Aadharno;
		strcpy(new->Cust_Name,c1.Cust_Name);
		strcpy(new->ndays,c1.ndays);
		new->Phoneno=c1.Phoneno;
		new->budget=c1.budget;
		strcpy(new->avail_event_opt,c1.avail_event_opt);
		strcpy(new->Password,c1.Password);
		if(!start)
		{
			start=last=new;
			new->next=NULL;
		}
		else
		{
			last->next=new;
			last=new;
			new->next=NULL;
		}
		fread(&c1,sizeof(c1),1,pc);
	}
	fclose(pc);
	//system("read a");
	//system("clear");
	return EXIT_SUCCESS;
}


/*********************************************************
 *
 * 	*FUNCTION NAME : customer_list_to_file
 *
 * 	*DESCRIPTION   : This function is used here to transfer the data from the customer list to the file.
 *
 * 	*RETURNS       : No Returns
 *
 *********************************************************/


int customer_list_to_file() 		//customer list to file function starts here...
{
	cust_temp c2;
	if(!start)
	{

		//printf("\n The list is Empty.\n");
		return EXIT_FAILURE;
	}
	FILE *pc1;
	if((pc1=fopen("../data/customer","wb"))==NULL)
	{
		printf("\nFile is Not Found\n");
		return EXIT_FAILURE;
	}
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		c2.Aadharno=ptr->Aadharno;
		strcpy(c2.Cust_Name,ptr->Cust_Name);
		strcpy(c2.ndays,ptr->ndays);
		c2.budget=ptr->budget;
	        c2.Phoneno=ptr->Phoneno;
		strcpy(c2.avail_event_opt,ptr->avail_event_opt);
		strcpy(c2.Password,ptr->Password);
		fwrite(&c2,sizeof(c2),1,pc1);
	}
	/*
	for(ptr=start;(ptr);prev=ptr,ptr=ptr->next)
	{
		free(prev);
	}
	free(prev);*/
	fclose(pc1);
	
	return EXIT_SUCCESS;
}


/*********************************************************
 *
 * 	*FUNCTION NAME : eventmanager_file_to_list
 *
 * 	*DESCRIPTION   : This function is used here to transfer the data from the  eventmanager file to the list.
 *
 * 	*RETURNS       : No Returns
 *
 *********************************************************/


int eventmanager_file_to_list()		//eventmanager file to list function start here...
{
	FILE *pt;
	EM_temp e1;
	if((pt=fopen("../data/eventmanager","rb"))==NULL)
	{
		//printf("\n File is not found\n");
		return EXIT_FAILURE;
	}
	fread(&e1,sizeof(e1),1,pt);
	while(!feof(pt))
	{
		if((new1=(EM *)calloc(1,sizeof(EM)))==NULL)
		{
			printf("\n Memory Allocation Failed \n");
			return EXIT_FAILURE;
		}
		strcpy(new1->EM_Name,e1.EM_Name);
		strcpy(new1->Address,e1.Address);
		new1->Years_of_experience=e1.Years_of_experience;
		new1->cost_of_event=e1.cost_of_event;
		new1->contact_number=e1.contact_number;
		new1->EMCODE=e1.EMCODE;
                new1->confirmation_status=e1.confirmation_status;
		strcpy(new1->event_type,e1.event_type);
		strcpy(new1->password,e1.password);
		if(!start1)
		{
			start1 = last1 = new1;
			new1->next1=NULL;
		}
		else
		{
			last1->next1=new1;
			last1=new1;
			new1->next1=NULL;
		}
		fread(&e1,sizeof(e1),1,pt);
	}

	fclose(pt);
	//system("read a");
	//system("clear");
	return EXIT_SUCCESS;
}


/*********************************************************
 *
 * 	*FUNCTION NAME : eventmanager_list_to_file
 *
 * 	*DESCRIPTION   : This function is used here to transfer the data from the evenmanager list to the file.
 *
 * 	*RETURNS       : No Returns
 *
 *********************************************************/


int eventmanager_list_to_file()		//eventmanager list to file function start here...
{
	EM_temp e2;
	if(!start1)
	{

		//printf("\n The list is Empty.\n");
		return EXIT_FAILURE;
	}
	FILE *pt1;
	if((pt1=fopen("../data/eventmanager","wb"))==NULL)
	{
		printf("\nFile is Not Found\n");
		return EXIT_FAILURE;
	}
	for(ptr1=start1;(ptr1);ptr1=ptr1->next1)
	{
		strcpy(e2.EM_Name,ptr1->EM_Name);
		strcpy(e2.Address,ptr1->Address);
		e2.Years_of_experience=ptr1->Years_of_experience;
		e2.cost_of_event=ptr1->cost_of_event;
		e2.contact_number=ptr1->contact_number;
		e2.EMCODE=ptr1->EMCODE;
		e2.confirmation_status=ptr1->confirmation_status;
		strcpy(e2.event_type,ptr1->event_type);
		strcpy(e2.password,ptr1->password);
		fwrite(&e2,sizeof(e2),1,pt1);
	}
	/*
	for(ptr1=start1;(ptr1);prev1=ptr1,ptr1=ptr1->next1)
	{
		free(prev1);
	}
	
	free(prev1);*/
	fclose(pt1);
	return EXIT_SUCCESS;
}


/*********************************************************
 *
 * 	*FUNCTION NAME : eventoo_file_to_list
 *
 * 	*DESCRIPTION   : This function is used here to transfer the data from the eventoo file to the list.
 *
 * 	*RETURNS       : No Returns
 *
 *********************************************************/


int eventoo_file_to_list()		//eventoo file to list function starts here...
{
	FILE *ps;
	eventoo_temp o1;
	if((ps=fopen("../data/eventoo","rb"))==NULL)
	{
		//printf("\n File is not found\n");
		return EXIT_FAILURE;
	}
	fread(&o1,sizeof(o1),1,ps);
	while(!feof(ps))
	{
		if((new2=(eventoo *)calloc(1,sizeof(eventoo)))==NULL)
		{
			printf("\n Memory Allocation Failed \n");
			return EXIT_FAILURE;
		}
		new2->event_ID=o1.event_ID;
		new2->Aadharno=o1.Aadharno;
		strcpy(new2->event_type,o1.event_type);
		new2->EMCODE=o1.EMCODE;
		strcpy(new2->start_date,o1.start_date);
		strcpy(new2->ndays,o1.ndays);
		new2->cost_of_event=o1.cost_of_event;
		new2->budget=o1.budget;
		new2->actual_expenses=o1.actual_expenses;
		new2->completion_status=o1.completion_status;
		new2->remarks=o1.remarks;
		if(!start2)
		{
			start2 = last2 = new2;
			new2->next2=NULL;
		}
		else
		{
			last2->next2=new2;
			last2=new2;
			new2->next2=NULL;
		}
		fread(&o1,sizeof(o1),1,ps);
	}

	fclose(ps);
	//system("read a");
	//system("clear");
	return EXIT_SUCCESS;
}


/*********************************************************
 *
 * 	*FUNCTION NAME : eventoo_list_to_file
 *
 * 	*DESCRIPTION   : This function is used here to transfer the data from the eventoo list to the file.
 *
 * 	*RETURNS       : No Returns
 *
 *********************************************************/


int eventoo_list_to_file()		//eventoo list to file function start here...
{
	eventoo_temp o2;
	if(!start2)
	{

		//printf("\n The list is Empty.\n");
		return EXIT_FAILURE;
	}
	FILE *ps1;
	if((ps1=fopen("../data/eventoo","wb"))==NULL)
	{
		printf("\nFile is Not Found\n");
		return EXIT_FAILURE;
	}
	for(ptr2=start2;(ptr2);ptr2=ptr2->next2)
	{
		o2.event_ID=ptr2->event_ID;
		o2.Aadharno=ptr2->Aadharno;
		strcpy(o2.event_type,ptr2->event_type);
		strcpy(o2.start_date,o2.start_date);
		o2.budget=ptr2->budget;
		strcpy(o2.ndays,ptr2->ndays);
		o2.EMCODE=ptr2->EMCODE;
		o2.cost_of_event=ptr2->cost_of_event;
		o2.actual_expenses=ptr2->actual_expenses;
		o2.completion_status=ptr2->completion_status;
		o2.remarks=ptr2->remarks;
		fwrite(&o2,sizeof(o2),1,ps1);
	}
	/*
	for(ptr2=start2;(ptr2);prev2=ptr2,ptr2=ptr2->next2)
	{
		free(prev2);
	}
	free(prev2);*/
	fclose(ps1);
	return EXIT_SUCCESS;
}
