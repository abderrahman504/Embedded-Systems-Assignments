#include "DataStructures.h"


namespace DataStructures
{
    template<class T> DynamicArray<T>::DynamicArray(int initialCapacity){
        this->capacity = initialCapacity;
        this->size = 0;
        this->arr = new T[capacity];
    }

    template<class T> DynamicArray<T>::~Queue() {delete[] this->arr;}

    template<class T> int DynamicArray<T>::size() {return this->size;}

    template<class T> void DynamicArray<T>::add(T val){
        if(this->size == this->capacity){
            this->capacity *= 2;
            T* temp = new T[capacity];
            for(int i = 0; i < this->size; i++) temp[i] = this->arr[i];
            delete[] this->arr;
            this->arr = temp;
        }
        this->arr[this->size] = val;
        this->size++;
        return true;
    }

    template<class T> T DynamicArray<T>::remove(){
        if(this->size == 0){
            return NULL;
        }
        else if (this.size <= this->capacity/4)
        {
            this->capacity /= 2;
            T* temp = new T[capacity];
            for(int i = 0; i < this->size; i++) temp[i] = this->arr[i];
            delete[] this->arr;
            this->arr = temp;
        }
        this->size--;
        return this->arr[this->size];
    }

    template<class T> T DynamicArray<T>::operator[](int index){
        if(index < 0 || index >= this->size){
            return NULL;
        }
        return this->arr[index];
    }

}