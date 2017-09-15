#include <iostream>
#include <time.h>
#include "Array.h"

using namespace std;




void Array::Insert_sort(long long int begin, long long int end)
{

	for (int i = 0; i < size; i++) {
		int temp = Arr[i];
		int j = i - 1;
		while (j >= 0 && Arr[j] > temp)
		{
			Arr[j + 1] = Arr[j];
			j--;
		}
		Arr[j + 1] = temp;
	}
}




void Array::Bubble_sort( long long int end)
{
	for (int i = 0; i < end - 1; ++i) {
		for (int j = 0; j < end - i - 1; ++j) {
			if (Arr[j] > Arr[j + 1]) {
				swap(Arr[j], Arr[j + 1]);
			}
		}
	}
}





void Array::Quiq_sort(long long int begin, long long int end)
{
	long long int left = begin, right = end, m = Arr[int((right + left) / 2)];

	while (left <= right)
	{
		while (Arr[left] < m) left++;
		while (Arr[right] > m) right--;
		if (left <= right) swap(Arr[left++], Arr[right--]);
	}
	if (left < end) Quiq_sort( left, end);
	if (right > begin) Quiq_sort( begin, right);

}


void Array::Merge_sort(long long int begin, long long int end)
{
	if (end <= begin)
		return;
	long long int ser = (begin + end) / 2;
	Merge_sort( begin, ser);
	Merge_sort( ser + 1, end);

	long long int *new_a = new long long int[100000];

	for (long long k = begin; k <= end; k++)
		new_a[k] = Arr[k];

	long long i = begin, j = ser + 1;
	for (long long k = begin; k <= end; k++) {

		if (i > ser) {
			Arr[k] = new_a[j];
			j++;
		}
		else if (j > end) {
			Arr[k] = new_a[i];
			i++;
		}
		else if (new_a[j] < new_a[i]) {
			Arr[k] = new_a[j];
			j++;
		}
		else {
			Arr[k] = new_a[i];
			i++;
		}
	}
	delete[] new_a;
}

void Heapily(long long int *Arr, long long int father, long long int size)
{
	if (2 * father + 1 < size)
	{
		long long int son = 2 * father + 1; //ïåðøèé ñèí
		if (2 * father + 2 < size && Arr[2 * father + 2] >= Arr[son]) // äðóãèé ñèí, ÿêùî ³ñíóº ³ á³ëüøèé çà ïåðøîãî
		{
			son = 2 * father + 2;
		}
		if (Arr[father] < Arr[son]) //íàéá³ëüøèé ñèí³â á³ëüøèé çà áàòüêà
		{
			swap(Arr[father], Arr[son]);


		}

		return Heapily(Arr, son, size);  //ïðåäîê íàñòóïíèé åëåìåíò

	}
}

void Array::Heap_sort()
{
	long long int i;
	for (i = size - 1; i >= 0; --i)
		Heapily(Arr, i, size);
	for (i = size - 1; i >= 0; --i)
	{
		swap(Arr[0], Arr[i]);
		Heapily(Arr, 0, i);

	}
}


Array::Array(long long int _size_)
{
	 size = _size_;
	 Arr = new long long int[size];

	 srand(time(NULL));
	 for (int i = 0; i < size; Arr[i++] = rand() % 1000000 - 20000);
}

Array::~Array()
{
	delete[] Arr;
}

void Array::Print() const
{
	for (int i = 0; i < size; cout << Arr[i] << "  ", ++i); cout << "\n\n";
}
