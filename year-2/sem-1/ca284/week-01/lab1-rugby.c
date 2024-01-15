#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int try_points = atoi(argv[1]);
    int conversion_points = atoi(argv[2]);
    int penalty_points = atoi(argv[3]);
    int drop_goal_points = atoi(argv[4]);

    int total_points = (try_points * 5) + (conversion_points * 2) + (penalty_points * 3) + (drop_goal_points * 3);

    printf("%d\n", total_points);

    return 0;
}