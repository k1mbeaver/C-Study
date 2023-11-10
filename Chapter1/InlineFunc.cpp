#include <iostream>

// 인라인 함수는 매크로 함수 처럼 코드에 선언을 해놓는 것!
// 매크로 인라인화는 전처리기, 키워드 inline을 활용한 인라인화는 컴파일러에 의해 처리
// 속도가 빠르다?

using namespace std;

inline int SQUARE(int n)
{
    return n * n;
}

int main()
{
    cout << SQUARE(5) << endl;
    cout << SQUARE(100) << endl;

    return 0;
}