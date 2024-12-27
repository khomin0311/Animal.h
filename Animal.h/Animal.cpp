#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal // Animal 클래스 선언
{
public:
	Animal() {} // 생성자
	virtual void makeSound() = 0; // 순수 가상함수 선언
	// 순수	가상함수는 자식 클래스에서 반드시 구현해야 하므로 Animal 클래스에서는 구현하지 않음
	virtual ~Animal() {} // 소멸자

};

// Dog, Cat, Cow 클래스는 Animal 클래스를 상속받음

// Dog 클래스는 Animal 클래스를 상속받고 makeSound 함수를 구현해야함
class Dog : public Animal // Dog 클래스 선언
{
public:
	void makeSound() { // makeSound 함수 구현
		cout << "Dog is Bow-wow" << endl; // Dog의 소리 출력
	}
};

// Cat 클래스는 Animal 클래스를 상속받고 makeSound 함수를 구현해야함
class Cat : public Animal // Cat 클래스 선언
{
public:
	void makeSound() { // makeSound 함수 구현
		cout << "Cat is Meow" << endl; // Cat의 소리 출력
	}
};

// Cow 클래스는 Animal 클래스를 상속받고 makeSound 함수를 구현해야함
class Cow : public Animal // Cow 클래스 선언
{
public:
	void makeSound() { // makeSound 함수 구현
		cout << "Cow is Moo" << endl; // Cow의 소리 출력
	}
};
void print(Animal* animal) // print 함수 정의
{
	animal->makeSound(); // Animal 클래스의 makeSound 함수 호출
}
int main()
{
	vector<Animal*> animals; // Animal 클래스의 포인터를 저장할 백터 생성
	// 백터에 동물 객체를 생성하여 저장
	animals.push_back(new Dog()); // Dog 객체 생성 후 백터에 저장
	animals.push_back(new Cat()); // Cat 객체 생성 후 백터에 저장
	animals.push_back(new Cow()); // Cow 객체 생성 후 백터에 저장

	char userInput; // 사용자 입력을 받을 변수 선언

	// 백터의 크기만큼 반복하면서 동물의 소리 출력
	for (size_t i = 0; i < animals.size(); ++i) { // 백터의 크기만큼 반복
		cout << "Enter 를 누르면 다음 동물소리가 나옵니다, 또는 q 를 눌러 종료 하십시오." << endl; // 안내문 출력
		cin.get(); // 사용자 입력을 받음
		print(animals[i]);  // print 함수로 각 동물의 소리를 출력
	}
	for (size_t i = 0; i < animals.size(); ++i) { // 백터의 크기만큼 반복
		delete animals[i]; // 동물 객체 삭제
	}

	return 0;
}