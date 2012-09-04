#ifndef MYARRAY_H_INCLUDED
#define MYARRAY_H_INCLUDED

#include <stdexcept>

/*!
\brief A dynamic array that can hold elements of type T.
*/
template <class T>
class MyArray
{
public:
    /*!
    \details Content of this array.
    */
    T* content;

    /*!
    \details Default constructor.
    */
    MyArray(void);

    /*!
    \details Constructs an array from another array.
    \param a Another array.
    */
    MyArray(const MyArray& a);

    /*!
    \details Destructor. Destructs this array.
    */
    ~MyArray(void);

    /*!
    \details Adds an element to this array.
    \param element Element to be added.
    */
    void addElement (T element);

    /*!
    \details Overloaded array-access operator to access an element in this array.
    \param i Index of the element to be accessed.
    \exception std::out_of_range
    \returns Element at index i(by reference).
    */
    T& operator[] (unsigned int i);

    /*!
    \details Assignment operator. Makes a copy of another array and assigns it to this array.
    \param a Another array.
    \returns A reference to this array.
    */
    MyArray& operator = (const MyArray& a);

    /*!
    \details Returns the size of this array.
    \returns The size of this array.
    */
    unsigned int getSize(void);

private:
    unsigned int size;
};

template <class T>
MyArray<T>::MyArray(void)
{
    content = 0;
    size = 0;
}

template <class T>
MyArray<T>::MyArray(const MyArray& a)
{
    size = a.size;
    content = new T[size];

    for (unsigned int i = 0; i < size; i++)
    {
        content[i] = a.content[i];
    }
}

template <class T>
MyArray<T>::~MyArray(void)
{
    delete [] content;
    content = 0;
}

template <class T>
MyArray<T>& MyArray<T>::operator = (const MyArray& a)
{
    if (&a != this)
    {
        delete [] content;
        content = 0;

        size = a.size;
        content = new T[size];

        for (unsigned int i = 0; i < size; i++)
        {
            content[i] = a.content[i];
        }
    }

    return *this;
}

template <class T>
void MyArray<T>::addElement(T element)
{
    T* temp_content = new T[size + 1];
    temp_content[size] = element;

    for (unsigned int i = 0; i < size; i++)
    {
        temp_content[i] = content[i];
    }

    delete [] content;
    content = 0;

    content = temp_content;

    size++;
}

template <class T>
T& MyArray<T>::operator [] (unsigned int i)
{
    if (i < size)
    {
        return content[i];
    }
    else
    {
        std::out_of_range outOfRangeException("MyArray - index out of range.");
        throw outOfRangeException;
    }
}

template <class T>
unsigned int MyArray<T>::getSize(void)
{
    return size;
}

#endif // MYARRAY_H_INCLUDED
