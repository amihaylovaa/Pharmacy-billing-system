#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void welcome()
{	
	cout << "               * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n";
	cout << "               *                                                                                       * \n";
	cout << "               *         |\\           /|   ______             ______                _____              * \n";
	cout << "               *         | \\         / |  |      |  |    /|  |      | |        |      |     |     |    * \n";
	cout << "               *         |  \\       /  |  |      |  |   / |  |      | |        |      |     |     |    * \n";
	cout << "               *         |   \\     /   |  |      |  |  /  |  |      | |        |      |     |_____|    * \n";
	cout << "               *         |    \\   /    |  |      |  | /   |  |      | |        |      |     |     |    * \n";
	cout << "               *         |     \\ /     |  |______|  |/    |  |______| |______  |      |     |     |    * \n";
	cout << "               *                                                                                       * \n";
	cout << "               * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  \n";

	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	
	system("cls");

	return;
}
