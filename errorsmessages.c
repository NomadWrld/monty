#include "monty.h"

/**
 * error.c - Contains functions for error handling in the Monty program.
 * @err: Prints error messages based on codes:
 *   - (1): No file provided.
 *   - (2): Unable to open/read the file.
 *   - (3): Invalid instruction in the file.
 *   - (4): Memory allocation failure.
 *   - (5): Non-integer argument for "push".
 *   - (6): Empty stack for "pint".
 *   - (7): Empty stack for "pop".
 *   - (8): Insufficient elements for operation.
 */
void custom_err(int err_code, ...)
{
	va_list args;
	char *operatin;
	int line_nm;

	va_start(args, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Unable to open file %s\n",
					va_arg(args, char *));
			break;
		case 3:
			line_nm = va_arg(args, int);
			operatin = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_nm, operatin);
			break;
		case 4:
			fprintf(stderr, "Error: Memory allocation failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * extra_err - Handles additional errors.
 * @err_code: Additional error codes:
 * (6) => Empty stack for "pint" instruction.
 * (7) => Empty stack for "pop" instruction.
 * (8) => Stack too short for operation.
 * (9) => Division by zero.
 */
void extra_err(int err_code, ...)
{
	va_list args;
	char *operatin;
	int line_nm;

	va_start(args, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack is empty\n",
					va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop, stack is empty\n",
					va_arg(args, int));
			break;
		case 8:
			line_nm = va_arg(args, unsigned int);
			operatin = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack is too short\n", line_nm, operatin);
			break;
		case 9:
			fprintf(stderr, "Division by zero\n");
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - Handles string-related errors.
 * @err_code: String-related error codes:
 * (10) ~> Node value is outside ASCII bounds.
 * (11) ~> Stack is empty.
 */
void string_err(int err_code, ...)
{
	va_list args;
	int line_num;

	va_start(args, err_code);
	line_num = va_arg(args, int);
	switch (err_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack is empty\n", line_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
