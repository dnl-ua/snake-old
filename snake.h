struct Coords {
	public:
		int y;
		int x;
};

class Snake {
	public:
		int length;
		int direction = 1; // 1 - down, 2 - up, 3 - left, 4 - right;
		void increase() {
			Coords *temp = new Coords[length+1];
			for (int i = 0; i < length; i++) {
				temp[i] = coords[i];
			}
			coords = temp;
		}

		Coords *coords;

		Snake() {
			length = 4;
			coords = new Coords[4];
			coords[0] = {11, 10};
			coords[1] = {12, 10};
			coords[2] = {13,  10};
			coords[3] = {14,  10};
		}
};
