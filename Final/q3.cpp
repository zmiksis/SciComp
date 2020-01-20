#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
#include "mpi.h"

using namespace std;

bool capture(vector<int> &King1, vector<int> &King2);
void move(vector<int> &King, int M);

int main(int argc, char* argv[]){

  if(argc < 3){
    cout << "Not enough values entered!";
    return 0;
  } else if(stoi(argv[1]) < 2){
    cout << "The board size is too small!";
    return 0;
  }

  int M = stoi(argv[1]);
  int trials = stoi(argv[2]);

  int *temp_moves;
  int rank, size;
  int start_trial, end_trial;
  const int MASTER = 0;
  MPI_Status status;
  MPI_Request request;
  double starttime, endtime;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int start_trials[size];
  int end_trials[size];
  int send_vals[2];

  starttime = MPI_Wtime();

  if(rank != MASTER){
    MPI_Recv(&send_vals,2,MPI_INT,MASTER,10,MPI_COMM_WORLD,&status);
    start_trial = send_vals[0];
    end_trial = send_vals[1];
  } else{
    for(int j = 0; j < size; j++){
      if(j != MASTER){
        start_trial = trials*j/size;
        end_trial = trials*(j+1)/size-1;
        send_vals[0] = start_trial;
        send_vals[1] = end_trial;
        start_trials[j] = start_trial;
        end_trials[j] = end_trial;
        MPI_Isend(&send_vals,2,MPI_INT,j,10,MPI_COMM_WORLD,&request);
        MPI_Wait(&request,&status);
      }
    }
    start_trial = trials*MASTER/size;
    end_trial = trials*(MASTER+1)/size-1;
    start_trials[MASTER] = start_trial;
    end_trials[MASTER] = end_trial;
  }

  long long int moves[trials];

  for(int i = start_trial; i <= end_trial; ++i){

    vector<int> King1{1,1};
    vector<int> King2{M,M};

    long long int num_moves = 0;
    bool capture_check = false;

    while(capture_check == false){
      move(King1,M);
      capture_check = capture(King1,King2);
      ++num_moves;
      move(King2,M);
      if(capture_check == false){
        capture_check = capture(King1,King2);
        ++num_moves;
      }
    }

    moves[i] = num_moves;

  }

  cout << "Trials " << start_trial << "-" << end_trial << " on rank " << rank << " complete!" << endl;

  if(rank != MASTER){
    temp_moves = new int[end_trial-start_trial+1];
    for(int i = start_trial; i <= end_trial; ++i){
      temp_moves[i-start_trial] = moves[i];
    }
    MPI_Send(temp_moves,end_trial-start_trial,MPI_INT,MASTER,20,MPI_COMM_WORLD);
  } else{
    for(int i = 0; i < size; ++i){
      if(i != MASTER){
        int num_trials = (end_trials[i]-start_trials[i]+1);
        temp_moves = new int[num_trials];
        MPI_Irecv(temp_moves,num_trials,MPI_INT,i,20,MPI_COMM_WORLD,&request);
        MPI_Wait(&request,&status);
        int temp_trial = 0;
        for(int trial = start_trials[i]; trial <= end_trials[i]; ++trial){
          moves[trial] = temp_moves[temp_trial];
          ++temp_trial;
        }
      }
    }
  }

  endtime = MPI_Wtime();

  double time = 0;
  double part_time;
  if(rank != MASTER){
    double time = endtime-starttime;
    MPI_Send(&time,1,MPI_DOUBLE,MASTER,30,MPI_COMM_WORLD);
  } else{
    for(int i = 0; i < size; ++i){
      if(i != MASTER){
        MPI_Recv(&part_time,1,MPI_DOUBLE,i,30,MPI_COMM_WORLD,&status);
        time += part_time;
      }
    }
    time += endtime-starttime;
  }

  if(rank == MASTER){
    double avg_moves = 0;
    for(int i = 0; i < trials; ++i){
      avg_moves += moves[i];
    }
    avg_moves /= trials;

    cout << "Average number of moves to capture on " << M << "x" << M << " board is " << avg_moves << endl;
    cout << "Total Computation Time: " << time << " seconds." << endl;
    cout << "Total Real Time: " << endtime-starttime << " seconds." << endl;
  }

  MPI_Finalize();

}

bool capture(vector<int> &King1, vector<int> &King2){

  bool capture = false;
  if(King1[0] == King2[0] && King1[1] == King2[1])
    capture = true;

  return capture;
}

void move(vector<int> &King, int M){

  random_device rd;
  int seed_value = rd();

  mt19937 generator(seed_value);
  uniform_int_distribution<int> distribution(1,8);
  vector<int> move_x{-1,0,1,1,1,0,-1,-1};
  vector<int> move_y{1,1,1,0,-1,-1,-1,0};

  int move_choice = distribution(generator);

  vector<int> temp_King;
  temp_King = King;

  temp_King[0] += move_x[move_choice-1];
  temp_King[1] += move_y[move_choice-1];

  if(temp_King[0] >= 1 && temp_King[0] <= M &&
     temp_King[1] >= 1 && temp_King[1] <= M){
       King[0] += move_x[move_choice-1];
       King[1] += move_y[move_choice-1];
  } else{
    move(King,M);
  }

  return;

}
