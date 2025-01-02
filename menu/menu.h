#ifndef OBSERVATEUR_H
#define OBSERVATEUR_H

class Menu
{
private:
    bool d_mode;
public:
    Menu();
    virtual ~Menu() = default;
    void run();
};

#endif // OBSERVATEUR_H