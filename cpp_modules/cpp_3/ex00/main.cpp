#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap obj("Target Puppet");

	obj.attack("Furkan");
	cout << obj.getHealth() << endl;
	obj.takeDamage(1);
	obj.takeDamage(1);
	cout << obj.getHealth() << endl;
	obj.beRepaired(2);
	cout << obj.getHealth() << endl << obj.getEngpoint() << endl;

	return 0;
}