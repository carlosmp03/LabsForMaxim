#include <iostream>
template<typename T>
class DynArray
{
private:
    T* arr;
    size_t size;
    size_t capacity;

    void resize(){
        capacity *= 2;
        T* resarr = new T[capacity];
        for (int i = 0; i < size; i++){
            resarr[i] = arr[i];
        }
        delete[] arr;
        arr = resarr;
    }

    DynArray(size_t new_capacity, size_t newSize, T* new_arr) : capacity(new_capacity), size(newSize), arr(new_arr) {}

    T* copy_array(size_t new_capacity) const {
        T* new_arr = new T[new_capacity];
        for (size_t i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        return new_arr;
    }
    
public:
    DynArray() : capacity(10), size(0){
        arr = new T[capacity];
    }
    ~DynArray() {
        delete[] arr;
    }
    DynArray(const DynArray& other) : capacity(other.capacity), size(other.size), arr(copyArrayFrom(other.arr, other.capacity)) {}

    void push_back(const T& elem){
        if(size == capacity){
            resize();
        }
        arr[size++] = elem;
    }

    void push_forward(const T& elem){
        if(size == capacity){
            resize();
        }
        for(int i = size + 1; i > 0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = elem;
        size++;
    }

    void insert(const T& elem, size_t index){
        if(size == capacity){
            resize();
        }
        for(int i = size; i > index; i--){
            arr[i] = arr[i - 1];
        }
        arr[index] = elem;
        size++;
    }

    void insertAt(const T& elem, size_t index){
        arr[index] = elem;
    }

    void pop_front() {
        if (size != 0){
            for (int i = 1; i < size; i++){
                arr[i-1] = arr[i];
            }
        }
        size--;
    }


    void pop_back() {
        if(size > 0){
            size--;
        }
    }

    size_t get_size() const {
        return size;
    }

    size_t get_capacity() const {
        return capacity;
    }

    const T get(size_t index) const {
        if(index >= size || index < 0){
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    void Concat(const DynArray<T>* side_array){
        if (size + side_array->get_size() >= capacity){
            while (size + side_array->get_size() >= capacity){
                resize();
            }
        }

        for(int i = 0; i < side_array->get_size(); i++){
            arr[i + size] = side_array.get(i);
        }

    }

    void print() const{
        for (int i = 0; i < size; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

#include <iostream>

template<typename T>
class ImmutableDynArray {
private:
    T* arr;
    size_t size;
    size_t capacity;

    ImmutableDynArray(size_t new_capacity, size_t newSize, T* new_arr) : capacity(new_capacity), size(newSize), arr(new_arr) {}

    T* copy_array(size_t new_capacity) const {
        T* new_arr = new T[new_capacity];
        for (size_t i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        return new_arr;
    }

public:
    ImmutableDynArray() : capacity(10), size(0), arr(new T[capacity]) {}

    ~ImmutableDynArray() {
        delete[] arr;
    }

    ImmutableDynArray(const ImmutableDynArray& other) : capacity(other.capacity), size(other.size), arr(other.copy_array(other.capacity)) {}

    ImmutableDynArray push_back(const T& elem) const {
        size_t new_capacity = capacity;
        if (size == capacity) {
            new_capacity *= 2;
        }
        T* new_arr = copy_array(new_capacity);
        new_arr[size] = elem;
        return ImmutableDynArray(new_capacity, size + 1, new_arr);
    }

    ImmutableDynArray push_forward(const T& elem) const {
        size_t new_capacity = capacity;
        if (size == capacity) {
            new_capacity *= 2;
        }
        T* new_arr = copy_array(new_capacity);
        for (size_t i = size; i > 0; --i) {
            new_arr[i] = new_arr[i - 1];
        }
        new_arr[0] = elem;
        return ImmutableDynArray(new_capacity, size + 1, new_arr);
    }

    ImmutableDynArray insert(const T& elem, size_t index) const {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        size_t new_capacity = capacity;
        if (size == capacity) {
            new_capacity *= 2;
        }
        T* new_arr = copy_array(new_capacity);
        for (size_t i = size; i > index; --i) {
            new_arr[i] = new_arr[i - 1];
        }
        new_arr[index] = elem;
        return ImmutableDynArray(new_capacity, size + 1, new_arr);
    }

    size_t get_size() const {
        return size;
    }

    size_t get_capacity() const {
        return capacity;
    }

    T get(size_t index) const {
        if (index >= size || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    void print() const {
        for (size_t i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

/*
int main(){
    DynArray<int> dar1;
    DynArray<int> dar2;
    dar1.push_back(1);
    dar1.push_back(2);
    dar1.push_forward(0);
    
    dar1.print();

    std::cout << dar1.get(1) << "\n";
    dar1.pop_back();
    dar1.pop_front();
    dar1.print();

    dar2 = dar1;
    dar2.print();


    ImmutableDynArray<int> dar11;
    dar11 = dar11.push_back(1);
    dar11 = dar11.push_back(2);
    dar11 = dar11.push_forward(0);
    
    dar11.print();

    std::cout << dar11.get(1) << "\n";
    ImmutableDynArray<int> dar22 = dar11.push_back(3);
    dar11.print();
    dar22.print();  
}
*/
