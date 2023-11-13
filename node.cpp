#include <iostream>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}

    void setChildren(Node* v) {
        if (v->value > value) {
            if (right == nullptr) {
                right = v;
            } else {
                right->setChildren(v);
            }
        } else if (v->value < value) {
            if (left == nullptr) {
                left = v;
            } else {
                left->setChildren(v);
            }
        }
    }

    Node* getNodeByValue(int v) {
        if (v == this->value) return this;
        // right
        if (v > this->value) {
            if (!this->right) throw std::invalid_argument("Node not found");

            return this->right->getNodeByValue(v);
        }

        if (!this->left) throw std::invalid_argument("Node not found");

        return this->left->getNodeByValue(v);
    }

    void inOrderTraversCall() {
        if (this->left) this->left->inOrderTraversCall();
        std::cout << "Node: " << this->value << std::endl;
        if (this->right) this->right->inOrderTraversCall();
    }
};