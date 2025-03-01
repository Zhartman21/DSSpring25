struct ListNode* reverseList(struct ListNode* head) {
    //check if list is empty
    if(head == NULL){
        return NULL;
    }
    //allocate spcace for temp prev and next nodes
    struct ListNode *temp , *prev , *next = (struct ListNode*)malloc(sizeof(struct ListNode));
    next, prev = NULL;  //set next and prev to null for use after assigning temp to head

    temp = head; //assign temp to head pointer

    while(temp != NULL){ //while loop that iterates through list and flips the pointers to point to  the previous node
        next = temp->next;
        temp->next = prev;

        prev = temp; // move pointers up the list
        temp = next;
    }
    return prev; //returns now head value
}
