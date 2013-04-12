#include "Field.h"
#include "IMAGEFILE.h"

Field::Field(int np, int mp) : robot(8)
{
   this -> n  = np;
   this -> m = mp;

   Star s(200, 300);
   s.img.setImage(IMG_STAR);
   stars.push_back(s);

   locateStarsOnTheField(30);

   robot.setX(dx);
   robot.setY(dy);
   robot.img.setImage(IMG_ROBOT);
}

void Field::paintEvent(QPaintEvent *)
{
    int x = dx;
    int y = dy;

    QPainter p(this);
    p.setPen(QPen(Qt::black, 1, Qt::SolidLine));

    //Field
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            p.drawRect(QRect(x, y, hw, hw));
            x += hw;
        }
        y += hw;
        x = dx;
    }

    //Robot
    p.drawImage(QPoint(robot.getX(), robot.getY()), robot.img.getImage());

    //Stars
    list<Star>::iterator its;
    its = stars.begin();
    while(its != stars.end())
    {
        if(((Star)*its).getIsALive())
        {
            p.drawImage(QPoint(((Star)*its).getX(), ((Star)*its).getY()), ((Star)*its).img.getImage());
            ++its;
        }
        else
        {
            its = stars.erase(its);
            QLabel lab("top");
            lab.show();
        }

    }

    //Bombs
    list<Bomb>::iterator itb;
    for(itb = bombs.begin(); itb != bombs.end(); ++itb)
    {
        p.drawImage(QPoint(((Bomb)*itb).getX(), ((Bomb)*itb).getY()), ((Bomb)*itb).img.getImage());
    }

    //Powers
    list<Power>::iterator itp;
    for(itp = powers.begin(); itp != powers.end(); ++itp)
    {
        p.drawImage(QPoint(((Power)*itp).getX(), ((Power)*itp).getY()), ((Power)*itp).img.getImage());
    }

    //Door
     p.drawImage(QPoint(door.getX(), door.getY()), door.img.getImage());

     //Battery
     int bx = 40;
     int by = dy + 100;
     int bw  = 120;
     int bh = 320;
     p.drawRect(bx, by, bw, bh);
     p.drawRect(bx + (bw / 2) - 10, by - 10, 30, 10);

     int d = 5; // distance between two blocks
     //Gradient
     QLinearGradient gr(0, 0, 100, 100);
     gr.setColorAt(0, Qt::green);
     gr.setColorAt(0.9, QColor("#6dc039"));
     gr.setColorAt(1, Qt::green);
     p.setBrush(gr);

     for(int i = 0; i < robot.battery.getPower(); i++)
     {
         p.drawRect(bx + 5, by + bh - 35 - i*(d + 35), bw - 10, 30);
     }

    //PointBar
     QImage imgs(IMG_STAR);
     int pb_offsety = 50;
     int pb_offsetx = (hw * m) + dx - 100;
     p.drawImage(QPoint(pb_offsetx, pb_offsety - 30), imgs) ;
     p.setFont(QFont("Times", 15, QFont::Normal));
     p.drawText(pb_offsetx + imgs.width() + 10, pb_offsety, "x20");
}


bool Field::testPosition(int x, int y)
{
    int px = (x - dx) / hw;
    int py = (y - dy) / hw;
    if ((px >= 0) && (px < m) && (py >= 0) && (py < n))
        return true;
    return false;
}


void Field::keyPressEvent(QKeyEvent * key)
{
    switch(key -> key())
    {
        case Qt::Key_Up:
            if(testPosition(robot.getX(), robot.getY() - hw))
            {
                visitLocation(robot.getX(), robot.getY() - hw);
                robot.setY(robot.getY() - hw);
                robot.battery.setPower(robot.battery.getPower() - 1);
            }
        break;
        case Qt::Key_Down:
            if(testPosition(robot.getX(), robot.getY() + hw))
            {
                visitLocation(robot.getX(), robot.getY() + hw);
                robot.setY(robot.getY() + hw);
                robot.battery.setPower(robot.battery.getPower() - 1);
            }
        break;
        case Qt::Key_Left:
            if(testPosition(robot.getX() - hw, robot.getY()))
            {
                visitLocation(robot.getX() - hw, robot.getY());
                robot.setX(robot.getX() - hw);
                robot.battery.setPower(robot.battery.getPower() - 1);
            }
        break;
        case Qt::Key_Right:
        if(testPosition(robot.getX() + hw, robot.getY()))
        {
            visitLocation(robot.getX() + hw, robot.getY());
            robot.setX(robot.getX() + hw);
            robot.battery.setPower(robot.battery.getPower() - 1);
        }
        break;
    }
    this -> update();
}

void Field::locateStarsOnTheField(int ns) {
    list<Star>::iterator its;

    int rx = 0;
    int ry = 0;
    int k = 0; //Help to recall function
    //Don't repeat and (0,0) - robot's place
    srand(time(NULL));

    for(int i = 0; i < ns; i++)
    {
        rx = rand() % m;
        ry = rand() % n;
        if(( rx != 0) && (ry != 0))
        {
            Star s(rx * hw + dx, ry * hw + dy);
            s.img.setImage(IMG_STAR);
            stars.push_back(s);
        }
    }

    if (k != 0)
        Field::locateStarsOnTheField(k);
}

void Field::visitLocation(int x, int y)
{
    list<Star>::iterator its;
    for(its = stars.begin(); its != stars.end(); ++its)
    {
        if((((Star)*its).getX() == x) && (((Star)*its).getY() == y))
        {
            ((Star)*its).setIsALive(false);
        }


    }
}
