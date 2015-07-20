#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>   /* for malloc */
#include <ctype.h>    /* for toupper */


struct employee
{
  int id_number;
  float wage;

  /* TODO - Add other members */

  struct employee *next;
};

/* TODO - Add Function Prototypes as needed */

/* TODO - Add Functions here as needed */

/* Optional - Add Challenge Functions here as needed */

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

  /* Start a beginning of list and print out each value               */
  /* loop until tmp points to null (remember null is 0 or false)      */
  for (tmp = emp1; tmp; tmp = tmp->next)
  {
    i++;

    /* TODO - print other members as well */
    printf("\nEmployee ID: %6d, Wage: %8.2f\n", tmp->id_number,
      tmp->wage);
  }

  printf("\n\nTotal Number of Employees = %d\n", i);

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
/* CALLS:        print_list                                                   */
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


    /* TODO - Prompt for Employee Name and Hours as well here */

    /* Read in Employee ID and Hourly Wage */
    printf("\nEnter employee ID: ");
    scanf("%i", &current_ptr->id_number);

    printf("\nEnter employee hourly wage: ");
    scanf("%f", &current_ptr->wage);

    /* TODO - Call Function(s) to calculate Overtime and Gross */

    printf("Would you like to add another employee? (y/n): ");
    scanf("%s", answer);

    /* Ask user if they want to add another employee */
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

  /* TODO: Call Function(s) to determine totals and averages */
  /* Optional TODO: Call Challenge Functions to determine min and max values */

  /* print out listing of all employee id's and wages that were entered */
  print_list(head_ptr);
  printf("\n\nEnd of program\n");
  return (0);

}