#include <iostream>
using std::string;

class AbstractEmployee { //alttaki fonksiyondan override ediyoruz
	virtual void AskForPromotion() = 0;

};

class Employee:public AbstractEmployee {

private:
	string Name;
	string Company;
	int Age;

public:

	void setName(string name) { //setter
		Name = name;
	}
	string getName() { //getter
		return Name;
	}
	void setCompany(string company) { //setter
		Company = company;
	}
	string getCompany() { //getter
		return Company;
	}
	void setAge(int age) { //setter
		if(age>=18)
		Age = age;
	}
	int getAge() { //getter
		return Age;
	}


	void IntroduceYourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;
	}
	void AskForPromotion() {
		if (Age >= 30)
			std::cout << Name << "got promoted" << std::endl;
		else
			std::cout << Name << "no promotion" << std::endl;
	}

	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;

	}

};

 //devoloper child/ employee super class
//devoloper employeede olan her şeye sahip.
//sadece devolopera özgü olması gerekenleri ekleriz.
class Developer : public Employee { // public employee olmaz ise employeeinin metodlarını inherit edemeyiz
	public:
		string FavLanguage;

		Developer(string name, string company, int age, string favLanguage)
			: Employee(name, company, age) {
			FavLanguage = favLanguage;
		}

		void FixBug() {
			std::cout << getName() << " fixed bug using " << FavLanguage << std::endl;
		}
};

int main() {
	Employee employee1 = Employee("ipek", "aa", 20);
	employee1.IntroduceYourself();

	Employee employee2 = Employee("john", "bb", 30);
	employee2.IntroduceYourself();

	employee1.setAge(21);
	std::cout << employee1.getName() << " is " << employee1.getAge() << " years old" << std::endl;

	employee1.AskForPromotion();
	employee2.AskForPromotion();

	Developer d = Developer("ayse", "cc", 45, "C++");
	d.FixBug();

	return 0;
}