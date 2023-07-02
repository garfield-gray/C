#include "iostream"
#include "string.h"
#include "vector"
#include "cmath"
#include "cstdlib"
#include "algorithm"


class Billet
{
public:
	Billet(std::string inname, int innumber): name(inname), number(innumber)
	{}
	Billet();

	static std::vector<Billet> cinema;

	static bool check (std::string name, int no)
	{
		if (no == 0)
		{
			for (int j = 0; j < cinema.size(); ++j)
			{
				if (cinema[j].returnname() == name)
				{                     
					return 1;
				}
			}
		}
		else
		{
			for (int j = 0; j < cinema.size(); ++j)
			{
				if (cinema[j].returnno() == no)
				{                     
					return 1;
				}
			}
		}
		return 0;
	}

	static bool cancel (std::string name, int no)
	{
		if (no == 0)
		{	
			for (int j = 0; j < cinema.size(); ++j)
			{
				if (cinema[j].returnname() == name)
				{      
					cinema.erase(cinema.begin()+j);               
					return 1;
				}
			}
		}
		else
		{
			for (int j = 0; j < cinema.size(); ++j)
			{
				if (cinema[j].returnno() == no)
				{
					cinema.erase(cinema.begin()+j);                  
					return 1;
				}
			}
		}
		return 0;
	}

	int returnno()
	{
		return number;
	}

	std::string returnname()
	{
		return name;
	}

private:
	std::string name;
	int number;
};

std::vector<Billet> Billet::cinema;

int Find_Number(std::string a, int n);

std::string Find_Name_from_bottom(std::string a, int n);


int main()
{
	
	int n;
	std::cin>>n;
	std::string *cmd = new std::string[n];
	std::cin.ignore();
	for (int i = 0; i < n; ++i)
	{
		std::getline(std::cin, cmd[i],'\n');
	}

	int no = 0;
	std::string name;
	char x;
	int l;
	
	for (int i = 0; i < n; ++i)
	{
		x = cmd[i][1];
		l = cmd[i].length();
		if ( x == 'e')//reserve  
		{
			bool q =0;
			bool p =0;
			bool u = 0;
			name = Find_Name_from_bottom(cmd[i],l);
			no = Find_Number(cmd[i], l);
			p =Billet::check("",no);
			if (p == 1)
			{
				std::cout<<"seat not available"<<std::endl;
			}
			q =Billet::check(Find_Name_from_bottom(cmd[i],l),0);
			if (q == 1 && p == 0)
			{
				u = Billet::cancel(name,0);
				Billet::cinema.push_back(Billet(name, no));
				std::cout<<"done"<<std::endl;
			}
			if (q ==0 && p==0)
			{
				Billet::cinema.push_back(Billet(name, no));
				std::cout<<"done"<<std::endl;
			}

		}
		else if(x == 'h')//check
		{
			bool q = 0;
			no = Find_Number(cmd[i], l);
			if (no == 0)
			{
				q =Billet::check(Find_Name_from_bottom(cmd[i],l),no);
			}
			else
			{
				q =Billet::check("",no);
			}

			if (q == 0)
			{
				std::cout<<"no"<<std::endl;
			}
			else
			{
				std::cout<<"yes"<<std::endl;
			}
		}
		else if(x == 'a')//cancel
		{
			bool q = 0;
			no = Find_Number(cmd[i], l);
			if (no == 0)
			{ 
				q = Billet::cancel(Find_Name_from_bottom(cmd[i],l),no);
			}
			else
			{
				q =Billet::cancel("",no);
			}

			if (q == 0)
			{
				std::cout<<"ticket not found"<<std::endl;
			}
			else
			{
				std::cout<<"done"<<std::endl;
			}
		}
	}
	for (int i = 0; i < Billet::cinema.size(); ++i)
	{
		std::cout<<Billet::cinema[i].returnno()<<" "<<Billet::cinema[i].returnname()<<std::endl;
	}
	
	return 0;
}

int Find_Number(std::string a, int n)
{
	int h = 0;
	int j = n-1;
	for (int i = 0; i < n ; ++i)
	{
		if (std::isdigit(a[i]))
		{
			j = i;
			break;
		}
	}
	while(std::isdigit(a[j]))
	{
		h *= 10;

		h += (a[j]-48);
	
		j++;
	}
	return h;
}


std::string Find_Name_from_bottom(std::string a, int n)
{
	int j;
	for (int i = n; i > 0 ; --i)
	{
		if (std::isalpha(a[i]))
		{
			j = i;
			break;
		}
	}
	int s = j;
	while(a[s] != 32) 
	{
		s--;
		if (s == 1)
			break;
	}
	return a.substr(s+1,j-s);
}