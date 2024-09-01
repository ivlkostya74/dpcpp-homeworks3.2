#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Observer;

class Observed
{
public:
	Observed& addObserver(Observer* observer);
	Observed& removeObserver(Observer* observer);
	void warning(const std::string& message) const;
	void error(const std::string& message) const;
	void fatalError(const std::string& message) const;
private:
	std::vector<Observer*> observers_;
};

class Observer
{
public:
	virtual ~Observer() {}
	virtual void onWarning(const std::string& message) = 0;
	virtual void onError(const std::string& message) = 0;
	virtual void onFatalError(const std::string& message) = 0;
};

class ObserverOnWarning : public Observer
{
public:
	void onWarning(const std::string& message) override;
	void onError(const std::string& message) override {}
	void onFatalError(const std::string& message) override {}
};

class ObserverOnError : public Observer
{
public:
	ObserverOnError(const std::string fileName);
	~ObserverOnError();
	void onWarning(const std::string& message) override {}
	void onError(const std::string& message) override;
	void onFatalError(const std::string& message) override {}
private:
	std::ofstream fout;
};

class ObserverOnFatalError : public Observer
{
public:
	ObserverOnFatalError(const std::string fileName);
	~ObserverOnFatalError();
	void onWarning(const std::string& message) override {}
	void onError(const std::string& message) override {}
	void onFatalError(const std::string& message) override;
private:
	std::ofstream fout;
};