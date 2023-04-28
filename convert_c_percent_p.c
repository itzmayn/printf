#include "main.h"

unsigned int convert_c(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_percent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int convert_p(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/**
 * convert_c - Converts an arg for an unsigned char &
 *             saves it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: the Flag..
 * @wid: the width.
 * @prec: the precision.
 * @len: the length.
 * @output: the buffer_t struct containing a char arr.
 *
 * Return: The number of bytes saved to the buffer.
 */
unsigned int convert_c(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	 char charcter;
	unsigned int reten = 0;

	 (void)prec;
	 (void)len;

	 charcter = va_arg(args, int);

	 reten += print_width(output, reten, flags, wid);
	 reten += _memcpy(output, &charcter, 1);
	 reten += print_neg_width(output, reten, flags, wid);
	return (reten);
}

/**
 * convert_percent - Stores a percent sign to a buffer
 *                   contained in a struct.
 * @args: The va_list pointing to the argument to be converted.
 * @flags: The Flag.
 * @wid: The width.
 * @prec: The precision.
 * @len: The length.
 * @output: The buffer_t struct containing a char arr.
 *
 * Return:  (always 1).
 */
unsigned int convert_percent(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	 char percent = '%';
	 unsigned int reten = 0;

	 (void)args;
	 (void)prec;
	 (void)len;

	 reten += print_width(output, reten, flags, wid);
	 reten += _memcpy(output, &percent, 1);
	 reten += print_neg_width(output, reten, flags, wid);
	return (reten);
}

/**
 * convert_p - Converts the address of an argument to hex.
 * @args: The va_list pointing to the argument to be converted.
 * @flags: The Flag.
 * @wid: The width.
 * @prec: The precision..
 * @len: The length..
 * @output: A buffer_t struct containing a char arr.
 *
 * Return: The number of bytes..
 */
unsigned int convert_p(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	 char *null = "(nil)";
	 unsigned long int address;
	 unsigned int reten = 0;

	 (void)len;
	 address = va_arg(args, unsigned long int);
	if (address == '\0')
		return (_memcpy(output, null, 5));

	 flags |= 32;
	 reten += convert_ubase(output, address,
			 "0123456789abcdef", flags, wid, prec);
	 reten += print_neg_width(output, reten, flags, wid);
	return (reten);
}
