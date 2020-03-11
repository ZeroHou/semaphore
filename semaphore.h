#pragma once
#include<mutex>
#include<condition_variable>
using namespace std;

class semaphore {
private:
	int count;
	mutex mtx;
	condition_variable con_var;
public:
	semaphore(int val = 0) :count(val) {}
	~semaphore() {}
	void wait() {
		unique_lock<mutex> lok(mtx);
		if (--count < 0)
			con_var.wait(lok);
	}
	void signal() {
		unique_lock<mutex> lok(mtx);
		if (count++ < 0)
			con_var.notify_one();
	}
};