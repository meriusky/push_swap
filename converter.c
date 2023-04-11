/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:02:22 by mehernan          #+#    #+#             */
/*   Updated: 2023/04/11 11:45:14 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Funcion usada para convertirn un * en un int, devuelve el numero int
int	converter(char str[])// la i no ha sido muy buena idea, creo que no es asi
{
	int	count;
	int	num;
	int	sign;

	count = 0;
	num = 0;
	sign = 1;
	while (str[count] == '\t' || str[count] == '\f' || str[count] == '\n'
		|| str[count] == '\r' || str[count] == '\v' || str[count] == ' ')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		num = (num * 10) + (str[count] - '0');
		count++;
	}
	return (num * sign);
}
