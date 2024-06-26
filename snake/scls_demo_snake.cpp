//******************
//
// scls_demo_snake.cpp
//
//******************
// Presentation :
//
// SCLS is a project containing base functions for C++.
// It can also be use in any projects.
//
// The "Demo" part is a part full of demonstrations for SCLS.
//
// This file contains the code source of scls_demo_snake.cpp.
//
//******************
//
// License (GPL V3.0) :
//
// Copyright (C) 2024 by Aster System, Inc. <https://aster-system.github.io/aster-system/>
// This file is part of SCLS.
// SCLS is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// SCLS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
// You should have received a copy of the GNU General Public License along with SCLS. If not, see <https://www.gnu.org/licenses/>.
//

// Include SCLS library
#include "scls_demo_snake.h"

// Using of the "scls" namespace to simplify the programmation
namespace scls {
    namespace demo {
        //*********
        //
        // Snake mains members
        //
        //*********

        // Snake constructor
        Snake::Snake(int window_width, int window_height, std::string exec_path) : Window(window_width, window_height, exec_path) {
            set_background_color(Color(0, 0, 0));

            // Create the page
            gui = new_page<GUI_Page>("gui");
            gui->set_scale(glm::vec3(2, 2, 1));
            gui->parent_object()->set_background_color(scls::Color(0, 0, 0));
            gui->parent_object()->set_position_in_pixel(0, 0);
            gui->parent_object()->set_height_in_scale(scls::Fraction(1));
            gui->parent_object()->set_width_in_scale(scls::Fraction(1));
            display_page("gui");

            // Create the playground
            playground = gui->parent_object()->new_object<GUI_Object>("playground");
            playground->set_height_in_pixel(window_width);
            playground->set_width_in_scale(1);
            playground->set_y_in_object_scale(Fraction(3, 5));
            std::shared_ptr<Image> image = playground_image();
            playground->texture()->set_image(image);
            playground->move_left_in_parent();
        }

        // Create the background image of the playground part
        std::shared_ptr<Image> Snake::playground_image() {
            std::shared_ptr<Image> to_return = std::make_shared<Image>(window_width(), window_width(), Color(160, 160, 160));

            // Draw the outer lines
            unsigned char outer_line_width = 4;
            Image* image = to_return.get();
            image->fill_rect(0, 0, outer_line_width, image->height() - outer_line_width, Color(60, 60, 60));
            image->fill_rect(0, image->height() - outer_line_width, image->width(), outer_line_width, Color(60, 60, 60));
            image->fill_rect(outer_line_width, 0, outer_line_width, image->height() - outer_line_width * 2, Color(102, 102, 102));
            image->fill_rect(outer_line_width, image->height() - outer_line_width * 2, image->width() - outer_line_width, outer_line_width, Color(102, 102, 102));
            image->fill_rect(outer_line_width * 2, 0, image->width() - outer_line_width * 2, outer_line_width, Color(200, 200, 200));
            image->fill_rect(image->width() - outer_line_width, 0, outer_line_width, image->height() - outer_line_width * 2, Color(200, 200, 200));

            // Draw the inner lines
            unsigned int current_pos = outer_line_width * 2;
            unsigned char inner_line_width = 1;
            std::vector<long long> cases = partition_number(image->width() - (outer_line_width * 3 - inner_line_width), a_width_in_cases);
            for(int i = 0;i<static_cast<int>(cases.size());i++) {
                current_pos += cases[i];
                if(i < static_cast<int>(cases.size()) - 1)image->draw_line(current_pos, outer_line_width - 1, current_pos, image->height() - outer_line_width * 2, scls::Color(102, 102, 102));
            }
            current_pos = outer_line_width * 2;
            cases = partition_number(image->height() - (outer_line_width * 3 - inner_line_width), a_height_in_cases);
            for(int i = 0;i<static_cast<int>(cases.size());i++) {
                current_pos += cases[i];
                if(i < static_cast<int>(cases.size()) - 1) image->draw_line(outer_line_width - 1, current_pos, image->width() - outer_line_width * 2, current_pos, scls::Color(102, 102, 102));
            }

            return to_return;
        }

        // Use the Snake window
        void use_snake(int window_width, int window_height, std::string exec_path) {
            std::unique_ptr<Snake> snake = std::make_unique<Snake>(window_width, window_height, exec_path);

            // Execution loop
            while(snake.get()->run()) {
                snake.get()->update_event();
                snake.get()->update();

                snake.get()->render();
            }
        }
    }
}
