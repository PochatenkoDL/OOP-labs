#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Функція для зчитування параметрів командного рядка
vector<string> getInputWords(int argc, char* argv[]) {
	vector<string> words;
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			words.push_back(string(argv[i]));
		}
	}
	else {
		cout << "Please enter words (type 'done' to finish):" << endl;
		string word;
		while (cin >> word && word != "done") {
			words.push_back(word);
		}
	}
	return words;
}

// Функція для виведення відсортованих слів
void printSortedWords(const vector<string>& words) {
	for (const string& word : words) {
		cout << word << " ";
	}
	cout << endl;
}

// Функція для підрахунку кількості слів та літер
void countWordsAndLetters(const vector<string>& words, int& wordCount, int& letterCount) {
	wordCount = words.size();
	letterCount = 0;
	for (const string& word : words) {
		letterCount += word.length();
	}
}

int main(int argc, char* argv[]) {
	// Вхідні дані - Параметри командного рядка або введення користувача
	vector<string> words = getInputWords(argc, argv);

	// Перший функціональний модуль
	sort(words.begin(), words.end());
	printSortedWords(words);

	// Другий функціональний модуль
	int wordCount, letterCount;
	countWordsAndLetters(words, wordCount, letterCount);

	// Виведення результатів у консоль
	cout << "Number of words: " << wordCount << endl;
	cout << "Number of letters: " << letterCount << endl;

	// Запис результатів у текстовий файл
	ofstream outFile("output.txt");
	outFile << "Number of words: " << wordCount << endl;
	outFile << "Number of letters: " << letterCount << endl;
	outFile.close();

	return 0;
}



