#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Add for bool type

#define HEAP_SIZE 1000

typedef struct node {
    int data;
    bool mark; // for marking the nodes to use mark and sweep method
    int referenceCount; // reference count method
    size_t size; // Add size member
    struct node* next_1;
    struct node* next_2;
    struct node* next_3;
} node;

node* array[8];
node* heap = NULL; // Global pointer to the start of the heap

void initializeHeap() {
    heap = (node*)malloc(HEAP_SIZE);
    if (heap == NULL) {
        fprintf(stderr, "Heap initialization failed.\n");
        exit(EXIT_FAILURE);
    }
    heap->size = HEAP_SIZE - sizeof(node); // Update size of heap
    heap->next_1 = NULL;
    heap->next_2 = NULL;
    heap->next_3 = NULL;
}

void* myMalloc(size_t size) {
    node* current = heap;
    node* prev = NULL;

    while (current != NULL) {
        if (current->size >= size) {
            if (current->size > size + sizeof(node)) {
                node* newnode = (node*)((char*)current + sizeof(node) + size);
                newnode->size = current->size - size - sizeof(node);
                newnode->next_1 = NULL;
                newnode->next_2 = NULL;
                newnode->next_3 = NULL;
                current->size = size;
                current->next_1 = newnode;
            }

            if (prev == NULL) {
                heap = current->next_1;
            } else {
                prev->next_1 = current->next_1;
            }

            return (void*)(current + 1); // Return pointer after node
        }

        prev = current;
        current = current->next_1;
    }

    fprintf(stderr, "Memory allocation failed. Insufficient space.\n");
    return NULL;
}

void myFree(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    node* n = (node*)ptr - 1;
    n->next_1 = heap;
    heap = n;
}

void printHeap() {
    node* current = heap;

    while (current != NULL) {
        printf("node: %p, Size: %lu\n", current, current->size);
        current = current->next_1;
    }
}

//function to display reference count and freed size
void print_node(int i)
{
    printf("value=%d\t reference_count=%d freed_size=%lu\n", array[i]->data, array[i]->referenceCount, sizeof(node));
}


//set edges between nodes
void edgeSet(int so,int dest1,int dest2,int dest3)
{
	if(dest1!=-1)
	{
		array[so]->next_1=array[dest1];
		array[dest1]->referenceCount+=1;
	}
	if(dest2!=-1)
	{
		array[so]->next_2=array[dest2];
		array[dest2]->referenceCount+=1;
	}
	if(dest3!=-1)
	{
		array[so]->next_3=array[dest3];
		array[dest3]->referenceCount+=1;
	}
	
}
//prints all the nodes (works as a tree in a way)
void print_allNodes(node* root)
{
	if(root!=NULL)
	{
		printf("value=%d:referenceCount=%d\n",root->data,root->referenceCount);
	}
	if(root==NULL)
	{
		return;
	}
	print_allNodes(root->next_1);
	print_allNodes(root->next_2);
	print_allNodes(root->next_3);
}
// it lists all the nodes that are connected for a particular vertex
void adjacency_list()
{
	int i=0;
	for(i=0;i<8;i++)
	{
		if(array[i]!=NULL)
		{
			printf("Value=%d: ",array[i]->data);
			if(array[i]->next_1!=NULL)
			{
				printf("%d ->",array[i]->next_1->data);
			}
			if(array[i]->next_2!=NULL)
			{
				printf("%d ->",array[i]->next_2->data);
			}
			if(array[i]->next_3!=NULL)
			{
				printf("%d ->",array[i]->next_3->data);
			}
			printf("NULL\n");
		}
	}
}
// it checks whether the node is present in the root pointing list or not
int root_is_present(node* root_1,node* temp)
{
	if(root_1==NULL)
	{
		return 0;
	}
	if(root_1->data==temp->data)
	{
		return 1;
	}
	
	if(root_is_present(root_1->next_1,temp))
	{
		return 1;
	}
	
	if(root_is_present(root_1->next_2,temp))
	{
		return 1;
	}
	if(root_is_present(root_1->next_3,temp))
	{
		return 1;
	}
 return 0;
}

