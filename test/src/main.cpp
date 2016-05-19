#include <ijengine/exception.h>
#include "test_game.h"
#include <iostream>

#include <ijengine/game_object.h>

using namespace ijengine;
using namespace std;

class Test : public GameObject
{
public:
    Test(int p = 0) : GameObject(nullptr, 0, 0, p) {}

    void add()
    {
        printf("before:");

        for (auto c : m_children)
        {
            printf(" (%p, %d)", (void *) c, c->priority());
        }
        
        printf("\n");

        int p = rand() % 1000;

        add_child(new Test(p));

        printf("after:");

        for (auto c : m_children)
        {
            printf(" (%p, %d)", (void *) c, c->priority());
        }
        
        printf("\n");
    }

protected:
        void update_self(unsigned now, unsigned last) {}
        void draw_self(Canvas *canvas, unsigned now, unsigned last) {}
};

int main()
{
/*    Test test;

    test.add();
    test.add();
    test.add();
    test.add();
    test.add(); */

    int rc;

    try
    {
        TestGame game("Teste", 640, 480);
        rc = game.run("red");
    } catch (Exception& ex)
    {
        cout << ex.what() << endl;
    } 
    
    return rc; 
}