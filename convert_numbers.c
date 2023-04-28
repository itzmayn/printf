#include "main.h"

/**
 * convert_di - Converts an argument to a signed int
 * @args: arguments.
 * @output: buffer.
 * @flags: Flag
 * @width: width.
 * @precision:  precision.
 * @length: length
 * Return: The number of bytes stored to the buffer.
 */
unsigned int convert_di(va_list args, buffer_t *output,
		unsigned char flags, int width, int precision, unsigned char length)
{
	long int d, copy;
	unsigned int ret = 0, count = 0;
	char pad, space = ' ', neg = '-', plus = '+';

	if (length == LONG)
		d = va_arg(args, long int);
	else
		d = va_arg(args, int);
	if (length == SHORT)
		d = (short)d;
	if (SPACE_FLAG == 1 && d >= 0)
		ret += _memcpy(output, &space, 1);
	if (precision <= 0 && NEG_FLAG == 0)
	{
		if (d == LONG_MIN)
			count += 19;
		else
		{
			for (copy = (d < 0) ? -d : d; copy > 0; copy /= 10)
				count++;
		}
		count += (d == 0) ? 1 : 0;
		count += (d < 0) ? 1 : 0;
		count += (PLUS_FLAG == 1 && d >= 0) ? 1 : 0;
		count += (SPACE_FLAG == 1 && d >= 0) ? 1 : 0;
		if (ZERO_FLAG == 1 && PLUS_FLAG == 1 && d >= 0)
			ret += _memcpy(output, &plus, 1);
		if (ZERO_FLAG == 1 && d < 0)
			ret += _memcpy(output, &neg, 1);
		pad = (ZERO_FLAG == 1) ? '0' : ' ';
		for (width -= count; width > 0; width--)
			ret += _memcpy(output, &pad, 1);
	}
	if (ZERO_FLAG == 0 && d < 0)
		ret += _memcpy(output, &neg, 1);
	if (ZERO_FLAG == 0 && (PLUS_FLAG == 1 && d >= 0))
		ret += _memcpy(output, &plus, 1);
	if (!(d == 0 && precision == 0))
		ret += convert_sbase(output, d,
				"0123456789", flags, 0, precision);
	ret += print_neg_width(output, ret,
			flags, width);
	return (ret);
}

/**
 * convert_b - Converts an unsigned int argument to binany
 * @args: arguments.
 * @output: buffer containing a character array.
 * @flags: Flag
 * @width: width
 * @precision: precision
 * @length: length
 * Return: The number of bytes saved.
 */
unsigned int convert_b(va_list args, buffer_t *output, unsigned char flags,
		       int width, int precision, unsigned char length)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	(void)length;

	return (convert_ubase(output, num, "01", flags, width, precision));
}

/**
 * convert_o - Converts an unsigned int to octal
 * @args: arguments.
 * @output: buffer.
 * @flags: Flag..
 * @width: width.
 * @precision:  precision
 * @length: length
 * Return: The number of bytes saved.
 */
unsigned int convert_o(va_list args, buffer_t *output, unsigned char flags,
		       int width, int precision, unsigned char length)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	if (length == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);

	if (length == SHORT)
		num = (unsigned short)num;

	if (HASH_FLAG == 1 && num != 0)
		ret += _memcpy(output, &zero, 1);

	if (!(num == 0 && precision == 0))
		ret += convert_ubase(output, num, "01234567", flags, width,
				     precision);

	ret += print_neg_width(output, ret, flags, width);

	return (ret);
}

/**
 * convert_u - Converts an unsigned int argument to decimal and
 *             stores it to a buffer contained in a struct.
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
unsigned int convert_u(va_list args, buffer_t *output, unsigned char flags,
		       int width, int precision, unsigned char length)
{
	unsigned long int num;
	unsigned int ret = 0;

	if (length == LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);

	if (length == SHORT)
		num = (unsigned short)num;

	if (!(num == 0 && precision == 0))
		ret += convert_ubase(output, num, "0123456789", flags, width,
				     precision);

	ret += print_neg_width(output, ret, flags, width);

	return (ret);
}
