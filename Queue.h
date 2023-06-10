    //
// Created by Yonatan Rappoport on 31/05/2023.
//

#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

#include <iostream>

// note: implementation: A 2 way linked list with head & tail
// head <-> prev_to_head <-> ... <-> next_to_tail <-> tail


template <class T>
class Queue {
public:
    Queue();
    Queue(const Queue<T> &);
    ~Queue();

    void pushBack(T value);
    T& front() const;
    void popFront();
    int size() const;

    class Iterator;
    Iterator begin() const;
    Iterator end() const;

    class ConstIterator;

    class Node;

    class EmptyQueue : public std::exception{}; // todo: Big red error


private:
    Node *m_head;
    Node *m_tail;
    int m_size;
};

template <class T>
class Queue<T>::Iterator {
public:
    virtual T& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator==(const Iterator& iterator) const;
    bool operator!=(const Iterator& iterator) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;

    class InvalidOperation : public std::exception{};

private:
    Node *m_node;
    explicit Iterator(Node* node);
    friend class Queue<T>;
};

template <class T>
class Queue<T>::ConstIterator {
    public:
        const T& operator*() const;
        ConstIterator& operator++();
        ConstIterator operator++(int);
        bool operator==(const ConstIterator& iterator) const;
        bool operator!=(const ConstIterator& iterator) const;
        ConstIterator(const ConstIterator&) = default;
        ConstIterator(const Iterator&);
        ConstIterator& operator=(const ConstIterator&) = default;

        class InvalidOperation : public std::exception{};

    private:
        Node *m_node;
        explicit ConstIterator(Node* node);
        friend class Queue<T>;
    };

template <class T>
class Queue<T>::Node {
public:
    explicit Node(T value);
    Node();
    Node(const Node&) = default;
    ~Node() = default;

private:
    Node* m_next;
    Node* m_prev;
    T m_value;
};


template <class T>
Queue<T>& filter(Queue<T>& queue, bool (*FilterFunction)(T));

template <class T>  
void transform(Queue<T>& queue, void (*TransformationFunction)(T&));

#endif //EX3_QUEUE_H

