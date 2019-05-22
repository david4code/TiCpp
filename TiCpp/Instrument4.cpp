//: C15:ObjectSlicing.cpp
#include <iostream>
#include <string>
using namespace std;
class Pet {
	string pname;
public:
	Pet(const string& name) : pname(name) {}
	Pet(const Pet& p) :pname(p.pname) {}
	virtual string name() const { return pname; }
	virtual string description() const {
		return "This is " + pname;
	}
	~Pet() {
		cout << "Destruct Pet" << endl;
	}
};
class Dog : public Pet {
	string favoriteActivity;
public:
	Dog(const string& name, const string& activity)
		: Pet(name), favoriteActivity(activity) {}
	Dog(const Dog& d) :favoriteActivity(d.favoriteActivity), Pet(d) {
	}
	string description() const {
		return Pet::name() + " likes to " +
			favoriteActivity;
	}
	~Dog() {
		cout << "Destruct Dog" << endl;
	}
};
void describe(Pet p) { // Slices the object
	cout << p.description() << endl;
}
int main() {
	Pet p("Alfred");
	Dog d("Fluffy", "sleep");
	Dog d1(d);
	describe(p);
	describe(d);
} ///:~