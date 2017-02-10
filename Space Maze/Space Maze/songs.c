#ifndef __SONGS__
#define __SONGS__

#include "scheduler.h"

#define C1	32.7
#define Db1	34.65
#define D1	36.71
#define Eb1	38.89
#define E1	41.20
#define F1	43.65
#define Gb1	46.25
#define G1	49.00
#define Ab1	51.91
#define A1	55.00
#define Bb1	58.27
#define B1	61.74

#define C2	65.41
#define Db2	69.30
#define D2	73.42
#define Eb2	77.78
#define E2	82.41
#define F2	87.31
#define Gb2	92.50
#define G2	98.00
#define Ab2	103.83
#define A2	110.00
#define Bb2	116.54
#define B2	123.47

#define C3	130.81
#define Db3	138.59
#define D3	146.83
#define Eb3	155.56
#define E3	164.81
#define F3	174.61
#define Gb3	185.00
#define G3	196.00
#define Ab3	207.65
#define A3	220.00
#define Bb3	233.08
#define B3	246.94

#define C4	261.94
#define Db4	277.18
#define D4	293.66
#define Eb4	311.13
#define E4	329.63
#define F4	349.23
#define Gb4	369.99
#define G4	392.00
#define Ab4	415.30
#define A4	440.00
#define Bb4	466.16
#define B4	493.88

#define C5	523.25
#define Db5	554.37
#define D5	587.33
#define Eb5	622.25
#define E5	657.25
#define F5	698.46
#define Gb5	739.99
#define G5	783.99
#define Ab5	830.61
#define A5	880.00
#define Bb5	932.33
#define B5	987.77

#define C6	1046.50

#define REST 0

#define Wh  400
#define Ha  200
#define Qu  100
#define Ei  50
#define Si  25
#define Th1	12
#define Th2	13

struct Song {
	double *rightNotes;
	unsigned short *rightTiming;
	unsigned short rightLen;
	double *leftNotes;
	unsigned short *leftTiming;
	unsigned short leftLen;
	unsigned char spd;
	unsigned char rcurr_note, lcurr_note;
	unsigned short rightWaits, leftWaits;
	signed short rightCnt, leftCnt;
};

void set_PWM1(double);
void set_PWM2(double);
void PWM_on();
void PWM_off();

//Setup the null song (nothing playing)
double null_notes1[] = {REST};
unsigned short null_timing1[] = {Wh};
double null_notes2[] = {REST};
unsigned short null_timing2[] = {Wh};

#define null_cnt1 1
#define null_cnt2 1
#define null_spd 4

//Mega Man 2, Wily Theme
double wily_notes[] = {REST, E3, E3, E3, E3, E3, E3, Db3, REST, Db3, Db3,
						E3, E3, E3, E3, Db3, REST, Ab3, Gb3, Ab3,
						REST, E3, E3, E3, E3, E3, E3, Db3, REST, Ab3,
						REST, Gb3, REST, E3, REST, Gb3, REST,
						
						REST, Gb3, Gb3, Gb3, Gb3, Gb3, Gb3, Eb3, REST, Ab3,
						REST, Gb4, REST, E4, REST, D4, REST, Db4,
						REST, Db3, Ab3, B3, Bb3, Db3,
						REST, Db3, Ab3, B3, Bb3, Eb4, E4,
						
						REST, E3, E3, E3, E3, E3, E3, Db3, REST, Db3, Db3,
						E3, E3, E3, E3, Db3, REST, Ab3, Gb3, Ab3,
						REST, E3, E3, E3, E3, E3, E3, Db3, REST, Ab3,
						REST, Gb3, REST, E3, REST, Gb3, REST,
						
						REST, Gb3, Gb3, Gb3, Gb3, Gb3, Gb3, Eb3, REST, Ab3,
						REST, Gb4, REST, E4, REST, D4, REST, Db4,
						REST, Db3, Ab3, B3, Bb3, Db3,
						REST, Db3, Ab3, B3, Bb3, B3, Db4,
						
						B3, E4,
						Db4, B3, Db4,
						B3, B3, Db4,
						Ab3, A3, Ab3, E3, REST, E3, Ab3, B3,
						Db4, B3, E4,
						Db4, B3, Db4, B3,
						B3, Ab3, B3, C4,
						REST, C4, C4, Eb4, Ab4,};
