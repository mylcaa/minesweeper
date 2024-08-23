#include "field.h"

Field::Field(unsigned int rows, unsigned int cols, unsigned int mines, QWidget* parent /*= nullptr*/):
     numRows(rows)
    ,numCols(cols)
    ,numMines(mines)
    ,numCorrectFlags(0)
    ,numIncorrectFlags(0)
    ,numRevealedSquares(0)
    ,QFrame(parent)
{
    init();
    fillField();
    addNeighbours();


}

void Field::init(){

    this->setAttribute(Qt::WA_LayoutUsesWidgetRect);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    layout->setSpacing(0);
    layout->setMargin(0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSizeConstraint(QLayout::SetFixedSize);

    this->setLayout(layout);
}

void Field::fillField(){

    for(unsigned int row = 0; row < numRows; ++row){
        field += QList<Square*>{};

        for(unsigned int col = 0; col < numCols; ++col){
            field[row] += new Square({row, col}, this);

            (this->layout)->addWidget(field[row][col], row, col);

            connect(field[row][col], &Square::first_click, this, &Field::placeMines);

            connect(field[row][col], &Square::flagged, [this](bool isMine)
                {
                    if(isMine){
                        numCorrectFlags++;
                    }else{
                        numIncorrectFlags++;
                    }

                    flag_count(numCorrectFlags + numIncorrectFlags);

                    if((numCols*numRows - numMines) == numRevealedSquares && numIncorrectFlags == 0){
                        qDebug() << "WON";
                        victory();
                    }
                });

            connect(field[row][col], &Square::unflagged, [this](bool isMine)
                {
                    if(isMine){
                        numCorrectFlags--;
                    }else{
                        numIncorrectFlags--;
                    }

                    flag_count(numCorrectFlags + numIncorrectFlags);

                    if((numCols*numRows - numMines) == numRevealedSquares && numIncorrectFlags == 0){

                        qDebug() << "WON";
                        victory();

                    }
                });

            connect(field[row][col], &Square::revealed, [this]()
                {
                    numRevealedSquares++;


                flag_count(numCorrectFlags + numIncorrectFlags);

                if((numCols*numRows - numMines) == numRevealedSquares && numIncorrectFlags == 0){

                    qDebug() << "WON";
                    victory();

                }

                });

            connect(field[row][col], SIGNAL(game_over()), this, SIGNAL(game_over()));
            connect(this, SIGNAL(game_over()), field[row][col], SIGNAL(reveal()));

            connect(this, SIGNAL(victory()), field[row][col], SIGNAL(reveal()));
        }
    }
}

void Field::addNeighbours()
{
    for (unsigned int row = 0; row < numRows; ++row)
    {
        for (unsigned int col = 0; col < numCols; ++col)
        {
            unsigned int lastRow = numRows - 1;
            unsigned int lastCol = numCols - 1;

            if (row && col)						field[row][col]->addNeighbour(field[row - 1][col - 1]);
            if (row)							field[row][col]->addNeighbour(field[row - 1][col]);
            if (row && col < lastCol)			field[row][col]->addNeighbour(field[row - 1][col + 1]);
            if (col < lastCol)                  field[row][col]->addNeighbour(field[row][col + 1]);
            if (row < lastRow && col < lastCol)	field[row][col]->addNeighbour(field[row + 1][col + 1]);
            if (row < lastRow)                  field[row][col]->addNeighbour(field[row + 1][col]);
            if (row < lastRow && col)			field[row][col]->addNeighbour(field[row + 1][col - 1]);
            if (col)							field[row][col]->addNeighbour(field[row][col - 1]);
        }
    }
}

void Field::placeMines(Square* firstClicked){

    // get a flat list of tiles
    QList<Square*> unused;
    QSet<Square*> used;

    //the first clicked tile does not contain a mine, this is how they make sure
    //it is sent into a set of "used" tiles along with it's neighbours which are also going to be mineless
    used += firstClicked;

    used += QSet<Square*>(firstClicked->neighbours.begin(), firstClicked->neighbours.end());

    for (unsigned int row = 0; row < numRows; ++row){
        for (unsigned int col = 0; col < numCols; ++col){

            Square* square = field[row][col];

            // add a new tile to the row (unless it's the first one clicked)
            if (!used.contains(square))
                unused += square;
        }
    }

    // shuffle it
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(unused.begin(), unused.end(), g);

    for (unsigned int i = 0; i < numMines; ++i)
    {
        qDebug() << i;
        unused[i]->placeMine();
    }

    start_game();

}
