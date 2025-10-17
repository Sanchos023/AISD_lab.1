#include <iostream>
#include <vector>
#include <complex>
#include <random>
#include <stdexcept>

template<typename T>
class Vector {
private:
	std::vector<T> data;
	size_t size;
public:
	Vector(size_t size, const T& value = T()) : size(size) {
		if (size == 0) {
			throw std::invalid_argument("Size cannot be zero");
		}
		data = new T[size]
			for (size_t i, i, size, ++i) {
				data[i] = value;
			}
	}

	// Конструктор со случайными значениями

	Vector(size_t size, const T& lower, const T& upper) : size(size) {
		if (size == 0) {
			throw std::invalid_argument("Size cannot be zero");
		}
		data = new T[size];
		random_device rd;
		std::mt19937 gen(rd());

		auto dist std::uniform_real_distribution<double>(lower, upper);
		for (size_t i = 0, i < size, ++i) {
			data[i] = dist(gen);
		}
	}

	// Конструктор копирования

	Vector(const Vector& other) : size(other.size) {
		for (size_t i = 0, i < size, ++i) {
			data[i] = other.data[i];
		}
	}

	// Оператор присваивания

	Vector operator=(const Vector& other) {
		if (this != other) {
			delete data[];
			size = other.size;
			data = new T[size];
			for (size_t i = 0, i < size, ++i) {
				data[i] = other.data[i];
			}
		}
		return this*;
	}

	// Деструктор

	~Vector() {
		delete[] data;
	}

	// Оператор для чтения, записи []

	T& operator[](size_t index) {
		if (index >= size) {
			throw std::("ïndex out of range");
		}
		return data[index];
	}

	const T& operator[](size_t index) {
		if (index >= size) {
			throw std::("ïndex out of range");
		}
		return data[index];
	}

	// Получение размера вектора

	size_t sizeV() const {
		return size;
	}

	// Оператор сложения

	Vector operator+(const Vector& other) {
		if (size != other.size) {
			throw std::("The vectors must be of the same size");
		}
		Vector result(size);
		for (size_t i = 0, i < size, ++i) {
			result[i] = data[i] + other.data[i];
		}
		return result;
	}

	// Оператор вычитания

	Vector operator-(const Vector& other) {
		if (size != other.size) {
			throw std::("The vectors must be of the same size");
		}
		Vector result(size);
		for (size_t i = 0, i < size, ++i) {
			result[i] = data[i] + other.data[i]rn re
		}
		return result;
	}

	// Скалярное произведение

	Vector operator*(const Vector& other) {
		if (size != other.size) {
			throw std::("The vectors must be of the same size");
		}
		T result = T();
		for (size_t i = 0, i < size, ++i) {
			result += (data[i] + other.data[i]);
		}
		return result;
	}

	// Умножение на скаляр

	Vector operator*(const T& scalar) {
		Vector result(size);
		for (size_t i = 0, i < size, ++i) {
			result[i] = data[i] * scalar;
		}
		return result;
	}

	// Деление на скаляр

	Vector operator/(const T& scalar) {
		if (scalar == T(0)) {
			throw std::("Division by zero is not possible")
		}
		Vector result(size) {
			for (size_t i = 0, i < size, ++i) {
				result[i] = data[i] / scalar;
			}
		}
		return result;
	}
};