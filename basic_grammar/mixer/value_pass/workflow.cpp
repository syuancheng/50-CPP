#include <iostream>
#include <unordered_map>
#include "workflow.h"
#include "pointer/context.h"

using namespace std;

void change_workflow(workflow::Workflow& workflow, unordered_map<string, workflow::Workflow> workflow_map){
    auto workflow_tmp = workflow_map.find("first");

    workflow = workflow_tmp->second;
}


int main(){

    unordered_map<string, workflow::Workflow> results;
    //1. build workflow
    workflow::Person person;
    person.name = "krystal";
    person.gender = true;
    person.height = 123;

    workflow::Workflow wflow_tmp;
    wflow_tmp.group_workflow = "3_group";

    wflow_tmp.person = make_shared<workflow::Person>(person);

    results.insert(make_pair("first", wflow_tmp));

    //get a workflow
    workflow::Workflow workflow_res;
    change_workflow(workflow_res, results);
    cout<< "Get from results: Before: " << workflow_res.group_workflow << endl;

    //do some change in workflow that get from results
    workflow_res.group_workflow = "non_group";

    cout<< "Get from results: After: " << workflow_res.group_workflow << endl;

    auto iter = results.find("first");
    cout<< "Results: " << iter->second.group_workflow << endl;


    cout<<"=========================="<<endl;

    Context context;
    context.uid = 1357747398;

    context.add_sec_ctx("1");
    context.sec_ctx("1")->uid = 1111111;
    context.sec_ctx("1")->set_bnd_ctx(context);

    context.add_sec_ctx("2");
    context.sec_ctx("2")->uid = 2222222;
    context.sec_ctx("2")->set_bnd_ctx(context);

    cout<< "bnd ctx: "<< context.uid<<endl;
    cout<<"bnd get sec: \n";

    cout<<"sec1: "<< context.sec_ctx("1")->uid<<endl;
    cout<<"sec2: "<< context.sec_ctx("2")->uid<<endl;

    cout<<"sec get bnd: \n";
    auto sec1 = context.sec_ctx("1");
    cout<<"1-bnd: "<<sec1->get_bnd_ctx().uid<< endl;

    auto sec2 = context.sec_ctx("2");
    cout<<"2-bnd: "<<sec1->get_bnd_ctx().uid<< endl;

    return 0;
}