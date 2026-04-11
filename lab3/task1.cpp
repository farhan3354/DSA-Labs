#include <iostream>
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    myStack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }
    
    ~myStack() {
        delete[] arr;
    }
    
    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++topIndex] = value;
        cout << value << " pushed to stack." << endl;
    }
    
    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return T();
        }
        T value = arr[topIndex--];
        cout << value << " popped from stack." << endl;
        return value;
    }
    
    T top() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }
        return arr[topIndex];
    }
    
    bool isEmpty() const {
        return topIndex == -1;
    }
    
    bool isFull() const {
        return topIndex == capacity - 1;
    }
    
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        
        cout << "Stack elements (Top to Bottom): ";
        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter maximum size of stack: ";
    cin >> size;
    
    myStack<int> stack(size);
    int choice, value;
    
    do {
        cout << "1. Push element\n";
        cout << "2. Pop element\n";
        cout << "3. Show top element\n";
        cout << "4. Check if stack is empty\n";
        cout << "5. Check if stack is full\n";
        cout << "6. Display stack elements\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
                
            case 2:
                stack.pop();
                break;
                
            case 3:
                cout << "Top element: " << stack.top() << endl;
                break;
                
            case 4:
                if (stack.isEmpty())
                    cout << "Stack is EMPTY" << endl;
                else
                    cout << "Stack is NOT empty" << endl;
                break;
                
            case 5:
                if (stack.isFull())
                    cout << "Stack is FULL" << endl;
                else
                    cout << "Stack is NOT full" << endl;
                break;
                
            case 6:
                stack.display();
                break;
                
            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while(choice != 7);
    
    return 0;
}