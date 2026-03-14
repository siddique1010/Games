#include <iostream>
#include <cstring>
using namespace std;

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"
class Muser
{
private:
    string name;
    string password;
    string role;

public:
    Muser() : name("unknown"), password("unknown"), role("Nothing") {}
    Muser(string name, string password, string role)
    {
        this->name = name;
        this->password = password;
        this->role = role;
    }
    bool SignIn(string n, string p)
    {
        if (name == n && password == p)
        {
            return true;
        }
        else
            return false;
    }
    void Display()
    {
        cout << "Name is : " << GREEN << name << RESET << " | " << "Role is : " << GREEN << role << RESET << endl
             << endl;
    }
    Muser(const Muser &other)
    {
        this->name = *new string(other.name);
        this->password = *new string(other.password);
        this->role = other.role;
        cout << "\nRole is : " << this->role << endl
             << endl;
    }

    ~Muser()
    {
        cout<<"\n\nDestructor Called for User : "<<name<<endl;
    }
};
int main()
{
    cout << GREEN << "\n\n\t\t\t\t\t>>>>>                  >>>>>\t\t\t\t\n"
         << RESET;
    cout << "\t\t\t\t\t\tSignIn/SignUp\t\t\t\t\t\t\n";
    cout << GREEN << "\t\t\t\t\t<<<<<                  <<<<<\t\t\t\t" << RESET;
    cout << endl
         << endl;

    string n, p, r;

    cout << "\n----First of all SignUp---- \n"
         << endl;
    cout << "Enter Your Name : ";
    cin >> n;
    cout << "Enter Your Password : ";
    cin >> p;
    cout << "Enter Your Role(Admin/User) : ";
    cin >> r;
    Muser *o1 = new Muser(n, p, r);
    cout << "\nParameterized constructor Called!\n";

    cout << "\n<...User Created Successfully...>\n"
         << endl;

    cout << "-----SignIn-----\n\n";

    char again;
    while (true)
    {
        cout << "Enter Your Name : ";

        cin >> n;
        cout << "Enter Your Password : ";
        cin >> p;
        if (o1->SignIn(n, p))
        {
            cout << "\nLogin Successfull \n\n"
                 << endl;
            o1->Display();
            break;
        }
        else
        {
            cout << RED << "Invalid Credential " << RESET << endl;
            Muser *o2 = new Muser(*o1);
            cout << "Do you Want to SignIn again ? ";
            cin >> again;

            if (again != 'y' || again != 'Y')
            {
               
            }

            delete o2;
        }
    }

    // cout<<"Creating a copy of user1....\n\n";

    //cout<<"Copy Constructor Called \n\n";
    delete o1;
    // cout<<RED<<"Program End \n"<<RESET;
    
    return 0;
}