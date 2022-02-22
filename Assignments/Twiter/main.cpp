#include <bits/stdc++.h>
using namespace std;
bool dont_give_password_agian = true;
int counter = 1;

class Twitter
{
struct Activity
{
	vector <string> postting;
	vector <string> comment;

//	bool private_account;
	/*Activity()
	{
		private_account = false;
	}*/
};
int like;
string name;
vector <Activity> v;
vector <string> usernames;
vector <string> followers;
vector <string> following;
vector <string> posts;
public:

	void take_post(string p);
	int whats_myNumber(string n);
	void search();
	void take_comment();
	void take_like();
	void design(string n);
	void request_to_somone();
	//vector <Activity> twitter_users;
	int number_post() { return posts.size(); }
	void save_post();
	ifstream read;
	ofstream write;
	Twitter(string n)
	{
		name = n;
		read.open("userNames.text",ios::in);
		string N;
		while(getline(read,N))
		{
		//	for(int i = 0;i<N.size();i++)
			usernames.push_back(N);
			save_post();
		}
	}
		
};

class User
{
	string user_name;
	string password;
	
	public:
		static string changePassword(string p);
		void Set_userName(string n,string p);
		void Set_password(string p);
		string Get_userName() { return user_name; }
		string Get_password() { return password; }  
		User(string u, string p);
		static bool check_password(string p);
		static bool check_userName(string n);
		/*void take_post(string p);
		void take_comment(string c);
		void take_like();*/
		~User()
		{
		}
		
};

User::User(string u, string p)
{
	Set_userName(u,p);
	if(dont_give_password_agian)
	Set_password(p);
}

bool check_username_used(string n)
{
	ifstream in("userNames.text",ios::in);
	string str;
	while(in >> str)
	{
		if(n == str)
			return false;
	}
	return true;
}	
void User::Set_userName(string n,string p)
{
	bool cant_enter = true;
	while(cant_enter)
	{
	if(check_username_used(n))
		{
			user_name = n;
			cant_enter = false;
			ofstream out1("userNames.text",ios::app);
			out1 << user_name<<endl;
		}
	else
	{
		system("cls");
		cout<<"your username has been used plz enter again :";
		cin >> n;
		dont_give_password_agian = false;
		cout<<endl<<"enter again your password :";
		cin>>p;
		Set_password(p);
	}
	}
}
void User::Set_password(string p)
{
	
	if(p.size() > 6)
	{
		password = changePassword(p);
		ofstream out2("password.text",ios::app);
		out2 << password << endl;
	}
		else
		{
			while(p.size() < 6)
			{
				system("cls");
				cout<<"Your password size must more than 6 corctor"<<endl;
				cout<<"enter again your password :";
				cin>>p;
			}
			password = changePassword(p);
			ofstream out2("password.text",ios::app);
			out2 << password <<endl;
		}
}

string User::changePassword(string p)
{
	string str;
	for (int i = 0, j = p.size(); i < p.size() / 2 && j > p.size() / 2; i++,j--)
	{
		str.push_back(p[j]);
		str.push_back(p[i]);
	}
	return str;
}

bool User::check_userName(string n)
{
	ifstream input("userNames.text",ios::in);
	string t;
	counter = 1;
	while(input >> t)
	{
		if(n == t)
		return true;
		counter++;
	}
	return false;
	
}

bool User::check_password(string p)
{
	ifstream input("password.text",ios::in);
	string t;
	//int cnt = 1;
	while(input >> t)
	{
		if(p == t)
		return true;
		
	}
	return false;
}
void Twitter::take_post(string p)
{
	
	write.open("posts.text",ios::app); 
	
	write << name << endl <<"post"<<endl<< p << endl;
	 
	
}
int Twitter::whats_myNumber(string n)
{
	int cnt = 1;
	for(int i=0; i < usernames.size(); i++,cnt++)
		if(n == usernames[i])
			return cnt;
}

