#include "DataStructures.h"


namespace DataStructures
{
    template<class T> Queue<T>::Queue(int capacity){
        this->capacity = capacity;
        this->size = 0;
        this->arr = new T[capacity];
    }

    template<class T> Queue<T>::~Queue() {delete[] this->arr;}

    template<class T> int Queue<T>::size() {return this->size;}

    template<class T> bool Queue<T>::enqueue(T val){
        if(this->size == this->capacity){
            return false;
        }
        this->arr[this->size] = val;
        this->size++;
        return true;
    }

    template<class T> T Queue<T>::dequeue(){
        if(this->size == 0){
            return NULL;
        }
        this->size--;
        this.head = (this->head+1) % this->capacity;
        return this->arr[this->head - 1];
    }

    template<class T> T Queue<T>::peak(){
        if(this->size == 0){
            return NULL;
        }
        return this->arr[this->size];
    }

}