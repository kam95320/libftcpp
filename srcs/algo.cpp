/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:10:31 by kahoumou          #+#    #+#             */
/*   Updated: 2025/08/27 14:05:15 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Libft.hpp"

/*
** Échange les valeurs de deux variables.
** Utile pour les algorithmes de tri ou les permutations.
*/
namespace algo
{
template <typename T> void swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template void swap<int>(int &, int &);
template void swap<std::string>(std::string &, std::string &);
} // namespace algo

/*
 ** Inverse l'ordre des éléments dans une séquence (entre first et last).
 ** Ex : [1, 2, 3, 4] devient [4, 3, 2, 1]
 */

template <typename Iterator> void algo::reverse(Iterator first, Iterator last)
{
	if (first == last)
		return ;
	--last;
	while (first < last)
	{
		swap(*first, *last);
		++first;
		--last;
	}
}

template void algo::reverse<std::vector<int>::iterator>(std::vector<int>::iterator,
	std::vector<int>::iterator);
template void algo::reverse<std::string::iterator>(std::string::iterator,
	std::string::iterator);



	/*
	** Vérifie si un vector est trié dans l’ordre croissant.
	** Retourne true si chaque élément est <= au suivant.
	*/
	template <typename T>
	bool algo::is_sorted(const std::vector<T>& vec)
	{
		for (std::size_t i = 1; i < vec.size(); ++i)
		{
			if (vec[i - 1] > vec[i])
				return false;
		}
		return true;
	}

	// Instanciation explicite
	template bool algo::is_sorted<int>(const std::vector<int>&);
	template bool algo::is_sorted<std::string>(const std::vector<std::string>&);

/*
	** Vérifie si un vector est trié dans l’ordre decroissant.
	** Retourne true si chaque élément est <= au suivant.
	*/
	
	template <typename T>
	bool algo::is_sorted_desc(const std::vector<T> &v)
	{
		for (std::size_t i = 1; i < v.size(); ++i)
		{
			if (v[i - 1] < v[i])
				return false;
		}
		return true;
	}

	template <typename T>
	std::size_t algo::find_max_index(const std::vector<T>& v)
	{
		if (v.empty())
			throw std::runtime_error("find_max_index: vector is empty");

		std::size_t max_index = 0;
		for (std::size_t i = 1; i < v.size(); ++i)
		{
			if (v[i] > v[max_index])
				max_index = i;
		}
		return max_index;
	}



/*
	find_max_element

	Parcourt un vecteur et retourne l’élément ayant la plus grande valeur.
	
	Lance une exception si le vecteur est vide.
	
	Peut être utilisé pour trouver l’élément maximal dans une série de scores, de chaînes,
	d’objets comparables via l’opérateur `>` (comme std::string, int, etc.).

	Exemples :
	- [2, 9, 5, 7]        → retourne 9
	- ["apple", "zebra"] → retourne "zebra"
*/





	template <typename T>
	T algo::find_max_element(const std::vector<T>& vec)
	{
		if (vec.empty())
			throw std::runtime_error("find_max_element: vector is empty");

		T max_val = vec[0];
		for (std::size_t i = 1; i < vec.size(); ++i)
		{
			if (vec[i] > max_val)
				max_val = vec[i];
		}
		return max_val;
	}

	// Instanciation explicite pour types communs (C++98 workaround)
	template int algo::find_max_element<int>(const std::vector<int>&);
	template std::string algo:: find_max_element<std::string>(const std::vector<std::string>&);



