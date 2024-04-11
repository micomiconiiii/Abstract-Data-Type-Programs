/*
Jhondel Mico N. Abas
BSIT - 2A
BINARY TREE
*/

#include <iostream>
using namespace std;

struct Node {
   char item;
   Node* leftChild;
   Node* rightChild;
   Node(char data) : item(data), leftChild(NULL), rightChild(NULL) {}
};

void inOrder(Node* n);
void preOrder(Node* n);
void postOrder(Node* n);
int result(Node* n);

int main(){
    char a, b, c, d, op1, op2, op3;
    cout << "ALGEBRAIC EXPRESSION\n(a+b)/(c^2-d)\n";    // The expression to be solved
    cout<<"Input a: ";  // user input values
    cin >> a;
    cout<<"Input b: ";
    cin >> b;
    cout<<"Input c: ";
    cin >> c;
    cout<<"Input d: ";
    cin >> d;
    // Building the binary tree
    Node* root = new Node('/');
    root->leftChild = new Node('+');
    root->rightChild = new Node('-');
    root->leftChild->leftChild = new Node(a);
    root->leftChild->rightChild = new Node(b);
    root->rightChild->leftChild = new Node('*');
    root->rightChild->rightChild = new Node(d);
    root->rightChild->leftChild->leftChild = new Node(c);
    root->rightChild->leftChild->rightChild = new Node(c);
    
    cout<<"\nIn-Order: ";
    inOrder(root);
    int evaluate = result(root);
    cout << "\nResult: " << evaluate;
    
}
void inOrder(Node* n){
if (n==NULL){   // return to the previous node if it reaches the null
    return;
    }
inOrder(n->leftChild); // recursively traverse until it reach the null
cout <<n->item<<" ";    // prints the item just before the null
inOrder(n->rightChild); // recursively traverse the right leaf

}
int result(Node *n){
    if (n == nullptr) {
        return 0;
    }
    if (n->item >= '0' && n->item <= '9') {
        return n->item - '0'; // Convert the character to an integer
    }
    
    int leftValue = result(n->leftChild);   // recursively traverse the left subtree
    int rightValue = result(n->rightChild); // recursively traverse the right subtree
    switch (n->item) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue != 0) {
                return leftValue / rightValue;
            } else {
                cout << "Error: Division by zero." << endl;
                return 0;
            }
        default:
            cout << "Error: Invalid operator." << endl;
            return 0;
    }
}
