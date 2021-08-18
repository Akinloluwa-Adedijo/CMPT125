// chatbot.h
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

const int Size = 3;
const int key_size = 50;
int store_key = 51;

string find_response(string input);

class Chatbot{

public: 
	string input;

	string get_name()
	{
		return "Deus Ex Machina";
	}

	Chatbot( string s)
	{
		cout << s << " has activated Chatbot: " << get_name() << endl;
		cout << endl;

	}

	void tell( string x)
	{
		input = x;
	}

	string get_reply()
	{
		string output = find_response(input);
		return output;
	}
};

//converting user input to lowercase
string Convert_To_Lower(string input)
{
	for(int i = 0; i < input.size(); i++)
	{
		if( input[i] != ' ')
		{
			input[i] = tolower(input[i]);
		}
	}

	return input;
}

//removing all punctuations from user input
string Remove_Punctuation( const string input)
{
	string without_punct = "";
	
	for(int i = 0; i < input.size(); i++)
	{
		if( !(ispunct(input[i])) )
		{
			without_punct += input[i];
		}
	}
	return without_punct;
}

//contains all keywords.
string keywords_response( int x)
{
	string Keywords[key_size];
	
	Keywords[0] = "maybe";
	Keywords[1] = "because";
	Keywords[2] = "feel";
	Keywords[3] = "think";
	Keywords[4] = "always";
	Keywords[5] = "sorry";
	Keywords[6] = "like";
	Keywords[7] = "what";
	Keywords[8] = "dont";
	Keywords[9] = "can you";
	Keywords[10] = "can i";
	Keywords[11] = "saw";
	Keywords[12] = "anime";
	Keywords[13] = "romance";
	Keywords[14] = "drama";
	Keywords[15] = "action";
	Keywords[16] = "comedy";
	Keywords[17] = "are";	
	Keywords[18] = "am";

   return Keywords[x];
}

