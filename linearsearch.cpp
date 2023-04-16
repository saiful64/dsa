#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
   if (size < 0) {
      return -1; // Key not found
   }
   else if (arr[size] == key) {
      return size; // Key found at index size
   }
   else {
      return linearSearch(arr, size - 1, key); // Recursive call with the size decremented by 1
   }
}#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
   if (size < 0) {
      return -1; // Key not found
   }
   if (arr[size] == key) {
      return size; // Key found at index size
   }
   
      return linearSearch(arr, size - 1, key); // Recursive call with the size decremented by 1
   
}

int main() {
   int arr[] = { 3, 6, 9, 12, 15, 18 };
   int size = sizeof(arr) / sizeof(arr[0]);
   int key = 12;
   
   int index = linearSearch(arr, size - 1, key);
   
   if (index == -1) {
      cout << "Key not found" << endl;
   }
   else {
      cout << "Key found at index " << index << endl;
   }
   
   return 0;
}


int main() {
   int arr[] = { 3, 6, 9, 12, 15, 18 };
   int size = sizeof(arr) / sizeof(arr[0]);
   int key = 12;
   
   int index = linearSearch(arr, size - 1, key);
   
   if (index == -1) {
      cout << "Key not found" << endl;
   }
   else {
      cout << "Key found at index " << index << endl;
   }
   
   return 0;
}
