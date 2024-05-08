#include <iostream>
#include <string>
#include <sstream>
#include "Sequence.cpp"

template<typename T>
void printSequence(Sequence<T>* sequence) {
    std::cout << "Sequence elements: ";
    for (int i = 0; i < sequence->GetLength(); ++i) {
        std::cout << sequence->Get(i) << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void interactWithSequence(Sequence<T>* sequence) {
    std::string command;
    T value;
    int index;

    while (true) {
        std::cout << "\nEnter command (append, prepend, pop_back, pop_front, insert, subseq, print, quit): ";
        std::cin >> command;

        if (command == "quit") {
            break;
        } else if (command == "append") {
            std::cout << "Enter value to append: ";
            std::cin >> value;
            sequence->Append(value);
        } else if (command == "prepend") {
            std::cout << "Enter value to prepend: ";
            std::cin >> value;
            sequence->Prepend(value);
        } else if (command == "pop_back") {
            sequence->pop_back();
        } else if (command == "pop_front") {
            sequence->pop_front();
        } else if (command == "insert") {
            std::cout << "Enter index and value to insert: ";
            std::cin >> index >> value;
            sequence->insert(index, value);
        } else if (command == "subseq") {
            int l, r;
            std::cout << "Enter left and right indices for subsequence: ";
            std::cin >> l >> r;
            Sequence<T>* sub = sequence->SubSeq(l, r);
            printSequence(sub);
            delete sub; // Clean up if the implementation returns a new sequence
        } else if (command == "print") {
            printSequence(sequence);
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }
}

int main() {
    std::cout << "Choose sequence type (list or array): ";
    std::string type;
    std::cin >> type;

    Sequence<int>* sequence = nullptr;

    if (type == "list") {
        sequence = new ListSequence<int>();
    } else if (type == "array") {
        sequence = new ArraySequence<int>();
    } else {
        std::cout << "Invalid sequence type." << std::endl;
        return 1;
    }

    interactWithSequence(sequence);

    delete sequence; // Clean up
    return 0;
}
