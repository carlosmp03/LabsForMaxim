#include "LinkedList.cpp"
#include "DynArray.cpp"
template<typename T>
class Sequence{
public:
    virtual T Get(int index) const = 0;
    virtual int GetLength() const = 0;
    virtual void Append(const T& elem) = 0;
    virtual void Prepend(const T& elem) = 0;
    virtual void insert(int index, const T& elem) = 0;
    virtual void insertAt(int index, const T& elem) = 0;
    virtual Sequence<T>* Concat(const Sequence<T>* list) const = 0;
    virtual Sequence<T>* SubSeq(int l, int r) const = 0;
    virtual void Print() const = 0;
    virtual ~Sequence() {}
};

template<typename T>
class ArraySequence: public Sequence<T>{
private:
    DynArray<T> array;
public:
    T Get(int index) const override{
        return array.get(static_cast<size_t>(index));
    }

    void Append(const T& elem) override {
        array.push_back(elem);
    }
    void Prepend(const T& elem) override {
        array.push_forward(elem);
    }

    int GetLength() const override {
        return array.get_size();
    }
    void insert(int index, const T& elem) override {
        array.insert(elem, static_cast<size_t>(index));
    }

    void insertAt(int index, const T& elem) override {
        array.insertAt(elem, static_cast<size_t>(index));
    }

    Sequence<T>* Concat(const Sequence<T>* list) const override {
        const ArraySequence<T>* arrList = dynamic_cast<const ArraySequence<T>*>(list);
        if (!arrList) {
            throw std::invalid_argument("Cannot concatenate different sequence types");
        }
        ArraySequence<T>* result = new ArraySequence<T>();
        for (size_t i = 0; i < array.get_size(); ++i) {
            result->Append(array.get(i));
        }
        for (size_t i = 0; i < arrList->array.get_size(); ++i) {
            result->Append(arrList->array.get(i));
        }
        return result;
    }

    Sequence<T>* SubSeq(const int l, const int r) const override {
        if (l > r || r >= array.get_size() || l < 0) {
            throw std::out_of_range("Index out of range!!!");
        }
        ArraySequence<T>* res = new ArraySequence<T>();
        for (int i = l; i <= r; i++) {
            res->Append(array.get(i));
        }
        return res;
    }

    
    void Print() const override {
        array.print();
    }

};

template<typename T>
class ListSequence : public Sequence<T> {
private:
    LinkedList<T> list;

public:
    T Get(int index) const override {
        return list.get(index);
    }

    int GetLength() const override {
        return list.getSize();
    }

    void Append(const T& elem) override {
        list.append(elem);
    }

    void Prepend(const T& elem) override {
        list.prepend(elem);
    }

    void insert(int index, const T& elem) override {
        list.insert(index, elem);
    }

    void insertAt(int index, const T& elem) override {
        list.insertAt(index, elem);
    }

    Sequence<T>* Concat(const Sequence<T>* other) const override {
        const ListSequence<T>* otherSeq = dynamic_cast<const ListSequence<T>*>(other);
        if (!otherSeq) throw std::invalid_argument("Sequence types must match.");
        ListSequence<T>* result = new ListSequence<T>();
        for (int i = 0; i < GetLength(); i++) {
            result->Append(Get(i));
        }
        for (int i = 0; i < otherSeq->GetLength(); i++) {
            result->Append(otherSeq->Get(i));
        }
        return result;
    }

    Sequence<T>* SubSeq(int l, int r) const override {
        if (l < 0 || r >= GetLength() || l > r) throw std::out_of_range("Index out of range.");
        ListSequence<T>* subseq = new ListSequence<T>();
        for (int i = l; i <= r; i++) {
            subseq->Append(Get(i));
        }
        return subseq;
    }

    void Print() const override {
        list.print();
    }
};


int main() {
    // Create a ListSequence and populate it
    ListSequence<int> listSeq;
    listSeq.Append(10);
    listSeq.Prepend(5);
    listSeq.Append(15);
    listSeq.insert(1, 7); // Inserts 7 at index 1

    std::cout << "ListSequence after insertions: ";
    listSeq.Print();

    // Create a sub-sequence from listSeq
    Sequence<int>* subListSeq = listSeq.SubSeq(1, 2); // Should contain 7 and 10
    std::cout << "SubListSequence from index 1 to 2: ";
    subListSeq->Print();

    // Create another ListSequence for concatenation
    ListSequence<int> anotherListSeq;
    anotherListSeq.Append(20);
    anotherListSeq.Append(25);

    // Concatenate listSeq with anotherListSeq
    Sequence<int>* concatListSeq = listSeq.Concat(&anotherListSeq);
    std::cout << "Concatenated ListSequence: ";
    concatListSeq->Print();

    // ArraySequence examples
    ArraySequence<int> arraySeq;
    arraySeq.Append(30);
    arraySeq.Prepend(25);
    arraySeq.Append(35);

    std::cout << "ArraySequence after insertions: ";
    arraySeq.Print();

    // Create a sub-sequence from arraySeq
    Sequence<int>* subArraySeq = arraySeq.SubSeq(0, 1); // Should contain 25 and 30
    std::cout << "SubArraySequence from index 0 to 1: ";
    subArraySeq->Print();

    // Create another ArraySequence for concatenation
    ArraySequence<int> anotherArraySeq;
    anotherArraySeq.Append(40);
    anotherArraySeq.Append(45);

    // Concatenate arraySeq with anotherArraySeq
    Sequence<int>* concatArraySeq = arraySeq.Concat(&anotherArraySeq);
    std::cout << "Concatenated ArraySequence: ";
    concatArraySeq->Print();

    // Clean up dynamically allocated memory
    delete subListSeq;
    delete concatListSeq;
    delete subArraySeq;
    delete concatArraySeq;

    return 0;
}
