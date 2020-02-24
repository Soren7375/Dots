#pragma once

int find_o(int grid1[30][30])
{
	int grid[30][30];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			grid[i][j] = grid1[i][j];
	int o=0,real_o=0;
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
		{
			if (grid[i][j] == 1)
			{
				o++;
				for (int k = 1; k < 5; k++)
					if (grid[i + k][j] == 1)
						o++;
			}
			if (o == 5)
			{
				for (int k = 0; k < 5; k++)
					grid[i + k][j] = 0;
				o = 0;
				real_o++;
			}
			else
				o = 0;
		}

	int grid2[30][30];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			grid2[i][j] = grid1[i][j];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
		{
			if (grid2[i][j] == 1)
			{
				o++;
				for (int k = 1; k < 5; k++)
					if (grid2[i][j + k] == 1)
						o++;
			}
			if (o == 5)
			{
				for (int k = 0; k < 5; k++)
					grid2[i][j + k] = 0;
				o = 0;
				real_o++;
			}
			else
				o = 0;
		}

	int grid3[30][30];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			grid3[i][j] = grid1[i][j];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
		{
			if (grid3[i][j] == 1)
			{
				o++;
				for (int k = 1; k < 5; k++)
					if (grid3[i + k][j + k] == 1)
						o++;
			}
			if (o == 5)
			{
				for (int k = 0; k < 5; k++)
					grid3[i + k][j + k] = 0;
				o = 0;
				real_o++;
			}
			else
				o = 0;
		}

	int grid4[30][30];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			grid4[i][j] = grid1[i][j];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
		{
			if (grid4[i][j] == 1)
			{
				o++;
				for (int k = 1; k < 5; k++)
					if (grid4[i - k][j + k] == 1)
						o++;
			}
			if (o == 5)
			{
				for (int k = 0; k < 5; k++)
					grid4[i - k][j + k] = 0;
				o = 0;
				real_o++;
			}
			else
				o = 0;
		}

	return real_o;
}

int find_b(int grid1[30][30])
{
	int grid[30][30];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			grid[i][j] = grid1[i][j];
	int o = 0, real_o = 0;
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
		{
			if (grid[i][j] == 2)
			{
				o++;
				for (int k = 1; k < 5; k++)
					if (grid[i + k][j] == 2)
						o++;
			}
			if (o == 5)
			{
				for (int k = 0; k < 5; k++)
					grid[i + k][j] = 0;
				o = 0;
				real_o++;
			}
			else
				o = 0;
		}

	int grid2[30][30];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			grid2[i][j] = grid1[i][j];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
		{
			if (grid2[i][j] == 2)
			{
				o++;
				for (int k = 1; k < 5; k++)
					if (grid2[i][j + k] == 2)
						o++;
			}
			if (o == 5)
			{
				for (int k = 0; k < 5; k++)
					grid2[i][j + k] = 0;
				o = 0;
				real_o++;
			}
			else
				o = 0;
		}

	int grid3[30][30];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			grid3[i][j] = grid1[i][j];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
		{
			if (grid3[i][j] == 2)
			{
				o++;
				for (int k = 1; k < 5; k++)
					if (grid3[i + k][j + k] == 2)
						o++;
			}
			if (o == 5)
			{
				for (int k = 0; k < 5; k++)
					grid3[i + k][j + k] = 0;
				o = 0;
				real_o++;
			}
			else
				o = 0;
		}

	int grid4[30][30];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
			grid4[i][j] = grid1[i][j];
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
		{
			if (grid4[i][j] == 2)
			{
				o++;
				for (int k = 1; k < 5; k++)
					if (grid4[i - k][j + k] == 2)
						o++;
			}
			if (o == 5)
			{
				for (int k = 0; k < 5; k++)
					grid4[i - k][j + k] = 0;
				o = 0;
				real_o++;
			}
			else
				o = 0;
		}

	return real_o;
}
