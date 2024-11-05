//******************
//
// scls_demo_raycast.cpp
//
//******************
// Presentation :
//
// SCLS is a project containing base functions for C++.
// It can also be use in any projects.
//
// The "Demo" part is a part full of demonstrations for SCLS.
//
// This file contains the source code of scls_demo_raycast.h.
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
#include "scls_demo_raycast.h"

// Using of the "scls" namespace to simplify the programmation
namespace scls {
    namespace demo {
        // Use the Raycast window
        void use_raycast(int window_width, int window_height, std::string exec_path) {
            std::unique_ptr<__Temp_Window> raycast = std::make_unique<__Temp_Window>(window_width, window_height, exec_path);

            // Execution loop
            while(raycast.get()->run()) {
                raycast.get()->update_event();
                raycast.get()->update();

                raycast.get()->render();
            }
        }
    }
}
