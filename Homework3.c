/*----------------------------------------------------*/
/*                                                    */
/* HOMEWORK: 3										                    */
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

int main()
{
  /* declaring variables needed for program       */
  long  int clockNumber[SIZE] = { 98401, 526488, 765349, 34645, 127615 }; /* form of worker identification */
  int   count;                                                            /* loop index */
  float wage[SIZE] = { 10.6, 9.75, 10.5, 12.25, 8.35 };              /* money earned per hour of work */
  float hours[SIZE];                                                      /* Number of hours worked */
  float overtime[SIZE]  { };                                                   /* Number of overtime hours */
  float gross[SIZE];                                                      /* Gross pay for the employee */

  /* Process each employee one at a time */
  for (count = 0; count < SIZE; count++)
  {
    /* Read in hours worked for employee */
    printf("Enter the number of hours worked: ");
    scanf("%f", &hours[count]);
    /* calculate overtime and gross pay for employee */
    if (hours[count] > STD_HOURS){
      overtime[count] = hours[count] - 40;
      float otPay = OT_FACTOR * wage[count] * overtime[count];
      gross[count] = otPay + wage[count] * STD_HOURS;
    }
    else
      gross[count] = wage[count] * hours[count];
  }

  /* Print a nice table header */
  printf("\n\n\t-------------------------------------------------------\n");
  printf("\tClock#      Wage        Hours        OT      Gross\n");
  printf("\t-------------------------------------------------------\n");

  /* Access each employee and print to screen or file */
  for (count = 0; count < SIZE; count++)
  {
    /* print employee information from your arrays */
    printf("\t%06i %10.2f %10.1f %10.1f %10.2f\n", clockNumber[count], wage[count], hours[count], overtime[count], gross[count]);
  }
  
  printf("\n");

  return(0);
}