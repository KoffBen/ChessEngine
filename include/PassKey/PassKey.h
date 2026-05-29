//
// Created by benja on 5/29/2026.
//

#ifndef CHESSENGINE_PASSKEY_H
#define CHESSENGINE_PASSKEY_H

//I just learned about the PassKey pattern for this so let's try it.

class PassKey
{
    friend class MovePiece;
    PassKey() = default;
    //So this should work as a private constructor that can ONLY be used by MovePiece, and then we can make a function
    //through Board that will require a PassKey to use, thus making it only callable by MovePiece
};
#endif //CHESSENGINE_PASSKEY_H
