/*----------------------------------------------------*/
/*                                                    */
/* HOMEWORK: 2										                    */
/*                                                    */
/* Name: Kevin Baker                                  */
/*                                                    */
/* Class: C Programming                               */
/*                                                    */
/* Date: 1 June, 2015                                 */
/*                                                    */
/* Description: Employee pay calculator. This program */
/* calculates the gross pay based on hours worked     */
/* to include overtime, and the employee's wage.      */    
/* Output is displayed in the console as well as      */
/*  Employee Gross Pay.txt.                           */
/*----------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
#define STD_HOURS 40.0  /* Number of hours until OT is made */
#define OT_MULT 1.5 /* Time and a half multiplier */

	int clockNumber; /* Employee clock number */
	float grossPay; /* The gross pay for that employee for that week */
	float hours; /* The number of hours worked */
	int numberOfEmployees; /* The number of employees to process */
	FILE *outputfileptr; /* Pointer to the output file */
	float wage; /* The wage of the employee */
  float overtime; /* The amount of overtime the employee worked */
  float otPay; /* The amount the employee made in overtime */

	printf("\t***Pay Calculator***\n");					  /***********************************************/
	printf("\n\tEnter number of employees to process: "); /* Title and get number of employees to process*/
	scanf("%d", &numberOfEmployees);                      /***********************************************/

	if ((outputfileptr = fopen("Employee Gross Pay.txt", "w")) == (FILE *)NULL)  /* open a file called Employee Gross Pay.txt */
	{
		fprintf(stderr, "Error, Unable to open file\n");   /* stderr will print to the screen if the file can't be opened */
		exit(1);
	}

	/* print out employee information to a file */
	fprintf(outputfileptr, "\n\tKevin Baker, C Programming, Second Homework Assignment, 1 June 2015\n\n\n");  /****************************/
	fprintf(outputfileptr, "\t--------------------------------------------------\n");								          /* Title and columns in     */
	fprintf(outputfileptr, "\tClock#       Wage      Hours      OT      Gross\n");								 	          /* output file.             */
	fprintf(outputfileptr, "\t-------------------------------------------------\n");								 	        /****************************/

	while (numberOfEmployees > 0){
		printf("\n\tEnter Employee's Clock #: ");			    /*******************************/
		scanf("%d", &clockNumber);							          /*                             */
		                                                  /*                             */
		printf("\tEnter hourly wage: ");				        	/* Gather relevant info from   */
		scanf("%f", &wage);									              /* the user.                   */
		                                                  /*                             */
		printf("\tEnter number of hours worked: ");			  /*                             */
		scanf("%f", &hours);								              /*******************************/

    if (hours > STD_HOURS){
      overtime = hours - 40;
      otPay = overtime * (wage * OT_MULT);
      grossPay = wage * STD_HOURS + otPay;		/* Calculate gross pay based on wage, hours and overtime */
    }
    else{
      grossPay = wage * hours; /* Calculate gross pay based on wage and hours */
      overtime = 0;
    }

		printf("\n\t------------------------------------------------");	    /****************************/
		printf("\n\t Clock#       Wage     Hours      OT      Gross");      /* Title for console output */
		printf("\n\t------------------------------------------------");     /****************************/

		fprintf(outputfileptr, "\t%06i %10.2f %10.1f %10.1f %10.2f\n", clockNumber, wage, hours, overtime, grossPay);  /* Actual data for output file    */

		printf("\n\t %06d      %.2f     %.1f      %.1f      %.2f\n", clockNumber, wage, hours, overtime, grossPay);		  /* Actual data for console output */

		numberOfEmployees--; /* Number of employees left to process is reduced by 1 */
	}

	printf("\n\tAll employees processed, ending...\n\n");

	return 0;
}