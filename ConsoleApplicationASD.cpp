

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
	void Init() {

		head = NULL;

	}



	void Add(int n) {

		if (head == NULL) {

			head = new element;
			head->value = n;
			head->next = 0;
			size++;
		}
		else if (head->next == 0) {

			element* tmpElement = new element;
			tmpElement->value = n;
			tmpElement->next = 0;
			head->next = tmpElement;
			size++;
		}
		else {

			element* currentElement = head->next;

			while (currentElement->next != 0) {

				currentElement = currentElement->next;

			}

			element* tmpElement = new element;
			tmpElement->value = n;
			tmpElement->next = 0;
			currentElement->next = tmpElement;
			size++;
		}

	}


	int Del(bool a) {

		int n = 0;

		if (Isempty() != 1) {
			n = head->value;
			head = head->next;


			if (Isempty() == 1) //2
			{
				Init(); //2
			}
		}
		size--;
		return n;

	}
	// удаление элемента из конца очереди
	int Del() //1+(2+2+2+1+2+2+2)=14
	{
		int val = NULL; //1
		// если очередь не пуста
		if (Isempty() != 1) //2
		{
			// создаем указатель на структуру
			element* tmp;
			// в указателюь tmp кладем ссылку на next предпоследнего элемента в очереди
			tmp = head->next; //2
			// в val записываем значение последнего элемента в очереди
			val = head->value; //2
			// удаляем объект по указателю head (последний элемент в очереди)
			delete head;
			// head начинает указывать на предпоcледний элемент в очереди (последний удален)
			head = tmp; //1
			// После удаления последнего элемента из очереди происходит повторная инициализация
			if (Isempty() == 1) //2
			{
				Init(); //2
			}
			size--; //2
			// возвращаем значение последнего элемента в очереди
			return val;
		}
		else { cout << "Очередь пуста!" << endl; }
		return 0;
	}

	void print() {

		element* currentElement = head;
		while (currentElement != 0) {

			cout << currentElement->value << " ";
			currentElement = currentElement->next;

		}

		cout << endl;

	}

	bool Isempty() {
		return head == 0;
	}
	int Value() //3
	{
		// если очередь не пуста
		if (Isempty() != 1) //2
		{
			// через указатель head получить значение value последнего элемента в очереди
			return head->value; //1
		}
		else { cout << "Очередь пуста!" << endl; }
		return 0;
	}
};


// Класс наследник
class Numbers : public Queue
{
public:
	int size_1 = 0;
	// получение значения из списка, x - номер элемента в списке
	int get(int x) //2+1+1+(1+33n)=5+33n
	{
		// если очередь не пуста
		if (Isempty() != 1) //2
		{
			size_1 = size; //1
			int val1 = NULL; //1
			// Перебор всех значений в списке
			for (int i = 1; i < size_1 + 1; i++) //1+∑(1+4+1+27)=1+∑(33)=1+33𝑛𝑛1𝑛1
			{
				if (i == x) //1
				{
					// Когда i доходит до номера получаемого элемента, то в val записывается значение данного элемента
					val1 = Value(); //4
				}
				// Перебор начинается только в случае если x не равен нулю
				if (x != 0) //1
				{
					// Вначале элемент удаляется из конца очереди, и сразу же добавляется в начало очереди, и так в цикле пока не восстановится первоначальное состояние очеред
					Add(Del()); //14+13=27
				}
				else
				{
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
	void set(int x, int y) //2+3+31n=5+31n
	{
		// если очередь не пуста
		if (Isempty() != 1) //2
		{

			if (x <= size) //1+1+1+31n=3+31n
			{
				size_1 = size; //1
				for (int i = 1; i < size_1 + 1; i++) //1+∑(1+2+1+27)𝑛1=1+31𝑛
				{
					if (i == x) //1
					{
						// Запись значения y в список
						head->value = y; //2
					}
					if (x != 1) //1
					{
						Add(Del()); //14+13=27
					}
					else
					{
						break;
					}
				}
			}
			// Если элемент устанавливается за пределы изначального списка
			else //1+2+1+∑(13)+13𝑥𝑛+1=17+ ∑(13)𝑥𝑛+1
			{
				if (x == size + 1) //2
				{
					//Если номер элемента в списке на 1 больше размера очереди, значит элемент добавляется в начало очереди
					Add(y);
				}
				else
				{
					for (i = size + 1; i < x; i++) //1+∑(13)𝑥𝑛+1
					{
						// В противном случае очередь заполняется нулями
						Add(0); //13
					}
					Add(y); //13
				}
			}
		}
		else { cout << "Очередь пуста!" << endl; }
	}
	void sort(int N)
	{
		int temp; // временная переменная для обмена элементов местами
		// Сортировка массива пузырьком
		for (int i = 0; i < size - 1; i++) // 3 + ∑0->n-1(
		{
			for (int j = 0; j < size - i - 1; j++) //4++∑0->n-
			{

				if (get(j) > get(j + 1)) // 12+66n
				{
					// меняем элементы местами
					temp = get(j); // 6+33n
					set(j, get(j + 1)); // 128n+11
					set(j + 1, temp); // 6+31n

				}
			}
		}
		for (int i = 0; i < N; i++) { cout << get(i) << " "; } // для вывода отсортированного массива
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
		cout << "Номер сортировки: " << i + 1 << " Колличество отсортированных элементов: " << N << " Время сортировки (ms): " << t_f - t_s << " Колличество операций (N_op): " << endl; // Шаг в 30 элементов
		cout << endl;
		N = N + 30;
	}
	return 0;
}

