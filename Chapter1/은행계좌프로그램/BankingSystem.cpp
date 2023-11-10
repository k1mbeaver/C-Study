#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum CurrentStage
{
    SHOWMENU = 0,
    MAKEACCOUNT,
    DEPOSIT,
    WITHDRAW,
    SHOW,
    EXIT
};

struct Account
{
    int accID;
    int CurrentMoney;
    string cusName;
};

void ShowMenu();
Account MakeAccount();
void DepositMoney(vector<Account> &myAccount);
void WithDrawMoney(vector<Account> &myAccount);
void ShowAllAccInfo(vector<Account> &myAccount);

int main()
{
    vector<Account> myAcc;
    int accNum = 0;
    int choice = 0;

    while(1)
    {
        ShowMenu();
        cout << "선 택: ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case MAKEACCOUNT:
                myAcc.push_back(MakeAccount());
                break;
            
            case DEPOSIT:
                DepositMoney(myAcc);
                break;
            
            case WITHDRAW:
                WithDrawMoney(myAcc);
                break;
            
            case SHOW:
                ShowAllAccInfo(myAcc);
                break;

            case EXIT:
                return 0;

            default:
                cout << "Illegal selection" << endl;
        }
    }

    return 0;
}

void ShowMenu()
{
    cout << "----------Menu----------" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입 금" << endl;
    cout << "3. 출 금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

Account MakeAccount()
{
    int id;
    string name;
    int money;
    Account newAccount;

    cout << "----------계좌개설----------" << endl;
    cout << "계좌 ID: ";
    cin >> id;
    cout << "이 름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> money;
    cout << endl;

    newAccount.accID = id;
    newAccount.CurrentMoney = money;
    newAccount.cusName = name;

    return newAccount;
}

void DepositMoney(vector<Account> &myAccount)
{
    int money;
    int id;
    
    cout << "----------입 금----------" << endl;
    cout << "계좌 ID: ";
    cin >> id;
    cout << "입금액: ";
    cin >> money;

    if(myAccount.empty())
    {
        cout << "정보가 없습니다." << endl;
        return;
    }

    for(int i = 0; i < myAccount.size(); i++)
    {
        if(myAccount[i].accID == id)
        {
            myAccount[i].CurrentMoney += money;
            cout << "입금완료" << endl;
            return;
        }
    }

    cout << "유효하지 않은 ID 입니다." << endl;
}

void WithDrawMoney(vector<Account> &myAccount)
{
    int money;
    int id;
    cout << "----------출 금----------" << endl;
    cout << "계좌 ID: ";
    cin >> id;
    cout << "출금액: ";
    cin >> money;

    for(int i = 0; i < myAccount.size(); i++)
    {
        if(myAccount[i].accID == id)
        {
            if(myAccount[i].CurrentMoney < money)
            {
                cout << "잔액부족 입니다." << endl;
                return;
            }

            myAccount[i].CurrentMoney -= money;
            cout << "출금완료" << endl << endl;
            return;
        }
    }

    cout << "유효하지 않은 ID 입니다." << endl;
}

void ShowAllAccInfo(vector<Account> &myAccount)
{
    for(int i = 0; i < myAccount.size(); i++)
    {
        cout << "계좌 ID: " << myAccount[i].accID << endl;
        cout << "이 름: " << myAccount[i].cusName << endl;
        cout << "잔 액: " << myAccount[i].CurrentMoney << endl;
    }
}