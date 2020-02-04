#include <iostream>

using namespace std;
int cells[1000000], cell = 0, loop, static_cell, past;

bool eightbit = false;

char inchar, slowAdd;

string command;
//;-prints int at cell |--------------------------command no. 1
//.-print char at cell |--------------------------command no. 2
//:-couts a new line |----------------------------command no. 3
//_-inputs an int |-------------------------------command no. 4
//*-changes beween 32 and 8 bit cells |-----------command no. 5
//+ ups the cell value by one |-------------------command no. 6
//- brings down the cell value by one |-----------command no. 7
//[-loop start |----------------------------------command no. 8
//]-loop end |------------------------------------command no. 9
//,-inputs ASCII value of char |------------------command no. 10
///-nullify cell |--------------------------------command no. 11
//&-bind current and last cell |------------------command no. 12
//'-prints cell position |------------------------command no. 13
//"-prints the whole array up to the current cell|command no. 15
//<-Moves cell pointer by one |-------------------command no. 16
//%-assigns current cell value to the static cell|command no. 17
//#-assigns static cell value to the current cell|command no. 18
//~-slow & mode, & is slower |--------------------command no. 19
//{-statement loop start, if end step cell val is
//the same as the start loop step cell, the loop
//terminates |------------------------------------command no. 20
//}-statement loop end, if the current cell val
//on this tep is the same as the start val, the
//loop terminates |-------------------------------command no. 21
//See official PDF documentation for more info.

int main(){
	cin>>command;
	for(int i = 0; i<command.size(); i++){
		if(command[i] == '~'){
			if(slowAdd){
				slowAdd = false;
			}
			else{
				slowAdd = true;
			}
		}
		if(command[i] == ';'){
			cout<<cells[cell];
		}
		if(command[i] == '.'){
			char outchar;
			outchar = cells[cell];
			cout<<outchar;
		}
		if(command[i] == ':'){
			cout<<endl;
		}
		if(command[i] == '_'){
			cin>>cells[cell];
		}
		if(command[i]=='*'){
			if(eightbit){
				eightbit = false;
			}
			else{
				eightbit = true;
			}
		}
		if(command[i] == '+'){
			cells[cell]++;
			if(eightbit && cells[cell]>255){
				cells[cell] = 0;
			}
		}
		if(command[i] == '-'){
			cells[cell]--;
			if(eightbit && cells[cell]<0){
				cells[cell] = 255;
			}
		}
		if(command[i] == '['){
			loop = i;
		}
		if(command[i] == ']'){
			if(cells[cell] > 0){
				i = loop;
			}
			
		}
		if(command[i] == ','){
			cin>>inchar;
			cells[cell] = inchar;
		}
		if(command[i] == '/'){
			cells[cell] = 0;
		}
		if(command[i] == '&'){
			if(slowAdd){
				past = cells[cell-1];
				while(past>0){
					past--;
					cells[cell]++;
				}
			}
			else{
				cells[cell] = cells[cell-1] + cells[cell];
			}
		}
		if(command[i] == '.'){
			cout<<cell;
		}
		if(command[i] == '"'){
			for(int j = 0; j<=cell; j++){
				cout<<cells[j]<<" ";
			}
		}
		if(command[i] == '>'){
			cell++;
		}
		if(command[i] == '<'){
			cell--;
		}
		if(command[i] == '%'){
			static_cell = cells[cell];
		}
		if(command[i] == '#'){
			cells[cell] = static_cell;
		}
	}
}