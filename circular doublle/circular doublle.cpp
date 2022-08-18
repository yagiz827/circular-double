using namespace std;
#include <iostream>



// Structure of a Node
class circullar {
    public:
        struct Node
        {   
            string name;
            int quantity;
            int price;
            struct Node* next;
            struct Node* prev;
        };
   
        Node* head;

    

    // Function to insert at the end
        void insertEnd(Node** head, int value, string name, int quantity)
        {
            // If the list is empty, create a single node
            // circular and doubly list
            if (*head == NULL)
            {
                struct Node* new_node = new Node;
                new_node->price = value;
                new_node->name = name;
                new_node->quantity =quantity ;
                new_node->next = new_node->prev = new_node;
                *head = new_node;
                cout << "Item: " << name << endl << "Quantity: " << quantity << endl << "Unit Price: " << value << endl;
                return;
            }

            // If list is not empty
            struct Node* temp = *head;
            while (temp->name != name) {
                if (temp->next == *head) {
                    cout << "asda"; break;
                   
                }
                else{
                    temp = temp->next;
                }
             }
                
           


           
           
            

            /*// insert new_node between temp and next.
            temp->next = new_node;
            new_node->prev = temp;
            new_node->next = next;
            next->prev = new_node;
             Find last node */
            Node* last = (*head)->prev;

            // Create Node dynamically
            struct Node* new_node = new Node;
            new_node->price = value;
            new_node->name = name;
            new_node->quantity = quantity;

            // Start is going to be next of new_node
            new_node->next = *head;

            // Make new node previous of start
            (*head)->prev = new_node;

            // Make last previous of new node
            new_node->prev = last;

            // Make new node next of old last
            last->next = new_node;


           
        }

        // Function to insert Node at the beginning
        // of the List,
        void insertBegin(struct Node** start, int value)
        {
            // Pointer points to last Node
            struct Node* last = (*start)->prev;

            struct Node* new_node = new Node;
            new_node->price = value;   // Inserting the price

            // setting up previous and next of new node
            new_node->next = *start;
            new_node->prev = last;

            // Update next and previous pointers of start
            // and last.
            last->next = (*start)->prev = new_node;

            // Update start pointer
            *start = new_node;
        }

        // Function to insert node with value as value1.
        // The new node is inserted after the node with
        // with value2
        void insertAfter(struct Node** start, int value1, int value2)
        {
            
        }


        void display(struct Node* start)
        {
            struct Node* temp = start;

            printf("\nTraversal in forward direction \n");
            while (temp->next != start)
            {
                printf("%d ", temp->price);
                temp = temp->next;
            }
            printf("%d ", temp->price);

            printf("\nTraversal in reverse direction \n");
            Node* last = start->prev;
            temp = last;
            while (temp->prev != last)
            {
                printf("%d ", temp->price);
                temp = temp->prev;
            }
            printf("%d ", temp->price);
        }
};

/* Driver program to test above functions*/
int main()
{   
    int qua, pri;
    string  a,nam;
    /* Start with the empty list */
    circullar start;
    start.head = NULL;
    cin >> a;
    while (a != "exit") {
        
        if (a == "add") {
            cin >> nam;
            cin >> qua>>pri ;
            start.insertEnd(&start.head, pri, nam, qua);
        }
        // Insert 5. So linked list becomes 5->NULL
        

        // Insert 4 at the beginning. So linked
        // list becomes 4->5
        /*
        insertBegin(start.head, 4);

        // Insert 7 at the end. So linked list
        // becomes 4->5->7
        insertEnd(start.head, 7);

        // Insert 8 at the end. So linked list
        // becomes 4->5->7->8
        insertEnd(start.head, 8);

        // Insert 6, after 5. So linked list
        // becomes 4->5->6->7->8
        insertAfter(start.head, 6, 5);
        */
        if (a == "print") {
            printf("Created circular doubly linked list is: ");
            start.display(start.head);
        }
       
        cin >> a;
    }
    

    

    return 0;
}