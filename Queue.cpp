//
// Created by Yonatan Rappoport on 31/05/2023.
//

#include "Queue.h"

template <class T>
void Queue<T>::pushBack(T value) {
    Node<T> node(value);
    node.SetNext(m_tail);
    m_tail.SetPrev(node);
    m_tail = node;
    ++m_size;
}

template <class T>
T& Queue<T>::front() const {
    return m_head.GetValue();
}


template <class T>
void Queue<T>::popFront() {
    m_head.GetPrev().GetNext() = 0;
    m_head.~Node();
    m_size--;
}

/*template <class T>
void Queue<T>::popFront() {
    m_tail.GetNext().SetPrev(0);
    m_tail.~Node();
    m_tail = m_tail.GetNext();
    --m_size;
}*/

template <class T>
int Queue<T>::size() const {
    return m_size;
}

template <class T>
Queue<T>& filter(Queue<T> &queue, bool (*FilterFunction)(T)) {
    Queue<T> result = new Queue<T>();

    for(T element : queue) {
        if(FilterFunction(element)) { // todo: fix if
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
}




template <class T>
typename Queue<T>::Iterator Queue<T>::begin() const {
    return Iterator(m_head);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end() const {
    return Iterator(m_tail);
}

template <class T>
Queue<T>::Iterator::Iterator(Node<T> node) :
    m_node(node)
{
    assert(node != 0);
}

template <class T>
const T& Queue<T>::Iterator::operator*() const {
    assert(m_node != 0);
    return m_node.GetValue();
}

template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++() {
    m_node = m_node.SetPrev();
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
    return (m_node.GetPrev() == iterator.m_node.GetPrev() &&
            m_node.Getnext() == iterator.m_node.GetNext() &&
            m_node.GetValue() == iterator.m_node.GetValue());
}

template <class T>
bool Queue<T>::Iterator::operator!=(const Iterator& iterator) const {
    return !(*this == iterator);
} // Iterator
