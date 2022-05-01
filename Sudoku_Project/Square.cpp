#include "Square.h"

Square::Square()
{
    _value_ = 0;
    _prefillied_ = false;
    x_ = 0;
    y_ = 0;

}

Square::Square(int val, int x, int y)
{
    _value_ = val;
    x_ = x;
    y_ = y;

    if(val == 0) _prefillied_ = false;
    else _prefillied_ = true; 
}

int Square::get_value()
{
    return _value_;
}

void Square::set_value(int val)
{
    _value_ = val;
}

bool Square::get_prefilled()
{
    return _prefillied_;
}

void Square::set_prefilled(bool val)
{
    _prefillied_ = val;
}

QRectF Square::boundingRect() const
{
    return QRectF(x_ * 60, y_ * 60, width_, width_);
}

QPainterPath Square::shape() const
{
    QPainterPath path;
    path.addRect(x_ * 60, y_ * 60, width_, width_);
    return path;
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    QFont font;
    font.setFamily("Arial");
    font.setPointSize(32);
    painter->setFont(font);
    //Load value again instead of zero
    painter->drawRect((x_ * 60) , (y_ * 60), width_, width_);
    if(!isValid_) painter->setPen(QColor(255, 0, 0 , 255));

    if(_value_ == 0)
    {
        painter->drawText((x_ * 60) + 22, (y_ * 60) + 42, "");
    }
    else painter->drawText((x_ * 60) + 22, (y_ * 60) + 42, QString::number(_value_));
    painter->setPen(QColor(255, 255, 255 ,255));
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit SquareSelected(this);
}

bool Square::operator==(const Square& square)
{
    if (_value_ == square._value_) return true;
    return false;
}
