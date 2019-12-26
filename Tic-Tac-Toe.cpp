#include <iostream>
#include <string>
#include <sstream>


using namespace std;

class Player1
{
	private:
		string sign = "X";
		string name = "";
		bool winner = false;		
	public:
		Player1(string name)
		{
			this->name = name;	
		}
		void setSign(string array[][5],string num)
		{
			for(int i = 0 ;i < 3; i++)
			{
				for(int j = 0; j < 5 ;j++)
				{
					if(array[i][j]==num)
					{
						array[i][j]=sign;
					}
				}
			}	
		}
		void setWinner()
		{
			winner = true;
		}
		bool getWinner() const
		{
			return winner;
		}
		string getSign() const
		{
			return sign;
		}
		string getName() const
		{
			return name;
		}
};

class Player2
{
	private:
		string sign = "O";
		string name = "";
		bool winner = false;
	public:
		Player2(string name)
		{
			this->name = name;
		}
		void setSign(string array[][5],string num)
		{
			for(int i = 0 ;i < 3; i++)
			{
				for(int j = 0; j < 5 ;j++)
				{
					if(array[i][j]==num)
					{
						array[i][j]=sign;
					}
				}
			}	
		}
		void setWinner()
		{
			winner = true;
		}
		bool getWinner() const
		{
			return winner;
		}
		
		string getSign()
		{
			return sign;
		}
		string getName() const
		{
			return name;
		}
};
bool checkRules(string array[][5])
{
	//ROWS
	if(array[0][0]=="O" && array[0][2]=="O" && array[0][4]=="O" || 
	array[1][1]=="O" && array[1][2]=="O" && array[1][4]=="O" ||
	array[2][1]=="O" && array[2][2]=="O" && array[2][4]=="O")
	{
		return false;
	}
	if(array[0][0]=="X" && array[0][2]=="X" && array[0][4]=="X" || 
	array[1][0]=="X" && array[1][2]=="X" && array[1][4]=="X" ||
	array[2][0]=="X" && array[2][2]=="X" && array[2][4]=="X")
	{
		return false;
	}
	//Columns
	if(array[0][0]=="O" && array[1][0]=="O" && array[2][0]=="O" || 
	array[0][2]=="O" && array[1][2]=="O" && array[2][2]=="O" || 
	array[0][3]=="O" && array[1][3]=="O" && array[2][3]=="O")
	{
		return false;
	}
	if(array[0][0]=="X" && array[1][0]=="X" && array[2][0]=="X" || 
	array[0][2]=="X" && array[1][2]=="X" && array[2][2]=="X" || 
	array[0][3]=="X" && array[1][3]=="X" && array[2][3]=="X")
	{
		return false;
	}
	//diagonal 
	if(array[0][0]=="O" && array[1][2]=="O" && array[2][4]=="O" ||
	array[0][4]=="O" && array[1][2]=="O" && array[2][0]=="O")
	{
		return false;
	}
	if(array[0][0]=="X" && array[1][2]=="X" && array[2][4]=="X" ||
	array[0][4]=="X" && array[1][2]=="X" && array[2][0]=="X")
	{
		return false;
	}
	return true;
}

//void display()
//{
//	for(int i = 0 ;i < 3; i++)
//	{
//		for(int j = 0; j < 5 ;j++)
//		{
//			cout<<array[i][j];
//		}
//		if(i==2)
//		{
//			break;
//		}
//		cout<<endl;
//		cout<<"-----"<<endl;
//	}
//}


void setUp(string array[][5])
{	
	array[0][1] = "|";
	array[0][3] = "|";
	array[1][1] = "|";
	array[1][3] = "|";
	array[2][1] = "|";
	array[2][3] = "|";
	for(int i = 0 ;i < 3; i++)
	{
		for(int j = 0; j < 5 ;j++)
		{
			cout<<array[i][j];
		}
		if(i==2)
		{
			break;
		}
		cout<<endl;
		cout<<"-----"<<endl;
	}	
}
void clearBoard(string array[][5])
{
	int num = 1;
	int flag = 2;
	for(int i = 0 ;i < 3; i++)
	{
		for(int j = 0; j < 5 ;j++)
		{
			stringstream ss;
			ss<<num;
			string str = ss.str();
			
			num=num+1;
			if(flag==2)
			{
				num--;
				array[i][j] = str;
				flag = 0;
			}
			flag++;
		}
		flag=2;
		num++;
	}
}
int main()
{
	string array[3][5];
	string number;
	
	string name;
	cout<<"Player's 1 Name:";
	cin>>name;
	Player1 p1(name);
	
	cout<<"Player's 2 Name:";
	cin>>name;
	Player2 p2(name);
	
	
	clearBoard(array);
	setUp(array);
	cout<<endl;

//	while(true)
	for(int i = 0 ; i < 5 ;i++)
	{
		
		cout<<"--"<<p1.getName()<<" turn--"<<endl;
		cout<<"Enter Number: ";
		cin>>number;
		p1.setSign(array,number);
		setUp(array);
		if(!checkRules(array))
		{
			p1.setWinner();
			break;	
		}
		
		cout<<endl;
		cout<<"--"<<p2.getName()<<" turn--"<<endl;
		cout<<"Enter Number: ";
		cin>>number;
		p2.setSign(array, number);
		setUp(array);
		if(!checkRules(array))
		{
			p2.setWinner();
			break;	
		}
		cout<<endl;
	}
	cout<<endl;
	if(p1.getWinner())
	{
		cout<<p1.getName()<<" is the Winner!!!"<<endl;
	}
	else if(p2.getWinner())
	{
		cout<<p2.getName()<<" is the Winner!!!"<<endl;
	}

	
	

	
	return 0;
}
