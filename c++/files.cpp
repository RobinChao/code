#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string filename("file1");
	
	ofstream out_fs;
	out_fs.open(filename, ios::out | ios::binary);
	
	if (out_fs.is_open()) {
		out_fs << "Test 123..." << endl;
		out_fs << "Test is line 2" << endl;
		out_fs << "Test is line 3" << endl;
		out_fs << "Test is line 4" << endl;
		out_fs << "Test ABCDEF...";
		out_fs.close();
	}
	else {
		cout << "Unable to open file '" << filename << "'" << endl;
	}

	streampos size;
	char * mem_block;

	ifstream in_fs;
	in_fs.open(filename, ios::in | ios::binary | ios::ate);

	cout << "\nUsing block reader ..." << endl;
	if (in_fs.is_open()) {
		size = in_fs.tellg();
		mem_block = new char [size];

		in_fs.seekg (0, ios::beg);
		in_fs.read (mem_block, size);
		
		cout << "size = " << size << endl;
		cout << "mem_block = '" << mem_block << "'" << endl;

		in_fs.close();
	}
	else {
		cout << "Unable to open file '" << filename << "'" << endl;
	}

	// line reader 1
	cout << "\nUsing line reader 1..." << endl;
	in_fs.open(filename, ios::in | ios::binary);
	if (in_fs.is_open()) {
		string line;
		while(getline(in_fs, line)) {
			cout << "line read : 1 = '" << line << "'" << endl;
		}

		in_fs.close();
	}
	else {
		cout << "Unable to open file '" << filename << "'" << endl;
	}

	// line reader 2
	cout << "\nUsing line reader 2..." << endl;
	in_fs.open(filename, ios::in | ios::binary);
	if (in_fs.is_open()) {
		int buf_len = 256;
		char * buf = new char [256];
		
		while(in_fs.getline(buf, buf_len)) {
			cout << "line read : 2 = '" << buf << "'" << endl;
		}

		in_fs.close();
	}
	else {
		cout << "Unable to open file '" << filename << "'" << endl;
	}

	// using input operator
	cout << "\nUsing input operator ..." << endl;
	in_fs.open(filename, ios::in | ios::binary);
	if (in_fs.is_open()) {
		string s;
		
		while(in_fs >> s) {
			cout << "string read = '" << s << "'" << endl;
		}

		in_fs.close();
	}
	else {
		cout << "Unable to open file '" << filename << "'" << endl;
	}

	return 0;
}