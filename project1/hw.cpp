#include "hw.h"

hw::hw(int num_rows, int num_cols):
    Rows(num_rows),
    Cols(num_cols)
{

    for(unsigned int i=0; i<Rows; ++i){
        for(unsigned int j=0; j<Cols; ++j){
            field[i][j] = 0; //unrevealed state
        }
    }

    if (wiringPiSetup () == -1) exit (1);
        fd = wiringPiI2CSetup(PCF8591);

    pinMode(21, INPUT);
    pinMode(22, INPUT);
}

void hw:: main_loop(){


    //while (1) {

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
                x_pos = Cols-1;
            }

        }else if(x_move > threshold_right){
        //printf("right \n");

            if(x_pos < Cols){
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

            if(y_pos < Rows){
                y_pos++;
            }else{
                y_pos = 0;
            }
        }else if(y_move < threshold_up){
        //printf("up \n");

            if(y_pos > 0){
                y_pos--;
            }else{
                y_pos = Rows-1;
            }
        }

        delay(500);

    //PRICA ZA TASTERE:

        right_click = digitalRead(21);
        //printf("right click = %d \n\n" , right_click);

        if(!right_click){
        //printf("right click = %d \n\n" , right_click);

        right_click = 1;

            if(!field[y_pos][x_pos]){
                field[y_pos][x_pos] = 1; //flag

        printf("flag x: %d y: %d \n", x_pos, y_pos);
        //emit signal for flag for square at pos x y
                flag(x_pos, y_pos);
            }

     if(field[y_pos][x_pos]){
                field[y_pos][x_pos] = 0; //flag

        printf("flag x: %d y: %d \n", x_pos, y_pos);
        //emit signal for unflag for square at pos x y
                unflag(x_pos, y_pos);
            }

        }

        left_click = digitalRead(22);
        //printf("left click = %d \n\n" , left_click);

        if(!left_click){
        //printf("left click = %d \n\n" , left_click);

            left_click = 1;

            if(!field[y_pos][x_pos]){
                field[y_pos][x_pos] = 2; //reveal

        printf("reveal x: %d y: %d \n", x_pos, y_pos);
                //emit signal for reveal for square at pos x y
                reveal(x_pos, y_pos);
            }
        }

    //}
}