unsigned short wily_timing[] = {Ei, Si, Si, Ei, Si, Si, Ei, Ei, Ei, Si, Si,
									Ei, Si, Si, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Si, Si, Ei, Si, Si, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Qu,
									
									Ei, Si, Si, Ei, Si, Si, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Qu+Ei, Ei,
									Ei, Ei, Ei, Ei, Qu, Ei, Ei,
									
									Ei, Si, Si, Ei, Si, Si, Ei, Ei, Ei, Si, Si,
									Ei, Si, Si, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Si, Si, Ei, Si, Si, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Qu,
									
									Ei, Si, Si, Ei, Si, Si, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Qu+Ei, Ei,
									Ei, Ei, Ei, Ei, Qu, Ei, Ei+Ha+Qu,
									
									Ei, Qu,
									Qu, Qu, Qu+Ei,
									Ha, Ei, Qu+Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ha+Qu, Ei, Qu,
									Qu, Qu, Qu, Ei+Ha,
									Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ha};
									
double wily_notes2[] = {Db2, Db2, Db2, Db2, Db2, Db2, Db2, Db2,
							Db2, Db2, Db2, Db2, Db2, Db2, Db2, Db2,
							A1, A1, A1, A1, A1, A1, A1, A1,
							A1, A1, A1, A1, A1, A1, A1, A1,
							B1, B1, B1, B1, B1, B1, B1, B1,
							B1, B1, B1, B1, B1, B1, B1, B1,
							Db2, Db2, Db2, Db2, Db2, Db2, Db2, Db2,
							Db2, Db2, Db2, Db2, Db2, Db2, B1, Db2,
							
							Db2, Db2, Db2, Db2, Db2, Db2, Db2, Db2,
							Db2, Db2, Db2, Db2, Db2, Db2, Db2, Db2,
							A1, A1, A1, A1, A1, A1, A1, A1,
							A1, A1, A1, A1, A1, A1, A1, A1,
							B1, B1, B1, B1, B1, B1, B1, B1,
							B1, B1, B1, B1, B1, B1, B1, B1,
							Db2, Db2, Db2, Db2, Db2, Db2, Db2, Db2,
							Db2, Db2, Db2, Db2, Db2, Db2, B1, Db2,
							
							REST, D2, D2, D2, D2, A2, Gb2, D2,
							REST, D2, Gb2, D2, D3, D2, Gb2, D2,
							Db2, Db2, Db2, Db2, Db2, Ab2, Db2, B2,
							REST, Db2, E2, Db2, B2, Db2, E2, Db2,
							D2, D2, D2, D2, D2, A2, Gb2, D2,
							REST, D2, Gb2, D2, D3, D2, Gb2, D2,
							B1, B1, B1, B1, B1, Ab1, B1, C2,
							REST, C2, C2, C2, C2,};
unsigned short wily_timing2[] = {Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ha,};

#define wily_cnt1 168
#define wily_cnt2 189
#define wily_spd 4


