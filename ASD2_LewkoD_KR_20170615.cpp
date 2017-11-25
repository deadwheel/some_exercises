
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>



const int SYSTEM = 256;
const int PRIME = 9556;

long expon(int k) {
	long s = 1;

	for (int i = 1; i <= k - 1; i++) {
		s = (SYSTEM*s) % PRIME;
	}
	return s;
}

unsigned long long hash(std::string text, long k) {
	unsigned long  long h = 0;
	long length = text.length() - 1;

	for (long i = 0; i<k; i++) {
		h = (SYSTEM * h + (unsigned char)text[i]) % PRIME;
	}
	return h;
}

bool check(std::string text, std::string pattern, int position) {
	for (unsigned int j = 0; j < pattern.length(); j++)
		if (pattern[j] != text[position + j])
			return false;
	return true;
}

void search(std::string pattern, std::string text) {

	if (pattern.length() > 0 && text.length() > 0) {

		long  patternLength = pattern.length();
		long  textLength = text.length();
		if (textLength >= patternLength) {

			unsigned long long oldHash = hash(text, patternLength);
			unsigned long long patternHash = hash(pattern, patternLength);
			long  textLength = text.length();
			int position = 0;
			long  d = expon(patternLength);
			for (long k = patternLength; k <= textLength; k++) {
				position = k - patternLength;
				if (patternHash == oldHash && check(text, pattern, position)) {
					std::cout << position << " ";
				}

				oldHash = (oldHash + PRIME - (d * (unsigned char)text[k - patternLength]) % PRIME) % PRIME;
				oldHash = (oldHash * SYSTEM + (unsigned char)text[k]) % PRIME;
			}
		}
	}
}


char* getTextFromFile(const char* name) {

	FILE * file;
	long str_length;
	char* str = nullptr;
	int offset = 0;
	if (fopen_s(&file, name, "rb") == 0) {
		fseek(file, offset, SEEK_END);
		str_length = ftell(file);
		fseek(file, offset, SEEK_SET);
		str = new char[str_length + 1];
		fread(str, str_length, 1, file);
		str[str_length] = '\0';
		str_length++;
	}

	return str;
}

int main()
{

	long n;

	std::string file;
	std::string pattern;
	std::string tmp;
	std::string text;

	std::cin >> n;
	std::cin.ignore();

	for (long i = 0; i < n; i++) {

		getline(std::cin, file);
		getline(std::cin, pattern);
		search(pattern, getTextFromFile(file.c_str()));
		std::cout << std::endl;
	}


	return 0;
}

