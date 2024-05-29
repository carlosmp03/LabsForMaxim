#include <iostream>
#include <vector>
#include <string>
#include <complex>
#include <stdexcept>
//#include <functional>

template<typename T>
class BinaryHeap {
private:
    std::vector<T> heap;
    size_t size;

    void shift_up(size_t i) {
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void shift_down(size_t i) {
        size_t left, right, j;
        while (2 * i + 1 < size) {
            left = 2 * i + 1;
            right = 2 * i + 2;
            j = left;
            if (right < size && heap[right] > heap[left]) {
                j = right;
            }
            if (heap[i] >= heap[j]) {
                break;
            }
            std::swap(heap[i], heap[j]);
            i = j;
        }
    }

public:
    BinaryHeap() : size(0) {}
    BinaryHeap(const std::vector<T>& arr) : heap(arr), size(heap.size()) {
        for (int i = (size - 1) / 2; i >= 0; --i) {
            shift_down(i);
        }
    }

    size_t GetSize() const {
        return size;
    }

    void push(T value) {
        heap.push_back(value);
        size++;
        shift_up(size - 1);
    }

    T extractMax() {
        if (size == 0) {
            throw std::out_of_range("heap is empty");
        }
        T max = heap[0];
        heap[0] = heap[size - 1];
        heap.pop_back();
        size--;
        if (size > 0) {
            shift_down(0);
        }
        return max;
    }

    void changePriority(size_t i, T newPriority) {
        if (i >= size) return;
        T oldPriority = heap[i];
        heap[i] = newPriority;
        if (newPriority > oldPriority) {
            shift_up(i);
        } else {
            shift_down(i);
        }
    }

    void print() const {
        std::cout << "Heap: ";
        for (auto& elem : heap) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    void merge(BinaryHeap<T>& BH) {
        for (size_t i = 0; i < BH.GetSize(); ++i) {
            this->push(BH.heap[i]);
        }
    }
    
};


template<typename T>
bool operator<(const std::complex<T>& lhs, const std::complex<T>& rhs) {
    return std::abs(lhs) < std::abs(rhs);
}

template<typename T>
bool operator>(const std::complex<T>& lhs, const std::complex<T>& rhs) {
    return std::abs(lhs) > std::abs(rhs);
}

template<typename T>
bool operator>=(const std::complex<T>& lhs, const std::complex<T>& rhs) {
    return std::abs(lhs) >= std::abs(rhs);
}

template<typename T>
bool operator<=(const std::complex<T>& lhs, const std::complex<T>& rhs) {
    return std::abs(lhs) <= std::abs(rhs);
}



struct PersonID {
    int series;
    int number;
};

class Person {
private:
    PersonID id;
    std::string first_name;
    std::string mid_name;
    std::string last_name;
public:
    Person(const PersonID& id, const std::string& first, const std::string& mid, const std::string& last)
        : id(id), first_name(first), mid_name(mid), last_name(last) {}

    PersonID GetId() const {
        return id;
    }
    std::string GetFirstName() const {
        return first_name;
    }

    std::string GetMidName() const {
        return mid_name;
    }
    std::string GetLastName() const {
        return last_name;
    }

    bool operator<(const Person& other) const {
        return id.number < other.id.number;
    }

    bool operator>(const Person& other) const {
        return id.number > other.id.number;
    }

    bool operator>=(const Person& other) const {
        return id.number >= other.id.number;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << person.first_name << " " << person.mid_name << " " << person.last_name;
        return os;
    }
};

/*

*/

template<typename T>
class PriorityQueue {
private:
    BinaryHeap<T> heap;
public:
    void push(T value) {
        heap.push(value);
    }

    T pop() {
        return heap.extractMax();
    }

    bool empty() const {
        return heap.GetSize() == 0;
    }

    size_t size() const {
        return heap.GetSize();
    }

    void print() const {
        heap.print();
    }

    void changePriority(size_t i, T newPriority) {
        heap.changePriority(i, newPriority);
    }


};
