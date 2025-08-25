/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MathUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:44:28 by kahoumou          #+#    #+#             */
/*   Updated: 2025/08/25 17:55:24 by kahoumou         ###   ########.fr       */
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
/*
** pow(base, exponent)
** Élève `base` à la puissance entière `exponent`.
**
** Si `exponent` est positif : multiplie `base` par lui-même `exponent` fois.
** Si `exponent` est 0 : retourne 1 (convention mathématique).
** Si `exponent` est négatif : retourne 1 / (base ^ |exponent|).
**
** Ne gère que les exposants entiers (positifs ou négatifs).
*/

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

/*
	La formule de Taylor permet d’approximer une fonction compliquée
	par un polynôme plus simple, en utilisant ses dérivées.

	Exemple avec f(x) = e^x autour de 0 :
		e^x = 1 + x + x^2/2! + x^3/3! + ... + x^n/n! + ...

	➤ En informatique et en ingénierie :
		- On utilise ce développement pour calculer rapidement e^x,
		sin(x), cos(x), log(1+x), etc.
		- Les calculateurs et processeurs n’évaluent pas directement
		ces fonctions : ils passent par ces approximations polynomiales.
		- En pratique, on coupe la série après quelques termes pour
		obtenir une valeur proche avec peu de calcul.

	Exemple numérique :
		Pour x = 1 :
		e^1 ≈ 1 + 1 + 1/2 + 1/6 + 1/24 = 2.7083...
		La vraie valeur est e ≈ 2.71828, donc l’approximation est
		déjà très bonne avec seulement 5 termes.
*/

double MathUtils::exp(double x)
{
	const int		max_iterations = 50;
	const double	epsilon = 1e-10;
	double			result;
	double			term;

	result = 1.0;
	term = 1.0;
	for (int i = 1; i < max_iterations; ++i)
	{
		term *= x / i;
		result += term;
		if (term < epsilon && term > -epsilon)
			break ;
	}
	return (result);
}

/*
** log(x)
** Calcule le logarithme népérien (ln) de x,
	c'est-à-dire le logarithme en base e.
**
** Implémenté sans <cmath> :
**  - Réduction de x autour de 1 en utilisant la constante e ≈ 2.71828.
**  - Utilise la série de Taylor de ln((x - 1)/(x + 1)) pour plus de précision.
**
** Lance une exception std::domain_error si x ≤ 0.
**
** Attention : précision limitée car implémenté sans bibliothèque mathématique.
*/

double MathUtils::log(double x)
{
	const double	e = 2.718281828459;
	int				k;
	double			y;
	double			y2;
	double			term;
	double			result;

	if (x <= 0.0)
		throw std::domain_error("MathUtils::log(x): x must be > 0");
	k = 0;
	while (x > 2.0)
	{
		x /= e;
		++k;
	}
	while (x < 0.5)
	{
		x *= e;
		--k;
	}
	y = (x - 1) / (x + 1);
	y2 = y * y;
	term = y;
	result = 0.0;
	for (int n = 1; n < 20; n += 2)
	{
		result += term / n;
		term *= y2;
	}
	result *= 2.0;
	return (result + k);
}

/*
** floor
** ---------------------------------------------
** Retourne le plus grand entier inférieur ou égal à x.
**
** Cette fonction tronque la partie décimale d’un double
** vers le bas, même pour les nombres négatifs :
** - floor(4.7)    → 4
** - floor(-4.7)   → -5
** - floor(3.0)    → 3
** - floor(-3.0)   → -3
**
** Implémentée sans utiliser <cmath> pour une compatibilité
** totale avec le standard C++98.
*/

int MathUtils::floor(double x)
{
	int	result;

	result = static_cast<int>(x);
	if (x < 0.0 && x != result)
		return (result - 1);
	return (result);
}

/*
** ceil
** ---------------------------------------------
** Retourne le plus petit entier supérieur ou égal à x.
**
** Cette fonction arrondit vers le haut, même pour les nombres
** négatifs :
** - ceil(4.3)    → 5
** - ceil(-4.3)   → -4
** - ceil(3.0)    → 3
** - ceil(-3.0)   → -3
**
** Implémentée sans utiliser <cmath> pour rester conforme
** au standard C++98.
*/

int MathUtils::ceil(double x)
{
	int	int_part;

	int_part = static_cast<int>(x);
	if (x > 0.0 && x != static_cast<double>(int_part))
		return (int_part + 1);
	return (int_part);
}
/**
 * Retourne l'entier le plus proche de la valeur donnée.
 * - Si la partie décimale est ≥ 0.5, la valeur est arrondie vers le haut.
 * - Sinon, elle est arrondie vers le bas.
 *
 * Exemple :
 *   round(3.2)   → 3
 *   round(3.7)   → 4
 *   round(-3.2)  → -3
 *   round(-3.7)  → -4
 *
 * Cette implémentation fonctionne sans <cmath>, compatible C++98.
 */

