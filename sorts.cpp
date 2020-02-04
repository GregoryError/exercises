// 	 sorts.cpp
//
//	 General sorting algorithms 
//
#include <iostream>
#include <algorithm>
#include <ctime>

template <class Item>
void exch(Item& A, Item& B)
{
	Item t = A;
	A = B;
	B = t;
}

// Bubble sort
template <class Item>
void bubbleSort(Item a[], int l, int r)
{
	for (int i = l; i < r; ++i)
		for (int j = r - 1; j > i; --j)
			if (a[j] < a[i])
				exch(a[j], a[i]);
}

// Selection sort
template <class Item>
void selectionSort(Item a[], int l, int r)
{
	for (int i = l; i < r; ++i)
		for (int j = i + 1; j < r; ++j)
			if (a[j] < a[i])
				exch(a[j], a[i]);
}

// Insertion sort
template <class Item>
void insertionSort(Item a[], int l, int r)
{
	for (int i = r - 1; i > l; --i)
		if (a[i] < a[i - 1])
			exch(a[i], a[i - 1]);
	for (int i = l + 2; i < r; ++i)
	{
		int j = i; 
		Item v = a[i];
		while (v < a[j - 1])
		{
			a[j] = a[j - 1];
			--j;
		}
		a[j] = v;
	}
}

// Shell sort
template <class Item>
void shellSort(Item a[], int l, int r)
{
	int h; 
	for (h = l + 1; h < (r - l) / 9; h = 3 * h + 1) ;
	for (; h > 0; h /= 3)
		for (int i = l + h; i < r; ++i)
		{
			int j = i;
			Item v = a[i];
			while (l + h <= j && v < a[j - h])
			{
				a[j] = a[j - h];
				j -= h;
			}
			a[j] = v;
		}
}

// Quick sort

template <class Item>
int separate(Item a[], int l, int r)
{
	int i = l - 1;
	int j = r;
	Item v = a[r];
	for (;;)
	{
		while (v > a[++i]) ;
		while (v < a[--j]) if (i == j) break;
		if (i >= j) break;
		exch(a[i], a[j]);
	}	
	exch(a[i], a[r]);
	return i;
}

template <class Item>
void quickSort(Item a[], int l, int r)
{
	if (r <= l) return;
	int i = separate(a, l, r);
	quickSort(a, l, i - 1);
	quickSort(a, i + 1, r);
}

int main(int argc, char* argv[])
{
	std::srand(std::time(0));
	const std::size_t N = 20;
	int arr[N];
	std::generate(std::begin(arr), std::end(arr), [](){ return std::rand() % 100; });
	std::cout << "Before:\n";
	for (const auto& v : arr)
		std::cout << v << " ";
	std::cout << "\nAfter:\n";
	
//	bubbleSort(arr, 0, N);
//	selectionSort(arr, 0, N);
//	insertionSort(arr, 0, N);
//	shellSort(arr, 0, N);
	quickSort(arr, 0, N - 1);

	for (const auto& v : arr)
		std::cout << v << " ";



	return 0;
}







