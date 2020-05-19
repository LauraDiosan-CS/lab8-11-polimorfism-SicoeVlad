#pragma once
#include<stdexcept>
#include<string>
using namespace std;
class VectorException : public runtime_error {
private:
	string mesaj;
public:

	VectorException(string msg) :runtime_error(msg), mesaj(msg) {

	}
	string what() {
		return mesaj;

	}
};