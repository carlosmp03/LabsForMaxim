#include "binary_tree.cpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>

    //                  2
    //                 / \
    //                1   3
    //               / \ / \
    //                      4
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v){
    os << "<";
    for(size_t i = 0; i < v.size(); i++){
        os << v[i];
        if(i != v.size() - 1){
            os << ", ";
        }
    }
    os << ">";
    return os;
}

bool tests_for_RightLeftRoot(){
    BinaryTree<Person> tree;

    Person p1("John", "Doe", 1);
    Person p2("Jane", "Doe", 2);
    Person p3("Alice", "Smith", 3);
    Person p4("Bob", "Johnson", 4);
    //Person p5("Basdasfasfb", "Johnsonokoskosk", 5);
    
    tree.insert(p1);
    tree.insert(p2);
    tree.insert(p3);
    tree.insert(p4);
    std::vector<int> actual;
    std::vector<int> expected = {4, 3, 1, 2};
    auto visit = [&](BinaryTree<Person>::node* n) {
        //std::cout << n->key.GetName() << " " << n->key.GetLastName() << " (ID: " << n->key.GetId() << ")" << std::endl;
        actual.push_back(n->key.GetId());
    };
    tree.RightLeftRoot(tree.GetRoot(), visit);
    std::cout << "tests_for_RightLeftRoot:" << std::endl;
    std::cout << "Expected: " << expected;
    std::cout << std::endl;
    std::cout << "Actual:   " << actual;
    std::cout << std::endl;
    return true?actual==expected:false;
}

bool tests_for_LeftRightRoot(){
    BinaryTree<Person> tree;

    Person p1("John", "Doe", 1);
    Person p2("Jane", "Doe", 2);
    Person p3("Alice", "Smith", 3);
    Person p4("Bob", "Johnson", 4);
    
    tree.insert(p1);
    tree.insert(p2);
    tree.insert(p3);
    tree.insert(p4);
    std::vector<int> actual;
    std::vector<int> expected = {1, 4, 3, 2};
    auto visit = [&](BinaryTree<Person>::node* n) {
        //std::cout << n->key.GetName() << " " << n->key.GetLastName() << " (ID: " << n->key.GetId() << ")" << std::endl;
        actual.push_back(n->key.GetId());
    };
    tree.LeftRightRoot(tree.GetRoot(), visit);
    std::cout << "Expected: " << expected;
    std::cout << std::endl;
    std::cout << "Actual:   " << actual;
    std::cout << std::endl;
    return true?actual==expected:false;
}

bool tests_for_RightRootLeft(){
    BinaryTree<Person> tree;

    Person p1("John", "Doe", 1);
    Person p2("Jane", "Doe", 2);
    Person p3("Alice", "Smith", 3);
    Person p4("Bob", "Johnson", 4);

    tree.insert(p1);
    tree.insert(p2);
    tree.insert(p3);
    tree.insert(p4);

    std::vector<int> actual;
    std::vector<int> expected ={4,3,2,1};
    auto visit = [&](BinaryTree<Person>::node* n){
        //std::cout << n->key.GetName() << " " << n->key.GetLastName() << " (ID: " << n->key.GetId() << ")" << std::endl;
        actual.push_back(n->key.GetId());
    };
    tree.RightRootLeft(tree.GetRoot(), visit);
    std::cout << "tests_for_RightRootLeft:" << std::endl;
    std::cout << "Expected: " << expected;
    std::cout << std::endl;
    std::cout << "Actual:   " << actual;
    std::cout << std::endl;
    return true?actual==expected:false;
}

bool tests_for_LeftRootRight(){
    BinaryTree<Person> tree;

    Person p1("John", "Doe", 1);
    Person p2("Jane", "Doe", 2);
    Person p3("Alice", "Smith", 3);
    Person p4("Bob", "Johnson", 4);

    tree.insert(p1);
    tree.insert(p2);
    tree.insert(p3);
    tree.insert(p4);

    std::vector<int> actual;
    std::vector<int> expected ={1,2,3,4};
    auto visit = [&](BinaryTree<Person>::node* n){
        //std::cout << n->key.GetName() << " " << n->key.GetLastName() << " (ID: " << n->key.GetId() << ")" << std::endl;
        actual.push_back(n->key.GetId());
    };
    tree.LeftRootRight(tree.GetRoot(), visit);
    std::cout << "tests_for_LeftRootRight:" << std::endl;
    std::cout << "Expected: " << expected;
    std::cout << std::endl;
    std::cout << "Actual:   " << actual;
    std::cout << std::endl;
    return true?actual==expected:false;
}

