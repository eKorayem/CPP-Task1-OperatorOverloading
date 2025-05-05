#include <iostream>
#include <algorithm>
using namespace std;
#pragma once
class MyArray
{
private:
	int size;
	int *arr;
public:
	MyArray(int size);
	MyArray(const MyArray& arr2);
	MyArray();
	int get_size();
	
	int& operator[] (int index);

	MyArray operator=(const MyArray& arr);
	
	friend ostream& operator<<(ostream& out, MyArray& arr) {
		out << "Array Elements: [";
		for (int i = 0; i != arr.size; ++i) {
			out << arr[i] << (i == arr.size - 1 ? "]\n" : ", ");
		}
		return out;
	}
	
	MyArray operator+(MyArray& arr2);

	MyArray operator-(MyArray& arr2);

	MyArray operator*(int n);

	bool reallocate(int newSize);

	bool read_values();

	~MyArray();

};

