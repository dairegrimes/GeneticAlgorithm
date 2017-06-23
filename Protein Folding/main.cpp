//
//  main.cpp
//  Protein Folding
//
//  Created by Daire Grimes on 30/05/2017.
//  Copyright © 2017 Daire Grimes. All rights reserved.
//





#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <vector>

using namespace std;


int main() {
    
    
    
    srand( static_cast<unsigned int>(time(NULL)));
    int selection[20];
    int bestFitness = 0;
    char black = '1';
    char start = 's';
    int n = 0;
    int gridSize = 100;
    int fitness = 0;
    int tSelection = 0;

    vector<int> averageFitness;
    vector<int> fitnessSize;
    //string genes = "hphpphhphpphphhpphph";
    string genes = "010000000001001000000000100010000000100001000000010000010000010000001000001000000010001000000001000100000000010100000000001010000000000010000000000001000000";
    char grid [gridSize][gridSize];
    char bestGrid [gridSize][gridSize];
    std::string moves [genes.length()];
    string printMoves [genes.length()];
    ofstream myfile;
    
    int i = 0,x = 0,y = 0;
    int j = 0;
    int total = 0;
       for(int index = 0; index < 1000; index ++){
    //while (bestFitness < 9){
    

        fitness = 0;
        
        for (i = 0; i < gridSize; i++ ) {
            
            for (j = 0; j < gridSize; j++ ) {
                grid[i][j] = '-';
            }
        }
        
       
        
           grid[gridSize / 2][gridSize / 2] = 0;
           x = gridSize / 2;
           y = gridSize / 2;
 
            
            
            
        for(i = 1; i < genes.size(); i ++){
            
            if(grid[x-1][y] != '-' && grid[x+1][y] != '-' && grid[x][y-1] != '-' && grid[x][y+1] != '-')
            {
                //index --;
                break;
            }
            
            n = (int)rand() % 4;
            
            switch(n)
            {
                case 0:
                { // code for going up
    
                    if(grid[x-1][y] == '-' && x >= 1)
                    {
                        x --;
                        moves[i] = "up";
                    } //  end if
                    
                    else
                    {
                        i --;
                    }
                    
                } break;// end case
                    
                    
                    
                    
                case 1:
                { // code for going right
                   
                    if(grid[x][y + 1] == '-' && y <= gridSize)
                    {
                        y++;
                        moves[i] = "right";
                    } // end if
                    
                    else
                    {
                        i --;
                    }
                    
                } break;// end case
                    
                    
                    
                    
                    
                case 2:
                {  // code for going down
    
                    if(grid[x+1][y] == '-' && x <= gridSize)
                    {
                        x ++;
                        moves[i] = "down";
                    } // end if
                    
                    else
                    {
                        i --;
                    }
                    
                }break; // end case
                    
                    
                    
                    
                case 3:
                { // code for going left
          
                    if(grid[x][y - 1] ==  '-' && y >= 1)
                    {
                        y--;
                        moves[i] = "left";
                    } // end if
                    
                    else
                    {
                        i --;
                    }
                    
                } break;// end case
                    
                
            }
            
            
             grid[x][y] = genes[i];
            
           
            
        } // end for
        
        
        //CHECKING FITNESS
        
        for(i = 0; i < gridSize; i ++){
            
            for(j = 0; j < gridSize; j ++){
                
                if(grid[i][j] == black){
                    
                    if(grid[i][j + 1] == black || grid[i][j + 1] == start){
                        fitness ++;
                    }
                }
            }
            
        }
        
        for(j = 0; j < gridSize; j ++){
            
            for(i = 0; i < gridSize; i ++){
                
                if(grid[i][j] == black){
                    
                    if(grid[i+1][j] == black || grid[i+1][j] == start){
                        fitness ++;
                    }
                }
            }
            
        }
        
        for(i = 0; i < 20; i ++){
            
            if(genes[i] == black && genes[i+1] == black){
                fitness --;
            }
        }
        
        
        for( i = 0; i < gridSize; i ++ )
        {
            cout << endl;
            
            for(j = 0; j < gridSize; j ++)
            {
                cout << grid[i][j];
            }
        }
           
           cout << endl;
            /*
            
            for( int c = 0; c < gridSize; c ++ )
            {
                cout << endl;
                
                for(int t = 0; t < gridSize; t ++)
                {
                    cout << grid[c][t];
                }
            }
        
        */
           // GET AVERAGE
           averageFitness.push_back(fitness);
           
           
        
        if(bestFitness < fitness){
            bestFitness = fitness;
            
            for( int c = 0; c < gridSize; c ++ )
            {
                for(int t = 0; t < gridSize; t ++)
                {
                    bestGrid[c][t] = grid[c][t];
                }
            }
            
            
            for(i = 0; i < genes.length(); i ++)
            {
                printMoves[i] = moves[i];
            }
            
        }
           
        fitnessSize.push_back(fitness);
           
        //cout <<"\nTHE FITNESS IS "<< fitness;
        //cout <<"\nTHE BEST FITNESS IS "<< bestFitness << endl;
        
        
        
    } // end while
    
    
    
    //Tournament Selection

    for( i = 0; i < 20; i ++)
    {
         selection[i] = rand() % 1000;
    }
    
    
    
    
    
    // Getting Average
    for(i = 0; i < averageFitness.size(); i ++)
    {
        total = averageFitness[i] + total;
    }
    
    total = total / averageFitness.size();
    
    
    // Output to CSV
    
    myfile.open ("Genetic.csv");
    myfile << "The best fitness is " << bestFitness << endl;
    for( int c = 0; c < gridSize; c ++ )
    {
        myfile << endl;
        for(int t = 0; t < gridSize; t ++)
        {
            myfile << bestGrid[c][t];
        }
    }
    
    for(i = 0; i < genes.size(); i ++)
    {
        myfile << endl << printMoves[i] << " ";
    }
    myfile << endl << "The average fitness is " << total << endl;
    
    myfile << endl << "Tournament Selection" << endl;
    
    for(i = 0 ; i < 20; i ++)
    {
        myfile << fitnessSize[selection[i]] << " ";
    }
    
    
    for(int i = 0 ; i < 20; i ++)
    {
        if(fitnessSize[selection[i]] > tSelection)
        {
            tSelection = fitnessSize[selection[i]];

            
        }
    }
    
    myfile << endl << "The biggest fitness is: " << tSelection;
    myfile << endl;
    myfile << endl;
    myfile << endl;
    myfile.close();
    
    
    return 0;
}


