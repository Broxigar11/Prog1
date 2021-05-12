#include "GUI/std_lib_facilities.h"

struct Person{
private:
	string first_name;
	string second_name;
	int age;

public:
	Person(){}
	Person(string fn, string sn, int a) : first_name(fn),second_name(sn), age(a){
		string invalid_char=";:\"'[]*^%$@!.";
		for (int i=0; i<first_name.length(); i++){
			for(int j=0; j<invalid_char.length(); j++){
				if(first_name[i]==invalid_char[j]) error("Invalid character found in first name");
			}
		}
			
		for (int i=0; i<second_name.length(); i++){
			for(int j=0; j<invalid_char.length(); j++){
				if(second_name[i]==invalid_char[j]) error("Invalid character found in first name");
			}
		}

		if (age < 0 || age > 150)
			error("Invalid age!");

		for (int i=0; i<second_name.length(); i++)
		{
			if (!isalpha(second_name[i]))
				error("Name forgotten");
		}
	}

	string get_firstname() const{
		return first_name;
	}

	string get_secondname() const{
		return second_name;
	}

	int get_age() const{
		return age;
	}

	void set_firstname(string n) 
	{
		string invalid_char=";:\"'[]*^%$@!.";
		for (int i=0; i<n.length(); i++){
			for(int j=0; j<invalid_char.length(); j++){
				if(n[i]==invalid_char[j]) error("Invalid character found in first name");
			}
		}
		first_name = n;
	}
	void set_secondname(string n)
	{
		string invalid_char=";:\"'[]*^%$@!.";
		for (int i=0; i<n.length(); i++){
			for(int j=0; j<invalid_char.length(); j++){
				if(n[i]==invalid_char[j]) error("Invalid character found in first name");
			}
		}

		for (int i = 0; i < n.length(); i++)
		{
			if (!isalpha(n[i]))
				error("Name forgotten");
		}

		second_name = n;
	}
	void set_age(int a) { 
		if (a < 0 || a > 150)
			error("Invalid age!"); 
		age = a; 
	}

	friend ostream&  operator<<(ostream &output, const Person &P){
		output << "First name: " << P.get_firstname();
		output << "\nSecond name: " << P.get_secondname();
		output << "\nAge: " << P.get_age();

		return output;
	}

	friend istream& operator>>(istream &input, Person &P){
		string input_fn, input_sn;
		int input_age;
		cout << "Type first name, second name and age: ";
		input >> input_fn >> input_sn >> input_age;

		P.set_firstname(input_fn);
		P.set_secondname(input_sn);
		P.set_age(input_age);
	
		return input;
	}
};

int main(){
	Person Goofy{"Goofy", "Goof",63};
	cout << Goofy.get_firstname() << " " << Goofy.get_secondname() << " " << Goofy.get_age() << endl;

	Person p2;
	cout << "Enter the name and the age of the person" << endl;
	cin >> p2;
	cout << p2 << endl;
	vector <Person> v;
	for (Person p; cin >> p;)
	{
		if (p.get_firstname() == "end") break;
		else v.push_back(p);
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}


	return 0;
}