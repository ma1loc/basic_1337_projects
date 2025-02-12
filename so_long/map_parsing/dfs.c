#include "../src_so_long/so_long.h"

// here the algo of the flood fill algorithm
// Breadth First Search (BFS)

// find the {row & col}
t_position	*finding_player_position(char **map)
{
	int			i;
	int			j;
	t_position	*row_and_col;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				row_and_col = put_row_and_col(i, j);
				if (!row_and_col)
        			cleanup_and_exit("Error\nAllocation faild.", map);
				return (row_and_col);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

// up, down, left, right
// valid think so! (is checkd)
void	up(char **copy_of_map, t_position *position, int *collectors, int *exit)
{
	while (copy_of_map[position->row][position->col] != '1')
	{
		if (copy_of_map[position->row][position->col] == 'P' \
		|| copy_of_map[position->row][position->col] == '0' \
		|| copy_of_map[position->row][position->col] == 'C' \
		|| copy_of_map[position->row][position->col] == 'E' \
		|| copy_of_map[position->row][position->col] == 'X')
		{
			if (copy_of_map[position->row][position->col] == 'C')
				(*collectors)++;
			if (copy_of_map[position->row][position->col] == 'E')
				(*exit) = 1;
			if (copy_of_map[position->row][position->col] != 'X')
				copy_of_map[position->row][position->col] = 'X';
		}
		if (copy_of_map[position->row - 1][position->col] == '1')
			return ;
		position->row--;
	}
}

// not valid have some thing on it! -> check it?
void	down(char **copy_of_map, t_position *position, int *collectors, int *exit)
{
	while (copy_of_map[position->row][position->col] != '1')
	{
		if (copy_of_map[position->row][position->col] == 'P' \
		|| copy_of_map[position->row][position->col] == '0' \
		|| copy_of_map[position->row][position->col] == 'C' \
		|| copy_of_map[position->row][position->col] == 'E' \
		|| copy_of_map[position->row][position->col] == 'X')
		{
			if (copy_of_map[position->row][position->col] == 'C')
				(*collectors)++;
			if (copy_of_map[position->row][position->col] == 'E')
				(*exit) = 1;
			if (copy_of_map[position->row][position->col] != 'X')
				copy_of_map[position->row][position->col] = 'X';
		}
		position->row++;
	}
}
void	left(char **copy_of_map, t_position *position, int *collectors, int *exit)
{
	while (position->col != 0)
	{
		if (copy_of_map[position->row][position->col] == 'P' \
		|| copy_of_map[position->row][position->col] == '0' \
		|| copy_of_map[position->row][position->col] == 'C' \
		|| copy_of_map[position->row][position->col] == 'E' \
		|| copy_of_map[position->row][position->col] == 'X')
		{
			if (copy_of_map[position->row][position->col] == 'C')
				(*collectors)++;
			if (copy_of_map[position->row][position->col] == 'E')
				(*exit) = 1;
			if (copy_of_map[position->row][position->col] != 'X')
				copy_of_map[position->row][position->col] = 'X';
		}
		else if (copy_of_map[position->row][position->col + 1] == '1')
			return ;
		position->col--;
	}
}


void	right(char **copy_of_map, t_position *position, int *collectors, int *exit)
{
	while (copy_of_map[position->row][position->col] != '1')
	{
		if (copy_of_map[position->row][position->col] == 'P' \
		|| copy_of_map[position->row][position->col] == '0' \
		|| copy_of_map[position->row][position->col] == 'C' \
		|| copy_of_map[position->row][position->col] == 'E' \
		|| copy_of_map[position->row][position->col] == 'X')
		{
			if (copy_of_map[position->row][position->col] == 'C')
				(*collectors)++;
			if (copy_of_map[position->row][position->col] == 'E')
				(*exit) = 1;
			if (copy_of_map[position->row][position->col] != 'X')
				copy_of_map[position->row][position->col] = 'X';
		}
		if (copy_of_map[position->row][position->col + 1] == '1')
			return ;
		position->col++;
	}
}

// walk thgout the map and check if the map has free space to walk. empliment BFS
void	map_tracking(char **copy_of_map, t_position *position)
{
	int collectors;
	int	exit;

	collectors = 0;
	exit = 0;

	// test the map move (up, down, left, right).
	// up	 -> not valid
	// down  -> valid
	// left	 ->
	// right ->
	// printf("\nThis is the before position of the player\nrow -> %d\ncol -> %d\n", position->row, position->col);

	down(copy_of_map, position, &collectors, &exit);
	right(copy_of_map, position, &collectors, &exit);
	up(copy_of_map, position, &collectors, &exit);

	int i = 0;
	while (copy_of_map[i])
	{
		printf("%s", copy_of_map[i]);
		i++;
	}

	// printf("\nThis is the after position of the player\nrow -> %d\ncol -> %d\n", position->row, position->col);

}
