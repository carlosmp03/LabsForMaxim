#include "BinaryHeap.cpp"
#include <iostream>
#include <complex>


void printMenu() {
    std::cout << "Priority Queue Menu:\n";
    std::cout << "1. Push integer\n";
    std::cout << "2. Push double\n";
    std::cout << "3. Push complex number\n";
    std::cout << "4. Push string\n";
    std::cout << "5. Push Person\n";
    std::cout << "6. Pop\n";
    std::cout << "7. Print queue\n";
    std::cout << "8. Change priority\n";
    std::cout << "9. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    PriorityQueue<int> intQueue;
    PriorityQueue<double> doubleQueue;
    PriorityQueue<std::complex<double>> complexQueue;
    PriorityQueue<std::string> stringQueue;
    PriorityQueue<Person> personQueue;
    int choice;

    while (true) {
        printMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                std::cout << "Enter integer: ";
                std::cin >> value;
                intQueue.push(value);
                break;
            }
            case 2: {
                double value;
                std::cout << "Enter double: ";
                std::cin >> value;
                doubleQueue.push(value);
                break;
            }
            case 3: {
                double real, imag;
                std::cout << "Enter real part: ";
                std::cin >> real;
                std::cout << "Enter imaginary part: ";
                std::cin >> imag;
                std::complex<double> value(real, imag);
                complexQueue.push(value);
                break;
            }
            case 4: {
                std::string value;
                std::cout << "Enter string: ";
                std::cin >> value;
                stringQueue.push(value);
                break;
            }
            case 5: {
                int series, number;
                std::string first, mid, last;
                std::cout << "Enter series: ";
                std::cin >> series;
                std::cout << "Enter number: ";
                std::cin >> number;
                std::cout << "Enter first name: ";
                std::cin >> first;
                std::cout << "Enter middle name: ";
                std::cin >> mid;
                std::cout << "Enter last name: ";
                std::cin >> last;
                Person person({series, number}, first, mid, last);
                personQueue.push(person);
                break;
            }
            case 6: {
                int sub_choice;
                std::cout << "Select data type of queue to pop from:\n";
                std::cout << "1. Integer\n";
                std::cout << "2. Double\n";
                std::cout << "3. Complex\n";
                std::cout << "4. String\n";
                std::cout << "5. Person\n";
                std::cin >> sub_choice;

                switch (sub_choice) {
                    case 1:
                        try {
                            std::cout << "Popped: " << intQueue.pop() << std::endl;
                        } catch (const std::out_of_range& e) {
                            std::cout << "queue is empty!" << std::endl;
                        }
                        break;
                    case 2:
                        try {
                            std::cout << "Popped: " << doubleQueue.pop() << std::endl;
                        } catch (const std::out_of_range& e) {
                            std::cout << "queue is empty!" << std::endl;
                        }
                        break;
                    case 3:
                        try {
                            std::cout << "Popped: " << complexQueue.pop() << std::endl;
                        } catch (const std::out_of_range& e) {
                            std::cout << "queue is empty!" << std::endl;
                        }
                        break;
                    case 4:
                        try {
                            std::cout << "Popped: " << stringQueue.pop() << std::endl;
                        } catch (const std::out_of_range& e) {
                            std::cout << "queue is empty!" << std::endl;
                        }
                        break;
                    case 5:
                        try {
                            std::cout << "Popped: " << personQueue.pop() << std::endl;
                        } catch (const std::out_of_range& e) {
                            std::cout << "queue is empty!" << std::endl;
                        }
                        break;
                    default:
                        //throw std::invalid_argument("Invalid choice!");
                        std::cout << "Invalid choice!" << std::endl;
                }
                break;
            }
            case 7: {
                int sub_choice;
                std::cout << "Select data type of queue to print:\n";
                std::cout << "1. Int\n";
                std::cout << "2. Double\n";
                std::cout << "3. Complex\n";
                std::cout << "4. Str\n";
                std::cout << "5. Person\n";
                std::cin >> sub_choice;

                switch (sub_choice) {
                    case 1:
                        intQueue.print();
                        break;
                    case 2:
                        doubleQueue.print();
                        break;
                    case 3:
                        complexQueue.print();
                        break;
                    case 4:
                        stringQueue.print();
                        break;
                    case 5:
                        personQueue.print();
                        break;
                    default:
                        //throw std::invalid_argument("Invalid choice!");
                        std::cout << "Invalid choice!" << std::endl;
                }
                break;
            }
            case 8: {
                int sub_choice;
                std::cout << "Select data type of queue to change priority:\n";
                std::cout << "1. Int\n";
                std::cout << "2. Double\n";
                std::cout << "3. Complex\n";
                std::cout << "4. Str\n";
                std::cout << "5. Person\n";
                std::cin >> sub_choice;
                size_t index;
                std::cout << "Enter index: ";
                std::cin >> index;

                switch (sub_choice) {
                    case 1: {
                        int newPriority;
                        std::cout << "Enter new priority (int): ";
                        std::cin >> newPriority;
                        intQueue.changePriority(index, newPriority);
                        break;
                    }
                    case 2: {
                        double newPriority;
                        std::cout << "Enter new priority (double): ";
                        std::cin >> newPriority;
                        doubleQueue.changePriority(index, newPriority);
                        break;
                    }
                    case 3: {
                        double real, imag;
                        std::cout << "Enter new real part: ";
                        std::cin >> real;
                        std::cout << "Enter new img part: ";
                        std::cin >> imag;
                        std::complex<double> newPriority(real, imag);
                        complexQueue.changePriority(index, newPriority);
                        break;
                    }
                    case 4: {
                        std::string newPriority;
                        std::cout << "Enter new priority (string): ";
                        std::cin >> newPriority;
                        stringQueue.changePriority(index, newPriority);
                        break;
                    }
                    case 5: {
                        int series, number;
                        std::string first, mid, last;
                        std::cout << "Enter new series: ";
                        std::cin >> series;
                        std::cout << "Enter new number: ";
                        std::cin >> number;
                        std::cout << "Enter new first name: ";
                        std::cin >> first;
                        std::cout << "Enter new middle name: ";
                        std::cin >> mid;
                        std::cout << "Enter new last name: ";
                        std::cin >> last;
                        Person newPriority({series, number}, first, mid, last);
                        personQueue.changePriority(index, newPriority);
                        break;
                    }
                    default:
                        //throw std::invalid_argument("Invalid choice!");
                        std::cout << "Invalid choice!" << std::endl;
                }
                break;
            }
            case 9:
                return 0;
            default:

                //throw std::invalid_argument("Invalid choice!");
                std::cout << "Invalid choice!" << std::endl;
        }
    }

    return 0;
}
