#include <iostream>
using std::cout;
using std::endl;

class Test
{
  private:
    int N;

  public:
    void setN(int N_in) { N = N_in; };
    int getN() { return N; };
    int *getptrN() { return &N; };
};

int main()
{
    Test A;
    A.setN(5);
    int *ptr = A.getptrN();
    cout << A.getN() << endl;
    *ptr = 10;
    cout << ptr << endl;
    cout << A.getN() << endl;
    return 0;
}