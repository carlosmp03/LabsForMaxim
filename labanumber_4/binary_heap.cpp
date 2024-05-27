#include <iostream>
#include <functional>
#include <string>
#include <cassert>
#include <complex>

class Person{
private:
    std::string Name;
    std::string LastName;
    long int id;
public:
    Person(){}

    Person(std::string n, std::string ln, long int ID): Name(n), LastName(ln), id(ID){}
    long int GetId() const {
        return id;
    }
    std::string GetName() const {
        return Name;
    }
    std::string GetLastName() const {
        return LastName;
    }

    void changeId(const long int id) {
        this->id = id;
    }

    friend bool operator==(const Person& other, const Person& that){
        return that.id == other.id;
    }

    friend bool operator<(const Person& other, const Person& that){
        return other.id < that.id;
    }

    friend bool operator>(const Person& other, const Person& that){
        return other.id > that.id;
    }

    friend bool operator>=(const Person& other, const Person& that){
        return !(other < that);
    }

    friend bool operator<=(const Person& other, const Person& that){
        return !(other > that);
    }
};

template<typename T>
class BinaryTree {
public:
    struct node {
        T key;
        unsigned char height;
        node* right;
        node* left;
        node(T k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

private:
    node* root;
    
public:
    BinaryTree() : root(nullptr) {}

    node* GetRoot() const {
        return root;
    }
    template<typename Func>
    void RootRightLeft(node* node, Func visit) {
        if (node == nullptr) return;
        visit(node);
        RootRightLeft(node->right, visit);
        RootRightLeft(node->left, visit);
    }
    template<typename Func>
    void RootLeftRight(node* node, Func visit) {
        if (node == nullptr) return;
        visit(node);
        RootLeftRight(node->left, visit);
        RootLeftRight(node->right, visit);
    }
    template<typename Func>
    void RightRootLeft(node* node, Func visit) {
        if (node == nullptr) return;
        RightRootLeft(node->right, visit);
        visit(node);
        RightRootLeft(node->left, visit);
    }
    template<typename Func>
    void LeftRootRight(node* node, Func visit) {
        if (node == nullptr) return;
        LeftRootRight(node->left, visit);
        visit(node);
        LeftRootRight(node->right, visit);
    }
    template<typename Func>
    void RightLeftRoot(node* node, Func visit) {
        if (node == nullptr) return;
        RightLeftRoot(node->right, visit);
        RightLeftRoot(node->left, visit);
        visit(node);
    }
    template<typename Func>
    void LeftRightRoot(node* node, Func visit) {
        if (node == nullptr) return;
        LeftRightRoot(node->left, visit);
        LeftRightRoot(node->right, visit);
        visit(node);
    }

    int height(node* p) const {
        return p ? p->height : 0;
    }

    int bfactor(node* p) const {
        return height(p->right) - height(p->left);
    }

    void fixheight(node* p) {
        unsigned char hl = height(p->left);
        unsigned char hr = height(p->right);
        p->height = (hl > hr ? hl : hr) + 1;
    }

    node* rotateright(node* p) {
        node* q = p->left;
        p->left = q->right;
        q->right = p;
        fixheight(p);
        fixheight(q);
        return q;
    }

    node* rotateleft(node* q) {
        node* p = q->right;
        q->right = p->left;
        p->left = q;
        fixheight(q);
        fixheight(p);
        return p;
    }

    node* balance(node* p) {
        fixheight(p);
        if (bfactor(p) == 2) {
            if (bfactor(p->right) < 0) p->right = rotateright(p->right);
            return rotateleft(p);
        }
        if (bfactor(p) == -2) {
            if (bfactor(p->left) > 0) p->left = rotateleft(p->left);
            return rotateright(p);
        }
        return p;
    }

    void insert(T key) {
        root = insert(root, key);
    }

    node* insert(node* p, T key) {
        if (!p) return new node(key);
        if (key < p->key) p->left = insert(p->left, key);
        else p->right = insert(p->right, key);
        return balance(p);
    }

    node* findmin(node* p) {
        return p->left ? findmin(p->left) : p;
    }

    node* removemin(node* p) {
        if (p->left == nullptr) return p->right;
        p->left = removemin(p->left);
        return balance(p);
    }

    void remove(T key) {
        root = remove(root, key);
    }

    node* remove(node* p, T key) {
        if (!p) return nullptr;
        if (key < p->key) {
            p->left = remove(p->left, key);
        } else if (key > p->key) {  // Здесь исправлено сравнение
            p->right = remove(p->right, key);
        } else {
            node* q = p->left;
            node* r = p->right;
            delete p;
            if (!r) return q;
            node* min = findmin(r);
            min->right = removemin(r);
            min->left = q;
            return balance(min);
        }
        return balance(p);
    }


    void merge(const BinaryTree<T>& other) {
        if (other.root) {
            auto insertNode = [this](node* n) {
                this->insert(n->key);
            };
            RootLeftRight(other.GetRoot(), insertNode);
        }
    }
};


int main() {
    BinaryTree<Person> tree;

    Person p1("John", "Doe", 1);
    Person p2("Jane", "Doe", 2);
    Person p3("Alice", "Smith", 3);
    Person p4("Bob", "Johnson", 4);

    tree.insert(p1);
    tree.insert(p2);
    tree.insert(p3);
    tree.insert(p4);

    tree.remove(p2);

    auto visit = [](BinaryTree<Person>::node* n) {
        std::cout << n->key.GetName() << " " << n->key.GetLastName() << " (ID: " << n->key.GetId() << ")" << std::endl;
    };

    std::cout << "Root-Left-Right Traversal:" << std::endl;
    tree.RootLeftRight(tree.GetRoot(), visit);

    return 0;
}
