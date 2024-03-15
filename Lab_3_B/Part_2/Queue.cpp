#include "DataStructures.h"


namespace DataStructures
{
    Queue::Queue(int capacity){
        this->capacity = capacity;
        this->_size = 0;
        this->arr = new float[capacity];
    }

    Queue::~Queue() {delete[] this->arr;}

    int Queue::size() {return this->_size;}

    bool Queue::enqueue(float val){
        if(this->_size == this->capacity){
            return false;
        }
        this->arr[this->_size] = val;
        this->_size++;
        return true;
    }

    float Queue::dequeue(){
        if(this->_size == 0){
            return 0;
        }
        this->_size--;
        this->head = (this->head+1) % this->capacity;
        return this->arr[this->head - 1];
    }

    float Queue::peak(){
        if(this->_size == 0){
            return 0;
        }
        return this->arr[this->_size];
    }

}