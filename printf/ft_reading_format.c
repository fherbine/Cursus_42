#include "ft_printf.h"

static int ft_reading_non_spe(char *format, int *n)
{
	int i;

	i = 0;
	while (format[i] && format[i] != '%')
	{
		ft_putchar(format[i]);
		i++;
	}
	*n += i;
	return (i);
}

static t_length ft_length(char *str)
{
	int i;
	t_length ret;

	i = 0;
	if (str[i] == 'h')
		ret = (str[i + 1] == 'h') ? hh : h;
	else if (str[i] == 'l')
		ret = (str[i + 1] == 'l') ? ll : l;
	else if (str[i] == 'j')
		ret = j;
	else if (str[i] == 'z')
		ret = z;
	else if (str[i] == 't')
		ret = t;
	else
		ret = none;
	return (ret);
}

static void ft_printing_spe(t_flags flags, va_list ap, int *n)
{
	if (flags.specifier == 'c')
		ft_printing_char(flags, va_arg(ap, int), n);
	else if (flags.specifier == 's')
		ft_printing_string(flags, va_arg(ap, char *), n);
	else if (flags.specifier == 'x' || flags.specifier == 'X')
		ft_printing_hex(flags, ft_ucast_length(va_arg(ap, uintmax_t), flags), n);
	else if (flags.specifier == 'o')
		ft_printing_oct(flags, ft_ucast_length(va_arg(ap, uintmax_t), flags), n);
	else if (flags.specifier == 'O')
		ft_printing_oct(flags, va_arg(ap, uintmax_t), n);
	else if (flags.specifier == 'p')
		ft_printing_ptr(flags, va_arg(ap, void *), n);
	else if (flags.specifier == 'd' || flags.specifier == 'i')
		ft_printing_dec(flags, ft_cast_length(va_arg(ap, intmax_t), flags), n);
	else if (flags.specifier == 'D')
		ft_printing_dec(flags, va_arg(ap, intmax_t), n);
	else if (flags.specifier == 'u')
		ft_printing_udec(flags, ft_ucast_length(va_arg(ap, uintmax_t), flags), n);
	else if (flags.specifier == 'U')
		ft_printing_udec(flags, va_arg(ap, uintmax_t), n);
	else if (flags.specifier == '%')
		ft_printing_prct(flags, n);
}

static int ft_reading_spe(char *format, int *n, va_list ap)
{
	int i;
	t_flags flags;

	flags.precision = -1;
	flags.width = 0;
	flags.to_put = ' ';
	i = 0;
	if (ft_strchr("-+#0 ", format[i]) != NULL)
	{
		while (format[i] && ft_strchr("-+#0 ", format[i]) != NULL && i < 5)
		{
			flags.flag[i] = format[i];
			i++;
		}
	}
	flags.flag[i] = '\0';
	if (format[i] >= 48 && format[i] <= 57)
	{
		flags.width = ft_atoi(&(format[i]));
		while (format[i] >= 48 && format[i] <= 57)
			i++;
	}
	if (format[i] == '.')
	{
		i++;
		flags.precision = ft_atoi(&(format[i]));
		while (format[i] >= 48 && format[i] <= 57)
			i++;
	}
	flags.length = ft_length(&(format[i]));
	if (ft_strchr("lhjz", format[i]))
	{
		while(ft_strchr("lhjz", format[i]) && format[i])
			i++;
	}
	//while (format[i] && ft_strchr("dDiuUoOxXcCsSp%", format[i]) == NULL)
	//	i++;
	if (format[i] && ft_strchr("dDiuUoOxXcCsSp%", format[i]))
		flags.specifier = format[i];
	else
	{
		if (ft_strchr(flags.flag, '-'))
		{
			ft_putchar(format[i]);
			ft_print_nc(flags.width - 1, ' ');
			(*n) += (flags.width == 0 && format[i]) ? 1 : flags.width;
		}
		else
		{
			ft_print_nc(flags.width - 1, ' ');
			ft_putchar(format[i]);
			(*n) += (flags.width == 0 && format[i]) ? 1 : flags.width;
		}
		return (i);
	}
	ft_printing_spe(flags, ap, n);
	return (i);
}

int ft_reading_format(char *format, va_list ap)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (format[i])
	{
		i += ft_reading_non_spe(&(format[i]), &n);
		if (format[i] == '\0')
			break;
		i++;
		i += ft_reading_spe(&(format[i]), &n, ap);
		if (format[i] == '\0')
			break;
		i++;
	}
	return (n);
}