//Megalovania, Undertale
double undertale_notes1[] = {D3, D3, D4, A3, REST, Ab3, G3, F3, D3, F3, G3,
								C3, C3, D4, A3, REST, Ab3, G3, F3, D3, F3, G3,
								B2, B2, D4, A3, REST, Ab3, G3, F3, D3, F3, G3,
								Bb2, Bb2, D4, A3, REST, Ab3, G3, F3, D3, F3, G3,
								
								D4, D4, D5, A4, REST, Ab4, G4, F4, D4, F4, G4,
								C4, C4, D5, A4, REST, Ab4, G4, F4, D4, F4, G4,
								B3, B3, D5, A4, REST, Ab4, G4, F4, D4, F4, G4,
								Bb3, Bb3, D5, A4, REST, Ab4, G4, F4, D4, F4, G4,
								
								E4, F4, F4, F4, F4, E4, F4, D4, D4,
								F4, F4, F4, G4, Ab4, G4, Ab4, G4, D4, F4, G4,
								F4, F4, F4, G4, Ab4, A4, C5, A4,
								D5, D5, D5, A4, D5, C5, G5,
								
								A4, A4, A4, A4, A4, G4, G4,
								A4, A4, A4, A4, G4, A4, D5, A4, G4,
								D5, A4, G4, F4, C5, G4, F4, E4,
								Bb3, D4, E4, F4, C5,
								
								};
unsigned short undertale_timing1[] = {Si, Si, Ei, Ei, Si, Ei, Ei, Ei, Si, Si, Si,
										Si, Si, Ei, Ei, Si, Ei, Ei, Ei, Si, Si, Si,
										Si, Si, Ei, Ei, Si, Ei, Ei, Ei, Si, Si, Si,
										Si, Si, Ei, Ei, Si, Ei, Ei, Ei, Si, Si, Si,
										
										Si, Si, Ei, Ei, Si, Ei, Ei, Ei, Si, Si, Si,
										Si, Si, Ei, Ei, Si, Ei, Ei, Ei, Si, Si, Si,
										Si, Si, Ei, Ei, Si, Ei, Ei, Ei, Si, Si, Si,
										Si, Si, Ei, Ei, Si, Ei, Ei, Ei, Si, Si, Si,
										
										Th1, Ei-Th1, Si, Ei, Ei, Th2, Ei-Th2, Ei, Qu+Si,
										Ei, Si, Ei, Ei, Ei, Th1, Th2, Si, Si, Si, Ei+Si,
										Ei, Si, Ei, Ei, Ei, Ei, Ei, Ei+Si,
										Ei, Ei, Si, Si, Si, Qu, Qu+Si,
										
										Ei, Si, Ei, Ei, Ei, Ei, Qu+Si,
										Ei, Ei, Si, Ei, Ei, Ei, Ei, Si, Ei,
										Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
										Ei, Si, Ei, Ei, Si+Ha,
										
										};

double undertale_notes2[] = {D2, D2, D2, D2, REST, D2, D2, D2, D2, D2, D2,
								C2, C2, C2, C2, REST, C2, C2, C2, C2, C2, C2,
								B1, B1, B1, B1, REST, B1, B1, B1, B1, B1, B1,
								Bb1, Bb1, Bb1, Bb1, REST, Bb1, Bb1, Bb1, Bb1, Bb1, Bb1,
								
								D2, D2, D2, D2, REST, D2, D2, D2, D2, D2, D2,
								C2, C2, C2, C2, REST, C2, C2, C2, C2, C2, C2,
								B1, B1, B1, B1, REST, B1, B1, B1, B1, B1, B1,
								Bb1, Bb1, Bb1, Bb1, REST, Bb1, Bb1, Bb1, Bb1, Bb1, Bb1,
								
								D2, D2, D2, D2, REST, D2, D2, D2, D2, D2, D2,
								C2, C2, C2, C2, REST, C2, C2, C2, C2, C2, C2,
								B1, B1, B1, B1, REST, B1, B1, B1, B1, B1, B1,
								Bb1, Bb1, Bb1, Bb1, REST, Bb1, Bb1, Bb1, Bb1, Bb1, Bb1,
								
								D2, D2, D3, A2, REST, Ab2, G2, F2, D2, F2, G2,
								C2, C2, D3, A2, REST, Ab2, G2, F2, D2, F2, G2,
								B1, B1, D3, A2, REST, Ab2, G2, F2, D2, F2, G2,
								Bb1, Bb1, D3, A2, REST, C1, G2, F2, D2, F2, G2,};

