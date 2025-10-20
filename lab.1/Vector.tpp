#ifndef VECTOR_TPP
#define VECTOR_TPP

template<typename T>
Vector<T>::Vector(size_t size, const T& value) : size_(size) {
    if (size == 0) {
        throw std::invalid_argument("Size cannot be zero");
    }
    data_ = new T[size_];
    for (size_t i = 0; i < size_; ++i) {
            data_[i] = value;
        }
}
template<typename T>
Vector<T>::Vector(size_t size, const T& lower, const T& upper) : size_(size) {
    if (size == 0) {
        throw std::invalid_argument("Size cannot be zero");
    }
    data_ = new T[size_];
    std::random_device rd;
    std::mt19937 gen(rd());

    if constexpr (std::is_integral_v<T>) {
        std::uniform_int_distribution<T> dist(lower, upper);
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = dist(gen);
        }
    }
    else if constexpr (std::is_floating_point_v<T>) {
        // Используем double для распределения, затем преобразуем к T
        std::uniform_real_distribution<double> dist(
            static_cast<double>(lower), 
            static_cast<double>(upper)
        );
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = static_cast<T>(dist(gen));
        }
    }
    else if constexpr (std::is_same_v<T, std::complex<int>> || 
                      std::is_same_v<T, std::complex<float>> || 
                      std::is_same_v<T, std::complex<double>>) {
        using ValueType = typename T::value_type;
        if constexpr (std::is_integral_v<ValueType>) {
            std::uniform_int_distribution<ValueType> dist_real(lower.real(), upper.real());
            std::uniform_int_distribution<ValueType> dist_imag(lower.imag(), upper.imag());
            for (size_t i = 0; i < size_; ++i) {
                data_[i] = T(dist_real(gen), dist_imag(gen));
            }
        }
        else {
            std::uniform_real_distribution<double> dist_real(lower.real(), upper.real());
            std::uniform_real_distribution<double> dist_imag(lower.imag(), upper.imag());
            for (size_t i = 0; i < size_; ++i) {
                data_[i] = T(static_cast<ValueType>(dist_real(gen)), 
                            static_cast<ValueType>(dist_imag(gen)));
            }
        }
    }
    else {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = T();
        }
    }
}

template<typename T>
Vector<T>::Vector(const Vector& other) : size_(other.size_) {
    data_ = new T[size_];
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = new T[size_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

template<typename T>
Vector<T>::~Vector() {
    delete[] data_;
}

template<typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range("ïndex out of range");
    }
    return data_[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const{
    if (index >= size_) {
        throw std::out_of_range("ïndex out of range");
    }
    return data_[index];
}

template<typename T>
size_t Vector<T>::sizeV() const {
    return size_;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector& other) const{
    if (size_ != other.size_) {
        throw std::invalid_argument("The vectors must be of the same size");
    }
    Vector result(size_);
    for (size_t i = 0; i < size_; ++i) {
        result[i] = data_[i] + other.data_[i];
    }
    return result;
}

template<typename T>
Vector<T> Vector<T>::operator-(const Vector& other) const{
    if (size_ != other.size_) {
        throw std::invalid_argument("The vectors must be of the same size");
    }
    Vector result(size_);
    for (size_t i = 0; i < size_; ++i) {
        result[i] = data_[i] - other.data_[i];
    }
    return result;
}

template<typename T>
T Vector<T>::operator*(const Vector& other) const{
    if (size_ != other.size_) {
        throw std::invalid_argument("The vectors must be of the same size");
    }
    T result = T();
    for (size_t i = 0; i < size_; ++i) {
        result += (data_[i] * other.data_[i]);
    }
    return result;
}

template<typename T>
Vector<T> Vector<T>::operator*(const T& scalar) const{
    Vector result(size_);
    for (size_t i = 0; i < size_; ++i) {
        result[i] = data_[i] * scalar;
    }
    return result;
}

template<typename T>
Vector<T> Vector<T>::operator/(const T& scalar) const{
    if (scalar == T(0)) {
        throw std::invalid_argument("Division by zero is not possible");
    }
    Vector result(size_);
        for (size_t i = 0; i < size_; ++i) {
            result[i] = data_[i] / scalar;
        }
    return result;
}

template<typename T>
T Vector<T>::length() const {
    T sum = T();
    for (size_t i = 0; i < size_; ++i) {
        sum += data_[i] * data_[i];
    }
    return std::sqrt(sum);
}

template<typename T>
Vector<T> Vector<T>::unit_V() const {
    T len = length();
    if (len == T(0)) {
        throw std::invalid_argument("Cannot get unit vector of zero vector");
    }
    Vector result(size_);
    for (size_t i = 0; i < size_; ++i) {
        result[i] = data_[i] / len;
    }
    return result;
}

template<typename T>
Vector<T> Vector<T>::perpendicular_V() const {
    if (size_ == 2) {
        Vector result(2);
        result[0] = -data_[1];
        result[1] = data_[0];
        return result;
    }
    else if(size_ == 3) {
        Vector result(3);
        if (data_[0] != T(0)) {
            result[0] = -data_[1];
            result[1] = data_[0];
            result[2] = T(0);
        }
        else if (data_[1] != T(0)) {
            result[0] = T(0);
            result[1] = -data_[2];
            result[2] = data_[1];
        }
        else if (data_[2] != T(0)) {
            result[0] = -data_[2];
            result[1] = T(0);
            result[2] = data_[0];
        }
        else {
            throw std::invalid_argument("Zero vector has no perpendicular");
        }
        return result;
    }
    else {
        throw std::invalid_argument("Uncorrect size. Only 2D and 3D.");
    }
}

template<typename T>
template<typename U>
std::complex<U> Vector<T>::dot_product_complex(const Vector<std::complex<U>>& v1,
    const Vector<std::complex<U>>& v2) {
    if (v1.sizeV() != v2.sizeV()) {
        throw std::invalid_argument("Vectors must have same size for dot product");
    }

    std::complex<U> result(0, 0);
    for (size_t i = 0; i < v1.sizeV(); ++i) {
        result += std::conj(v1[i]) * v2[i];
    }
    return result;
}

template<typename T>
template<typename U>
U Vector<T>::length_complex(const Vector<std::complex<U>>& vec) {
    U sum = U(0);
    for (size_t i = 0; i < vec.sizeV(); ++i) {
        auto val = vec[i];
        sum += val.real() * val.real() + val.imag() * val.imag();
    }
    return std::sqrt(sum);
}

template<typename T>
template<typename U>
Vector<std::complex<U>> Vector<T>::unit_vector_complex(const Vector<std::complex<U>>& vec) {
    U len = length_complex(vec);
    if (len == U(0)) {
        throw std::invalid_argument("Cannot get unit vector of zero vector");
    }
    Vector<std::complex<U>> result(vec.sizeV());
    for (size_t i = 0; i < vec.sizeV(); ++i) {
        result[i] = vec[i] / len;
    }
    return result;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.sizeV(); ++i) {
        os << vec[i];
        if (i < vec.sizeV() - 1) os << ", ";
    }
    os << "]";
    return os;
}

template<typename U>
std::ostream& operator<<(std::ostream& os, const Vector<std::complex<U>>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.sizeV(); ++i) {
        auto val = vec[i];
        os << "(" << val.real() << (val.imag() >= 0 ? "+" : "") << val.imag() << "i)";
        if (i < vec.sizeV() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

#endif

