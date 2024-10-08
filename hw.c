//IDEJA JE POSTAVITI while(1) u jedan thread a GAMING state mainwindow-a u drugi tako da primamo istovremeno hw i mis "dogadjaje"
//iz hw thread-a slati signale kada se desi nesto ka drugom thread-u i na pojavew tih signala igrica reaguje kao da se desio mis dogadjaj


#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
const char PCF8591 = 0x48; // adresa
int fd, x_move, y_move;
int x_pos = 0, y_pos = 0;
int threshold_left = 50;
int threshold_right = 250;
int threshold_down = 250;
int threshold_up = 50;
int num_cols = 15;
int num_rows = 20;
int right_click = 0, left_click = 0;



int main() {
    
    int field[num_rows][num_cols];

    for(int i=0; i<num_rows; ++i){
	for(int j=0; j<num_cols; ++j){
		field[i][j] = 0; //unrevealed state
	}
    }

    if (wiringPiSetup () == -1) exit (1);
        fd = wiringPiI2CSetup(PCF8591);

    pinMode(21, INPUT);
    pinMode(22, INPUT);

    
    while (1) {

    //set different stylesheet for square at pos x y

    //PRICA ZA JOYSTICK:

        // procitaj DAC preko AIN0
        wiringPiI2CReadReg8(fd, PCF8591 + 0) ; // dummy
        x_move = wiringPiI2CReadReg8(fd, PCF8591 + 0);
        //printf("x move = %d \n\n" , x_move);
        
        if(x_move < threshold_left){
	    //printf("left \n");
	    	
         if(x_pos > 0){
                x_pos--;
            }else{
                x_pos = num_cols-1;
            }

        }else if(x_move > threshold_right){
	    //printf("right \n");

            if(x_pos < num_cols){
                x_pos++;
            }else{
                x_pos = 0;
            }
         
        }

        // procitaj DAC preko AIN1
        wiringPiI2CReadReg8(fd, PCF8591 + 1) ; // dummy
        y_move = wiringPiI2CReadReg8(fd, PCF8591 + 1);
        //printf("y move = %d \n\n" , y_move);
        
         if(y_move > threshold_down || y_move == -1){
	    //printf("down \n");

            if(y_pos < num_rows){
                y_pos++;
            }else{
                y_pos = 0;
            }
        }else if(y_move < threshold_up){
	    //printf("up \n");

            if(y_pos > 0){
                y_pos--;
            }else{
                y_pos = num_rows-1;
            }
        }

        delay(500);
    
    //PRICA ZA TASTERE:

        right_click = digitalRead(21);
        //printf("right click = %d \n\n" , right_click);

        if(right_click == 0){
	    //printf("right click = %d \n\n" , right_click);

	    right_click = 1;

            if(field[y_pos][x_pos] == 0){
                field[y_pos][x_pos] = 1; //flag

		printf("flag x: %d y: %d \n", x_pos, y_pos);                
		//emit signal for flag for square at pos x y
                //flag(pos_x, pos_y); 
            }

	 if(field[y_pos][x_pos] == 1){
                field[y_pos][x_pos] = 0; //flag

		printf("flag x: %d y: %d \n", x_pos, y_pos);                
		//emit signal for unflag for square at pos x y
                //unflag(pos_x, pos_y); 
            }

        }

        left_click = digitalRead(22);
        //printf("left click = %d \n\n" , left_click);

        if(left_click == 0){
	    //printf("left click = %d \n\n" , left_click);

            left_click = 1;

            if(field[y_pos][x_pos] == 0){
                field[y_pos][x_pos] = 2; //reveal

		printf("reveal x: %d y: %d \n", x_pos, y_pos);
                //emit signal for reveal for square at pos x y
                //reveal(pos_x, pos_y);
            }
        }

    }
    return 0;
}