bool tests_for_RootLeftRight(){
    BinaryTree<Person> tree;

    Person p1("John", "Doe", 1);
    Person p2("Jane", "Doe", 2);
    Person p3("Alice", "Smith", 3);
    Person p4("Bob", "Johnson", 4);

    tree.insert(p1);
    tree.insert(p2);
    tree.insert(p3);
    tree.insert(p4);

    std::vector<int> actual;
    std::vector<int> expected ={2,1,3,4};
    auto visit = [&](BinaryTree<Person>::node* n){
        //std::cout << n->key.GetName() << " " << n->key.GetLastName() << " (ID: " << n->key.GetId() << ")" << std::endl;
        actual.push_back(n->key.GetId());
    };
    tree.RootLeftRight(tree.GetRoot(), visit);
    std::cout << "tests_for_RootLeftRight:" << std::endl;
    std::cout << "Expected: " << expected;
    std::cout << std::endl;
    std::cout << "Actual:   " << actual;
    std::cout << std::endl;
    return true?actual==expected:false;
}

bool tests_for_RootRightLeft(){
    BinaryTree<Person> tree;

    Person p1("John", "Doe", 1);
    Person p2("Jane", "Doe", 2);
    Person p3("Alice", "Smith", 3);
    Person p4("Bob", "Johnson", 4);

    tree.insert(p1);
    tree.insert(p2);
    tree.insert(p3);
    tree.insert(p4);

    std::vector<int> actual;
    std::vector<int> expected ={2,3,4,1};
    auto visit = [&](BinaryTree<Person>::node* n){
        //std::cout << n->key.GetName() << " " << n->key.GetLastName() << " (ID: " << n->key.GetId() << ")" << std::endl;
        actual.push_back(n->key.GetId());
    };
    tree.RootRightLeft(tree.GetRoot(), visit);
    std::cout << "tests_for_RootRightLeft:" << std::endl;
    std::cout << "Expected: " << expected;
    std::cout << std::endl;
    std::cout << "Actual:   " << actual;
    std::cout << std::endl;
    return true?actual==expected:false;
}

bool tests_for_insertion(){
    BinaryTree<int> tree;
    std::vector<int> elems;
    for(int i = 0; i < 100; ++i){elems.push_back(i);}
    std::random_shuffle(elems.begin(), elems.end());
    for(int i = 0; i < elems.size(); ++i){
        tree.insert(elems[i]);
    }
    std::vector<int> actual;
    std::vector<int> expected;
    for(int i = 0; i < 100; ++i){expected.push_back(i);}
    
    auto visit = [&](BinaryTree<int>::node* n){
        actual.push_back(n->key);
    };
    tree.LeftRootRight(tree.GetRoot(), visit);
    
    return true?actual==expected:false;
}

bool tests_for_removal(){
    BinaryTree<Person> tree;

    Person p1("John", "Doe", 1);
    Person p2("Jane", "Doe", 2);
    Person p3("Alice", "Smith", 3);
    Person p4("Bob", "Johnson", 4);
    Person p5("Bilbo", "Baggins", 5);
    
    tree.insert(p1);
    tree.insert(p2);
    tree.insert(p3);
    tree.insert(p4);
    tree.insert(p5);

    tree.remove(p3);

    std::vector<int> expected = {1,2,4,5};
    std::vector<int> actual;
    auto visit = [&](BinaryTree<Person>::node* n){
        actual.push_back(n->key.GetId());
    };
    tree.LeftRootRight(tree.GetRoot(), visit);
    return true?actual==expected:false;
}

bool tests_for_merge(){
    BinaryTree<Person> tree1;
    Person p1("John", "Doe", 1);
    Person p2("Jane", "Doe", 2);
    Person p3("Alice", "Smith", -3);
    Person p4("Bob", "Johnson", 7);
    Person p5("Bilbo", "Baggins", 5);
    tree1.insert(p1);
    tree1.insert(p2);
    tree1.insert(p3);
    tree1.insert(p4);
    tree1.insert(p5);

    BinaryTree<Person> tree2;
    Person p12("Jerry", "Gondos", -1);
    Person p22("Jim", "Carry", 6);
    Person p32("Alice", "Cooper", 3);
    Person p42("Bob", "Dylan", 4);
    Person p52("Will", "Smith", 8);
    tree2.insert(p12);
    tree2.insert(p22);
    tree2.insert(p32);
    tree2.insert(p42);
    tree2.insert(p52);
    tree1.merge(tree2);
    std::vector<int> actual;
    std::vector<int> expected = {-3, -1, 1, 2, 3, 4, 5, 6, 7, 8};
    auto visit = [&](BinaryTree<Person>::node* n){
        actual.push_back(n->key.GetId());
    };
    tree1.LeftRootRight(tree1.GetRoot(), visit);
    std::cout << "Tests_for_merge:" << std::endl;
    std::cout << "Expected: " << expected;
    std::cout << std::endl;
    std::cout << "Actual:   " << actual;
    std::cout << std::endl;
    return true?actual==expected:false;
}

int main(){
    assert(tests_for_RightLeftRoot());
    assert(tests_for_LeftRightRoot());
    assert(tests_for_RightRootLeft());
    assert(tests_for_LeftRootRight());
    assert(tests_for_RootLeftRight());
    assert(tests_for_RootRightLeft());
    assert(tests_for_insertion());
    assert(tests_for_removal());
    assert(tests_for_merge());

    
    std::cout << "All tests passed!";
}

