
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream fin("in.txt");
	std::ofstream fon("out.txt");
	int length1 = 0;
	int length2 = 0;
	int num = 0;

	fin >> length1;
	int* arr1 = new int[length1];
	for (int i = 0; i < length1; ++i) {
		fin >> arr1[i];
	}

	if (length1 > 1) {
		int last = arr1[0];
		for (int i = 0; i < length1; ++i) {
			arr1[i] = arr1[i + 1];
		}
		arr1[length1 - 1] = last;
	}

	fin >> length2;
	int* arr2 = new int[length2];
	for (int i = 0; i < length2; ++i) {
		fin >> arr2[i];
	}
	
	if (length2 > 1) {
		int last = arr2[length2 - 1];
		for (int i = length2 - 1; i > 0; --i) {
			arr2[i] = arr2[i - 1];
		}
		arr2[0] = last;
	}


	fon << length2 << "\n";
	for (int i = 0; i < length2; ++i) {
		fon << arr2[i]<<( i < length2-1? " " : "\n" );
	}
	fon << length1 << "\n";
	for (int i = 0; i < length1; ++i) {
		fon << arr1[i]<< (i < length1 - 1 ? " " : "\n");
	}

	delete[] arr1;
	delete[] arr2;
	fin.close();
	fon.close();
}