unsigned short undertale_timing2[] = {Ei, Ei, Si, Si, Si, Ei, Ei, Si, Si, Si, Ei,
										Ei, Ei, Si, Si, Si, Ei, Ei, Si, Si, Si, Ei,
										Ei, Ei, Si, Si, Si, Ei, Ei, Si, Si, Si, Ei,
										Ei, Ei, Si, Si, Si, Ei, Ei, Si, Si, Si, Ei,
										
										Ei, Ei, Si, Si, Si, Ei, Ei, Si, Si, Si, Ei,
										Ei, Ei, Si, Si, Si, Ei, Ei, Si, Si, Si, Ei,
										Ei, Ei, Si, Si, Si, Ei, Ei, Si, Si, Si, Ei,
										Ei, Ei, Si, Si, Si, Ei, Ei, Si, Si, Si, Ei,
										
										Ei, Ei, Si, Si, Si, Ei, Ei, Si, Si, Si, Ei,
										Ei, Ei, Si, Si, Si, Ei, Ei, Si, Si, Si, Ei,
										Ei, Ei, Si, Si, Si, Ei, Ei, Si, Si, Si, Ei,
										Ei, Ei, Si, Si, Si, Ei, Ei, Si, Si, Si, Ei,
										
										Si, Si, Ei, Ei, Si, Ei, Ei, Ei, Si, Si, Si,
										Si, Si, Ei, Ei, Si, Ei, Ei, Ei, Si, Si, Si,
										Si, Si, Ei, Ei, Si, Ei, Ei, Ei, Si, Si, Si,
										Si, Si, Ei, Ei, Si, Ei, Ei, Ei, Si, Si, Si,};
	
#define undertale_cnt1 152
#define undertale_cnt2 176
#define undertale_spd 5

//Great Fair Fountain, Legend of Zelda Series
double fairy_notes1[] = {A4, D4, Bb3, G3, G4, D4, Bb3, G3, Gb4, D4, Bb3, G3, G4, D4, Bb3, G3,
							G4, C4, A3, F3, F4, C4, A3, F3, E4, C4, A3, F3, F4, C4, A3, F3,
							F4, Bb3, G3, E3, E4, Bb3, G3, E3, Eb4, Bb3, G3, E3, E4, Bb3, G3, E3,
							E4, A3, F3, D3, D4, A3, F3, D3, Db4, A3, F3, D3, D4, A3, F3, D3,
							
							
							A4, D4, Bb3, G3, G4, D4, Bb3, G3, Gb4, D4, Bb3, G3, G4, D4, Bb3, G3,
							Bb4, Eb4, C4, Gb3, A4, Eb4, C4, Gb3, Ab4, Eb4, C4, Gb3, A4, Eb4, C4, Gb3,
							C5, D4, Bb3, G3, Bb4, D4, Bb3, G3, A4, D4, Bb3, G3, Bb4, D4, Bb3, G3,
							A4, Bb3, G3, E3, G4, Bb3, G3, E3, F4, Bb3, G3, E3, E4, Bb3, G3, E3, };

unsigned short fairy_timing1[] = {Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si,
									
									Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si,};
	
double fairy_notes2[] = {Bb2, Bb2, D3, A3, D3, A3, G3, C4, A3, G3, D3,
							A2, A2, C3, F3, A2, A2, G3, F3, C4, G3, F3, C3,
							G2, G2, Bb2, F3, G2, G2, F3, E3, G3, E3, C3, Bb2,
							F2, F2, A2, E3, F2, F2, E3, D3, G3, F3, C4, A3,
							
							Bb2, Bb2, D3, A3, Bb2, D3, A3, G3, D4, A3, G3, D3,
							A2, A2, C3, C4, D3, D3, C4, A3, Eb4, D4, C4, A3,
							G2, G2, D3, Bb3, G2, G2, Bb3, A3, C4, Bb3, G3, D3,
							C3, C3, G3, Bb3, C3, C3, Bb3, G3, E4, D4, G4, E4,};
	
