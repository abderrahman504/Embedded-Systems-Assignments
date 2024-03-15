#include "DataStructures.h"


namespace DataStructures
{
    template<class T> Stack<T>::Stack(int capacity){
        this->capacity = capacity;
        this->size = 0;
        this->arr = new T[capacity];
    }

    template<class T> Stack<T>::~Stack() {delete[] this->arr;}

    template<class T> int Stack<T>::size() {return this->size;}

    template<class T> bool Stack<T>::push(T val){
        if(this->size == this->capacity){
            return false;
        }
        this->arr[this->size] = val;
        this->size++;
        return true;
    }

    template<class T> T Stack<T>::pop(){
        if(this->size == 0){
            return NULL;
        }
        this->size--;
        return this->arr[this->size];
    }

    template<class T> T Stack<T>::peak(){
        if(this->size == 0){
            return NULL;
        }
        return this->arr[this->size];
    }

}