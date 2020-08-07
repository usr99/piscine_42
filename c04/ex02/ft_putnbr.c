void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
    long    nbr;

    nbr = nb;
    if (nbr > 9)
    {
	ft_putnbr(nbr / 10);
	ft_putnbr(nbr % 10);
    }
    else
	ft_putchar(nbr + '0');
}
