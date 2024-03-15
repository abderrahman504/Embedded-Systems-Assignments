#include "DataStructures.h"


namespace DataStructures
{
    DynamicArray::DynamicArray(int initialCapacity){
        this->capacity = initialCapacity;
        this->_size = 0;
        this->arr = new float[capacity];
    }

    DynamicArray::~DynamicArray() {delete[] this->arr;}

    int DynamicArray::size() {return this->_size;}

    void DynamicArray::add(float val){
        if(this->_size == this->capacity){
            this->capacity *= 2;
            float* temp = new float[capacity];
            for(int i = 0; i < this->_size; i++) temp[i] = this->arr[i];
            delete[] this->arr;
            this->arr = temp;
        }
        this->arr[this->_size] = val;
        this->_size++;
    }

    float DynamicArray::remove(){
        if(this->_size == 0){
            return 0;
        }
        else if (this->_size <= this->capacity/4)
        {
            this->capacity /= 2;
            float* temp = new float[capacity];
            for(int i = 0; i < this->_size; i++) temp[i] = this->arr[i];
            delete[] this->arr;
            this->arr = temp;
        }
        this->_size--;
        return this->arr[this->_size];
    }

    float DynamicArray::operator[](int index){
        if(index < 0 || index >= this->_size){
            return 0;
        }
        return this->arr[index];
    }

}