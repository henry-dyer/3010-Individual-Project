#ifndef _SQUARE_HPP_
#define _SQUARE_HPP_

class Square
{
    public:
        Square();
        Square(int val);

        int get_value();
        void set_value(int val);

        const bool* get_notes();
        const bool get_single_note(int index);

        bool get_prefilled();
        void set_prefilled(bool val);

        void set_note(int index, bool val);

        bool operator==(const Square& square);

    private:
        int _value_;
        bool _prefillied_;
        bool _notes_[9];
};


#endif