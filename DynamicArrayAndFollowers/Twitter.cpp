#include <iostream>
#include "Twitter.h"

using namespace std;

template<typename T>
Twitter<T>::Twitter()
	: followers(2)
{
}


template<typename T>
void Twitter<T>::AddFollower(T& follower)
{
	T*& tempPtr = this->followers.getPtr();
	double currentCap = this->followers.getCurrentCapacity();
	int& index = this->followers.getIndex();
	
	index += 1;
	this->numFollowers += 1;

	// Check Array capacity
	if (this->numFollowers == currentCap)
	{
		this->followers.changeSize(2.0);	  //Double size
	}
	else if ((this->numFollowers / currentCap) < 0.25)
	{
		this->followers.changeSize(0.5);  //Half the size
	}

	tempPtr[index] = follower;

	this->PrintFollower();
}


template<typename T>
void Twitter<T>::RemoveFollower(T& follower)
{
	T*& tempPtr = this->followers.getPtr();						// Reference to the User's followers
	double& currentCap = this->followers.getCurrentCapacity();	// Current max capacity of followers list
	T* tempArray = new T[currentCap];							// Temporary array to store the followers
	int counter = 0;											// A second counter variable
	int& index = this->followers.getIndex();
	
	index -= 1;
	this->numFollowers -= 1;

	// Check Array capacity
	if (this->numFollowers == currentCap)
	{
		this->followers.changeSize(2.0);	  //Double size
	}
	else if ((this->numFollowers / currentCap) < 0.25 && this->numFollowers != 0)
	{
		this->followers.changeSize(0.5);	  //Half the size
	}

	// Transfer everything but the item to be deleted, to tempArray
	for (int i = 0; i < currentCap; i++)
	{
		if (!(tempPtr[i] == follower))
		{
			tempArray[counter] = tempPtr[i];	// Use a second counter variable to stagger the indices, if necessary

			counter++;
		}
	}

	// Transfer the "new" array back to tempPtr
	for (int i = 0; i < currentCap; i++)
	{
		tempPtr[i] = tempArray[i];
	}

	delete[] tempArray;
	tempArray = NULL;

	this->PrintFollower();
}


// Print user's follower list
template<typename T>
void Twitter<T>::PrintFollower()
{
	T*& tempPtr = this->followers.getPtr();
	int cap = this->followers.getCurrentCapacity();

	for (int i = 0; i < this->numFollowers; i++)
	{
		cout << tempPtr[i] << endl;
	}
}