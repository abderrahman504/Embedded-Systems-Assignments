#include <stdio.h>
#include "DataStructures.h"

int main()
{
    DataStructures::Stack* stack = new DataStructures::Stack(5);
    stack->size();
    printf("Stack size = %d\n", stack->size());
    printf("Pushing 1 to stack.\n");
    stack->push(1);
    // Serial.println("Pushing 5 to stack.");
    // stack.push(5);
    // Serial.println("Pushing 3 to stack.");
    // stack.push(3);
    // Serial.print("Stack size = ");
    // Serial.println(stack->size());
    // Serial.print("Peeking in stack. Found ");
    // Serial.println(stack->peak());
    // Serial.print("Stack size = ");
    // Serial.println(stack->size());
    // Serial.print("Popping from stack. Found");
    // Serial.println(stack->pop());
    // Serial.print("Stack size = ");
    // Serial.println(stack->size());
    // Serial.print("Popping from stack. Found");
    // Serial.println(stack->pop());
    // Serial.print("Stack size = ");
    // Serial.println(stack->size());
    // Serial.print("Popping from stack. Found");
    // Serial.println(stack->pop());
    // Serial.print("Stack size = ");
    // Serial.println(stack->size());
    // Serial.print("Popping from stack. Found");
    // Serial.println(stack->pop());
    // Serial.print("Stack size = ");
    // Serial.println(stack->size());
}