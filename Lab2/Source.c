#include <stdio.h>
#include <windows.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct
{
	int  razmer;
	double *obj;
	bool isFilled;
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
	return (atoi(s));
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
			if (!(s[i] >= '1'  && s[i] <= '9'))
			{
				//system("cls");
				printf("Некорректное значение. Пожалуйста, повторите ввод %s.\n", name);
				break;
			}
			i++;
		}
		if (s[i] <= 0) done++;
	}
	return (atoi(s));
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
	return (atof(s));
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
	}
	object->isFilled = true;
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	objarray object;
	object.isFilled = false;
	object.razmer = -1;
	object.obj = NULL;

	int k = -1, vih, n = 0;
	while (k != 5)
	{
		printf("Меню пользователя:\n1. Ввести элементы массива вручную.\n2. Заполнить массив случайными числами.\n3. Вывести массив на экран.\n4. заменить минимальное значение элементов массива средним арифметическим его элементов, находящихся на четных позициях.\n5. Выход.\n");
		k = VDCelPol("номера команды");
		if (k == 1)
		{
			system("cls");
			/*printf("Введите количество элементов массива.\n");*/
			Customfill(&object);
		}
		if (k == 3)
		{

			system("cls");
			if (object.isFilled)
			{
				printf("Элементы массива:\n");
				for (int i = 0; i < object.razmer; i++)
					printf("%lf ", object.obj[i]);
			}
			else
			{
				printf("Массив не был заполнен.\n");
			}
			system("pause");
		}

	}
	printf("Работа программы завершена.\n");
	free(object.obj);
	getchar();
	getchar();
	return 0;
}