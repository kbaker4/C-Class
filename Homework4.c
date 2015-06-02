/*----------------------------------------------------*/
/*                                                    */
/* HOMEWORK: 4										                    */
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

/* constants to use */
#define SIZE 5            /* employees to process */
#define OT_FACTOR 1.5
#define STD_HOURS 40

float getHours(long int clockNumber);
void printData(long int clockNumber[], float wage[], float hours[],
  float overtime[], float gross[]);
float getGross(float hours, float overtimePay, float wage);
float getOvertimeHours(float hours);
float getOvertimePay(float overtime, float wage);

int main()
{
  /* declaring variables needed for program       */
  long  int clockNumber[SIZE] = { 98401, 526488, 765349, 34645, 127615 }; /* form of worker identification */
  float gross[SIZE];                                                      /* Gross pay for the employee */
  float hours[SIZE];                                                      /* Number of hours worked */
  int i;                                                                   /* loop index */
  float overtime[SIZE]  {};                                                   /* Number of overtime hours */
  float overtimePay[SIZE] {};                                               /* Number of overtime pay */
  float wage[SIZE] = { 10.6, 9.75, 10.5, 12.25, 8.35 };              /* money earned per hour of work */

  /* Calculate the total gross pay per employee */
  for (int i = 0; i < SIZE; i++)
  {
    hours[i] = getHours(clockNumber[i]); 
    overtime[i] = getOvertimeHours(hours[i]);  /* Calculate total amount of overtime hours */
    overtimePay[i] = getOvertimePay(overtime[i], wage[i]);  /* Calculate total amount of overtime pay, if necessary */
    gross[i] = getGross(hours[i], overtimePay[i], wage[i]); /* Calculate gross pay */
  }

  printData(clockNumber, wage, hours, overtime, gross);

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
float getHours(long  int clockNumber){
  float hoursWorked; /* Amount of hours worked */
  /* Read in hours worked for employee */
  printf("Enter the number of hours worked by emp # %06i: ", clockNumber);
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
float getOvertimeHours(float hours){
  float otHours; /* Amount of overtime worked */
  if (hours > STD_HOURS)
    otHours = hours - 40;
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
float getOvertimePay(float overtime, float wage){
  float otPay; /* Amount of overtime pay the employee receives, if any */
  
  if (overtime > 0)
    otPay = OT_FACTOR * wage * overtime;
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
float getGross(float hours, float overtimePay, float wage){
  float gross;  /* Total gross pay for employee */
  
  if (overtimePay == 0)
    gross = hours * wage;
  else
    gross = STD_HOURS * wage + overtimePay;

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
// clockNumber - Array of employee clock numbers
// wageRate - Array of employee wages per hour
// hrs - Array of number of hours worked by an employee
// overtime - Array of overtime hours for each employee
// gross - Array of gross pay calculations for each employee
// size - Number of employees to process  
// 
// Returns: Nothing (call by reference)
//  
//**************************************************************/ 
void printData(long int clockNumber[], float wage[], float hours[],
  float overtime[], float gross[]){

  /* Print a nice table header */
  printf("\n\n\t-------------------------------------------------------\n");
  printf("\tClock#      Wage        Hours        OT      Gross\n");
  printf("\t-------------------------------------------------------\n");

  /* Access each employee and print to screen or file */
  for (int i = 0; i < SIZE; i++)
  {
    /* print employee information from your arrays */
    printf("\t%06i %10.2f %10.1f %10.1f %10.2f\n", 
      clockNumber[i], wage[i], hours[i], overtime[i], gross[i]);
  }

  printf("\n");

  return;
}