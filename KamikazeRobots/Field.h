#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include <QtGui>
#include <QPainter>
#include <QImage>
#include <QLabel>

#include <time.h>

#include "Points.h"
#include "Door.h"
#include "Bomb.h"
#include "Star.h"
#include "Robot.h"
#include "Power.h"

using namespace std;

/// class Field -
class Field : public QWidget {
  // Associations
  Points points;
  Door door;
  Robot robot;
  // Attributes
public:
  list<Star> stars;
  list<Bomb> bombs;
  list<Power> powers;
private:
  int n;
  int m;
  const static int dx = 200; // Offset X
  const static int dy = 100; // Offset Y
  const static int hw = 50; // cell height width
  // Operations
public:
  Field(int n, int m);
private:
  bool testPosition(int x, int y);
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
    void visitLocation(int x, int y);
    void locateStarsOnTheField(int ns);
};



#endif // FIELD_H
