#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "ticTacToe_global.h"
#include "game.h"
#include <QObject>
namespace Lib {
namespace ticTacToe{

class TICTACTOE_EXPORT TicTacToe: public QObject
{
    Q_PROPERTY(QString ui_welcomeMessage MEMBER welcomeMessage CONSTANT)
    Q_PROPERTY(QString ui_select READ getSelected WRITE setSelected NOTIFY selectedChanged)
    Q_PROPERTY(int ui_gameMode READ getMode WRITE setMode CONSTANT)
    Q_PROPERTY(QString ui_player READ getDefaultPlayer WRITE setDefaultPlayer NOTIFY playerChanged)
    Q_PROPERTY(int ui_slot READ getSlot WRITE interfaceGame NOTIFY gameInterfaced)
    Q_PROPERTY(QString ui_winner READ getWinner CONSTANT)
    Q_PROPERTY(int ui_xScores READ getXScores CONSTANT)
    Q_PROPERTY(int ui_oScores READ getOScores CONSTANT)
    Q_OBJECT
public:
    TicTacToe(QObject *parent = nullptr);
    ~TicTacToe();
    QString getSelected() const;
    void setSelected(const QString &select);
    int getMode() const;
    void setDefaultPlayer(const QString &player);
    QString getDefaultPlayer() const;
    void setMode(const int &mode);
    void interfaceGame(const int &slot);
    int getSlot();
    int getXScores();
    int getOScores();
    QString getWinner();

signals:
    void selectedChanged();
    void gameModeChanged();
    void playerChanged();
    void gameInterfaced();
private:
    Game *game;
    QString welcomeMessage;
    QString selected = "";
    int gameMode = 1;
    QString Player = "X";
};

}}

#endif // TICTACTOE_H
