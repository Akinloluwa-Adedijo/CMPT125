// adt_vec.cpp

#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Vec_stack : public Stack {

private:
	vector<string> myVector;

public:

	//default constructor to make an empty stack
	Vec_stack()   { }

	~Vec_stack()  { }

	bool is_empty() const
	{
		
		return myVector.size() == 0;
	}

	int size() const
	{

		return myVector.size();
	}

	void push( const string& x)
	{

		myVector.push_back(x);
	}

	void push( const vector<string>& v)
	{
		for(int i = 0; i < v.size(); i++)
		{
			myVector.push_back(v[i]);
		}
	}

	void push_new( const string& s )
	{
		bool check = false;
		for( int i = 0; i < myVector.size(); i++)
		{
			if(myVector[i] == s)
			{
				check = true;
				break;
			}
		}

		if( check != true )
		{
			myVector.push_back(s);
		}
	}


	string pop()
	{
		string result = myVector.back();
		myVector.pop_back();

		return result;
	}

	vector<string> pop(int n)
	{
		vector<string> result;
		int check = 0;

		if( n <= 0)
		{
			return result;
		}
		else if( n <  myVector.size() )
		{
			for( int i = myVector.size() - 1; i >= 0; i--)
			{
				result.push_back( myVector[i]);
				myVector.pop_back();
				check++;

				if(check == n)
				{
					break;
				}
			}
		}
		else
		{
			for( int i = myVector.size() - 1; i >= 0; i--)
			{
				result.push_back( myVector[i]);
				myVector.pop_back();
			}
		}

		return result;
	}


	string peek() const
	{
		return myVector.back();
	}



}; // class Vec_stack


void vecStack_test()
{
	Vec_stack s;

	assert( s.is_empty() );
	assert( s.size() == 0 );

	s.push("akin");
	assert( !s.is_empty() );
	assert(s.size() == 1);
	assert( s.peek() == "akin");
	

	vector<string> x = {"goku", "vegeta"};
	s.push(x);
	assert(s.size() == 3);
	assert( s.peek() == "vegeta");


	string y = "akin";
	s.push_new(y);
	assert(s.size() == 3);
	assert( s.peek() == "vegeta");


	y = "adae";
	s.push_new(y);
	assert( s.size() == 4);
	assert( s.peek() == "adae");
	

	y = s.pop();
	assert( y == "adae");
	assert( s.size() == 3 );
	

	vector<string> v = s.pop(1);
	assert(s.size() == 2);
	assert( v[0] == "vegeta");

	s.pop_all();
	assert(s.size() == 0);
	assert( s.is_empty() );

	s.push("akin");
	s.push("vegeta");
	s.push("goku");

	vector<string> all = s.pop(20);
	assert( all[0] == "goku");
	assert( all[1] == "vegeta");
	assert( all[2] == "akin");
	assert( s.size() == 0);
	assert( s.is_empty());

	vector<string> none = s.pop(0);
	vector<string> none1 = s.pop(-1);
	assert( none.size() == 0);
	assert( none1.size() == 0);

    cout << "All Vec_stack tests passed\n";
}

int main()
{
    vecStack_test();
    return 0;
} // main
