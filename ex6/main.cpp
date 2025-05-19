#include <QCoreApplication>
#include <iostream>

struct Node {
    int data;
    Node *next;
};

void add_node(Node* head_node, int new_data) {

    Node* temp = head_node;

    //Traverse the list till the last one
    while(temp->next != NULL) {
        temp = temp->next;
    }
    //Allocate memory for the new List
    temp->next = (Node*)malloc(sizeof(Node));
    temp->next->data = new_data;
    temp->next->next = NULL;
}


void print_list(Node* head_node) {
    Node* temp = head_node;
    while(temp != NULL) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}

void push_node(Node **head_node, int val) {
    //Node* old_head = *head_node;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->next = *head_node;
    *head_node = temp;
}

void insert_node(Node **current_node, int val) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = (*current_node)->next;
    (*current_node)->next = new_node;
}

void remove_first(Node **head_node) {
    Node* temp_head = (*head_node)->next;
    free(*head_node);
    (*head_node) = temp_head;
}

void remove_last(Node **head_node) {
    Node *last_node = *head_node;
    Node *next_to_last = *head_node;
    while(last_node->next != NULL) {
        next_to_last = last_node;
        last_node = last_node->next;
    }
    next_to_last->next = NULL;
    free(last_node);
}

void remove_no_scan(Node *remove_node) {
    //We have the pointer for the node we want to
    // remove, but no Head pointer. So we do not have the previous node
    // and we can not update its node->next pointer.
    // The trick is to copy the following node to the current one, then
    // remove the following node instead of current one.

    //backup following node
    Node *p_following = remove_node->next;
    //copy following node to the current one
    remove_node->data = remove_node->next->data;
    remove_node->next = remove_node->next->next;
    //now remove following node
    delete p_following;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Set up code that uses the Qt event loop here.
    // Call a.quit() or a.exit() to quit the application.
    // A not very useful example would be including
    // #include <QTimer>
    // near the top of the file and calling
    // QTimer::singleShot(5000, &a, &QCoreApplication::quit);
    // which quits the application after 5 seconds.

    // If you do not need a running Qt event loop, remove the call
    // to a.exec() or use the Non-Qt Plain C++ Application template.

    std::cout << "**** Practice Linked List ****" << std::endl;
    Node *head = NULL;
    head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    //std::cout << head->data << std::endl;

    head->next = (Node*)malloc(sizeof(Node));
    head->next->data = 2;
    //std::cout << head->data << std::endl;

    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    add_node(head, 4);
    add_node(head, 5);
    add_node(head, 6);
    push_node(&head, 11);
    insert_node(&(head->next->next->next), 22);
    std::cout << "Step 1: Full List" << std::endl;
    print_list(head);

    remove_first(&head);
    std::cout << std::endl << "Step 2: Remove first item" << std::endl;
    print_list(head);

    remove_first(&head);
    std::cout << std::endl << "Step 3: Remove first item" << std::endl;
    print_list(head);

    remove_last(&head);
    std::cout << std::endl << "Step 4: remove last item" << std::endl;
    print_list(head);

    remove_last(&head);
    std::cout << std::endl << "Step 5: remove last item" << std::endl;
    print_list(head);

    remove_no_scan(head->next);
    std::cout << std::endl << "Step 6: remove by not scanning" << std::endl;
    print_list(head);


    a.exit();
    //return a.exec();
}
