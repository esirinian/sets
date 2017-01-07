//
//  set.hpp
//  
//
//  Created by Eric Sirinian on 11/1/16.
//
//

#ifndef set_hpp
#define set_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

template <class T>
class Set
{
private:
    static const int DEFAULT_SIZE = 5;
    T *set;
    int pSize, numElements;
public:
    Set<T>(int n = DEFAULT_SIZE);
    Set<T>(Set<T> &copy);
    Set<T>(T [] , int size);
    
    ~Set<T>();
    
    int size();
    void expand(int n);
    bool duplicate(T n);
    void insert(T n);
    void userInput();
    void display();
    Set<T> join(Set<T> set2);
    Set<T> intersect(Set<T> set2);
    int getNumElements();
    
    Set<T> operator+(Set<T> set2)
    {
        T set3;
        set3 = join(set2);
        return set3;
    }
    
    Set<T> operator^(Set<T> set2)
    {
        T set3;
        set3 = intersect(set2);
        return set3;
    }
    
};


template <class T>
Set<T>::Set(int n)
{
    set = new T [n];
    pSize = n;
    numElements = 0;
}

template <class T>
Set<T>::Set(Set<T> &copy)
{
    pSize = copy.pSize;
    set = new T[pSize];
    for(int i = 0; i < pSize; i++)
    {
        set[i] = copy.set[i];
    }
}

template <class T>
Set<T>::Set(T a[], int size)
{
    set = new T [size];
    pSize = size;
    numElements = 0;
    for(int i = 0; i < size; i++)
    {
        insert(a[i]);
    }
    
}

template <class T>
Set<T>::~Set<T>()
{
    //delete [] set;
}

template <class T>
void Set<T>::expand(int n)
{
    if(n + numElements > pSize)
    {
        pSize += n - 1;
        
        T *temp = new T [pSize];
        
        for(int i = 0; i < numElements; i++)
        {
            temp[i] = set[i];
        }
        
        delete[] set;
        
        set = temp;
    }
}

template <class T>
bool Set<T>::duplicate(T n)
{
    bool dupe = false;
    for(int i = 0; i < numElements; i++)
    {
        if(set[i] == n)
            dupe = true;
    }
    return dupe;
}

template <class T>
void Set<T>::insert(T n)
{
    if(!duplicate(n))
    {
        if(numElements >= pSize)
        {
            expand(pSize);
        }
        set[numElements] = n;
        numElements++;
    }
}

template <class T>
void Set<T>::userInput()
{
    int elements = 0;
    T value;
    
    cout << "Amount of elements: ";
    cin >> elements;
    
    if(numElements + elements > pSize)
        expand(elements);
    
    
    cout << "Enter values separated by spaces: ";
    for(int i = 0; i < elements; i++)
    {
        cin >> value;
        if(!duplicate(value))
        {
            set[numElements] = value;
            numElements++;
        }
    }
}

template <class T>
Set<T> Set<T>::join(Set<T> newSet)
{
    int *tempSet = new int[pSize];
    T returnSet = newSet;
    
    for(int i = 0; i < numElements; i++)
    {
        tempSet[i] = set[i];
    }
    
    delete[] set;
    
    for(int i = 0; i < numElements; i++)
    {
        returnSet.insert(tempSet[i]);
    }
    
    return returnSet;
}

template <class T>
Set<T> Set<T>::intersect(Set<T> newSet)
{
    int size = numElements;
    T tempSet(size);
    int index = 0;
    
    for (int i = 0; i < numElements; i++)
    {
        if(newSet.duplicate(set[i]))
        {
            tempSet.set[index] = set[i];
            index++;
        }
        else
        {
            size--;
        }
    }
    
    tempSet.numElements = size;
    
    return tempSet;
    
}

template <class T>
void Set<T>::display()
{
    cout << "{";
    for(int i = 0; i < numElements; i++)
    {
        cout << set[i];
        if(i == numElements - 1)
            cout << "}" << endl;
        else
            cout << ", ";
    }
}
#endif /* set_hpp */
