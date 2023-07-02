#include <iostream>
#include <vector>
#include <string.h>


class message
{
public:
	virtual std::string Return_content() = 0;

protected:
	std::string content;
};



class text: public message
{
public:
	text(std::string txt)
	{
		content = txt;
	}
	std::string Return_content()
	{
		return content;
	}
};

class photo: public message
{
public:
	photo(std::string url)
	{
		content = url;
	}
	std::string Return_content()
	{
		return content;
	}
};

class voice: public message
{
public:
	voice(std::string url)
	{
		content = url;
	}
	std::string Return_content()
	{
		return content;
	}
	
};

class sticker: public message
{
public:
	sticker(std::string ID)
	{
		content = ID;
	}
	std::string Return_content()
	{
		return content;
	}
	
};

class user
{
public:
	user(std::string inname): name(inname){}
	std::vector<message*> v;
	
	void add(message* m)
	{
		v.push_back(m);
	}
	void Delete_message(std::string m)
	{
		int n = v.size();
		for (int i = 0; i < n; ++i)
		{
			if (v[i]->Return_content() == m)
			{
				v.erase(v.begin() +i);
				--n;
			}
		}
	}
	void Replace_message(std::string m, message * ma)
	{
		int n = v.size();
		for (int i = 0; i < n; ++i)
		{
			if (v[i]->Return_content() == m)
			{
				v[i] = ma;
			}
		}
	}
	
	void Return_messages()
	{
		for (int i = 0; i < v.size(); ++i)
		{
			std::cout<<"Message#"<<i+1<<":"<<v[i]->Return_content()<<std::endl;
		}
	}
	
private:
	std::string name;
};


int main()
{
	user * a = new user("Abbas");
	user * am = new user("Amirhossein");
	user * s = new user("Shahrzad");
	user * r = new user("Rojin");
	
	text * t = new text("Hello world");
	photo * p = new photo("http://www.goog.gl/cUGbDk");
	voice * v = new voice("http://www.goog.gl/bUdvDg");
	sticker * st = new sticker("32483434");

	a->add(t);
	a->add(p);
	am->add(st);

	am->Delete_message("32483434");

	photo * alternative = new photo("http://www.goog.gl/cUGbDka");
	a->Replace_message("Hello world", alternative);

	a->Return_messages();

	return 0;
}