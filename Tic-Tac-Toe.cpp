#include <iostream>
#include <string>

using namespace std;

class Player1
{
	private:
		string sign = "X";
	public:
		string getSign()
		{
			return sign;
		}
};

class Player2
{
	private:
		string sign = "O";
	public:
		string getSign()
		{
			return sign;
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
	array[0][2]=="O" && array[1][2]=="O" && array[3][2]=="O" || 
	array[0][3]=="O" && array[1][3]=="O" && array[2][3]=="O")
	{
		return false;
	}
	if(array[0][0]=="X" && array[1][0]=="X" && array[2][0]=="X" || 
	array[0][2]=="X" && array[1][2]=="X" && array[3][2]=="X" || 
	array[0][3]=="X" && array[1][3]=="X" && array[2][3]=="X")
	{
		return false;
	}
}

void Board()
{
	cout<<" | | "<<endl;
	cout<<"-----"<<endl;
	cout<<" | | "<<endl;
	cout<<"-----"<<endl;
	cout<<" | | "<<endl;	
}


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
	for(int i = 0 ;i < 3; i++)
	{
		for(int j = 0; j < 5 ;j++)
		{
			array[i][j] = '0';
		}
	}
}
int main()
{
	string array[3][5];

//	string number;
//	cout<<"Enter Number: ";
//	cin>>number;
	
//	Board();
	clearBoard(array);
	setUp(array);
	
		
	
	return 0;
}
