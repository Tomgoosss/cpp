#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Basic Animal Tests ===" << std::endl;
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "\nTesting getType():" << std::endl;
	std::cout << "Dog type: " << j->getType() << std::endl;
	std::cout << "Cat type: " << i->getType() << std::endl;
	std::cout << "Animal type: " << meta->getType() << std::endl;

	std::cout << "\nTesting makeSound():" << std::endl;
	std::cout << "Cat sound: ";
	i->makeSound();
	std::cout << "Dog sound: ";
	j->makeSound();
	std::cout << "Animal sound: ";
	meta->makeSound();

	std::cout << "\n=== Wrong Animal Tests ===" << std::endl;
	const WrongAnimal *wrong_animal = new WrongAnimal();
	const WrongAnimal *wrong_cat = new WrongCat();

	std::cout << "\nTesting getType():" << std::endl;
	std::cout << "WrongCat type: " << wrong_cat->getType() << std::endl;
	std::cout << "WrongAnimal type: " << wrong_animal->getType() << std::endl;

	std::cout << "\nTesting makeSound():" << std::endl;
	std::cout << "WrongCat sound (through WrongAnimal pointer): ";
	wrong_cat->makeSound();
	std::cout << "WrongAnimal sound: ";
	wrong_animal->makeSound();

	std::cout << "\n=== Testing Direct Objects ===" << std::endl;
	Cat direct_cat;
	Dog direct_dog;
	WrongCat direct_wrongcat;

	std::cout << "\nTesting direct object sounds:" << std::endl;
	std::cout << "Direct Cat sound: ";
	direct_cat.makeSound();
	std::cout << "Direct Dog sound: ";
	direct_dog.makeSound();
	std::cout << "Direct WrongCat sound: ";
	direct_wrongcat.makeSound();

	std::cout << "\n=== Cleanup ===" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong_animal;
	delete wrong_cat;

	return 0;
}