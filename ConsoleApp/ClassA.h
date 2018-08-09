#pragma once

class ClassA
{
private:
	int a, b;
public:
	ClassA();
	ClassA(ClassA &obj);

	void PlayBoost();

	void PlayBoost2();

	void PlayVec();
	void PlayMap();
	void PlayBook1();
	void PlayReverse();
	void PlayReverse2();
	void PlayReverse3();
	void PlayReverse4();
	void PlayErastos();
	void PlayCopy1();
	virtual ~ClassA();
};

