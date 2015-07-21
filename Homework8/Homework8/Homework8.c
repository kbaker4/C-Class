//*****************************************************/
//                                                    
// HOMEWORK: 8									                    
//                                                    
// Name: Kevin Baker                                  
//                                                    
// Class: C Programming                               
//                                                    
// Date: 20 July, 2015                                 
//                                                    
// Description: Employee pay calculator. This program 
// calculates the gross pay based on hours worked     
// to include overtime, and the employee's wage.      
// Output is displayed in the console                 
//*****************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>   /* for malloc */
#include <ctype.h>    /* for toupper */

const int STD_HOURS = 40;
const float OT_RATE = 1.5;

struct employee
{
  char name[30];
  int id_number;
  float wage;
  float hours;
  float overtime;
  float gross;

  struct employee *next;
};

struct Totals{
  float totalWage;
  float totalHours;
  float totalOvertime;
  float totalGross;
};

struct Averages{
  float averageWage;
  float averageHours;
  float averageOvertime;
  float averageGross;
};

void print_list(struct employee *emp1);
void getOvertime(struct employee *emp);
void getGross(struct employee *emp);
void getTotals(struct employee *emp, struct Totals *totals);
void printTotals(struct Totals *totals);
void getAverages(struct Employee *emp, struct Averages *averages);
void printAverages(struct Averages *averages);

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  print_list                                                       */
/*                                                                             */
/* DESCRIPTION:  This function will print the contents of a linked             */
/*               list.  It will traverse the list from beginning to the        */
/*               end, printing the contents at each node.                      */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list                               */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
void print_list(struct employee *emp1)
{
  struct employee *tmp;   /* tmp pointer value to current node */
  int i = 0;              /* counts the nodes printed          */

  printf("\n\n -------------------------------------------------------------------\n");
  printf(" Name            Clock#      Wage        Hours        OT      Gross\n");
  printf(" -------------------------------------------------------------------\n");

  /* Start a beginning of list and print out each value               */
  /* loop until tmp points to null (remember null is 0 or false)      */
  for (tmp = emp1; tmp; tmp = tmp->next)
  {
    i++;

    printf("\ %-15s %.06i %10.2f %10.1f %10.1f %10.2f\n", 
      tmp->name, tmp->id_number, tmp->wage, tmp->hours, tmp->overtime, tmp->gross);
  }
  printf("\n\nTotal Number of Employees = %d\n", i);
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  getOvertime                                                      */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the total overtime pay of an     */
/*               employee. Overtime rate is 1.5 times normal rate.             */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list                               */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
void getOvertime(struct employee *emp){
  float otHours = 0;
  if (emp->hours > STD_HOURS)
    otHours = emp->hours - STD_HOURS;

  emp->overtime = otHours;
}

/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  getGross                                                         */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the total gross pay of an        */
/*               employee.                                                     */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list                               */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
void getGross(struct employee *emp){
  if (emp->hours > STD_HOURS)
    emp->gross = (STD_HOURS * emp->wage) + (emp->overtime * (emp->wage * OT_RATE));
  else
    emp->gross = (emp->hours * emp->wage);
}

//**************************************************************/ 
// Function: getTotals
// 
// Purpose: Calculates all totals for all employees
// 
// Parameters: 
// pointer to struct of type Employee, 
// pointer to struct of type Totals  
// 
// Returns:  struct Total totals
//**************************************************************/ 
void getTotals(struct employee *emp, struct Totals *totals){
  struct employee *tmp;
  /* loop until tmp points to null (remember null is 0 or false)      */
  for (tmp = emp; tmp; tmp = tmp->next){
    totals->totalWage += tmp->wage;
    totals->totalHours += tmp->hours;
    totals->totalOvertime += tmp->overtime;
    totals->totalGross += tmp->gross;
  }
}

//**************************************************************/ 
// Function: printTotals
// 
// Purpose: Nicely prints all the totals
// 
// Parameters: 
// struct of type Totals    
// 
// Returns: nothing
//**************************************************************/ 
void printTotals(struct Totals *totals){
  printf(" Totals: %25.2f %10.1f %10.1f %10.2f\n",
    totals->totalWage, totals->totalHours, totals->totalOvertime, totals->totalGross);
}

//**************************************************************/ 
// Function: getAverages
//
// Purpose: Calculates the average Wage, Hours, Overtime and Gross
// for each employee
// 
// Parameters: 
// Employee struct pointer and Averages struct pointer    
// 
// Returns: Nothing
//**************************************************************/
void getAverages(struct employee *emp, struct Averages *averages){
  float avgTmp[4] = { 0, 0, 0, 0 }; // order for array is Wage, Hours, Overtime(hours), and Gross
  struct employee *tmp;
  int i = 0;
  for (tmp = emp; tmp; tmp = tmp->next){
    avgTmp[0] += tmp->wage;
    avgTmp[1] += tmp->hours;
    avgTmp[2] += tmp->overtime;
    avgTmp[3] += tmp->gross;
    i++;
  }
  averages->averageWage = avgTmp[0] / i;
  averages->averageHours = avgTmp[1] / i;
  averages->averageOvertime = avgTmp[2] / i;
  averages->averageGross = avgTmp[3] / i;
} // end getAverages

//**************************************************************/ 
// Function: printAverages
//
// Purpose: Nicely prints all averages
// 
// Parameters: 
// Averages struct pointer   
// 
// Returns: Nothing
//**************************************************************/
void printAverages(struct Averages *averages){
  printf(" Averages: %23.2f %10.1f %10.1f %10.2f\n",
    averages->averageWage, averages->averageHours, averages->averageOvertime, averages->averageGross);
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/* FUNCTION:  main                                                            */
/*                                                                            */
/* DESCRIPTION:  This function will prompt the user for an employee           */
/*               id and wage until the user indicates they are finished.      */
/*               At that point, a list of id and wages will be                */
/*               generated.                                                   */
/*                                                                            */
/* PARAMETERS:   None                                                         */
/*                                                                            */
/* OUTPUTS:      None                                                         */
/*                                                                            */
/* CALLS:        print_list, getOvertime, getGross                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int main()
{
  char   answer[80];       /* to see if the user wants to add more employees */
  int    more_data = 1;    /* flag to check if another employee is to be processed */
  char   value;            /* gets the first character of answer */

  struct employee *current_ptr,   /* pointer to current node */
    *head_ptr;      /* always points to first node */

  /* Set up storage for first node */
  head_ptr = (struct employee *) malloc(sizeof(struct employee));
  current_ptr = head_ptr;

  while (more_data)
  {
    /* Prompt for Employee Name */
    printf("Enter employee name: ");
    char *firstName[15], *lastName[15];
    scanf("%s %s", firstName, lastName);
    strcpy(current_ptr->name, firstName);
    strcat(current_ptr->name, " ");
    strcat(current_ptr->name, lastName);

    /* Read in Employee ID */
    printf("\nEnter employee ID: ");
    scanf("%i", &current_ptr->id_number);

    // Read in hourly wage
    printf("\nEnter employee hourly wage: ");
    scanf("%f", &current_ptr->wage);

    // Read in hours worked
    printf("\nEnter number of hours worked: ");
    scanf("%f", &current_ptr->hours);

    getOvertime(current_ptr); // Calculate overtime hours for current employee
    getGross(current_ptr); // Calculate gross pay for current employee
    
    /* Ask user if they want to add another employee */
    printf("Would you like to add another employee? (y/n): ");
    scanf("%s", answer);

    if ((value = toupper(answer[0])) != 'Y')
    {
      current_ptr->next = (struct employee *) NULL;
      more_data = 0;
    }
    else
    {
      /* set the next pointer of the current node to point to the new node */
      current_ptr->next = (struct employee *) malloc(sizeof(struct employee));
      /* move the current node pointer to the new node */
      current_ptr = current_ptr->next;
    }
  } /* while */

  struct Totals totals[4] = { 0, 0, 0, 0 }; // initialize array for holding totals
  struct Averages averages[4] = { 0, 0, 0, 0 }; //initialize array for holding averages
  getTotals(head_ptr, totals); // get all the totals
  getAverages(head_ptr, averages); // get all the averages

  /* print out listing of all employee id's and wages that were entered */
  print_list(head_ptr); // print standard list of employees
  printf(" ------------------------------------------------------------------- \n");
  printTotals(totals); // print row for totals
  printAverages(averages); // print row for averages
  printf("\n\nEnd of program\n");
  return (0);

} // end main