#include <stdio.h>
#include <windows.h>

int VDCelPol(char name[100])
{
	int i, done = 0;
	char s[100];

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
			if (!(s[i] >= '0'  && s[i] <= '9'))
			{
				system("cls");
				printf("������������ ��������. ����������, ��������� ���� %s.\n", name);
				break;
			}
			i++;
		}
		if (s[i] <= 0) done++;
	}
	return (atoi(s));
}
float VDVesh(char name[100])
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
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int k = -1, vih, n = 0;
	while (k != 5)
	{
		printf("���� ������������ (������� ��������������� �����):\n1. ������ �������� ������� �������.\n2. ��������� ������ ���������� �������.\n3. ������� ������ �� �����.\n4. �������� ����������� �������� ��������� ������� ������� �������������� ��� ���������, ����������� �� ������ ��������.\n5. �����.");
		k = VDcel("������ �������");
		
	}

	getchar();
	getchar();
}