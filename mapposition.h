#ifndef MAPPOSITION_H
#define MAPPOSITION_H
struct MapPosition {
	int row;
	int col;

	MapPosition(int row, int col) {
		this->row = row;
		this->col = col;
	}

	bool operator ==(MapPosition other) {
		return other.col == col && other.row == row;
	}

	bool operator !=(MapPosition other) {
		return other.col != col || other.row != row;
	}
};

#endif // MAPPOSITION_H
