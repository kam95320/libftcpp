/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Libft.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:15:11 by kahoumou          #+#    #+#             */
/*   Updated: 2025/08/27 14:03:00 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_HPP
# define LIBFT_HPP

# include <cctype>
// # include <cmath>
# include <iostream>
# include <sstream>
# include <string>
# include <vector>
#include <stdexcept>
#include <vector>
#include <map>
#include <set>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define CYAN "\033[36m"
# define ORANGE "\033[33m"
# define BOLD_CYAN "\033[1;36m"

namespace StringUtils
{
std::string to_upper(const std::string &str);
std::string to_lower(const std::string &str);
std::vector<std::string> split(const std::string &str, char delimiter);
std::string trim(const std::string &str);
std::string join(const std::vector<std::string> &parts, char delimiter);
std::string join_numbers(const std::vector<int> &numbers, char delimiter);
std::string replace(const std::string &str, const std::string &from,
	const std::string &to);
std::string trim_all(const std::string &str);
std::string remove_chars(const std::string &str, char c);

} // namespace StringUtils

namespace parsing
{
std::vector<std::string> split(const std::string &str, char delimiter);
bool				starts_with(const std::string &str,
						const std::string &prefix);
bool				ends_with(const std::string &str,
						const std::string &suffix);
int					count_words(const std::string &str, char delimiter);
bool				is_numeric(const std::string &str);
bool				is_alpha(const std::string &str);
bool				is_alnum(const std::string &str);
bool				is_ascii(const std::string &str);
bool				is_printable(const std::string &str);
bool				contains_any(const std::string &str,
						const std::string &charset);
bool				contains_only(const std::string &str,
						const std::string &charset);
std::string strip_all_quotes(const std::string &str);
std::string extract_between(const std::string &str, const std::string &start,
	const std::string &end);
std::vector<std::string> tokenize(const std::string &str, char delimiter = ' ');
std::vector<std::string> tokenize_extreme(const std::string &str,
	const std::string &delimiters);

} // namespace parsing

namespace MathUtils
{
int					abs(int n);
long				abs(long n);
float				abs(float n);
double				abs(double n);

template <typename T> T min(const T &a, const T &b);
template <typename T> T max(const T &a, const T &b);

int					sign(int n);
long				sign(long n);
float				sign(float n);
double				sign(double n);

int					mod(int a, int b);
long				mod(long a, long b);
float				mod(float a, float b);
double				mod(double a, double b);

template <typename T> T pow(T base, int exponent);

bool				is_even(int n);
bool				is_odd(int n);

unsigned long long	factorial(unsigned int n);

int					gcd(int a, int b);
int					lcm(int a, int b);

double				sqrt(double x);

double	exp(double x); // approximation de e^x
double	log(double x); // approximation de ln(x)

int					floor(double x);
int					ceil(double x);

int					round(double x);
} // namespace MathUtils

namespace algo
{
template <typename T> 
void swap(T &a, T &b);

template <typename Iterator> 
void reverse(Iterator begin, Iterator end);

template <typename T> 
bool is_sorted(const std::vector<T> &vec);

template <typename T> 
bool is_sorted_desc(const std::vector<T> &v);
template <typename T> 
std::size_t find_max_index(const std::vector<T> &v);
template <typename T> 
T find_max_element(const std::vector<T> &vec);
template <typename T>
std::size_t find_min_index(const std::vector<T>& vec);
template <typename T>
T find_min_element(const std::vector<T>& vec);
template <typename T>
int count_occurrences(const std::vector<T>& vec, const T& value);
template <typename T>
std::vector<T> find_duplicates(const std::vector<T>& vec);
template <typename T>
std::vector<T> remove_duplicates(const std::vector<T>& vec);

template <typename T>
std::map<T, int> find_frequency(const std::vector<T>& vec);
template <typename Container, typename T>

bool binary_search(const Container &c,
	const T &value);

template <typename Container, typename T> 
bool linear_search(const Container &c,
	const T &value);

template <typename Container> 
void bubble_sort(Container &c);

template <typename Container> 
void insertion_sort(Container &c);

template <typename Container> 
void selection_sort(Container &c);

template <typename T>
std::vector<T> remove_element(const std::vector<T>& vec, const T& value);
template <typename T>
std::vector<T> rotate_left(const std::vector<T>& vec, std::size_t n);
template <typename T>
std::vector<T> rotate_right(const std::vector<T>& vec, std::size_t n);
template <typename T>
bool binary_search(const std::vector<T>& vec, const T& target);

} // namespace algo

#endif
