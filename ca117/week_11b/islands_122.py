#!/usr/bin/env python3

import sys

def find_islands(adj_list):
    visited = set()
    num_islands = 0

    def dfs(vertex):
        visited.add(vertex)
        for neighbor in adj_list[vertex]:
            if neighbor not in visited:
                dfs(neighbor)

    for vertex in range(len(adj_list)):
        if vertex not in visited:
            dfs(vertex)
            num_islands += 1

    return num_islands


if __name__ == '__main__':
    adj_list = []
    num_vertices = int(sys.stdin.readline())
    for i in range(num_vertices):
        adj_list.append([])

    for line in sys.stdin:
        src, dest = map(int, line.split())
        adj_list[src].append(dest)
        adj_list[dest].append(src)

    num_islands = find_islands(adj_list)
    print(num_islands)
