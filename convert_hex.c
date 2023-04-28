#include "main.h"

/**
 * convert_x - Converts an unsigned int argument to hex
 * @args: arguments to be converted.
 * @output: buffer
 * @flags: Flag.
 * @width: width
 * @precision:  precision
 * @length: length
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_x(va_list args, buffer_t *output, unsigned char flags,
		int width, int precision, unsigned char length)
{
	unsigned long int number;
	unsigned int reten = 0;
	char *lead = "0x";

	if (length == LONG)
		number = va_arg(args, unsigned long int);
	else
		number = va_arg(args, unsigned int);
	if (length == SHORT)
		number = (unsigned short)number;

	if (HASH_FLAG == 1 && number != 0)
		reten += _memcpy(output, lead, 2);

	if (!(number == 0 && precision == 0))
		reten += convert_ubase(output, number, "0123456789abcdef",
				flags, width, precision);

	reten += print_neg_width(output, reten, flags, width);
	return (reten);
}

/**
 * convert_X - Converts an unsigned int argument to hex
 * @args: arguments
 * @output: buffer.
 * @flags: Flag.
 * @width: width..
 * @precision: precision.
 * @length: length
 * Return: number of bytes.
 */
unsigned int convert_X(va_list args, buffer_t *output, unsigned char flags,
		int width, int precision, unsigned char length)
{
	unsigned long int number;
	unsigned int reten = 0;
	char *lead = "0X";

	if (length == LONG)
		number = va_arg(args, unsigned long);
	else
		number = va_arg(args, unsigned int);
	if (length == SHORT)
		number = (unsigned short)number;

	if (HASH_FLAG == 1 && number != 0)
		reten += _memcpy(output, lead, 2);

	if (!(number == 0 && precision == 0))
		reten += convert_ubase(output, number, "0123456789ABCDEF",
				flags, width, precision);

	reten += print_neg_width(output, reten, flags, width);

	return (reten);
}
