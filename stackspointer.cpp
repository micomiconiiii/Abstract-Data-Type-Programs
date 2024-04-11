#include <iostream>
#define MAX 5
using namespace std;


class Top{
    private:
    int DATA[MAX];
    int top;
    bool isempty();
    bool isfull();
    public:
    // constructor
    Top(): top(MAX){};
    void push(int x); // add
    void pop(); // deletes the latest input
    void display();
};

bool Top::isempty(){
    return (top==MAX); // returns true if top is equal to MAX, returns false otherwise.
}

bool Top::isfull(){
    return (top==0); // returns true if top is equal to 0, returns false otherwise
}

void Top::push(int x){
    // check first if the stack is full or not
    if (isfull()){
        cout << "List is full already" << endl;
    }
    else{
        top--;
        DATA[top]=x;
        
    }
}
void Top::pop(){
    // check first if list is empty
    if (isempty()){
        cout << "List is empty" << endl;
    }
    else{
        top++;
    }
}
void Top::display(){
    int i, j=1;
    for (int i=top; i<MAX; i++){
        cout << j << ") " << DATA[i] << endl;
        j++;
    } 
}

int main(){
    Top s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    cout << "After one pop" << endl;
    s.display();
}