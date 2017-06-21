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

#include <time.h>


using namespace std;

int main() {
    srand( static_cast<unsigned int>(time(NULL)));
    int bestFitness = 0;
    
    
    
        
        // int arrSize = 20;
        
        char black = 'h';
        int n = 0;
        
        int gridSize = 20;
        //int var = 3;
        
        int fitness = 0;

        //int genes [20] = {1,2,1,2,2,1,1,2,1,2,2,1,2,2,1,1,2,2,1};
        string genes = "hphpphhphpphphhpphph";
        //string genes = "hphpphhphpphphhpphphhphpphhphpphphhpphphhphpphhphpphphhpphphhphpphhphpphphhpphphhphpphhphpphphhpphph";
    
    
        char grid[gridSize][gridSize];
    
    
        int i = 0,x = 0,y = 0;
        int j = 0;
        
        
        for(int index = 0; index < 50; index ++){
        fitness = 0;
        
        for (i = 0; i < gridSize; i++ ) {
            
            for (j = 0; j < gridSize; j++ ) {
                grid[i][j] = '-';
            }
        }
        
        
        if(genes[0] == black){
            
            grid[gridSize / 2][gridSize / 2] = black;
            x = gridSize / 2;
            y = gridSize / 2;
            
            
        }
        
 
        for(i = 1; i < genes.size(); i ++){
            n = (int)rand() % 4;
            
            
            switch(n){
                case 0:{ // code for going up
    
                    if(grid[x-1][y] == '-' && x > 1){
                        
                        x --;
                      
                        
                       
                    } //  end if
                    
                    else{
                        i --;
        
                        
                    }
                    
                } break;// end case
                    
                case 1:{ // code for going right
                   
                    if(grid[x][y + 1] == '-' && y < gridSize){
                        
                        y++;
                       
                        //  cout << "X is " << x << " "  << "Y is " << y << endl;
                        
                     
                        
                    } // end if
                    
                    else{
                        i --;
                        
                  
                    }
                    
                } break;// end case
                    
                case 2:{  // code for going down
    
                    if(grid[x+1][y] == '-' && x < gridSize){
                        
                        x ++;
                       
                        //cout << "X is " << x << " "  << "Y is " << y << endl;
                        
                     
                        
                    } // end if
                    
                    else{
                        i --;
                        
                        
                        
                    }
                    
                }break; // end case
                    
                case 3:{ // code for going left
          
                    if(grid[x][y - 1] ==  '-' && y > 1){
                        
                        y--;
                     
                        
                        // cout << "X is " << x << " "  << "Y is " << y << endl;
                        
                        
                        
                    } // end if
                    
                    else{
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
                    
                    if(grid[i][j + 1] == black){
                        fitness ++;
                    }
                }
            }
            
        }
        
        for(j = 0; j < gridSize; j ++){
            
            for(i = 0; i < gridSize; i ++){
                
                if(grid[i][j] == black){
                    
                    if(grid[i+1][j] == black){
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
        
        
        
        
        
        
        
        
        
        if(bestFitness < fitness){
            bestFitness = fitness;
        }
        cout <<"\nTHE FITNESS IS "<< fitness;
        cout <<"\nTHE BEST FITNESS IS "<< bestFitness << endl;
        
        
        
    } // end while
    
    
    
    return 0;
}


