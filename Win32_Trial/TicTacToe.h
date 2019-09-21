// necessary header_guard
#pragma once
#ifndef HEADER_GUARD
#define HEADER_GUARD

class Game
{
public:
	Game();
	~Game();

	// delete copy & move functionality -> avoid copying bugs
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(const Game&&) = delete;
	Game&& operator=(const Game&&) = delete;

	// declaration of member functions	(inline)
	inline void instruct() const;
	inline void repeatedError() const;
	inline void turn() const;
	inline bool noRepeat(int i) const;
	inline void refresh() const;

	// declaration of member functions (non-inline)
	bool checkGame() const;
	void display() const;
	void gameStart();
	void select();

private:
	// map[0] should be ignored, use map[1] ~ map[9] to represent the gameboard 
	char map[11];
	char currentPlayer;
};

#endif // !HEADER_GUARD