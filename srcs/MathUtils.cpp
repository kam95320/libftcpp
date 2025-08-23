/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MathUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:44:28 by kahoumou          #+#    #+#             */
/*   Updated: 2025/08/23 12:34:02 by kahoumou         ###   ########.fr       */
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
template <typename T> T min(const T &a, const T &b)
{
	return (a < b ? a : b);
}
template <typename T> T max(const T &a, const T &b)
{
	return (a > b ? a : b);
}
} // namespace MathUtils

/*
Retourne :
  -  1 si le nombre est positif
  - -1 si le nombre est négatif
  -  0 si le nombre est nul
*/
namespace MathUtils
{
int	sign(int n)
{
	if (n > 0)
		return (1);
	else if (n < 0)
		return (-1);
	return (0);
}

long	sign(long n)
{
	if (n > 0)
		return (1);
	else if (n < 0)
		return (-1);
	return (0);
}

float	sign(float n)
{
	if (n > 0.0f)
		return (1);
	else if (n < 0.0f)
		return (-1);
	return (0);
}

double	sign(double n)
{
	if (n > 0.0)
		return (1);
	else if (n < 0.0)
		return (-1);
	return (0);
}
} // namespace MathUtils

namespace MathUtils
{
int	mod(int a, int b)
{
	return (b == 0 ? 0 : a % b);
}

long	mod(long a, long b)
{
	return (b == 0 ? 0 : a % b);
}

float	mod(float a, float b)
{
	int	quotient;

	if (b == 0.0f)
		return (0.0f);
	quotient = static_cast<int>(a / b);
	return (a - quotient * b);
}

double	mod(double a, double b)
{
	long	quotient;

	if (b == 0.0)
		return (0.0);
	quotient = static_cast<long>(a / b);
	return (a - quotient * b);
}

} // namespace MathUtils

// pow =  calcule  de puissance (exponent)

template <typename T> T MathUtils::pow(T base, int exponent)
{
	T		result;
	bool	is_negative;

	if (exponent == 0)
		return (static_cast<T>(1));
	result = static_cast<T>(1);
	is_negative = (exponent < 0);
	if (is_negative)
		exponent = -exponent;
	for (int i = 0; i < exponent; ++i)
		result *= base;
	if (is_negative)
		return (static_cast<T>(1) / result);
	if (is_negative && base == static_cast<T>(0))
		throw std::runtime_error("Division by zero in pow()");
	return (result);
}

/*Deux fonctions très simples mais pratiques à avoir dans une lib :

is_even(n) : retourne true si le nombre est pair.

is_odd(n) : retourne true si le nombre est impair.
*/

namespace MathUtils
{
bool	is_even(int n)
{
	return (n % 2 == 0);
}

bool	is_odd(int n)
{
	return (n % 2 != 0);
}
} // namespace MathUtils
/*
La factorielle d’un entier n (notée n!) est définie comme :
n! = n × (n-1) × (n-2) × ... × 1
Et par convention : 0! = 1

Exemples :
5! = 5 × 4 × 3 × 2 × 1 = 120
0! = 1
3! = 3 × 2 × 1 = 6
*/

unsigned long long MathUtils::factorial(unsigned int n)
{
	unsigned long long	result;

	if (n == 0 || n == 1)
		return (1);
	result = 1;
	for (unsigned int i = 2; i <= n; ++i)
		result *= i;
	return (result);
}

/*
La fonction gcd (Greatest Common Divisor) renvoie le plus grand entier qui divise à
la fois a et b sans laisser de reste.
Exemples :
gcd(20, 30) = 10
gcd(42, 56) = 14
gcd(13, 17) = 1 (ils sont premiers entre eux)

La fonction lcm renvoie le plus petit entier positif divisible à la fois
par a et par b.

Exemples :
lcm(3, 4) = 12
lcm(6, 8) = 24
lcm(7, 5) = 35

*/
namespace MathUtils
{
int	gcd(int a, int b)
{
	int	temp;

	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}
int	lcm(int a, int b)
{
	int	gcd_val;

	if (a == 0 || b == 0)
		return (0);
	gcd_val = gcd(a, b);
	return ((a / gcd_val) * b);
}
} // namespace MathUtils
/*
But de sqrt()
La fonction sqrt (square root) retourne la racine carrée d’un nombre positif ou nul.
Exemples :
sqrt(4) = 2
sqrt(9) = 3
sqrt(2) ≈ 1.4142...
*/

namespace MathUtils
{
double	sqrt(double x)
{
	double	guess;
	double	epsilon;

	if (x < 0.0)
		return (-1);
	guess = x / 2.0;
	epsilon = 0.000001;
	while ((guess * guess - x) > epsilon || (x - guess * guess) > epsilon)
		guess = (guess + x / guess) / 2.0;
	return (guess);
}
} // namespace MathUtils

