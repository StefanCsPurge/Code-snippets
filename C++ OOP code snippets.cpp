#include <vector>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template <typename T>
// function or class


Adder& operator+(T elem)
    {
        this->s += elem;
        return *this;
    }

Adder& operator++()
    {
        this->s += addedStack.back();
        return *this;
    }

// copy constructor
Complex(const Complex& r) {
        this->real = r.real;
        this->imag = r.imag;
    }

bool operator==(const Complex& r) { return this->real == r.real && this->imag == r.imag; }

Complex& operator=(const Complex& r){
        this->real = r.real;
        this->imag = r.imag;
        return *this;
    }

void operator+=(T& elem)
    {
        elems.push_back(elem);
    }


friend ostream& operator<<(ostream& out, const Complex& r){
        out << r.real << '+' << r.imag << 'i';
        return out;
    }

friend istream& operator>>(istream& in, Issue& i) {
		string line, token;
		getline(in, line);
		if (line == "") return in;
		stringstream tokenStream(line);
		getline(tokenStream, token, ','); i.description = token;
		getline(tokenStream, token, ','); i.status = token;
		return in;
	}


/*  Method that prints all the elments from the Vector class
    input: out - out stream
    output: - ; prints all the elements using the output stream
    */
    void printAll(ostream& out) {
        copy(elems.begin(), elems.end(), ostream_iterator<T>(out, ", "));
	//copy(a.rbegin(), a.rend(), ostream_iterator<int>(out, " "));  //print reverse
    }

void print()
    {
        for_each(items.begin(), items.end(), [](MenuItem* it) {it->print(); });
	// for_each(issues.begin(), issues.end(), [&](const Issue& i) {fout << i; });
    }


// Pair
elems.push_back(pair<T1,T2>(el1, el2));

sort(elems.begin(), elems.end(), [](pair<T1, T2>& x1, pair<T1, T2>& x2) {return x1.second < x2.second; });


// Make class iterable
    typename vector<T>::iterator begin() { return elems.begin(); }
    typename vector<T>::iterator end() { return elems.end(); }


// Find in vector
	auto it = find(issues.begin(), issues.end(), elem);
	if (it == issues.end()) throw CustomException("There is no issue with this description!");
// and remove from vector: issues.erase(it); , or update: *it = newElem;


void IssueRepository::loadIssuesFromFile()
{
	ifstream fin(issuesFile);
	Issue i;
	while (fin >> i)
		this->issues.push_back(i);
	fin.close();
}


// FILTER
vector<Victim> Service::filterVictims(const string& orig, int age) const
{
	vector<Victim> newV, victims = getAllVictims();
	auto goodVictim = [&](const Victim& v) {return v.getAge() < age && (orig.size() && v.getPlaceOfOrigin() == orig || !orig.size()); };
	copy_if(victims.begin(), victims.end(), back_inserter(newV), goodVictim);
	return newV;
}


string Service::str_tolower(string s) {
	std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); } );
	return s;
}

// Check substring:
if( str_tolower(e.getName()).find(str_tolower(namePart)) != std::string::npos ) cout<<"found namePart in name!";


// Custom exception

//H
#include <exception>
#include <string>

class CustomException : public std::exception
{
private:
	std::string message;
public:
	CustomException(std::string msg = "");
	const char* what() const noexcept override;
};

//C
#include "customException.h"
using namespace std;
CustomException::CustomException(string _message) : message{"Issue error - " + _message } {}

const char* CustomException::what() const noexcept
{
	return message.c_str();
}