/*
		find_min_index

		Retourne l’index de l’élément **ayant la plus petite valeur** dans un vecteur.

		Lance une exception si le vecteur est vide.

		Utile si tu veux connaître la **position** (pas la valeur) de l’élément minimal.

		Exemples :
		- [2, 9, 5, 7]        → retourne 0
		- ["zebra", "apple"] → retourne 1 (car "apple" < "zebra")
	*/

	template <typename T>
	std::size_t algo::find_min_index(const std::vector<T>& vec)
	{
		if (vec.empty())
			throw std::runtime_error("find_min_index: vector is empty");

		std::size_t min_index = 0;
		for (std::size_t i = 1; i < vec.size(); ++i)
		{
			if (vec[i] < vec[min_index])
				min_index = i;
		}
		return min_index;
	}



		/*
		find_min_element

		Retourne l’élément **ayant la plus petite valeur** dans un vecteur.

		Lance une exception si le vecteur est vide.

		Pratique pour obtenir directement le plus petit élément, sans avoir besoin de connaître son index.

		Exemples :
		- [2, 9, 5, 7]        → retourne 2
		- ["zebra", "apple"] → retourne "apple"
		*/
	template <typename T>
	T algo::find_min_element(const std::vector<T>& vec)
	{
		if (vec.empty())
			throw std::runtime_error("find_min_element: vector is empty");

		T min = vec[0];
		for (std::size_t i = 1; i < vec.size(); ++i)
		{
			if (vec[i] < min)
				min = vec[i];
		}
		return min;
	}


	/*
		count_occurrences

		Compte le **nombre de fois** qu’une valeur apparaît dans un vecteur.

		 Exemple :
		- [1, 2, 3, 2, 4], val = 2 → retourne 2
		- ["a", "b", "a"], val = "a" → retourne 2
	*/
	template <typename T>
	int algo::count_occurrences(const std::vector<T>& vec, const T& value)
	{
		int count = 0;
		for (std::size_t i = 0; i < vec.size(); ++i)
		{
			if (vec[i] == value)
				++count;
		}
		return count;
	}

	/*
		find_duplicates

		Retourne une liste de tous les éléments qui apparaissent **plus d'une fois** dans un vecteur.

		🔍 Exemple :
		- [1, 2, 2, 3, 3, 3] → retourne [2, 3]
		- ["a", "b", "a"] → retourne ["a"]
	*/

	template <typename T>
	std::vector<T> algo::find_duplicates(const std::vector<T>& vec)
	{
		std::map<T, int> counts;
		std::vector<T> result;

		for (std::size_t i = 0; i < vec.size(); ++i)
			++counts[vec[i]];

		for (typename std::map<T, int>::iterator it = counts.begin(); it != counts.end(); ++it)
		{
			if (it->second > 1)
				result.push_back(it->first);
		}
		return result;
	}


/*
		remove_duplicates

		Retourne une version du vecteur sans doublons, en conservant **l'ordre original**.

		🔍 Exemple :
		- [1, 2, 2, 3, 3, 3] → [1, 2, 3]
		- ["a", "b", "a", "b", "c"] → ["a", "b", "c"]
*/

	template <typename T>
	std::vector<T> algo::remove_duplicates(const std::vector<T>& vec)
	{
		std::set<T> seen;
		std::vector<T> result;

		for (std::size_t i = 0; i < vec.size(); ++i)
		{
			if (seen.find(vec[i]) == seen.end())
			{
				seen.insert(vec[i]);
				result.push_back(vec[i]);
			}
		}
		return result;
	}

	
	/*
		find_frequency

		Compte combien de fois chaque élément apparaît dans le vecteur.

		🔍 Exemple :
		- [1, 2, 2, 3, 1] → {1: 2, 2: 2, 3: 1}
		- ["apple", "banana", "apple"] → {"apple": 2, "banana": 1}
	*/
	template <typename T>
	std::map<T, int> algo::find_frequency(const std::vector<T>& vec)
	{
		std::map<T, int> freq_map;
		for (std::size_t i = 0; i < vec.size(); ++i)
			freq_map[vec[i]]++;
		return freq_map;
	}


	


	/*
		remove_element

		Supprime toutes les occurrences d’un élément donné dans le vecteur.

		🔍 Exemple :
		- remove_element([1, 2, 3, 2, 4], 2) → [1, 3, 4]
		- remove_element(["a", "b", "a"], "a") → ["b"]
	*/
	template <typename T>
	std::vector<T> algo::remove_element(const std::vector<T>& vec, const T& value)
	{
		std::vector<T> result;
		for (std::size_t i = 0; i < vec.size(); ++i)
		{
			if (vec[i] != value)
				result.push_back(vec[i]);
		}
		return result;
	}



	/*
		rotate_left

		Fait une rotation à gauche d’un vecteur (d’un nombre de positions n).
		Les éléments décalés à gauche reviennent à la fin du vecteur.

		📌 Exemple :
		- rotate_left([1, 2, 3, 4, 5], 2) → [3, 4, 5, 1, 2]
		- rotate_left(["a", "b", "c"], 1) → ["b", "c", "a"]
	*/
	template <typename T>
	std::vector<T> algo::rotate_left(const std::vector<T>& vec, std::size_t n)
	{
		std::vector<T> result;
		if (vec.empty())
			return result;

		n %= vec.size();
		for (std::size_t i = 0; i < vec.size(); ++i)
			result.push_back(vec[(i + n) % vec.size()]);

		return result;
	}


	/*
		rotate_right

		Fait une rotation à droite d’un vecteur (d’un nombre de positions n).
		Les derniers éléments sont déplacés au début.

		📌 Exemple :
		- rotate_right([1, 2, 3, 4, 5], 2) → [4, 5, 1, 2, 3]
		- rotate_right(["a", "b", "c"], 1) → ["c", "a", "b"]
	*/

	template <typename T>
	std::vector<T> algo::rotate_right(const std::vector<T>& vec, std::size_t n)
	{
		std::vector<T> result;
		if (vec.empty())
			return result;

		n %= vec.size();
		for (std::size_t i = 0; i < vec.size(); ++i)
			result.push_back(vec[(i + vec.size() - n) % vec.size()]);

		return result;
	}
	
