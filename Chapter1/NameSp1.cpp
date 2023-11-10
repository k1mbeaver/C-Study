#include <iostream>

using namespace std;

namespace BestComImp1
{
    void SimpleFunc(void)
    {
        cout << "BestCom이 정의한 함수" << endl;
    }
}

namespace ProgComImp1
{
    void SimpleFunc(void)
    {
        cout << "ProgCom이 정의한 함수" << endl;
    }
}

int main()
{
    BestComImp1::SimpleFunc();
    ProgComImp1::SimpleFunc();

    return 0;
}