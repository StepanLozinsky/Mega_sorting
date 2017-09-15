#pragma once
#include <iostream>

using namespace std;

class Array
{
  private:

	  long long int size;
	  long long int *Arr;

  public:
	Array(long long int _size_);
	void Bubble_sort(long long int end);
	void Quiq_sort(long long int begin, long long int end);
	void Merge_sort(long long int begin, long long int end);
	void Insert_sort(long long int begin, long long int end);
	void Heap_sort();
	void Print() const;
	~Array();


};

