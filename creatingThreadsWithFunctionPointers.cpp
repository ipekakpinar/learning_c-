// 5 FARKLI ŞEKİLDE  THREAD OLUŞTURABİLİRİZ.
//
// NOT: EĞER BİRDEN FAZLA THREADİ AYNI ANDA OLUŞTURURSAK, HANGİ THREADİN İLK BAŞLAYACAĞININ GARANTİSİ YOKTUR
//

#include <iostream>
#include <thread>
using namespace std;


//FONKSİYON POINTERI İLE THREAD OLUŞTURMA



void fun(int x) {
	while (x-- > 0) {

		cout << x << endl;

	}
}

int main() {
	std::thread t1(fun, 11);
	t1.join();
	return 0;

}