int MathUtils::round(double x)
{
	if (x >= 0.0)
		return (static_cast<int>(x + 0.5));
	else
		return (static_cast<int>(x - 0.5));
}

/**
 * Vérifie si une chaîne est composée uniquement de caractères alphanumériques (lettres ou chiffres).
 *
 * @param str La chaîne à tester.
 * @return true si tous les caractères sont alphanumériques et que la chaîne n'est pas vide,
 *         false sinon.
 *
 * Utile pour vérifier des identifiants, des noms de variables ou toute entrée ne devant contenir
 * que des lettres et des chiffres.
 */



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
	std::cout << BOLD_CYAN << "\n=== TEST EXP ===\n" << RESET;
	std::cout << "exp(1) ≈ " << MathUtils::exp(1.0) << " (attendu ≈ 2.718...)\n";
	std::cout << "exp(0) ≈ " << MathUtils::exp(0.0) << " (attendu = 1)\n";
	std::cout << "exp(-1) ≈ " << MathUtils::exp(-1.0) << " (attendu ≈ 0.367...)\n";
	std::cout << BOLD_CYAN << "\n=== TEST POW ===\n" << RESET;
	try
	{
		std::cout << "pow(2, 3)    = " << MathUtils::pow(2.0, 3) << "\n";
		// 8.0
		std::cout << "pow(5, 0)    = " << MathUtils::pow(5.0, 0) << "\n";
		// 1.0
		std::cout << "pow(2.0, -2) = " << MathUtils::pow(2.0, -2) << "\n";
		// 0.25
		std::cout << "pow(3.5, 2)  = " << MathUtils::pow(3.5, 2) << "\n";
		// 12.25
		std::cout << "pow(10, 1)   = " << MathUtils::pow(10.0, 1) << "\n";
		// 10.0
		std::cout << "pow(0, 5)    = " << MathUtils::pow(0.0, 5) << "\n";
		// 0.0
		std::cout << "pow(0, 0)    = " << MathUtils::pow(0.0, 0) << "\n";
		// 1.0 (convention)
		std::cout << "pow(2, -3)   = " << MathUtils::pow(2.0, -3) << "\n";
		// 0.125
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Erreur : " << e.what() << RESET << std::endl;
	}
	std::cout << BOLD_CYAN << "\n=== TEST LOG ===\n" << RESET;
	try
	{
		std::cout << "log(1.0)   = " << MathUtils::log(1.0) << "\n";
		// ≈ 0
		std::cout << "log(e)     = " << MathUtils::log(2.718281828459) << "\n";
		// ≈ 1
		std::cout << "log(10.0)  = " << MathUtils::log(10.0) << "\n";
		std::cout << "log(0.5)   = " << MathUtils::log(0.5) << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "Erreur : " << e.what() << RESET << std::endl;
	}
	std::cout << BOLD_CYAN << "\n=== TEST FLOOR ===\n" << RESET;
	std::cout << "floor(4.7)    = " << MathUtils::floor(4.7) << "\n";
	std::cout << "floor(-4.7)   = " << MathUtils::floor(-4.7) << "\n";
	std::cout << "floor(3.0)    = " << MathUtils::floor(3.0) << "\n";
	std::cout << "floor(-3.0)   = " << MathUtils::floor(-3.0) << "\n";
	std::cout << "floor(0.0)    = " << MathUtils::floor(0.0) << "\n";
	std::cout << BOLD_CYAN << "\n=== TEST CEIL ===\n" << RESET;
	std::cout << "ceil(4.3)   = " << MathUtils::ceil(4.3) << "\n";
	std::cout << "ceil(-4.3)  = " << MathUtils::ceil(-4.3) << "\n";
	std::cout << "ceil(3.0)   = " << MathUtils::ceil(3.0) << "\n";
	std::cout << "ceil(-3.0)  = " << MathUtils::ceil(-3.0) << "\n";
	std::cout << BOLD_CYAN << "\n=== TEST ROUND ===\n" << RESET;
	std::cout << "round(3.2)   = " << MathUtils::round(3.2) << "\n";  // 3
	std::cout << "round(3.7)   = " << MathUtils::round(3.7) << "\n";  // 4
	std::cout << "round(-3.2)  = " << MathUtils::round(-3.2) << "\n"; // -3
	std::cout << "round(-3.7)  = " << MathUtils::round(-3.7) << "\n"; // -4
	std::cout << "round(0.0)   = " << MathUtils::round(0.0) << "\n";  // 0
	return (0);
}
