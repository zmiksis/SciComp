#include <iostream>
#include <random>
#include <functional>
#include <vector>
#include <string>



using namespace std;

bool is_valid(int x, int y, int M);


int main(int argc, char* argv[]){




	int N = stoi(argv[1]);
	int num_trials = stoi(argv[2]);

	random_device rd;
	mt19937 generator(rd());

	uniform_int_distribution<int> rook_dist(1, 4);
	uniform_int_distribution<int> knight_dist(1, 8);
	uniform_int_distribution<int> move_dist(1, N-1);

	auto draw_rook_direction = bind(rook_dist, ref(generator));
	auto draw_knight_direction = bind(knight_dist, ref(generator));
	auto draw_move_distance = bind(move_dist, ref(generator));


	if(N < 3){
		cout << "Board too small!" << endl;
	}


	int knight_wins = 0;
	int rook_wins = 0;

	int rook_x, rook_y, knight_x, knight_y;
	int new_x, new_y;

	int move_distance;
	int direction;

	string winner = "";


	long long int total_steps = 0;

	for(int i = 0; i < num_trials; i++){
		// Reset simulation
		rook_x = 0;
	 	rook_y = 0;

		knight_x = N-1;
		knight_y = N-1;	
		int steps = 0;

		while(true){
			new_x = -1;
			new_y = -1;
			while(!is_valid(new_x, new_y, N)){
				direction = draw_rook_direction();
				move_distance = draw_move_distance();
				switch(direction){
					case 1: 
						new_x = rook_x + move_distance;
						new_y = rook_y;
						break;
					case 2:
						new_x = rook_x;
						new_y = rook_y + move_distance;
						break;
					case 3:
						new_x = rook_x - move_distance;
						new_y = rook_y;
						break;
					case 4:
						new_x = rook_x;
						new_y = rook_y - move_distance;
						break;
				}
			}
			// cout << "Rook moves to " << new_x << ", " << new_y << endl;
			rook_x = new_x;
			rook_y = new_y;
			steps++;
			
			if(rook_x == knight_x && rook_y == knight_y){
				rook_wins++; winner = "Rook"; total_steps += steps;
				break;
			}

			new_x = -1;
			new_y = -1;
						
			while(!is_valid(new_x, new_y, N)){
				direction = draw_knight_direction();
				switch(direction){
					case 1: 
						new_x = knight_x + 2;
						new_y = knight_y + 1;
						break;
					case 2:
						new_x = knight_x + 2;
						new_y = knight_y - 1;
						break;
					case 3:
						new_x = knight_x - 2;
						new_y = knight_y + 1;
						break;
					case 4:
						new_x = knight_x - 2;
						new_y = knight_y - 1;
						break;
					case 5:
						new_x = knight_x + 1;
						new_y = knight_y + 2;
						break;
					case 6:
						new_x = knight_x + 1;
						new_y = knight_y - 2;
						break;
					case 7:
						new_x = knight_x - 1;
						new_y = knight_y + 2;
						break;
					case 8:
						new_x = knight_x - 1;
						new_y = knight_y - 2;
						break;
				}
			}

			knight_x = new_x;
			knight_y = new_y;
			steps++;
			// cout << "Knight moves to " << new_x << ", " << new_y << endl;

			if(knight_x == rook_x && knight_y == rook_y){
				knight_wins++; winner = "Knight";total_steps += steps;
				break;
			}
		}
		
		// cout << "Winner: " << winner << endl;
	}

	cout << "The rook won approximately: " << double(rook_wins)/num_trials << " probability of rook win" << endl;
	cout << "The knight won approximately: " << double(knight_wins)/num_trials << " probability of knight win" << endl;
	cout << "The average number of turns was: " << total_steps/double(num_trials) << endl;

	return 0;

}



bool is_valid(int x, int y, int M){
	return x >= 0 && x <= M-1 && y >= 0 && y <= M-1;
}
