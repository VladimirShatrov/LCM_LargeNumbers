#include <iostream>


using namespace std;


void from_string_to_array(string a, int* array)
{
	string sub_string;
	int j ;
	int pos = 0;
	for (int i = a.size() - 10; i >= 0; i -= 9)
	{
		sub_string = "";
		j = 1;
		while ((j <= 9) and (i + j < a.size())) // ��������� ��������� �� 9 ��������
		{
			sub_string += a[i + j];
			j++;
		}
		array[pos] = atoi(sub_string.c_str());
		pos++;
	}
	if (a.size() % 9 != 0) // ���� ��������� ��������� ����� 9 �������� ��������� ����
	{
		sub_string = "";
		for (int i = 0; i < a.size() % 9; i++)
			sub_string += a[i];
		array[pos] = atoi(sub_string.c_str());
	}
}


/*int* multiplay_longNumbers(int* a, int* b, int c, int d) // c - ������ � ,d - ������ b
{
	// a * b = a0 * b0 + ((a0 + a1) * (b0 + b1) - a0 * b0 - a1 * b1) * 10^m + a1 * b1 * 10^2m
	int m = max(c, d) / 2 + (max(c, d) % 2); // m - ���-�� ��������� � a0 a1 b0 b1, ���� max(sizeof(a), sizeof(b)) ��������, �� � a1 b1 ����� ������ ���� ���������� ����
	
	int* a0 = new int[m];
	int* a1 = new int[m];
	int* b0 = new int[m];
	int* b1 = new int[m];

	for (int i = 0; i < m; i++)
		a0[i] = a[i + m - (max(c, d) % 2)];
	for (int i = max(c, d) - c + (max(c, d) % 2); i < m; i++) // ���� b > a � a1 ����� sizeof(b) - sizeof(a) ������. ����� � ���� a >= b, �� sizeof(a) % 2 == 1 � a1 ����� 1 ������ ����
		a1[i] = a[i - (max(c, d) % 2) - (max(c, d) - c)];
	for (int i = 0; i < m; i++)
		b0[i] = b[i + m - (max(c, d) % 2)];
	for (int i = max(c, d) - c + (max(c, d) % 2); i < m; i++)
		b1[i] = b[i - (max(c, d) % 2) - (max(c, d) - d)];

	int* result = new int[c + d]; // ����. ����� ������������ = ����� ����� ����� 
	





	delete[]a0;
	delete[]a1;
	delete[]b0;
	delete[]b1;
}*/


int* sum_longNumbers(int* a, int* b, int len_a, int len_b)
{
	
	int* result = new int[max(len_a, len_b) + 1];
	int ost = 0;
	if (a[max(len_a, len_b)] < 0)
		a[max(len_a, len_b)] = 0;
	if (b[max(len_a, len_b)] < 0)
		b[max(len_a, len_b)] = 0;
	for (int i = 0; i < max(len_a, len_b) + 1; i++)
	{
		result[i] = (a[i] + b[i]) % 1000000000 + ost;
		ost = (a[i] + b[i]) / 1000000000;
	}
	return result;
}


/*int* subtraction_longNumbers(int* a, int* b)
{

}


int* NOD(int* n, int* m)
{

}


string NOK(int* n, int* m, int* nod)
{

}
*/