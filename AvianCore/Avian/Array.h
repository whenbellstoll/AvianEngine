#ifndef _ARRAY_H_
#define _ARRAY_H_

template <class T>
class Array
{
	T * ar;
	unsigned int capacity;
	unsigned int numberOfElements;
    void Alloc();
	void Free();
    void Realloc();

public:
	Array();
    Array(const Array & a);
	~Array();
	void InsertBack(T m);
    void RemoveBack();
	unsigned int NumberOfElements();
	unsigned int Capacity();
	void Resize(unsigned int newCapacity);
	void SetAllTo(T m);
	void Clear();
	T & operator[](unsigned int i);
	Array & operator=(const Array & a);
};

const int C = 10; 

template <class T>
void Array<T>::Alloc()
{
	ar = new T[capacity];
}

template <class T>
void Array<T>::Free()
{
	delete[] ar;
	ar = nullptr;
}

template <class T>
void Array<T>::Realloc()
{
	T * temp = new T[capacity]; 
	if(capacity < numberOfElements)
		numberOfElements = capacity;
	for(unsigned int i =0;i<numberOfElements;i++)
		temp[i]=ar[i];
	Free();
	ar = temp;
}

template <class T>
Array<T>::Array()
{
	capacity = C;
	numberOfElements = 0; 
	Alloc();
}

	
template <class T>
Array<T>::Array(const Array & a)
{
	numberOfElements = a.numberOfElements;
	capacity = a.capacity;
	Alloc();
	for(unsigned int i=0;i<numberOfElements;i++)
		ar[i] = a.ar[i]; 
}

template <class T>
Array<T>::~Array()
{
	Free();
}

template <class T>
void Array<T>::InsertBack(T m)
{
	if (numberOfElements == capacity)
	{
		capacity+=C;
		Realloc();
	}
	ar[numberOfElements] = m;
	numberOfElements++;
}

template <class T>
void Array<T>::RemoveBack()
{
	if(numberOfElements > 0)
		numberOfElements--;
}

template <class T>
unsigned int Array<T>::NumberOfElements()
{
	return numberOfElements;
}

template <class T>
unsigned int Array<T>::Capacity()
{
	return capacity;
}

template <class T>
void Array<T>::Resize(unsigned int newCapacity)
{
	if(newCapacity > 0)
	{
		capacity = newCapacity;
		Realloc();
	}
}

template <class T>
void Array<T>::SetAllTo(T m)
{
	for(unsigned int i=0;i<numberOfElements;i++)
		ar[i] = m;
}

template <class T>
void Array<T>::Clear()
{
	Free();
	capacity = C;
	numberOfElements = 0;
	Alloc();
}

template <class T>
T & Array<T>::operator[](unsigned int i)
{
	return ar[i];
}

template <class T>
Array<T> & Array<T>::operator=(const Array<T> & a)
{
		Free();
		numberOfElements = a.numberOfElements;
		capacity = a.capacity;
		Alloc();
		for(unsigned int i=0;i<numberOfElements;i++)
			ar[i] = a.ar[i]; 

		return *this;
		
}

#endif


