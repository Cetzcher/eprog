#include <iostream>
#include <string>
using namespace std;

class T1
{
    string t1;

  public:
    T1(string val)
    {
        cout << "Ich bin Konstruktor von " << val << endl;
        t1 = val;
    }
    T1()
    {
        cout << "Ich bin Konstruktor von default" << endl;
        t1 = "default";
    }
    ~T1() { cout << "Ich bin Destruktor von " << t1 << endl; }
};
int main()
{
    T1 bert("bert");
    T1 bob;
    T1 def("bob");
    return 0;
}