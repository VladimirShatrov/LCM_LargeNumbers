#include <iostream>
#include <string>
#include <vector>


using namespace std;


void from_string_to_array(string a, long long int* array)
{
	string sub_string;
	int j;
	int pos = 0;
	for (int i = a.size() - 9; i >= 0; i -= 9)
	{
		sub_string = "";
		j = 0;
		while ((j <= 8) and (i + j < a.size())) // формируем подстроку из 9 символов
		{
			sub_string += a[i + j];
			j++;
		}
		array[pos] = atoi(sub_string.c_str());
		pos++;
	}
	if (a.size() % 9 != 0) // если полседн€€ подстрока менье 9 символов дописывем нули
	{
		sub_string = "";
		for (int i = 0; i < a.size() % 9; i++)
			sub_string += a[i];
		array[pos] = atoi(sub_string.c_str());
	}
}


long long int* multiplay_longNumbers(long long int* a, long long int* b, int len)
{
	long long int* result = new long long int[2 * len]; // макс. длина произведени€ = сумме длинн чисел 
	for (int i = 0; i < 2 * len; i++)
		result[i] = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			result[(i + j)] += a[i] * b[j];
		}
	return result;
}


long long int* sum_longNumbers(long long int* a, long long int* b, int len)
{
	
	long long int* result = new long long int[len + 1]; // макс длина суммы = длина макс слагаемого + 1
	for (int i = 0; i < len + 1; i++)
		result[i] = 0;
	int ost = 0;
	for (int i = 0; i < len; i++)
	{
		result[i] = (a[i] + b[i]) % 1000000000 + ost;
		ost = (a[i] + b[i]) / 1000000000;
	}
	return result;
}


long long int* subtraction_longNumbers(long long int* a, long long int* b, int len)
{
	int is_a_eq_b = 1;
	for (int i = len - 1; i >= 0; i--)
	{
		if (a[i] > b[i])
		{
			is_a_eq_b = 0;
			break;
		}

	}

	long long int* result = new long long int[len];
	for (int i = 0; i < len; i++)
		result[i] = 0;

	if (is_a_eq_b) // если a = b возвращаем 0
		return result;
	for (int i = 0; i < len; i++)
	{
		result[i] = a[i] - b[i];
		if (result[i] < 0)
		{
			result[i] += 1000000000;
			a[i + 1]--;
		}
	}
	return result;
}


bool a_larger_b(long long int* a, long long int* b, int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		if (a[i] > b[i])
			return true;
		else
			if (a[i] < b[i])
				return false;
	}
	return false; // если a = b
}


bool a_larger_or_equal_b_oneElement_oneNumber(int* a, int* b)
{
	int len_a = sizeof(a) - sizeof(a[0]);
	int len_b = sizeof(b) - sizeof(b[0]);
	if (len_a > len_b)
		return true;
	else
		if (len_a < len_b)
			return false;
	for (int i = 0; i < len_a; i++)
	{
		if (a[i] < b[i])
			return false;
	}
	return true;
}


/*long long int* mod(long long int* a, long long int* b, int len)
{

}
*/

long long int* divide_longNumbers(long long int* a, long long int* b, int len)
{
	long long int* result = new long long int[9 * len];
	for (int i = 0; i < len; i++)
		result[i] = 0;
	string a_copy, b_copy; // € не придумал как реализовать деление дл€ массивов с элементами - 9 значнами числами, поэтому перезаписываем их в вектора по одной цифре в один элемент
	for (int i = 0; i < len; i++)
	{
		a_copy = to_string(a[i]) + a_copy;
		b_copy = to_string(b[i]) + b_copy;
	}
	int size_a = a_copy.size();
	int size_b = b_copy.size();
	bool neznach_zeros = true;
	int i = 0, i_max = 0;
	while (neznach_zeros)
	{
		if (a_copy[i] != 0)
			neznach_zeros = false;
		else
		{
			i_max = i;
			i++;
		}
	}
	int* a_one_number_one_element = new int[size_a - i_max];
	for (int j = i_max + 1; j <= size_a - i_max; j++)
		a_one_number_one_element[j - i_max - 1] = a_copy[j];
	neznach_zeros = true;
	i = 0, i_max = 0;
	while (neznach_zeros)
	{
		if (b_copy[i] != 0)
			neznach_zeros = false;
		else
		{
			i_max = i;
			i++;
		}
	}
	int* b_one_number_one_element = new int[size_b - i_max];
	for (int j = i_max + 1; j <= size_a - i_max; j++)
		b_one_number_one_element[j - i_max - 1] = b_copy[j];
	//теперь само деление
	int* temp = new int[size_b - i_max];
	while (a_larger_or_equal_b_oneElement_oneNumber(a_one_number_one_element, b_one_number_one_element)) // while (a >= b)
	{
		for (i = 0; i < size_b - i_max; i++)
			temp[i] = a_one_number_one_element[i];
		int k = 0;
		if (!a_larger_or_equal_b_oneElement_oneNumber(temp, b_one_number_one_element))
			temp[i + 1] = a_one_number_one_element[i + 1];
		while (a_larger_or_equal_b_oneElement_oneNumber(temp, b_one_number_one_element))
		{
			
		}
	}
}



/*long long int* greatest_common_divisor(long long int* n, long long int* m)
{

}


string NOK(long long int* n, long long int* m, long long int* nod)
{

}*/
