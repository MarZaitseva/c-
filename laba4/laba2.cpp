#include <iostream>
#include <string>

using namespace std;

struct Cat
{
	string Name;
	int age = 1;
	int health = 9;
	string color;

	void Feed(int foodCount)
	{
		health += foodCount;
	}

	void Punish(int punch)
	{
		health -= punch;
	}
};

void main()
{
	cout << "name the cat" << endl;

	Cat cat;
	cin >> cat.Name;
	
	while (cat.health > 0)
	{
		cat.color = "green";
		cout << "choose an action" << endl;
		cout << "1 - feed the cat" << endl;
		cout << "2 - punish the cat" << endl;
		cout << "3 - find out the age of the cat" << endl;

		int action;
		cin >> action;

		if (action == 1)
		{
			cout << "enter the amount of feed" << endl;
			int foodCount;
			cin >> foodCount;

			cat.Feed(foodCount);
		}

		if (action == 2)
		{
			cout << "enter the number of punches" << endl;
			int punch;
			cin >> punch;

			cat.Punish(punch);
		}
		if (action == 3)
		{
			cout << cat.age << endl;
		}

		if (cat.health < 0)
		{
			cat.color = "white";
		}

		cout << "cat health-" << cat.color << endl;
	}
}