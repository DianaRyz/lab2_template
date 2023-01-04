#pragma once
#include <iostream>
template <class T>
class Set {
private:
	T* arr;
	int size;
	bool check_num(T num) {
		for (int i = 0; i < size; i++) {
			if (num == arr[i])
				return true;
		}
		return false;
	}
public:
	Set(): arr(nullptr), size(0) {}
	Set(int size): arr(new T[size]), size(size) {}
	Set(Set<T>& second) {
		size = second.size;
		arr = second.arr;
	}
	~Set() {
		if (!arr)
			delete[] arr;
	}


	T operator[](const int index) { // получение значения по индексу
		if (!arr)
			throw std::logic_error("arr == nullptr");
		if (index > size - 1 || index < 0)
			throw std::logic_error("invalide index");
		return arr[index];
	}
	Set& operator+=(T num) //добавление чзначения
	{
		if (check_num(num) == false) {
			Set res(size + 1);
			res.size = 0;
			for (int i = 0; i < size; i++) {
				res.arr[i] = arr[i];
				res.size++;
			}
			res.arr[res.size] = num;
			arr = res.arr;
			size++;
		}
		return *this;
	}
	Set operator+(const Set& second) { //объединение множеств
		Set res(size + second.size);
		res.size = 0;
		for (int i = 0; i < size; i++) {
			res.arr[i] = arr[i];
			res.size++;
		}
		for (int i = 0; i < second.size; i++) {
			if (check_num(second.arr[i]) == false)
			{
				res.arr[res.size] = second.arr[i];
				res.size++;
			}
		}
		return res;
	}
	Set operator-(const Set& second) { //разность множеств
		Set res(size);
		res.size = 0;
		bool flag = false;
		for (int i = 0; i < size; i++) {
			flag = false;
			for (int j = 0; j < second.size; j++) {
				if (arr[i] == second.arr[j])
				{
					flag = true;
					break;
				}
			}
			if (flag == false)
			{
				res.arr[res.size] = arr[i];
				res.size++;
			}
		}
		return res;
	}
	Set operator+(T num) { //добавление значения
		Set res(size + 1);
		res.size = 0;
		if (check_num(num) == false) {
			for (int i = 0; i < size; i++) {
				res.arr[i] = arr[i];
				res.size++;
			}
			res.arr[res.size] = num;
			res.size++;
		}
		return res;
	}
	Set operator-(T num) //удаление значения
	{
		Set arr_n(size);
		for (int i = 0; i < arr_n.size; i++) {
			arr_n.arr[i] = arr[i];
		}
		if (check_num(num) == true) {
			for (int i = 0; i < arr_n.size; i++) {
				if (arr_n.arr[i] == num)
				{
					for (int j = i; j < arr_n.size - 1; j++) {
						arr_n.arr[j] = arr_n.arr[j + 1];
					}
					arr_n.size--;
					break;
				}
			}
		}
		else std::cout << "Set have not got this num" << std::endl;
		return arr_n;
	}
	Set& operator-=(T num) { //удаление значения
		if (check_num(num) == true) {
			for (int i = 0; i < size; i++) {
				if (arr[i] == num)
				{
					for (int j = i; j < size - 1; j++) {
						arr[j] = arr[j + 1];
					}
					size--;
					break;
				}
			}
		}
		else std::cout << "Set have not got this num" << std::endl;
		return *this;
	}
	Set intersection(const Set& second) { //пересечение множеств
		Set res(size);
		res.size = 0;
		bool flag = false;
		for (int i = 0; i < size; i++) {
			flag = false;
			for (int j = 0; j < second.size; j++) {
				if (arr[i] == second.arr[j])
				{
					flag = true;
					break;
				}
			}
			if (flag == true)
			{
				res.arr[res.size] = arr[i];
				res.size++;
			}
		}
		return res;
	}

	bool check_count(const Set& second) { //все элементы 1 множества хотя бы раз встречаются во 2
		bool flag = false;
		for (int i = 0; i < size; i++)
		{
			flag = false;
			for (int j = 0; j < second.size; j++) {
				if (arr[i] == second.arr[j]) {
					flag = true;
					break;
				}
			}
			if (flag == false)
				return false;
		}
		return true;
	}

	bool operator==(const Set& second) { //равенство множеств
		if (second.size != size)
			return false;
		else
		{
			bool flag = false; 
			for (int i = 0; i < size; i++)
			{
				flag = false;
				for (int j = 0; j < second.size; j++) {
					if (arr[i] == second.arr[j]) {
						flag = true;
						break;
					}
				}
				if (flag == false)
					return false;
			}
			return true;
		}
	}

	bool operator!=(const Set& second) { //неравенство
		if (second.size != size)
			return true;
		else
		{
			bool flag = true; 
			for (int i = 0; i < size; i++)
			{
				flag = true;
				for (int j = 0; j < second.size; j++) {
					if (arr[i] == second.arr[j]) {
						flag = false;
						break;
					}
				}
				if (flag == true)
					return true;
			}
			return false;
		}
	}
	friend std::ostream& operator<<(std::ostream& s, const Set<T>& set) 
	{
		for (int i = 0; i < set.size; i++) {
			s << set.arr[i] << "  ";
		}
		return s;
	}
};