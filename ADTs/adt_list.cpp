// adt_list.cpp

#include "Stack.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class List_stack : public Stack {
private:

	class Node
	{
		public:
			string value;
			Node* next;
	};

	Node* head = nullptr;

public:
	//default constructor makes an empty stack
	List_stack()   { }

	~List_stack()   { }
	
	
	bool is_empty() const
	{
		return head == nullptr;
	}

	int size() const
	{
		int result = 0;
		Node* p = head;

		while( p != nullptr )
		{
			result++;
			p = p->next;
		}

		return result;	
	}

    void push( const string& x )
    {
    	head = new Node{x, head};
    }

 
    void push(const vector<string>& v)
    {
    	for( int i = 0; i < v.size(); i++ )
    	{
    		head = new Node{ v[i], head};
    	}
    }


    void push_new( const string& s )
    {
    	bool check = false;

    	Node* p = head;
    	while( p != nullptr )
    	{
    		if( p->value == s )
    		{
    			check = true;
    			break;
    		}
    		p = p->next;
    	
    	}

    	if( check == false )
	    {
			head = new Node{ s, head };
		}
    }

    string pop()
    {
    	string result = head->value;

    	Node* p = head;
    	head = head->next;
    	delete p;

    	return result;
    }

    vector<string> pop( int n )
    {
    	int result = 0;
		Node* p = head;

		while( p != nullptr )
		{
			result++;
			p = p->next;
		}

    	vector<string> answer;
    	if( n <= 0 )
    	{
    		return answer;
    	}
    	else if( n < result )
    	{
    		for( int i = 0; i < n; i++ )
    		{
    			answer.push_back( head->value );
    			Node* P = head;
    			head = head->next;

    			delete P;
    		}
    	}
    	else
    	{
    		for( int i = 0; i < result; i++ )
    		{	
    			answer.push_back( head->value );
    			Node* P = head;
    			head = head->next;

    			delete P;
    		}
    	}
    	return answer;

    }

    string peek() const
    {
    	return head->value;
    }	


}; // class List_stack


void List_stack_Test()
{
	List_stack s;

	assert( s.is_empty() );
	assert( s.size() == 0);

	s.push("akin");
	assert( !s.is_empty() );
	assert( s.size() == 1);
	assert( s.peek() == "akin");


	vector<string> x = {"goku", "vegeta"};
	s.push(x);
	assert( s.size() == 3);
	assert( s.peek() == "vegeta");

	string y = "akin";
	s.push_new( y );
	assert( s.size() == 3);
	assert( s.peek() == "vegeta");

	string z = "adae";
	s.push_new(z);
	assert( s.size() == 4);
	assert( s.peek() == "adae");

	y = s.pop();
	assert( y == "adae");
	assert( s.size() == 3);


	vector<string> v = s.pop(1);
	assert( s.size() == 2);
	assert( v[0] == "vegeta");

	s.pop_all();
	assert( s.size() == 0);
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

    cout << "All List_stack tests passed\n";
}


int main()
{
	List_stack_Test();
	return 0;
} // main