int	main(void)
{
	std::cout << "=== TEST ABS ===" << std::endl;
	std::cout << "abs(int -42)      = " << MathUtils::abs(-42) << std::endl;
	std::cout << "abs(long -42000)  = " << MathUtils::abs(-42000L) << std::endl;
	std::cout << "abs(float -4.2f)  = " << MathUtils::abs(-4.2f) << std::endl;
	std::cout << "abs(double -4.2)  = " << MathUtils::abs(-4.2) << std::endl;
	std::cout << "\n=== TEST CLAMP ===\n\n";
	std::cout << "clamp(5, 0, 10)       = " << MathUtils::clamp(5, 0,
		10) << "\n";
	std::cout << "clamp(-2, 0, 10)      = " << MathUtils::clamp(-2, 0,
		10) << "\n";
	std::cout << "clamp(15, 0, 10)      = " << MathUtils::clamp(15, 0,
		10) << "\n";
	std::cout << "clamp(4.2f, 0.0f, 10.0f)  = " << MathUtils::clamp(4.2f, 0.0f,
		10.0f) << "\n";
	std::cout << "clamp(-9.0, 0.0, 100.0)   = " << MathUtils::clamp(-9.0, 0.0,
		100.0) << "\n";
	std::cout << "\n=== TEST MIN ===" << std::endl;
	std::cout << "min(5, 10) = " << MathUtils::min(5, 10) << std::endl;
	std::cout << "min(3.14, 2.72) = " << MathUtils::min(3.14,
		2.72) << std::endl;
	std::cout << "min('z', 'a') = " << MathUtils::min('z', 'a') << std::endl;
	std::cout << "\n=== TEST MAX ===" << std::endl;
	std::cout << "max(5, 10) = " << MathUtils::max(5, 10) << std::endl;
	std::cout << "max(3.14, 2.72) = " << MathUtils::max(3.14,
		2.72) << std::endl;
	std::cout << "max('z', 'a') = " << MathUtils::max('z', 'a') << std::endl;
	std::cout << "\n=== TEST SIGN ===" << std::endl;
	std::cout << "sign(-42)     = " << MathUtils::sign(-42) << std::endl;
	std::cout << "sign(0)       = " << MathUtils::sign(0) << std::endl;
	std::cout << "sign(42)      = " << MathUtils::sign(42) << std::endl;
	std::cout << "sign(-3.14f)  = " << MathUtils::sign(-3.14f) << std::endl;
	std::cout << "sign(0.0)     = " << MathUtils::sign(0.0) << std::endl;
	std::cout << "sign(2.71)    = " << MathUtils::sign(2.71) << std::endl;
	std::cout << "\n=== TEST MOD ===" << std::endl;
	std::cout << "mod(10, 3)         = " << MathUtils::mod(10, 3) << std::endl;
	std::cout << "mod(-10, 3)        = " << MathUtils::mod(-10, 3) << std::endl;
	std::cout << "mod(10.5, 3.0)     = " << MathUtils::mod(10.5,
		3.0) << std::endl;
	std::cout << "mod(-10.5, 3.0)    = " << MathUtils::mod(-10.5,
		3.0) << std::endl;
	std::cout << "\n=== TEST POW ===\n\n";
	std::cout << "pow(2, 3) = " << MathUtils::pow(2, 3) << "\n";
	std::cout << "pow(5, 0) = " << MathUtils::pow(5, 0) << "\n";
	std::cout << "pow(2.0, -2) = " << MathUtils::pow(2.0, -2) << "\n";
	std::cout << "pow(3.5f, 2) = " << MathUtils::pow(3.5f, 2) << "\n";
	std::cout << "\n=== TEST IS_EVEN / IS_ODD ===\n\n";
	std::cout << "is_even(4) = " << (MathUtils::is_even(4) ? "true" : "false") << "\n";
	std::cout << "is_odd(4)  = " << (MathUtils::is_odd(4) ? "true" : "false") << "\n";
	std::cout << "is_even(7) = " << (MathUtils::is_even(7) ? "true" : "false") << "\n";
	std::cout << "is_odd(7)  = " << (MathUtils::is_odd(7) ? "true" : "false") << "\n";
	std::cout << "\n=== TEST FACTORIAL ===\n";
	std::cout << "0! = " << MathUtils::factorial(0) << "\n";
	std::cout << "1! = " << MathUtils::factorial(1) << "\n";
	std::cout << "5! = " << MathUtils::factorial(5) << "\n";
	std::cout << "10! = " << MathUtils::factorial(10) << "\n";
	std::cout << "\n=== TEST GCD ===\n";
	std::cout << "gcd(20, 30) = " << MathUtils::gcd(20, 30) << "\n";
	std::cout << "gcd(42, 56) = " << MathUtils::gcd(42, 56) << "\n";
	std::cout << "gcd(13, 17) = " << MathUtils::gcd(13, 17) << "\n";
	std::cout << "\n=== TEST LCM ===\n";
	std::cout << "lcm(3, 4) = " << MathUtils::lcm(3, 4) << "\n";
	std::cout << "lcm(6, 8) = " << MathUtils::lcm(6, 8) << "\n";
	std::cout << "lcm(7, 5) = " << MathUtils::lcm(7, 5) << "\n";
	std::cout << "lcm(0, 5) = " << MathUtils::lcm(0, 5) << "\n";
	std::cout << "\n=== TEST SQRT ===\n";
	std::cout << "sqrt(4) = " << MathUtils::sqrt(4) << "\n";
	std::cout << "sqrt(9) = " << MathUtils::sqrt(9) << "\n";
	std::cout << "sqrt(2) = " << MathUtils::sqrt(2) << "\n";
	std::cout << "sqrt(0) = " << MathUtils::sqrt(0) << "\n";
	std::cout << "sqrt(-1) = " << MathUtils::sqrt(-1) << "\n";
	return (0);
}
