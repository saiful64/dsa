#include<iostream>

using namespace std;

class CircularQueue {
  private:
    int front;
  int rear;
  int arr[3];
  int itemCount;

  public:
    CircularQueue() {
      itemCount = 0;
      front = -1;
      rear = -1;
      for (int i = 0; i < 3; i++) {
        arr[i] = 0;
      }
    }
  bool isEmpty() {
    if (front == -1 && rear == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if ((rear + 1) % 3 == front)
      return true;
    else
      return false;
  }
  void enqueue(int val) {
    if (isFull()) {
      cout << "Queue full" << endl;
      return;
    } else if (isEmpty()) {
      rear = 0;
      front = 0;
      arr[rear] = val;

    } else {
      rear = (rear + 1) % 3;
      arr[rear] = val;

    }
    itemCount++;

  }

  int dequeue() {
    int x = 0;
    if (isEmpty()) {
      cout << "Queue is Empty" << endl;
      return x;
    } else if (rear == front) {
      x = arr[rear];
      rear = -1;
      front = -1;
      itemCount--;
      return x;
    } else {
      cout << "front value: " << front << endl;
      x = arr[front];
      arr[front] = 0;
      front = (front + 1) % 3;
      itemCount--;
      return x;
    }
  }

  int count() {
    return (itemCount);
  }

  void display() {
    cout << "All values in the Queue are - " << endl;
    for (int i = 0; i < 3; i++) {
      cout << arr[i] << "  ";
    }
  }

};

int main() {
  CircularQueue q1;
  int value, option;

  do {
    cout << "\n\nEnter choice" << endl;
    cout << "1. Enqueue()" << endl;
    cout << "2. Dequeue()" << endl;
    cout << "3. display()" << endl;

    cin >> option;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "\nEnter an item" << endl;
      cin >> value;
      q1.enqueue(value);
      break;
    case 2:
      cout << "\nDequeued Value : " << q1.dequeue() << endl;
      break;
    case 3:
      cout << "Display Function Called - " << endl;
      q1.display();
      break;

    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}