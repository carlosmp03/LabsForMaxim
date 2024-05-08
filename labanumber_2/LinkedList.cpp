#include <iostream>
#include <stdexcept>

template<typename T>
class Node {
public:
    T elem;
    Node* next;

    Node(T elem, Node* next = nullptr) : elem(elem), next(next) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t len;

public:
    LinkedList() : head(nullptr), tail(nullptr), len(0) {}

    ~LinkedList() {
        clear();
    }

    size_t getSize() const {
        return len;
    }

    T get(size_t index) const {
        if (index < 0 || index >= len) {
            throw std::out_of_range("Index out of range.");
        }
        Node<T>* currentNode = head;
        for (size_t i = 0; i < index; i++) {
            currentNode = currentNode->next;
        }
        return currentNode->elem;
    }

    void append(const T& elem) {
        Node<T>* node = new Node<T>(elem);
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        len++;
    }

    void prepend(const T& elem) {
        Node<T>* node = new Node<T>(elem, head);
        head = node;
        if (tail == nullptr) {
            tail = node;
        }
        len++;
    }

    void insert(size_t index, const T& elem) {
        if (index == 0) {
            prepend(elem);
            return;
        }
        if (index == len) {
            append(elem);
            return;
        }
        Node<T>* currentNode = head;
        for (size_t i = 0; i < index - 1; i++) {
            currentNode = currentNode->next;
        }
        Node<T>* newNode = new Node<T>(elem, currentNode->next);
        currentNode->next = newNode;
        len++;
    }

    void insertAt(size_t index, const T& elem) {
        if (index < 0 || index >= len) {
            throw std::out_of_range("Index out of range.");
        }
        Node<T>* currentNode = head;
        for (size_t i = 0; i < index; i++) {
            currentNode = currentNode->next;
        }
        currentNode->elem = elem;
    }

    void clear() {
        while (head != nullptr) {
            Node<T>* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        tail = nullptr;
        len = 0;
    }

    void print() const {
        Node<T>* currentNode = head;
        while (currentNode != nullptr) {
            std::cout << currentNode->elem << " -> ";
            currentNode = currentNode->next;
        }
        std::cout << "nullptr\n";
    }
};
