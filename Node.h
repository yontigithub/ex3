//
// Created by Yonatan Rappoport on 31/05/2023.
//

#ifndef EX3_NODE_H
#define EX3_NODE_H

template <class T>
class Node {
public:
    Node(T value);
    Node();
    Node(const Node<T>&) = default;
    ~Node() = default;

    void SetNext(const Node<T>& next);
    void SetPrev(const Node<T>& prev);
    void SetValue(const T& next);
    Node& GetNext() const;
    Node& GetPrev() const;
    T GetValue() const;

private:
    Node* m_next;
    Node* m_prev;
    T m_value;
};

#endif //EX3_NODE_H
