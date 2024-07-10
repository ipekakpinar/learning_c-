#include <iostream>
#include <thread>
#include <mutex> //mutex için gerekli kütüphane

using namespace std;

int myAmount = 0;
std::mutex m; //mutex türünde m nesnesini oluşturduk

void addMoney() {
	m.lock();
	++myAmount; //bu durumda myAmount critical region olur.
	m.unlock();
}

/*
m.lock() ile m=0 olan durumu m=1 yaparız.
m=1 durumunda yeni bir thread gelirse durum tekrar m=0 olana kadar işlem yapamaz, beklemek zorundadır.
böylece threadler birbirine karışmamış ve myAmount korunmuş olur.

critical regionın önğne lock sonuna da unlock koyarak koruruz.
lock m=1
unlock m=0 yapar.
*/

int main() {

	std::thread t1(addMoney);
	std::thread t2(addMoney);

	t1.join();
	t2.join();

	cout << myAmount << endl;
	return 0;


}
