//-----------------------------------------------------------------------------
// File: packcage.cpp
//                                     Реализация классов и тестирующих функций
//-----------------------------------------------------------------------------
#include "packcage.h"
//-----------------------------------------------------------------------------
void test1() // Из методички
{
	Bas *pObj;
	Type1 T1(10);
	Type2 T2(20);
	// Задание значения указателя для Т1
	pObj = &T1;
	cout << "T1 = " << T1.Coord << " T2 = " << T2.Coord <<endl;
	//При pObj->Move(); Ошибка, так как указатель па базовый класс, а так Move нет!
	switch (pObj->ClassType)
	{
		case 1:
			((Type1 *)pObj)->Move(5); break; // Типизация указателя для Type1
		case 2:
			((Type2 *)pObj)->Move(5); break; // Типизация указателя для Type2
	}
	cout << "T1 = " << T1.Coord << " T2 = " << T2.Coord <<endl;
	// Задание значения указателя для Т2
	pObj = &T2;
	switch (pObj->ClassType)
	{
		case 1:
			((Type1 *)pObj)->Move(5); break;
		case 2:
			((Type2 *)pObj)->Move(5); break;
	}
	cout << "T1 = " << T1.Coord << " T2 = " << T2.Coord <<endl;
}
//-----------------------------------------------------------------------------
void test2()
{
	// 4.6. Проверка описания объекта абстрактного класса
	//Abstr a(10); // ОШИБКА: Нельзя создать экземпляр абстрактного класса

	// 4.7. Проверка созданных классов – описание объектов
	Abstr *pAbs;
	Deriv1 d1(33);
	Deriv2 d2(44);
	Deriv3 d3(66);

	// 4.8. Проверка вызова функции через объекты
	d1.print();
	d2.print();
	d3.print();
	cout << endl << endl;

	// 4.9. Проверка вызова функции через указатель на объект
	Deriv1 *pD1 = &d1, *pD2 = &d2, *pD3 = &d3;
	pD1->print();
	pD2->print();
	pD3->print();
	cout << endl << endl;

	// 4.10. Проверка виртуального вызова функции
	pAbs = &d1;
	pAbs->print();
	pAbs = &d2;
	pAbs->print();
	pAbs = &d3;
	pAbs->print();
	cout << endl << endl;

	// 4.11. Описание объекта списка типа CObList
	CObList ListDer;
	// Описание: https://msdn.microsoft.com/ru-ru/library/425sx0t2.aspx

	// 4.12. Занесение объектов в список трех типов
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			Abstr *p;
			switch (i)
			{
				case 1:
					p = new Deriv1(i*j);
					break;
				case 2:
					p = new Deriv2(i*j);
					break;
				case 3:
					p = new Deriv3(i*j);
					break;
			}
			//ListDer.AddHead(p); // В начало (в голову)
			ListDer.AddTail(p);   // В конец (в хвост)
		}
	}

	// 4.13. Распечатка списка объектов с помощью виртуального вызова
	for (auto pos = ListDer.GetHeadPosition(); pos != NULL;)
	{
		Abstr *cur_obj = (Abstr*)ListDer.GetNext(pos);
		cur_obj->print();
	}
	cout << endl << endl;

	// Удаление из списка элемента под индексом 5
	int i = 0;
	for (auto pos = ListDer.GetHeadPosition(); pos != NULL; ++i)
	{
		if (i == 5)
		{
			pAbs = (Abstr*)ListDer.GetAt(pos);
			ListDer.RemoveAt(pos);
			cout << "!" << endl;
			delete pAbs;
		}
		else
		{
			ListDer.GetNext(pos);
		}
	}
	cout << endl << endl;

	// 4.14. Виртуальные деструкторы
	for (auto pos = ListDer.GetHeadPosition(); pos != NULL;)
	{
		Abstr *cur_obj = (Abstr*)ListDer.GetNext(pos);
		delete cur_obj;
		cout << "END!" << endl;
	}


	F obj(1, 2, 3, 4);
	obj.print();

}
//-----------------------------------------------------------------------------