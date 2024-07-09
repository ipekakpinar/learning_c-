#include <iostream>
#include <thread>
using namespace std;
// LAMBDA FONKSİYONU İLE THREAD OLUŞTURMA

//Lambdayı thread oluşturma esnasında doğrudan enjekte edebiliriz.
int main() {
	/* auto fun = [](int x) {
		while (x-- > 0) {
			cout << x << endl;

		}
		};

	std::thread t1(fun, 10);*/

	// yerine;

	std::thread t1([](int x) {
		while (x-- > 0) {
			cout << x << endl;
		}
		},10);


	t1.join();
	return 0;
}

/************
* 
* NOT:
* auto anahtar kelimesi, C++11 ile birlikte gelen bir özelliktir ve bir değişkenin türünü otomatik olarak çıkarsar.
Bu, özellikle karmaşık türler için yararlıdır ve kodun daha okunabilir olmasını sağlar. auto kullanıldığında, derleyici değişkenin türünü bağlamdan çıkarır.


*
* Lambda İfadesi: [](int x) { ... } bir lambda ifadesidir. [] içinde herhangi bir değişken belirtilmediği için, bu lambda dışarıdan hiçbir değişkeni yakalamaz.
(int x) lambda ifadesinin bir parametre aldığını belirtir.
* 
* kod parçası, x değeri 0'dan büyük olduğu sürece x'i azaltarak (x--) ekrana yazdırır (cout << x << endl). Döngü, x değeri 0'a ulaştığında durur.
**********/

