#include "safeArray.h"
#include "safeArrayOutOfBundsException.h"
template < typename T > class SafePointer
{
private:
	SafeArray<T>& arr;
	T*    pData; // Generic pointer to be stored
	#define	START &(arr[0])
	#define	END &(arr[arr.getSize()-1])
public:
	SafePointer(SafeArray<T>& arr, T* pValue) : arr(arr),pData(pValue)
	{
		
	}
	~SafePointer()
	{
	}

	T& operator* ()
	{
		return *pData;
	}

	T* operator-> ()
	{
		return pData;
	}
	SafePointer operator+(const SafePointer& f) const
	{
		if (this->pData + f.pData > END)
		{
			throw SafeArrayOutOfBundsException();
		}
		return SafePointer(arr, this->pData + f.pData);
	}
	SafePointer operator-(const SafePointer& f) const
	{
		if (this->pData - f.pData < START)
		{
			throw SafeArrayOutOfBundsException();
		}
		return SafePointer(arr, this->pData - f.pData);
	}
	SafePointer& operator++()
	{
		if (pData==END)
		{
			throw SafeArrayOutOfBundsException();
		}
		pData++;
		return *this;
	}
	SafePointer& operator--()
	{
		if (pData == START)
		{
			throw SafeArrayOutOfBundsException();
		}
		pData--;
		return *this;
	}
};
