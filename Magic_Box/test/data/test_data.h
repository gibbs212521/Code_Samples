#ifndef __TEST_DATA_H__
#define __TEST_DATA_H__


int basic2x2Matrix[2][2] = { {1,2}, {3,4} };
int basic3x3Matrix[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
int basic4x4Matrix[4][4] = { {1,2,3,4}, {1,2,3,4}, {1,2,3,4} };

int basic2x3Matrix[2][3] = { {1,2}, {1,2,3} };
int basic5x3Matrix[5][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {1,2,3}, {1,2,3} };
int basic7x15Matrix[7][15] = {
    {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5}, {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5},
    {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5}, {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5},
    {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5}, {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5},
    {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5}
};

int magic3x3Matrix[3][3] = { {8,3,4}, {1,5,9}, {6,7,2}};
int magic4x4Matrix[4][4] = { {1,15,14,4}, {12,6,7,9}, {8,10,11,5}, {13,3,2,16} };

int generateRandomMatrix(int width_length, int side_length);
int generateRandomMagicSquare(int side_length);

// use replacement method for trivial even solution
int generateEvenMagicSquare(int side_length);

// use symetry method for trivial odd solution
int generateOddMagicSqure(int side_length);



#endif
