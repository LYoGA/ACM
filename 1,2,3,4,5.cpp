#include<iostream>
using namespace std;

class Employee{

	public:
		Employee(){
			age = 0;	
			yearOfService = 0;	
			salary = 0;
			money = 0;
		}
		void set_Employee(int a, int b, int c){
			age = a;	
			yearOfService = b;	
			salary = c;
		}
		void make_money(){
			money = yearOfService * salary;	
			cout << "money = " << money << endl;	
		}//赚钱
		void play_Employee(){	
			cout << "age = " << age << endl;	
			cout << "yearOfService = " << yearOfService << endl;	
			cout << "salary = " << salary << endl;		
		}
	private:
		int age;
		int yearOfService;
		int salary;
		int money;
};

int main(){
	int a, b, c, d, e, f;
	cout << "Please enter N0.1:"<< endl;	
	cin >> a >> b >> c;
	cout << "Please enter N0.2:"<< endl;		
	cin >> d >> e >> f;	
	Employee E1, E2;	
	E1.set_Employee(a, b, c);	
	E2.set_Employee(d, e, f);	
	E1.play_Employee();
	E2.play_Employee();
	E1.make_money();
	E2.make_money();
	return 0;
}
