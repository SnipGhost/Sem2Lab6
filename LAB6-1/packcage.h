//-----------------------------------------------------------------------------
// File: packcage.h
//                                                 Описание и структура классов
//-----------------------------------------------------------------------------
#pragma once       // Гарантируем подключение данного файла только один раз
#ifndef PACKCAGE_H // Такая же проверка, поддерживаем обратную совместимость
#define PACKCAGE_H
//-----------------------------------------------------------------------------
// Линкуем нужные библиотеки
//-----------------------------------------------------------------------------
#include <afx.h>
#include <iostream>
#include <atlcoll.h>
using namespace std;
//-----------------------------------------------------------------------------
// Протестировать пункт 4.3
void test1();
// Протестировать пункт 4.4
void test2();
//-----------------------------------------------------------------------------
// Пункт 4.3
//-----------------------------------------------------------------------------
// Базовый класс
class Bas 
{
 public:
	 int a;
	 int ClassType;
	 Bas() { a = 0; ClassType = 0;};      // Конструктор 1
	 Bas(int x) { a = x; ClassType = 0;}; // Конструктор 2
};
// Производный класс 1
class Type1: public Bas 
{
 public:
	 int Coord; 
	 Type1() { Coord = 0; ClassType = 1;};            // Конструктор 1
	 Type1(int x) { Coord = x; ClassType = 1;};       // Конструктор 2
	 void Move(int Delta) { Coord = Coord + Delta; }; // Метод для "+"
};
// Производный класс 2
class Type2: public Bas 
{ 
 public:
	 int Coord; 
	 Type2() { Coord = 0; ClassType = 2;};            // Конструктор 1
	 Type2(int x) { Coord = x; ClassType = 2;};       // Конструктор 2
	 void Move(int Delta) { Coord = Coord - Delta; }; // Метод для "-"
};
//-----------------------------------------------------------------------------
// Пункт 4.4
//-----------------------------------------------------------------------------
class Abstr: public CObject
{
 public:
	 int iPar;
	 Abstr(): iPar(0) {}
	 Abstr(int p): iPar(p) {}
	 virtual ~Abstr() {}
	 virtual void print() = 0;
};

class Deriv1: public Abstr
{
 public:
	 int iDPar;
	 Deriv1(): iDPar(0) { cout << "Объект Deriv1 создан с 0" << endl; }
	 Deriv1(int p): iDPar(p) { cout << "Объект Deriv1 создан с p" << endl; }
	 virtual ~Deriv1() { cout << "Объект Deriv1 уничтожен" << endl; }
	 virtual void print() 
	 { cout << "Deriv1 = " << iDPar << " Absrt = " << iPar << endl; }
};

class Deriv2: public Deriv1
{
 public:
	 int iDPar;
	 Deriv2(): iDPar(0) { cout << "Объект Deriv2 создан c 0" << endl; }
	 Deriv2(int p): iDPar(p) { cout << "Объект Deriv2 создан c p" << endl; }
	 virtual ~Deriv2() { cout << "Объект Deriv2 уничтожен" << endl; }
	 virtual void print() 
	 { cout << "Deriv2 = " << iDPar << " Absrt = " << iPar << endl; }
};

class Deriv3: public Deriv1
{
 public:
	 int iDPar;
	 Deriv3(): iDPar(0) { cout << "Объект Deriv3 создан c 0" << endl; }
	 Deriv3(int p): iDPar(p) { cout << "Объект Deriv3 создан c p" << endl; }
	 virtual ~Deriv3() { cout << "Объект Deriv3 уничтожен" << endl; }
	 virtual void print() 
	 { cout << "Deriv3 = " << iDPar << " Absrt = " << iPar << endl; }
};
//-----------------------------------------------------------------------------
#endif /* PACKCAGE_H */
//-----------------------------------------------------------------------------