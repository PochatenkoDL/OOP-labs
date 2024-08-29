#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// ������� ��� ���������� ��������� ���������� �����
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

// ������� ��� ��������� ������������ ���
void printSortedWords(const vector<string>& words) {
	for (const string& word : words) {
		cout << word << " ";
	}
	cout << endl;
}

// ������� ��� ��������� ������� ��� �� ����
void countWordsAndLetters(const vector<string>& words, int& wordCount, int& letterCount) {
	wordCount = words.size();
	letterCount = 0;
	for (const string& word : words) {
		letterCount += word.length();
	}
}

int main(int argc, char* argv[]) {
	// ����� ��� - ��������� ���������� ����� ��� �������� �����������
	vector<string> words = getInputWords(argc, argv);

	// ������ �������������� ������
	sort(words.begin(), words.end());
	printSortedWords(words);

	// ������ �������������� ������
	int wordCount, letterCount;
	countWordsAndLetters(words, wordCount, letterCount);

	// ��������� ���������� � �������
	cout << "Number of words: " << wordCount << endl;
	cout << "Number of letters: " << letterCount << endl;

	// ����� ���������� � ��������� ����
	ofstream outFile("output.txt");
	outFile << "Number of words: " << wordCount << endl;
	outFile << "Number of letters: " << letterCount << endl;
	outFile.close();

	return 0;
}



