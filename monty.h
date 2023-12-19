#ifndef _MONTY_H_
#define _MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIM " \n\t\a\b"

extern char **op_toks;
/**
 * struct stack_t - doubly linked list
 * @i : integer
 * @prev: previous
 * @next: next
 */

typedef struct stack_t
{
	int i;
	struct stack_t *prev;
	struct stack_t *next;
} stack_s;

/**
 * struct instruction_s - function
 * @opcode: the opcode
 * @f: function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_s **stack,
			unsigned int lnumber);
}instruction_t;

void free_stacks(stack_s **stacks);
int init_stack(stack_s **stacks);
int check(stack_s *stacks);
void free_token(void);
unsigned int array_length(void);
int run(FILE *script_fd);
void set_error(int errors);
void monty_push(stack_s **stacks,
unsigned int lnumber);
void monty_pall(stack_s **stacks,
unsigned int lnumber);
void monty_pint(stack_s **stacks,
unsigned int lnumber);
void monty_pop(stack_s **stacks,
unsigned int lnumber);
void monty_swap(stack_s **stacks,
unsigned int lnumber);
void monty_add(stack_s **stacks,
unsigned int lnumber);
void monty_nop(stack_s **stacks,
unsigned int lnumber);
void monty_sub(stack_s **stacks,
unsigned int lnumber);
void monty_div(stack_s **stacks,
unsigned int lnumber);
void monty_mul(stack_s **stacks,
unsigned int lnumber);
void monty_mod(stack_s **stacks,
unsigned int lnumber);
void monty_pchar(stack_s **stacks,
unsigned int lnumber);
void monty_pstr(stack_s **stacks,
unsigned int lnumber);
void monty_rotl(stack_s **stacks,
unsigned int lnumber);
void monty_rotr(stack_s **stacks,
unsigned int lnumber);
void monty_stack(stack_s **stacks,
unsigned int lnumber);
void monty_queue(stack_s **stacks,
unsigned int lnumber);
char **strtok(char *str, char *delim);
char get_integer(int j);
int using_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_opp(char *opcode,
unsigned int lnumber);
int no_error(unsigned int lnumber);
int pop_error(unsigned int lnumber);
int pint_error(unsigned int lnumber);
int short_error(unsigned int lnumber, char *opp);
int div_error(unsigned int lnumber);
int pchar_error(unsigned in lnumber, char *m);

#endif
