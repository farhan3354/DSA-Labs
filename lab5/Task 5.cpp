#include <iostream>
#include <string>
using namespace std;

class DeliveryQueue {
    int* id;
    string* address;
    int* startTime;
    int* endTime;
    int front, rear, size, capacity;

public:
    DeliveryQueue(int cap) {
        capacity = cap;
        id = new int[capacity];
        address = new string[capacity];
        startTime = new int[capacity];
        endTime = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~DeliveryQueue() {
        delete[] id;
        delete[] address;
        delete[] startTime;
        delete[] endTime;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int p_id, string p_address, int p_startTime, int p_endTime) {
        if (isFull()) {
            cout << "Queue full!\n";
            return;
        }
        rear = (rear + 1) % capacity;
        id[rear] = p_id;
        address[rear] = p_address;
        startTime[rear] = p_startTime;
        endTime[rear] = p_endTime;
        size++;
        cout << "Package added: " << p_id << endl;
    }

    void dequeue(int currentTime) {
        if (isEmpty()) {
            cout << "No packages.\n";
            return;
        }

        if (currentTime > endTime[front]) {
            cout << "Package " << id[front] << " expired!\n";
        } else {
            cout << "Delivered package " << id[front] << endl;
        }

        front = (front + 1) % capacity;
        size--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "No packages.\n";
            return;
        }

        cout << "Next Package:\n";
        cout << "ID: " << id[front] << ", Address: " << address[front]
             << ", Time: " << startTime[front] << "-" << endTime[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "No packages in queue.\n";
            return;
        }

        cout << "Packages in Queue:\n";
        for (int i = 0; i < size; i++) {
            int idx = (front + i) % capacity;
            cout << "ID: " << id[idx] << ", Address: " << address[idx]
                 << ", Time: " << startTime[idx] << "-" << endTime[idx] << endl;
        }
    }
};

int main() {
    DeliveryQueue dq(5);

    dq.enqueue(101, "Lahore", 10, 15);
    dq.enqueue(102, "Karachi", 12, 18);
    dq.enqueue(103, "Islamabad", 9, 11);

    dq.display();

    int currentTime = 16;

    dq.dequeue(currentTime);
    dq.dequeue(currentTime);

    dq.display();

    return 0;
}