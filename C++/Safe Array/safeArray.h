#pragma once
#include "safeArrayOutOfBundsException.h"

template<class T>
class SafeArray
{
private:
	T* arr;
	int size;
public:
	SafeArray(int size) :size(size)
	{
		arr = new T[size];
	}
	~SafeArray()
	{
		delete[] arr;
	}

	int getSize()
	{
		return size;
	}

	T &operator[](int idx)
	{
		if (idx > this->size)
		{
			throw SafeArrayOutOfBundsException();
		}
		return arr[idx];
	}
};

