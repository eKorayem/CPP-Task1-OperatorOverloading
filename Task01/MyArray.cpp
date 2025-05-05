#include "MyArray.h"

MyArray::MyArray(int size)
{
	this->size = size;
	arr = new int[size];
	fill(arr, arr + size, 0);
}

MyArray::MyArray(const MyArray& arr2)
{
	size = arr2.size;
	arr = new int[size];
	copy(arr2.arr, arr2.arr + size, arr);
}

MyArray::MyArray()
{
	size = 10;
	arr = new int[size];
}

int MyArray::get_size()
{
	return size;
}

int& MyArray::operator[](int index)
{
	if (index < 0 || index >= size)
		throw out_of_range("Index out of bounds");
	else
		return arr[index];
	
}

MyArray MyArray::operator=(const MyArray& arr2)
{
	if (this != &arr2) {
		delete[] arr;
		size = arr2.size;
		arr = new int[size];
		copy(arr2.arr, arr2.arr + size, arr);
	}

	return *this;
}

MyArray MyArray::operator+(MyArray& arr2)
{
	MyArray resArray(size + arr2.size);

	for (int i = 0; i != size; ++i)
		resArray[i] = arr[i];

	for (int i = 0; i != arr2.size; ++i)
		resArray[i + size] = arr2[i]; 

	return resArray;
}

bool find_v(int* arr, int s, int v) {
	for (int i = 0; i != s; ++i) {
		if (v == arr[i]) return true;
	}
	return false;
}

MyArray MyArray::operator-(MyArray& arr2)
{
	
	int* tempArr = new int[size];
	int ss = size;
	int curr_pos = 0;
	for (int i = 0; i != size; ++i) {
		if (!find_v(arr2.arr, arr2.size, arr[i])) {
			tempArr[curr_pos] = arr[i];
			curr_pos++;
		}
	}

	MyArray resArray(curr_pos);
	copy(tempArr, tempArr + curr_pos, resArray.arr);
	delete[] tempArr;




	return resArray;

}

MyArray MyArray::operator*(int n)
{
	MyArray arr2(size);
	for (int i = 0; i != size; i++) {
		arr2.arr[i] = arr[i] * n;
	}
	return arr2;
}

bool MyArray::reallocate(int newSize)
{
	if (newSize <= size) {
		cout << "New size is less then or equal to the old size\n";
		return false;
	}
	int* newArr = new int[newSize];
	fill(newArr, newArr + newSize, 0);


	copy(arr, arr + size, newArr);
	//delete[] newArr;

	this->arr = newArr;

	size = newSize;

	return true;
}

bool MyArray::read_values()
{
	int insertedVals;
	cout << "\nEnter number of values you will insert: ";
	cin >> insertedVals;
	if (insertedVals > size) {
		cout << "values can't be inserted, array capacity is " << size;
		return false;
	}
	cout << "Enter Array elements: ";
	for (int i = 0; i != insertedVals; ++i) {
		cin >> arr[i];
	}
	return true;
}

MyArray::~MyArray()
{
	delete[] arr;
}




