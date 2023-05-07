
#include <iostream>

using namespace std;

int arr[20][20] = {};
int x = -1;
int y = 0;
int maxX = 0;
int maxY = 0;
int minX = -1;
int minY = -1;
int direction = 0;


// 방향을 바꾸면서 지나온길 소거
void Turn()
{
	switch (direction)
	{
	case 0:
		direction++;
		minX++;
		break;
	case 1:
		direction++;
		maxY--;
		break;
	case 2:
		direction++;
		maxX--;
		break;
	case 3:
		direction = 0;
		minY++;
		break;

	}
}

// turn값에 따라 좌표 한칸씩 이동
void Go()
{
	int dx = 1;
	int dy = 0;

	switch (direction)
	{
	case 0:
		dx = 1; dy = 0;
		break;
	case 1:
		dx = 0; dy = 1;
		break;
	case 2:
		dx = -1; dy = 0;
		break;
	case 3:
		dx = 0; dy = -1;
		break;
	}
	x += dx;
	y += dy;
}

//달팽이배열만들기
void Snailarr(int a)
{
	maxX = a;
	maxY = a;
	int printnum = 1;
	
	while (printnum <= a * a)
	{
		switch (direction)
		{
		case 0:
		{
			Go();
			arr[x][y] = printnum++;
			if (x == maxY - 1)
			{
				Turn();
			}
			break;

		}
		case 1:
		{
			Go();
			arr[x][y] = printnum++;
			if (y == maxX - 1)
				Turn();
			break;
		}
		case 2:
		{
			Go();
			arr[x][y] = printnum++;
			if (x == minY + 1)
				Turn();
			break;

		}
		case 3:
		{
			Go();
			arr[x][y] = printnum++;
			if (y == minX + 1)
			{
				Turn();
			}
			break;
		}
		}
	}
}

// 너비 4으로 맞추고 빈공간에 여백 넣기
ostream& blank(ostream& stream)
{
	stream.width(4);
	stream.fill(' ');
	return stream;
}

//출력
void printarr(int num)
{
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << blank << arr[j][i];
		}
		cout << endl;
	}
}



int main()
{
	while (true)
	{
		x = -1;
		y = 0;
		maxX = 0;
		maxY = 0;
		minX = -1;
		minY = -1;
		direction = 0;

		int width = 0;
		cout << "1~20의 정수를 입력하시오." << endl;
		cin >> width;
		Snailarr(width);
		printarr(width);

	}
	
	
}

