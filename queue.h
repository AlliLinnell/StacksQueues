#include <iostream>
#include <cstdlib>

using namespace std;

struct q_node //student
{
    char *data;
    q_node *next;
};

class queue
{
    public:
            queue();
            ~queue();
            void enqueue(char *to_add);
            char* dequeue();
            char *peek();

    private:
            q_node *head; //DQ at head (exit queue at head)
            q_node *tail; //NQ at tail (enter the queue at tail)
            
            void remove_all(q_node *&);

};
class course
{
    public: 
        course();
        ~course();
        void set_course_name();
        void add_student();
        void enroll();

    private: 
    char * name;
    queue * waiting_list;
};
