#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>

typedef struct
{
	int  razmer;
	double *obj;
	bool isFilled;
	double minimal;
} objarray;

int VDCel(char name[100])
{
	int i, done = 0;
	char s[100];
	printf("Введите значение %s\n", name);
	while (done == 0)
	{
		for (i = 0; i < 99; i++)
		{
			s[i] = 0;
		}

		scanf("%s", s);

		i = 0;

		if (s[0] == '-') i++;

		while (s[i] > 0)
		{
			if (!(s[i] >= '0'  && s[i] <= '9'))
			{
				//system("cls");
				printf("Некорректное значение. Пожалуйста, повторите ввод %s.\n", name);
				break;
			}
			i++;
		}
		if (s[i] <= 0) done++;

	}
	return atoi(s);
}

int VDCelPol(char name[100])
{
	int i, done = 0;
	char s[100];
	printf("Введите значение %s\n", name);
	while (done == 0)
	{
		for (i = 0; i < 99; i++)
		{
			s[i] = 0;
		}

		scanf("%s", s);

		i = 0;

		while (s[i] > 0)
		{
			if (!(s[i] >= '0'  && s[i] <= '9') || (s[i] == '0' && i == 0))
			{
				//system("cls");
				printf("Некорректное значение. Пожалуйста, повторите ввод %s.\n", name);
				break;
			}
			i++;
		}
		if (s[i] <= 0) done++;
	}
	return atoi(s);
}

double VDVesh(char name[100])
{
	int i, zapyat, done = 0;
	char s[100];

	while (done == 0)
	{
		zapyat = 0;

		for (i = 0; i < 99; i++)
		{
			s[i] = 0;
		}

		scanf("%s", s);

		i = 0;

		if (s[0] == '-') i++;

		while (s[i] > 0)
		{
			if (s[i] == '.') zapyat++;
			if (!(s[i] >= '0'  && s[i] <= '9') && s[i] != '.' || s[i] == '.' && zapyat > 1)
			{
				printf("Некорректное значение %s. Пожалуйста, повторите ввод значения %s.\n", name, name);
				break;
			}
			i++;

		}
		if (s[i] <= 0) done++;
	}
	return atof(s);
}

void Customfill(objarray *object)
{
	//free(object->obj); = free((*object).obj);
	if (object->isFilled)
	{
		free(object->obj);
	}
	int i;
	//(*object).razmer = VDCelPol("размера массива");
	object->razmer = VDCelPol("размера массива");
	object->obj = (double*)malloc(object->razmer * sizeof(double));
	system("cls");
	printf("Далее поочередно вводите элементы массива.\n");
	for (i = 0; i < object->razmer; i++)
	{
		object->obj[i] = VDCel("элемента массива");
		if (object->minimal < object->obj[i])
		{
			object->minimal = object->obj[i];
		}
	}
	object->isFilled = true;
}

void RandomFill(objarray *object)
{
	srand((unsigned)time(NULL));
	if (object->isFilled)
	{
		free(object->obj);
	}
	object->razmer = VDCelPol("размера массива");
	object->obj = (double*)malloc(object->razmer * sizeof(double));
	for (int i = 0; i < object->razmer; i++)
	{
		object->obj[i] = (rand() % 201) - 100;
		if (object->minimal < object->obj[i])
		{
			object->minimal = object->obj[i];
		}
	}
	object->isFilled = true;
}

void obrabotka(objarray *object)
{
	int i;
	double sum = 0, sred;
	for (i = 0; i < object->razmer; i++)
	{
		if (object->obj[i] < object->minimal)
		{
			object->minimal = object->obj[i];
		}
		if ((i + 1) % 2 == 0)
		{
			sum += object->obj[i];
		}
		sred = sum / (object->razmer / 2);
	}
	for (i = 0; i < object->razmer; i++)
	{
		if (object->obj[i] == object->minimal)
		{
			object->obj[i] = sred;
		}
	}
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	objarray object;
	object.isFilled = false;
	object.razmer = -1;
	object.obj = NULL;
	object.minimal = 0;

	int k = -1, vih, n = 0;
	while (k != 5)
	{
		system("cls");
		printf("Меню пользователя:\n1. Ввести элементы массива вручную.\n2. Заполнить массив случайными числами.\n3. Вывести массив на экран.\n4. заменить минимальное значение элементов массива средним арифметическим его элементов, находящихся на четных позициях.\n5. Выход.\n");
		k = VDCelPol("номера команды");
		if (k == 1)
		{
			system("cls");
			Customfill(&object);
			printf("Ввод массива завершен.\n");
		}
		if (k == 2)
		{
			system("cls");
			RandomFill(&object);
			printf("Массив был заполнен случайными числами в диапозоне от -100 до 100.\n");
		}
		if (k == 3)
		{
			system("cls");
			if (object.isFilled)
			{
				printf("Элементы массива:\n");
				for (int i = 0; i < object.razmer; i++)
				{
					printf("%lf\n", object.obj[i]);
				}
			}
			else
			{
				printf("Массив не был заполнен.\n");
			}
		}
		if (k == 4)
		{
			system("cls");
			if (object.isFilled && object.razmer > 1)
			{
				obrabotka(&object);
				printf("Массив был обработан.\n");
			}
			else
			{
				printf("Массив не был заполнен или состоит из одного элемента.\n");
			}
		}
		if (k != 5)
		{
			getchar();
			getchar();
		}
	}
	printf("Работа программы завершена.\n");
	free(object.obj);
	return 0;
}
