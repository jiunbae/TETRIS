#include "block.h"
shape newShape(int type)
{
	shape block;
	block.x = 0;
	block.y = 0;
	block.type = type;
	block.rotate = 0;
	return block;
}

bool applyMatrix(MATPTR matrix, shape block)
{
	bool valid = true;
	MATPTR blockMatrix = shapeToMatrix(block);
	for (int i = 0; i < 4; ++i)
		for (int j = 0; valid && j < 4; ++j)
			if ((*matrix)[i + block.y][j + block.x] ^ (*blockMatrix)[i][j])
				valid = false;
			else
				(*matrix)[i + block.y][j + block.x] = (*blockMatrix)[i][j];

	return valid;
}

MATPTR shapeToMatrix(shape block)
{
	MATRIX matrix = NULL;
	newMatrix(&matrix, 4, 4);
	for (int i = 0; i < 4; ++i)
		matrix[SHAPE_POINT[block.type][i].y][SHAPE_POINT[block.type][i].x] = block.type + 1;

	while (block.rotate--)
	{
		MATRIX temp = NULL;
		newMatrix(&temp, 4, 4);
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				temp[j][i] = matrix[i][j];

		delMatrix(&matrix, 4, 4);
		matrix = temp;
	}
	return &matrix;
}

shape rotate(shape block)
{
	block.rotate++;
	block.rotate %= 4;
	return block;
}

shape rRotate(shape block)
{
	block.rotate--;
	if (block.rotate == -1)
		block.rotate = 4;
	return block;
}