unsigned short fairy_timing2[] = {Si, Si, Si, Si+Qu+Si, Si, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si+Qu, Si, Si, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si+Qu, Si, Si, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si+Qu, Si, Si, Si, Si, Si, Si, Si, Si,
									
									Si, Si, Si, Si+Qu, Si, Si, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si+Qu, Si, Si, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si+Qu, Si, Si, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si+Qu, Si, Si, Si, Si, Si, Si, Si, Si,};

#define fairy_cnt1 128
#define fairy_cnt2 95
#define fairy_spd 8

//Flagpole Fanfare, Super Mario Bros
double flag_notes1[] = {G2, C3, E3, G3, C4, E4,
						G4, E4,
						Ab2, C3, Eb3, Ab3, C4, Eb4,
						Ab4, Eb4,
						Bb2, D3, F3, Bb3, D4, F4,
						Bb4, Bb4, Bb4, Bb4,
						C5};

unsigned short flag_timing1[] = {Ei, Ei, Ei, Ei, Ei, Ei,
									Qu, Qu,
									Ei, Ei, Ei, Ei, Ei, Ei,
									Qu, Qu,
									Ei, Ei, Ei, Ei, Ei, Ei,
									Qu, Ei, Ei, Ei,
									Ha};

double flag_notes2[] = {G2, E2, G2, C2, E2, G2,
						E3, C3,
						Ab2, Eb2, Ab2, C2, Eb2, Ab2,
						Eb3, C3,
						Bb2, F2, Bb2, D2, F2, Bb2,
						F3, D3, D3, D3,
						E3};

unsigned short flag_timing2[] = {Ei, Ei, Ei, Ei, Ei, Ei,
									Qu, Qu,
									Ei, Ei, Ei, Ei, Ei, Ei,
									Qu, Qu,
									Ei, Ei, Ei, Ei, Ei, Ei,
									Qu, Ei, Ei, Ei,
									Ha};

#define flag_cnt1 27
#define flag_cnt2 27
#define flag_spd 3


struct Song null_song, wily, undertale, fairyFountain, flagWin;
task songTask;
struct Song curr_song;
#define num_songs 3
struct Song songs[num_songs];

//Switch the SoundTick variable out for those of the new song
void playSong(struct Song s) {
	curr_song = s;
	curr_song.rcurr_note = curr_song.lcurr_note = 0;
	curr_song.rightWaits = curr_song.leftWaits = 0;
	curr_song.rightCnt = curr_song.leftCnt = 0;
	songTask.period = songTask.elapsedTime = curr_song.spd;
}

//Play the next song
void nextSong() {
	static unsigned char song_num = 0;
	playSong(songs[song_num]);
	song_num = (song_num + 1) % num_songs;
}

