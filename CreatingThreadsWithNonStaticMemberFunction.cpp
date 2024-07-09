// 5 FARKLI ŞEKİLDE  THREAD OLUŞTURABİLİRİZ.
//
// NOT: EĞER BİRDEN FAZLA THREADİ AYNI ANDA OLUŞTURURSAK, HANGİ THREADİN İLK BAŞLAYACAĞININ GARANTİSİ YOKTUR
//

#include <iostream>
#include <thread>
using namespace std;


////NON STATIC MEMBER FUNCTION

class Base {
public:
	void run(int x) {
		while (x-- > 0) {
			cout << x << endl;
		}
	}
};

int main() {
	Base b; //non static fonksiyonları çağırırken object ihtiyacı duyarız. statikse duymayız
	std::thread t1(&Base::run,&b,10);
	t1.join();
	return 0;
}
