#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// 在链表末尾添加新节点
void appendNode(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 遍历并打印链表
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);

    printList(head);

    //return 0;

    //Node * newNode = new Node;
    //newNode->data = 123;
    //cout << newNode;

    return 0;
}
