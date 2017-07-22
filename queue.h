#include <iostream>
#include <cstdlib>

using namespace std;

struct q_node //student
{
    char *data;
    q_node *next;
}

class queue
{
    public:
            queue();
            //~queue();
            //void enqueue(char *to_add);
            //char* dequeue();
            //char *peek();
            //void remove_all();

    private:
            q_node *head; //DQ at head (exit queue at head)
            q_node *tail; //NQ at tail (enter the queue at tail)