// if node is absent in root and then all the linkages to that particular node is , i.e.; reference counting should be decreased by 1 
// as the node is now garbage
void reference_counting(node* root)
{
	int i=0;
	while(i<8)
	{
		if(root_is_present(root,array[i])==0 )
		{		
			if(array[i]->next_1!=NULL)
			{
				array[i]->next_1->referenceCount-=1;
			}
			if(array[i]->next_2!=NULL)
			{
				array[i]->next_2->referenceCount-=1;
			}
			if(array[i]->next_3!=NULL)
			{
				array[i]->next_3->referenceCount-=1;
			}
			printf("Garbage:");
			print_node(i);
			free(array[i]);
			array[i]=NULL;
		}
		 i++;		
	}
	 
}
// represents a finite graph
// 1 if present 
// 0 if absent
void adjacency_Matrix()
{
	int adm[8][8];
	int i,j,k;
	
	for(i=0;i<8;i++)		//initialising all indices values to 0
	{
		for(j=0;j<8;j++)
		{
			adm[i][j]=0;
		}	
	}
	
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			
		if(array[j]!=NULL&&array[i]!=NULL)
		{
			
			if(array[i]->next_1!=NULL)
			{
				if(array[i]->next_1->data==array[j]->data&&i!=j)
				{
					adm[i][j]=1;
				}
			}
			if(array[i]->next_2!=NULL)
			{
				if(array[i]->next_2->data==array[j]->data&&i!=j)
				{
					adm[i][j]=1;
				}
			}
			if(array[i]->next_3!=NULL)
			{
				if(array[i]->next_3->data==array[j]->data&&i!=j)
				{
					adm[i][j]=1;
				}
			}
		}
		
		}
	}
	
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			printf("%d ",adm[i][j]);		//printing the adjacency matrix
		}
		printf("\n");
	}
}
// marks true if node is active, otherwise false
void mark_the_Nodes(node*root,int i,int j)
{
    node *current, *pre;

    current = root;
        
    while (current != NULL) 
    {
  
        if (current->next_1== NULL) 
        {
            current->mark=true;
            current = current->next_2;
        }   
        else 
        {
            pre = current->next_1;
            while ((pre->next_2 != NULL) && (pre->next_2 != current))
            {
            	pre = pre->next_2;
			}
                
            if (pre->next_2 == NULL) 
            {
                pre->next_2 = current;
                current = current->next_1;
            }
            else 
            {
                pre->next_2 = NULL;
                current->mark=true;
                current = current->next_2;
            } 
        }
    }   
    
    current = root;
        
    while (current != NULL) 
    {
  
        if (current->next_1== NULL) 
        {
            current->mark=true;
            current = current->next_3;
        }   
        else 
        {
            pre = current->next_1;
            while ((pre->next_3 != NULL) && (pre->next_3 != current))
            {
            	pre = pre->next_3;
			}
                
            if (pre->next_3 == NULL) 
            {
                pre->next_3 = current;
                current = current->next_1;
            }
            else 
            {
                pre->next_3 = NULL;
                current->mark=true;
                current = current->next_3;
            } 
        }
    }  
    
}
// mark method
void mark_method(node* root)
{
	
	if(root!=NULL)
	{
		root->mark=true;
	}
	if(root==NULL)
	{
		return;
	}
	mark_method(root->next_1);
	mark_method(root->next_2);
	mark_method(root->next_3);
}
// frees the space if mark bit is false i.e. zero
void sweep_method()
{
	int i;
	for(i=0;i<8;i++)
	{
		if(array[i]->mark==false)
		{
			if(array[i]->next_1!=NULL)
			{
				array[i]->next_1->referenceCount-=1;
			}
			if(array[i]->next_2!=NULL)
			{
				array[i]->next_2->referenceCount-=1;
			}
			if(array[i]->next_3!=NULL)
			{
				array[i]->next_3->referenceCount-=1;
			}
			printf("Garbage:");
			print_node(i);
			free(array[i]);
			array[i]=NULL;
		}
	}
}

int main() {
    initializeHeap();

    // Allocate memory nodes
    void* ptr1 = myMalloc(100);
    void* ptr2 = myMalloc(200);
    void* ptr3 = myMalloc(150);

    // Display the current state of the heap
    printf("Heap after allocations:\n");
    printHeap();

    // Free memory nodes
    myFree(ptr2);

    // Display the current state of the heap after deallocation
    printf("\nHeap after deallocation:\n");
    printHeap();

    // Allocate more memory
    void* ptr4 = myMalloc(50);

    // Display the final state of the heap
    printf("\nHeap after additional allocation:\n");
    printHeap();

    // Free all memory
    myFree(ptr1);
    myFree(ptr3);
    myFree(ptr4);

    // Display the empty heap
    printf("\nHeap after freeing all memory:\n");
    printHeap();

    // Additional part of the main function for graph operations and garbage collection

    int val[] = {1,2, 3, 5, 7, 8, 9, 10};
    int i;
    for (i = 0; i < 8; i++) {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->data = val[i];
        new_node->next_1 = NULL;
        new_node->next_2 = NULL;
        new_node->next_3 = NULL;
        new_node->referenceCount = 0;
        new_node->mark = false;
        array[i] = new_node;
    }

    node* root_1 = array[3];
    array[3]->referenceCount += 1;
    node* root_2 = array[0];
    array[0]->referenceCount += 1;

    edgeSet(0, 1, 6, 7);
    edgeSet(2, 5, 7, -1);
    edgeSet(3, 0, -1, -1);
    edgeSet(4, 0, 5, -1);
    edgeSet(5, 6, -1, -1);

    printf("\nAll nodes through Root-1:\n");
    print_allNodes(root_1);

    printf("\nAll nodes through Root-2:\n");
    print_allNodes(root_2);

    // Displaying Adjacency list of the nodes with corresponding value or vertex
    printf("\n\nAdjacency list :\n");
    adjacency_list();

    // Displaying Adjacency Matrix of the nodes
    printf("\n\nAdjacency matrix:\n");
    adjacency_Matrix();

    printf("\nCalling the mark and sweep garbage collector\n");
    mark_method(root_1);
    sweep_method();
    printf("\n\nAdjacency list after removal of garbage:\n");
    adjacency_list();

    printf("\n\nAdjacency matrix after removal of garbage:\n");
    adjacency_Matrix();

    return 0;
}
