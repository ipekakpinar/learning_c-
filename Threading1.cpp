#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>
using namespace std::chrono_literals;

void RefreshForecast(std::map<std::string, int>forecastMap) {
	while (true) {
		for (auto& item : forecastMap) {
			item.second++;//item.second=sıcaklık
			std::cout << item.first << " - " << item.second << std::endl;
		}
			

		
		std::this_thread::sleep_for(2000ms);//2 snliğine şuanki threadi sleep yap

	}
}

int main(){

	std::map<std::string, int> forecastMap = {
		{"New York",15},
		{ "Mumbai", 20 },
		{"Istanbul",30 }
	};

	std::thread bgWorker(RefreshForecast, forecastMap);
	system("pause>nul");

	bgWorker.join();
	return 0;
}
