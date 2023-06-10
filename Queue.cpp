//
// Created by Yonatan Rappoport on 31/05/2023.
//

#include "Queue.h"

template <class T>
Queue<T>::Queue() :
    m_head(nullptr),
    m_tail(nullptr),
    m_size(0)
{

}

template <class T>
Queue<T>::Queue(const Queue<T>& queue) :
    m_head(nullptr),
    m_tail(nullptr),
    m_size(queue.m_size)
{
    for(T element : queue) {
        this->pushBack(element);
    }
}

template <class T>
Queue<T>::~Queue() {
    while(this->size()) {
        this->popFront();
    }
} // constructors and destructors

template <class T>
void Queue<T>::pushBack(T value) {
    Node node(value);
    node.m_next = &m_tail;
    ++m_size;

    if(m_tail != nullptr) {
        m_tail.m_prev = &node;
        m_tail = node;
    }
}

template <class T>
T& Queue<T>::front() const {
    return m_head.m_value;
}

template <class T>
void Queue<T>::popFront() {
    m_head.m_prev->m_next = nullptr;
    m_head.~Node();
    m_size--;
}

template <class T>
int Queue<T>::size() const {
    return m_size;
}

template <class T>
Queue<T>& filter(Queue<T> &queue, bool (*FilterFunction)(T)) {
    Queue<T> result = new Queue<T>();

    for(T element : queue) {
        if(FilterFunction(element)) {
            result.push_back(element);
        }
    }

    return result;
}

template <class T>
void transform(Queue<T> &queue, void (*TransformationFunction)(T&))  {
    for(T& element : queue) {
        TransformationFunction(element);
    }
} // methods

template <class T>
typename Queue<T>::Iterator Queue<T>::begin() const {
    return Iterator(m_head);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end() const {
    return Iterator(m_tail);
}

template <class T>
Queue<T>::Iterator::Iterator(Node node) :
    m_node(node)
{
    assert(node != nullptr); // todo: do we need to assert?
}

template <class T>
const T& Queue<T>::Iterator::operator*() const {
    assert(m_node != nullptr); // todo: do we need to assert?
    return m_node.m_value;
}

template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
    m_node = *m_node.m_prev;
    return m_node;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int){
    Iterator result = *this;
    *this++;
    return result;
}

template <class T>
bool Queue<T>::Iterator::operator==(const Iterator& iterator) const {
    return (m_node.m_prev == iterator.m_node.m_prev &&
            m_node.m_next == iterator.m_node.m_next &&
            m_node.m_value == iterator.m_node.m_value);
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator& iterator) const {
    return !(*this == iterator);
} // Iterator

template <class T>
Queue<T>::Node::Node(T value) :
        m_next(nullptr),
        m_value(value)
{

}

template <class T>
Queue<T>::Node::Node() :
        m_next(nullptr),
        m_prev(nullptr),
        m_value(NULL)
{

} // Node