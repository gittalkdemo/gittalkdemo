#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdexcept>

template <typename T>
class ArrayList
{
    public:
        ArrayList()
            : capacity(10),
              currentSize(0),
              elements(new T[capacity])
        {
        }

        ArrayList(const ArrayList<T> &) = delete;

        ~ArrayList()
        {
            delete[] elements;
        }

        ArrayList<T> &operator =(const ArrayList<T> &) = delete;

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

            return elements[index];
        }

        void add(const T &element)
        {
            if (currentSize == capacity)
            {
                expand();
            }

            elements[currentSize++] = element;
        }

        void add(int index, const T &element)
        {
            if (index < 0 || index >= currentSize)
            {
                throw std::out_of_range("Index out of range");
            }

            if (currentSize == capacity)
            {
                expand();
            }

            for (int i = currentSize - 1; i >= index; i--)
            {
                elements[i + 1] = elements[i];
            }

            elements[index] = element;
            currentSize++;
        }

        void remove(T element)
        {
            int indexOfRemoved = -1;
            for (int i = 0; i < currentSize; i++)
            {
                if (elements[i] == element)
                {
                    indexOfRemoved = i;
                    break;
                }
            }

            if (indexOfRemoved != -1)
            {
                for (int i = indexOfRemoved; i < currentSize - 1; i++)
                {
                    elements[i] = elements[i + 1];
                }

                currentSize--;
            }
        }

        void clear()
        {
            T *newElements = new T[capacity];
            T *oldElements = elements;
            elements = newElements;
            currentSize = 0;
            delete[] oldElements;
        }

    private:
        void expand()
        {
            T *newElements = new T[capacity * 2];

            for (int i = 0; i < currentSize; i++)
            {
                newElements[i] = elements[i];
            }

            T* tmp = elements;
            elements = newElements;
            capacity *= 2;
            delete[] tmp;
        }

        int capacity;
        int currentSize;
        T *elements;

};

#endif // ARRAYLIST_H
