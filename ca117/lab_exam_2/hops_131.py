#!/usr/bin/env python3

import sys

class Graph:

    def __init__(self, airports):
        self.graph = {a: [] for a in airports}

    def addEdge(self, a, b):
        self.graph[a].append(b)
        self.graph[b].append(a)

    def get_neighbors(self, airport):
        return self.graph[airport]

def read_graph(filename):
    with open(filename) as f:
        airports = f.readline().strip().split()
        graph = Graph(airports)
        for line in f:
            a, b = line.strip().split()
            graph.addEdge(a, b)
        return graph

def find_reachable_airports(graph, start, N):
    visited = set()
    queue = [(start, 0)]
    while queue:
        airport, dist = queue.pop(0)
        visited.add(airport)
        if dist < N:
            for neighbor in graph.get_neighbors(airport):
                if neighbor not in visited:
                    queue.append((neighbor, dist+1))
    return sorted(list(visited))

if __name__ == '__main__':
    filename = sys.argv[1]
    start = sys.argv[2]
    N = int(sys.argv[3])
    graph = read_graph(filename)
    reachable_airports = find_reachable_airports(graph, start, N)
    for airport in reachable_airports:
        print(airport)
