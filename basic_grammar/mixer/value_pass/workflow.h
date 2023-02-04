#include <iostream>
#include <map>

using namespace std;

namespace workflow{
struct Person
{
    string name;
    bool gender=false;
    int height;
};

class Workflow {
public:
    shared_ptr<Person> person;
    string group_workflow;
    bool user_profile = false;
    bool relationship_label = false;
    bool friend_relationship_label = false;
    bool enable_real_time = false;
};
}