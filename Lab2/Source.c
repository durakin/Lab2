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
	printf("������� �������� %s\n", name);
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
				printf("������������ ��������. ����������, ��������� ���� %s.\n", name);
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
	printf("������� �������� %s\n", name);
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
				printf("������������ ��������. ����������, ��������� ���� %s.\n", name);
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
				printf("������������ �������� %s. ����������, ��������� ���� �������� %s.\n", name, name);
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
	//(*object).razmer = VDCelPol("������� �������");
	object->razmer = VDCelPol("������� �������");
	object->obj = (double*)malloc(object->razmer * sizeof(double));
	system("cls");
	printf("����� ���������� ������� �������� �������.\n");
	for (i = 0; i < object->razmer; i++)
	{
		object->obj[i] = VDCel("�������� �������");
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
	object->razmer = VDCelPol("������� �������");
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
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	objarray object;
	object.isFilled = false;
	object.razmer = -1;
	object.obj = NULL;
	object.minimal = 0;

	int k = -1, vih, n = 0;
	while (k != 5)
	{
		system("cls");
		printf("���� ������������:\n1. ������ �������� ������� �������.\n2. ��������� ������ ���������� �������.\n3. ������� ������ �� �����.\n4. �������� ����������� �������� ��������� ������� ������� �������������� ��� ���������, ����������� �� ������ ��������.\n5. �����.\n");
		k = VDCelPol("������ �������");
		if (k == 1)
		{
			system("cls");
			Customfill(&object);
			printf("���� ������� ��������.\n");
		}
		if (k == 2)
		{
			system("cls");
			RandomFill(&object);
			printf("������ ��� �������� ���������� ������� � ��������� �� -100 �� 100.\n");
		}
		if (k == 3)
		{
			system("cls");
			if (object.isFilled)
			{
				printf("�������� �������:\n");
				for (int i = 0; i < object.razmer; i++)
				{
					printf("%lf\n", object.obj[i]);
				}
			}
			else
			{
				printf("������ �� ��� ��������.\n");
			}
		}
		if (k == 4)
		{
			system("cls");
			if (object.isFilled && object.razmer>1)
			{
				obrabotka(&object);
				printf("������ ��� ���������.\n");
			}
			else
			{
				printf("������ �� ��� �������� ��� ������� �� ������ ��������.\n");
			}
		}
		if (k != 5)
		{
			getchar();
			getchar();
		}
	}
	printf("������ ��������� ���������.\n");
	free(object.obj);
	return 0;
}