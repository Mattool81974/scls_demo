//******************
//
// scls_demo_snake.h
//
//******************
// Presentation :
//
// SCLS is a project containing base functions for C++.
// It can also be use in any projects.
//
// The "Demo" part is a part full of demonstrations for SCLS.
//
// This file contains a little snake game made with SCLS.
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

#ifndef SCLS_DEMO_SNAKE
#define SCLS_DEMO_SNAKE

// Include SCLS library
#include "../../../scls-3d-margaret/headers/scls_3d_engine.h"

// Using of the "scls" namespace to simplify the programmation
namespace scls {
    namespace demo {
        //*********
        //
        // The Snake class
        //
        //*********

        class Snake : public Window {
            // Class representating the window for the Snake game
        public:

            //*********
            //
            // Snake mains members
            //
            //*********

            // Snake constructor
            Snake(int window_width, int window_height, std::string exec_path);

            // Create the background image of the playground part
            std::shared_ptr<Image> playground_image();
        private:

            //*********
            //
            // Snake gampelay attributes
            //
            //*********

            // Height of the playground in scale
            unsigned short a_height_in_cases = 15;
            // Width of the playground in scale
            unsigned short a_width_in_cases = 15;

            //*********
            //
            // Snake GUI attributes
            //
            //*********

            // Page of the game
            GUI_Page* gui = 0;
            // Playground of the game
            GUI_Object* playground = 0;
        };

        // Use the Snake window
        void use_snake(int window_width, int window_height, std::string exec_path);
    }
}

#endif // SCLS_DEMO_SNAKE
