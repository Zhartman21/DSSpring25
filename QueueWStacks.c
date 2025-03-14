#define MAX_SIZE 100


typedef struct {
    int s1[MAX_SIZE];
    int s2[MAX_SIZE];
    int s1Top;
    int s2Top;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));// initialize memory for the queue
    queue->s1Top = -1;//set both top values to empty
    queue->s2Top = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    while(obj->s2Top != -1){                   //check outstack has elements
        obj->s1[++obj->s1Top] = obj->s2[obj->s2Top--];//push output top to input top
    }
    obj->s1[++obj->s1Top] = x;  //push x to input
    while(obj->s1Top != -1){    //check output stack has elements
        obj->s2[++obj->s2Top] = obj->s1[obj->s1Top--]; //pop input to output
    }
}

int myQueuePop(MyQueue* obj) {
    return obj->s2[obj->s2Top--]; // pop output top
}

int myQueuePeek(MyQueue* obj) {
    return obj->s2[obj->s2Top];  //return output top
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->s2Top == -1; //check if top of stack 2 is empty
}

void myQueueFree(MyQueue* obj) {
    free(obj);  //Free up obj in memory
}
