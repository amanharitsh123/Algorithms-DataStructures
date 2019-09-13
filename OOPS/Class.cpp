#include <iostream>
#include <string>
using namespace std;

class person {
    public:
    string name;
    int age;

    void display() {
        cout<<"Member Funtion"<<endl;
        cout<<"Name is "<<name<<endl;
        cout<<"Age is "<<age<<endl;
    }

};

int main() {
    person* p1 = new person();
    p1->name="Aman";
    p1->age=20;
    p1->display();
}