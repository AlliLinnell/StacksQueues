#include "queue.h"

struct s_node
{
    course * data;
    s_node *next;
};

class stack
{
    public:
        stack();
        ~stack();
        void pop(
