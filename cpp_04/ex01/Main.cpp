#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "=== Basic Animal Tests ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "\nTesting makeSound():" << std::endl;
	std::cout << "Dog sound: ";
	j->makeSound();
	std::cout << "Cat sound: ";
	i->makeSound();
	
	delete j;
	delete i;
	
	std::cout << "\n=== Animal Array Test ===" << std::endl;
	const int animalCount = 10;
	Animal* animals[animalCount];
	
	for (int idx = 0; idx < animalCount; idx++) {
		if (idx < animalCount / 2) {
			std::cout << "Creating Dog " << idx << ":" << std::endl;
			animals[idx] = new Dog();
		} else {
			std::cout << "Creating Cat " << idx << ":" << std::endl;
			animals[idx] = new Cat();
		}
	}
	
	std::cout << "\nTesting animal sounds:" << std::endl;
	for (int idx = 0; idx < animalCount; idx++) {
		std::cout << "Animal " << idx << " type: " << animals[idx]->getType() << ", sound: ";
		animals[idx]->makeSound();
	}
	
	std::cout << "\nCleaning up animals:" << std::endl;
	for (int idx = 0; idx < animalCount; idx++) {
		std::cout << "Deleting animal " << idx << " (" << animals[idx]->getType() << "):" << std::endl;
		delete animals[idx];
	}
	
	std::cout << "\n=== Deep Copy Test ===" << std::endl;
	
	std::cout << "Creating original Dog:" << std::endl;
	Dog originalDog;
	
	std::cout << "\nCreating copy of the Dog:" << std::endl;
	Dog copyDog = originalDog;
	
	std::cout << "\nCreating new Dog and assigning to original:" << std::endl;
	Dog newDog;
	originalDog = newDog;
	
	std::cout << "\nAll dogs still valid and have their own Brain instances" << std::endl;
	std::cout << "Original Dog: ";
	originalDog.makeSound();
	std::cout << "Copy Dog: ";
	copyDog.makeSound();
	std::cout << "New Dog: ";
	newDog.makeSound();
	
	std::cout << "\n=== Cat Deep Copy Test ===" << std::endl;
	
	std::cout << "Creating original Cat:" << std::endl;
	Cat* originalCat = new Cat();
	
	std::cout << "\nCreating copy of the Cat:" << std::endl;
	Cat* copyCat = new Cat(*originalCat);
	
	std::cout << "\nDeleting original Cat:" << std::endl;
	delete originalCat;
	
	std::cout << "\nCopy Cat is still valid with its own Brain:" << std::endl;
	copyCat->makeSound();
	
	std::cout << "\nDeleting copy Cat:" << std::endl;
	delete copyCat;
	
	return 0;
}