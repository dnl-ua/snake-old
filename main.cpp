#include <ncurses.h>
#include <unistd.h>
#include <locale.h>
#include <random>
#include "board.h"

void printn(Board, int);
int generate_random_number();

int main()
{
	setlocale(LC_ALL, "");

	initscr();
	curs_set(false);
	clear();
	noecho();
	cbreak();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	refresh();

	Board b;
	Snake *s = nullptr;
	s = b.start();

	int c;
	int direction = 1;
	while (b.move(s, direction)) {
		c = wgetch(stdscr);

		if (!(b.fruit)) {
			b.generate_fruit(generate_random_number(), generate_random_number());
		}

		switch (c) {
			case KEY_UP:
				if (direction != 1 && direction != 2)
					direction = 1;
				usleep(50000);
				break;
			case KEY_DOWN:
				if (direction != 2 && direction != 1)
					direction = 2;
				usleep(50000);
				break;
			case KEY_LEFT:
				if (direction != 3 && direction != 4)
					direction = 3;
				usleep(50000);
				break;
			case KEY_RIGHT:
				if (direction != 4 && direction != 3)
					direction = 4;
				usleep(50000);
				break;
			case 'q':
				endwin();
				return 0;
				break;
			default:
				break;
		}
		clear();
		printn(b, s->length);
		refresh();
		usleep(150000);
	}

	nodelay(stdscr, false);
	printw("\n\nYou lost\n");
	printw("Press anything to leave\n");
	wgetch(stdscr);
	clear();
	refresh();
	endwin();

	return 0;
}

void printn(Board b, int length) {
	printw("+=========================================+\n");
	for (int i = 1; i < 21; i++) {
		printw("| ");
		for (int o = 1; o < 21; o++) {
			if (!(b.board[i][o])) {
				printw(". ");
			} else if (b.board[i][o] == 1) {
				printw("■ ");
			} else if (b.board[i][o] == 2) {
				printw("o ");
			}
		}
		printw("|\n");
	}
	printw("+=========================================+\n");
	printw("Snake length: %d\n", length);
}

int generate_random_number() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);

	return dist(rng);
}
