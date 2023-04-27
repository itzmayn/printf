#include "main.h"

/**
 * convert_x - Converts an unsigned int argument to hex using abcdef
 *             and stores it to a buffer contained in a struct.
 *
 * @args: A va_list pointing to the argument to be converted.
 * @output: A buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @width: A width modifier.
 * @precision: A precision modifier.
 * @length: A length modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_x(va_list args, buffer_t *output, unsigned char flags,
		int width, int precision, unsigned char length)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0x";

	if (length == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (length == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, lead, 2);

	if (!(num == 0 && precision == 0))
		ret += convert_ubase(output, num, "0123456789abcdef",
				flags, width, precision);

	ret += print_neg_width(output, ret, flags, width);

	return (ret);
}

/**
 * convert_X - Converts an unsigned int argument to hex using ABCDEF
 *             and stores it to a buffer contained in a struct.
 *
 * @args: A va_list pointing to the argument to be converted.
 * @output: A buffer_t struct containing a character array.
 * @flags: Flag modifiers.
 * @width: A width modifier.
 * @precision: A precision modifier.
 * @length: A length modifier.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_X(va_list args, buffer_t *output, unsigned char flags,
		int width, int precision, unsigned char length)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *lead = "0X";

	if (length == LONG)
		num = va_arg(args, unsigned long);
	else
		num = va_arg(args, unsigned int);
	if (length == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, lead, 2);

	if (!(num == 0 && precision == 0))
		ret += convert_ubase(output, num, "0123456789ABCDEF",
				flags, width, precision);

	ret += print_neg_width(output, ret, flags, width);

	return (ret);
}
