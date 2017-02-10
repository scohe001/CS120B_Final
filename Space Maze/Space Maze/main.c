/*
 * Space Maze.c
 *
 * Created: 3/4/2016 8:15:07 PM
 * Author : Ace
 */ 

#include <avr/io.h>
#include "scheduler.h"
#include "arduino.h"
#include "joystick.h"
#include "arduino.h"
#include "timer.h"
#include "queue.h"
#include "levels.h"
#include "songs.c"

//Create our tasks up here so that they can edit eachother
task joyTask, moveTask, levelSetup, gameManager;

signed char currlvl = -1, loadlvl = 0;

Queue qmoves;
unsigned char ship_loc[2] = {0, 0};

enum MoveStates {MoveStart, MoveWait, MoveStep};

enum ManagerStates {ManagerPlaying, ManagerLoss, ManagerWin};
unsigned char cnt;
int ManagerTick(int state) { //Manages the game
	unsigned char tempA = ~PINA;
	switch(state) {
		case ManagerPlaying:
			if(tempA & 0x04) loadlvl = currlvl;
			break;
		case ManagerLoss:
			joyTask.running = 0;
			moveTask.running = 0;
			if(tempA & 0x04) {
				state = ManagerPlaying;
				loadlvl = currlvl;
			}
			break;
		case ManagerWin:
			joyTask.running = 0;
			moveTask.running = 0;
			if(tempA & 0x04) {
				nextSong();
				state = ManagerPlaying;
				currlvl = (currlvl + 1) % NUM_LVLS;
				loadlvl = currlvl;
			}
			break;
	}
	return state;
}

unsigned char increment(unsigned char *x, unsigned char *y) {
	(*y)++;
	if((*y) % 16 == 0) {
		*y = (*y) % 16, (*x)++;
	}
	if(*x > 0 && (*x) % 8 == 0) return 0;
	return 1;
}

enum LevelStates {LevelWait, LevelSetup};
unsigned char levx, levy;
int LevelTick(int state) { //Draws our levels for us when loadlvl != -1
	switch(state) {
		case LevelWait:
			if(loadlvl != -1) {
				//Disable all game tasks temporarily
				ship_loc[0] = ship_loc[1] = 0;
				joyTask.running = 0;
				moveTask.running = 0;
				gameManager.running = 0;
				levx = levy = 0;
				QueueMakeEmpty(qmoves);
				state = LevelSetup;
				clearScreen();
			}
			break;
		case LevelSetup:
			while(Levels[loadlvl][levx][levy] == EMPTY && increment(&levx, &levy));
			if(levx > 0 && levx%8 == 0) {
				joyTask.running = 1;
				moveTask.running = 1;
				moveTask.state = MoveStart;
				gameManager.running = 1;
				currlvl = loadlvl;
				loadlvl = -1;
				state = LevelWait;
				break;
			}
			drawBox(levx * 2, levy * 2, Levels[loadlvl][levx][levy]);
			if(Levels[loadlvl][levx][levy] == SHIP) {
				ship_loc[0] = levx;
				ship_loc[1] = levy;
			}
			increment(&levx, &levy);
	}
	return state;
}

enum JoyStates {JoyWait, JoyHold};	
int JoyTick(int state) { //Updates the joystick for us if it's not pressed
	switch(state) {
		case JoyWait:
			if(joyPos != None) {
				QueueEnqueue(qmoves, joyPos);
				state = JoyHold;
			}
			break;
		case JoyHold:
			if(joyPos == None) {state = JoyWait;}
			break;
	}
	return state;
}

void dead(unsigned char x, unsigned char y) {
	gameManager.state = ManagerLoss;
	sendLoss(2 * x, 2 * y);
}

void win(unsigned char x, unsigned char y) {
	gameManager.state = ManagerWin;
	playSong(flagWin);
	sendWin(2 * x, 2 * y);
}


signed char move[2] = {0, 0};
enum Positions pos;
int MoveTick(int state) { //Moves the ship and updates game state
	switch(state) {
		case MoveStart:
			move[0] = move[1] = 0;
			QueueMakeEmpty(qmoves);
			state = MoveWait;
			break;
		case MoveWait:
			if(!QueueIsEmpty(qmoves)) {
				state = MoveStep;
				pos = QueueDequeue(qmoves);
				//Setup our move vector
				if(pos == Left) {move[0] = 1; move[1] = 0;}
				else if(pos == Right) {move[0] = -1; move[1] = 0;}
				else if(pos == Down) {move[0] = 0; move[1] = 1;}
				else if(pos == Up) {move[0] = 0; move[1] = -1;}
			}
			break;
		case MoveStep:
			;signed char new_pos[2] = {ship_loc[0] + move[0], ship_loc[1] + move[1]};
			enum Piece next = Levels[currlvl][new_pos[0]][new_pos[1]];
			if(next == ASTEROID || next == USPIKE || next == RSPIKE || next == DSPIKE || next == LSPIKE) { //They hit an asteroid and stopped
				state = MoveWait;
				if((move[1] == 1 && next == LSPIKE) || 
					(move[0] == 1 && next == USPIKE) ||
					(move[1] == -1 && next == RSPIKE) || 
					(move[0] == -1 && next == DSPIKE)) {
						
						dead(ship_loc[0], ship_loc[1]);
				}
				break;
			}
			drawBox(ship_loc[0] * 2, ship_loc[1] * 2, EMPTY);
			ship_loc[0] = new_pos[0];
			ship_loc[1] = new_pos[1];
			drawBox(ship_loc[0] * 2, ship_loc[1] * 2, SHIP);
			if(ship_loc[0] < 0 || ship_loc[0] >= 8 || ship_loc[1] < 0 || ship_loc[1] >= 16) {
				dead(ship_loc[0] - move[0], ship_loc[1] - move[1]);
				state = MoveWait;
			} else if(Levels[currlvl][ship_loc[0]][ship_loc[1]] == FINISH) { //They won!
				win(ship_loc[0], ship_loc[1]);
				state = MoveWait;
			}
			break;
	}
	return state;
};


int main(void)
{
	DDRA = 0x00; PINA = 0xFF; PORTA = 0xFF;
	DDRB = 0xFF; PINB = 0x00; PORTB = 0x00;
	DDRC = 0xFF; PINC = 0x00; PORTC = 0x00;
	DDRD = 0xFF; PIND = 0x00; PORTD = 0x00;
	
	#define num_tasks 5
	
	songTask = (task){Start, 5, 5, &SoundTick, 1};
	levelSetup = (task){LevelWait, 50, 50, &LevelTick, 1};
	joyTask = (task){JoyWait, 25, 25, &JoyTick, 0};
	moveTask = (task){MoveWait, 100, 100, &MoveTick, 0};
	gameManager = (task){ManagerPlaying, 25, 25, &ManagerTick, 0};
	
	playSong(undertale);
	
	task *tasks[num_tasks] = {&songTask, &joyTask, &moveTask, &levelSetup, &gameManager};
	unsigned short period = 1;
	
	TimerSet(period);
	TimerOn();
	joystickInit();
	initUSART(0);
	USART_Flush(0);
	
	qmoves = QueueInit(10);
	
    while (1) {
		joystickSample(); //updates joyPos
		for(int i=0; i<num_tasks; i++) {
			if(!tasks[i]->running) continue;
			if(tasks[i]->elapsedTime >= tasks[i]->period) {
				tasks[i]->elapsedTime = 0;
				tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
			}
			tasks[i]->elapsedTime += period;
		}
		while(!TimerFlag);
		TimerFlag = 0;
    }
}

