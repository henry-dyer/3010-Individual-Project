#include "Square.hpp"

Square::Square()
{
    _value_ = 0;
    _prefillied_ = false;
    _notes_[0] = 0;
    _notes_[1] = 0;
    _notes_[2] = 0;
    _notes_[3] = 0;
    _notes_[4] = 0;
    _notes_[5] = 0;
    _notes_[6] = 0;
    _notes_[7] = 0;
    _notes_[8] = 0;
}

Square::Square(int val)
{
    _value_ = val;
    _notes_[0] = 0;
    _notes_[1] = 0;
    _notes_[2] = 0;
    _notes_[3] = 0;
    _notes_[4] = 0;
    _notes_[5] = 0;
    _notes_[6] = 0;
    _notes_[7] = 0;
    _notes_[8] = 0;

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

const bool* Square::get_notes()
{
    return _notes_;
}

const bool Square::get_single_note(int index)
{
    return _notes_[index];
}

void Square::set_note(int index, bool val)
{
    _notes_[index] = val;
}

bool Square::get_prefilled()
{
    return _prefillied_;
}

void Square::set_prefilled(bool val)
{
    _prefillied_ = val;
}

bool Square::operator==(const Square& square)
{
    if (_value_ == square._value_) return true;
    return false;
}