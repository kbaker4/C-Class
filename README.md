# C-Class
Homework assignments from C at UML

HOMEWORK 1 - PROGRAM LOOPING

Write a C program that will calculate the pay for employees.

For each employee the program should prompt the user to enter the clock number, wage rate, and number of hours. This input will be used to determine the gross pay for a given week, which is the number of hours worked in a given week multiplied by the an employee's hourly wage.

HOMEWORK 2 - MAKING DECISIONS

Write a C program that will calculate the gross pay of a set of employees.

For each employee the program should prompt the user to enter the clock number, wage rate, and number of hours as shown below.

The program determines both the overtime hours (anything over 40 hours) and the gross pay, and outputs the following format. Hours over 40 are paid at time and a half.

HOMEWORK 3 - ARRAYS

Write a C program that will calculate the gross pay and overtime hours for a set of employees using arrays. Do not use concepts we have not yet covered in the lecture notes or book.

The program should prompt the user to enter the number of hours each employee worked. When prompted, key in the hours shown below. You do not need to prompt for how many employees to process up front. Instead, define a constant and use it for your array size and within your code (such as loop tests)

HOMEWORK 4 - FUNCTIONS

Write a C program using multiple functions that will calculate the gross pay for a set of employees.

HOMEWORK 5 - STRUCTURES

Write a C program that will calculate the gross pay of a set of employees.

The program should prompt the user to enter the number of hours each employee worked. When prompted, key in the hours shown below.

The program determines the overtime hours (anything over 40 hours), the gross pay, and then outputs a table in the following format. Column alignment, leading zeros in Clock#, and zero suppression in float fields is important. Use 1.5 as the overtime pay factor.
You should implement this program using the following structure to store the information for each employee.

    /* This is the structure you will need, feel free to modify as needed */
    struct employee
    {
          long  int id_number;  /* or just int id_number; */
          float wage;
          float hours;
          float overtime;
          float gross;
    };
    
HOMEWORK 6 - CHARACTER STRINGS

Write a C program that will calculate the gross pay of a set of employees.

The program should prompt the user to enter the number of hours each employee worked. When prompted, key in the hours shown below.

The program determines the overtime hours (anything over 40 hours), the gross pay and then outputs a table in the following format. 

Column alignment, leading zeros in Clock#, and zero suppression in float fields is important. 
  1) These are mandatory and need to be done:
    a) Add a Total row at the end to sum up the wage, hours, ot, and gross columns
    b) Add an Average row to print out the average of the wage, hours, ot, and gross columns
    
HOMEWORK 7 - SIMPLE POINTERS

Write a C program that will calculate the gross pay of a set of employees.   Declare an array of structures to hold your employees as well as a pointer to it.  

Do not use any array references with indexes.
