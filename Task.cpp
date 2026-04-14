#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Размер массива (количество игр)
const int SIZE = 20;

// Типы игр
enum Genre { RPG, Strategy, Racing, Flight_sim, Shooter, Action, Adventure };

// Поддерживаемые платформы
struct Platforms
{
	bool PC;
	bool mobile;
	bool gamepad;
};

// Структура игры (название, студия-разработчик, стоимость подписки, объём аудитории игроков, поддерживаемые платформы, тип)
struct Game
{
	char name[40];
	char developer[40];
	double price;
	int players;
	Platforms platforms;
	Genre genre;
};
typedef Game arr[SIZE];

// Инициализация 20 игр
Game* init()
{
	Game* games = new Game[SIZE];
	games[0] = { "DOOM Eternal", "id Software", 9.99, 5, {1, 0, 0}, Shooter };
	games[1] = { "DOOM 2016", "id Software", 7.99, 4, {1, 0, 0}, Shooter };
	games[2] = { "Quake Champions", "id Software", 0.00, 1, {1, 0, 0}, Shooter };
	games[3] = { "CS:GO", "Valve", 0.99, 25, {1, 0, 0}, Shooter };
	games[4] = { "PUBG Mobile", "Tencent", 0.00, 100, {0, 1, 0}, Shooter };
	games[5] = { "Call of Duty Mobile", "Activision", 0.99, 80, {0, 1, 0}, Shooter };
	games[6] = { "Half-Life 2", "Valve", 2.99, 12, {1, 0, 0}, Shooter };
	games[7] = { "Wolfenstein", "MachineGames", 8.99, 3, {1, 0, 0}, Shooter };
	games[8] = { "Asphalt 9", "Gameloft", 0.99, 50, {0, 1, 0}, Racing };
	games[9] = { "Need for Speed", "EA", 11.99, 8, {1, 0, 1}, Racing };
	games[10] = { "Forza Horizon 5", "Playground", 12.99, 15, {1, 1, 1}, Racing };
	games[11] = { "Cyberpunk 2077", "CD Projekt", 14.99, 25, {1, 0, 0}, RPG };
	games[12] = { "The Witcher 3", "CD Projekt", 9.99, 20, {1, 0, 0}, RPG };
	games[13] = { "Genshin Impact", "miHoYo", 0.00, 60, {1, 1, 0}, RPG };
	games[14] = { "StarCraft II", "Blizzard", 0.00, 6, {1, 0, 0}, Strategy };
	games[15] = { "Warcraft III", "Blizzard", 7.99, 4, {1, 0, 0}, Strategy };
	games[16] = { "Microsoft Flight Sim", "Asobo", 15.99, 5, {1, 0, 0}, Flight_sim };
	games[17] = { "IL-2 Sturmovik", "1C", 19.99, 1, {1, 0, 0}, Flight_sim };
	games[18] = { "Minecraft", "Mojang", 7.99, 140, {1, 1, 0}, Adventure };
	games[19] = { "Portal 2", "Valve", 3.99, 8, {1, 0, 0}, Action };

	return games;
}

// Функция преобразования типа игры в строку
const char* getGenreName(Genre g)
{
	switch (g)
	{
	case RPG: return "RPG";
	case Strategy: return "Strategy";
	case Racing: return "Racing";
	case Flight_sim: return "Flight simulator";
	case Shooter: return "Shooter";
	case Action: return "Action";
	case Adventure: return "Adventure";
	default: return "Unknown";
	}
}

// Функция для обмена играми
void swall(Game& a, Game& b)
{
	Game temp = a;
	a = b;
	b = temp;
}

// Фильтр 1: Shooter от id Software
bool isIdSoftwareShooter(Game g)
{
	return g.genre == Shooter && strcmp(g.developer, "id Software") == 0;
}

// Фильтр 2: Мобильная гонка
bool isMobileRacing(Game g)
{
	return g.platforms.mobile && g.genre == Racing;
}

// Функция для фильтрации массива
int filterGames(Game src[], int srcSize, Game dst[], bool (*filter)(Game))
{
	int cnt = 0;
	for (int i = 0; i < srcSize; i++)
	{
		if (filter(src[i]))
		{
			dst[cnt++] = src[i];
		}
	}
	return cnt;
}

// Функция сортировки пузырьком 
void bubbleSort(Game arr[], int n, bool (*compare)(Game, Game))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (compare(arr[j], arr[j + 1]))
			{
				swall(arr[j], arr[j + 1]);
			}
		}
	}
}

