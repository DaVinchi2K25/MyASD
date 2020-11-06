

#include <locale.h>

#include <ctime>

#include "windows.h"

#include <iostream>
using namespace std;



struct element {

	int value;
	element* next;

};
class Queue {

public:
	element* head;
	int N;
	int i;
	int size;
	unsigned long long int N_op = 0;
	void Init() {

		head = 0; N_op++;

	}


	void Add(int n) {

		if (head == 0) {
			N_op++;
			head = new element; N_op++;
			head->value = n; N_op+=2;
			head->next = 0; N_op+=2;
			size++; N_op+=2;
		}
		else if (head->next == 0) {
			N_op+=2;
			element* tmpElement = new element; N_op += 3;
			tmpElement->value = n; N_op += 2;
			tmpElement->next = 0; N_op += 2;
			head->next = tmpElement; N_op += 2;
			size++; N_op+=2;
		}
		else {

			element* currentElement = head->next; N_op += 3;
			
			while (currentElement->next != 0) {
				N_op += 2;
				currentElement = currentElement->next; N_op += 2;

			}

			element* tmpElement = new element; N_op += 3;
			tmpElement->value = n; N_op += 2;
			tmpElement->next = 0; N_op += 2;
			currentElement->next = tmpElement; N_op += 2;
			size++; N_op += 2;
		}

	}

	// удаление элемента из конца очереди
	int Del() //1+(2+2+2+1+2+2+2)=14
	{
		int val = 0; N_op++; //1
		// если очередь не пуста
		if (Isempty() != 1) //2
		{
			N_op++;
			// создаем указатель на структуру
			element* tmp;
			// в указателюь tmp кладем ссылку на next предпоследнего элемента в очереди
			tmp = head->next; N_op += 2; //2
			// в val записываем значение последнего элемента в очереди
			val = head->value; N_op += 2; //2
			// удаляем объект по указателю head (последний элемент в очереди)
			delete head;
			// head начинает указывать на предпоcледний элемент в очереди (последний удален)
			head = tmp; N_op++; //1
			// После удаления последнего элемента из очереди происходит повторная инициализация
			if (Isempty() == 1) //2
			{
				N_op++;
				Init(); //2
			}
			size--; N_op += 2;//2
			// возвращаем значение последнего элемента в очереди
			return val;
		}
		else { cout << "Очередь пуста!" << endl; }
		return 0;
	}

	void print() {

		element* currentElement = head; N_op += 2;
		while (currentElement != 0) {
			N_op++;
			cout << currentElement->value << " "; N_op++;
			currentElement = currentElement->next; N_op += 2;

		}

		cout << endl;

	}

	bool Isempty() {
		return head == 0; N_op++;
	}
	int Value() //3
	{
		// если очередь не пуста
		if (Isempty() != 1) //2
		{
			N_op++;
			// через указатель head получить значение value последнего элемента в очереди
			return head->value; N_op++; //1
		}
		else { cout << "Очередь пуста!" << endl; }
		return 0;
	}
};


// Класс наследник
class Numbers : public Queue
{
public:
	int size_1;
	// получение значения из списка, x - номер элемента в списке
	int get(int x)
	{
		// если очередь не пуста
		if (Isempty() != 1)
		{
			N_op++;
			size_1 = size; N_op++;
			int val1 = NULL; N_op++;

			/* Перебор всех значений в списке*/ N_op++;
			for (int i = 1; i < size_1 + 1; i++)
			{
				if (i == x)
				{
					N_op++;
					// Когда i доходит до номера получаемого элемента, то в val записывается значение данного элемента
					val1 = Value();	N_op++;
				}

				// Перебор начинается только в случае если x не равен нулю
				if (x != 1)
				{
					N_op++;
					// Вначале элемент удаляется из конца очереди, и сразу же добавляется в начало очереди, и так в цикле пока не восстановится первоначальное состояние очереди
					Add(Del());
				}
				else
				{
					N_op++;
					// В противном случае сразу выходим из цикла for
					break;
				}
			}
			// Возвращается значение элемента под номером x из очереди
			return val1;
		}
		else { cout << "Очередь пуста!" << endl; }
		return 0;
	}

	// установка значения элемента в списке, x - номер элемента в списке, y - значение элемента в списке
	void set(int x, int y)
	{
		// если очередь не пуста
		if (Isempty() != 1)
		{
			N_op++;
			if (x <= size)
			{
				N_op++;
				size_1 = size; N_op++;
				N_op++;
				for (int i = 1; i < size_1 + 1; i++)
				{
					if (i == x)
					{
						N_op++;
						// Запись значения y в список
						head->value = y; N_op += 2;
					}

					if (x != 1)
					{
						N_op++;
						Add(Del());
					}
					else
					{
						N_op++;
						break;
					}
				}
			}
			// Если элемент устанавливается за пределы изначального списка
			else
			{
				N_op++;
				if (x == size + 1)
				{
					N_op += 2;
					//Если номер элемента в списке на 1 больше размера очереди, значит элемент добавляется в начало очереди
					Add(y);
				}
				else
				{
					N_op += 2; N_op++;
					for (i = size + 1; i < x; i++)
					{
						// В противном случае очередь заполняется нулями
						Add(0);
					}
					Add(y);
				}
			}
		}
		else { cout << "Очередь пуста!" << endl; }
	}

	void sort(int N)
	{
		int temp; // временная переменная для обмена элементов местами
		// Сортировка массива пузырьком
		N_op += 3;
		for (int i = 0; i < size - 1; i++) // 3 + ∑0->n-1(
		{
			N_op += 4;
			N_op += 4;
			for (int j = 0; j < size - i - 1; j++) //4++∑0->n-
			{
				N_op += 5;
				N_op += 2;
				if (get(j) > get(j + 1)) // 12+66n
				{	
					// меняем элементы местами
					temp = get(j); N_op++; // 6+33n
					set(j, get(j + 1)); N_op++; // 128n+11
					set(j + 1, temp); N_op++;// 6+31n

				}
			}
		}
		//for (int i = 0; i < N; i++) { cout << get(i) << " "; } // для вывода отсортированного массива
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	// Схема эксперимента
	// Инициализация очереди и заполнение хранилища ключей
	int i, t_s, t_f;
	// Хранилище ключей
	int Key[300];
	int N = 30;
	Numbers list;
	list.Init();
	for (i = 0; i < 300; i++)
	{
		// Заполнение хранилища ключей случайными числами до 1000
		Key[i] = rand() % 999;
	}
	for (i = 0; i < 10; i++)
	{
		for (int z = N - 30; z < N; z++)
		{
			list.Add(Key[z]);
		}
		t_s = GetTickCount64();
		list.sort(N);
		t_f = GetTickCount64();
		cout << "Номер сортировки: " << i + 1 << " Колличество отсортированных элементов: " << N << " Время сортировки (ms): " << t_f - t_s << " Колличество операций (N_op): " << list.N_op << endl; // Шаг в 30 элементов
		cout << endl;
		N = N + 30;
	}
	return 0;
}

