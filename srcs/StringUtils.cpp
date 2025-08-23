/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:48:59 by kahoumou          #+#    #+#             */
/*   Updated: 2025/08/23 15:32:37 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft.hpp"

// ┌────────────────────────────┐
// │ LIBFT++ : StringUtils      │
// └────────────────────────────┘
// - to_upper(const std::string&) → std::string
// - to_lower(const std::string&) → std::string
// - trim(const std::string&) → std::string
// - trim_all(const std::string&) → std::string
// - replace(str, from, to) → std::string
// - remove_chars(const std::string&, char)→ std::string
// - starts_with(str, prefix) → bool
// - ends_with(str, suffix) → bool
// - split(str, delimiter) → std::vector<std::string>
// - join(vector<string>, delimiter) → std::string
// - join_numbers(vector<int>, delimiter) → std::string


namespace StringUtils
{
std::string to_upper(const std::string &str)
{
	std::string result;
	for (std::size_t i = 0; i < str.length(); ++i)
		result += std::toupper(static_cast<unsigned char>(str[i]));
	return (result);
}

std::string to_lower(const std::string &str)
{
	std::string result;
	for (std::size_t i = 0; i < str.length(); ++i)
		result += std::tolower(static_cast<unsigned char>(str[i]));
	return (result);
}

} // namespace StringUtils

std::string StringUtils::trim(const std::string &str)
{
	std::size_t start = 0;
	while (start < str.length()
		&& std::isspace(static_cast<unsigned char>(str[start])))
		start++;
	std::size_t end = str.length();
	while (end > start && std::isspace(static_cast<unsigned char>(str[end
				- 1])))
		end--;
	return (str.substr(start, end - start));
}
std::string StringUtils:: trim_all(const std::string &str)
{
	std::string result;
	for (std::size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			result += str[i];
	}
	return (result);
}

std::string StringUtils::replace(const std::string &str,
	const std::string &from, const std::string &to)
{
	if (from.empty())
		return (str);
	std::string result = str;
	std::size_t pos = 0;
	while ((pos = result.find(from, pos)) != std::string::npos)
	{
		result.replace(pos, from.length(), to);
		pos += to.length();
	}
	return (result);
}
std::string StringUtils:: remove_chars(const std::string &str, char c)
{
	std::string result;
	for (std::size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] != c)
			result += str[i];
	}
	return (result);
}

namespace StringUtils
{
bool	starts_with(const std::string &str, const std::string &prefix)
{
	if (prefix.length() > str.length())
		return (false);
	for (std::size_t i = 0; i < prefix.length(); ++i)
	{
		if (str[i] != prefix[i])
			return (false);
	}
	return (true);
}

bool	ends_with(const std::string &str, const std::string &suffix)
{
	if (suffix.length() > str.length())
		return (false);
	std::size_t offset = str.length() - suffix.length();
	for (std::size_t i = 0; i < suffix.length(); ++i)
	{
		if (str[offset + i] != suffix[i])
			return (false);
	}
	return (true);
}
} // namespace StringUtils

std::vector<std::string> StringUtils ::split(const std::string &str,
	char delimiter)
{
	std::vector<std::string> result;
	std::string current;
	for (std::size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == delimiter)
		{
			if (!current.empty())
			{
				result.push_back(trim(current));
				current.clear();
			}
		}
		else
		{
			current += str[i];
		}
	}
	if (!current.empty())
		result.push_back(trim(current));
	return (result);
}

std::string StringUtils::join(const std::vector<std::string> &parts,
	char delimiter)
{
	std::string result;
	for (std::size_t i = 0; i < parts.size(); ++i)
	{
		result += parts[i];
		if (i < parts.size() - 1)
			result += delimiter;
	}
	return (result);
}

std::string StringUtils::join_numbers(const std::vector<int> &numbers,
	char delimiter)
{
	std::ostringstream oss;
	for (std::size_t i = 0; i < numbers.size(); ++i)
	{
		oss << numbers[i];
		if (i < numbers.size() - 1)
			oss << delimiter;
	}
	return (oss.str());
}


int	main(void)
{
	std::string s = "libft est solide";
	std::string to_split = "je,teste,la,split,fonction";
	std::vector<std::string> to_join;
	std::vector<int> scores;
	std::string phrase = "je mange du pain, pain et encore du pain";
	std::string replaced = StringUtils::replace(phrase, "pain", "riz");
	std::string noisy = "42--++lib--ft++";
	std::string cleaned = StringUtils::remove_chars(noisy, '+');
	std::string messy = "  bon  jour   42 ";
	std::string remove_chars(const std::string &str, char c);
	std::string trimmed = StringUtils::trim_all(messy);
	std::cout << BOLD_CYAN << "\n=== TESTS LIBFT++ ===\n\n" << RESET;
	std::cout << CYAN << "[TO_UPPER]      " << RESET << StringUtils::to_upper(s) << "\n";
	std::cout << CYAN << "[TO_LOWER]      " << RESET << StringUtils::to_lower(s) << "\n";
	std::cout << CYAN << "[STARTS_WITH]   " << RESET << (StringUtils::starts_with(s,
			"lib") ? GREEN "true" : RED "false") << RESET << "\n";
	std::cout << CYAN << "[ENDS_WITH]     " << RESET << (StringUtils::ends_with(s,
			"solide") ? GREEN "true" : RED "false") << RESET << "\n";
	std::cout << BOLD_CYAN << "\n=== TEST SPLIT ===\n" << RESET;
	std::vector<std::string> tokens = StringUtils::split(to_split, ',');
	for (std::size_t i = 0; i < tokens.size(); ++i)
		std::cout << "[" << i << "] " << tokens[i] << "\n";
	to_join.push_back("lib");
	to_join.push_back("ft");
	to_join.push_back("plus");
	std::cout << BOLD_CYAN << "\n=== TEST JOIN ===\n" << RESET;
	std::string result = StringUtils::join(to_join, '_');
	std::cout << result << "\n";
	scores.push_back(10);
	scores.push_back(20);
	scores.push_back(42);
	std::cout << BOLD_CYAN << "\n=== TEST JOIN_NUMBERS ===\n" << RESET;
	std::string score_line = StringUtils::join_numbers(scores, ',');
	std::cout << score_line << "\n";
	std::cout << BOLD_CYAN << "\n=== TEST REPLACE ===\n" << RESET;
	std::cout << replaced << "\n";
	std::cout << BOLD_CYAN << "\n=== TEST TRIM_ALL ===\n" << RESET;
	std::cout << CYAN << "[Original]   " << ORANGE << "\"" << messy << "\"" << RESET << "\n";
	std::cout << CYAN << "[Trim All]   " << GREEN << "\"" << trimmed << "\"" << RESET << "\n";
	std::cout << BOLD_CYAN << "\n=== TEST REMOVE_CHARS ===\n" << RESET;
	std::cout << CYAN << "[Original]   " << ORANGE << "\"" << noisy << "\"" << RESET << "\n";
	std::cout << CYAN << "[No '+']     " << GREEN << "\"" << cleaned << "\"" << RESET << "\n";
	std::cout << BOLD_CYAN << "\n=== FIN DES TESTS ===\n" << RESET;
	return (0);
}
