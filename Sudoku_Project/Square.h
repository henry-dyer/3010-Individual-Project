#ifndef _SQUARE_H_
#define _SQUARE_H_

#include <QObject>
#include <QGraphicsItem>
#include <QColor>
#include <QPainter>
#include <QString>
#include <QFont>
#include <QKeyEvent>

class Square : public QObject, public QGraphicsItem
{
    Q_OBJECT //Not sure what this is doing
    public:
        Square();
        Square(int val, int x, int y);

        int get_value();
        void set_value(int val);

        bool get_prefilled();
        void set_prefilled(bool val);

        int get_x() {return x_ ;};
        int get_y() {return y_;};

        void set_isValid(bool valid) { isValid_ = valid; };

        QRectF boundingRect() const override;
        QPainterPath shape() const override;

        void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

        static const int width_ = 60;

        bool operator==(const Square& square);

    signals:
        void SquareSelected(Square* curr);

    protected:
     void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    private:
        int _value_;
        bool _prefillied_;
        int x_;
        int y_;
        bool isValid_ = true;

};


#endif
