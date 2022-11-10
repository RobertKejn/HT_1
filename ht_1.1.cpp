
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ifstream fin("in.txt");
	std::ofstream fon("out.txt");
	int length1 = 0;
	int length2 = 0;
	int num = 0;

	if (fin.is_open()) {
		fin >> length1;
		int* arr1 = new int[length1];
		if (length1 > 0) {
			for (int i = 0; i < length1; ++i) {
				fin >> arr1[i];
			}
			int last = arr1[0];
			for (int i = 0; i < length1; ++i) {
				arr1[i] = arr1[i + 1];
			}
			arr1[length1 - 1] = last;
		}
		else {
			std::string s;
			std::getline(fin, s);
			std::getline(fin, s);
		}

		fin >> length2;
		int* arr2 = new int[length2];
		if (length2 > 0) {
			for (int i = 0; i < length2; ++i) {
				fin >> arr2[i];
			}
			int last = arr2[length2 - 1];
			for (int i = length2 - 1; i > 0; --i) {
				arr2[i] = arr2[i - 1];
			}
			arr2[0] = last;
		}

		if (length2 > 0) {
			fon << length2 << "\n";
			for (int i = 0; i < length2; ++i) {
				fon << arr2[i] << (i < length2 - 1 ? " " : "\n");
			}
		}
		else {
			fon << "количество символов 2 массива равно 0\n";
		}
		if (length1 > 0) {
			fon << length1 << "\n";
			for (int i = 0; i < length1; ++i) {
				fon << arr1[i] << (i < length1 - 1 ? " " : "\n");
			}
		}
		else {
			fon << "количество символов 1 массива равно 0\n";
		}

		delete[] arr1;
		delete[] arr2;
		fin.close();
	}
	else {
		fon << "Не удалось открыть файл in.txt";
	}
	fon.close();

}

