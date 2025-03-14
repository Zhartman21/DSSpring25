#define MAX_SIZE 100


typedef struct {
    int q1[MAX_SIZE];
    int q1top;
} MyStack;


MyStack* myStackCreate() {
    MyStack *stack = (MyStack*)malloc(sizeof(MyStack));// init memory for stack
    stack->q1top = -1; // set queue to null
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if(obj->q1top < MAX_SIZE - 1){ //check if full
        obj->q1[++obj->q1top]= x; // set queue top to x
    }
    else{
        printf("Stack overflow\n");
    }
}

int myStackPop(MyStack* obj) {
    if(obj->q1top == -1){ //check if empty
        printf("Stack underflow\n");
        return -1;
    }
    return obj->q1[obj->q1top--]; //remove top element
}

int myStackTop(MyStack* obj) {
    if(obj->q1top == -1){   //check empty
        printf("Stack is empty\n");
        return -1;
    }
    return obj->q1[obj->q1top];//return top value
}

bool myStackEmpty(MyStack* obj) {
    return obj->q1top == -1; //return true if <0
}

void myStackFree(MyStack* obj) {
    free(obj); //release memory 
}
