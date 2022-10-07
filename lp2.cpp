#include <iostream>
using std::cin;using std::cout;
//функция для решения задачи 1 
void task1()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<j;
        }
        cout<<'\n';
    }
} 
//функция для решения задачи 2 
void task2() 
{
    float n, c=1;
    cin>>n;
    for(float k=0;k<=n;k++){
        cout<<k<<" "<<c<<'\n';
        c*=(n-k);
        c/=(k+1);
    }
}
void task3()
{
    int f = 501, s = 0, k=0;
    while (f!=0){
        cin>>f;
        s+=f;
        k++;
    }
    k--;
    cout<<double(s)/k;
}
    int main() 
    { 
     int choice =0; // в этой переменной будет храниться выбор пользователя 
     while (true) // непрерывный цикл 
     { 
         std::cout << "Что вы хотите выполнить? \n" 
         << "1. задание 1\n" 
         << "2. задание 2\n" 
         << "3. задание 3\n"
         << "4. задание 4\n"; 
         std::cin >> choice; 
         switch (choice) 
         { 
             case 1: 
             { 
             /*вызов функции для решения задания 1*/; 
                task1(); 
                break; // если его не ставить, то после вызова task1(), начнет выполнятся task2() 
             } 
             case 2: 
             { 
             /*вызов функции для решения задания 1*/; 
                task2(); 
                break; 
             }
             case 3:
             {
                task3();
                break;
             }
             default: 
             { 
                return 0; 
             } 
         } 
     } 
}