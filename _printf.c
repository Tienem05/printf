#include <unistd.h>
#include "main.h"

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;

				case 's':
				{
					char *str = va_arg(args, char *);
					while (*str)
					{
						count += _putchar(*str++);
					}
					break;
				}

				case '%':
					count += _putchar('%');
					break;

				default:
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return count;
}
