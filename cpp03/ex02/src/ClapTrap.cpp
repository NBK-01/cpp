#include "../headers/ClapTrap.h"

ClapTrap::ClapTrap(std::string _name) : _name(_name), hitPoints(100), energyPoints(50), attackDamage(20)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
	this->_name = clapTrap._name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	this->attackDamage = clapTrap.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << YELLOW "------------- STATS -------------" << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Hit Points: " << hitPoints << std::endl;
	std::cout << "Energy Points: " << energyPoints << std::endl;
	std::cout << "--------------------------------" RESET << std::endl;
	if (this->energyPoints == 0)
	{
		std::cout  << RED "ClapTrap " << _name << " is out of energy points!" RESET << std::endl;
		return ;
	}
	this->energyPoints = this->energyPoints - 1;
	std::cout << "<<<-------------- 🗡️🗡️🗡️🗡️🗡️ ------------------>>>>" << std::endl;
	std::cout << GREEN "ClapTrap " << _name << RED " attacks " << target << ", causing " << attackDamage << " points of damage!\n\n\n" RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << YELLOW "------------- STATS -------------" << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Hit Points: " << hitPoints << std::endl;
	std::cout << "Energy Points: " << energyPoints << std::endl;
	std::cout << "--------------------------------" RESET << std::endl;
	if (this->hitPoints == 0)
	{
		std::cout << RED "ClapTrap " << _name << " is already dead!" RESET << std::endl;
		return ;
	}
	this->hitPoints = this->hitPoints - amount;
	std::cout << "<<<-------------- 🛡️🛡️🛡️🛡️🛡️ ------------------>>>>" << std::endl;
	std::cout << GREEN "ClapTrap " << _name << RED " takes " << amount << " points of damage!\n\n\n" RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << YELLOW "------------- STATS -------------" << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Hit Points: " << hitPoints << std::endl;
	std::cout << "Energy Points: " << energyPoints << std::endl;
	std::cout << "--------------------------------" RESET << std::endl;
	if (this->hitPoints == 10)
	{
		std::cout << GREEN "ClapTrap " << _name << " is already at full health!" RESET << std::endl;
		return ;
	}
	this->energyPoints = this->energyPoints - 1;
	this->hitPoints = this->hitPoints + amount;
	std::cout << "<<<-------------- 🩹🩹🩹🩹🩹 ------------------>>>>" << std::endl;
	std::cout << GREEN "ClapTrap " << _name << " is repaired for " << amount << " points!\n\n\n" RESET << std::endl;
}
