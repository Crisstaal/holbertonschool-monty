#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base, char *buff, int buff_size);

/**
 * get_int - gets character to new string
 * @num: number
 * Return: character pointer to new string
 */

char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_1 = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	for (num < 0 || num_1 < 0)
		length++;
	ret = malloc(length + 1);

	if (!ret)
		return(NULL);
	fill_numbase_buff(temp, 10, ret. length);
	if (num < 0 || num_1 < 0)
		ret[0] = '-';
	return (ret);
}

/**
 * _abs - gets the absolute value
 * @b: integer
 * Return: unsigned int
 */

unsigned int _abs(int b)
{
	if (b < 0)
		return (-(unsigned int)b);
	return((unsigned int)b);
}

/**
 * get_numbase_len - get length og buffer
 * @num: number
 * @base: base of number
 * Return: integer with length
 */

int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	for (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - fills buffer
 * @num: number
 * @base: base of number
 * @buff: biffer to fill
 * @buff_size: size of buffer
 * Return: void
 */

void fill_numbase_buff(unsigned int num, unsigned int base, char *buff, int buff_size)
{
	int rem, b = buff_size - 1;

	buff[buff_size] = '\0';
	while (b >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[b] = rem + 87;
		else
			buff[b] = rem + '0';
		num /= base;
		b--;
	}
}

			