enum SoundStates {Start, Play};
int SoundTick(int state) {
	switch(state) {
		case Start:
            //Setup our Song items
			PWM_on();
			null_song = (struct Song){null_notes1, null_timing1, null_cnt1, null_notes2, null_timing2, null_cnt2, null_spd};
			undertale = (struct Song){undertale_notes1, undertale_timing1, undertale_cnt1, undertale_notes2, undertale_timing2, undertale_cnt2, undertale_spd};
			fairyFountain = (struct Song){fairy_notes1, fairy_timing1, fairy_cnt1, fairy_notes2, fairy_timing2, fairy_cnt2, fairy_spd};
			wily = (struct Song){wily_notes, wily_timing, wily_cnt1, wily_notes2, wily_timing2, wily_cnt2, wily_spd};
			flagWin = (struct Song){flag_notes1, flag_timing1, flag_cnt1, flag_notes2, flag_timing2, flag_cnt2, flag_spd};
			songs[0] = wily; songs[1] = undertale; songs[2] = fairyFountain;
			nextSong();
			state = Play;
			break;
		case Play:
            //Increment time on each speaker and play the correct note
			if(curr_song.rightCnt < 0) {
				set_PWM1(0); curr_song.rightCnt++;
			} else {
				set_PWM1(curr_song.rightNotes[curr_song.rcurr_note]);
				curr_song.rightCnt++;
				if(curr_song.rightCnt >= curr_song.rightTiming[curr_song.rcurr_note]) {
					if(curr_song.rightWaits >= curr_song.leftWaits) {curr_song.rightCnt = -1; curr_song.rightWaits++;}
					else {curr_song.rightCnt = -2; curr_song.rightWaits += 2;}
					curr_song.rcurr_note = (curr_song.rcurr_note + 1) % curr_song.rightLen;
				}
			}
			
			if(curr_song.leftCnt < 0) {
				set_PWM2(0); curr_song.leftCnt++;
				} else {
				set_PWM2(curr_song.leftNotes[curr_song.lcurr_note]);
				curr_song.leftCnt++;
				if(curr_song.leftCnt >= curr_song.leftTiming[curr_song.lcurr_note]) {
					if(curr_song.leftWaits >= curr_song.rightWaits) {curr_song.leftCnt = -1; curr_song.leftWaits++;}
					else {curr_song.leftCnt = -2; curr_song.leftWaits += 2;}
					if(curr_song.leftLen == 27 && curr_song.rightLen == 27 && curr_song.lcurr_note + 1 == curr_song.leftLen) playSong(null_song);
					curr_song.lcurr_note = (curr_song.lcurr_note + 1) % curr_song.leftLen;
				}
			}
			break;
	}
	return state;
}










//Hearthstone
#define hearth_cnt 106
#define hearth_spd 6
double hearth_notes[] = {D4, F4, D4, C4, A3, C4, A3, G3, D3, F3, A3, B3,
							F3, D3, F3, E3, D4, F4, D4, C4, A3, C4,
							A3, G3, D3, F3, A3, B3, F3, D3, F3,
							
							REST, G3, A3, C4, A3, G3, D3, C3,
							D3, A2, D3, E3, F3, E3, C3, D3, A2, D3,
							E3, F3, E3, REST, D3, A2, D3, E3, F3, E3,
							F3, E3, D3, C3, A2, C3, B2, G2, A2, REST,
							
							D3, A2, D3, E3, F3, E3, C3, D3, A2, D3,
							E3, F3, G3, REST, D3, A2, D3, E3, F3, E3, F3,
							G3, F3, E3, D3, A3, C4, A3, G3, D3, G3, A3, C4, A3, G3, D3, G3};
unsigned short hearth_timing[] = {Si, Si, Si, Ei+Si, Si, Si, Si, Ei+Si, Si, Si, Si, Si,
									Si, Si, Ei+Si, Ei+Si, Si, Si, Si, Ei+Si, Si, Si,
									Si, Ei+Si, Si, Si, Si, Si, Si, Si, Qu+Ei,
									
									Ei+Th1, Th2, Si, Si, Si, Si, Si, Si,
									Ei, Si, Si, Si, Si, Ei, Qu, Ei, Si, Si,
									Si, Si, Qu, Ei, Ei, Si, Si, Si, Si, Ei,
									Th1, Th2, Ei, Si, Ei, Si, Ei, Si, Qu, Ei,
									
									Ei, Si, Si, Si, Si, Ei, Qu, Ei, Si, Si,
									Si, Si, Qu, Ei, Ei, Si, Si, Si, Si, Si, Si,
									Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si, Si};
double hearth_notes2[hearth_cnt] = {0};
unsigned short hearth_timing2[hearth_cnt] = {0};

