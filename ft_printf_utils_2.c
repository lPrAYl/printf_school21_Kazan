#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;
	int	digit;

	i = 0;
	nbr = 0;
	sign = 1;
	digit = 18;
	while ((*(str + i) > 8 && *(str + i) < 14) || *(str + i) == 32)
		i++;
	if (*(str + i) == 43 || *(str + i) == 45)
	{
		if (*(str + i) == 45)
			sign = -1;
		i++;
	}
	while (*(str + i) > 47 && *(str + i) < 58)
	{
		if (!digit--)
			return ((sign + 1) / (-2));
		nbr = nbr * 10 + (*(str + i) - 48);
		i++;
	}
	return (nbr * sign);
}

int	ft_abs_nbr(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	ft_len_nbr(unsigned long nbr, int sign, int base)
{
	int	len;

	len = 1;
	nbr /= base;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len + sign);
}

char	ft_char_from_itoa(int digit, t_printf *spec)
{
	char	c;

	if (digit > 9)
	{
		if (spec->type == 'X')
			c = ft_abs_nbr(digit) + 7 + '0';
		else
			c = ft_abs_nbr(digit) + 39 + '0';
	}
	else
		c = ft_abs_nbr(digit) + '0';
	return (c);
}

char	*ft_itoa_base(unsigned long nbr, t_printf *spec)
{
	int		sign;
	int		len_nbr;
	int		digit;
	char	*str;

	sign = 0;
	if (nbr < 0)
		sign = 1;
	len_nbr = ft_len_nbr(nbr, sign, spec->base);
	str = (char *)malloc(sizeof(char) * (len_nbr + 1));
	if (!str)
		return (NULL);
	if (nbr < 0)
		*(str + 0) = '-';
	str[len_nbr] = '\0';
	while (--len_nbr >= sign)
	{
		digit = nbr % spec->base;
		str[len_nbr] = ft_char_from_itoa(digit, spec);
		nbr /= spec->base;
	}
	return (str);
}