// Функции сравнения для сортировки по убыванию объёма аудитории игроков
bool compareByPlayersDesc(Game a, Game b)
{
	return a.players < b.players;
}

// Функции сравнения для сортировки по возрастанию стоимости подписки
bool compareByPriceAsc(Game a, Game b)
{
	return a.price > b.price;
}

// Функция для вывода одной игры
void printGame(Game g)
{
	printf(" %-23s %-15s $%-5.2f     %d mil. \t PC:%d Mob:%d Pad:%d\t %s\n",
		g.name, g.developer, g.price, g.players, g.platforms.PC, g.platforms.mobile, g.platforms.gamepad,
		getGenreName(g.genre));
}

// Функция перегрузки print для массива
void printAll(Game games[], int n, const char* title)
{
	printf("\n =================== %s ===================\n", title);
	printf("\n");
	printf(" %-23s %-15s %-10s %-10s   %-20s    %-15s\n", "Name", "Developer", "Price", "Players", "Platforms", "Genre");
	printf(" ---------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < n; i++)
	{
		printGame(games[i]);
	}
}

// Функция для поиска игры по названию
void findGame(Game games[], int n, const char* searchName)
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(games[i].name, searchName) == 0)
		{
			printf("\n =================== FOUND: %s ===================\n", searchName);
			printf("\n");
			printf(" %-23s %-15s %-10s %-10s   %-20s    %-15s\n", "Name", "Developer", "Price", "Players", "Platforms", "Genre");
			printf(" ---------------------------------------------------------------------------------------------------------\n");
			printGame(games[i]);
			return;
		}
	}
	printf("\n Game \"%s\" not found!\n", searchName);
}

//  Функция для вывода 4 самых недорогих по стоимости подписки игр
void print4Cheapest(Game games[], int n)
{
	Game* copy = new Game[n];
	for (int i = 0; i < n; i++) copy[i] = games[i];

	bubbleSort(copy, n, compareByPriceAsc);

	printf("\n =================== 4 CHEAPEST GAMES ===================\n");
	printf("\n");
	for (int i = 0; i < 4 && i < n; i++)
	{
		printf(" %d. %s: Price = $%.2f\n", i + 1, copy[i].name, copy[i].price);
	}

	delete[] copy;
}

// Функция изменения игры
void modifyGame(Game& g, const char* newName, double newPrice, int newPlayers)
{
	strcpy(g.name, newName);
	g.price = newPrice;
	g.players = newPlayers;
	printf("\n Game modified successfully!\n");
}

// Оберточная функция для вывода отфильтрованных данных
void showFiltered(Game games[], int n, const char* filterName)
{
	printf("\n =================== FILTERED: %s (%d games) ===================\n", filterName, n);
	if (n == 0)
	{
		printf(" No games found!\n");
	}
	else
	{
		printf("\n");
		printf(" %-23s %-15s %-10s %-10s   %-20s    %-15s\n", "Name", "Developer", "Price", "Players", "Platforms", "Genre");
		printf(" ---------------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i < n; i++)
		{
			printGame(games[i]);
		}
	}
}

// Подпрограмма для записи названия игры и нового разработчика в текстовый файл
void writeDevelopersToTextFile(const char* filename)
{
	ofstream out(filename);
	if (!out.is_open())
	{
		cout << " Error: The file could not be created. " << filename << endl;
		return;
	}

	out << "DOOM_Eternal Bethesda" << endl;
	out << "DOOM_2016 Bethesda" << endl;
	out << "Quake_Champions Bethesda" << endl;
	out << "CS:GO ValveNew" << endl;
	out << "PUBG_Mobile Krafton" << endl;
	out << "Call_of_Duty_Mobile Activision" << endl;
	out << "Half-Life_2 ValveNew" << endl;
	out << "Wolfenstein Bethesda" << endl;
	out << "Asphalt_9 Gameloft" << endl;
	out << "Need_for_Speed_2 Criterion" << endl;
	out << "Forza_Horizon_5 PlaygroundGames" << endl;
	out << "Cyberpunk_2077 CDPRed" << endl;
	out << "The_Witcher_3 CDPRed" << endl;
	out << "Genshin_Impact HoYoverse" << endl;
	out << "StarCraft_II Blizzard" << endl;
	out << "Warcraft_III Blizzard" << endl;
	out << "Microsoft_Flight_Sim AsoboStudio" << endl;
	out << "IL-2_Sturmovik 1CGS" << endl;
	out << "Minecraft MojangStudios" << endl;
	out << "Portal_2 ValveNew" << endl;

	out.close();
	cout << " The text file has been created: " << filename << "." << endl;
}

// Подпрограмма для чтения данных из текстового файла и обновления структуры
void readAndUpdateFromTextFile(Game games[], int n, const char* filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << " Error: Could not find the " << filename << " file." << endl;
		return;
	}

	char name[40];
	char developer[40];
	int found = 0;

	while (fin >> name >> developer)
	{
		for (int i = 0; i < strlen(name); i++)
		{
			if (name[i] == '_') name[i] = ' ';
		}

		for (int i = 0; i < n; i++)
		{
			if (strcmp(games[i].name, name) == 0)
			{
				strcpy(games[i].developer, developer);
				found++;
				break;
			}
		}
	}
	fin.close();
	cout << " Updated " << found << " developers from the " << filename << " file." << endl;
}

