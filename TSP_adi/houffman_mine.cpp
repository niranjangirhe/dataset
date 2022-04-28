#include<bits/stdc++.h>

using namespace std;

typedef struct treenode{

    char val;
    int freq;
    struct treenode* left;
    struct treenode* right;


}treenode;
int insert_heap(treenode *heap[],treenode *node,int heap_size)
{
    int current;
    heap_size++;
    heap[heap_size]=node;
    current = heap_size;
    treenode * temp = NULL;
    while(current>1)
    {
        if(heap[current]->freq < heap[current/2]->freq)
        {
            temp = heap[current];
            heap[current] = heap[current/2];
            heap[current/2] = temp;

            current = current/2;
        }
        else
            break;
    }
    return heap_size;

}
treenode *delete_heap(treenode *heap[],int *heap_size)
{
    int current;
    treenode *temp = NULL;
    treenode *first = heap[1];
    heap[1] = heap[*heap_size];
    *heap_size = *heap_size-1;
    current =1;
    int x=0;
    while(1)
          {
              int left = current * 2;
              int right = (current*2)+1;
              if(left <= *heap_size && heap[current]->freq > heap[left]->freq)
              {
                  if(right <= *heap_size)
                  {
                      if(heap[left]->freq < heap[right]->freq)
                      {
                          x = left;
                      }
                      else
                      {
                          x = right;
                      }
                  }
                  else
                  {
                      x= left;
                  }
                  temp = heap[x];
                  heap[x] = heap[current];
                  heap[current] = temp;

                  current = x;
              }
              else
                 break;

          }
          return first;
}
void print_codes(treenode *root,int arr[],int top)
{
    if(root->left)
    {
        arr[top]=0;
        print_codes(root->left,arr,top+1);
    }
    if(root->right)
    {
        arr[top]=1;
        print_codes(root->right,arr,top+1);
    }
    if(root->left == NULL && root->right == NULL)
    {
        cout<<endl<<"The code of "<<root->val<<"is :";
        for(int i=0;i<top;i++)
        {
            cout<<""<<arr[i];
        }
    }
}
int main()
{
    int n,i,f,heap_size = 0;
    char ch;
    treenode * heap[100];
    treenode * node = NULL;
    treenode * t1 = NULL;
    treenode * t2 = NULL;
    treenode * parent = NULL;
    cout<<"Enter the Number of Characters :";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<endl<<"Enter the Character "<<i+1<<" : ";
        cin>>ch;
        cout<<endl<<"Enter the Frequency "<<i+1<<" : ";
        cin>>f;
        node = new(treenode);
        node->val = ch;
        node->freq  = f;
        node->left = NULL;
        node->right = NULL;
        heap_size = insert_heap(heap,node,heap_size);
    }
    while(heap_size != 1)
    {
        t1 = delete_heap(heap,&heap_size);
        t2 = delete_heap(heap,&heap_size);
        parent = new(treenode);
        parent->val = '$';
        parent -> freq = t1->freq + t2->freq;
        parent -> left =t1;
        parent -> right =t2;
        heap_size = insert_heap(heap,parent,heap_size);
    }
    parent = delete_heap(heap,&heap_size);

    int arr[100];
    int top = 0;
    print_codes(parent,arr,top);

}
