#include <iostream>

using namespace std;

struct Context
{
    string name;
    int age;
};

void handle(Context* ctx) {
    ctx->name = "handle";
    cout << "function: name: " << ctx->name << ",age:" << ctx->age << endl;
}

int main() {
    Context ctx;
    ctx.name = "krystal";
    ctx.age = 28;

    cout << "before:name: " << ctx.name << ",age:" << ctx.age << endl;
    handle(&ctx);
    cout << "after: name: " << ctx.name << ",age:" << ctx.age << endl;
    return 0;
}