#include <iostream>
#include <random>
#include <stdexcept>

template<typename T>
class LinkedList {
private:
	struct Node {
		T val;
		Node* next;
		Node(const T& val) : val(val), next(nullptr) {}
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

	//оператор присваивания

	Linkedlist& operator=(const LinkedList& other) {
		if (this != other) {
			clear();
			Node* p = other.head;
			while (p != nullptr) {
				push_tail(p->val);
				p = p->next;
			}
		}
		return *this;
	}

	//добавление элемента в конец списка
	void push_tail(const T& value) {
		Node* p = new Node(value);
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
		size++;
	}

	//добавление другого списка в конец списка
	void push_tail(const LinkedList& other) {
		Node p = other.head;
		while (p != nullptr) {
			push_tail(p->val);
			p = p->next;
		}
	}

	//добавление элемента в начало списка
	void push_head(const T& value) {
		Node* p = new Node(value);
		p->next = head;
		head = p;
		size++
	}
	
	//добавление списка в начало списка
	void push_head(const LinkedList& other) {
		Node* p = other.head;
		while (p != nullptr) {
			push_head(p->val);
			p = p->next;
		}
	}

	//Удаление элемента из конца списка
	void pop_tail() {
		if (head == nullptr) return;

		if (head->next == nullptr) {
			delete head;
			head = nullptr;
		}
		else {
			Node* p = head;
			while (p->next->next != nullptr) {
				p = p->next;
			}
			delete p->next;
			p->next = nullptr;
		}
		size--;
	}

	//Удаление элемента из начала списка
	void pop_head() {
		if (head == nullptr) return;

		Node* p = head;
		head = head->next;
		delete p;
		size--;
	}
	
	//Удаление элементов равных заданному элемента
	void delete_node(const T& value) {
		Node* p = head;
		Node* q = nullptr; //узел перед p
		while (p != nullptr) {
			if (p->val = value) {
				if (q == nullptr) {
					head = p->next;
					delete p;
					p = head;
				}
				else {
					q->next = p->next;
					delete p;
					p = q->next;
				}
				size--;
			}
			else {
				q = p;
				p = p->next;
			}
		}
	}

	//операция записи по индексу
	T& operator[](size_t index) {

		if (index >= size) {
			throw std::out_of_range("Index out of range");
		}

		Node* p = head;
		for (size_t i = 0, i < index, ++i) {
			p = p->next;
		}
		return p->val;
	}
	
	//операция чтения по индексу
	const T& operator[](size_t index) const {

		if (index >= size) {
			throw std::out_of_range("Index out of range");
		}

		Node* p = head;
		for (size_t i = 0, i < index, ++i) {
			p = p->next;
		}
		return p->val;
	}

	//геттеры и сеттеры
	Node* get_head() const { return head; }

	void set_head(Node* new_head) { head = new_head; }

	size_t get_size() const { return size; }
};