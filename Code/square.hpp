#ifndef _SQUARE_HPP_
#define _SQUARE_HPP_

class Square
{
    public:
        Square();
        Square(int val);

        const int get_value();
        void set_value(int val);

        const bool* get_notes();
        const bool get_single_note(int index);

        void set_note(int index, bool val);

    private:
        int _value_;
        bool _notes_[9];
};


#endif