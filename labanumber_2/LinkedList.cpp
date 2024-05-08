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

    void Concat(const LinkedList<T>* side_list) {
        for(int i = 0; i < side_list->getSize(); i++){
            this->append(side_list->get(i));
        }
    }


    void pop_back() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T>* currentNode = head;
            while (currentNode->next != tail) {
                currentNode = currentNode->next;
            }
            delete tail;
            tail = currentNode;
            tail->next = nullptr;
        }
        len--;
    }

    void pop_front() {
        if (head == nullptr) return;
        Node<T>* temp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr;
        delete temp;
        len--;
    }

    LinkedList<T>* ImmutableConcat(const LinkedList<T>* side_list) const {
        LinkedList<T>* result = new LinkedList<T>();
        for(int i = 0; i < len; i++){
            result->append(this->get(i));
        } 
        for(int i = 0; i < side_list->getSize(); i++){
            result->append(side_list->get(i));
        }
        return result;
    }

    LinkedList<T>* GetSubList(int l, int r) const {
        if(l < 0 || r >= len || r - l < 0){
            throw std::out_of_range("Index out of range.");
        }
        LinkedList<T>* res = new LinkedList<T>();
        Node<T>* curNode = head;
        int count = 0;
        
        while (count != r+1){
            if (count >= l && count <= r){
                res->append(curNode->elem);
                curNode = curNode->next;
            } 
            else{
                curNode = curNode->next;
            }
            count++;
        }
        
        return res;
    } 

    LinkedList<T>* ImmutableAppend(const T& elem) const {
        LinkedList<T>* res = new LinkedList<T>(*this);
        res->append(elem);
        return res;
    }

    LinkedList<T>* ImmutablePrepend(const T& elem) const {
        LinkedList<T>* res = new LinkedList<T>(*this);
        res->prepend(elem);
        return res;
    }

    LinkedList<T>* ImmutableInsert(size_t index, const T& elem) const {
        LinkedList<T>* res = new LinkedList<T>(*this);
        res->insert(index, elem);
        return res;
    } 
    LinkedList<T>* ImmutableInsertAt(size_t index, const T& elem) const {
        LinkedList<T>* res = new LinkedList<T>(*this);
        res->insertAt(index, elem);
    }

    LinkedList<T>* ImmutablePop_back() const {
        LinkedList<T>* res = new LinkedList<T>(*this);
        res->pop_back();
        return res;
    }
    LinkedList<T>* ImmutablePop_front() const {
        LinkedList<T>* res = new LinkedList<T>(*this);
        res->pop_front();
        return res;
    }
};
