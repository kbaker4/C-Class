//*****************************************************/
//                                                    
// HOMEWORK: 7										                    
//                                                    
// Name: Kevin Baker                                  
//                                                    
// Class: C Programming                               
//                                                    
// Date: 8 July, 2015                                 
//                                                    
// Description: Employee pay calculator. This program 
// calculates the gross pay based on hours worked     
// to include overtime, and the employee's wage.      
// Output is displayed in the console                 
//*****************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* constants to use */
#define SIZE 5            /* employees to process */
#define OT_FACTOR 1.5
#define STD_HOURS 40

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
void printData(struct Employee emps[]);
float getGross(struct Employee *emps);
float getOvertimeHours(struct Employee *emps);
float getOvertimePay(struct Employee *emps);

// Functions for Totals struct
struct Totals getTotalWage(struct Employee emps[], struct Totals totals);
struct Totals getTotalHours(struct Employee emps[], struct Totals totals);
struct Totals getTotalOvertime(struct Employee emps[], struct Totals totals);
struct Totals getTotalGross(struct Employee emps[], struct Totals totals);
void printTotals(struct Totals totals);

// Functions for Averages struct
struct Averages getAverageWage(struct Employee emps[], struct Averages averages);
struct Averages getAverageHours(struct Employee emps[], struct Averages averages);
struct Averages getAverageOvertime(struct Employee emps[], struct Averages averages);
struct Averages getAverageGross(struct Employee emps[], struct Averages averages);
void printAverages(struct Averages averages);

// Functions for Mins struct
struct Mins getMinWage(struct Employee emps[], struct Mins mins);
struct Mins getMinHours(struct Employee emps[], struct Mins mins);
struct Mins getMinOvertime(struct Employee emps[], struct Mins mins);
struct Mins getMinGross(struct Employee emps[], struct Mins mins);
void printMins(struct Mins mins);

// Functions for Maxes struct
struct Maxes getMaxWage(struct Employee emps[], struct Maxes maxes);
struct Maxes getMaxHours(struct Employee emps[], struct Maxes maxes);
struct Maxes getMaxOvertime(struct Employee emps[], struct Maxes maxes);
struct Maxes getMaxGross(struct Employee emps[], struct Maxes maxes);
void printMaxes(struct Maxes maxes);

