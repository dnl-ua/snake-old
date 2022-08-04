#include "board.h"

Snake *Board::start() {
	Snake *s = new Snake();
	set_snake_coords(*s, 1);

	return s;
}

void Board::generate_fruit(int y, int x) {
	if (board[y][x] != 1) {
		board[y][x] = 2;
		fruit = 1;
	}
}

void Board::set_snake_coords(Snake s, int value) {
	for (int i = 0; i < s.length; i++) {
		board[s.coords[i].y][s.coords[i].x] = value;
	}
}

bool Board::move(Snake *s, int direction) {
	set_snake_coords(*s, 0);
	Coords temp = {s->coords[0].y, s->coords[0].x};
	switch (direction) {
		case 1: // up
			if (s->coords[0].y-1 == 0) {
				s->coords[0].y = 20;
			} else {
				s->coords[0].y -= 1;
			}
			break;
		case 2: // down
			if (s->coords[0].y+1 == 21) {
				s->coords[0].y = 1;
			} else {
				s->coords[0].y += 1;
			}
			break;
		case 3: // left
			if (s->coords[0].x-1 == 0) {
				s->coords[0].x = 20;
			} else {
				s->coords[0].x -= 1;
			}
			break;
		case 4: // right
			if (s->coords[0].x+1 == 21) {
				s->coords[0].x = 1;
			} else {
				s->coords[0].x += 1;
			}
			break;
		default:
			break;
	}

	for (int i = s->length-1; i > 1; i--) {
		if (s->coords[0].y == s->coords[i].y &&
		    s->coords[0].x == s->coords[i].x) {
			return 0;
		}
		s->coords[i] = s->coords[i-1];
	}
	s->coords[1] = temp;
	s->direction = direction;
	if (board[s->coords[0].y][s->coords[0].x] == 2) {
		if (s->length >= 11) {
			s->increase();
		}
		s->coords[s->length] = {s->coords[s->length-1].y, s->coords[s->length-1].x};
		s->length += 1;
		fruit = 0;
	}
	set_snake_coords(*s, 1);

	return 1;
}
