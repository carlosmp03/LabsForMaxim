#include <iostream>
#include "binary_tree.cpp"  

void printMenu() {
    std::cout << "AVL Tree Operations Menu:\n";
    std::cout << "1. Insert a node\n";
    std::cout << "2. Remove a node\n";
    std::cout << "3. Search for a node\n";
    std::cout << "4. Display tree (Left->Root->Right)\n";
    std::cout << "5. Merge another tree\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    BinaryTree<int> tree;
    int choice;
    while (true) {
        printMenu();
        std::cin >> choice;

        if (choice == 6) {
            break;
        }

        int value;

        switch (choice) {
            case 1:
                std::cout << "Enter integer value: ";
                std::cin >> value;
                tree.insert(value);
                std::cout << "Node inserted.\n";
                break;

            case 2:
                std::cout << "Enter integer value to remove: ";
                std::cin >> value;
                tree.remove(value);
                std::cout << "Node removed.\n";
                break;

            case 3:
                std::cout << "Enter integer value to search for: ";
                std::cin >> value;
                if (tree.contains(tree.GetRoot(), value)) {
                    std::cout << "Node found.\n";
                } else {
                    std::cout << "Node not found.\n";
                }
                break;

            case 4:
                std::cout << "Tree elements (Left->Root->Right):\n";
                tree.LeftRootRight(tree.GetRoot(), [](auto* node) {
                    std::cout << node->key << "\n";
                });
                break;

            case 5: {
                BinaryTree<int> otherTree;
                int numNodes;
                std::cout << "Enter number of nodes in the other tree: ";
                std::cin >> numNodes;
                for (int i = 0; i < numNodes; ++i) {
                    std::cout << "Enter integer value for node " << i + 1 << ": ";
                    std::cin >> value;
                    otherTree.insert(value);
                }
                tree.merge(otherTree);
                std::cout << "Trees merged.\n";
                break;
            }

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
