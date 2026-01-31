#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int generator() {
   srand(time(0));
   int num = rand() % 3 + 1;
   return num;
}
string computer() {
   int gen = generator();
   if (gen == 1) {
       return "rock";
   }
   else if (gen == 2) {
       return "scissor";
   }
   else
       return "paper";

}
string user() {
   string name;
   cout << "enter the name u want (rock,paper,scissor) :  ";
   cin >> name;
   for (char& c : name) {
       c = toupper(c);

   }


   while (name != "ROCK" && name != "SCISSOR" && name != "PAPER") {
       cout << "enter the sign u want : ";
       cin >> name;
       for (char& c : name) {
           c = toupper(c);
       }
   }
   return name;
}
void game() {
   string com_enter = computer();
   string user_enter = user();
   for (char& c : com_enter) {
       c = toupper(c);
   }


   if (user_enter == "ROCK" && com_enter == "SCISSOR" ||
       user_enter == "SCISSOR" && com_enter == "PAPER" || user_enter == "PAPER" && com_enter == "ROCK") {
       cout << user_enter << " | " << com_enter << endl;
       cout << "You Win " << endl;
   }
   else if (user_enter == "SCISSOR" && com_enter == "ROCK" ||
       user_enter == "PAPER" && com_enter == "SCISSOR" || user_enter == "ROCK" && com_enter == "PAPER") {
       cout << user_enter << " | " << com_enter << endl;
       cout << "You Loss " << endl;
   }
   else if (user_enter == "ROCK" && com_enter == "ROCK" ||
       user_enter == "SCISSOR" && com_enter == "SCISSOR" || user_enter == "PAPER" && com_enter == "PAPER") {
       cout << user_enter << " | " << com_enter << endl;
       cout << "The Game is Draw  " << endl;
   }
}

int main(){
   int n;
   cout << "enter the number how much times u want to play game : ";
   cin >> n;
   while (n < 1) {
       cout << "invalid input :" << endl;
       cout << "enter again ";
       cin >> n;

   }
   for (int i = 0; i < n; i++) {
       game();
   }
   return 0;
}

