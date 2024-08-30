#ifndef STACKS_H
#define STACKS_H

#include <iostream>
#include <cstdlib>

template <typename T>
class Stacks {
    int size;
    int capacity;
    T *arr;

public:
    Stacks() : size(0), capacity(0), arr(nullptr) {}

    Stacks(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        arr = new T[capacity]();
    }

    void setStack(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        arr = new T[capacity]();
    }

    void reStack(int capacity) {
        this->capacity = capacity;
        T *arr1 = new T[capacity]();
        for (int i = 0; i < size; i++) {
            arr1[i] = arr[i];
        }
        delete[] arr;
        arr = arr1;
    }

    bool isEmpty() const {
        return this->size == 0;
    }

    bool isFull() const {
        return this->size == this->capacity;
    }

    int Size() const {
        return size;
    }

    void Push(T value) {
        if (isFull()) {
            std::cout << "Stack overflow" << std::endl;
            return;
        }
        arr[this->size++] = value;
    }

    void Pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow" << std::endl;
            return;
        }
        this->size--;
    }

    T Peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1;  // This return value needs handling for non-int types
        }
        return arr[this->size - 1];
    }

    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    ~Stacks() {
        delete[] arr;
    }
};

#endif
