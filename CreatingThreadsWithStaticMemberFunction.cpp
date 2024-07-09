// 5 FARKLI ŞEKİLDE  THREAD OLUŞTURABİLİRİZ.
//
// NOT: EĞER BİRDEN FAZLA THREADİ AYNI ANDA OLUŞTURURSAK, HANGİ THREADİN İLK BAŞLAYACAĞININ GARANTİSİ YOKTUR
//

#include <iostream>
#include <thread>
using namespace std;


////STATIC MEMBER FUNCTION

class Base {
public:
	static void run(int x) {
		while (x-- > 0) {
			cout << x << endl;
		}
	}
};

int main() {
	std::thread t1(&Base::run,10); //static olduğu için çağırırken object ihtiyacı duymadık 
	t1.join();
	return 0;
}
