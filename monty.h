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

typedef struct stack_s
{
	int i;
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - function
 * @opcode: the opcode
 * @f: function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stacks, unsigned int line_number);
}instruction_t;

void run_monty();
int arr_len(const int *arr);
void free_stacks(stack_t **stacks);
int init_stack(stack_t **stacks);
int check_mode(stack_t *stacks);
void free_token(void);
void set_error(int errors);
void parse_stack_operation(stack_t **stack, unsigned int line_number);
void (*get_operation(char *op))(stack_t**, unsigned int);
void monty_push(stack_t **stacks, unsigned int line_number);
void monty_pall(stack_t **stacks, unsigned int line_number);
void monty_pint(stack_t **stacks, unsigned int line_number);
void monty_pop(stack_t **stacks, unsigned int line_number);
void monty_swap(stack_t **stacks, unsigned int line_number);
void monty_add(stack_t **stacks, unsigned int line_number);
void monty_nop(stack_t **stacks, unsigned int line_number);
void monty_sub(stack_t **stacks, unsigned int line_number);
void monty_div(stack_t **stacks, unsigned int line_number);
void monty_mul(stack_t **stacks, unsigned int line_number);
void monty_mod(stack_t **stacks, unsigned int line_number);
void monty_pchar(stack_t **stacks, unsigned int line_number);
void monty_pstr(stack_t **stacks, unsigned int line_number);
void monty_rotl(stack_t **stacks, unsigned int line_number);
void monty_rotr(stack_t **stacks, unsigned int line_number);
void monty_stack(stack_t **stacks, unsigned int line_number);
void monty_queue(stack_t **stacks, unsigned int line_number);
char get_integer(int j);
int usage_error(void);
int malloc_error(void);
int f_open_error(char *filename);
int unknown_op(char *opcode, unsigned int line_number);
int no_error(unsigned int line_number);
int pop_error(unsigned int line_number);
int pint_error(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *m);

#endif