void Twitter::save_post()
{
	read.open("posts.text",ios::in);
	string s;
	for(int i = 0;getline(read,s) && s != "post" && s != "like" && s != "comment"; i++)
	{
		posts.push_back(s);
		v[i].postting.push_back(s);
	}
}
void Twitter::design(string n)
{
	char num;
	while(num != 4)
	{
		
		//system("cls");
		cout<<"1-profile    2-search    3-New post    4-Exit"<<endl;
		cin>>num;
		switch(num)
		{
			case '1':
				{
					system("cls");
					cout << n <<"\t\t\t\t1-Setting";
					save_post();
					for(int i = 0; i < number_post(); i++)
					{
						cout << posts[i] <<endl;
					}
					break;
				}
			case '2':
				{
					system("cls");
					int num;
					cout<<"1- search Users\t\t"<<"2- search Posts";
					cin>>num;
					if (num == 1)
					{
						string str;
						cout<<"Enter username : ";
						cin>>str;
						for(int i = 0; i < usernames.size(); i++)
						{
							if(str == usernames[i])
							{
								cout << str<<endl;
								bool o= true;
								for(int j = 0; j < following.size(); j++)
								{
									if(str == following[j])
									{
										o = false;
										cout << "1- follow ";
										int a;
										cin>>a;
										if(a == 1)
										{
											for(int k = 0; k < str.size(); k++)
											{
												following[following.size()].push_back(str[k]);	
												//followers[followers.size()].str.push_back(name);
											}
										
										}
									}
									if(o)
									{
										cout<<"1- unfllow";
										int a;
										cin>>a;
										if(a == 1)
										{
											for(int k=0;k<str.size();k++)
											{
												//following[following.size()].pop_back();
												//followers[followers.size()].str.pop_back();
											}
										}
									}
								}
							}
						}
					
					}
					else if(num == 2)
					{
						system("cls");
						string str;
						cout<<"enter your string :";
						getline(cin,str);
						string temp;
						read.open("posts.text");
						while(getline(read,temp))
						{
							if(str.find_first_of(str) != -1)
								cout << temp<<endl;
						}
						
					}
					break;
				}
			case '3':
			{
				system("cls");
				cout<< "write yor post\n";
				string s;
				getline(cin,s);
				take_post(s);
				break;
	
			}	
			case '4':
			{
				break;	
			}
			default:
				break;
		}
		//break;
	}

	
}
void Twitter::search()
{
	for(int i=0;i<usernames.size();i++)
	cout<<usernames[i]<<endl;
}
int main()
{
	char choice;

	while(choice != '3')
	{
		cout<<"\t\t\tWelcome to Twitter"<<endl;
		cout<<"1- sign up"<<endl;
		cout<<"2- log in"<<endl;
		cout<<"3- Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case '1':
				{
				system("cls");
				string name,pass,pass2;
				cout<<"Enter your Username :";
				cin>>name;
				cout<<"Enter your Password :";
				cin>>pass;
				cout<<"Enter your confirm password again :";
				cin>>pass2;
				while(pass != pass2)
				{
					system("cls");
					cout<<"!!The passwords are not the same!!"<<endl;
					cout<<"Enter your Password :";
					cin>>pass;
					cout<<"Enter your confirm password again :";
					cin>>pass2;
				}
				User u1(name,pass);
				Twitter t(name);
				t.design(name);
				
				break;
				}
				 
			case '2':
				{
				system("cls");
				string name,pass;
				cout<<"Enter your Username :";
				cin>>name;
				cout<<"Enter your Password :";
				cin>>pass;
				
				if(User::check_userName(name))
				{
					pass = User::changePassword(pass);
					if(User::check_password(pass))
					{
						Twitter t(name);
						t.search();
						t.design(name);
						
					}
					else
					{
						bool ok = false;
						system("cls");
						while(!ok)
						{
							system("cls");
							cout<<"!!your password isnt correct!!"<<endl<<"Enter it again :";
							cin>>pass; 
							pass = User::changePassword(pass);
							if(User::check_password(pass))
								ok = true;
						}
					}
					
				}
				else
				{
					bool ok = false;
					system("cls");
					while(!ok)
					{
						system("cls");
						cout<<"!!username not found!!"<<endl<<"Enter again your username : ";
						cin>>name;
						cout<<"Enter your password :";
						cin>>pass;
						User u1(name,pass);
					}
				}
				break;
				}
				
			case '3':
				system("cls");
				cout<<"press any key to exit";
				return 0;
				
			default:
				cout<<endl<<"!!plz enter correct number!!"<<endl;
		}
	}
	return 0;
}
