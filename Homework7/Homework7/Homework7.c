//*****************************************************/
//                                                    
// HOMEWORK: 7										                    
//                                                    
// Name: Kevin Baker                                  
//                                                    
// Class: C Programming                               
//                                                    
// Date: 9 July, 2015                                 
//                                                    
// Description: Employee pay calculator. This program 
// calculates the gross pay based on hours worked     
// to include overtime, and the employee's wage.      
// Output is displayed in the console                 
//*****************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// constants to use 
#define SIZE 5            // employees to process 
#define OT_FACTOR 1.5     // rate for overtime pay increase
#define STD_HOURS 40      // anything over this is overtime

struct Employee
{
  char name[20];
  long  int clockNumber;  /* or just int id_number; */
  float wage;
  float hours;
  float overtime;
  float gross;
  float overtimePay;
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

struct Mins{
  float minWage;
  float minHours;
  float minOvertime;
  float minGross;
};

struct Maxes{
  float maxWage;
  float maxHours;
  float maxOvertime;
  float maxGross;
};

// Functions for Employee struct
void getHours(struct Employee *emps);
void getGross(struct Employee *emps);
void getOvertimeHours(struct Employee *emps);
void getOvertimePay(struct Employee *emps);
void printData(struct Employee *emps);

// Functions for Totals struct
void getTotals(struct Employee *emps, struct Totals *totals);
void printTotals(struct Totals *totals);

// Functions for Averages struct
void getAverages(struct Employee *emps, struct Averages *averages);
void printAverages(struct Averages *averages);

// Functions for Mins struct
void getMins(struct Employee *emps, struct Mins *mins);
void printMins(struct Mins *mins);

// Functions for Maxes struct
void getMaxes(struct Employee *emps, struct Maxes *maxes);
void printMaxes(struct Maxes *maxes);

int main()
{
  struct Employee emps[SIZE] = { { "Connie Cobol", 98401, 10.60 },
                                 { "Mary Apl", 526488, 9.75 },
                                 { "Frank Fortran", 765349, 10.50 },
                                 { "Jeff Ada", 34645, 12.25 },
                                 { "Anton Pascal", 127615, 10.00 } };
  
  struct Totals totals[4] = { 0, 0, 0, 0 };
  struct Averages averages[4] = { 0, 0, 0, 0 };
  struct Mins mins[4] = { 0, 0, 0, 0 };
  struct Maxes maxes[4] = { 0, 0, 0, 0 };

  getHours(emps);
  getOvertimeHours(emps);  // Calculate total amount of overtime hours 
  getOvertimePay(emps);  // Calculate total amount of overtime pay, if necessary 
  getGross(emps); // Calculate gross pay 
  printData(emps); // Print everything

  printf(" ------------------------------------------------------------------- \n");

  // Get all the totals and print them out
  getTotals(emps, totals);
  printTotals(totals);

  // Get all the averages and print them out
  getAverages(emps, averages);
  printAverages(averages);

  // Get all the mins and print them out
  getMins(emps, mins);
  printMins(mins);

  // Get all the maxes and print them out
  getMaxes(emps, maxes);
  printMaxes(maxes);
} // end main

//**************************************************************/ 
// Function: getHours 
// 
// Purpose: Determines hours worked based on user input 
// 
// Parameters: clockNumber - The clock number of the employee
// 
// Returns: hoursWorked - hours worked by the employee in a given week (call by value)
//  
//**************************************************************/ 
void getHours(struct Employee *emps){
  /* Read in hours worked for employee */
  for (int i = 0; i < SIZE; i++){
    printf("Enter the number of hours worked by emp # %06i: ", emps->clockNumber);
    scanf("%f", &emps->hours);
    ++emps;
  }
}

//**************************************************************/ 
// Function: getOvertimeHours
// 
// Purpose: Determine the total amount of overtime hours that
// the employee worked, if any
//  
// Parameters: hours
// 
// Returns: otHours - overtime hours worked
//  
//**************************************************************/ 
void getOvertimeHours(struct Employee *emps){
  float otHours; /* Amount of overtime worked */
  for (int i = 0; i < SIZE; i++){
    if (emps->hours > STD_HOURS)
      (*emps).overtime = emps->hours - 40;
    else
      emps->overtime = 0;
    emps++;
  }
}

//**************************************************************/ 
// Function: getOvertimePay
// 
// Purpose: Determine the total amount of overtime pay that
// the employee receoved, if any
//  
// Parameters: overtime, wage
// 
// Returns: otPay - overtime pay received
//  
//**************************************************************/ 
void getOvertimePay(struct Employee *emps){
  float otPay; /* Amount of overtime pay the employee receives, if any */
  for (int i = 0; i < SIZE; i++){
    if (emps->overtime > 0)
      otPay = OT_FACTOR * emps->wage * emps->overtime;
    else
      otPay = 0;
    emps++;
  }
}

//**************************************************************/ 
// Function: getGross
// 
// Purpose: Calculate gross pay of employee based on wage, hours
// and overtimePay, if applicable
// 
// Parameters: hours, overtimePay, wage
// 
// Returns: gross - gross pay for employee
//  
//**************************************************************/ 
void getGross(struct Employee *emps){
  float gross;  /* Total gross pay for employee */
  for (int i = 0; i < SIZE; i++){
    if (emps->overtimePay == 0)
      emps->gross = emps->hours * emps->wage;
    else
      emps->gross = STD_HOURS * emps->wage + emps->overtimePay;
    emps++;
  }
}

//**************************************************************/ 
// Function: printData  
// 
// Purpose: Prints out all the employee information in a 
// nice and orderly table format.
// 
// Parameters: 
//
// struct of type Employee  
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void printData(struct Employee *emps){

  /* Print a nice table header */
  printf("\n\n -------------------------------------------------------------------\n");
  printf(" Name            Clock#      Wage        Hours        OT      Gross\n");
  printf(" -------------------------------------------------------------------\n");

  /* Access each employee and print to screen or file */
  for (int i = 0; i < SIZE; i++)
  {
    /* print employee information from your arrays */
    printf(" %-15s %.06i %10.2f %10.1f %10.1f %10.2f\n",
      emps->name, emps->clockNumber, emps->wage, emps->hours, emps->overtime, emps->gross);
    emps++;
  }
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
void getTotals(struct Employee *emps, struct Totals *totals){
  for (int i = 0; i < SIZE; ++i){
    totals->totalWage += emps->wage;
    totals->totalHours += emps->hours;
    totals->totalOvertime += emps->overtimePay;
    totals->totalGross += emps->gross;
    emps++;
  }
}

//**************************************************************/ 
// Function: printTotals
// 
// Purpose: Nicely prints all the totals
// 
// Parameters: 
// struct of type Employee, struct of type Totals    
// 
// Returns: struct Total totals
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
void getAverages(struct Employee *emps, struct Averages *averages){
  float tmp[4] = { 0, 0, 0, 0 }; // order for array is Wage, Hours, Overtime(hours), and Gross
  for (int i = 0; i < SIZE; i++){
    tmp[0] += emps->wage;
    tmp[1] += emps->hours;
    tmp[2] += emps->overtime;
    tmp[3] += emps->gross;
    emps++;
  }
  averages->averageWage = tmp[0] / SIZE;
  averages->averageHours = tmp[1] / SIZE;
  averages->averageOvertime = tmp[2] / SIZE;
  averages->averageGross = tmp[3] / SIZE;
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

//**************************************************************/ 
// Function: getMins
// 
// Purpose: get the min number of wages, hours, overtime(hours) 
// and gross
// 
// Parameters: 
// struct Employee pointer, struct Mins pointer   
// 
// Returns: Nothing
//**************************************************************/
void getMins(struct Employee *emps, struct Mins *mins){
  mins->minWage = emps->wage;
  mins->minHours = emps->hours;
  mins->minOvertime = emps->overtime;
  mins->minGross = emps->gross;
  emps++;

  while (emps->hours > 0 && emps->hours < 150) {
    if (emps->wage < mins->minWage)
      mins->minWage = emps->wage;
    if (emps->hours < mins->minHours)
      mins->minHours = emps->hours;
    if (emps->overtime < mins->minOvertime)
      mins->minOvertime = emps->overtime;
    if (emps->gross < mins->minOvertime)
      mins->minOvertime = emps->gross;
    emps++;
  } ;
}

//**************************************************************/ 
// Function: printMins
// 
// Purpose: Nicely prints the mins column
// 
// Parameters: 
// struct of type Mins    
// 
// Returns: Nothing
//**************************************************************/
void printMins(struct Mins *mins){
  printf(" Mins: %27.2f %10.1f %10.1f %10.2f\n",
    mins->minWage, mins->minHours, mins->minOvertime, mins->minGross);
}

//**************************************************************/ 
// Function: getMaxes
// 
// Purpose: get the max number of wages, hours, overtime(hours) 
// and gross
// 
// Parameters: 
// struct Employee pointer, struct Maxes pointer    
// 
// Returns: Nothing
//**************************************************************/
void getMaxes(struct Employee *emps, struct Maxes *maxes){
  maxes->maxWage = emps->wage;
  maxes->maxHours = emps->hours;
  maxes->maxOvertime = emps->overtime;
  maxes->maxGross = emps->gross;
  emps++;

  while (emps->hours > 0 && emps->hours < 150){
    if (emps->wage > maxes->maxWage)
      maxes->maxWage = emps->wage;
    if (emps->hours > maxes->maxHours)
      maxes->maxHours = emps->hours;
    if (emps->overtime > maxes->maxOvertime)
      maxes->maxOvertime = emps->overtime;
    if (emps->gross > maxes->maxGross)
      maxes->maxGross = emps->gross;
    emps++;
  }
}

//**************************************************************/ 
// Function: printMaxes
// 
// Purpose: Nicely prints the maxes column
// 
// Parameters: 
// struct of type Maxes    
// 
// Returns: Nothing
//**************************************************************/
void printMaxes(struct Maxes *maxes){
  printf(" Maxes: %26.2f %10.1f %10.1f %10.2f\n",
    maxes->maxWage, maxes->maxHours, maxes->maxOvertime, maxes->maxGross);
}