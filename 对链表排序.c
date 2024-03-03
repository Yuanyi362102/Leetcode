
 #include<stdio.h>
 #include<stdlib.h>
 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    typedef struct ListNode* Node;
    Node cur=list1;
    Node temp;
    Node head=list1;
    Node p=list1;
    int i=0,flag=1;
    if(list1==NULL){
        return list2;
    }
    if(list2==NULL){
        return list1;
    }
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=list2;
    while(i<50){
        cur=head;
        while(cur!=NULL && cur->next!=NULL){
            while(cur!=NULL && cur->next!=NULL && cur->val > cur->next->val ){
                if(cur==head){
                    temp=head->next;
                    head->next=temp->next;
                    temp->next=head;
                    head=temp;
                }
                else{
                    p=head;
                    while(p->next!=cur){
                        p=p->next;
                    }
                    temp=cur->next;
                    cur->next=temp->next;
                    p->next=temp;
                    temp->next=cur;
                }
            }
            cur=cur->next;
        }
        i++;
    }
    return head;
}