// Запись всех игр в бинарный файл
void saveGamesToBinary(const char* filename, Game games[], int n)
{
	ofstream out(filename, ios::binary | ios::out);
	if (!out)
	{
		cout << " Error writing to a binary file." << endl;
		return;
	}
	out.write((char*)games, sizeof(Game) * n);
	out.close();
	cout << " The data is saved to a binary file: " << filename << "." << endl;
}

// Чтение всех игр из бинарного файла
void readGamesFromBinary(const char* filename, Game games[], int n)
{
	ifstream in(filename, ios::binary | ios::in);
	if (!in)
	{
		cout << " Error reading from a binary file." << endl;
		return;
	}
	in.read((char*)games, sizeof(Game) * n);
	in.close();
	cout << " The data is downloaded from a binary file: " << filename << "." << endl;
}


// Основная программа
int main()
{
	Game* games = init();

	// Вывод всех игр
	printAll(games, SIZE, "ALL GAMES");
	
	// Фильтрация Shooter от id Software
	Game idGames[SIZE];
	int idCount = filterGames(games, SIZE, idGames, isIdSoftwareShooter);
	printAll(idGames, idCount, "ID SOFTWARE SHOOTERS");

	// Сортировка пузырьком по возрастанию стоимости подписки
	bubbleSort(idGames, idCount, compareByPlayersDesc);
	printAll(idGames, idCount, "SORTED BY PLAYERS (descending)");

	// Вывод всех данных по конкретной игре
	findGame(games, SIZE, "Genshin Impact");

	findGame(games, SIZE, "Football");

	// Вывод 4 самых недорогих по стоимости подписки игр
	print4Cheapest(games, SIZE);

	// Изменение игры
	for (int i = 0; i < SIZE; i++)
	{
		if (strcmp(games[i].name, "Need for Speed") == 0)
		{
			modifyGame(games[i], "Need for Speed 2", 12.89, 9);
			break;
		}
	}

	// Вывод измененной игры
	findGame(games, SIZE, "Need for Speed 2");

	// Вывод через обёрточную функцию мобильных гонок
	Game mobileRacing[SIZE];
	int mobileCount = filterGames(games, SIZE, mobileRacing, isMobileRacing);
	showFiltered(mobileRacing, mobileCount, "MOBILE RACING GAMES");

	// Работа с текстовым файлом
	cout << "\n =================== WORKING WITH A TEXT FILE ===================" << endl;
	cout << endl;

	// Запись в текстовый файл
	writeDevelopersToTextFile("developers.txt");

	// Чтение из текстового файла и обновление
	readAndUpdateFromTextFile(games, SIZE, "developers.txt");

	// Показываем обновлённые данные
	printAll(games, SIZE, "UPDATED FROM TEXT FILE");

	// Работа с бинарным файлом
	cout << "\n =================== WORKING WITH A BINARY FILE ===================" << endl;
	cout << endl;

	// Записываем данные в бинарный файл
	saveGamesToBinary("games.bin", games, SIZE);

	// Создаём новый массив для загрузки
	Game* readGames = new Game[SIZE];

	// Читаем данные из бинарного файла
	readGamesFromBinary("games.bin", readGames, SIZE);

	// Проверка на корректность данных
	printAll(readGames, SIZE, "READ FROM BINARY FILE");
	
	delete[] games;
	return 0;
}