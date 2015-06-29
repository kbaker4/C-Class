/*----------------------------------------------------*/
/*                                                    */
/* HOMEWORK: 4										                    */
/*                                                    */
/* Name: Kevin Baker                                  */
/*                                                    */
/* Class: C Programming                               */
/*                                                    */
/* Date: 29 June, 2015                                 */
/*                                                    */
/* Description: Employee pay calculator. This program */
/* calculates the gross pay based on hours worked     */
/* to include overtime, and the employee's wage.      */
/* Output is displayed in the console as well as      */
/*  Employee Gross Pay.txt.                           */
/*----------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* constants to use */
#define SIZE 5            /* employees to process */
#define OT_FACTOR 1.5
#define STD_HOURS 40

struct Employee
{
  long  int clockNumber;  /* or just int id_number; */
  float wage;
  float hours;
  float overtime;
  float gross;
  float overtimePay;
};

float getHours(struct Employee emps);
void printData(struct Employee emps[]);
float getGross(struct Employee emps);
float getOvertimeHours(struct Employee emps);
float getOvertimePay(struct Employee emps);

int main()
{
  struct Employee emps[SIZE] = { { 98401, 10.60 },
                             { 526488, 9.75 },
                             { 765349, 10.50 },
                             { 34645, 12.25 },
                             { 127615, 8.35 } };

  for (int i = 0; i < SIZE; ++i){
    emps[i].hours = getHours(emps[i]);
    emps[i].overtime = getOvertimeHours(emps[i]);  /* Calculate total amount of overtime hours */
    emps[i].overtimePay = getOvertimePay(emps[i]);  /* Calculate total amount of overtime pay, if necessary */
    emps[i].gross = getGross(emps[i]); /* Calculate gross pay */
  }

  printData(emps);

  /* Calculate the total gross pay per employee 
  for (int i = 0; i < SIZE; i++)
  {
    hours[i] = getHours(clockNumber[i]);
    overtime[i] = getOvertimeHours(hours[i]);  /* Calculate total amount of overtime hours 
    overtimePay[i] = getOvertimePay(overtime[i], wage[i]);  /* Calculate total amount of overtime pay, if necessary 
    gross[i] = getGross(hours[i], overtimePay[i], wage[i]); /* Calculate gross pay 
  }

  printData(clockNumber, wage, hours, overtime, gross);
  */
  return(0);
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
float getHours(struct Employee emps){
  float hoursWorked; /* Amount of hours worked */
  /* Read in hours worked for employee */
  printf("Enter the number of hours worked by emp # %06i: ", emps.clockNumber);
  scanf("%f", &hoursWorked);

  return hoursWorked;
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
float getOvertimeHours(struct Employee emps){
  float otHours; /* Amount of overtime worked */
  if (emps.hours > STD_HOURS)
    otHours = emps.hours - 40;
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
float getOvertimePay(struct Employee emps){
  float otPay; /* Amount of overtime pay the employee receives, if any */

  if (emps.overtime > 0)
    otPay = OT_FACTOR * emps.wage * emps.overtime;
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
float getGross(struct Employee emps){
  float gross;  /* Total gross pay for employee */

  if (emps.overtimePay == 0)
    gross = emps.hours * emps.wage;
  else
    gross = STD_HOURS * emps.wage + emps.overtimePay;

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
  printf("\n\n\t-------------------------------------------------------\n");
  printf("\tClock#      Wage        Hours        OT      Gross\n");
  printf("\t-------------------------------------------------------\n");

  /* Access each employee and print to screen or file */
  for (int i = 0; i < SIZE; i++)
  {
    /* print employee information from your arrays */
    printf("\t%06i %10.2f %10.1f %10.1f %10.2f\n",
      emps[i].clockNumber, emps[i].wage, emps[i].hours, emps[i].overtime, emps[i].gross);
  }

  printf("\n");

  return;
}