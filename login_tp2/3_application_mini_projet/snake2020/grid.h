#define NBL 8
#define NBC 6

void debug(char matrix[NBL][NBC + 1]);
int compute_size(int w, int h);
void draw_grid(char grid[NBL][NBC + 1]);
enum Element
{
    WALL = 'b',
    EMPTY = 'w',
    FRUIT = 'r'
};