int main()
{
  struct Employee emps[SIZE] = { { "Connie Cobol", 98401, 10.60 },
                                 { "Mary Apl", 526488, 9.75 },
                                 { "Frank Fortran", 765349, 10.50 },
                                 { "Jeff Ada", 34645, 12.25 },
                                 { "Anton Pascal", 127615, 10.00 } };
  
  struct Totals totals = { 0, 0, 0, 0 };
  struct Averages averages = { 0, 0, 0, 0 };
  struct Mins mins = { 0, 0, 0, 0 };
  struct Maxes maxes = { 0, 0, 0, 0 };

    getHours(emps);
    emps->overtime = getOvertimeHours(emps);  /* Calculate total amount of overtime hours */
    emps->overtimePay = getOvertimePay(emps);  /* Calculate total amount of overtime pay, if necessary */
    emps->gross = getGross(emps); /* Calculate gross pay */
  printData(emps);

  printf(" ------------------------------------------------------------------- \n");

  // Get all the totals and print them out
  totals = getTotalWage(emps, totals);
  totals = getTotalHours(emps, totals);
  totals = getTotalOvertime(emps, totals);
  totals = getTotalGross(emps, totals);
  printTotals(totals);

  // Get all the averages and print them out
  averages = getAverageWage(emps, averages);
  averages = getAverageHours(emps, averages);
  averages = getAverageOvertime(emps, averages);
  averages = getAverageGross(emps, averages);
  printAverages(averages);

  // Get all the mins and print them out
  mins = getMinWage(emps, mins);
  mins = getMinHours(emps, mins);
  mins = getMinOvertime(emps, mins);
  mins = getMinGross(emps, mins);
  printMins(mins);

  // Get all the maxes and print them out
  maxes = getMaxWage(emps, maxes);
  maxes = getMaxHours(emps, maxes);
  maxes = getMaxOvertime(emps, maxes);
  maxes = getMaxGross(emps, maxes);
  printMaxes(maxes);

  return;
}

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
    scanf("%f", emps->hours);
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
float getOvertimeHours(struct Employee *emps){
  float otHours; /* Amount of overtime worked */
  if (emps->hours > STD_HOURS)
    otHours = emps->hours - 40;
  else
    otHours = 0;

  return otHours;
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
float getOvertimePay(struct Employee *emps){
  float otPay; /* Amount of overtime pay the employee receives, if any */

    if (emps->overtime > 0)
      otPay = OT_FACTOR * emps->wage * emps->overtime;
    else
      otPay = 0;

  return otPay;
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
float getGross(struct Employee *emps){
  float gross;  /* Total gross pay for employee */

    if (emps->overtimePay == 0)
      gross = emps->hours * emps->wage;
    else
      gross = STD_HOURS * emps->wage + emps->overtimePay;

  return gross;
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
void printData(struct Employee emps[]){

  /* Print a nice table header */
  printf("\n\n -------------------------------------------------------------------\n");
  printf(" Name            Clock#      Wage        Hours        OT      Gross\n");
  printf(" -------------------------------------------------------------------\n");

  /* Access each employee and print to screen or file */
  for (int i = 0; i < SIZE; i++)
  {
    /* print employee information from your arrays */
    printf(" %-15s %.06i %10.2f %10.1f %10.1f %10.2f\n",
      emps[i].name, emps[i].clockNumber, emps[i].wage, emps[i].hours, emps[i].overtime, emps[i].gross);
  }

  return;
}

//**************************************************************/ 
// Function: getTotalWage
// 
// Purpose: Calculates the Total Wage for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Totals  
// 
// Returns:  struct Total totals
//**************************************************************/ 
struct Totals getTotalWage(struct Employee emps[], struct Totals totals){
  for (int i = 0; i < SIZE; ++i)
    totals.totalWage += emps[i].wage;
  return totals;
}

//**************************************************************/ 
// Function: getTotalHours
// 
// Purpose: Calculates the Total Hours for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Totals    
// 
// Returns:  struct Total totals
//**************************************************************/ 
struct Totals getTotalHours(struct Employee emps[], struct Totals totals){
  for (int i = 0; i < SIZE; ++i)
    totals.totalHours += emps[i].hours;
  return totals;
}

//**************************************************************/ 
// Function: getTotalOvertime
// 
// Purpose: Calculates the Total Overtime for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Totals    
// 
// Returns:  struct Total totals
//**************************************************************/ 
struct Totals getTotalOvertime(struct Employee emps[], struct Totals totals){
  for (int i = 0; i < SIZE; ++i)
    totals.totalOvertime += emps[i].overtime;
  return totals;
}

//**************************************************************/ 
// Function: getTotalGross
// 
// Purpose: Calculates the Total Gross for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Totals    
// 
// Returns: struct Total totals
//**************************************************************/ 
struct Totals getTotalGross(struct Employee emps[], struct Totals totals){
  for (int i = 0; i < SIZE; ++i)
    totals.totalGross += emps[i].gross;
  return totals;
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
void printTotals(struct Totals totals){
  printf(" Totals: %25.2f %10.1f %10.1f %10.2f\n",
    totals.totalWage, totals.totalHours, totals.totalOvertime, totals.totalGross);
}

//**************************************************************/ 
// Function: getAverageWage
// 
// Purpose: Calculates the average wage for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Averages    
// 
// Returns: struct Average averages
//**************************************************************/ 
struct Averages getAverageWage(struct Employee emps[], struct Averages averages){
  float tmp = 0;
  for (int i = 0; i < SIZE; ++i)
    tmp += emps[i].wage;
  averages.averageWage = tmp / SIZE;
  return averages;
}

//**************************************************************/ 
// Function: getAverageHours
// 
// Purpose: Calculates the average hours for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Averages    
// 
// Returns: struct Average averages
//**************************************************************/ 
struct Averages getAverageHours(struct Employee emps[], struct Averages averages){
  float tmp = 0;
  for (int i = 0; i < SIZE; ++i)
    tmp += emps[i].hours;
  averages.averageHours = tmp / SIZE;
  return averages;
}

//**************************************************************/ 
// Function: getAverageOvertime
// 
// Purpose: Calculates the average overtime hours for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Averages    
// 
// Returns: struct Average averages
//**************************************************************/ 
struct Averages getAverageOvertime(struct Employee emps[], struct Averages averages){
  float tmp = 0;
  for (int i = 0; i < SIZE; ++i)
    tmp += emps[i].overtime;
  averages.averageOvertime = tmp / SIZE;
  return averages;
}

//**************************************************************/ 
// Function: getAverageGross
// 
// Purpose: Calculates the average gross pay for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Averages    
// 
// Returns: struct Average averages
//**************************************************************/
struct Averages getAverageGross(struct Employee emps[], struct Averages averages){
  float tmp = 0;
  for (int i = 0; i < SIZE; ++i)
    tmp += emps[i].gross;
  averages.averageGross = tmp / SIZE;
  return averages;
}

//**************************************************************/ 
// Function: printAverages
//
// Purpose: Nicely prints all averages
// 
// Parameters: 
// struct of type Averages    
// 
// Returns: Nothing
//**************************************************************/
void printAverages(struct Averages averages){
  printf(" Averages: %23.2f %10.1f %10.1f %10.2f\n",
    averages.averageWage, averages.averageHours, averages.averageOvertime, averages.averageGross);
  return;
}

//**************************************************************/ 
// Function: getMinWage
// 
// Purpose: Calculates the min wage for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Mins    
// 
// Returns: struct Mins mins
//**************************************************************/
struct Mins getMinWage(struct Employee emps[], struct Mins mins){
  mins.minWage = emps[0].wage;
  for (int i = 1; i < SIZE; ++i){
    if (emps[i].wage < mins.minWage)
      mins.minWage = emps[i].wage;
  }
  return mins;
}

//**************************************************************/ 
// Function: getMinHours
// 
// Purpose: Calculates the min hours for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Mins    
// 
// Returns: struct Mins mins
//**************************************************************/
struct Mins getMinHours(struct Employee emps[], struct Mins mins){
  mins.minHours = emps[0].hours;
  for (int i = 1; i < SIZE; ++i){
    if (emps[i].hours < mins.minHours)
      mins.minHours = emps[i].hours;
  }
  return mins;
}

//**************************************************************/ 
// Function: getMinOvertime
// 
// Purpose: Calculates the min overtime hours for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Mins    
// 
// Returns: struct Mins mins
//**************************************************************/
struct Mins getMinOvertime(struct Employee emps[], struct Mins mins){
  mins.minOvertime = emps[0].overtime;
  for (int i = 1; i < SIZE; ++i){
    if (emps[i].overtime < mins.minOvertime)
      mins.minOvertime = emps[i].overtime;
  }
  return mins;
}

//**************************************************************/ 
// Function: getMinGross
// 
// Purpose: Calculates the min gross for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Mins    
// 
// Returns: struct Mins mins
//**************************************************************/
struct Mins getMinGross(struct Employee emps[], struct Mins mins){
  mins.minGross = emps[0].gross;
  for (int i = 1; i < SIZE; ++i){
    if (emps[i].gross < mins.minGross)
      mins.minGross = emps[i].gross;
  }
  return mins;
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
void printMins(struct Mins mins){
  printf(" Mins: %27.2f %10.1f %10.1f %10.2f\n",
    mins.minWage, mins.minHours, mins.minOvertime, mins.minGross);
  return;
}

//**************************************************************/ 
// Function: getMaxWage
// 
// Purpose: Calculates the max wage for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Maxes    
// 
// Returns: struct Maxes maxes
//**************************************************************/
struct Maxes getMaxWage(struct Employee emps[], struct Maxes maxes){
  maxes.maxWage = emps[0].wage;
  for (int i = 1; i < SIZE; ++i){
    if (emps[i].wage > maxes.maxWage)
      maxes.maxWage = emps[i].wage;
  }
  return maxes;
}

//**************************************************************/ 
// Function: getMaxHours
// 
// Purpose: Calculates the max hours for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Maxes    
// 
// Returns: struct Maxes maxes
//**************************************************************/
struct Maxes getMaxHours(struct Employee emps[], struct Maxes maxes){
  maxes.maxHours = emps[0].hours;
  for (int i = 1; i < SIZE; ++i){
    if (emps[i].hours > maxes.maxHours)
      maxes.maxHours = emps[i].hours;
  }
  return maxes;
}

//**************************************************************/ 
// Function: getMaxOvertime
// 
// Purpose: Calculates the max overtime hours for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Maxes    
// 
// Returns: struct Maxes maxes
//**************************************************************/
struct Maxes getMaxOvertime(struct Employee emps[], struct Maxes maxes){
  maxes.maxOvertime = emps[0].overtime;
  for (int i = 1; i < SIZE; ++i){
    if (emps[i].overtime > maxes.maxOvertime)
      maxes.maxOvertime = emps[i].overtime;
  }
  return maxes;
}

//**************************************************************/ 
// Function: getMaxGross
// 
// Purpose: Calculates the max gross for 
// all employees
// 
// Parameters: 
// struct of type Employee, struct of type Maxes    
// 
// Returns: struct Maxes maxes
//**************************************************************/
struct Maxes getMaxGross(struct Employee emps[], struct Maxes maxes){
  maxes.maxGross = emps[0].gross;
  for (int i = 1; i < SIZE; ++i){
    if (emps[i].gross > maxes.maxGross)
      maxes.maxGross = emps[i].gross;
  }
  return maxes;
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
void printMaxes(struct Maxes maxes){
  printf(" Maxes: %26.2f %10.1f %10.1f %10.2f\n",
    maxes.maxWage, maxes.maxHours, maxes.maxOvertime, maxes.maxGross);
  return;
}