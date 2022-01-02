#pragma once
using namespace std;
#include <iostream>
#include <Windows.h>

class dynamic_INT_array{
private:
	int UnlockSize = 1000;
public:

	void FillArray(int* const arr, const int SIZE) { //Передаем массив,с константным указателем
		for (int i = 0; i < SIZE; ++i) {
			arr[i] = rand() % 50;
		}
	}

	void ShowArray(const int* const arr, const int SIZE) { //Констаный массив
		for (int i = 0; i < SIZE; ++i) {
			cout << "Arr " << i << ": \t" << arr[i] << "\t" << arr + i << endl;
		}
	}

	void push_back(int*& arr, int& SIZE, const int value) { //Передаем указатель на ссылку,чтобы можно было изменить
		int* newArray = new int[SIZE + 1];// Создаем новый массив,с размером на 1 больше

		for (int i = 0; i < SIZE; ++i) {
			newArray[i] = arr[i]; // Заполняем его,данными прежнего массива
		}

		newArray[SIZE] = value; //К последнему элементу,добавляем вэлью
		++SIZE; //Увеличиваем размер

		delete[] arr; //Очищаем старый массив

		arr = newArray; //Передаем ссылку в наш массив,для последующей работы

	}

	void pop_back(int*& arr, int& SIZE) {
		SIZE -= 1;
		int* newArray = new int[SIZE];

		for (int i = 0; i < SIZE; ++i) {
			newArray[i] = arr[i];
		}

		delete[] arr;

		arr = newArray;

	}

	int size(const int* const arr, const int SIZE) {
		return sizeof(arr);
	}

	void push_start(int*& arr, int& SIZE, const int value) {
		int* newArray = new int[SIZE + 1];

		++SIZE;

		newArray[0] = value; //Set value in start
		for (int i = 1; i < SIZE; ++i) {
			newArray[i] = arr[i - 1]; //Fill elements
		}

		newArray[SIZE] = arr[SIZE - 1]; //Fill last element


		delete[] arr;

		arr = newArray;
	}

	void pop_start(int*& arr, int& SIZE) {
		--SIZE;
		int* newArray = new int[SIZE];

		for (int i = 1; i < SIZE; ++i) {
			newArray[i - 1] = arr[i];
		}

		newArray[SIZE - 1] = arr[SIZE];

		delete[] arr;

		arr = newArray;
	}

	void exchange(int*& arr, int& SIZE, const int value, const int num) {
		if (num >= SIZE) {
			cout << "[DA_ERROR]You num,bigger SIZE" << endl;
			exit(-1);
		}
		else {
			int* newArray = new int[SIZE];

			for (int i = 0; i < SIZE; ++i) {
				if (i == num) {
					newArray[i] = value;
				}
				else {
					newArray[i] = arr[i];
				}
			}

			delete[] arr;

			arr = newArray;
		}
	}

	void del(int*& arr, int& SIZE, const int index) {
		--SIZE;
		int* newArray = new int[SIZE];

		int n;
		for (int i = 0; i < SIZE; ++i) {
			if (i == index) {
				n = i;
			}else {
				newArray[i] = arr[i];
			}
		}
		++n;
		for (int j = n; n < SIZE + 1; ++n) {
			newArray[n - 1] = arr[n];
		}

		//newArray[SIZE] = arr[SIZE];

		delete[] arr;

		arr = newArray;
	}

	void sort(int* const arr, int SIZE){
		int temp;
		for (int i = 1; i < SIZE; ++i) {//Check element
			for (int j = 0; j < SIZE; ++j) {
				if (arr[j] > arr[i]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}

	void upsize(int*& arr, int& SIZE, const int SIZEVAL) {
		SIZE += SIZEVAL;

		int* newArray = new int[SIZE];

		for (int i = 0; i < SIZE - SIZEVAL; ++i) {
			newArray[i] = arr[i];
		}

		delete[] arr;

		arr = newArray;
	}

	void boolconv(int*& arr, int& SIZE,bool *&arrBool,int &SIZEBOOL) {
		if (SIZEBOOL > SIZE) {
			cout << "Size bool array > size INT array" << endl;
			exit(-1);
		}else {
			for (int i = 0; i < SIZE; ++i) {
				arrBool[i] = (bool)arr[i];
			}
		}
	}

	int summarize(const int* const arr, const int SIZE) {
		int sum = 0;
		for (int i = 0; i < SIZE; ++i) {
			sum += arr[i];
		}
		return sum;
	}
};

class dynamic_DOUBLE_array {
public:
	void push_back(double*& arr, int& SIZE, const double value) {
		double* newArray = new double[SIZE + 1];

		for (int i = 0; i < SIZE; ++i) {
			newArray[i] = arr[i];
		}

		newArray[SIZE] = value;
		++SIZE;

		delete[] arr;

		arr = newArray;
	}

	void pop_back(double*& arr, int& SIZE) {
		--SIZE;
		double* newArray = new double[SIZE];

		for (int i = 0; i < SIZE; ++i) {
			newArray[i] = arr[i];
		}

		delete[] arr;

		arr = newArray;
	}

	void push_start(double *&arr,int &SIZE,const int value){
		double* newArray = new double[SIZE + 1];

		++SIZE;

		newArray[0] = value;

		for (int i = 1; i < SIZE; ++i) {
			newArray[i] = arr[i - 1];
		}

		newArray[SIZE] = arr[SIZE- 1];

		delete[] arr;

		arr = newArray;
	}

	void pop_start(double*& arr, int& SIZE) {
		double* newArray = new double[SIZE];

		for (int i = 1; i < SIZE; ++i) {
			newArray[i - 1] = arr[i];
		}

		--SIZE;

		newArray[SIZE] = arr[SIZE + 1];

		delete[]arr;

		arr = newArray;

	}

	void ShowArray(const double* const arr,const int SIZE) {
		for (int i = 0; i < SIZE; ++i) {
			cout << arr[i] << endl;
		}
	}

	void exchange(double*& arr, const int SIZE, const double value, const double num) {
		if (num >= SIZE) {
			cout << "Sorry,but you num,is bigger SIZE" << endl;
			exit(-1);
		}else {
			double* newArray = new double[SIZE];
			for (int i = 0; i < SIZE; ++i) {
				if (i == num) {
					newArray[i] = value;
				}else {
					newArray[i] = arr[i];
				}
			}

			delete[]arr;

			arr = newArray;
		}
	}

	void sort(double*& arr, const int SIZE) {
		double* newArray = new double[SIZE];
		double temp;

		for (int i = 1; i < SIZE; ++i) {
			for (int j = 0; j < SIZE; ++j) {
				if (arr[i] < arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}

};