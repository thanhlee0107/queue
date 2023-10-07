void add(int element)
{
    Node*temp=new Node(element, NULL,NULL);
    temp->value=element;
    if(count==0){
        head=temp;
    }
    else{
        tail->next=temp;
    }
    temp->prev=tail;
    count++;
    tail=temp;
}

void add(int index, int element)
{
    if(index==count||count==0) return add(element);
    else if(index==0){
        Node*temp=new Node(element);
        temp->value=element;
        temp->next=head;
        head->prev=temp;
        head=temp;
        count++;
    }
    else if(index>0&&index<count){
        Node*temp=new Node(element);
        temp->value=element;
        Node*pos;
        if(index<count/2){
            pos=head;
            for(int i=0;i<index-1;i++){
                pos=pos->next;
            }
            temp->next=pos->next;
            temp->prev=temp;
            (pos->next)->prev=temp;pos->next=temp;
        }
        else {
            pos=tail;
                for(int i=count-1;i>index;i--){
                   pos=pos->prev; 
                }
                temp->prev=pos->prev;
                temp->next=pos;
                (pos->prev)->next=temp;
                pos->prev=temp;
            
        }
        count++;
    }
    else throw out_of_range("Index is out of range");
}

int removeAt(int index)
{   
    if(count==1){
        int temp=head->value;
        delete head;
        count--;
        head=tail=nullptr;
        return temp;
    }
    else if(index==0){
        int val=head->value;
        head=head->next;
        delete (head->prev);
        head->prev=nullptr;
        count--;
        return val;
    }
    else if(index<count&&index>0){
        if(index<count/2){
            Node*temp=head;
            for(int i=0;i<index-1;i++){
                temp=temp->next;
            }
            Node*clone=temp->next;
            int val=clone->value;
            temp->next=clone->next;
            (clone->next)->prev=temp;
            delete clone;
            count--;
            return val;
        }
        else{
            Node*temp=tail;
            for(int i=count-1;i>index;i--){
                temp=temp->prev;
            }
            int val=temp->value;
            if(index!=count-1){
                Node*clone=temp->prev;
                (clone->next)=temp->next;
                (temp->next)->prev=clone;
                delete temp;
            }
            else {
                Node*clone=temp->prev;
                clone->next=nullptr;
                delete temp;
                tail=clone;
            }
            count--;
            return val;
        }
    }
    else {
        throw std::out_of_range("Index is out of range");        }
        return 0;
}

bool removeItem(int element)
{   if(indexOf(element)!=-1)
    {int i=indexOf(element);
            removeAt(i);
            return true;}
    return false;
}


int get(int index)
{   
    if(index<0||index>=count){
        throw out_of_range("Index is out of range");
    }
    Node*temp;
        if(index<count/2){
            temp=this->head;
            for(int i=0;i<index;i++){
                temp=temp->next;
            }
        }
        else{
            temp=tail;
            for(int i=count-1;i>index;i--){
                temp=temp->prev;
            }
        }   
    
    return temp->value;
}

void set(int index, int element)
{   Node*temp;
        if(index<count/2){
            temp=this->head;
            for(int i=0;i<index;i++){
                temp=temp->next;
            }
            temp->value=element;
        }
        else if(index>=count/2){
            temp=tail;
            for(int i=count-1;i>index;i--){
                temp=temp->prev;
            }
            temp->value=element;
        }
    
    else throw std::out_of_range("Index is out of range");

}

int indexOf(int element)
{   Node*temp=head;
    for(int i=0;i<count;i++){
        if(temp->value==element) return i;
        temp=temp->next;
    }
    return -1;
}

bool contains(int element)
{   if(indexOf(element)!=-1) return true;
    return false;
}

int size()
{   
    return count;
}

bool empty()
{   if(count) return false;
    return true;
}

void clear()
{
    while(count){
        removeAt(0);
    }
}