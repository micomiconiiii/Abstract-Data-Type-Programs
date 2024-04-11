/*
JHONDEL MICO N. ABAS
BSIT-2A
Write the ADT Queue operations program using OOP/C++ with the following menu
       MENU
ENQUEUE
DEQUEUE
DISPLAY
EXIT*/

#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 5

typedef struct queue{                               // structure 
    int DATA[MAX];                                  // array
    int front;      
    int rear;
    int count;
} QUEUE;

class ADT{
    private:
    QUEUE Q;
    public:
    void makenull();
    void enqueue(int x);
    int isempty();
    int isfull();
    void dequeue();
    void display();
};
int menu();


int main(){
    
    ADT q;
    int x;
    q.makenull();   // front = 0
    while(true){
        system("cls");
        switch(menu()){
            case 1: //enqueue
            cout << "Enter a number to be inserted: ";
            cin >> x;
            q.enqueue(x);                                   // insert
            break;
            case 2: //dequeue
            q.dequeue();                                    // deletes the front element
            break;
            case 3: //display
            q.display();
            break;
            case 4: //exit
            system("pause");
            exit(0);
            break;
            default:
            cout << "Wrong input!\n";
            system("pause");
            continue;
        }
    }

return 0;
}

void ADT::makenull(){
     Q.front=0;                     // initializze everything to null
     Q.rear=-1;
     Q.count=0;
}

void ADT::enqueue(int x){

    if(isfull()){
        cout << "The array is full\n";
        system("pause");
    }
    else{ // rear + 1
        Q.rear++;                           // since rear is empty, we need to allocate new space
        if(Q.rear==MAX)
            Q.rear=0;                       // circular array implementation wherein if it reaches the final index, it will return to zero as long as the list is not full
        Q.DATA[Q.rear]=x;
        // q.count = 3
        Q.count++;                          // keeps track of how many enqueue happened
    }
}

int ADT::isempty(){
    return (Q.count==0);            // it is empty if the count did not increment, meaning, the list is empty
}

int ADT::isfull(){
    return (Q.count==MAX);          // the array is full not if it reaches the last index, but if it reaches MAX count
}

void ADT::dequeue(){
    if(isempty())
        cout << "The array is empty\n";                           // checks first if array is empty before dequeueing
    else{
        Q.front++;                                              // moves the front index to the next index to remove the first index
        Q.count--;                                              // decrement count since an index is deleted
    // q.count = 2
    }
}
// front = 2 , front=0 + 1 = 1
// count = 4
// 0    1   2   3   4
// a        c   d   e

// a c d e
void ADT::display() {
    int i, j = 1;
    system("cls");

    if (isempty()) {                                            // checks if array is empty
        cout << "The queue is empty\n";
    } 
    else {              
                //  2             4                         // displays the content of the array in circular manner
        for (i = Q.front; j <= Q.count; i++) {                  // iterates first at the front index up to the current count
            if (i == MAX)
                i = 0;                                          // initialize i to 0 if i reaches MAX to iterate circularly
            cout << j << ".) " << Q.DATA[i] << "\n";
            j++;
        }
    }
    getch(); 
}

int menu(){
    int op;
    cout << "1. ENQUEUE\n";
    cout << "2. DEQUEUE\n";
    cout << "3. DISPLAY\n";
    cout << "4. EXIT\n";
    cout << "Enter selection: ";
    cin >> op;
    return op;
}