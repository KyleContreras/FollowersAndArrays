#pragma once

#include "Array.h"

template <typename T>
class Twitter
{
public:
	// TODO: Constructor
	Twitter();

	void AddFollower(T& follower);

	void RemoveFollower(T& follower);

	void PrintFollower();

private:
	T username;
	int numFollowers = 0;
	Array<T> followers;
};
