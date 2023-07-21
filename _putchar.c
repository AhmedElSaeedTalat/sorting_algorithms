#include <stdio.h>
/**
  * _putchar - prints characters
  *
  * @c: character received to print
  *
  * Return: 1 success
  */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