//Requiem
double requiem_notes[] = {Bb4, A4, G4, D4, Bb4, A4, G4, D4,
							Bb4, A4, G4, D4, C5, Bb4, A4, Bb4,
							Bb4, A4, G4, D4, Bb4, A4, G4, D4,
							Bb4, A4, G4, D4, C5, Bb4, A4, Bb4,};
unsigned short requiem_timing[] = {Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
									Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei};
#define requiem_cnt 32
#define requiem_spd 7

//Epic Sax Guy
double epicsax_notes[] = {Gb4, REST, Gb4, Gb4, Gb4, E4, Gb4, REST,
							Gb4, REST, Gb4, Gb4, Gb4, E4, Gb4, REST,
							Gb4, REST, A4, Gb4, REST, E4,
							E4, D4, REST, B3, B3, Db4, D4, B3};
unsigned short epicsax_timing[] = {Qu, Qu, Ei, Si, Si, Si, Si, Ei,
							Qu, Qu, Ei, Si, Si, Si, Si, Ei,
							Qu, Ei, Qu, Ei, Ei, Ei,
							Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei};
#define epicsax_cnt 30
#define epicsax_spd 5

//Dreamland 91 notes
double dreamland_notes[] = {Eb5, D5, C5, Bb4, F4, D4,
					Ab4, Bb4, C5, D5, B4, REST,
					C5, REST, G4, REST,
					Eb4, D4, C4, REST,
					C4, D4, Eb4, C4,
					Bb3, C4, G3, REST,
					C5, REST, G4, REST,
					Eb4, D4, C4, C4, D4,
					Eb4, F4, D4, Bb3,
					C4, G3, C4, REST,
					
					C6, REST, G5, REST,
					Eb5, D5, C5, REST,
					C5, D5, Eb5, C5,
					Bb4, C5, G4, REST,
					C6, REST, G5, REST,
					D5, F5, G5, C5,
					D5, F5, D5, Bb4,
					C5, REST,
					
					F2, F3, F2, F3, A2, F3, C3, F3,
					Eb3, Eb3, D3, Eb3, C3, Eb3, Bb2, Eb3,
					//REST, F3, REST, F3, REST, F3, REST, F3,
					//REST, F3, REST, F3, REST, F3, REST, F3,
					};
unsigned short dreamland_timing[] = {Qu, Ei, Ei, Ei, Ei, Qu,
							Ei, Ei, Ei, Ei, Qu, Qu,
							Qu, Qu, Qu, Qu,
							Qu, Qu, Qu, Qu,
							Qu, Qu, Qu, Qu,
							Qu, Qu, Qu, Qu,
							Qu, Qu, Qu, Qu,
							Qu, Qu, Qu, Ei, Ei,
							Qu, Qu, Qu, Qu,
							Qu, Qu, Qu, Qu,
							
							Qu, Qu, Qu, Qu,
							Qu, Qu, Qu, Qu,
							Qu, Qu, Qu, Qu,
							Qu, Qu, Qu, Qu,
							Qu, Qu, Qu, Qu,
							Qu, Qu, Qu, Qu,
							Qu, Qu, Qu, Qu,
							Ha, Ha,
							
							Ei, Ei, Ei, Ei, Ei, Ei, Ei,
							Ei, Ei, Ei, Ei, Ei, Ei, Ei,};
#define dreamland_cnt 91
#define dreamland_spd 4

//Tetris Theme A 63 notes
double tetris_notes[] = {E4, B3, C4, D4, E4, D4, C4, B3,
					A3, A3, C4, E4, D4, C4,
					B3, E3, Ab3, C4, D4, E4,
					C4, A3, A3,
					REST, D4, F4, A4, G4, F4,
					E4, C4, E4, D4, C4,
					B3, E3, B3, C4, D4, Ab3, E4, Ab3,
					C4, E3, A3, A3, REST,
					
					E4, C4,
					D4, B3,
					C4, A3,
					Ab3, B3,
					E4, C4,
					D4, B3,
					C4, E4, A4,
					Ab4};
