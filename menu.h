#ifndef MENU_H
#define MENU_H

class Menu
{
private:
    bool d_mode;
public:
    Menu();
    virtual ~Menu() = default;
    void execute();
};

#endif // MENU_H