/*
		binary_search

		Recherche binaire dans un vecteur trié.
		Retourne true si l’élément est trouvé, false sinon.

		⚠️ Le vecteur doit être trié !

		📌 Exemple :
		- binary_search({1, 3, 5, 7}, 5) → true
		- binary_search({1, 3, 5, 7}, 6) → false
	*/

	template <typename T>
	bool algo::binary_search(const std::vector<T>& vec, const T& target)
	{
		std::size_t left = 0;
		std::size_t right = vec.size();

		while (left < right)
		{
			std::size_t mid = left + (right - left) / 2;
			if (vec[mid] == target)
				return true;
			else if (vec[mid] < target)
				left = mid + 1;
			else
				right = mid;
		}
		return false;
	}



int	main(void)
{


	std::cout << BOLD_CYAN << "\n=== TEST SWAP ===\n" << RESET;

	// Test avec des entiers
	int a = 42;
	int b = 21;
	std::cout << CYAN << "Avant swap (int): " << RESET << "a = " << a << ", b = " << b << "\n";
	algo::swap(a, b);
	std::cout << GREEN << "Après swap (int): " << RESET << "a = " << a << ", b = " << b << "\n";

	// Test avec des strings
	std::string s1 = "hello";
	std::string s2 = "world";
	std::cout << CYAN << "Avant swap (string): " << RESET << "s1 = " << s1 << ", s2 = " << s2 << "\n";
	algo::swap(s1, s2);

	std::cout << GREEN << "Après swap (string): " << RESET << "s1 = " << s1 << ", s2 = " << s2 << "\n";

	std::cout << BOLD_CYAN << "\n=== TEST REVERSE ===\n" << RESET;

	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	std::cout << "Avant reverse : ";
	for (std::size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << "\n";

	algo::reverse(v.begin(), v.end());

	std::cout << "Après reverse : ";
	for (std::size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";
	std::cout << "\n";

	std::string str = "lib42";
	algo::reverse(str.begin(), str.end());
	std::cout << "Reverse de lib42 : " << str << "\n";

	std::cout << BOLD_CYAN << "\n=== TEST IS_SORTED ===\n" << RESET;

	std::vector<int> sorted;
	sorted.push_back(1);
	sorted.push_back(2);
	sorted.push_back(3);
	sorted.push_back(4);
	sorted.push_back(5);

	std::vector<int> unsorted;
	unsorted.push_back(5);
	unsorted.push_back(3);
	unsorted.push_back(1);
	unsorted.push_back(4);
	unsorted.push_back(2);

	std::cout << CYAN << "Vecteur [1 2 3 4 5]   : " << RESET
			  << (algo::is_sorted(sorted) ? GREEN "true" : RED "false") << RESET << "\n";

	std::cout << CYAN << "Vecteur [5 3 1 4 2]   : " << RESET
			  << (algo::is_sorted(unsorted) ? GREEN "true" : RED "false") << RESET << "\n";

	std::vector<std::string> words;
	words.push_back("apple");
	words.push_back("banana");
	words.push_back("cherry");
	
	std::cout << CYAN << "Strings [a b c]       : " << RESET
			  << (algo::is_sorted(words) ? GREEN "true" : RED "false") << RESET << "\n";

	std::cout << BOLD_CYAN << "\n=== TEST DESC_SORTED ===\n" << RESET;

	std::vector<int> desc_sorted;
	desc_sorted.push_back(5);
	desc_sorted.push_back(4);
	desc_sorted.push_back(3);
	desc_sorted.push_back(2);
	desc_sorted.push_back(1);

	std::vector<int> not_desc;
	not_desc.push_back(3);
	not_desc.push_back(5);
	not_desc.push_back(1);

	std::cout << CYAN << "Desc [5 4 3 2 1]      : " << RESET
			  << (algo::is_sorted_desc(desc_sorted) ? GREEN "true" : RED "false") << RESET << "\n";

	std::cout << CYAN << "Pas Desc [3 5 1]      : " << RESET
			  << (algo::is_sorted_desc(not_desc) ? GREEN "true" : RED "false") << RESET << "\n";
			  
	std::cout << BOLD_CYAN << "\n=== TEST FIND_MAX ===\n" << RESET;
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(9);
	nums.push_back(5);
	nums.push_back(7);

	std::cout << CYAN << "Vecteur [2 9 5 7] : Index max = " << RESET
			  << algo::find_max_index(nums) << "\n";

	std::vector<std::string> words_a;
	words_a.push_back("apple");
	words_a.push_back("zebra");
	words_a.push_back("banana");

	std::cout << CYAN << "Vecteur [apple, zebra, banana] : Index max = " << RESET
			  << algo::find_max_index(words_a) << "\n";

	
		std::cout << BOLD_CYAN << "\n=== TEST MAX_VALUE ===\n" << RESET;

	std::vector<int> nums_a;
	nums_a.push_back(2);
	nums_a.push_back(9);
	nums_a.push_back(5);
	nums_a.push_back(7);

	std::cout << CYAN << "Max value [2 9 5 7] = " << RESET
          << algo::find_max_element(nums_a) << "\n";

	std::vector<std::string> words_b;
	words_b.push_back("apple");
	words_b.push_back("zebra");
	words_b.push_back("banana");

	std::cout << CYAN << "Max value [apple, zebra, banana] = " << RESET
          << algo::find_max_element(words_b) << "\n";

	std::cout << BOLD_CYAN << "\n=== TEST FIND_MIN_INDEX ===\n" << RESET;

	std::vector<int> values;
	values.push_back(42);
	values.push_back(3);
	values.push_back(99);
	values.push_back(7);
	std::cout << CYAN << "Index min [42 3 99 7] = " << RESET
	          << algo::find_min_index(values) << "\n";

	std::vector<std::string> words_c;
	words_c.push_back("zebra");
	words_c.push_back("apple");
	words_c.push_back("banana");
	std::cout << CYAN << "Index min [zebra, apple, banana] = " << RESET
	          << algo::find_min_index(words_c) << "\n";
	
	std::cout << BOLD_CYAN << "\n=== TEST FIND_MIN_ELEMENT ===\n" << RESET;

	std::vector<int> ints;
	ints.push_back(5);
	ints.push_back(3);
	ints.push_back(8);
	ints.push_back(1);
	std::cout << CYAN << "Min [5 3 8 1] = " << RESET
	          << algo::find_min_element(ints) << "\n";

	std::vector<std::string> fruits;
	fruits.push_back("banana");
	fruits.push_back("apple");
	fruits.push_back("zebra");
	std::cout << CYAN << "Min [banana, apple, zebra] = " << RESET
	          << algo::find_min_element(fruits) << "\n";
	
	std::cout << BOLD_CYAN << "\n=== TEST COUNT_OCCURRENCES ===\n" << RESET;

	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(4);
	std::cout << CYAN << "[1 2 3 2 4], valeur 2 → " << RESET
	          << algo::count_occurrences(numbers, 2) << "\n";

	std::vector<std::string> words_f;
	words_f.push_back("a");
	words_f.push_back("b");
	words_f.push_back("a");
	std::cout << CYAN << "[a b a], valeur 'a' → " << RESET
	          << algo::count_occurrences(words_f, std::string("a")) << "\n";

		std::cout << BOLD_CYAN << "\n=== TEST FIND_DUPLICATES ===\n" << RESET;

	std::vector<int> nums_b;
	nums_b.push_back(1);
	nums_b.push_back(2);
	nums_b.push_back(2);
	nums_b.push_back(3);
	nums_b.push_back(3);
	nums_b.push_back(3);

	std::vector<int> dup = algo::find_duplicates(nums_b);
	std::cout << CYAN << "[1 2 2 3 3 3] → " << RESET;
	for (std::size_t i = 0; i < dup.size(); ++i)
		std::cout << dup[i] << " ";
	std::cout << "\n";

	std::vector<std::string> mots;
	mots.push_back("a");
	mots.push_back("b");
	mots.push_back("a");

	std::vector<std::string> dup_str = algo::find_duplicates(mots);
	std::cout << CYAN << "[a b a] → " << RESET;
	for (std::size_t i = 0; i < dup_str.size(); ++i)
		std::cout << dup_str[i] << " ";
	std::cout << "\n";

	std::cout << BOLD_CYAN << "\n=== TEST REMOVE_DUPLICATES ===\n" << RESET;

	std::vector<int> nums2;
	nums2.push_back(1);
	nums2.push_back(2);
	nums2.push_back(2);
	nums2.push_back(3);
	nums2.push_back(1);

	std::vector<int> nodup = algo::remove_duplicates(nums2);
	std::cout << CYAN << "[1 2 2 3 1] → " << RESET;
	for (std::size_t i = 0; i < nodup.size(); ++i)
		std::cout << nodup[i] << " ";
	std::cout << "\n";

	std::vector<std::string> mots2;
	mots2.push_back("apple");
	mots2.push_back("banana");
	mots2.push_back("apple");

	std::vector<std::string> unique_str = algo::remove_duplicates(mots2);
	std::cout << CYAN << "[apple banana apple] → " << RESET;
	for (std::size_t i = 0; i < unique_str.size(); ++i)
		std::cout << unique_str[i] << " ";
	std::cout << "\n";
	std::cout << BOLD_CYAN << "\n=== TEST FIND_FREQUENCY ===\n" << RESET;

	std::vector<int> nums_freq;
	nums_freq.push_back(1);
	nums_freq.push_back(2);
	nums_freq.push_back(2);
	nums_freq.push_back(3);
	nums_freq.push_back(1);

	std::map<int, int> freq1 = algo::find_frequency(nums_freq);
	std::cout << CYAN << "[1 2 2 3 1] → " << RESET;
	for (std::map<int, int>::iterator it = freq1.begin(); it != freq1.end(); ++it)
		std::cout << it->first << ":" << it->second << " ";
	std::cout << "\n";

	std::vector<std::string> words_freq;
	words_freq.push_back("apple");
	words_freq.push_back("banana");
	words_freq.push_back("apple");

	std::map<std::string, int> freq2 = algo::find_frequency(words_freq);
	std::cout << CYAN << "[apple banana apple] → " << RESET;
	for (std::map<std::string, int>::iterator it = freq2.begin(); it != freq2.end(); ++it)
		std::cout << it->first << ":" << it->second << " ";
	std::cout << "\n";


	std::cout << BOLD_CYAN << "\n=== TEST REMOVE_ELEMENT ===\n" << RESET;

	std::vector<int> vec1;
	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(2);
	vec1.push_back(4);

	std::vector<int> cleaned = algo::remove_element(vec1, 2);

	std::cout << CYAN << "Original [1 2 2 3 2 4] sans 2 → " << RESET;
	for (std::size_t i = 0; i < cleaned.size(); ++i)
		std::cout << cleaned[i] << " ";
	std::cout << "\n";

	std::vector<std::string> words_g;
	words_g.push_back("apple");
	words_g.push_back("banana");
	words_g.push_back("apple");

	std::vector<std::string> cleaned_strs = algo::remove_element(words_g, std::string("apple"));

	std::cout << CYAN << "Original [apple banana apple] sans 'apple' → " << RESET;
	for (std::size_t i = 0; i < cleaned_strs.size(); ++i)
		std::cout << cleaned_strs[i] << " ";
	std::cout << "\n";
	std::cout << BOLD_CYAN << "\n=== TEST ROTATE_LEFT ===\n" << RESET;

	std::vector<int> numbers_a;
	for (int i = 1; i <= 5; ++i)
		numbers_a.push_back(i); // [1, 2, 3, 4, 5]

	std::vector<int> rotated = algo::rotate_left(numbers, 2);

	std::cout << CYAN << "Original [1 2 3 4 5], rotate 2 → " << RESET;
	for (std::size_t i = 0; i < rotated.size(); ++i)
		std::cout << rotated[i] << " ";
	std::cout << "\n";

	std::vector<std::string> letters;
	letters.push_back("a");
	letters.push_back("b");
	letters.push_back("c");

	std::vector<std::string> rotated_letters = algo::rotate_left(letters, 1);

	std::cout << CYAN << "Original [a b c], rotate 1 → " << RESET;
	for (std::size_t i = 0; i < rotated_letters.size(); ++i)
		std::cout << rotated_letters[i] << " ";
	std::cout << "\n";

	std::cout << BOLD_CYAN << "\n=== TEST ROTATE_RIGHT ===\n" << RESET;

	std::vector<int> numbers_b;
	for (int i = 1; i <= 5; ++i)
		numbers_b.push_back(i); // [1, 2, 3, 4, 5]

	std::vector<int> rotated_a = algo::rotate_right(numbers_b, 2);

	std::cout << CYAN << "Original [1 2 3 4 5], rotate 2 → " << RESET;
	for (std::size_t i = 0; i < rotated_a.size(); ++i)
		std::cout << rotated_a[i] << " ";
	std::cout << "\n";

	std::vector<std::string> letters_a;
	letters_a.push_back("a");
	letters_a.push_back("b");
	letters_a.push_back("c");

	std::vector<std::string> rotated_letters_a = algo::rotate_right(letters, 1);

	std::cout << CYAN << "Original [a b c], rotate 1 → " << RESET;
	for (std::size_t i = 0; i < rotated_letters_a.size(); ++i)
		std::cout << rotated_letters_a[i] << " ";
	std::cout << "\n";

	std::cout << BOLD_CYAN << "\n=== TEST BINARY_SEARCH ===\n" << RESET;

	std::vector<int> sorted_a;
	sorted_a.push_back(1);
	sorted_a.push_back(3);
	sorted_a.push_back(5);
	sorted_a.push_back(7);
	sorted_a.push_back(9);

	std::cout << CYAN << "Recherche 5 → " << RESET
			  << (algo::binary_search(sorted_a, 5) ? GREEN "true" : RED "false") << RESET << "\n";

	std::cout << CYAN << "Recherche 8 → " << RESET
			  << (algo::binary_search(sorted_a, 8) ? GREEN "true" : RED "false") << RESET << "\n";

	std::vector<std::string> words_h;
	words_h.push_back("apple");
	words_h.push_back("banana");
	words_h.push_back("cherry");

	std::cout << CYAN << "Recherche \"banana\" → " << RESET
			  << (algo::binary_search(words_h, std::string("banana")) ? GREEN "true" : RED "false") << RESET << "\n";

	std::cout << CYAN << "Recherche \"kiwi\" → " << RESET
			  << (algo::binary_search(words_h, std::string("kiwi")) ? GREEN "true" : RED "false") << RESET << "\n";



	return (0);
}