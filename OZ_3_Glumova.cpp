#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node*& head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* ptr = head;
        for (int i = 0; i < position - 1 && ptr != nullptr; ++i) {
            ptr = ptr->next;
        }
        if (ptr != nullptr) {
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }
}

void deleteNode(Node*& head, int position) {
    if (head == nullptr) return;

    Node* ptr = head;
    if (position == 0) {
        head = head->next;
        delete ptr;
    }
    else {
        for (int i = 0; i < position - 1 && ptr != nullptr; ++i) {
            ptr = ptr->next;
        }
        if (ptr != nullptr && ptr->next != nullptr) {
            Node* nodeToDelete = ptr->next;
            ptr->next = ptr->next->next;
            delete nodeToDelete;
        }
    }
}

void printList(Node* head) {
    Node* ptr = head;
    while (ptr != nullptr) {
        cout << "[" << ptr->data << " | " << ptr->next << "] ";
        ptr = ptr->next;
    }
    cout << endl;
}

void Clean(Node*& head) {
    while (head != nullptr) {
        Node* ptr = head;
        head = head->next;
        delete ptr;
    }
}

int main() {
    srand(time(0));

    int n;
    cin >> n;

    if (n <= 2) {
        cout << "Error" << endl;
        return 0;
    }

    Node* head = nullptr;
    for (int i = 0; i < n; ++i) {
        int data = rand() % 101;
        insertNode(head, data, i);
    }

    int choice;
    while (true) {
        cout << "\nMeny\n";
        cout << "1. Add\n";
        cout << "2. Del\n";
        cout << "3. Show list\n";
        cout << "4. Leave\n";
        cout << "Choice action: ";
        cin >> choice;

        if (choice == 1) {
            int data, position;
            cout << " Enter data new element: ";
            cin >> data;
            cout << " Enter position new element: ";
            cin >> position;
            insertNode(head, data, position - 1);
        }
        else if (choice == 2) {
            int position;
            cout << "Enter position element which u want delete: ";
            cin >> position;
            deleteNode(head, position - 1);
        }
        else if (choice == 3) {
            cout << "List: ";
            printList(head);
        }
        else if (choice == 4) {
            cout << "Leave\n";
            break;
        }
        else {
            cout << "Error\n";
        }
    }
    Clean(head);

    return 0;
}
