// Crack09.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <time.h>

int main()
{
	printf("CrackMe 09 \n");
	HKEY hKey;
	DWORD res;
	DWORD TYPE;
	DWORD Count1;
	DWORD Count2;
	if (RegCreateKeyEx(HKEY_CURRENT_USER, L"SOFTWARE\\CRACK09", 0, NULL, REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS, NULL, &hKey, &res) != ERROR_SUCCESS) return 0;

	if (res == REG_CREATED_NEW_KEY)
	{
		srand((unsigned)time(NULL));
		Count1 = (unsigned)rand();
		Count2 = 0x100 ^ Count1;
		RegSetValueEx(hKey, L"Count1", 0, REG_DWORD, (CONST BYTE*) & Count1, 4);
		RegSetValueEx(hKey, L"Count2", 0, REG_DWORD, (CONST BYTE*) & Count2, 4);
		printf("Base count have saved! \n");
	}
	else
	{
		res = 4;
		RegQueryValueEx(hKey, L"Count1", 0, &TYPE, (LPBYTE)& Count1, &res);
		RegQueryValueEx(hKey, L"Count2", 0, &TYPE, (LPBYTE)& Count2, &res);

		Count2 = Count2 ^ Count1;
		Count2--;
		printf("Count  %x \n", Count2);
		if (!Count2) return 0;

		srand((unsigned)time(NULL));
		Count1 = (unsigned)rand();
		Count2 = Count2 ^ Count1;

		RegSetValueEx(hKey, L"Count1", 0, REG_DWORD, (CONST BYTE*) & Count1, 4);
		RegSetValueEx(hKey, L"Count2", 0, REG_DWORD, (CONST BYTE*) & Count2, 4);


	}
	RegCloseKey(hKey);
	std::system("pause");
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
