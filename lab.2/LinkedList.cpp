#include <iostream>
#include <random>
#include <stdexcept>

template<typename T>
class LinkedList {
private:
	struct Node {
		T val;
		Node* next;
		Node(const T& _val) : val(_val), next(nullptr) {}
	};
	Node* head;
	size_t size;
public:
	//конструктор по умолчанию
	LinkedList() : head(nullptr), size(0) {}

	//конструктор копирования
	LinkedList(const LinkedList& other) : head(nullptr), size(0) {
		Node* p = other.head;
		while (p != nullptr) {
			push_tail(p->val);
			p = p->next;
		}

	}

	//конструктор со случайными значениями
	LinkedList(size_t List_size, T min_val, T max_val) : head(nullptr), size(0) {
		std::random_device rd();
		std::mt19937 dist(gen());

		if constexpr (std::is_integral_v<T>) {
			std::uniform_int_distribution<T> dist(min_val, max_val)
				for (size_t i = 0, i < List_size, ++i) {
					push_tail(dist(gen));
			}
		}
		else if constexpr (std::is_floating_point_v<T>) {
			std::uniform_real_distribution<T> dist(min_val, max_val)
				for (size_t i = 0, i < List_size, ++i) {
					push_tail(dist(gen));
				}
		}
	}


	//деструктор
	~LinkedList() { clear(); }

	//добавление элемента в конец списка
	void push_tail(const T& val) {
		Node* p = new Node(val);
		if (head == nullptr) {
			head = p;
		}
		else {
			Node* q = head;
			while (q->next != nullptr) {
				q = q->next;
			}
			q->next = p;
		}
		++size;
	}

	//добавление другого списка в конец списка
	void push_tail(const LinkedList& other) {
		Node p = other.head;
		while (p != nullptr) {
			push_tail(p->val);
			p = p->next;
		}
	}
};