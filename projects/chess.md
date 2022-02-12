# Chess Game

Create a simple command-line version of [Chess Game](https://en.wikipedia.org/wiki/Chess) where two players can play chess.
Each player has sixteen pieces: one king, one queen, two rooks, two knights, two bishops, and eight pawns. One in white and another in black. 

|  | a | b | c | d | e | f | g | h |  |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |  :---: | 
| 8 |  |  |  |  |  |  |  |  | 8 |
| 7 |  |  |  |  |  |  |  |  | 7 |
| 6 |  |  |  |  |  |  |  |  | 6 |
| 5 |  |  |  |  |  |  |  |  | 5 |
| 4 |  |  |  |  | e4 |  |  |  | 4 |
| 3 |  |  | c3 |  |  |  |  |  | 3 |
| 2 |  |  |  |  |  |  |  |  | 2 |
| 1 |  |  |  |  |  |  |  |  | 1|
|  | a | b | c | d | e | f | g | h |  |

## Features
1. Let user enter two user names. ("jack", "tim")
2. Every user will enter two inputs (L1)
3. Validate the input. e.g. c3, e4
    1. Is there any piece on that cell? Cell is valid, piece in the cell belongs to the right user) 
    2. Is the piece movement valid or not? (Can that piece move from one location to another?)
4. Option to terminate/reset the game.

## Taking it to the next level
1. Given a piece in the chess, show the possible moves.
2. Implement timed version of chess.
3. Create users. If a user comes back to his/her account, he/she should be able to see previous records of wins and losses.
