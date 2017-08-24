#include "queue.h"

queue::queue()
{
    head = NULL;
    tail = NULL;
}
queue::~queue()
{
    remove_all(head);
    tail = NULL;
}
void queue::enqueue(char *to_add)
{
    if(!head)
    {
        head = new q_node;
        tail = head;
        head->data = new char[strlen(to_add) + 1];
        strcpy(head->data, to_add);
        head->next = NULL;
        return;
    }
    tail->next = new q_node;
    tail = tail->next;
    tail->data = new char[strlen(to_add) +1];
    strcpy(tail->data, to_add);
    tail->next = NULL;
    return;
}
char * queue::peek()
{
    if(!head)
    {
        return NULL;
    }
    return head->data;
}
char * queue::dequeue()
{
    if(!head)
    {
        return NULL;
    }
    char * temp = new char[strlen(head->data) + 1];
    strcpy(temp, head->data);
    q_node *to_delete = head;
    head = head->next;
    delete [] to_delete->data;
    delete to_delete;
    if(!head)
        tail = head;
    return &(*temp);
}
void queue::remove_all(q_node*& head)
{
    if(!head)
        return;
    remove_all(head->next);
    delete [] head->data;
    delete head;
    head = NULL;
    return;
}


course::course()
{
    name = NULL; //set name pointer to NULL
    waiting_list = new queue; //waiting list creates new queue
}
course::~course()
{
    if(name)
    {
        delete [] name;//delete what name is pointing to
        name = NULL; // set name pointer to null
    }
    if(waiting_list)
    {
        delete waiting_list; //delete what waiting_list was pointing to
        waiting_list = NULL; //set waiting_list pointer to NULL;
    }
}
void course::set_course_name()
{
    char temp[200]; //user input
    cout << "Enter course name. " << endl;
    cin.get(temp, 200, '\n'); //allow for spaces in user input
    cin.ignore(200, '\n'); //clear input buffer
    name = new char[strlen(temp) + 1]; //allocate memory for course name
    strcpy(name, temp); //copy temp into name
    return;
}
void course::add_student()
{
    char temp[200]; //user input
    cout << "Enter student name. " << endl;
    cin.get(temp, 200, '\n');
    cin.ignore(200, '\n');
    waiting_list->enqueue(temp);
    return;
}
void course::enroll()
{
    char * temp = waiting_list->dequeue();
    if(temp) //check to see if temp = NULL
    {
        delete [] temp;
        temp = NULL;
        cout << "Enrolled." << endl;
        return;
    }
    cout << "No waiting list. " << endl;
}
    

