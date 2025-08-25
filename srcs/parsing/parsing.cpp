/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:34:40 by kahoumou          #+#    #+#             */
/*   Updated: 2025/08/25 18:16:29 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Libft.hpp"

/**
 * @brief Découpe une chaîne de caractères en un vecteur de sous-chaînes.
 * 
 * Cette fonction divise la chaîne `str` selon le caractère `delimiter`
 * et retourne un std::vector contenant chaque sous-chaîne extraite.
 * Les délimiteurs successifs produisent des chaînes vides.
 * 
 * Exemple : split("a,b,,c", ',') → ["a", "b", "", "c"]
 */

std::string trim(const std::string &str)
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

std::vector<std::string> parsing ::split(const std::string &str, char delimiter)
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

/**
 * @brief Vérifie si une chaîne commence par un préfixe donné.
 * 
 * Retourne true si la chaîne `str` commence exactement par la chaîne `prefix`.
 * 
 * Exemple : starts_with("hello world", "hello") → true
 */

 /**
 * @brief Vérifie si une chaîne se termine par un suffixe donné.
 * 
 * Retourne true si la chaîne `str` se termine exactement par la chaîne `suffix`.
 * 
 * Exemple : ends_with("image.png", ".png") → true
 */

namespace parsing
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
} // namespace parsing



	int parsing::count_words(const std::string& str, char delimiter)
	{
		bool in_word = false;
		int count = 0;

		for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
		{
			if (*it != delimiter && !in_word)
			{
				in_word = true;
				++count;
			}
			else if (*it == delimiter)
			{
				in_word = false;
			}
		}
		return count;
	}


	/**
	 * @brief Vérifie si une chaîne est entièrement composée de chiffres.
	 * 
	 * Cette fonction retourne true si la chaîne `str` contient au moins un caractère
	 * et que **tous** les caractères sont des chiffres décimaux (0 à 9).
	 * 
	 * Exemple :
	 *   is_numeric("12345") → true
	 *   is_numeric("12a5")  → false
	 *   is_numeric("")      → false
	 */

     
    bool parsing::is_numeric(const std::string& str)
	{
		if (str.empty())
			return false;
		for (size_t i = 0; i < str.size(); ++i)
		{
			if (!std::isdigit(str[i]))
				return false;
		}
		return true;
	}

/**
 * Vérifie si une chaîne de caractères est composée uniquement de lettres (a-z, A-Z).
 *
 * @param str La chaîne à tester.
 * @return true si tous les caractères sont alphabétiques et que la chaîne n'est pas vide,
 *         false sinon.
 *
 * Utile pour valider les entrées utilisateurs, les noms, ou détecter des chaînes "pures lettres".
 */



	bool parsing :: is_alpha(const std::string& str)
	{
		if (str.empty())
			return false;
		for (std::size_t i = 0; i < str.length(); ++i)
		{
			if (!std::isalpha(static_cast<unsigned char>(str[i])))
				return false;
		}
		return true;
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
	
bool parsing::is_alnum(const std::string& str)
{
	if (str.empty())
		return false;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isalnum(static_cast<unsigned char>(*it)))
			return false;
	}
	return true;
}
/**
 * Vérifie si une chaîne ne contient que des caractères ASCII (valeurs entre 0 et 127).
 *
 * @param str La chaîne à tester.
 * @return true si tous les caractères sont dans la plage ASCII standard,
 *         false sinon.
 *
 * Utile pour s'assurer que la chaîne ne contient pas de caractères spéciaux,
 * d'accents ou de symboles non pris en charge dans certains systèmes ou protocoles.
 */

 bool parsing::is_ascii(const std::string& str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (static_cast<unsigned char>(*it) > 127)
			return false;
	}
	return true;
}

/**
 * Vérifie si tous les caractères d'une chaîne sont imprimables (ASCII 32 à 126).
 *
 * @param str La chaîne à tester.
 * @return true si tous les caractères sont imprimables, false sinon.
 *
 * Cela permet de filtrer les chaînes contenant des caractères de contrôle
 * (comme les retours chariot, tabulations, etc.).
 */
