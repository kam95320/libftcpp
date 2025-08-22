/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MathUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:44:28 by kahoumou          #+#    #+#             */
/*   Updated: 2025/08/22 18:23:47 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft.hpp"

/*Donne la valeur absolue de tous les types*/

namespace MathUtils
{
int	abs(int n)
{
	return (n < 0 ? -n : n);
}

long	abs(long n)
{
	return (n < 0 ? -n : n);
}

float	abs(float n)
{
	return (n < 0.0f ? -n : n);
}

double	abs(double n)
{
	return (n < 0.0 ? -n : n);
}
} // namespace MathUtils

/*
clamp
retourne:
minimum si la valeur est inférieure au minimum
maximum si la valeur est supérieure au maximum
la valeur elle-même si elle est dans les bornes
*/
namespace MathUtils
{
int	clamp(int value, int min, int max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	return (value);
}

long	clamp(long value, long min, long max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	return (value);
}

float	clamp(float value, float min, float max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	return (value);
}

double	clamp(double value, double min, double max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	return (value);
}

} // namespace MathUtils


/* Donne la valeur  min  et max */
namespace MathUtils
{
	template <typename T>
	T min(const T& a, const T& b)
	{
		return (a < b ? a : b);
	}
    template <typename T>
	T max(const T& a, const T& b)
	{
		return (a > b ? a : b);
	}
}


int	main(void)
{
	std::cout << "=== TEST ABS ===" << std::endl;
	std::cout << "abs(int -42)      = " << MathUtils::abs(-42) << std::endl;
	std::cout << "abs(long -42000)  = " << MathUtils::abs(-42000L) << std::endl;
	std::cout << "abs(float -4.2f)  = " << MathUtils::abs(-4.2f) << std::endl;
	std::cout << "abs(double -4.2)  = " << MathUtils::abs(-4.2) << std::endl;
    std::cout << "\n=== TEST CLAMP ===\n\n";
	std::cout << "clamp(5, 0, 10)       = " << MathUtils::clamp(5, 0, 10) << "\n";
	std::cout << "clamp(-2, 0, 10)      = " << MathUtils::clamp(-2, 0, 10) << "\n";
	std::cout << "clamp(15, 0, 10)      = " << MathUtils::clamp(15, 0, 10) << "\n";
	std::cout << "clamp(4.2f, 0.0f, 10.0f)  = " << MathUtils::clamp(4.2f, 0.0f, 10.0f) << "\n";
	std::cout << "clamp(-9.0, 0.0, 100.0)   = " << MathUtils::clamp(-9.0, 0.0, 100.0) << "\n";
   
    std::cout << "\n=== TEST MIN ===" << std::endl;
    std::cout << "min(5, 10) = " << MathUtils::min(5, 10) << std::endl;
	std::cout << "min(3.14, 2.72) = " << MathUtils::min(3.14, 2.72) << std::endl;
	std::cout << "min('z', 'a') = " << MathUtils::min('z', 'a') << std::endl;
    std::cout << "\n=== TEST MAX ===" << std::endl;
	std::cout << "max(5, 10) = " << MathUtils::max(5, 10) << std::endl;
	std::cout << "max(3.14, 2.72) = " << MathUtils::max(3.14, 2.72) << std::endl;
	std::cout << "max('z', 'a') = " << MathUtils::max('z', 'a') << std::endl;
	return (0);
}
