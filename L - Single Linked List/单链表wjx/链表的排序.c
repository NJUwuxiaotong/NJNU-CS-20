//链表的排序：实际是数值的排序交换，并不需要交换指针的指向那么麻烦
//           类似的：删除的不一定是一个节点，删除一个值将所有值提前，然后删除最后一个节点也是一种方法（但是很慢）
//                        /*这也是链表的一个优势，删除直接删除一个点即可*/ 
//           在这里值的排序即可，较为方便 （需要找到该节点和它的上一个节点）



//线性表的排序,采用冒泡排序,直接遍历链表   /*   1    */
void Listsort(Node* & head) {
    int i = 0;
    int j = 0;
    //用于变量链表
    Node * L = head;
    //作为一个临时量
    Node * p;
    Node * p1;
    //如果链表为空直接返回
    if (head->value == 0)return;

    for (i = 0; i < head->value - 1; i++) {
        L = head->next;
        for (j = 0; j < head->value - i - 1; j++) {
            //得到两个值
            p = L;
            p1 = L->next;
            //如果前面的那个比后面的那个大，就交换它们之间的是数据域
            if (p->value > p1->value) {
                Elemtype temp = p->value;
                p->value = p1->value;
                p1->value = temp;
            }
            L = L->next;
        }
    }
} 



//将链表中的值放进数组，对数组排序，然后再存回去  /*   2     */


void Listsort_1(Node* & head) {
    int i = 0;
    int j = 0;
    //用于变量链表
    Node * L = head;
    //如果链表为空直接返回
    if (head->value == 0)return;
    Elemtype * copy = new Elemtype[head->value];
    //变量链表，存放数组
    for (i = 0; i < head->value; i++) {
        L = L->next;
        copy[i] = L->value;
    }
    //调用STL中的sort函数
    sort(copy, copy + head->value);
    L = head;
    //存放回链表中
    for (i = 0; i < head->value; i++) {
        L = L->next;
          L->value= copy[i];
    }
}



//交换节点排序         /*        3          * /

void swap_node(Node * & head,int i,int j) {//头节点，和需要交换的两节点的位置 
    if (i<1 || j<1 || i>head->value || j >head->value) {
        cout << "请检查位置是否合法" << endl;
        return;
    }
    if (i == j)
    {
        return;
    }
    if (abs(i - j) == 1) {
        Node * pre;
        if (i < j)//交换相邻两节点 （需要三个位置的标记） 
            pre = getitem(head, i);
        else
            pre = getitem(head, j);
        Node * a = pre->next;
        Node * b = a->next;
        pre->next = b;
        a->next = b->next;
        b->next = a;
        return;
    }
	//交换任意两节点（需要6个位置的标记） 
    Node * a = getitem(head, i);
    Node * b = getitem(head, j);
    Node * p = a->next;
    Node * q = b->next;
    Node * p_next = p->next;
    Node * q_next = q->next;
    a->next = q;
    q->next = p_next;
    b->next = p;
    p->next = q_next;
} 
Node * getitem(Node * & head, int i) {
    int j = 0;
    Node * L = head;
    if (i<1 || i >head->value)return NULL;
    while (j < i - 1) {
        L = L->next;
        ++j;
    }
    return L;
}
       //线性表的排序，交换结点
void Listsort_Node(Node* & head) {
    int i = 0;
    int j = 0;
    //用于变量链表
    Node * L = head;
    //作为一个临时量
    Node * p;
    Node * p1;
    //如果链表为空直接返回
    if (head->value == 0)return;
    int flag = 0;
    cout << head->value << endl;
    for (i = 0; i < head->value - 1; i++) {
        L = head->next;
        for (j = 0; j < head->value - 1 - i; j++) {
            //交换了结点，那么就已经在交换结点的时候，把L移动到下一个结点了（因为只是左右交换），所以不要
            //再执行：L = L->next;，否则会报错的
            if (L->value > L->next->value) {
                flag = 1;
                swap_node(head, j + 1, j + 2);

            }
            if (flag == 1) {
                flag = 0;
            }
            else {
                L = L->next;
            }

        }   
    }
}