bool parsing::is_printable(const std::string& str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		unsigned char c = static_cast<unsigned char>(*it);
		if (c < 32 || c > 126)
			return false;
	}
	return true;
}



/**
 * Vérifie si une chaîne contient au moins un caractère de l'ensemble donné.
 *
 * @param str La chaîne à analyser.
 * @param charset Les caractères recherchés.
 * @return true si au moins un caractère de str est présent dans charset, false sinon.
 *
 * Exemple : contains_any("hello", "aeiou") => true
 */
bool parsing::contains_any(const std::string& str, const std::string& charset)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (charset.find(*it) != std::string::npos)
			return true;
	}
	return false;
}

/**
 * Vérifie si une chaîne ne contient que des caractères appartenant à un ensemble donné.
 *
 * @param str La chaîne à analyser.
 * @param charset Les caractères autorisés.
 * @return true si tous les caractères de str sont dans charset, false sinon.
 *
 * Exemple : contains_only("1234", "0123456789") => true
 */
bool parsing :: contains_only(const std::string& str, const std::string& charset)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (charset.find(*it) == std::string::npos)
			return false;
	}
	return true;
}



int	main(void)
{
	std::string to_split = "je,teste,la,split,fonction";
	std::vector<std::string> to_join;
	std::cout << BOLD_CYAN << "\n=== TEST SPLIT ===\n" << RESET;
	std::vector<std::string> tokens = parsing::split(to_split, ',');
	for (std::size_t i = 0; i < tokens.size(); ++i)
		std::cout << "[" << i << "] " << tokens[i] << "\n";
	to_join.push_back("lib");
	to_join.push_back("ft");
	to_join.push_back("plus");

	std::cout << BOLD_CYAN << "\n=== TEST START_WITH && START_END ===\n" << RESET;
	std::string s = "libft est solide";
	std::cout << CYAN << "[STARTS_WITH]   " << RESET << (parsing::starts_with(s,
			"lib") ? GREEN "true" : RED "false") << RESET << "\n";
	std::cout << CYAN << "[ENDS_WITH]     " << RESET << (parsing::ends_with(s,
			"solide") ? GREEN "true" : RED "false") << RESET << "\n";
    std::cout << CYAN << "\n=== TEST count_words ===\n" << RESET;

    std::string s1 = "apple,banana,,cherry";
    std::string s2 = ",,,";
    std::string s3 = "one";
    std::string s4 = "a b c d";
    std::cout << "count_words(\"" << s1 << "\", ',') = " << parsing::count_words(s1, ',') << "\n"; 
    std::cout << "count_words(\"" << s2 << "\", ',') = " << parsing::count_words(s2, ',') << "\n"; 
    std::cout << "count_words(\"" << s3 << "\", ',') = " << parsing::count_words(s3, ',') << "\n"; 
    std::cout << "count_words(\"" << s4 << "\", ' ') = " << parsing::count_words(s4, ' ') << "\n"; 
    
	std::cout << BOLD_CYAN << "\n=== TEST IS_NUMERIC ===\n" << RESET;
    std::string test1 = "12345";
    std::string test2 = "12a45";
    std::string test3 = "";
    std::string test4 = "0000";
    std::string test5 = " 123";

    std::cout << "is_numeric(\"" << test1 << "\") = " << (parsing::is_numeric(test1) ? "true" : "false") << "\n";
    std::cout << "is_numeric(\"" << test2 << "\") = " << (parsing::is_numeric(test2) ? "true" : "false") << "\n";
    std::cout << "is_numeric(\"" << test3 << "\") = " << (parsing::is_numeric(test3) ? "true" : "false") << "\n";
    std::cout << "is_numeric(\"" << test4 << "\") = " << (parsing::is_numeric(test4) ? "true" : "false") << "\n";
    std::cout << "is_numeric(\"" << test5 << "\") = " << (parsing::is_numeric(test5) ? "true" : "false") << "\n";


    std::cout << BOLD_CYAN << "\n=== TEST IS_ALPHA ===\n" << RESET;

    std::string a1 = "Hello";
    std::string a2 = "world42";
    std::string a3 = "";
    std::string a4 = "bonjour";
    std::string a5 = "42";

    std::cout << "is_alpha(\"" << a1 << "\") = " << (parsing::is_alpha(a1) ? "true" : "false") << "\n";
    std::cout << "is_alpha(\"" << a2 << "\") = " << (parsing::is_alpha(a2) ? "true" : "false") << "\n";
    std::cout << "is_alpha(\"" << a3 << "\") = " << (parsing::is_alpha(a3) ? "true" : "false") << "\n";
    std::cout << "is_alpha(\"" << a4 << "\") = " << (parsing::is_alpha(a4) ? "true" : "false") << "\n";
    std::cout << "is_alpha(\"" << a5 << "\") = " << (parsing::is_alpha(a5) ? "true" : "false") << "\n";
	
	std::cout << BOLD_CYAN << "\n=== TEST IS_ALNUM ===\n" << RESET;
	std::cout << "is_alnum(\"abc123\")   = " << (parsing::is_alnum("abc123") ? "true" : "false") << "\n";
	std::cout << "is_alnum(\"abc_123\") = " << (parsing::is_alnum("abc_123") ? "true" : "false") << "\n";
	std::cout << "is_alnum(\"42\")       = " << (parsing::is_alnum("42") ? "true" : "false") << "\n";
	std::cout << "is_alnum(\"\")         = " << (parsing::is_alnum("") ? "true" : "false") << "\n";

	std::cout << BOLD_CYAN << "\n=== TEST IS_ASCII ===\n" << RESET;
	std::cout << "is_ascii(\"Hello\")     = " << (parsing::is_ascii("Hello") ? "true" : "false") << "\n";
	std::cout << "is_ascii(\"123\")       = " << (parsing::is_ascii("123") ? "true" : "false") << "\n";
	std::cout << "is_ascii(\"café\")      = " << (parsing::is_ascii("café") ? "true" : "false") << "\n"; // accent
	std::cout << "is_ascii(\"\")          = " << (parsing::is_ascii("") ? "true" : "false") << "\n";
	
	std::cout << BOLD_CYAN << "\n=== TEST IS_PRINTABLE ===\n" << RESET;
	std::cout << "is_printable(\"Hello\")        = " << (parsing::is_printable("Hello") ? "true" : "false") << "\n";
	std::cout << "is_printable(\"Hello\\n\")      = " << (parsing::is_printable("Hello\n") ? "true" : "false") << "\n";
	std::cout << "is_printable(\"42\")           = " << (parsing::is_printable("42") ? "true" : "false") << "\n";
	std::cout << "is_printable(\"\")             = " << (parsing::is_printable("") ? "true" : "false") << "\n";

	std::cout << BOLD_CYAN << "\n=== TEST CONTAINS_ONLY ===\n" << RESET;
	std::cout << "contains_only(\"123\", \"0123456789\") = " << (parsing::contains_only("123", "0123456789") ? "true" : "false") << "\n";
	std::cout << "contains_only(\"abc\", \"abc\")        = " << (parsing::contains_only("abc", "abc") ? "true" : "false") << "\n";
	std::cout << "contains_only(\"abc\", \"abcd\")       = " << (parsing::contains_only("abc", "abcd") ? "true" : "false") << "\n";
	std::cout << "contains_only(\"abcx\", \"abc\")       = " << (parsing::contains_only("abcx", "abc") ? "true" : "false") << "\n";
	std::cout << "contains_only(\"\", \"abc\")           = " << (parsing::contains_only("", "abc") ? "true" : "false") << "\n";


	return (0);
}