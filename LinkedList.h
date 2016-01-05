#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>

template <typename T>
class LinkedList
{
    public:
        LinkedList()
            : firstNode(nullptr),
              lastNode(nullptr),
              currentSize(0)
        {
        }

        ~LinkedList()
        {
            clear();
        }

        int size()
        {
            return currentSize;
        }

        T get(int index)
        {
            if (index < 0 || index >= currentSize)
            {
                throw std::out_of_range("Index out of range");
            }

            Node *node = firstNode;

            for (int i = 0; i < index; i++)
            {
                node = node->nextNode;
            }

            return node->element;
        }

        void add(const T &element)
        {
            Node *newNode = new Node(element);

            if (currentSize == 0)
            {
                firstNode = newNode;
                lastNode = newNode;
                currentSize++;
                return;
            }

            newNode->previousNode = lastNode;
            lastNode->nextNode = newNode;
            lastNode = newNode;
            currentSize++;
        }

        void add(int index, const T &element)
        {
            if (index < 0 || index >= currentSize)
            {
                throw std::out_of_range("Index out of range");
            }

            Node *newNode = new Node(element);

            if (currentSize == 0)
            {
                firstNode = newNode;
                lastNode = newNode;
                currentSize++;
                return;
            }

            Node *precedingNode = firstNode;
            Node *succeedingNode;

            for (int i = 0; i < index - 1; i++)
            {
                precedingNode = precedingNode->nextNode;
            }

            succeedingNode = precedingNode->nextNode;

            newNode->nextNode = succeedingNode;
            newNode->previousNode = precedingNode;
            precedingNode->nextNode = newNode;
            succeedingNode->previousNode = newNode;
            currentSize++;
        }

        void remove(const T &element)
        {
            Node *node = firstNode;
            while (node != nullptr)
            {
                Node *next = node->nextNode;
                Node *previous = node->previousNode;
                if (node->element == element)
                {
                    if (node == firstNode)
                    {
                        firstNode = next;
                    }

                    if (node == lastNode)
                    {
                        lastNode = previous;
                    }

                    if (previous != nullptr)
                    {
                        previous->nextNode = next;
                    }

                    if (next != nullptr)
                    {
                        next->previousNode = previous;
                    }

                    delete node;
                    currentSize--;
                    break;
                }

                node = node->nextNode;
            }
        }

        void clear()
        {
            Node *toDelete = firstNode;
            while (toDelete != nullptr)
            {
                Node *next = toDelete->nextNode;
                delete toDelete;
                toDelete = next;
            }

            firstNode = nullptr;
            lastNode = nullptr;
            currentSize = 0;
        }

    private:
        class Node
        {
            public:
                Node(T element)
                    : element(element),
                      previousNode(nullptr),
                      nextNode(nullptr)
                {
                }

                T element;
                Node *previousNode;
                Node *nextNode;
        };

        Node *firstNode;
        Node *lastNode;
        int currentSize;
};

#endif // LINKEDLIST_H
