#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_flags
{
	va_list	ap;
	int		minus;
	int		null;
	int		width;
	int		precision;
	char	type;
	int		i;
	int		counter;
}				t_flags;

int				ft_printf(const char *str, ...);
void			zero_flags(t_flags *flags);
void			ft_flags(const char *str, t_flags *flags);
int				ft_specifiers(const char *str, t_flags *flags);
void			ft_parser(const char *str, t_flags *flags);
void			ft_type(t_flags *flags);
void			ft_space(int n, t_flags *flags);
void			ft_zeros(int n, t_flags *flags);
void			if_percent(t_flags *flags);
void			if_char(t_flags *flags);
void			if_string(t_flags *flags);
void			if_uns_int(t_flags *flags);
void			if_hex(t_flags *flags);
void			if_int(t_flags *flags);
void			if_pointer(t_flags *flags);
int				ft_intlen(long long int n);
int				ft_hexlen(unsigned long int n);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
void			ft_putchar(char c);
void			ft_putnbr(unsigned int nb);
void			ft_putstr(const char *str, int len);
void			ft_putchar_hex(int c, char type);
void			ft_puthex(unsigned long int n, char type);

#endif
