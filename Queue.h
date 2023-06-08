//
// Created by Yonatan Rappoport on 31/05/2023.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

#include "Node.h"

// note: implementation: A 2 way linked list with head & tail
// head <-> prev_to_head <-> ... <-> next_to_tail <-> tail


template <class T>
class Queue {
public:
    Queue();
    Queue(const Queue<T> &); // todo: implement methods
    ~Queue();

    void pushBack(T value);
    T& front() const;
    void popFront();
    int size() const;

    class Iterator;
    Iterator begin() const;
    Iterator end() const;

    class EmptyQueue : public std::exception;

private:
    Node<T> m_head;
    Node<T> m_tail;
    int m_size;
};

template <class T>
class Queue<T>::Iterator {
public:
    const T& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& iterator) const;
    bool operator!=(const Iterator& iterator) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;


private:
    Node<T> m_node;
    explicit Iterator(Node<T> node);
    friend class Queue<T>;
};

template <class T>
Queue<T>& filter(Queue<T>& queue, bool (*FilterFunction)(T)); // todo: make support both object ()

template <class T>  
void transform(Queue<T>& queue, void (*TransformationFunction)(T&));

#endif //EX3_QUEUE_H
