#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>
#include <complex>
#include <random>
#include <stdexcept>
#include <cmath>

template<typename T>
class Vector {
private:
    T* data_;
    size_t size_;
public:
    Vector(size_t size, const T& value = T());
    Vector(size_t size, const T& lower, const T& upper);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t sizeV() const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    T operator*(const Vector& other) const;
    Vector operator*(const T& scalar) const;
    Vector operator/(const T& scalar) const;

    T length() const;
    Vector unit_V() const;
    Vector perpendicular_V() const;

    template<typename U>
    static std::complex<U> dot_product_complex(const Vector<std::complex<U>>& v1,
        const Vector<std::complex<U>>& v2);

    template<typename U>
    static U length_complex(const Vector<std::complex<U>>& vec);

    template<typename U>
    static Vector<std::complex<U>> unit_vector_complex(const Vector<std::complex<U>>& vec);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec);

template<typename U>
std::ostream& operator<<(std::ostream& os, const Vector<std::complex<U>>& vec);

#include "Vector.tpp"

#endif