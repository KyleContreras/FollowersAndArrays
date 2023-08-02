#pragma once

template <class T>
class Array
{
	public:
		// Constructor
		Array(int size);

		// Destructor
		~Array();

		// Changes the size of the followers array
		void changeSize(double size);

		// Returns ptrToFollowers
		T*& getPtr();

		// Returns current array size
		double& getCurrentCapacity();

		// Return lastIndex
		int& getIndex();


	private:
		T* ptrToFollowers;	 // pointer to array
		double capacity;		 // current array length
		int lastIndex;
};

template<class T>
inline Array<T>::Array(int size)
{
	capacity = 2;
	lastIndex = -1;
	ptrToFollowers = new T[capacity];
}

template<class T>
inline Array<T>::~Array()
{
	delete[] ptrToFollowers;
}

template<class T>
inline void Array<T>::changeSize(double size)
{
	int oldCap = capacity;
	int capToUse;
	capacity *= size;

	if (size == 2.0)
	{
		capToUse = oldCap;
	}
	else if (size == 0.5)
	{
		capToUse = capacity;
	}

	T* tempArray = new T[capacity];
	int index = this->getIndex();
	

	for (int i = 0; i < capToUse; i++)
	{
		tempArray[i] = ptrToFollowers[i];
	}

	delete[] ptrToFollowers;
	
	ptrToFollowers = tempArray;
}

template<class T>
inline T*& Array<T>::getPtr()
{
	return ptrToFollowers;
}

template<class T>
inline double& Array<T>::getCurrentCapacity()
{
	return capacity;
}

template<class T>
inline int& Array<T>::getIndex()
{
	return lastIndex;
}