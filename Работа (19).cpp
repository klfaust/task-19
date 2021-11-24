#include <iostream>
#include <string> 
#include <cmath>

using namespace std;

int diff = 1;
int trycount = 1;
int help = 1;

struct questions
{
	string qst;
	string answ;
	string w_answ[3];
};

void helpconfig()
{
	int q = 0;
	while (q == 0)
	{
		system("cls");
		cout << "[] Количество подсказок\n\n";
		cout << "[1] 1\n[2] 3\n[3] 5\n[4] 666\n[5] Назад\n\n";
		cout << "Действие: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			help = 1;
			break;
		}
		case 2:
		{
			help = 3;
			break;
		}
		case 3:
		{
			help = 5;
			break;
		}
		case 4:
		{
			help = 666;
			break;
		}
		case 5:
		{
			q = 1;
			break;
		}
		default:
		{
			cout << "Такого действия не существует.\n";
			break;
		}
		break;
		}
	}
}

void tryconfig()
{
	int q = 0;
	while (q == 0)
	{
		system("cls");
		cout << "[] Количество попыток\n\n";
		cout << "[1] 1\n[2] 3\n[3] 5\n[4] 666\n[5] Назад\n\n";
		cout << "Действие: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			trycount = 1;
			break;
		}
		case 2:
		{
			trycount = 3;
			break;
		}
		case 3:
		{
			trycount = 5;
			break;
		}
		case 4:
		{
			trycount = 666;
			break;
		}
		case 5:
		{
			q = 1;
			break;
		}
		default:
		{
			cout << "Такого действия не существует.\n";
			break;
		}
		break;
		}
	}
}

void gmconfig()
{
	int q = 0;
	while (q == 0)
	{
		system("cls");

		cout << "[] Сложность\n\n";
		cout << "[1] Легко (5 вопросов)\n[2] Средне(10 вопросов)\n[3] Сложно(15 вопросов)\n[4] Назад\n\n";
		cout << "Действие: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			diff = 1;
			break;
		}
		case 2:
		{
			diff = 2;
			break;
		}
		case 3:
		{
			diff = 3;
			break;
		}
		case 4:
		{
			q = 1;
			break;
		}
		default:
		{
			cout << "Такого действия не существует.\n";
			break;
		}
		break;
		}
	}
}

void help4player()
{
	int q = 0;
	while (q == 0)
	{
		system("cls");

		cout << "[] Количество подсказок\n\n";
		cout << "[1] 1\n[2] 3\n[3] 5\n[4] 666\n[5] Назад\n\n";
		cout << "Действие: ";
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			help = 1;
			break;
		}
		case 2:
		{
			help = 3;
			break;
		}
		case 3:
		{
			help = 5;
			break;
		}
		case 4:
		{
			help = 666;
			break;
		}
		case 5:
		{
			q = 1;
			break;
		}
		default:
		{
			cout << "Такого действия не существует.\n";
			break;
		}
		break;
		}
	}
}

