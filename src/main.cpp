#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
int main()
{

    bn::core::init();
    bn::backdrop::set_color(bn::color(25, 5, 31));

    int combo_color_index = 0;
    int combo_frame_counter = 0;
    const int PAUSE_FRAMES = 10; 
    while (true)
    {
        bn::backdrop::set_color(bn::color(25, 5, 31));

        if (bn::keypad::a_held() && bn::keypad::b_held())
        {
            combo_frame_counter++;

            if (combo_frame_counter >= PAUSE_FRAMES)
            {
                combo_frame_counter = 0;
                combo_color_index = (combo_color_index + 1) % 3;
            }

            if (combo_color_index == 0)
            {
                bn::backdrop::set_color(bn::color(31, 0, 0));
            }
            else if (combo_color_index == 1)
            {
                bn::backdrop::set_color(bn::color(0, 0, 31));
            }
            else if (combo_color_index == 2)
            {
                bn::backdrop::set_color(bn::color(0, 31, 0));
            }
        }
        else if (bn::keypad::a_held())
        {
            bn::backdrop::set_color(bn::color(31, 21, 22));
        }
        else if (bn::keypad::b_held())
        {
            bn::backdrop::set_color(bn::color(0, 0, 31));
        }

        bn::core::update();
    }
}
