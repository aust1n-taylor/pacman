#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

char gb[28][32] = {
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#','#'},
	{'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
	{'#', '.', '#', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '#', '.', '#'},
	{'#', '@', '#', ' ', ' ', '#', '.', '#', ' ', ' ', ' ', ' ', ' ', '#', '.', '#', '#', '.', '#', ' ', ' ', ' ', ' ', ' ', '#', '.', '#', ' ', ' ', '#', '.', '#'},
	{'#', '.', '#', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '#', '@', '#'},
	{'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
	{'#', '.', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
	{'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
	{'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', ' ', '#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', '#', '.', '#', '.', '.', '.', '.', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '.', '.', '.', '#', '.', '#', ' ', ' ', ' ', ' ', ' '},
	{'#', '#', '#', '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '.', '.', '.', '#', '.', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', ' ', ' ', '.', ' ', '.', '.', '.', '.', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '.', '.', '.', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' '},
	{'#', '#', '#', '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '.', '.', '.', '#', '.', '#', '#', '#', '#', '#', '#'},
	{' ', ' ', ' ', ' ', ' ', '#', '.', '#', '.', '.', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '.', '#', '.', '#', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', '#', '.', '#', '.', '.', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '.', '#', '.', '#', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', '#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#', ' ', ' ', ' ', ' ', ' '},
	{'#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#'},
	{'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
	{'#', '.', '#', '#', '#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '.', '#', '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '#', '.', '#'},
	{'#', '.', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '.', '#'},
	{'#', '.', '.', '.', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '.', '.', '.', '#'},
	{'#', '.', '.', '.', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '.', '.', '.', '#'},
	{'#', '#', '#', '.', '#', '#', '.', '#', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '#', '.', '#', '#', '.', '#', '#', '#'},
	{'#', '.', '.', '.', '.', '.', '.', '#', '#', '#', '#', '#', '#', '.', '.', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.', '#'},
	{'#', '@', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '@', '#'},
	{'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int playx;
int playy;
int ghost1x, ghost2x, ghost3x, ghost4x;
int ghost1y, ghost2y, ghost3y, ghost4y;
int health;
int xp;
int running;
int r;
int timer;

void startscreen();
void render();
char quickchar(float delay);
void bold_cyan();
void red();
void yellow();
void cyan();
void magenta();
void pink();
void orange();
void blue();
void blink();
void reset_blink();
void reset();

int main() {

	char direction;
	char input;
	char c,y,x;

	startscreen();

	blink();
	printf("          Push Y to play: ", input);
	scanf(" %c", &input);
	reset_blink();

	if(input == 'Y' || input == 'y') {

		render();

		srand( time(0));

		health = 100;
		xp = 0;
		running = 1;

		playy = 26;
		playx = 15;
		ghost1y = 11;
		ghost1x = 14;
		ghost2y = 11;
		ghost2x = 18;
		ghost3y = 13;
		ghost3x = 14;
		ghost4y = 13;
		ghost4x = 18;

		system("stty -echo raw");

		while(running == 1) {

			render();

			if (playy == ghost1y && playx == ghost1x ||
				playy == ghost2y && playx == ghost2x ||
				playy == ghost3y && playx == ghost3x ||
				playy == ghost4y && playx == ghost4x) {
				health -= 25;
				gb[playy][playx] == ' ';
			} else if (health<25){
				yellow();
				printf("  _____                        _____                _ \r\n");
				printf(" |  __ \\                      |  _  |              | | \r\n");
				printf(" | |  \\/ __ _ _ __ ___   ___  | | | |_   _____ _ __| | \r\n");
				printf(" | | __ / _` | '_ ` _  \\/ _ \\ | | | \\ \\ / / _ \\ '__| | \r\n");
				printf(" | |_\\ \\ (_| | | | | | |  __/ \\ \\_/ /\\ V /  __/ |  |_| \r\n");
				printf("  \\____/\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|  (_) \r\n");
				reset();
				return 0;
			}else if (gb[playy][playx] == '@') {
				gb[playy][playx] = ' ';
				timer = 200;

			} else if (gb[playy][playx] == gb[ghost2y][ghost2x]) {
				ghost2y = 11;
				ghost2x = 18;

			} else if (gb[playy][playx] == gb[ghost3y][ghost3x]) {
				ghost3y = 13;
				ghost3x = 14;

			} else if (gb[playy][playx] == gb[ghost4y][ghost4x]) {
				ghost4y = 13;
				ghost4x = 18;

			} else if (gb[playy][playx] == '.') {
				xp += 25;
				gb[playy][playx] = ' ';
			}

		if (gb[25][1] != '@') {

			if (playy == ghost1y && playx == ghost1x && timer > 0) {
				health = 100;
			} else if (playy == ghost2y && playx == ghost2x && timer > 0) {
				health = 100;
			} else if (playy == ghost3y && playx == ghost3x && timer > 0) {
				health = 100;
			} else if (playy == ghost4y && playx == ghost4x && timer > 0) {
				health = 100;
			}

			if (playy == ghost1y && playx == ghost1x ) {
				ghost1y = 11;
				ghost1x = 14;
			} else if (playy == ghost2y && playx == ghost2x ) {
				ghost2y = 11;
				ghost2x = 18;
			} else if (playy == ghost3y && playx == ghost3x ) {
				ghost3y = 13;
				ghost3x = 14;
			} else if (playy == ghost4y && playx == ghost4x ) {
				ghost4y = 13;
				ghost4x = 18;
				}
		}

		if (gb[3][1] != '@') {

			if (playy == ghost1y && playx == ghost1x && timer > 0) {
				health = 100;
			} else if (playy == ghost2y && playx == ghost2x && timer > 0) {
				health = 100;
			} else if (playy == ghost3y && playx == ghost3x && timer > 0) {
				health = 100;
			} else if (playy == ghost4y && playx == ghost4x && timer > 0) {
				health = 100;
			}

			if (playy == ghost1y && playx == ghost1x ) {
				ghost1y = 11;
				ghost1x = 14;
			} else if (playy == ghost2y && playx == ghost2x ) {
				ghost2y = 11;
				ghost2x = 18;
			} else if (playy == ghost3y && playx == ghost3x ) {
				ghost3y = 13;
				ghost3x = 14;
			} else if (playy == ghost4y && playx == ghost4x ) {
				ghost4y = 13;
				ghost4x = 18;
			}

		}

		if (gb[4][30] != '@') {
			if (playy == ghost1y && playx == ghost1x && timer > 0) {
				health = 100;
			} else if (playy == ghost2y && playx == ghost2x && timer > 0) {
				health = 100;
			} else if (playy == ghost3y && playx == ghost3x && timer > 0) {
				health = 100;
			} else if (playy == ghost4y && playx == ghost4x && timer > 0) {
				health = 100;
			}

			if (playy == ghost1y && playx == ghost1x ) {
				ghost1y = 11;
				ghost1x = 14;
			} else if (playy == ghost2y && playx == ghost2x ) {
				ghost2y = 11;
				ghost2x = 18;
			} else if (playy == ghost3y && playx == ghost3x ) {
				ghost3y = 13;
				ghost3x = 14;
			} else if (playy == ghost4y && playx == ghost4x ) {
				ghost4y = 13;
				ghost4x = 18;
			}

		}

		if (gb[25][30] != '@') {

			if (playy == ghost1y && playx == ghost1x && timer > 0) {
				health = 100;
			} else if (playy == ghost2y && playx == ghost2x && timer > 0) {
				health = 100;
			} else if (playy == ghost3y && playx == ghost3x && timer > 0) {
				health = 100;
			} else if (playy == ghost4y && playx == ghost4x && timer > 0) {
				health = 100;
			}

			if (playy == ghost1y && playx == ghost1x ) {
				ghost1y = 11;
				ghost1x = 14;
			} else if (playy == ghost2y && playx == ghost2x ) {
				ghost2y = 11;
				ghost2x = 18;
			} else if (playy == ghost3y && playx == ghost3x ) {
				ghost3y = 13;
				ghost3x = 14;
			} else if (playy == ghost4y && playx == ghost4x ) {
				ghost4y = 13;
				ghost4x = 18;
			}

		}

		if(gb[1][1] != '.' && gb[1][2] != '.' && gb[1][3] != '.' && gb[1][4] != '.' && gb[1][5] != '.' && gb[1][6] != '.' &&
		   gb[1][7] != '.' && gb[1][8] != '.' && gb[1][9] != '.' && gb[1][10] != '.' && gb[1][11] != '.' && gb[1][12] != '.' &&
		   gb[1][13] != '.' && gb[1][14] != '.' && gb[1][17] != '.' && gb[1][18] != '.' && gb[1][19] != '.' && gb[1][20] != '.' &&
		   gb[1][21] != '.' && gb[1][22] != '.' && gb[1][23] != '.' && gb[1][24] != '.' && gb[1][25] != '.' && gb[1][26] != '.' &&
		   gb[1][27] != '.' && gb[1][28] != '.' && gb[1][29] != '.' && gb[1][30] != '.' && gb[2][1] != '.' && gb[2][6] != '.' &&
		   gb[2][14] != '.' && gb[2][17] != '.' && gb[2][25] != '.' && gb[2][30] != '.' && gb[3][1] != '@' && gb[3][6] != '.' &&
		   gb[3][14] != '.' && gb[3][17] != '.' && gb[3][25] != '.' && gb[3][30] != '.' && gb[4][1] != '.' && gb[4][6] != '.' &&
		   gb[4][14] != '.' && gb[4][17] != '.' && gb[4][25] != '.' && gb[4][30] != '@' && gb[5][1] != '.' && gb[5][2] != '.' &&
		   gb[5][5] != '.' && gb[5][6] != '.' && gb[5][7] != '.' && gb[5][8] != '.' && gb[5][9] != '.' && gb[5][10] != '.' &&
		   gb[5][11] != '.' && gb[5][12] != '.' && gb[5][13] != '.' && gb[5][15] != '.' && gb[5][15] != '.' && gb[5][16] != '.' &&
           gb[5][17] != '.' && gb[5][18] != '.' && gb[5][19] != '.' && gb[5][20] != '.' && gb[5][21] != '.' && gb[5][22] != '.' &&
		   gb[5][23] != '.' && gb[5][24] != '.' && gb[5][25] != '.' && gb[5][26] != '.' && gb[5][27] != '.' && gb[5][28] != '.' &&
		   gb[5][29] != '.' && gb[5][30] != '.' && gb[6][1] != '.' && gb[6][6] != '.' && gb[6][8] != '.' && gb[6][23] != '.' &&
		   gb[6][25] != '.' && gb[6][30] != '.' && gb[7][1] != '.' && gb[7][2] != '.' && gb[7][3] != '.' && gb[7][4] != '.' &&
	       gb[7][5] != '.' && gb[7][6] != '.' && gb[7][8] != '.' && gb[7][9] != '.' && gb[7][10] != '.' && gb[7][11] != '.' &&
	       gb[7][12] != '.' && gb[7][13] != '.' && gb[7][14] != '.' && gb[7][17] != '.' && gb[7][18] != '.' && gb[7][19] != '.' &&
	       gb[7][20] != '.' && gb[7][21] != '.' && gb[7][22] != '.' && gb[7][23] != '.' && gb[7][25] != '.' && gb[7][26] != '.' &&
	       gb[7][27] != '.' && gb[7][28] != '.' && gb[7][29] != '.' && gb[7][30] != '.' && gb[8][6] != '.' && gb[8][14] != '.' &&
	       gb[8][17] != '.' && gb[8][25] != '.' && gb[9][6] != '.' && gb[9][8] != '.' && gb[9][9] != '.' && gb[9][10] != '.' &&
		   gb[9][11] != '.' && gb[9][12] != '.' && gb[9][13] != '.' && gb[9][14] != '.' && gb[9][15] != '.' && gb[9][16] != '.' &&
		   gb[9][17] != '.' && gb[9][18] != '.' && gb[9][19] != '.' && gb[9][20] != '.' && gb[9][21] != '.' && gb[9][22] != '.' &&
		   gb[9][23] != '.' && gb[10][6] != '.' && gb[10][8] != '.' && gb[10][9] != '.' && gb[10][10] != '.' && gb[10][11] != '.' &&
		   gb[10][21] != '.' && gb[10][22] != '.' && gb[10][23] != '.' && gb[10][25] != '.' && gb[11][6] != '.' && gb[11][8] != '.' &&
		   gb[11][9] != '.' && gb[11][10] != '.' && gb[11][11] != '.' && gb[11][21] != '.' && gb[11][22] != '.' && gb[11][23] != '.' &&
           gb[11][25] != '.' && gb[12][6] != '.' && gb[12][8] != '.' && gb[12][9] != '.' && gb[12][10] != '.' && gb[12][11] != '.' &&
		   gb[12][21] != '.' && gb[12][22] != '.' && gb[12][23] != '.' && gb[12][25] != '.' && gb[13][6] != '.' && gb[13][8] != '.' &&
		   gb[13][9] != '.' && gb[13][10] != '.' && gb[13][11] != '.' && gb[13][21] != '.' && gb[13][22] != '.' && gb[13][23] != '.' &&
		   gb[13][25] != '.' && gb[14][6] != '.' && gb[14][8] != '.' && gb[14][9] != '.' && gb[14][10] != '.' && gb[14][11] != '.' &&
		   gb[14][21] != '.' && gb[14][22] != '.' && gb[14][23] != '.' && gb[14][25] != '.' && gb[15][6] != '.' && gb[15][8] != '.' &&
		   gb[15][9] != '.' && gb[15][10] != '.' && gb[15][11] != '.' && gb[15][21] != '.' && gb[15][22] != '.' && gb[15][23] != '.' &&
		   gb[15][25] != '.' && gb[16][6] != '.' && gb[16][8] != '.' && gb[16][9] != '.' && gb[16][10] != '.' && gb[16][11] != '.' &&
		   gb[16][12] != '.' && gb[16][13] != '.' && gb[16][14] != '.' && gb[16][15] != '.' && gb[16][16] != '.' && gb[16][17] != '.' &&
		   gb[16][18] != '.' && gb[16][19] != '.' && gb[16][20] != '.' && gb[16][21] != '.' && gb[16][22] != '.' && gb[16][23] != '.' &&
		   gb[16][25] != '.' && gb[17][6] != '.' && gb[17][8] != '.' && gb[17][23] != '.' && gb[17][25] != '.' && gb[18][1] != '.' &&
		   gb[18][2] != '.' && gb[18][3] != '.' && gb[18][4] != '.' && gb[18][5] != '.' && gb[18][6] != '.' && gb[18][7] != '.' &&
		   gb[18][8] != '.' && gb[18][9] != '.' && gb[18][10] != '.' && gb[18][11] != '.' && gb[18][12] != '.' && gb[18][13] != '.' &&
		   gb[18][14] != '.' && gb[18][17] != '.' && gb[18][18] != '.' && gb[18][19] != '.' && gb[18][20] != '.' && gb[18][21] != '.' &&
		   gb[18][22] != '.' && gb[18][23] != '.' && gb[18][24] != '.' && gb[18][25] != '.' && gb[18][26] != '.' && gb[18][27] != '.' &&
		   gb[18][28] != '.' && gb[18][29] != '.' && gb[18][30] != '.' && gb[19][1] != '.' && gb[19][6] != '.' && gb[19][14] != '.' &&
		   gb[19][17] != '.' && gb[19][25] != '.' && gb[19][30] != '.' && gb[20][1] != '.' && gb[20][6] != '.' && gb[20][7] != '.' &&
		   gb[20][8] != '.' && gb[20][9] != '.' && gb[20][10] != '.' && gb[20][11] != '.' && gb[20][12] != '.' && gb[20][13] != '.' &&
		   gb[20][14] != '.' && gb[20][15] != '.' && gb[20][16] != '.' && gb[20][17] != '.' && gb[20][18] != '.' && gb[20][19] != '.' &&
		   gb[20][20] != '.' && gb[20][21] != '.' && gb[20][22] != '.' && gb[20][23] != '.' && gb[20][24] != '.' && gb[20][25] != '.' &&
		   gb[20][30] != '.' && gb[21][1] != '.' && gb[21][2] != '.' && gb[21][3] != '.' && gb[21][6] != '.' && gb[21][8] != '.' &&
		   gb[21][23] != '.' && gb[21][25] != '.' && gb[21][28] != '.' && gb[21][29] != '.' && gb[21][30] != '.' && gb[22][1] != '.' &&
		   gb[22][2] != '.' && gb[22][3] != '.' && gb[22][6] != '.' && gb[22][8] != '.' && gb[22][23] != '.' && gb[22][25] != '.' &&
		   gb[22][28] != '.' && gb[22][29] != '.' && gb[22][30] != '.' && gb[23][3] != '.' && gb[23][6] != '.' && gb[23][8] != '.' &&
		   gb[23][9] != '.' && gb[23][10] != '.' && gb[23][11] != '.' && gb[23][12] != '.' && gb[23][13] != '.' && gb[23][18] != '.' &&
		   gb[23][19] != '.' && gb[23][20] != '.' && gb[23][21] != '.' && gb[23][22] != '.' && gb[23][23] != '.' && gb[23][25] != '.' &&
		   gb[23][28] != '.' && gb[24][1] != '.' && gb[24][2] != '.' && gb[24][3] != '.' && gb[24][4] != '.' && gb[24][5] != '.' &&
		   gb[24][6] != '.' && gb[24][13] != '.' && gb[24][14] != '.' && gb[24][17] != '.' && gb[24][18] != '.' && gb[24][25] != '.' &&
		   gb[24][26] != '.' && gb[24][27] != '.' && gb[24][28] != '.' && gb[24][29] != '.' && gb[24][30] != '.' && gb[25][1] != '.' &&
		   gb[25][14] != '.' && gb[25][15] != '.' && gb[25][16] != '.' && gb[25][17] != '.' && gb[25][30] != '.' && gb[26][1] != '.' &&
		   gb[26][2] != '.' && gb[26][3] != '.' && gb[26][4] != '.' && gb[26][5] != '.' && gb[26][6] != '.' && gb[26][7] != '.' &&
		   gb[26][8] != '.' && gb[26][9] != '.' && gb[26][10] != '.' && gb[26][11] != '.' && gb[26][12] != '.' && gb[26][13] != '.' &&
		   gb[26][14] != '.' && gb[26][15] != '.' && gb[26][16] != '.' && gb[26][17] != '.' && gb[26][18] != '.' && gb[26][19] != '.' &&
		   gb[26][20] != '.' && gb[26][21] != '.' && gb[26][22] != '.' && gb[26][23] != '.' && gb[26][24] != '.' && gb[26][25] != '.' &&
		   gb[26][26] != '.' && gb[26][27] != '.' && gb[26][28] != '.' && gb[26][29] != '.' && gb[26][30] != '.') {

		   yellow();
		   printf(" __     __          __          __         _ \r\n");
		   printf(" \\ \\   / /          \\ \\        / /        | | \r\n");
		   printf("  \\ \\_/ /__  _   _   \\ \\  /\\  / /__  _ __ | | \r\n");
		   printf("   \\   / _ \\| | | |   \\ \\/  \\/ / _ \\| '_ \\| | \r\n");
		   printf("    | | (_) | |_| |    \\  /\\  / (_) | | | |_| \r\n");
		   printf("    |_|\\___/ \\__,_|     \\/  \\/ \\___/|_| |_(_) \r\n");
		   reset();
			return 0;
	}

		direction = quickchar(0.1);

		if (direction == 'a' && playy == 12 && playx == 0)  {
			playy = 12;
			playx = 31;
		} else if (direction == 'd' && playy == 12 && playx == 31) {
			playy = 12;
			playx = 0;
		} else if (direction == 'w' && gb[playy -1][playx] != '#'){
			playy--;
		} else if (direction == 'a' && gb[playy][playx - 1] != '#'){
			playx--;
		} else if (direction == 's' && gb[playy + 1][playx] != '#'){
			playy++;
		} else if (direction == 'd' && gb[playy][playx + 1] != '#'){
			playx++;
		} else if (direction == 'x'){
			running = 0;
		}

		r = rand() % 16;
		//moving ghost1 up
		if (r == 0) {
			if (gb[ghost1y-1][ghost1x] != '#') {
				ghost1y--;
			}
		} else if (r == 1) {
		//moing ghost1 down
			if (gb[ghost1y+1][ghost1x] != '#') {
				ghost1y++;
			}
		} else if (r == 2) {
		//moving ghost1 left
			if (gb[ghost1y][ghost1x-1] != '#') {
				ghost1x--;
			}
		} else if (r == 3) {
		//moving ghost1 right
		if (gb[ghost1y][ghost1x+1] != '#') {
				ghost1x++;
			}
		}
		//moving ghost2 up
		if (r == 4) {
			if (gb[ghost2y-1][ghost2x] != '#') {
				ghost2y--;
			}
		} else if (r == 5) {
		//moing ghost2 down
			if (gb[ghost2y+1][ghost2x] != '#') {
				ghost2y++;
			}
		} else if (r == 6) {
		//moving ghost2 left
			if (gb[ghost2y][ghost2x-1] != '#') {
				ghost2x--;
			}
		} else if (r == 7) {
		//moving ghost2 right
		if (gb[ghost2y][ghost2x+1] != '#') {
				ghost2x++;
			}
		}
		//moving ghost3 up
		if (r == 8) {
			if (gb[ghost3y-1][ghost3x] != '#') {
				ghost3y--;
			}
		} else if (r == 9) {
		//moing ghost3 down
			if (gb[ghost3y+1][ghost3x] != '#') {
				ghost3y++;
			}
		} else if (r == 10) {
		//moving ghost3 left
			if (gb[ghost3y][ghost3x-1] != '#') {
				ghost3x--;
			}
		} else if (r == 11) {
		//moving ghost3 right
		if (gb[ghost3y][ghost3x+1] != '#') {
				ghost3x++;
			}
		}
		//moving ghost4 up
		if (r == 12) {
			if (gb[ghost4y-1][ghost4x] != '#') {
				ghost4y--;
			}
		} else if (r == 13) {
		//moing ghost4 down
			if (gb[ghost4y+1][ghost4x] != '#') {
				ghost4y++;
			}
		} else if (r == 14) {
		//moving ghost4 left
			if (gb[ghost4y][ghost4x-1] != '#') {
				ghost4x--;
			}
		} else if (r == 15) {
		//moving ghost4 right
		if (gb[ghost4y][ghost4x+1] != '#') {
				ghost4x++;
			}
		}
}

} else if(input == 'N' || input == 'n') {
		return 0;
	}

	return 0;
}

void startscreen() {

	int x, y;

	system("clear");


	yellow();
	printf("  _____                  __  __              \r\n");
	printf(" |  __ \\                |  \\/  |             \r\n");
	printf(" | |__) |_ _  ___ ______| \\  / | __ _ _ __   \r\n");
	printf(" |  ___/ _` |/ __|______| |\\/| |/ _` | '_ \\ \r\n");
	printf(" | |  | (_| | (__       | |  | | (_| || | | \r\n");
	printf(" |_|  \\__,_|\\___|       |_|  |_|\\_,_|_| |_| \r\n");
	printf("\n");
	reset();

	yellow();
	printf("      __________________|       \r\n");
	printf("           ,--.    ,--.         \r\n");
	printf("          |oo  | _  \\  `.      \r\n");
	printf("      o  o|~~  |(_) /   ;       \r\n");
	printf("          |/\\/\\    '._,'       \r\n");
	printf("      __________________        \r\n");
	printf("                        |      \r\n");
	reset();


	printf("    [HEALTH : %d ] [xp : %d ]\r\n", health, xp);

	for(y=0; y<28; y++) {
		for (x=0; x<32; x++){

			playy = 26;
			playx = 15;
			ghost1y = 11;
			ghost1x = 14;
			ghost2y = 11;
			ghost2x = 18;
			ghost3y = 13;
			ghost3x = 14;
			ghost4y = 13;
			ghost4x = 18;

			if (y == playy && x == playx && y) {
				yellow();
				printf("0");
				reset();
			} else if(ghost1y == y && ghost1x == x){
				red();
                printf("G");
				reset();
			} else if(ghost2y == y && ghost2x == x){
                pink();
				printf("G");
				reset();
			} else if(ghost3y == y && ghost3x == x){
				orange();
                printf("G");
				reset();
			} else if(ghost4y == y && ghost4x == x){
				bold_cyan();
                printf("G");
				reset();
			} else if(gb[y][x] == '#'){
				bold_cyan();
				printf("%c", gb[y][x]);
				reset();
			} else {
				printf("%c", gb[y][x]);
			}
		}
		printf("\r\n");
	}

	yellow();
	printf(" |______________________________\r\n");
	printf("    ,--.   ,--.                                 \r\n");
	printf("   | oo | |  oo|                                \r\n");
	printf("   | ~~ | |  ~~|o  o  o  o  o   \r\n");
	printf("   |/\\/\\| |/\\/\\|               \r\n");
	printf(" _______________________________\r\n");
	printf(" |dwb                             \r\n");
	reset();

	printf("Ues w/a/s/d to move around the board.\n");
	printf("          Push x to exit.\n");

}

void render() {

	int x, y;

	system("clear");

	yellow();
	printf("  _____                  __  __              \r\n");
	printf(" |  __ \\                |  \\/  |             \r\n");
	printf(" | |__) |_ _  ___ ______| \\  / | __ _ _ __   \r\n");
	printf(" |  ___/ _` |/ __|______| |\\/| |/ _` | '_ \\ \r\n");
	printf(" | |  | (_| | (__       | |  | | (_| || | | \r\n");
	printf(" |_|  \\__,_|\\___|       |_|  |_|\\_,_|_| |_| \r\n");
	printf("\n");
	reset();

	yellow();
	printf("      __________________|       \r\n");
	printf("           ,--.    ,--.         \r\n");
	printf("          |oo  | _  \\  `.      \r\n");
	printf("      o  o|~~  |(_) /   ;       \r\n");
	printf("          |/\\/\\    '._,'       \r\n");
	printf("      __________________        \r\n");
	printf("                        |      \r\n");
	reset();

	printf("    [HEALTH : %d ] [xp : %d ] \r\n", health, xp);

	if(timer >= 0) {
		timer--;
	}

	for(y=0; y<28; y++) {
		for (x=0; x<32; x++){
			if (y == playy && x == playx) {
				yellow();
				printf("0");
				reset();
			} else if(ghost1y == y && ghost1x == x && timer >= 0){
				magenta();
				printf("G");
				reset();
			} else if(ghost2y == y && ghost2x == x && timer >= 0){
				magenta();
                printf("G");
				reset();
			} else if(ghost3y == y && ghost3x == x && timer >= 0){
				magenta();
                printf("G");
				reset();
			} else if(ghost4y == y && ghost4x == x && timer >= 0){
				magenta();
                printf("G");
				reset();
			} else if(ghost1y == y && ghost1x == x){
				red();
				printf("G");
				reset();
			} else if(ghost2y == y && ghost2x == x){
				pink();
                printf("G");
				reset();
			} else if(ghost3y == y && ghost3x == x){
				orange();
                printf("G");
				reset();
			} else if(ghost4y == y && ghost4x == x){
				bold_cyan();
                printf("G");
				reset();
			} else if(gb[y][x] == '#'){
				bold_cyan();
				printf("%c", gb[y][x]);
				reset();
			} else {
				printf("%c", gb[y][x]);
			}
		}

		printf("\r\n");
}
	yellow();
	printf(" |______________________________\r\n");
	printf("    ,--.   ,--.                                 \r\n");
	printf("   | oo | |  oo|                                \r\n");
	printf("   | ~~ | |  ~~|o  o  o  o  o   \r\n");
	printf("   |/\\/\\| |/\\/\\|               \r\n");
	printf(" _______________________________\r\n");
	printf(" |dwb                             \r\n");
	reset();

}

char quickchar(float delay) {

     int flags;
     char c;

     usleep((int)(delay * 1000000));

     flags = fcntl(0, F_GETFL, 0);
     fcntl(0, F_SETFL, flags | O_NONBLOCK);
     c = getchar();
     fcntl(0, F_SETFL, flags ^ O_NONBLOCK);

     return c;
 }

void bold_cyan() {
	printf("\033[0;36m");
}

void red() {
	printf("\033[1;31m");
}

void yellow() {
	printf("\033[1;33m");
}

void cyan() {
	printf("\033[0;36m");
}

void magenta() {
	printf("\033[1;35m");
}

void pink() {
	printf("\033[38;5;219m");
}

void orange() {
	printf("\033[38;5;208m");
}

void blue() {
	printf("\033[94m");
}

void blink() {
	printf("\033[5m");
}

void reset_blink() {
	printf("\033[25m");
}

void reset() {
	printf("\033[0m");
}
austin.taylor@dev:~/csc150$ 
