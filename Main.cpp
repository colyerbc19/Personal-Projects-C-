//Brent Colyer
//Tic tac toe 
//1/24/2022

#include <iostream>

using namespace std;

//Create an array to hold Xs and Os
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

//Tracks the current marker and player
char currentMarker;
string currentPlayer;
//creates variables for player names and markers
char player1Marker;
char player2Marker;
string player1Name;
string player2Name;

//function to print board to screen 
void drawBoard() {
	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;

	cout << "-----------\n";

	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;

	cout << "-----------\n";

	cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void placeMarker(int slot) {

	//variables for the row and column 
	int row = slot / 3;
	int col;
	//if the slot is 3,6 or 9 
	if (slot % 3 == 0) {
		row = row - 1;
		//must be the last column 
		col = 2;
	}

	else {
		//ex: 8 % 3 = 2, 2-1= 1, 8 is in column 1
		col = (slot % 3) - 1;
	}

	board[row][col] = currentMarker;
}

void swapPlayer() {

	if (currentPlayer == player1Name && currentMarker == player1Marker) {
		std::swap(currentPlayer, player2Name);
		std::swap(currentMarker, player2Marker);
	}
	else if (currentPlayer == player2Name && currentMarker == player2Marker); {
		std::swap(currentPlayer, player1Name);
		std::swap(currentMarker, player1Marker);
	}

}

bool winner() {

	for (int i = 0; i < 3; i++) {

		//check all rows for a winner 
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			swapPlayer();
			cout << currentPlayer << " Wins!!" << endl;;
			return true;
		}

		//check all cols for a winner 
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			swapPlayer();
			cout << currentPlayer << " Wins!!" << endl;
			return true;
		}

		//checks first diagnol for winner 
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
			swapPlayer();
			cout << currentPlayer << " Wins!!" << endl;
			return true;
	}
		//checks second diagnol for winner 
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
			swapPlayer();
			cout << currentPlayer << " Wins!!" << endl;
			return true;
		}
	}
	return false; 
}

void getPlayerInfo() {
	//ask player one for name 
	cout << "Who is player one?" << endl;
	cin >> player1Name;

	//ask player one for marker 
	cout << player1Name << " choose your marker : " << endl;
	cin >> player1Marker;

	//ask player two for name 
	cout << "Who is player two?" << endl;
	cin >> player2Name;

	//ask player two for marker 
	cout << player2Name << " choose your marker : " << endl;
	cin >> player2Marker;

	//player one goes first 
	currentMarker = player1Marker;
	currentPlayer = player1Name;
}

void game() {
	getPlayerInfo();
	drawBoard();
	swapPlayer();
	

	//the game can only last 9 turns 
	for (int i = 0; i < 9; ++i) {
		cout << "It's " << currentPlayer  << "'s turn." << " Enter your slot..." << endl;
		int slot;
		cin >> slot;

		if (slot < 1 || slot > 9) {
			cout << "Invaild slot location. Please try again." << endl;
			cin >> slot; 
			placeMarker(slot);
		}
		placeMarker(slot);

		swapPlayer();

		drawBoard();

		if (winner() == true) {
			break;
		}
	}
}


int main() { 
		game();

		return 0;
	}