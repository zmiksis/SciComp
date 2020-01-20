for (long long int i=0; i < trials; i++){
    vector<int> location(2);
    bool finished = false;
    int moves = 0;
    while (!finished){
        vector<vector<int>> options;
        options = {{2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}}; // The 8 moves

        bool validmove = false;
        while(!validmove){
            int opt = select();

            // Temporary holding for possible location, needs to be validated.
            PSEUDOCODE: add current location coordinates to new location direction

            if ((x >= 0) && (x < N) && (y >= 0) && (y < N)){ // Don't go off the board
                validmove = true;
                PSEUDOCODE: set location x-coordinate to x
                PSEUDOCODE: set location y-coordinate to y
            }
        }
        moves++;
        PSEUDOCODE: if the location is back at the origin, finished = true;
    }
    sum += moves;
}
double avg = sum / float(trials);