#include <iostream>
#include <vector>

using namespace std;

struct RUnit
{
    string name;
    float score;
};


void build_runits(vector<shared_ptr<RUnit> >& runits) {
    shared_ptr<RUnit> item_0 = std::make_shared<RUnit>();
    item_0->name = "item_0";
    item_0->score = 2.51;
    runits.push_back(item_0);

    shared_ptr<RUnit> item_1 = std::make_shared<RUnit>();
    item_1->name = "item_1";
    item_1->score = 2.53;
    runits.push_back(item_1);

    shared_ptr<RUnit> item_2 = std::make_shared<RUnit>();
    item_2->name = "item_2";
    item_2->score = 2.52;
    runits.push_back(item_2);

    shared_ptr<RUnit> item_3 = std::make_shared<RUnit>();
    item_3->name = "item_3";
    item_3->score = 2.61;
    runits.push_back(item_3);

    shared_ptr<RUnit> item_4 = std::make_shared<RUnit>();
    item_4->name = "item_4";
    item_4->score = 2.69;
    runits.push_back(item_4);

    shared_ptr<RUnit> item_5 = std::make_shared<RUnit>();
    item_5->name = "item_5";
    item_5->score = 2.66;
    runits.push_back(item_5);

    shared_ptr<RUnit> item_6 = std::make_shared<RUnit>();
    item_6->name = "item_6";
    item_6->score = 2.73;
    runits.push_back(item_6);

    shared_ptr<RUnit> item_7 = std::make_shared<RUnit>();
    item_7->name = "item_7";
    item_7->score = 2.79;
    runits.push_back(item_7);

    shared_ptr<RUnit> item_8 = std::make_shared<RUnit>();
    item_8->name = "item_8";
    item_8->score = 2.78;
    runits.push_back(item_8);

    shared_ptr<RUnit> item_9 = std::make_shared<RUnit>();
    item_9->name = "item_9";
    item_9->score = 2.781;
    runits.push_back(item_9);
}


bool compare(const shared_ptr<RUnit>& lhs, const shared_ptr<RUnit>& rhs) {
    return lhs->score > rhs->score;
}

int main() {
    vector<shared_ptr<RUnit > > data;
    build_runits(data);

    for (auto &item : data)
    {
        std::cout << "name: " << item->name << " ,score: " << item->score << endl;
    }

    std::cout << "=======" << std::endl;


    // std::stable_sort(data.begin(), data.begin()+3, compare);

    // std::stable_sort(data.begin()+3, data.begin()+6, compare);

    // std::stable_sort(data.begin()+6, data.end(), compare);

    std::cout << "length=" << data.end()-data.begin() << std::endl;

    for (size_t i = 0; i <= data.size()-7;)
    {
        std::stable_sort(data.begin()+i, data.begin()+i+7, compare);
        i+=7;
    }
    

    for (auto &item : data)
    {
        std::cout << "name: " << item->name << " ,score: " << item->score << endl;
    }

    return 0;
}