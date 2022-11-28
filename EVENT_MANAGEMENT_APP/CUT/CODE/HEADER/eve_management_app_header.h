#ifndef EVE_MANAGEMENT_APP_HEADER_H
#define EVE_MANAGEMENT_APP_HEADER_H
#define MAX 100

typedef struct Customer
{
	char Cust_Name[MAX];
	char ndays[MAX];
	long long int Aadharno;
	double budget;
	long int Phoneno;
	char val_cust[MAX];
	char total_cust[MAX];
	char event_type[MAX];
	long int contact_number;
	char start_date[MAX];
	char avail_event_opt[MAX];
	int event_ID;
	char Password[MAX];
	int choice;
	struct Customer *next;
}cust;

//Temporary Structure for Customer
typedef struct Cust_temp
{
	char Cust_Name[MAX];
	char val_cust[MAX];
        char ndays[MAX];
	long long int Aadharno;
	char total_cust[MAX];
	char event_type[MAX];
	long int Phoneno;
	long int contact_number;
	double budget;
	int event_ID;
	char start_date[MAX];
	char avail_event_opt[MAX];
	char Password[MAX];
}cust_temp;

typedef struct EventManager
{
	char EM_Name[MAX];
	int EMCODE;
	char Address[MAX];
	int Years_of_experience;
	double cost_of_event;
	long int contact_number;
	double budget;
	int confirmation_status;
	char cust[MAX];
	double actual_expenses;
	char password[MAX];
	int choice;
	int event_ID;
	char event_type[MAX];
	struct EventManager *next1;
}EM;

//Temporary Structure for event manager
typedef struct EventManager_temp
{
	char EM_Name[MAX];
	int EMCODE;
	double budget;
	double actual_expenses;
	char Address[MAX];
	int Years_of_experience;
	int confirmation_status;
	char cust[MAX];
	double cost_of_event;
	long int contact_number;
	int event_ID;
	char password[MAX];
	int choice;
	char event_type[MAX];
}EM_temp;

typedef struct Eventoo
{
	int event_ID;
	long long int Aadharno;
	char event_type[MAX];
	int EMCODE;
	char EName[MAX];
	int total_cust;
	double cost_of_event;
	double actual_expenses;
	char cust[MAX];
	int completion_status;
	char ndays[MAX];
	double budget;
	char remarks;
	char start_date[MAX];


	struct Eventoo *next2;
}eventoo;

//Temporary Structure for Eventoo
typedef struct Eventoo_temp 
{
	int event_ID;
	long long int Aadharno;
	char event_type[MAX];
	int EMCODE;
        double cost_of_event;
	char EName[MAX];
	double actual_expenses;
	int completion_status;
	char cust[MAX];
	double budget;
	char remarks;
	char ndays[MAX];
	char start_date[MAX];
}eventoo_temp;


int customer_corner();
int eventmanager_corner();
int eventoo_corner();
int admin();

//Operations performed on Customer database
int add_cust_details();
int edit_cust_details();
int del_cust_details();
int view_cust_details();


//Operations performed on Event Manager database
int add_EM_details();
int edit_EM_details();
int view_EM_details();

//Operations performed on Eventoo database

int events_completed_report();
int events_with_budget_overrun();
int successfull_event_managers();
int pending_events_list();
int valued_customers();
int del_EM_details();
//prototype for validation functions
int alpha_valid(char *s);
//int count_digits(long int num);
int validate_aadhar(long long int num);
int validate_password(char *str);
int validate_phoneno(long int num);
int customer_file_to_list();
int eventmanager_file_to_list();
int eventoo_file_to_list();
int customer_list_to_file();
int eventmanager_list_to_file();
int eventoo_list_to_file();

#endif
