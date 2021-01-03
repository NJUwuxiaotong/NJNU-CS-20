/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int kthToLast(struct ListNode* head, int k){
    int i,j;
    struct ListNode* p=head;
    for(i=0;p->next!=NULL;i++)
    {p=p->next;};
    p=head;
    i=i+2;
    for(j=0;j<i-k;j++)
    {
        if(j==i-k-1)return p->val;
        p=p->next;
    }
    return 0;
}

