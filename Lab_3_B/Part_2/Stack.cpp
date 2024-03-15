#include "DataStructures.h"


namespace DataStructures
{
    Stack::Stack(int capacity){
        this->capacity = capacity;
        this->_size = 0;
        this->arr = new float[capacity];
    }

    Stack::~Stack() {delete[] this->arr;}

    int Stack::size() {return this->_size;}

    bool Stack::push(float val){
        if(this->_size == this->capacity){
            return false;
        }
        this->arr[this->_size] = val;
        this->_size++;
        return true;
    }

    float Stack::pop(){
        if(this->_size == 0){
            return 0;
        }
        this->_size--;
        return this->arr[this->_size];
    }

    float Stack::peak(){
        if(this->_size == 0){
            return 0;
        }
        return this->arr[this->_size];
    }

}