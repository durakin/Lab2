#include <stdio.h>
#include <windows.h>
#include <malloc.h>

int *obj, razmer;
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
			if (!(s[i] >= '1'  && s[i] <= '9'))
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
void Customfill()
{
	free(obj);
	int i;
	razmer = VDCelPol("������� �������");
	obj = (int*)malloc(razmer * sizeof(double));
	system("cls");
	printf("����� ���������� ������� �������� �������.\n");
	for (i = 0; i < razmer; i++) obj[i] = VDCel("�������� �������");
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int k = -1, vih, n = 0;
	while (k != 5)
	{
		printf("���� ������������:\n1. ������ �������� ������� �������.\n2. ��������� ������ ���������� �������.\n3. ������� ������ �� �����.\n4. �������� ����������� �������� ��������� ������� ������� �������������� ��� ���������, ����������� �� ������ ��������.\n5. �����.\n");
		k = VDCelPol("������ �������");
		if (k == 1)
		{
			system("cls");
			/*printf("������� ���������� ��������� �������.\n");*/
			Customfill();
		}
		if (k == 3)
		{
			system("cls");
			printf("�������� �������:\n");
			for (int i = 0; i < razmer; i++)
				printf("%f ", obj[i]);
			system("pause");
		}
		
	}
	printf("������ ��������� ���������.\n");
	getchar();
	getchar();
	return 0;
}