#include <iostream>
#include <ctime> //necessary for random Numbers
#include <vector> //necessary for Snake Body
#include <deque> // deque is able to push from front and back unlike the vector

int main()
{	 

	// map 
	const int x = 20;
	const int y = 20;
	char map[x][y];
	char grid = '.';


	//Snake:

	int PosX = 13;
	int PosY = 15;
	char SnakeHead = '#';

	struct SnakeBody
	{
	public:
		char body = 'o';
		int SnakeBodyPosX;
		int SnakeBodyPosY;
	};

	std::vector<SnakeBody> snakeBody;
	std::deque<int> oldPosX;
	std::deque<int> oldPosY;

	//Apple
	int ApplePosX;
	int ApplePosY;
	char Apple = 'A';

	srand((unsigned)time(0)); 

	ApplePosX = (rand() % x);
	ApplePosY = (rand() % y);
	
	int GamePoints = 0;

	//Loop 
	bool playerMove = false;

	//Character
	char characterDirections;


	//Filling up map with dots
	for (int i = 0; i < y; i++)
	{

		for (int j = 0; j < x; j++)
		{
			map[i][j] = grid;
		}
	}

	while (!playerMove)
	{	 
		//drawing map
		for (int i = 0; i < y; i++)
		{

			for (int j = 0; j < x; j++)
			{
				
				if (i == PosY && j == PosX) // putting character in the correct position
				{
					map[i][j] = SnakeHead;
				}
				else if (i == ApplePosY && j == ApplePosX) // putting Apple in the correct position
				{
					map[i][j] = Apple;
				}
				else
				{
					map[i][j] = grid;
				}
				for (int k = 0; k < snakeBody.size(); k++)
				{
					if (i == snakeBody[k].SnakeBodyPosY && j == snakeBody[k].SnakeBodyPosX)
					{
						map[i][j] = snakeBody[k].body;
					}
				}
				std::cout << map[i][j];
			}
			std::cout << std::endl;
		}
		
		//1) vectro gets previous HeadPosition
		oldPosX.push_front(PosX);
		oldPosY.push_front(PosY);
		


		//Player Movement
		std::cin >> characterDirections;
		switch (characterDirections) //2) PosY & Pos X get changed
		{
		case 'w':
			PosY--;
			break;

		case 's':
			PosY++;
			break;

		case 'a':
			PosX--;
			break;

		case 'd':
			PosX++;
			break;

		default:
			break;
		}

		//3)
		for (int i = 0; i < snakeBody.size(); i++)
		{
			snakeBody[i].SnakeBodyPosX = oldPosX[i];
			snakeBody[i].SnakeBodyPosY = oldPosY[i];
		}
		
		

		//Apples
		if (PosX == ApplePosX && PosY == ApplePosY)
		{
			ApplePosX = (rand() % x);
			ApplePosY = (rand() % y);
			GamePoints++;
			snakeBody.push_back(SnakeBody());
		}
		
		std::cout << "Current GamePoints: " << GamePoints << std::endl;



		if (PosX < 0 || PosX >= x || PosY < 0 || PosY >= y) //check if head is over the map
		{
			playerMove = true; // GAME OVER
			std::cout << "GAME OVER\n";
		}

		for (int i = 0; i < snakeBody.size(); i++)
		{
			if (PosX == oldPosX[i] && PosY == oldPosY[i])
			{
				playerMove = true; // GAME OVER
				std::cout << "GAME OVER\n";
			}
		}
	}
}