#!/usr/bin/env python3

import sys

def chess_pieces(k, q, r, b, kn, p):
    pieces_needed = [2, 2, 4, 4, 4, 16]  # kings, queens, rooks, bishops, knights, pawns
    pieces_available = [k, q, r, b, kn, p]
    pieces_difference = [needed - available for needed, available in zip(pieces_needed, pieces_available)]
    return pieces_difference

if __name__ == "__main__":
    for line in sys.stdin:
        k, q, r, b, kn, p = map(int, line.split())
        pieces_difference = chess_pieces(k, q, r, b, kn, p)
        print(*pieces_difference)
