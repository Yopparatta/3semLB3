#include <iostream>

using namespace std;

class Account {

private:
    double money;
public:
    Account() {
        money = 0;
    }
    void show() {
        cout << "Money: " << money << endl;
    }

    void moneyput(double money) {
        this->money += money;
    }
    double moneyget(){
        return money;
    }


    friend void deposit(double money, Account person);
    friend void withdraw(double money, Account person);
};

void deposit(double money, Account person) {
    person.money += money;
}
void withdraw(double money, Account person) {
    person.money -= money;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Account user;
    string oper;
    double money;
    while (true) {
        cout << "Введите тип операции и сумму (дробная часть отделяется запятой)\n";
        cin >> oper >> money;
        if (oper == "withdraw") {
          //  withdraw(money, user);
            //user.show();
            user.moneyput(-money);
            cout << "Money: " << user.moneyget() << endl;
        }
        else if (oper == "deposit") {
           // deposit(money, user);
            //user.show();
            user.moneyput(money);
            cout << "Money: " << user.moneyget() << endl;
        }
        else if (oper == "exit") {
            exit(0);
        }
        else
            cout << "Такой операции не существует\n";


        }

}