/*
C. Gaines
Pprogram that supports the operations of union, difference, and cardinality between two arrays (SetA and SetB)
*/

#include <iostream>
#include <algorithm>

using namespace std;

int getSetSize(int& m, int& n);
void buildSet(char arr1[], char arr2[], int m, int n);
void printSets(char arr1[], char arr2[], int m, int n);
void printUnion(char arr1[], char arr2[], int m, int n);
int binarySearch(char arr[], int l, int r, int x);
void difference(char arr1[], char arr2[], int m, int n);
void difference2(char arr1[], char arr2[], int m, int n);


int main()
{
	char arr1[100];
	char arr2[100];

	int m = sizeof(arr1) / sizeof(arr1[0]);
	int n = sizeof(arr2) / sizeof(arr2[0]);

	getSetSize(m, n);
	buildSet(arr1, arr2, m, n);

	printSets(arr1, arr2, m, n);

	cout << endl << "THE UNION SET IS (AUB): ";
	printUnion(arr1, arr2, m, n);
	cout << endl;

	cout << "THE DIFFERENCE IS (A-B): ";
	difference(arr1, arr2, m, n);
	cout << endl;

	cout << "THE DIFFERENCE IS (B-A): ";
	difference2(arr1, arr2, m, n);
	cout << endl;

	system("pause");
	return 0;
}

int getSetSize(int& m, int& n)
{//Prompts the user for the size of the Array sets they would like to build

	cout << "PLEASE ENTER THE SIZE OF SET A: ";
	cin >> m;

	while (m < 0 || m > 15)
	{
		cout << "YOU HAVE ENTERED AN INVALID NUMBER." << endl << "PLEASE ENTER A NUMBER BETWEEN 0-15: ";
		cin >> m;
		cout << endl;
	}

	cout << "PLEASE ENTER THE SIZE OF SET B: ";
	cin >> n;

	while (n < 0 || n > 15)
	{
		cout << "YOU HAVE ENTERED AN INVALID NUMBER." << endl << "PLEASE ENTER A NUMBER BETWEEN 0-15: ";
		cin >> n;
		cout << endl;
	}

	return m, n;
}
void buildSet(char arr1[], char arr2[], int m, int n)
{//Prompts the user for elements to be placed into the sets

	cout << endl << "PLEASE ENTER THE CHARACTERS OF SET A: ";

	for (int i = 0; i < m; i++)
	{
		cin >> arr1[i];
	}

	cout << endl << "PLEASE ENTER THE CHARACTERS OF SET B: ";

	for (int i = 0; i < n; i++)
	{
		cin >> arr2[i];
	}
}

void printSets(char arr1[], char arr2[], int m, int n)
{//Prints the original user created sets

	cout << endl << "SET A: ";
	for (int i = 0; i < m; i++)
	{
		cout << arr1[i] << " ";
	}

	cout << endl << "SET B: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr2[i] << " ";
	}

	cout << endl;
}

void printUnion(char arr1[], char arr2[], int m, int n)
{//Finds and prints the union of arr1 and arr2

	int count = 0;

	if (m > n) // Before finding union, make sure arr1 is smaller
	{
		char* tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}

	sort(arr1, arr1 + m); // Sort the first array

	for (int i = 0; i < m; i++)
	{
		cout << arr1[i] << " "; //Print array elements
		count++; //count array elements
	}

	for (int i = 0; i < n; i++)
	{
		if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1) //Search every element of bigger array in smaller array and print the element if not found
		{
			cout << arr2[i] << " ";
			count++;
		}
	}

	if (count == 0) //Cardinality output
		cout << endl << "THE SET IS EMPTY" << endl;

	else
		cout << endl << "THE CARDINALITY OF THE UNION SET IS: | " << count << " |" << endl;
}

int binarySearch(char arr[], int l, int r, int x)
{//Recursive binary Search function used to sort the arrays, returns location of x, otherwise -1

	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)  return mid; //If the element is present at the middle

		if (arr[mid] > x) //If element is smaller than the middle, then it can only be present in left array
			return binarySearch(arr, l, mid - 1, x);

		return binarySearch(arr, mid + 1, r, x); //Else the element can only be present in right subarray
	}

	return -1; //When the element is not present in the array
}

void difference(char arr1[], char arr2[], int m, int n)
{//Finds the differnce of the sets

	int count = 0;

	if (m > n)
	{
		char* tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}

	sort(arr1, arr1 + m); //Sort both arrays
	sort(arr2, arr2 + n);

	for (int j = 0; j < m; j++)
	{
		if (binarySearch(arr2, 0, n - 1, arr1[j]) == -1) //Search every element of second array and print if not found
		{
			cout << arr1[j] << " ";
			count++;
		}

	}

	if (count == 0) //Cardinality output
		cout << endl << "THE SET IS EMPTY" << endl;

	else
		cout << endl << "THE CARDINALITY OF THE DIFFERENCE SET IS: | " << count << " |" << endl;
}

void difference2(char arr1[], char arr2[], int m, int n)
{//Finds the difference of (opposite of first difference function)
	int count = 0;

	if (m > n)
	{
		char* tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = m;
		m = n;
		n = temp;
	}

	sort(arr1, arr1 + m);
	sort(arr2, arr2 + n);

	for (int i = 0; i < n; i++)
	{
		if (binarySearch(arr1, 0, m - 1, arr2[i]) == -1)
		{
			cout << arr2[i] << " ";
			count++;
		}
	}

	if (count == 0)
		cout << endl << "THE SET IS EMPTY" << endl;

	else
		cout << endl << "THE CARDINALITY OF THE DIFFERENCE SET IS: | " << count << " |" << endl;
}
