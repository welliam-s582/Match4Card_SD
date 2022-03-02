#include "SLL.h"
#include "Stack.h"

#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <cwchar>

void mainScreen() {
	cout << R"( .----------------.  .----------------.  .----------------.  .----------------.  .----------------. 
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
| | ____    ____ | || |      __      | || |  _________   | || |     ______   | || |  ____  ____  | |
| ||_   \  /   _|| || |     /  \     | || | |  _   _  |  | || |   .' ___  |  | || | |_   ||   _| | |
| |  |   \/   |  | || |    / /\ \    | || | |_/ | | \_|  | || |  / .'   \_|  | || |   | |__| |   | |
| |  | |\  /| |  | || |   / ____ \   | || |     | |      | || |  | |         | || |   |  __  |   | |
| | _| |_\/_| |_ | || | _/ /    \ \_ | || |    _| |_     | || |  \ `.___.'\  | || |  _| |  | |_  | |
| ||_____||_____|| || ||____|  |____|| || |   |_____|    | || |   `._____.'  | || | |____||____| | |
| |              | || |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------' )" << "\n\n";

	cout << R"( .----------------.  .----------------.  .----------------.  .----------------.  .----------------. 
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
| |              | || |              | || |   _    _     | || |              | || |              | |
| |              | || |              | || |  | |  | |    | || |              | || |              | |
| |    ______    | || |    ______    | || |  | |__| |_   | || |    ______    | || |    ______    | |
| |   |______|   | || |   |______|   | || |  |____   _|  | || |   |______|   | || |   |______|   | |
| |              | || |              | || |      _| |_   | || |              | || |              | |
| |              | || |              | || |     |_____|  | || |              | || |              | |
| |              | || |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------' )" << "\n\n";

	cout << R"( .----------------.  .----------------.  .----------------.  .----------------.  .----------------. 
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
| |     ______   | || |      __      | || |  _______     | || |  ________    | || |    _______   | |
| |   .' ___  |  | || |     /  \     | || | |_   __ \    | || | |_   ___ `.  | || |   /  ___  |  | |
| |  / .'   \_|  | || |    / /\ \    | || |   | |__) |   | || |   | |   `. \ | || |  |  (__ \_|  | |
| |  | |         | || |   / ____ \   | || |   |  __ /    | || |   | |    | | | || |   '.___`-.   | |
| |  \ `.___.'\  | || | _/ /    \ \_ | || |  _| |  \ \_  | || |  _| |___.' / | || |  |`\____) |  | |
| |   `._____.'  | || ||____|  |____|| || | |____| |___| | || | |________.'  | || |  |_______.'  | |
| |              | || |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------' )" << "\n\n";

	cout << "Welcome to Match 4 Cards!\n\n";
	cout << "CREATED BY:\n";
	cout << "- Charlton Gilbert (C14190037)\n";
	cout << "- Welliam Hanwe (C14190194)\n";
	cout << "- Calvert Tanudihardjo (C14190033)\n\n";
}

string getMaxCount(char cards[4]) {
	int cardsCount[4] = { 0 };

	for (int i = 0; i < 4; i++)
	{
		if (cards[i] == 'K') {
			cardsCount[0]++;
		}
		if (cards[i] == 'Q') {
			cardsCount[1]++;
		}
		if (cards[i] == 'J') {
			cardsCount[2]++;
		}
		if (cards[i] == 'A') {
			cardsCount[3]++;
		}
	}

	string cardWithMaxCount;
	if (cardsCount[0] == 1 && cardsCount[1] == 1 && cardsCount[2] == 1 && cardsCount[3] == 1) {
		srand(time(NULL));
		int randomIndex = rand() % 4;
		cardWithMaxCount = to_string(randomIndex) + 'X';
	}
	else
	{
		int maxValue;
		int maxIndex;
		for (int i = 0; i < 4; i++)
		{
			if (i == 0) {
				maxValue = cardsCount[0];
				maxIndex = i;
			}
			else if (cardsCount[i] > maxValue) {
				maxValue = cardsCount[i];
				maxIndex = i;
			}
		}

		//cek kalau ada 2 kartu yang jumlah terbanyaknya sama
		char maxIndexSecond = -1;
		for (int i = 0; i < 4; i++)
		{
			if (i != maxIndex) {
				if (cardsCount[i] == maxValue) {
					maxIndexSecond = i;
				}
			}
		}

		if (maxIndex == 0) {
			cardWithMaxCount += 'K';
		}
		if (maxIndex == 1) {
			cardWithMaxCount += 'Q';
		}
		if (maxIndex == 2) {
			cardWithMaxCount += 'J';
		}
		if (maxIndex == 3) {
			cardWithMaxCount += 'A';
		}

		if (maxIndexSecond != -1) {
			if (maxIndexSecond == 0) {
				cardWithMaxCount += 'K';
			}
			if (maxIndexSecond == 1) {
				cardWithMaxCount += 'Q';
			}
			if (maxIndexSecond == 2) {
				cardWithMaxCount += 'J';
			}
			if (maxIndexSecond == 3) {
				cardWithMaxCount += 'A';
			}
		}
		else {
			cardWithMaxCount += 'X';
		}
	}

	return cardWithMaxCount;
}

void random_pick(Link& a, Link& b, Link& c, cstack& d, Link& p2Out, Link& p3Out, Link& p4Out)
{
	char cardsP1[4];
	char cardsP2[4];
	char cardsP3[4];

	for (int i = 0; i < 4; i++)
	{
		cardsP1[i] = a.get_data_by_index(i).front();
		cardsP2[i] = b.get_data_by_index(i).front();
		cardsP3[i] = c.get_data_by_index(i).front();
	}
	string p1Choice = getMaxCount(cardsP1);
	string p2Choice = getMaxCount(cardsP2);
	string p3Choice = getMaxCount(cardsP3);

	if (p1Choice[1] != 'X') {
		srand(time(NULL));
		int randomIndex = rand() % 4;
		d.push(a.get_data_by_index(randomIndex));
		p2Out.input_data(a.get_data_by_index(randomIndex));
		a.delete_by_index(randomIndex);
	}
	else if (p1Choice[0] == '0' || p1Choice[0] == '1' || p1Choice[0] == '2' || p1Choice[0] == '3') {
		d.push(a.get_data_by_index(stoi(p1Choice)));
		p2Out.input_data(a.get_data_by_index(stoi(p1Choice)));
		a.delete_by_index(stoi(p1Choice));
	}
	else {
		for (int i = 0; i < 4; i++)
		{
			if (p1Choice[0] != a.get_data_by_index(i).front()) {
				d.push(a.get_data_by_index(i));
				p2Out.input_data(a.get_data_by_index(i));
				a.delete_by_index(i);
				break;
			}
		}
	}

	if (p2Choice[1] != 'X') {
		srand(time(NULL));
		int randomIndex = rand() % 4;
		d.push(b.get_data_by_index(randomIndex));
		p3Out.input_data(b.get_data_by_index(randomIndex));
		b.delete_by_index(randomIndex);
	}
	else if (p2Choice[0] == '0' || p2Choice[0] == '1' || p2Choice[0] == '2' || p2Choice[0] == '3') {
		d.push(b.get_data_by_index(stoi(p2Choice)));
		p3Out.input_data(b.get_data_by_index(stoi(p2Choice)));
		b.delete_by_index(stoi(p2Choice));
	}
	else {
		for (int i = 0; i < 4; i++)
		{
			if (p2Choice[0] != b.get_data_by_index(i).front()) {
				d.push(b.get_data_by_index(i));
				p3Out.input_data(b.get_data_by_index(i));
				b.delete_by_index(i);
				break;
			}
		}
	}

	if (p3Choice[1] != 'X') {
		srand(time(NULL));
		int randomIndex = rand() % 4;
		d.push(c.get_data_by_index(randomIndex));
		p4Out.input_data(c.get_data_by_index(randomIndex));
		c.delete_by_index(randomIndex);
	}
	else if (p3Choice[0] == '0' || p3Choice[0] == '1' || p3Choice[0] == '2' || p3Choice[0] == '3') {
		d.push(c.get_data_by_index(stoi(p3Choice)));
		p4Out.input_data(c.get_data_by_index(stoi(p3Choice)));
		c.delete_by_index(stoi(p3Choice));
	}
	else {
		for (int i = 0; i < 4; i++)
		{
			if (p3Choice[0] != c.get_data_by_index(i).front()) {
				d.push(c.get_data_by_index(i));
				p4Out.input_data(c.get_data_by_index(i));
				c.delete_by_index(i);
				break;
			}
		}
	}

	/*a.print();
	b.print();
	c.print();*/
}

bool check(Link p1, Link p2, Link p3, Link p4)
{
	if (p2.get_data_by_index(0).front() == p2.get_data_by_index(1).front() && p2.get_data_by_index(0).front() == p2.get_data_by_index(2).front() && p2.get_data_by_index(0).front() == p2.get_data_by_index(3).front())
	{
		cout << "\nPlayer 2 (BOT) WON!" << endl;
		cout << "YOU LOST!" << endl;
		cout << "BETTER LUCK NEXT TIME!" << endl;
		return true;
	}
	else if (p3.get_data_by_index(0).front() == p3.get_data_by_index(1).front() && p3.get_data_by_index(0).front() == p3.get_data_by_index(2).front() && p3.get_data_by_index(0).front() == p3.get_data_by_index(3).front())
	{
		cout << "\nPlayer 3 (BOT) WON!" << endl;
		cout << "YOU LOST!" << endl;
		cout << "BETTER LUCK NEXT TIME!" << endl;
		return true;
	}
	else if (p4.get_data_by_index(0).front() == p4.get_data_by_index(1).front() && p4.get_data_by_index(0).front() == p4.get_data_by_index(2).front() && p4.get_data_by_index(0).front() == p4.get_data_by_index(3).front())
	{
		cout << "\nPlayer 4 (BOT) WON!" << endl;
		cout << "YOU LOST!" << endl;
		cout << "BETTER LUCK NEXT TIME!" << endl;
		return true;
	}
	else if (p1.get_data_by_index(0).front() == p1.get_data_by_index(1).front() && p1.get_data_by_index(0).front() == p1.get_data_by_index(2).front() && p1.get_data_by_index(0).front() == p1.get_data_by_index(3).front())
	{
		cout << "\nYOU WON!\nCONGRATULATIONS!" << endl;
		return true;
	}
	else
	{
		return false;
	}

}

void shuffle(Link& p1, Link& p2, Link& p3, Link& p4, string cards[16])
{
	int loop = 0;

	while (loop != 16)
	{
		p1.input_data(cards[loop]);
		loop++;
		p2.input_data(cards[loop]);
		loop++;
		p3.input_data(cards[loop]);
		loop++;
		p4.input_data(cards[loop]);
		loop++;
	}
}

void arrayShuffle(string cards[16]) {
	int len = 16;
	srand(time(NULL));
	for (int i = 0; i < len; i++) {
		int r = rand() % (len - 1) + 1;

		string n = cards[i];
		cards[i] = cards[r];
		cards[r] = n;
	}
}

void setCMDSize() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 834, 770, TRUE); // 800 width, 100 height
}

void setCMDSizeStart() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 570, 850, TRUE); // 800 width, 100 height
}

void setFont() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 16;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Crete Round"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

}

void setFontStart() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 24;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Crete Round"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

}

int main()
{
	bool playAgain = true;
	while (playAgain) {
		setCMDSize();
		setFont();

		srand(time(NULL));
		cstack store;
		Link p1, p2, p3, p4;
		Link p1Out, p2Out, p3Out, p4Out;
		int chc;
		string cards[16] = { "KH","KD","KS","KC","QH","QD","QS","QC","JH","JD","JS","JC","AH","AD","AS","AC" };

		arrayShuffle(cards);
		shuffle(p1, p2, p3, p4, cards);

		mainScreen();

		system("PAUSE");

		setFontStart();
		setCMDSizeStart();
		do
		{
			system("CLS");
			cout << "DESCRIPTION: \n" << endl;

			cout << R"(.------..------..------..------.
|J.--. ||Q.--. ||K.--. ||A.--. |
| :(): || (\/) || :/\: || :/\: |
| ()() || :\/: || :\/: || (__) |
| '--'J|| '--'Q|| '--'K|| '--'A|
`------'`------'`------'`------')" << "\n\n";

			cout << "Name of Cards:\nK = KING\nQ = QUEEN\nJ = JACK\nA = ACE" << endl;
			cout << "\nType of Cards:\nH = HEART\nD = DIAMOND\nC = CLOVER\nS = SPADE" << endl;
			cout << endl;

			cout << "Your Cards (YOU)       : ";
			p1.print();
			cout << "Player 2's Cards (BOT) : ";
			p2.print();
			cout << "Player 3's Cards (BOT) : ";
			p3.print();
			cout << "Player 4's Cards (BOT) : ";
			p4.print();

			if (check(p1, p2, p3, p4) == true)
			{
				break;
			}

			cout << "\nSelect a Card to Give to Player 2: " << endl;
			for (int i = 0; i < 4; i++)
			{
				cout << i + 1 << ". " << p1.get_data_by_index(i) << endl;
			}
			cout << "\nYour Choice of Card: ";
			cin >> chc;

			if (chc >= 1 && chc <= 4)
			{
				store.push(p1.get_data_by_index(chc - 1));
				p1Out.input_data(p1.get_data_by_index(chc - 1));
				p1.delete_by_index(chc - 1);

				random_pick(p2, p3, p4, store, p2Out, p3Out, p4Out);

				system("CLS");

				cout << "Player 1 Got " << store.print_data() << " From Player 4" << endl;
				p1.input_data(store.pop());
				cout << "Player 4 Got " << store.print_data() << " From Player 3" << endl;
				p4.input_data(store.pop());
				cout << "Player 3 Got " << store.print_data() << " From Player 2" << endl;
				p3.input_data(store.pop());
				cout << "Player 2 Got " << store.print_data() << " From Player 1" << endl;
				p2.input_data(store.pop());

				cout << "\nYour Cards (YOU)       : ";
				p1.print();
				cout << "Player 2's Cards (BOT) : ";
				p2.print();
				cout << "Player 3's Cards (BOT) : ";
				p3.print();
				cout << "Player 4's Cards (BOT) : ";
				p4.print();

				cout << "\nCARD TAKING HISTORY";
				cout << "\nPlayer 1 (YOU) : ";
				p1Out.print();
				cout << "Player 2 (BOT) : ";
				p2Out.print();
				cout << "Player 3 (BOT) : ";
				p3Out.print();
				cout << "Player 4 (BOT) : ";
				p4Out.print();

				if (check(p1, p2, p3, p4) == true)
				{
					break;
				}

				cout << endl;
			}
			else
			{
				system("CLS");
				cout << "Please choose between 1-4 only!" << endl;
			}

			system("pause");
		} while (chc != 0);
		cout << "\nWanna play again? (y/n) ";
		char chcPlay; cin >> chcPlay;
		if (chcPlay == 'N' || chcPlay == 'n') {
			playAgain = false;
		}
		else if (chcPlay == 'Y' || chcPlay == 'y') {
			playAgain = true;
		}
	}
	system("CLS");
	cout << "Thank you for playing!\n";
	system("PAUSE");
}