void gmstart(questions* quest)
{
	for (int i = 0; i < 15; i++)
	{
		quest[i].qst = "Вопрос "; quest[i].qst += std::to_string(i + 1);
		quest[i].answ = "Правильный";
		for (int j = 0; j < 3; j++) {
			quest[i].w_answ[j] = "Неправильный";
		}
	}

	switch (diff)
	{
	case 1:
	{
		int qty = 5;
		int wrong = 0;

		while (wrong == 0)
		{
			for (int i = 0; i < qty; i++)
			{
				int rnd = rand() % 14;
				system("cls");
				cout << "Осталось попыток: " << trycount - wrong << "\n";
				cout << "Осталось подсказок: " << help << "\n";
				cout << "Осталось вопросов: " << qty - i << "\n\n";
				cout << quest[rnd].qst << "\n\n";
				cout << "[1] " << quest[rnd].answ << "\n";
				cout << "[2] " << quest[rnd].w_answ[0] << "\n";
				cout << "[3] " << quest[rnd].w_answ[1] << "\n";
				cout << "[4] " << quest[rnd].w_answ[2] << "\n\n\n";
				cout << "Чтобы вызвать помощь, нажмите [5]\n";
				cout << "Введите ответ: ";

				int answ = 0;
				cin >> answ;

				if (answ == 5)
				{
					if (help != 0)
					{
						cout << "[1] 50/50\n[2] Правильный ответ\n\nВыбор: ";
						int chs; cin >> chs;
						switch (chs)
						{
						case 1:
						{
							cout << "[1] " << quest[rnd].answ << "\n";
							cout << "[2] " << quest[rnd].w_answ[0] << "\n";
							help--;
							break;
						}
						case 2:
						{
							cout << "Правильный ответ: " << "[1] " << quest[rnd].answ << "\n";
							help--;
							break;
						}
						default:
						{
							cout << "Неизвестная команда\n";
							break;
						}
						break;
						}
						cout << "Введите ответ: ";
						cin >> answ;
					}
					else
					{
						cout << "Подсказки кончились!\n";
						cout << "Введите ответ: ";
						cin >> answ;
					}
				}

				if (answ != 1)
				{
					cout << "Неправильный ответ!\n\n";
					wrong++;
				}

				if (wrong == trycount)
				{
					cout << "Вы проиграли!\n\nВведите любую цифру для выхода \n";
					int _; cin >> _;
					break;
				}

				if (i == qty - 1)
				{
					cout << "Вы победили!\n\nВведите любую цифру для выхода \n";
					int _; cin >> _;
					break;
				}
			}
			break;
		}

		break;
	}

	case 2:
	{
		int qty = 10;
		int wrong = 0;

		while (wrong == 0)
		{
			for (int i = 0; i < qty; i++)
			{
				int rnd = rand() % 14;
				system("cls");
				cout << "Осталось попыток: " << trycount - wrong << "\n";
				cout << "Осталось подсказок: " << help << "\n";
				cout << "Осталось вопросов: " << qty - i << "\n\n";
				cout << quest[rnd].qst << "\n\n";
				cout << "[1] " << quest[rnd].answ << "\n";
				cout << "[2] " << quest[rnd].w_answ[0] << "\n";
				cout << "[3] " << quest[rnd].w_answ[1] << "\n";
				cout << "[4] " << quest[rnd].w_answ[2] << "\n\n\n";
				cout << "Чтобы вызвать помощь, нажмите [5]\n";
				cout << "Введите ответ: ";

				int answ = 0;
				cin >> answ;

				if (answ == 5)
				{
					if (help != 0)
					{
						cout << "[1] 50/50\n[2] Правильный ответ\n\nВыбор: ";
						int chs; cin >> chs;
						switch (chs)
						{
						case 1:
						{
							cout << "[1] " << quest[rnd].answ << "\n";
							cout << "[2] " << quest[rnd].w_answ[0] << "\n";
							help--;
							break;
						}
						case 2:
						{
							cout << "Правильный ответ: " << "[1] " << quest[rnd].answ << "\n";
							help--;
							break;
						}
						default:
						{
							cout << "Неизвестная команда\n";
							break;
						}
						break;
						}
						cout << "Введите ответ: ";
						cin >> answ;
					}
					else
					{
						cout << "Подсказки кончились!\n";
						cout << "Введите ответ: ";
						cin >> answ;
					}
				}

				if (answ != 1)
				{
					cout << "Неправильный ответ!\n\n";
					wrong++;
				}

				if (wrong == trycount)
				{
					cout << "Вы проиграли!\n\nВведите любую цифру для выхода \n";
					int _; cin >> _;
					break;
				}

				if (i == qty - 1)
				{
					cout << "Вы победили!\n\nВведите любую цифру для выхода \n";
					int _; cin >> _;
					break;
				}
			}
			break;
		}
	}
	case 3:
	{
		int qty = 15;
		int wrong = 0;

		while (wrong == 0)
		{
			for (int i = 0; i < qty; i++)
			{
				int rnd = rand() % 14;
				system("cls");
				cout << "Осталось попыток: " << trycount - wrong << "\n";
				cout << "Осталось подсказок: " << help << "\n";
				cout << "Осталось вопросов: " << qty - i << "\n\n";
				cout << quest[rnd].qst << "\n\n";
				cout << "[1] " << quest[rnd].answ << "\n";
				cout << "[2] " << quest[rnd].w_answ[0] << "\n";
				cout << "[3] " << quest[rnd].w_answ[1] << "\n";
				cout << "[4] " << quest[rnd].w_answ[2] << "\n\n\n";
				cout << "Чтобы вызвать помощь, нажмите [5]\n";
				cout << "Введите ответ: ";

				int answ = 0;
				cin >> answ;

				if (answ == 5)
				{
					if (help != 0)
					{
						cout << "[1] 50/50\n[2] Правильный ответ\n\nВыбор: ";
						int chs; cin >> chs;
						switch (chs)
						{
						case 1:
						{
							cout << "[1] " << quest[rnd].answ << "\n";
							cout << "[2] " << quest[rnd].w_answ[0] << "\n";
							help--;
							break;
						}
						case 2:
						{
							cout << "Правильный ответ: " << "[1] " << quest[rnd].answ << "\n";
							help--;
							break;
						}
						default:
						{
							cout << "Неизвестная команда\n";
							break;
						}
						break;
						}
						cout << "Введите ответ: ";
						cin >> answ;
					}
					else
					{
						cout << "Подсказки кончились!\n";
						cout << "Введите ответ: ";
						cin >> answ;
					}
				}

				if (answ != 1)
				{
					cout << "Неправильный ответ!\n\n";
					wrong++;
				}

				if (wrong == trycount)
				{
					cout << "Вы проиграли!\n\nВведите любую цифру для выхода \n";
					int _; cin >> _;
					break;
				}

				if (i == qty - 1)
				{
					cout << "Вы победили!\n\nВведите любую цифру для выхода \n";
					int _; cin >> _;
					break;
				}
			}
			break;
		}
	}
	}
}

int main()
{
	system("color 02");
	setlocale(0, "");
	srand(time(NULL));
	questions* quest = new questions[15];
	int status = 0;
	while (status == 0)
	{
		system("cls");

		cout << "[] Викторина\n\n";
		cout << "[1] Начать игру\n[2] Сложность\n[3] Количество попыток\n[4] Количество подсказок\n[5] Выход\n\n";
		cout << "Действие: ";

		int choice = 0;
		cin >> choice;


		switch (choice)
		{
		case 1:
		{
			gmstart(quest);
			break;
		}
		case 2:
		{
			gmconfig();
			break;
		}
		case 3:
		{
			tryconfig();
			break;
		}
		case 4:
		{
			helpconfig();
			break;
		}
		case 5:
		{
			cout << "Ждем Вас снова\n";
			status = 1;
			break;
		}
		default:
		{
			cout << "Такого действия не существует.\n";
			break;
		}
		break;
		}
	}


	int _;
	cin >> _;
	return 0;
}