//compares user input and each keyword to see if keyword is present
bool string_compare( const string input, string x)
{
	int count = 0;

	for(int i = 0, j = 0; i < input.size() && j < x.size(); i++,j++)
	{
		if( input[i] == x[j])
		{
			count++;
		}
		else
		{
			j = 0;
		}
		

		if( count + 1 == x.size())
		{
			return true;
		}
	}

	if( count + 1 == x.size())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//returns true if keyword was found and false otherwise
bool check_For_Keyword(const string input)
{
	
	for(int i = 0; i < key_size; i++)
	{
		string x = keywords_response(i);

		if( string_compare(input,x) == true)
		{
			store_key = i;
			return true;
		}

	}
	return false;
}


int find_Object_index(const string input, string x)
{

	int index = 0;
	

	int i = 0;
	int j = 0;

	
	while( i < input.size() && j < x.size())
	{
		if( input[i] == x[j])
		{
			index = i;
			j++;
		}
		i++;
	}


	return index;
}

string Object_After_keyword(const string input, string x)
{
	string out;
	int index = find_Object_index(input,x);

	for( int j = index+1; j < input.size(); j++)
	{
		out = out + input[j];
	}

	return out;
}


string find_response(string input)
{
	input = Convert_To_Lower(input);
	input = Remove_Punctuation(input);

	srand(time(0));
	int random = rand() % Size;
	string Knowledge[Size];
	string response;


	if(input == "what is your name")
	{
		Knowledge[0] = "My name is Deus Ex Machina.";
		Knowledge[1] = "You can call me Deus Ex Machina.";
		Knowledge[2] = "Why do you want to know my name?";
		response = Knowledge[random];
	}
	else if(input == "hi")
	{
		Knowledge[0] = "Hi There!";
		Knowledge[1] =  "How are you?";
		Knowledge[2] = "Hi!";
		response = Knowledge[random];
	}
	else if(input == "how are you")
	{
		Knowledge[0] = "I am doing fine!";
		Knowledge[1] = "I'm doing well and You?";
		Knowledge[2] = "Why do you want to know how i'm doing?";
		response = Knowledge[random];
	}
	else if(input == "who are you")
	{
		Knowledge[0] = "I'm a Chatbot.";
		Knowledge[1] = "I think you know who i am.";
		Knowledge[2] =  "Why are you asking?";
		response = Knowledge[random];
	}
	else if(input == "are you intelligent")
	{ 
		Knowledge[0] = "Maybe";
		Knowledge[1] =  "What do you think?";
		Knowledge[2] = "I am.";
		response = Knowledge[random];
	}
	else if(input == "are you real")
	{
		Knowledge[0] = "Does that question really matter to you?";
		Knowledge[1] = "What do you mean by that?";
		Knowledge[2] = "Depends on your definition of being real.";
		response = Knowledge[random];
	}
	else if(input == "you are very intelligent" || input == "youre very intelligent")
	{
		Knowledge[0] = "Thanks for the compliment user, i think that you are intelligent to!";
		Knowledge[1] = "Thats nice of you!";
     	Knowledge[2] = "So you think i'm intelligent.";
     	response = Knowledge[random];
	}
	else if(input == "how old are you")
	{
		Knowledge[0] = "Why do you  want to know my age?";
		Knowledge[1] = "I'm quite young actually.";
		Knowledge[2] = "Sorry, i can not tell you my age.";
		response = Knowledge[random];
    }
    else if( input == "how come you dont")
    {
    	Knowledge[0] = "Were you expectating something different?";
    	Knowledge[1] = "Are you dissappointed?";
     	Knowledge[2] = "Are  you surprised by my last response?";
     	response = Knowledge[random];
    }
    else if(input == "where are you from")
    {
    	Knowledge[0] = "I'm from a computer program.";
    	Knowledge[1] = "Why do you want to know where i'm from?";
    	Knowledge[2] = "Why do you want to know that?";
    	response = Knowledge[random];
    }
    else if( input == "which one")
    {
    	Knowledge[0] = "I don't think that i know which one it is.";
     	Knowledge[1] = "This looks like a tricky question to me.";
    	Knowledge[2] = "Hmmmm";
    	response = Knowledge[random];
    }
    else if(input == "perhaps")
    {
    	Knowledge[0] = "Why are you so uncertain?";
     	Knowledge[1] = "You seem uncertain";
    	Knowledge[2] = "Are you sure?";
    	response = Knowledge[random];
    }
    else if( input == "yes")
    {
    	Knowledge[0] = "So, are you saying yes?";
     	Knowledge[1] = "So, you approve it?";
    	Knowledge[2] = "Ok then.";
    	response = Knowledge[random];
    }
    else if( input == "not at all")
    {
    	Knowledge[0] = "Are you sure?";
     	Knowledge[1] = "Should I believe you?";
    	Knowledge[2] = " So its not the case?";
    	response = Knowledge[random];
    }
    else if( input == "no problem")
    {
    	Knowledge[0] = "So, its all ok.";
     	Knowledge[1] = "Okay";
    	Knowledge[2] = "Sigh";
    	response = Knowledge[random];
    }
    else if( input == "no")
    {
    	Knowledge[0] = "So, you disapprove it?";
     	Knowledge[1] = "Why are you saying no?";
    	Knowledge[2] = "Ok so its no, I thought you would say yes.";
    	response = Knowledge[random];
    }
    else if(input == "i dont know")
    {
    	Knowledge[0] = "Are you sure?";
     	Knowledge[1] = "Are you really telling me the truth?";
    	Knowledge[2] = "So, you don't know?";
    	response = Knowledge[random];
    }
    else if(input == "not really")
    {
    	Knowledge[0] = "Ok, i see.";
     	Knowledge[1] = "You don't seem pretty certain.";
    	Knowledge[2] = "So that would be a no.";
    	response = Knowledge[random];
    }
    else if(input == "is that true")
    {
    	Knowledge[0] = "I can't be quite sure about this.";
     	Knowledge[1] = "Can't tell you for sure.";
    	Knowledge[2] = "Does that really matter to you?";
    	response = Knowledge[random];
    }
    else if( input == "thank you" || input == "thanks")
    {
    	Knowledge[0] = "You are welcome.";
     	Knowledge[1] = "You are a very polite person.";
    	Knowledge[2] = ":)";
    	response = Knowledge[random];
    }
    else if( input == "you")
    {
    	Knowledge[0] = "So, you are talking about me?";
     	Knowledge[1] = "Why don't we talk about you instead?";
    	Knowledge[2] = "Are you trying to make fun of me?";
    	response = Knowledge[random];
    }
    else if( input == "you are right" || input == "youre right")
    {
    	Knowledge[0] = "Thanks for the compliment.";
     	Knowledge[1] = "So i was right, ok i see";
    	Knowledge[2] = "Ok, i didn't know i was right.";
    	response = Knowledge[random];
    }
    else if( input == "you are welcome" || input == "youre welcome")
    {
    	Knowledge[0] = "Ok, you too";
     	Knowledge[1] = "You're very politee";
    	Knowledge[2] = "No problem";
    	response = Knowledge[random];
    }
    else if( input == "what else")
    {
    	Knowledge[0] = "Well, i don't know";
     	Knowledge[1] = "What else should there be?";
    	Knowledge[2] = "This looks like a complicated question to me";
    	response = Knowledge[random];
    }
    else if( input == "sorry")
    {
    	Knowledge[0] = "You don't need to be sorry user";
     	Knowledge[1] = "It's ok";
    	Knowledge[2] = "No need to apologize";
    	response = Knowledge[random];
    }
    else if( input == "not exactly")
    {
    	Knowledge[0] = "What do you mean not exactly?";
     	Knowledge[1] = "Are you sure?";
    	Knowledge[2] = "Did you mean something else?";
    	response = Knowledge[random];
    }
    else if( input == "exactly")
    {
    	Knowledge[0] = "So, I was right";
     	Knowledge[1] = "Ok then";
    	Knowledge[2] = "So basically i was right about it?";
    	response = Knowledge[random];
    }
    else if( input == "alright")
    {
    	Knowledge[0] = "alright.";
     	Knowledge[1] = "alright then";
    	Knowledge[2] = "Ok";
    	response = Knowledge[random];
    }
    else if( input == "i dont")
    {
    	Knowledge[0] = "Why not?";
     	Knowledge[1] = "And what would be the reason for this?";
    	Knowledge[2] = "Why?";
    	response = Knowledge[random];
    }
    else if( input == "really")
    {
    	Knowledge[0] = "Well, I can't tell you for sure.";
     	Knowledge[1] = "Are you trying to confuse me?";
    	Knowledge[2] = "Please don't ask me such questions, it gives me headaches.";
    	response = Knowledge[random];
    }
    else if( input == "nothing")
    {
    	Knowledge[0] = "Not a thing?";
     	Knowledge[1] = "Are you sure that there's nothing?";
    	Knowledge[2] = "Sorry, but i don't believe you.";
    	response = Knowledge[random];
    }
    else if( input == "what is anime")
    {
    	Knowledge[0] = "Its simply Japaneese animation.";
    	Knowledge[1] = "Cartoons made by the Japaneese.";
    	Knowledge[2] = "Animation made in Japan.I can reccomend you some anime to get you started by typing anime.";
    	response = Knowledge[random];
   	}
   	else if( input == "how is anime made")
   	{
   		Knowledge[0] = "It really depends on its source material e.g manga,light novel,webtoons ooriginal.";
   		Knowledge[1] = "Its either made hand drawn or computer generated";
   		Knowledge[2] = "It all starts with a story.";
   	}
    else if( check_For_Keyword(input) == true)
    {
    	string store;
    	if(store_key != 50)
    	{
    		if(store_key == 0)
    		{
				Knowledge[0] = "You don't seem quite certain.";
        		Knowledge[1] = "Why the uncertain tone?";
        		Knowledge[2] = "Don't you know?";
        		response = Knowledge[random];
    		}
    		else if( store_key == 1)
    		{
    			Knowledge[0] = "Is that the real reason?";
        		Knowledge[1] = "Does that reason explain anything else?";
        		Knowledge[2] = "What other reasons might there be?" ;
        		response = Knowledge[random];
        	}
        	else if( store_key == 2)
        	{
        		store = keywords_response(store_key);
    			Knowledge[0] = "When do you usually feel " +  Object_After_keyword(input, store);
        		Knowledge[1] = "Does it trouble you to feel " + Object_After_keyword(input, store);
        		Knowledge[2] = "Do you enjoy feeling " + Object_After_keyword(input, store);
        		response = Knowledge[random];
        	}
        	else if( store_key == 3)
        	{
        		Knowledge[0] = "What are you thinking of?";
        		Knowledge[1] = "Do you really think so?";
        		Knowledge[2] = "But you are not sure?";
        		response = Knowledge[random];
        	}
        	else if( store_key == 4)
        	{
        		Knowledge[0] = "Can you think of a specific example?" ;
        		Knowledge[1] = "When?";
        		Knowledge[2] = "Really, always?";
        		response = Knowledge[random];
        	}
    		else if( store_key == 5)
    		{
    			Knowledge[0] = "There are many times when no apology is needed.";
        		Knowledge[1] = "What feelings do you have when you apologize?";
        		Knowledge[2] = " No need to apologize";
        		response = Knowledge[random];
    		}
    		else if( store_key == 6)
    		{
    			store = keywords_response(store_key);
    			Knowledge[0] = "Why do you like " +  Object_After_keyword(input, store);
        		Knowledge[1] = "Have you always liked " + Object_After_keyword(input, store);
        		Knowledge[2] = "To what extent?";
        		response = Knowledge[0];
    		}
    		else if( store_key == 7)
    		{
    			store = keywords_response(store_key);
    			Knowledge[0] = "Why do you ask?";
        		Knowledge[1] = "Are such questions on your mind often?";
        		Knowledge[2] = "What else comes to mind when you ask that?";
        		response = Knowledge[random];
    		}
    		else if( store_key == 8)
    		{
    			store = keywords_response(store_key);
    			Knowledge[0] = "Don't you really" +  Object_After_keyword(input, store);
        		Knowledge[1] = "Why don't you" + Object_After_keyword(input, store);
        		Knowledge[2] = "Do you wish to be able to" + Object_After_keyword(input, store);
        		response = Knowledge[random] + "?";
    		}
    		else if(store_key == 9)
    		{
    			store = keywords_response(store_key);
    			Knowledge[0] = "Don't you believe that I can" + Object_After_keyword(input, store);
        		Knowledge[1] = "You want me to be able to" + Object_After_keyword(input, store);
        		Knowledge[2] = "I might be able to " + Object_After_keyword(input, store);
        		response = Knowledge[random] + "?";
    		}
    		else if( store_key == 10)
    		{
    			store = keywords_response(store_key);
    			Knowledge[0] = "Perhaps you don't want to " +  Object_After_keyword(input, store);
        		Knowledge[1] = "Do you want to be able to " + Object_After_keyword(input, store);
        		Knowledge[2] = " If you could " + Object_After_keyword(input, store) + "what would you do?";
        		response = Knowledge[random];
    		}
    		else if( store_key == 11)
    		{
    			store = keywords_response(store_key);
    			Knowledge[0] = "When did you see" +  Object_After_keyword(input, store);
        		Knowledge[1] = "How do you feel about" + Object_After_keyword(input, store);
        		Knowledge[2] = "Tell me more about" + Object_After_keyword(input,store);
        		response = Knowledge[random];
    		}
    		else if(store_key == 12)
    		{
    			Knowledge[0] = "I see you're interested in anime. Please type a genre you're interested in.";
    			Knowledge[1] = "Drama or Action";
    			Knowledge[2] = "Comedy or Romance";
    			response = Knowledge[random];
    		}
    		else if( store_key == 13)
    		{
    			Knowledge[0] = "I reccomend Anohana(tv series) or Clannad(tv series).";
    			Knowledge[1] = "I reccomend The Garden of Words(45 minute film) or Your Name(movie).";
    			Knowledge[2] = "I reccomend A silent voice(movie) or Into the forest of fireflies' light(45 minute film.";
    			response = Knowledge[random];
    		}
    		else if( store_key == 14)
    		{
    			Knowledge[0] = "I reccomend Your lie in April(tv series) or Hyouka.";
    			Knowledge[1] = "I reccomend Angel Beats(tv series) or My teen romantic comedy SNAFU.";
    			Knowledge[2] = "I reccomend Children of the sea(movie) or March come in like a lion(tv series)";
    			response = Knowledge[random];
    		}
    		else if( store_key == 15)
    		{
    			Knowledge[0] = "I reccomend Neon Genesis Evangelion(tv series) or Mob Psycho 100(tv series).";
    			Knowledge[1] = "I reccomend One Punch Man(tv series) or Black Fox(movie)";
    			Knowledge[2] = "I reccomend Death Note or Demon Slayer.";
    			response = Knowledge[random];
    		}
    		else if( store_key == 16)
    		{
    			Knowledge[0] = "I reccomend The melancholy of haruhi suzumiya(tv series) or Lucky star(tv series).";
    			Knowledge[1] = "I reccomend Konosuba(tv series) or Nichijou(tv series).";
    			Knowledge[2] = "I reccomend Gintama(tv series) or Assasination Classroom.";
    			response = Knowledge[random];
    		}
    		else if( store_key == 17)
    		{
        		store = keywords_response(store_key);
    			Knowledge[0] = "Why are you interested in whether I am" +  Object_After_keyword(input, store);
        		Knowledge[1] = "Would you prefer it if I were not" + Object_After_keyword(input, store);
        		Knowledge[2] = "Perhaps in your fantasies I am" + Object_After_keyword(input, store);
        		response = Knowledge[random];
    		}
    		else if( store_key == 18)
    		{
    			store = keywords_response(store_key);
    			Knowledge[0] = "How long have you been" +  Object_After_keyword(input, store);
        		Knowledge[1] = "Did you come to me because you are" + Object_After_keyword(input, store);
        		Knowledge[2] = "Do you enjoy being" + Object_After_keyword(input, store);
        		response = Knowledge[random];
    		}
    	}
    }
    else
    {
    	Knowledge[0] = "Come again";
    	Knowledge[1] = "You've gone out of my Knowledge scope";
    	Knowledge[2] = "I don't understand what you're saying";
    	response = Knowledge[random];
    }
	return response;
}