unsigned short tetris_timing[] = {Qu, Ei, Ei, Ei, Si, Si, Ei, Ei,
							Qu, Ei, Ei, Qu, Ei, Ei,
							Ei, Ei, Ei, Ei, Qu, Qu,
							Qu, Qu, Ha,
							Ei, Qu, Ei, Qu, Ei, Ei,
							Qu+Ei, Ei, Qu, Ei, Ei,
							Ei, Ei, Ei, Ei, Ei, Ei, Ei, Ei,
							Ei, Ei, Qu, Qu, Qu,
							
							Ha, Ha,
							Ha, Ha,
							Ha, Ha,
							Ha, Ha,
							Ha, Ha,
							Ha, Ha,
							Qu, Qu, Ha,
							Wh};
#define tetris_cnt 63
#define tetris_spd 5

double sandstorm_notes[] = {B3, B3, B3, B3, B3, B3, B3, B3, B3, B3, B3, B3, E4, E4,
					E4, E4, E4, E4, E4, D4, D4, D4, D4, D4, D4, D4, A3, A3};
unsigned short sandstorm_timing[] = {25, 25, 25, 25, 50, 25, 25, 25, 25, 25, 25, 50, 25, 25,
							25, 25, 25, 25, 50, 25, 25, 25, 25, 25, 25, 50, 25, 25};
#define sandstorm_cnt 28
#define sandstorm_spd 4


void set_PWM2(double frequency) {
	// Keeps track of the currently set frequency
	// Will only update the registers when the frequency
	// changes, plays music uninterrupted.
	static double current_frequency;
	if (frequency != current_frequency) {

		if (!frequency) TCCR1B &= 0x08; //stops timer/counter
		else TCCR1B |= 0x03; // resumes/continues timer/counter
		
		// prevents OCR3A from overflowing, using prescaler 64
		// 0.954 is smallest frequency that will not result in overflow
		if (frequency < 0.954) OCR1A = 0xFFFF;
		
		// prevents OCR3A from underflowing, using prescaler 64					// 31250 is largest frequency that will not result in underflow
		else if (frequency > 31250) OCR1A = 0x0000;
		
		// set OCR3A based on desired frequency
		else OCR1A = (short)(8000000 / (128 * frequency)) - 1;

		TCNT1 = 0; // resets counter
		current_frequency = frequency;
	}
}

void set_PWM1(double frequency) {
	// Keeps track of the currently set frequency
	// Will only update the registers when the frequency
	// changes, plays music uninterrupted.
	static double current_frequency;
	if (frequency != current_frequency) {

		if (!frequency) TCCR3B &= 0x08; //stops timer/counter
		else TCCR3B |= 0x03; // resumes/continues timer/counter
		
		// prevents OCR3A from overflowing, using prescaler 64
		// 0.954 is smallest frequency that will not result in overflow
		if (frequency < 0.954) OCR3A = 0xFFFF;
		
		// prevents OCR3A from underflowing, using prescaler 64					// 31250 is largest frequency that will not result in underflow
		else if (frequency > 31250) OCR3A = 0x0000;
		
		// set OCR3A based on desired frequency
		else OCR3A = (short)(8000000 / (128 * frequency)) - 1;

		TCNT3 = 0; // resets counter
		current_frequency = frequency;
	}
}

void PWM_on() {
	TCCR3A = (1 << COM3A0);
	TCCR3B = (1 << WGM32) | (1 << CS31) | (1 << CS30);
	set_PWM1(0);
	
	TCCR1A = (1 << COM1A0);
	TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10);
	set_PWM2(0);
}

void PWM_off() {
	TCCR3A = 0x00;
	TCCR3B = 0x00;
	
	TCCR1A = 0x00;
	TCCR1B = 0x00;
}

#endif