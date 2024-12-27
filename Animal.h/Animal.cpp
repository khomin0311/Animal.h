#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal // Animal Ŭ���� ����
{
public:
	Animal() {} // ������
	virtual void makeSound() = 0; // ���� �����Լ� ����
	// ����	�����Լ��� �ڽ� Ŭ�������� �ݵ�� �����ؾ� �ϹǷ� Animal Ŭ���������� �������� ����
	virtual ~Animal() {} // �Ҹ���

};

// Dog, Cat, Cow Ŭ������ Animal Ŭ������ ��ӹ���

// Dog Ŭ������ Animal Ŭ������ ��ӹް� makeSound �Լ��� �����ؾ���
class Dog : public Animal // Dog Ŭ���� ����
{
public:
	void makeSound() { // makeSound �Լ� ����
		cout << "Dog is Bow-wow" << endl; // Dog�� �Ҹ� ���
	}
};

// Cat Ŭ������ Animal Ŭ������ ��ӹް� makeSound �Լ��� �����ؾ���
class Cat : public Animal // Cat Ŭ���� ����
{
public:
	void makeSound() { // makeSound �Լ� ����
		cout << "Cat is Meow" << endl; // Cat�� �Ҹ� ���
	}
};

// Cow Ŭ������ Animal Ŭ������ ��ӹް� makeSound �Լ��� �����ؾ���
class Cow : public Animal // Cow Ŭ���� ����
{
public:
	void makeSound() { // makeSound �Լ� ����
		cout << "Cow is Moo" << endl; // Cow�� �Ҹ� ���
	}
};
void print(Animal* animal) // print �Լ� ����
{
	animal->makeSound(); // Animal Ŭ������ makeSound �Լ� ȣ��
}
int main()
{
	vector<Animal*> animals; // Animal Ŭ������ �����͸� ������ ���� ����
	// ���Ϳ� ���� ��ü�� �����Ͽ� ����
	animals.push_back(new Dog()); // Dog ��ü ���� �� ���Ϳ� ����
	animals.push_back(new Cat()); // Cat ��ü ���� �� ���Ϳ� ����
	animals.push_back(new Cow()); // Cow ��ü ���� �� ���Ϳ� ����

	char userInput; // ����� �Է��� ���� ���� ����

	// ������ ũ�⸸ŭ �ݺ��ϸ鼭 ������ �Ҹ� ���
	for (size_t i = 0; i < animals.size(); ++i) { // ������ ũ�⸸ŭ �ݺ�
		cout << "Enter �� ������ ���� �����Ҹ��� ���ɴϴ�, �Ǵ� q �� ���� ���� �Ͻʽÿ�." << endl; // �ȳ��� ���
		cin.get(); // ����� �Է��� ����
		print(animals[i]);  // print �Լ��� �� ������ �Ҹ��� ���
	}
	for (size_t i = 0; i < animals.size(); ++i) { // ������ ũ�⸸ŭ �ݺ�
		delete animals[i]; // ���� ��ü ����
	}

	return 0;
}