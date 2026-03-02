//
// Created by benja on 2/24/2026.
//

#ifndef CHESSENGINE_KING_H
#define CHESSENGINE_KING_H

class King : public Piece {
public:

private:
    int mPoints;

    bool mColor;

    char mChar;


    const Board mBoard;

    GridPoint mLoc;

    std::list<GridPoint> mMoves;

    void findMoves();
};

#endif //CHESSENGINE_KING_H