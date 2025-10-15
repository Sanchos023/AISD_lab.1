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
};